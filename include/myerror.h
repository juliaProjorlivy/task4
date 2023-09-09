#ifndef MYERROR_H
#define MYERROR_H

#include <errno.h>
#include <string.h>

#define ERROR(err) (fprintf(stderr, "☠️  Error %s: %d, %s\n", (err), errno, strerror(errno)))

#endif
