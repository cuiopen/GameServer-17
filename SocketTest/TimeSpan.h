#include "platform.h"
#include <stdio.h>

#if defined(_WIN32_PLATFROM_)
#include <Windows.h>
#define timelong_t ULARGE_INTEGER
#endif

#if defined(_LINUX_PLATFROM_)
#include <sys/time.h>
#include <linux/errno.h>
#define timelong_t struct timeval
#endif


class CMyTimeSpan
{
public:
	 CMyTimeSpan();
	 void Reset();
	 unsigned long long GetSpaninMicroseconds();
	 unsigned int GetSpaninMilliseconds();
	 unsigned int GetSpaninSeconds();

private:
	 timelong_t m_start;
	 void getCurrentTimeLong(timelong_t *tl);

};
