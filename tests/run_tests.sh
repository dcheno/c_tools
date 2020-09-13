#!/bin/bash

# Really we should have a make file with a test and normal target (right?)
#

echo "--- STARTING TESTS ---"
FAILED=0
for f in *.c
do
    echo "RUNNING $f..."
    gcc -o active_test $f ../src/$f
    ./active_test
    RESULT=$?
    if [ $RESULT -ne 0 ]; then FAILED=1; fi
    rm active_test
done
echo "--- TESTS COMPLETE ---"
if [ $FAILED -eq 0 ]
then
    echo "* SUCCESS *"
else
    echo "* THERE WERE FAILURES *"
fi

