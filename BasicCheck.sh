#!/bin/bash
ARRAY=("$@")
SOURCE=`pwd`
cd ${ARRAY[0]}
ARRAY=("${ARRAY[@]:1}")
make
MakefileExist=$?
if [ $MakefileExist -gt 0 ]
 then
        exit 7
fi
chmod u+x ./${ARRAY[0]}
valgrind --leak-check=full --error-exitcode=3 -v ./${ARRAY[@]}  
valgrindOUT=$?
valgrind --tool=helgrind --error-exitcode=3 ./${ARRAY[@]} 
helgrindOUT=$?
if [[ valgrindOUT -gt 0 && helgrindOUT -gt 0 ]]
 then   
        exit 3
elif [[ valgrindOUT -gt 0 ]]
 then
        exit 2
elif [[ helgrindOUT -gt 0 ]]
 then 
        exit 1
fi
cd $SOURCE
exit 0
