#ifndef CLASSLIB_SYSAPI_IO_PLATFORM_DATA_H
# define CLASSLIB_SYSAPI_IO_PLATFORM_DATA_H
# include "classlib/sysapi/system.h"
# ifdef _WIN32
#  include <windows.h>
# endif

namespace lat {

#ifdef _WIN32
struct IOPlatformData
{
    // FIXME: what if we get a random handle and can't do olap?
    // FIXME: maintain level-triggered state -- when read ready,
    //   maintain it until it would return EWOULDBLOCK, then
    //   null it out (similar to write, ...)
    // FIXME: simulate unix? files are always ready?
    DWORD	m_state;
    OVERLAPPED	m_olap;
};
#else
struct IOPlatformData {};
#endif

} // namespace lat
#endif // CLASSLIB_SYSAPI_IO_PLATFORM_DATA_H
