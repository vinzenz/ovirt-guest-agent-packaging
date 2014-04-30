#!/bin/sh

./helpers/get_latest.sh

LATEST_VERSION="`cat LATEST_VERSION`"
FOLDER_NAME="ovirt-guest-agent-${LATEST_VERSION}"
SOURCE_NAME="ovirt-guest-agent-${LATEST_VERSION}.tar.bz2"
ORIG_NAME="ovirt-guest-agent_${LATEST_VERSION}.orig.tar.bz2"

/bin/mv ${SOURCE_NAME} ${ORIG_NAME}
/bin/rm -rf ${FOLDER_NAME}/debian
/bin/cp -a debian ${FOLDER_NAME}
