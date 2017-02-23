#include "nameserverinterface.h"
#include "vns.h"
#include <vector>
#include <algorithm>

using namespace std;

VNS::VNS(){}

// ugly code but gets job done
void VNS::insert(const HostName&, const IPAddress&)
{
	na_pair in;
	in.name = HostName;
	in.address = IPAddress;
	vector.push_back(in);
}

//elemt: position where element recdies
//elemt is a pointer... i think
//find_if returns
bool VNS::remove(const HostName&)
{
	vector<na_pair>::iterator elemt;
	elemt = find_if(data.begin, data.end, exists);
	if(elemt = data.end){return false;}
	delete *elemt;
	return true;
}

IPAddress VNS::lookup(const HostName&)
{
	vector<na_pair>::iterator elemt;
	elemt = find_if(data.begin, data.end, exists);
	return *elemt.address;
}
//check that the element exists
private bool exists (const HostName&, na_pair element)
{
	return (HostName == element.name);
}
