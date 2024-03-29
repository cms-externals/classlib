#ifndef CLASSLIB_FILE_ERROR_H
# define CLASSLIB_FILE_ERROR_H
# include "classlib/iobase/IOError.h"

namespace lat {

/** File-system related exception class. */
class FileError : public IOError
{
public:
    FileError (const char *context, int code = 0);
    FileError (const char *context, Error *chain);
    FileError (Error *chain);

    virtual std::string	explainSelf (void) const;
    virtual Error *	clone (void) const;
    virtual void	rethrow (void);
};

} // namespace lat
#endif // CLASSLIB_FILE_ERROR_H
