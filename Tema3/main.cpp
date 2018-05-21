#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

const int nrC = 4; //numarul de coloane

ifstream fin("date.in");

int nrQ, *Q, nrF, *F;
char **arr;
int n;
string cuv = "aaaabbbbbbbb";
string stack = "z";
char x, y;
char q;
int l;
string add[100];
string extra[100];

int get_line()
{
  for(int i = 0; i < n; i++)
      if(arr[i][0] == q && arr[i][1] == x && arr[i][2] == y)
        return i;
  cout<<"NEACCEPTAT SAU AUTOMAT DEFINIT GRESIT"<<endl;
  return 404;
}

int isFinal(int j)
{
  for(int i = 0; i < nrF; i++)
    if(F[i] == j-48)
      return 1;
  return 0;
}

int check()
{
  x = cuv.back();

  cuv.pop_back();
  y = stack.back();
  if((l = get_line()) == 404) return 0;
  cout<<q<<x<<y<<l<<" ";
  if(add[l] == string(1, '$'))
    stack.pop_back();
  else
  {
    if(extra[l] != string(1,'$'))
      stack.pop_back();
    stack += add[l];
  }
  q = arr[l][3];
  cout<<stack<<" "<<q<<endl;

  if(isFinal(q) && x == '$')
    {cout<<x; cout<<q;cout<<isFinal(q); return 1;};

  check();
}

int main()
{
  reverse(cuv.begin(), cuv.end());
  cuv.insert(0,"$");

  fin>>nrQ;
  Q = new int[nrQ];
  for(int i = 0; i < nrQ; i++)
    fin>>Q[i];
  fin>>nrF;
  F = new int[nrF];
  for(int i = 0; i < nrF; i++)
    fin>>F[i];

  fin>>n;
  arr = new char*[n];
  for(int i = 0; i < n; i++)
    arr[i] = new char[nrC];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < nrC; j++)
      fin>>arr[i][j];
  for(int i = 0; i < n; i++)
  {
    fin>>add[i];
    fin>>extra[i];
  }
    for(int i = 0; i < n; i++)
      cout<<add[i];

      cout<<endl;



  q = '0';
  if(check() == 1)
    cout<<"acceptat";
    cout<<F[0]<<nrF;



}
