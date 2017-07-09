#ifndef TRACE_H
#define TRACE_H

#include <cstdio>


#define TRACE( format, args...)   printf( "%s::%s(%d)" format "\n", __FILE__, __FUNCTION__,  __LINE__ , ##args)




#endif // TRACE_H
