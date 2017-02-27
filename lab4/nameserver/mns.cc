#include "nameserverinterface.h"
#include "mns.h"
#include <map>
#include <algorithm>

using namespace std;

MNS::MNS(){}

MNS::~MNS()
{
	data.clear();
}

// ugly code but gets job done
void MNS::insert(const HostName& name, const IPAddress& addr)
{
	data[name] = addr;
}

//elemt: position where element recdies
//elemt is a pointer... i think
//find_if returns
bool MNS::remove(const HostName& name)
{
		auto it = data.find(hn);
		if (it != data.end()) {
			server.erase(it);
			return true;
		}
		return false;
}

IPAddress MNS::lookup(const HostName& name)
{
	auto itr = data.find(name);
	if (itr == data.last()) {return NON_EXISTING_ADDRESS;}
	return itr->second;
}
