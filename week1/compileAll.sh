#Run script (on seas) in folder you plan on submitting before zipping
#Checks if files are named correctly.  If files named correctly, compiles them using g31. Also checks to make sure a report file is present.
#Disclaimer: You are still responsible for checking your own work.  I have not tested this script with the auto-grader.  This is just a suggestion for how to quickly check that all your code compiles using g31.  Additionally, you may need to remove this script from the folder before zipping and submitting.

original=original.cpp

if [ -f $original ] ; then
    g31 $original -o `basename $original .cpp` 
else
    echo "$original is missing or not named correctly"
fi

q6=logic_error.cpp

if [ -f $q6 ] ; then
    g31 $q6 -o `basename $q6 .cpp` 
else
    echo "$q6 is missing or not named correctly"
fi

q7=compile_error.cpp

if [ -f $q7 ] ; then
    g31 $q7 -o `basename $q7 .cpp` 
else
    echo "$q7 is missing or not named correctly"
fi

if [ ! -f report.docx ] && [ ! -f report.doc ]  && [ ! -f report.txt ] ; then
    echo "Report file missing"
fi 
