#Run script (on seas) in folder you plan on submitting before zipping
#Checks if files are named correctly
#If files named correctly, compiles them using g31
#Also checks to make sure a report file is present

original=original.cpp

if [ -f $original ] ; then
    g31 $original -o `basename $original .cpp` 
else
    echo "$original not named correctly"
fi

q6=logic_error.cpp

if [ -f $q6 ] ; then
    g31 $q6 -o `basename $q6 .cpp` 
else
    echo "$q6 not named correctly"
fi

q7=compile_error.cpp

if [ -f $q7 ] ; then
    g31 $q7 -o `basename $q7 .cpp` 
else
    echo "$q7 not named correctly"
fi

if [ ! -f report.docx ] && [ ! -f report.doc ]  && [ ! -f report.txt ] ; then
    echo "Report file missing"
fi
    
