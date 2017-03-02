#include "nameserverinterface.h"
#include "umns.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

UMNS::UMNS()
{
}

// ugly code but gets job done
void UMNS::insert(const HostName& name, const IPAddress& addr)
{
	data[name] = addr;
}

//elemt: position where element recdies
//elemt is a pointer... i think
//find_if returns
bool UMNS::remove(const HostName& name)
{
	auto target = pair<HostName, IPAddress>(name, NON_EXISTING_ADDRESS);
	auto elemt = find(data.begin(), data.end(), target);
	if(elemt == data.end()){return false;}
	data.erase(elemt);
	return true;
}

IPAddress UMNS::lookup(const HostName& name) const
{
	auto target = pair<HostName, IPAddress>(name, NON_EXISTING_ADDRESS);
	auto itr = find(data.begin(), data.end(), target);
	if (itr == data.end()) {return NON_EXISTING_ADDRESS;}
	return itr->second;
}
