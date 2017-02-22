#include "nameserverinterface.h"
#include <unsorted_vector>

class VNS : public NameServerInterface
{
  public:
    virtual ~NameServerInterface() = default;
    virtual void insert(const HostName&, const IPAddress&) = 0;
    virtual bool remove(const HostName&) = 0;
    virtual IPAddress lookup(const HostName&) const = 0;
  private:
    vector data;
}

VNS::VNS()
{
data = vector<na_pair>
}

void VNS::insert(const HostName&, const IPAddress&)
{
	na_pair in; 
	in.name = HostName;
	in.address = IPAddress;
	vector.push_back(in);
}

bool VNS::remove(const HostName&)
{
}

IPAddress VNS::lookup(const HostName&)
{}
