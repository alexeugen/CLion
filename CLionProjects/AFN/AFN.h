//
// Created by eugen on 3/30/18.
//

#ifndef AFN_AFN_H
#define AFN_AFN_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class AFN {
public:
    AFN(char *fisier);
    bool check(char *cuvant, int sc, int poz);
private:
    int nrQ, nrF;
    int *F;
    int nrE;
    char *E;
    int nrD;
    struct tranz
    {
        int a,b;
        char c;
    } *D;
    int sc;
    int exista;

};


#endif //AFN_AFN_H
