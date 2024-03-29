#ifndef CLASSLIB_IO_OUTPUT_H
# define CLASSLIB_IO_OUTPUT_H
# include "classlib/iobase/IOBuffer.h"

namespace lat {

/** Abstract base class for stream-oriented output targets. */
class IOOutput
{
public:
    virtual ~IOOutput (void);
    // implicit constructor
    // implicit copy constructor
    // implicit assignment operator

    IOSize		write (unsigned char byte);
    IOSize		write (IOBuffer from);
    virtual IOSize	write (const void *from, IOSize n) = 0;
    virtual IOSize	writev (const IOBuffer *from, IOSize buffers);

    IOSize		xwrite (const void *from, IOSize n);
    IOSize		xwrite (IOBuffer from);
    IOSize		xwritev (const IOBuffer *from, IOSize buffers);

protected:
    // Trap migration errors, these are undefined.  Use x/readv() instead.
    IOSize		write (IOBuffer *into, IOSize buffers);
    IOSize		xwrite (IOBuffer *into, IOSize buffers);
};

} // namespace lat
#endif // CLASSLIB_IO_OUTPUT_H
