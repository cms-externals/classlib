#ifndef CLASSLIB_IOSELECT_KQUEUE_H
# define CLASSLIB_IOSELECT_KQUEUE_H
# include "IOSelectFdMap.h"
# if BSD > 0 || __APPLE__
#  include <sys/event.h>
#  include <errno.h>
#  include <vector>

namespace lat {

/** Implementation of #IOSelectMethod using kqueue() system call in
    FreeBSD 4.1 (may require a system patch).  */
class IOSelectKqueue : public IOSelectFdMap
{
public:
    IOSelectKqueue (void);
    ~IOSelectKqueue (void);

    // Attaching and detaching descriptors
    virtual void	attach    (const IOSelectRequest &req);
    virtual void	detach    (const IOSelectRequest &req);
    virtual void	clear     (void);

    // Descriptor listening states
    virtual void	setMask   (IOFD fd, unsigned value);
    virtual void	andMask   (IOFD fd, unsigned value);
    virtual void	orMask    (IOFD fd, unsigned value);

    // Selection	       
    virtual bool	wait      (long msecs);
    virtual IOFD	next      (IOSelectEvent &event, IOSelectCB &cb);

private:
    void		doSet     (IOFD fd, unsigned mask);
    void		doClear   (IOFD fd, unsigned mask);

    int				m_kqueue;	//< Kernel queue handle.
    std::vector<struct kevent>	m_changes;	//< Changes to the queue.
    std::vector<struct kevent>	m_results;	//< Results from last #kevent() call.
    size_t			m_nready;	//< Number of results in #m_nresults.
    size_t			m_current;	//< Counter for #next().
};

} // namespace lat
# endif // BSD > 0 || __APPLE__
#endif // CLASSLIB_IOSELECT_KQUEUE_H
