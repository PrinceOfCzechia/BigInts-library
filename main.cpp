#include <iostream>
//#include "range.h"
//#include "charray.h"
//#include "bigUnsgnd.h"
// bigInt.h contains the commented includes, also bigUnsgnd.h
// contains charray.h and charray.h contains range.h
#include "bigInt.h"

using namespace std;

int main()
{
    int aux1 = 4;
    Charray a = Charray(aux1);

    char aux2[] = {'1','0','7','7','3','1','3','\0'};
    Charray b = Charray(aux2);


    BigInt c = BigInt(a);
    //c.setSgn(0);
    cout << "c=";
    c.printShort();


    BigInt d = BigInt(b);
    //d.setSgn(0);
    cout << "d=";
    d.printShort();


    BigInt e = d/c;
    cout << "e=";
    e.printShort();

    BigInt f = d%c;
    cout << "f=";
    f.printShort();

    /*
    BigInt e = d-c;
    e.printShort();
    */

    /*
    BigInt e = c*d;
    e.printShort();
    */

    /*
    BigInt e = c-d;
    e.printShort();
    */

    return 0;
}
