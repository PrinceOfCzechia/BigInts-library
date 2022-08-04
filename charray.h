#ifndef CHARRAY_H
#define CHARRAY_H

#include <iostream>
#include <cmath>
#include "range.h"

class Charray
{
    char array[N];
public:
    Charray();
    Charray(unsigned long n);
    Charray(char arr[]);
    ~Charray();
    void setNum(unsigned n, unsigned i);
    char getNum(unsigned i);
    void print(std::ostream &out = std::cout);
    void printShort(std::ostream &out = std::cout);
    void fillWithZeros();
};

std::ostream& operator<<(std::ostream &out, Charray a);

#endif // CHARRAY_H
