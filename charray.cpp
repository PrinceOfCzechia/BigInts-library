#include "charray.h"
#include "string.h"

// CONSTRUCTORS and AUXILIARY functions

void Charray::fillWithZeros()
{
    for(unsigned i=0; i<N; i++)
    {
        this->array[i]='0';
    }
}

Charray::Charray()
{
    this->fillWithZeros();
}

Charray::Charray(unsigned long n)
{
    this->fillWithZeros();
    unsigned carry = 0;
    unsigned aux = 0;
    for(int i = 1; i<10; i++)
    {
        aux = pow(10, i);
        carry = n%aux;
        n -= carry;
        this->setNum(carry*10/aux, i-1);
    }
    this->setNum((n-(n%aux))/aux,9);
}

Charray::Charray(char arr[])
{
    this->fillWithZeros();
    unsigned length = strlen(arr);
    for(unsigned i = 0; i<length; i++)
    {
        this->setNum(arr[length-1-i]-'0',i);
    }
}

Charray::~Charray(){}

// several functions to handle instances of Charray

void Charray::setNum(unsigned n, unsigned i)
{
    if(n<10) this->array[i]=n+'0';
    else
    {
        std::ostream &out = std::cerr;
        out<<"WARNING: Invalid input was changed to zero"<<std::endl;
        this->array[i]='0';
    }
}

char Charray::getNum(unsigned i)
{
    return this->array[i];
}

void Charray::print(std::ostream &out)
{
    for(unsigned i=0; i<N; i++)
    {
        out<<this->getNum(N-i-1);
    }
    out<<std::endl;
}

void Charray::printShort(std::ostream& out)
{
    bool virgin = 1;
    for(unsigned i=0; i<N; i++)
    {
        char aux = this->getNum(N-i-1);
        if(aux!='0') virgin = 0;
        if(!virgin) out<<aux;
    }
    if(virgin) out<<'0';
    out<<std::endl;
}

std::ostream& operator<<(std::ostream& out, Charray a)
{
    bool virgin = 1;
    for(unsigned i=0; i<N; i++)
    {
        char aux = a.getNum(N-i-1);
        if(aux!='0') virgin = 0;
        if(!virgin) out<<aux;
    }
    if(virgin) out<<'0';
    out<<std::endl;
    return out;
}
