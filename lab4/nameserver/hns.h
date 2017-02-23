/*
 * Interface HNS
 * implement this interface.
 */
#ifndef HNS_H
#define HNS_H
#include <vector>


class HNS
{
  public:
    virtual void insert(const HostName&, const IPAddress&) ;
  	virtual bool remove(const HostName&) ;
    virtual IPAddress lookup(const HostName&) const ;
  private:
    int table_size;
    std::vector<std::pair<HostName, IPAddress> > data;
};

#endif
