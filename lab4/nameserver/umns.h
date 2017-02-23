/*
 * Interface UMNS
 * implement this interface.
 */
#ifndef UMNS_H
#define UMNS_H
#include <unordered_map>

class UMNS : public NameServerInterface
{
  public:
    UMNS();
    virtual void insert(const HostName&, const IPAddress&) ;
    virtual bool remove(const HostName&) ;
    virtual IPAddress lookup(const HostName&) const ;
  private:
  std::unordered_map<HostName, IPAddress> data;
};

#endif
