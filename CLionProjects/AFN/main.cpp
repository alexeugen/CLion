#include <iostream>
#include "AFN.h"

using namespace std;

int main()
{
    AFN a1("/home/eugen/CLionProjects/AFN/date");


    if (a1.check("aaaaaabbbbbbbbbbbb",0,0))
        cout<<"Da";
    else
        cout<<"Nu";

    return 0;
}