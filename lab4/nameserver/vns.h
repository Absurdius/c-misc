/*
 * Interface vns
 * implement this interface.
 */
#ifndef VNS_H
#define VNS_H

#include <vector>

class VNS : public NameServerInterface
{
  public:
  //  virtual ~NameServerInterface() = default;
    VNS();
    virtual void insert(const HostName&, const IPAddress&);
    virtual bool remove(const HostName&) ;
    virtual IPAddress lookup(const HostName&) const;
  private:

  std::vector<std::pair<HostName, IPAddress>> data;
};

#endif
