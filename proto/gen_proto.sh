#!/bin/bash
rm -f *.cc
rm -f *.h
for proto in `ls .`
do
   echo $proto | grep -E "*.proto$" 
   if [ $? -eq 0 ]
   then
      protoc --cpp_out=. $proto
   fi
done

mv *.cc ../src
mv *.h ../include
