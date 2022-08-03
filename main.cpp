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
    int aux1 = 6;
    Charray a(aux1);

    char aux2[] = {'1','0','7','7','3','2','3','\0'};
    Charray b(aux2);


    BigInt c(aux1); // number constructor
    //c.setSgn(0);
    cout << "c=";
    c.printShort();


    BigInt d(aux2,0); // array constructor
    //d.setSgn(0);
    cout << "d=";
    d.printShort();

    BigInt e;

    e = d/c;
    cout << "e=";
    e.printShort();

    BigInt f = d%c;
    cout << "f=";
    f.printShort();

    /*
    e = d-c;
    e.printShort();
    */

    /*
    e = c*d;
    e.printShort();
    */

    /*
    e = c+d;
    e.printShort();
    */

    return 0;
}
