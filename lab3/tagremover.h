#ifndef TAGREMOVER_H
#define TAGREMOVER_H
#include <iostream>

class Tagremover {
public:
	Tagremover(std::istream &is);
	void print(std::ostream &os);
private:
	std::string outline;
};

#endif
