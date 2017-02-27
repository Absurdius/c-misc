/*
 * Interface NameServerInterface -- all name server implementations must
 * implement this interface.
 */
#ifndef NAME_SERVER_INTERFACE_H
#define NAME_SERVER_INTERFACE_H

#include <string>
#include <utility> 

using HostName = std::string;
using IPAddress = unsigned int;
const IPAddress NON_EXISTING_ADDRESS = 0;

bool operator==(std::pair<HostName, IPAddress> a, std::pair<HostName, IPAddress> b)
{
	return a.first == b.first; 
}

bool operator== (std::pair<HostName, IPAddress> na_pair, const std::string str)
{
	return na_pair.first == str; 
}


class NameServerInterface {
public:
	virtual ~NameServerInterface() = default;

	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	virtual void insert(const HostName&, const IPAddress&) = 0;

	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	virtual bool remove(const HostName&) = 0;

	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	virtual IPAddress lookup(const HostName&) const = 0;
};

#endif
