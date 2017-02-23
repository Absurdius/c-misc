/*
 * Interface vns
 * implement this interface.
 */
#ifndef VNS_H
#define VNS_H

#include <vector>

class VNS
{
  public:
  //  virtual ~NameServerInterface() = default;
    virtual void insert(const HostName&, const IPAddress&);
    virtual bool remove(const HostName&) ;
    virtual IPAddress lookup(const HostName&) const;
  private:
    //does not name a type !!!
  std::vector<std::pair<HostName, IPAddress>> data;
};

#endif
