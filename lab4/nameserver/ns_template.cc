#include "nameserverinterface.h"

class VNS : public NameServerInterface
{
  public:
    virtual ~NameServerInterface() = default;
    virtual void insert(const HostName&, const IPAddress&) = 0;
    virtual bool remove(const HostName&) = 0;
    virtual IPAddress lookup(const HostName&) const = 0;
  private:
}

VNS::VNS()
{
  //constructor
}

void VNS::insert(const HostName&, const IPAddress&)
{}

bool VNS::remove(const HostName&)
{}

IPAddress VNS::lookup(const HostName&)
{}
