## Subjects

1. Given a sorted array [x] of integers and f(x)=x^x function, write a program that will produce a sorted array [y] with y[i]=f(x[i]) elements in O(n) time.
2. Write a program that will count the number of inversions in an array in O(nlogn) time.
3. Given nxn matrix, where n is a positive integer, write a program that will clockwise rotate the matrix 90 degrees. Write the non-in-place version using O(nxn) space.
4. Write the in-place version for problem3 using O(1) space. E.g.: Input: n=4 matrix: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 Output: 13 9 5 1 14 10 6 2 15 11 7 3 16 12 8 4.
5. Given a string of words separated by spaces. Write a O(n) program to reverse the string. E.g.: Input: "abc ef" Output: "fe cba".
6. Write a O(n) program to reverse the words in a string. E.g.: Input: "abc defg hi klmn" Output: "klmn hi defg abc".
7. Define Student structure containing the following fields: "name" for first and last names, "group" for group number, grades for grades array of 10 subjects. Write a function that will input n students from the given stream and will save them sorted by the average of grades.
8. Write a program that will take an input string and will print the data of students from problem07 whose first name ends with the given string letters.
9. Given an n-sized array of non-negative integers, write a program that will arrange the elements in such a way, that their concatenation will be produce the largest possible number. The function should return the resulting number a single string. Note: Since the concatenation may produce a larger integer than allowed, to avoid overflow use std::string.
10. Write a program that takes n and d integers as arguments, where d is necessarily a power of 2, and computes "n modulo d", namely the remainder, using bitwise operations, i.e. without % or /.
11. Write a program that takes n and d integers as arguments, and left-rotates n by d bits. Example: input: n=16, i.e. (000...00010000)2 d=2 output: 64, i.e. (000...01000000)2.
12. Write a program that takes an integer and checks if it's a power of 4 in O(1).
13. Write a program that takes n, p, r as integer arguments and swaps the bits of position p and r in n. Example: Input: n=11, i.e. (0...01011)2, p=1, r=4 Output: 25, i.e. (0....11001)2.
14. Extend the swapping program(problem13) so that it takes the 4th integer q, indicating the number of bits to swap. Example: Input: n=47, i.e. (00101111)2, p=1, r=5, q=3 Output: 227, i.3. (11100011)2.
15. Write C-style variadic function that takes a string and a bunch of numbers, and replaces each "#" symbol with corresponding number. replace("aa# nn # cc## e", 3, 12, -2, 1) should return "aa3 nn 12 cc-21 e".
16. Solve problem15 using variadic template.
17. Write a optimal function, that takes a positive integer n and returns the smallest power of 2 larger than n. Try to solve using O(1) time complexity.
18. Write a program using templates to calculate factorial of the given number during compilation(compile time).
19. Solve problem18 using constexpr function.
20. Write a program using templates to calculate nth Fibonacci number during compilation(compile time).
21. Implement high order function, which multiply given 2 numbers, located in different parentheses. Use lambda expressions to solve this problem. Example: <code>mult(5)(8)</code> return value 40.
22. Solve problem21 for 5 numbers, which locates in 5 different parentheses. Example: <code>mult(2)(7)(-8)(6)(3)</code> return value -2016.
