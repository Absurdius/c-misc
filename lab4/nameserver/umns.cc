#include "nameserverinterface.h"
#include "umns.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

VNS::VNS()
{
}

// ugly code but gets job done
void VNS::insert(const HostName& name, const IPAddress& addr)
{
	data[name] = addr;
}

//elemt: position where element recdies
//elemt is a pointer... i think
//find_if returns
bool VNS::remove(const HostName& name)
{
	auto elemt = find(name);
	if(elemt == data.end){return false;}
	delete *elemt;
	return true;
}

IPAddress VNS::lookup(const HostName& name)
{
	auto itr = data.find(name);
	if (itr == data.last()) {return NON_EXISTING_ADDRESS;}
	return itr->second;
}
