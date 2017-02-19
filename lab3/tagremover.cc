//tag remover
#include <iostream>
#include "tagremover.h"

using namespace std;

Tagremover::Tagremover(istream &is)
{
  outline = "";
  string str ((istream_iterator<char>(is), istream_iterator<char>()));
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
  os& << outline;
}
