#!/bin/sh

exitStatus=0

if [[ ! -x ./build/example ]]; then
    echo "Can't find \"./build/example\".  Make sure that build.sh has been executed."
    exitStatus=1
else
    cd ./build && ./example
    exitStatus=$?
fi

echo
if [[ $exitStatus == 0 ]]; then
    echo "Exit status = SUCCESS"
else
    echo "Exit status = FAILURE"
fi

exit $exitStatus
