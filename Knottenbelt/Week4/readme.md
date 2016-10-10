Question 1

Write a program which outputs its own C++ source file to the screen.

(EXAMPLE ANSWER) (BACK TO COURSE CONTENTS)
Question 2

Write a program that (i) starts with the output test statement:

	cout << "Testing: " << 16/2 << " = " << 4*2 << ".\n\n"; 

and then (ii) outputs its own C++ source file to a file called "WithoutComments.cpp" and to the screen, but omitting any of the comments enclosed in "/* ... */" markers (and omitting the markers themselves). The new program in the file "WithoutComments.cpp" should compile and run in exactly the same way as the program from which it was generated.

Hints:
(i) you might find the "putback()" function useful,
(ii) you might want to use the idea of a "flag" to keep track of whether you're inside a comment or not.

(EXAMPLE ANSWER) (BACK TO COURSE CONTENTS)
Question 3

Write a program which counts and displays the number of characters (including blanks) in its own source code file.

(EXAMPLE ANSWER) (BACK TO COURSE CONTENTS)
Question 4

Without using an array (we will learn about arrays in Lecture 6), write a program that prints itself out backwards on the screen.

Hints:
(i) the answer to question 3 might help at the start of your program,
(ii) be careful not to re-use an input stream once an operation has failed on it - use a new stream instead.

Remark: don't worry if your program takes a while before it prints to the screen - opening and closing files takes time.

(EXAMPLE ANSWER) (BACK TO COURSE CONTENTS)
