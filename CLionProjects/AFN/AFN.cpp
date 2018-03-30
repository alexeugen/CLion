//
// Created by eugen on 3/30/18.
//

#include "AFN.h"

AFN::AFN(char *fisier)
{
    int i;
    ifstream fin(fisier);
    fin>>nrQ>>nrF;
    F=new int[nrF];
    for (i=0;i<nrF;i++)
        fin>>F[i];
    fin>>nrE;
    E=new char[nrE];
    for (i=0;i<nrE;i++)
        fin>>E[i];
    fin>>nrD;
    D=new tranz[nrD];
    for (i=0;i<nrD;i++)
    {
        fin>>D[i].a>>D[i].c>>D[i].b;
    }
    sc=0;
    exista=0;
}

bool AFN::check(char *cuvant, int sc, int poz)
{
    int i;

    if ((poz==strlen(cuvant))) //&&(sc<=nrQ)
    {
        for (i=0;i<nrF;i++)
            if (sc==F[i])
            {
                exista = 1;
                return true;
            }
    }
    else
    {
        for (i=0;i<nrD;i++)
        {


          if (exista==1)
              return true;
            if ((D[i].a==sc)&&(D[i].c==cuvant[poz))
            {
                check(cuvant,D[i].b,poz+1);
            }
        }

        return false;
    }
}