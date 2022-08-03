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
    void print();
    void printShort();
    void fillWithZeros();
};

#endif // CHARRAY_H
