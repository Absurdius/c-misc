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
    unsorted_vector data;
}

VNS::VNS()
{
data = unsorted_vector<HostName, IPAddress>
}

void VNS::insert(const HostName&, const IPAddress&)
{}

bool VNS::remove(const HostName&)
{}

IPAddress VNS::lookup(const HostName&)
{}
