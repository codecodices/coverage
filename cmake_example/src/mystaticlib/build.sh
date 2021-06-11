#!/bin/sh

cd ./build && make

exitStatus=$?

if [[ $exitStatus == 0 ]]; then
    echo "Succeeded"
else
    echo "Failed"
fi

exit $exitStatus
