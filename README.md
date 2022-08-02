<h1>BigInts library</h1>

a school project from the 3rd semester at Faculty of Nuclear Sciences and Physical Engineering (FNSPE),
Czech Technical University (CTU), Prague, written by Petr Kral in 2022


The code (most likely) accompanying this file implements arithmetic operations with numbers up to two hundred digits long
(or any other number respectively, the length can be easily adjusted) represented as character arrays. The ultimate goal was
to provide class BigInt, a 'data type' which implements addition, subtraction, multpilication, division and modulo operations
on itself and can as such be treated like a regular integer of chosen maximum length.
Description of individual files' functions follows:


<h3>range.h</h3>

This file functions solely to state maximum range of a single BigInt via a constant unsigned integer N, which represents this range.


<h3>charray.h and charray.cpp</h3>

Class Charray provides an array of characters and length N. Its functions allow it to create a new instance in several ways, acces
individual 'numbers' - characters '0', '1', '2', '3', '4', '5', '6', '7', '8' and '9' and change their value
and print a Charray to the console.


<h3>bigUnsgnd.h and bigUnsgnd.cpp</h3>

BigUnsgnd extends charray with arithmetic operations and overloads operators +, -, *, / and %. The desired manipulation is achieved via
Charray functions, several auxiliary functions and algorithms of long (a.k.a. by hand or the traditional way) 
addition, subtraction, multiplication and division. Note that subtraction is actually differentiation in this case, since there is no
sign for BigUnsgnd. I prefered to use the word 'subtract' though, because differentiation may imply some derivative shenanigans which
are not implemented here.


<h3>bigInt.h and bigInt.cpp</h3>

BigInt has a BigUnsgnd property - its absolute value - and a bool for sign, where 1 or true represents +, while 0 or false represents -.
Arithmetic operations are implemented by performing analogical operation on BigUnsgnds - absolute values of concerned BigInts - and
adjusting the result's sign according to signs and absolute values of original BigInts


<h3>Expected behaviour</h3>

All the operations +, -, * and / work just as the reader would expect and could calculate by hand.

I frankly do not know, whether and how modulo of negative numbers is defined. In this program, I define modulo in such way,
that a result of (integer) division times the divisor plus modulo add up the original dividend, e.g. (a/b)*b + a%b = a.

In the event of array overflow, the overflowing cipher is discarded, so just like with any other data type, it is most recommended
to proceed with caution when e.g. adding two large (relatively to the size of the data type) numbers. For example adding a+a,
where BigInt a has '6' in position 199 (or other value of N-1 in the event of changing BigInt's range), the operator + will return
a BigInt with a '2' in position 199 and the carry, hence it cannot be added anywhere, is simply deleted when the function resolves.


**Author's notes:**


Implementation of all the operators ==, !=, >, <, >=, <= is in fact unnecessary for the library's functionality, yet the author
deems they might come in handy while using the library for actual calculations outside the implementation itself. By default, some
of them are redundant though.


Aside from logical errors, which are hopefully tackled by now, only place where something could go wrong are the constructors,
or rather invalid inputs into constructors. This issue is tackled via an exception and any input, which is not among '0' and '9'
is changed to '0'. The excpetion lets the user know that it changed their values and the calculations may potentially vary from
what the user intended. So far, the exception prints is message in the console, but its function can easily be used in other ways.


In this readme, I did not explicitly mention all functions in each class, the aim of this text was to get the reader
acquainted with the philosophy of the project.
The reader is of course very much invited to study and perhaps improve the code (There are certainly more efficient
algortihms than long multiplication and long division, at the moment of coding, the author did not feel numerically proficient
enough to implement e.g. Karatsuba's algorithm, which I have only briefly heard of. There is probably also a similar thing for
division) if they feel like it.
