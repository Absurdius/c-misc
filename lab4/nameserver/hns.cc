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
void HNS::insert(const HostName& name, const IPAddress&)
{
	hash<string> hashed;
	size_t hash = hashed(name) % table_size;
	while (server[hash].first != "") hash = (hash + 1) % table_size;
	server[hash] = make_pair(hn, adress);
}

//elemt: position where element recdies
//elemt is a pointer... i think
//find_if returns
bool HNS::remove(const HostName&)
{
	std::hash<string> hasher;
		size_t hash = hasher(hn) % table_size;
		while (server[hash].first != hn && server[hash].first != "") hash = (hash + 1) % table_size;
		if (server[hash].first == ""){
			return false;
		}
		server[hash].first = "";
return true;
}

IPAddress HNS::lookup(const HostName&)
{
	std::hash<string> hasher;
			size_t hash = hasher(hn) % table_size;
			while (server[hash].first != hn && server[hash].first != "") hash = (hash + 1) % table_size;
			if (server[hash].first == ""){
				return NON_EXISTING_ADDRESS;
			}
	return server[hash].second;
}
//check that the element exists
private bool exists (const HostName&, na_pair element)
{

}
