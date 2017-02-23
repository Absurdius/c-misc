/*
 * Interface UMNS
 * implement this interface.
 */
#ifndef UMNS_H
#define UMNS_H
#include <map>
#include <unordered_map>

class UMNS
{
  public:
    virtual void insert(const HostName&, const IPAddress&) ;
    virtual bool remove(const HostName&) ;
    virtual IPAddress lookup(const HostName&) const ;
  private:
  std::map::unordered_map data<HostName, IPAddress> data;
};

#endif
