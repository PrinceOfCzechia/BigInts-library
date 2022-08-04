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
    int aux1 = 69420;
    //Charray a(aux1);

    char aux2[] = {'1','f','7','7','3','2','3','\0'};
    //Charray b(aux2);

    BigInt c(aux1); // number constructor, sign is given by the argument
    //c.setSgn(0);
    cout << "c=" << c; //c.printShort();


    BigInt d(aux2,0); // array constructor, setting sign to minus
    cout << "d=" << d; //d.printShort();


    //BigInt e;

    /*
    try
    {
        e = d/c;
        cout << "d/c=" << e;
    }
    catch(exception &e)
    {
        cerr<<e.what()<<endl;
        return 1;
    }
    */

    /*
    try
    {
        BigInt f = d%c;
        cout << "d%c=" << f;
    }
    catch (exception &e)
    {
        cerr<<e.what()<<endl;
    }
    */

    /*
    e = d-c;
    cout << "d-c=" << e;
    */

    /*
    e = c*d;
    cout << "c*d=" << e;
    */

    /*
    e = c+d;
    cout << "c+d=" << e;
    */

    return 0;
}
