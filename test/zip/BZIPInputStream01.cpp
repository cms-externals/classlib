#include "test/Test.h" 
#include "classlib/zip/BZIPInputStream.h"
#include "classlib/iobase/File.h"
#include "classlib/iobase/Filename.h"
#include "classlib/iotools/StorageInputStream.h"
#include "classlib/iotools/BufferInputStream.h"
#include "classlib/utils/Signal.h"
#include <iostream>

using namespace lat;

int TEST(int, char **argv)
{
    Signal::handleFatal (argv [0]);

    File		input ("test.bz2");
    StorageInputStream	sinput (&input);
    BufferInputStream	binput (&sinput);
    BZIPInputStream	t (&binput);
    char		buf [1024];
    IOSize		read;

    while ((read = t.read (buf, sizeof (buf))))
	std::cout.write (buf, read);

    return 0;
}
