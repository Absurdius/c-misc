//tag remover
#include <iostream>
#include "tagremover.h"

using namespace std;

Tagremover::Tagremover(istream &is)
{
  outline = "";
  char c;
  while(is.get())
  {
    if(&c == "<")
    {
      cout << "found tag";
    }
  }
}

void Tagremover::print(ostream &os)
{
  cout << outline;
}
