
#include "classlib/utils/Log.h"
#include <stdio.h>
#include <new>

namespace lat {

//<doc>		Console logger.
//
//		This is a loggind device that dumps all output to the standard
//		error.
class StderrLog : public logstream
{
public:
    StderrLog (void);
    ~StderrLog (void);

protected:
    virtual void	emit (const char *psz, int n);
};


logstream *
logstream::createStderrLogDevice (const char *)
{
    // make sure the log stays around beyond destructors
    static char		data[sizeof(StderrLog)];
    static StderrLog	*log = new (&data[0]) StderrLog;
    return log;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

//<doc>		Initialise a console logging device.
StderrLog::StderrLog (void)
{ }

//<doc>		Flush the log.
StderrLog::~StderrLog (void)
{
    flush ();
}

//<doc>		Dump output to the console.
//<args>	string			The data to write.
//		length			The length of data to write.
void StderrLog::emit (const char *string, int length)
{
    // std::cerr.write (string, length);
    // std::cerr.flush ();
    fwrite (string, 1, length, stderr);
    fflush (stderr);
}

} // namespace lat
