#!/bin/sh

./helpers/get_latest.sh

LATEST_VERSION="`cat LATEST_VERSION`"
FOLDER_NAME="ovirt-guest-agent-${LATEST_VERSION}"
SOURCE_NAME="ovirt-guest-agent-${LATEST_VERSION}.tar.bz2"

[ -x ./helpers/hooks/prepare/before.sh ] && ./helpers/hooks/prepare/before.sh

/bin/tar xf ${SOURCE_NAME}

[ -x ./helpers/hooks/prepare/after.sh ] && ./helpers/hooks/prepare/after.sh

./helpers/create_patches.sh
