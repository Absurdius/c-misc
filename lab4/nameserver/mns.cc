#include "nameserverinterface.h"
#include "mns.h"
#include <map>
#include <algorithm>

using namespace std;

MNS::MNS()
{
data = map<pair<HostName, IPAddress>>;
}

// ugly code but gets job done
void MNS::insert(const HostName&, const IPAddress&)
{
	na_pair in;
	in.name = HostName;
	in.address = IPAddress;
	data.insert(in);
}

//elemt: position where element recdies
//elemt is a pointer... i think
//find_if returns
bool MNS::remove(const HostName&)
{
	map<na_pair>::iterator elemt;
	elemt = find_if(data.begin, data.end, exists);
	if(elemt = data.end){return false;}
	delete *elemt;
	return true;
}

IPAddress MNS::lookup(const HostName&)
{
	map<na_pair>::iterator elemt;
	elemt = find_if(data.begin, data.end, exists);
	return *elemt.address;
}
//check that the element exists
private bool exists (const HostName&, na_pair element)
{
	return (HostName == element.name);
}
