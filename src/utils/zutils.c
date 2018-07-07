#include "zutils.h"
#include "time.h"
#include <sys/time.h>


S64 getCurrentSecond(){
	time_t rawtime;
	time( &rawtime );
	return rawtime;
}

S64 getCurrentMillisecond{
	struct timeval start, end;
	gettimeofday( &start, NULL );
	return start.tv_sec +  start.tv_usec;
}


