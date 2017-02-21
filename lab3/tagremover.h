#ifndef TAGREMOVER_H
#define TAGREMOVER_H

#include <string>
#include <iostream>
#include <fstream>

class Tagremover {
 public:
  Tagremover(std::istream& in);
  void print(std::ostream& out);

 private:
  std::istream& instream;
	std::ifstream test;
};

#endif
