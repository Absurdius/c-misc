#include "nameserverinterface.h"
#include "vns.h"
#include <vector>
#include <algorithm>
#include <utility> 

using namespace std;

VNS::VNS()
{}

// ugly code but gets job done
void VNS::insert(const HostName& name, const IPAddress& addr)
{
	data.emplace_back(pair<HostName, IPAddress>(name, addr));
}

//elemt: position where element recdies
//elemt is a pointer... i think
//find_if returns
bool VNS::remove(const HostName& name)
{
	auto x = pair<HostName, IPAddress>(name, NON_EXISTING_ADDRESS);
	auto elemt = find(data.begin(), data.end(), x);
	if(elemt == data.end()){return false;}
	data.erase(elemt);
	return true;
}

IPAddress VNS::lookup(const HostName& name) const
{
	auto elemt = pair<HostName, IPAddress>(name, NON_EXISTING_ADDRESS);
	auto itr = find(data.begin(), data.end(), elemt);
	if (itr == data.end()) {return NON_EXISTING_ADDRESS;}
	return itr->second;
}
