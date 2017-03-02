#include "nameserverinterface.h"
#include "hns.h"
#include <vector>
#include <algorithm>

using namespace std;

HNS::HNS(int size)
{
	table_size = size;
	data = vector<pair<HostName, IPAddress>>(size);
}

// ugly code but gets job done
void HNS::insert(const HostName& name, const IPAddress& adress)
{
	hash<string> hashed;
	size_t hash = hashed(name) % table_size;
	while (data[hash].first != "") hash = (hash + 1) % table_size;
	data[hash] = make_pair(name, adress);
}

//elemt: position where element recdies
//elemt is a pointer... i think
//find_if returns
bool HNS::remove(const HostName& name)
{
	std::hash<string> hasher;
		size_t hash = hasher(name) % table_size;
		while (data[hash].first != name && data[hash].first != "") hash = (hash + 1) % table_size;
		if (data[hash].first == ""){
			return false;
		}
		data[hash].first = "";
return true;
}

IPAddress HNS::lookup(const HostName& name) const
{
	std::hash<string> hasher;
			size_t hash = hasher(name) % table_size;
			while (data[hash].first != name && data[hash].first != "") hash = (hash + 1) % table_size;
			if (data[hash].first == ""){
				return NON_EXISTING_ADDRESS;
			}
	return data[hash].second;
}
