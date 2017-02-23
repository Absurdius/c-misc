#include "nameserverinterface.h"
#include "umns.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

VNS::VNS()
{
data = unordered_map<na_pair>;
}

// ugly code but gets job done
void VNS::insert(const HostName&, const IPAddress&)
{
	na_pair in;
	in.name = HostName;
	in.address = IPAddress;
	data.insert(in);
}

//elemt: position where element recdies
//elemt is a pointer... i think
//find_if returns
bool VNS::remove(const HostName&)
{
	unordered_map<na_pair>::iterator elemt;
	elemt = find_if(data.begin, data.end, exists);
	if(elemt = data.end){return false;}
	delete *elemt;
	return true;
}

IPAddress VNS::lookup(const HostName&)
{
	unordered_map<na_pair>::iterator elemt;
	elemt = find_if(data.begin, data.end, exists);
	return *elemt.address;
}
//check that the element exists
private bool exists (const HostName&, na_pair element)
{
	return (HostName == element.name);
}
