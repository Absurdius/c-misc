/*
 * Interface MNS
 * implement this interface.
 */
#ifndef MNS_H
#define MNS_H
#include <map>

class MNS
{
  public:
    virtual void insert(const HostName&, const IPAddress&);
    virtual bool remove(const HostName&);
    virtual IPAddress lookup(const HostName&) const;
  private:
    std::map<HostName, IPAddress> data;
};

#endif
