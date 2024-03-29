#include "test/Test.h" 
#include "classlib/utils/Log.h"
#include "classlib/utils/Signal.h"

/**   
 *      Example on how to use Seal Log 
 */

using namespace lat;

int TEST(int, char **)
{
    LOG (2, warning, LFinit, "This is an initialization message\n");
    LOG (2, trace, LFgeneral, "This is a general message\n");
    LOG (-1, error, LFassert, "This is an error message which will be always visible\n");
 
    return 0;
}
