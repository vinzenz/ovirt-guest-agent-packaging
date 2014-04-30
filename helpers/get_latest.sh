#!/bin/sh

BASE_URL=http://evilissimo.fedorapeople.org/releases/ovirt-guest-agent/latest
[ -f LATEST_VERSION ] && /bin/rm LATEST_VERSION
curl "${BASE_URL}/LATEST" -o LATEST_VERSION 2> /dev/null

LATEST_VERSION=`cat LATEST_VERSION`

curl "${BASE_URL}/ovirt-guest-agent-${LATEST_VERSION}.tar.bz2" -o ovirt-guest-agent-${LATEST_VERSION}.tar.bz2 2> /dev/null
