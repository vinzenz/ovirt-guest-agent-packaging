#!/bin/sh

LATEST_VERSION="`cat LATEST_VERSION`"

if [ -d "./extra-sources/ovirt-guest-agent-${LATEST_VERSION}" ]; then
    cp -a ./extra-sources/ovirt-guest-agent-${LATEST_VERSION} "ovirt-guest-agent-${LATEST_VERSION}"
fi
