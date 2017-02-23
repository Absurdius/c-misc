#include "nameserverinterface.h"
#include "vns.h"
#include <vector>
#include <algorithm>

using namespace std;

VNS::VNS()
{
data = vector<pair<HostName, IPAddress>>;
}

// ugly code but gets job done
void VNS::insert(const HostName& name, const IPAddress& addr)
{
	vector.push_back(pair(name, addr));
}

//elemt: position where element recdies
//elemt is a pointer... i think
//find_if returns
bool VNS::remove(const HostName& name)
{
	elemt = find(name);
	if(elemt = data.end){return false;}
	delete elemt;
	return true;
}

IPAddress VNS::lookup(const HostName&)
{
	vector<na_pair>::iterator elemt;
	elemt = find_if(data.begin, data.end, exists);
	return *elemt.address;
}
