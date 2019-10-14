#ifndef CLASSLIB_PUSH_BACK_INPUT_STREAM_H
# define CLASSLIB_PUSH_BACK_INPUT_STREAM_H
# include "classlib/iotools/FilterInputStream.h"

namespace lat {

class PushBackInputStream : public FilterInputStream
{
public:
    PushBackInputStream (InputStream *input);
    ~PushBackInputStream (void);

    using FilterInputStream::read;
    virtual IOOffset	available (void);
    virtual IOSize	read (void *into, IOSize n);
    virtual IOSize	skip (IOSize n);
    virtual void	close (void);
    virtual void	reset (void);

    virtual void	unread (const void *data, IOSize n);
    void		unread (IOBuffer from);

private:
    unsigned char	*m_buffer;
    unsigned char	*m_bottom;
    unsigned char	*m_top;
};

} // namespace lat
#endif // CLASSLIB_PUSH_BACK_INPUT_STREAM_H