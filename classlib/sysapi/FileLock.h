#ifndef CLASSLIB_SYSAPI_FILE_LOCK_H
# define CLASSLIB_SYSAPI_FILE_LOCK_H
# include "classlib/sysapi/system.h"
# ifdef _WIN32
#  include <windows.h>
# else
#  include <unistd.h>
#  include <fcntl.h>
#  include <cerrno>
#  include <cstdlib>
# endif
#endif // CLASSLIB_SYSAPI_FILE_LOCK_H
