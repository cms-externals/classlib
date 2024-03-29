#ifndef CLASSLIB_FILENAME_ERROR_H
# define CLASSLIB_FILENAME_ERROR_H
# include "classlib/iobase/IOError.h"

namespace lat {

/** Filename expansion error class. */
class FilenameError : public Error
{
public:
    enum Reason {
	UNTERMINATED_VAR,	//< Unterminated variable reference
	BAD_SYNTAX,		//< Badly formed variable
	NO_SUCH_VAR		//< Non-existent variable
    };

    FilenameError (Reason cause, const std::string &spec = "");

    Reason		reason (void) const;
    const std::string &	variable (void) const;

    virtual std::string	explainSelf (void) const;
    virtual Error *	clone (void) const;
    virtual void	rethrow (void);

private:
    Reason		m_reason;
    std::string		m_spec;
};

} // namespace lat
#endif // CLASSLIB_FILENAME_ERROR_H
