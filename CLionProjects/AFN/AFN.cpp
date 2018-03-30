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

    fin>>nrD;
    D=new tranz[nrD];
    for (i=0;i<nrD;i++)
    {
        fin>>D[i].a>>D[i].c>>D[i].b;
    }
    sc=0;
    gasit = false;
}

bool AFN::check(char *cuvant, int sc, int poz)
{
    int i;

    if (poz==strlen(cuvant))
    {
        for (i=0;i<nrF;i++)
            if (sc==F[i])
            {
                gasit = true;
                return true;
            }
    }
    else
    {
        for (i=0;i<nrD;i++)
        {


          if (gasit)
              return true;
            if ((D[i].a==sc)&&(D[i].c==cuvant[poz]))
            {
                check(cuvant,D[i].b,poz+1);
            }
        }

        return false;
    }
}