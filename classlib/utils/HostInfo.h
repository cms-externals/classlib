#ifndef CLASSLIB_HOST_INFO_H
# define CLASSLIB_HOST_INFO_H
# include "classlib/sysapi/system.h"
# include <string>

namespace lat {

/** Describe a host, and by default the current host.  */
class HostInfo
{
public:
    static std::string	name (void);
    static std::string	dnsname (void);
    static std::string	dnsdomain (void);
    static std::string	fqdn (void);

    // FIXME: for host name x?
    // FIXME: gethostbyname, gethostbyaddr, ...
private:
    static bool		isfqdn (const char *name);
};

} // namespace lat
#endif // CLASSLIB_HOST_INFO_H
