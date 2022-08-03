#include "charray.h"
#include "string.h"
#include "charrayExcpt.h"

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
    try
    {
        if(n<10) this->array[i]=n+'0';
        else throw (CharrayException("Invalid input was changed to '0'"));
    }
    catch (CharrayException e)
    {
        std::cout<<e.what()<<std::endl;
        this->array[i]='0';
    }
}

char Charray::getNum(unsigned i)
{
    return this->array[i];
}

void Charray::print()
{
    for(unsigned i=0; i<N; i++)
    {
        std::cout<<this->getNum(N-i-1);
    }
    std::cout<<std::endl;
}

void Charray::printShort()
{
    bool virgin = 1;
    for(unsigned i=0; i<N; i++)
    {
        char aux = this->getNum(N-i-1);
        if(aux!='0') virgin = 0;
        if(!virgin) std::cout<<aux;
    }
    if(virgin) std::cout<<'0';
    std::cout<<std::endl;
}
