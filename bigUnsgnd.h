#ifndef BIGUNSGND_H
#define BIGUNSGND_H

#include "charray.h"

class BigUnsgnd: public Charray
{
    // big unsigned extends charray with arithmetic properties
    Charray digits;
public:
    BigUnsgnd();
    BigUnsgnd(unsigned long value);
    BigUnsgnd(char arr[]);
    BigUnsgnd(Charray value);
    ~BigUnsgnd();
    void setNum(unsigned n, unsigned i);
    char getNum(unsigned i);
    void print();
    void printShort();
    BigUnsgnd multiplyBy(unsigned q);
    BigUnsgnd shiftLeft(unsigned q);
    BigUnsgnd shiftRight();
    bool greaterThan(BigUnsgnd b);
    bool lesserThan(BigUnsgnd b); // unnecessary, but may come in handy
    bool geq(BigUnsgnd b); // as well
    bool leq(BigUnsgnd b); // and as well
    bool eq(BigUnsgnd b);

    bool operator>(BigUnsgnd b);
    bool operator<(BigUnsgnd b);
    bool operator>=(BigUnsgnd b);
    bool operator<=(BigUnsgnd b);
    bool operator==(BigUnsgnd b);
    bool operator!=(BigUnsgnd b);
    BigUnsgnd operator+(BigUnsgnd b);
    BigUnsgnd operator-(BigUnsgnd b);
    BigUnsgnd operator*(BigUnsgnd b);
    BigUnsgnd operator*(unsigned c);
    BigUnsgnd operator/(BigUnsgnd b);
    BigUnsgnd operator%(BigUnsgnd b);
};

BigUnsgnd add(BigUnsgnd a, BigUnsgnd b);
BigUnsgnd difference(BigUnsgnd a, BigUnsgnd b);
BigUnsgnd multiply(BigUnsgnd a, BigUnsgnd b);
BigUnsgnd divide(BigUnsgnd a, BigUnsgnd b);
BigUnsgnd modulo(BigUnsgnd a, BigUnsgnd b);

#endif // BIGUNSGND_H
