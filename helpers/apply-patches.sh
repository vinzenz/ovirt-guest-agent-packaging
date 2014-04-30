#!/bin/sh

LATEST_VERSION=`cat LATEST_VERSION`
SOURCE_DIR="ovirt-guest-agent-${LATEST_VERSION}"
HOOK_DIR=./helpers/hooks/apply-patch
START_DIR=`pwd`

apply_patch() {
    PATCH_PATH=$1
    PATCH_FILE_NAME=$2

    if [ -f ${HOOK_DIR}/before ]; then
        ${HOOK_DIR}/before "${PATCH_PATH}" "${PATCH_FILE_NAME}" || return 0
    fi
    echo Attempt to apply patch $START_DIR/$PATCH_PATH/$PATCH_FILE_NAME
    patch -p1 -F3 --ignore-whitespace -d $SOURCE_DIR < $START_DIR/$PATCH_PATH/$PATCH_FILE_NAME
    PATCH_RESULT=$?
    echo patch result is $PATCH_RESULT
    if [  ${PATCH_RESULT} != 0 ]; then
        echo Applying $PATCH_FILE_NAME failed. Patch returned ${PATCH_RESULT}
        return 1
    fi

    if [ -f ${HOOK_DIR}/after ]; then
        ${HOOK_DIR}/after "${PATCH_PATH}" "${PATCH_FILE_NAME}" || return 1
    fi
    return 0
}

for PATCH in `ls patches/*patch`; do
    apply_patch "patches" "`basename $PATCH`"
    APPLY_PATCH_RESULT=$?
    if [ ${APPLY_PATCH_RESULT} != 0 ]; then
        echo "Aborting after $PATCH"
        return 1
    fi
done
