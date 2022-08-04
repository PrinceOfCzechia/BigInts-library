<h1>BigInts library</h1>

A school project from the 3rd semester at Faculty of Nuclear Sciences and Physical Engineering (FNSPE),
Czech Technical University (CTU), Prague, written by Petr Kral in 2022.


The code (most likely) accompanying this file implements arithmetic operations with numbers **up to two hundred digits long**
(or any other number respectively, the length can be easily adjusted via the file *range.h*) represented as arrays of characters. The
ultimate goal was to provide class *BigInt*, a 'data type' which implements **addition, subtraction, multpilication, division** and **modulo**
operations on instances of itself and can as such be treated as a regular integer of chosen maximum length.
Description of individual files' functions follows:


<h3>range.h</h3>

This file functions solely to **state maximum length** of a single BigInt via a constant unsigned integer *N*, which represents this length.


<h3>charray.h and charray.cpp</h3>

Class **Charray provides an array of characters and length *N***. Its functions allow it to create a new instance in several ways, acces
individual 'numbers' - characters *'0'*, *'1'*, *'2'*, *'3'*, *'4'*, *'5'*, *'6'*, *'7'*, *'8'* and *'9'* - change their value and add a Charray to a stream.
Here, the default option is *cout*, but the user can adjust this to their liking.


<h3>bigUnsgnd.h and bigUnsgnd.cpp</h3>

**BigUnsgnd extends charray with arithmetic operations** and overloads operators *+*, *-*, *\**, */* and *%*. The desired manipulation is achieved via
Charray functions, several auxiliary functions and algorithms of **long** (a.k.a. by hand or the traditional way) 
**addition, subtraction, multiplication and division**. Note that subtraction is actually differentiation in this case, since there is no
sign for BigUnsgnd. I prefered to use the word 'subtract' though, because differentiation may imply some derivative shenanigans which
are not implemented here.


<h3>bigInt.h and bigInt.cpp</h3>

BigInt has a **BigUnsgnd property** - its absolute value - and a **bool for sign**, where *1* or *true* represents *+*, while *0* or *false* represents *-*.
Arithmetic operations are implemented by performing analogical operation on BigUnsgnds - absolute values of concerned BigInts - and
adjusting the result's sign according to signs and absolute values of original BigInts.

<h3>Exceptions</h3>

In this program, two possible errors arise: invalid input into a constructor on Charray level (since all instances
of BigInt contain an instance of Charray) and division by zero and related issue with modulo.

The first case is dealt with simply using an *if* statement and leaving the user a warning message in the *cerr* stream.

Division by zero throws an *exception* which is to be caught when trying to divide two instances of BigInt, in this particular case,
the code goes like this:

```
try {
    
        e = d/c;
        
        cout << "d/c=" << e;
        
} catch(exception &e) {

        cerr<<e.what()<<endl;
        
        return 1;
        
}
```


<h3>Expected behaviour</h3>

All the operations *+*, *-*, *** and */* work just as the reader would expect and could calculate by hand.

In this program, I define modulo in such way, that a result of (integer) division times the divisor plus modulo add up
the original dividend, e.g. *(a/b)\*b + a%b = a*. This is in line with the original C/C++ definiton.

In the event of array overflow, the overflowing cipher is discarded, so just like with any other data type, it is most recommended
to proceed with caution when working with large (relatively to the size of the data type) numbers. For example adding *a+a*,
where BigInt *a* has *'6'* in position *199* (or other value of *N-1* in the event of changing BigInt's range), the operator *+* will return
a BigInt with a *'2'* in position *199*. The carry, since it cannot be added anywhere, is simply deleted when the function resolves.

Division and modulo by zero both throw a *BigIntException* which is to be caught wherever it is thrown.

Another place where something could go wrong are the constructors, or rather invalid inputs into them. This issue is tackled
via an *if* statement. Any input, which is not among *'0'* and *'9'*, is changed to *'0'*. The excpetion lets the user know that it changed
their values and the calculations may potentially vary from what the user intended.

When a constructor is given an array of length larger than *N* as an input, the BigInt constructed contains only the last *N* elements
(numerals) from the array. The rest is not used in any way.


**Author's notes:**

Functions *print()* and *printShort()* are kept, but not really recommended to use for printing, since the overloaded *<<* operator
seems to be much more convenient to use.


Implementation of all the operators *==*, *!=*, *>*, *<*, *>=*, *<=* is in fact unnecessary for the library's functionality, yet the author
deems they might come in handy while using the library for actual calculations outside the implementation itself. By default, some
of them are redundant though.


In this readme, I did not explicitly mention all functions in each class, the aim of this text was to get the reader
acquainted with the philosophy of the project.

The reader is of course very much invited to study and perhaps improve the code (there are certainly more efficient
algortihms than long multiplication and long division, but implementing them was not the purpose of this program)
if they feel like it.
