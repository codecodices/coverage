#!/bin/sh

if [[ ! -d ./build ]]; then
    echo "The configure.sh script has not been executed.  Executing it now."
    ./configure.sh
fi

cd ./build && make

exitStatus=$?

if [[ $exitStatus == 0 ]]; then
    echo "Succeeded"
else
    echo "Failed"
fi

exit $exitStatus
