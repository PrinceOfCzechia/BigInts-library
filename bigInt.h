#ifndef BIGINT_H
#define BIGINT_H

#include "bigUnsgnd.h"

class BigInt: public BigUnsgnd
{
    // big int ads sign and sign arithmetics for big unsigned
    // absolute value
    BigUnsgnd abs;
    // sign of the number, 1 for +, 0 for -
    bool sgn;
public:
    BigInt();
    ~BigInt();
    BigInt(long val);
    BigInt(Charray val);
    BigInt(BigUnsgnd val);
    void print();
    void printShort();
    BigUnsgnd getAbs();
    void setAbs(BigUnsgnd value);
    bool getSgn();
    void setSgn(bool sign);

    bool eq(BigInt b);
    bool greaterThan(BigInt b);
    bool lesserThan(BigInt b);
    bool geq(BigInt b);
    bool leq(BigInt b);

    bool operator==(BigInt b);
    bool operator!=(BigInt b);
    bool operator>(BigInt b);
    bool operator<(BigInt b);
    bool operator>=(BigInt b);
    bool operator<=(BigInt b);

    BigInt operator+(BigInt b);
    BigInt operator-(BigInt b);
    BigInt operator*(BigInt b);
    BigInt operator/(BigInt b);
    BigInt operator%(BigInt b);
};

BigInt add(BigInt a, BigInt b);
BigInt multiply(BigInt a, BigInt b);
BigInt divide(BigInt a, BigInt b);
BigInt modulo(BigInt a, BigInt b);

#endif // BIGINT_H
