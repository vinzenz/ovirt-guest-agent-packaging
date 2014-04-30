#!/bin/sh

LATEST_VERSION=`cat LATEST_VERSION`

/bin/mkdir patches
/bin/mkdir repo
cd repo
git clone http://gerrit.ovirt.org/ovirt-guest-agent
cd ovirt-guest-agent
git format-patch ${LATEST_VERSION}
cp *.patch ../../patches
cd ../..
/bin/rm -rf repo

if [ -f ./blacklist/${LATEST_VERSION} ]; then
    echo "Removing black listed patches"
    cd patches
    /bin/rm "`cat ../blacklist/${LATEST_VERSION}`"
    cd ..
fi
