2Sum Problem
===================

About
------------
Check if there are distinct numbers x,y in the input file that satisfy x + y = sum.  
For better performance sort the vector in O(n * log n) and then for every element x
binary search for t - x.
Could be done even better instead of binary search for t - x store key t - x in a hash table.

Running code examples
------------
**C** implementation:

You should compile the source file first.

    cd C/
    gcc -o 2Sum 2Sum.c (Linux)
    ./2Sum ../in/inputBig.txt (Linux)
    
    compile with Visual Studio | MinGW | DevC++ (Windows)
    2Sum.exe ../in/inputBig.txt (Windows)

**Java** implementation:

Contains also JUnit test files for QuickSort and BinarySearch algorithms.

Used java 1.6.0_33, junit 4.10 to compile source files.

    cd Java/
    java TwoSum ../in/inputBig.txt (Windows & Linux)
    java -cp "<path_to_junit_4.x_jar_file>;./" org.junit.runner.JUnitCore QuickSortTest (Windows)
    java -cp "<path_to_junit_4.x_jar_file>;./" org.junit.runner.JUnitCore BinarySearchTest (Windows)
    java -cp "<path_to_junit_4.x_jar_file>:./" org.junit.runner.JUnitCore QuickSortTest (Linux)
    java -cp "<path_to_junit_4.x_jar_file>:./" org.junit.runner.JUnitCore BinarySearchTest (Linux)

To compile yourself the source files:

    cd Java/
    javac QuickSort.java BinarySearch.java TwoSum.java (Windows & Linux)
    javac -cp "<path_to_junit_4.x_jar_file>;./" QuickSortTest.java BinarySearchTest.java (Windows)
    javac -cp "<path_to_junit_4.x_jar_file>:./" QuickSortTest.java BinarySearchTest.java (Linux)

For the input files in *in/* folder the expected results are:   
for *inputBig.txt* and sum -8848 algorithm should find a pair x,y, x != y that gives that sum  
for *inputSmall.txt* and sum 10 algorithm should find a pair x,y, x != y that gives that sum  
