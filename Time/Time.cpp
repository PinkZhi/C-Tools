#include "Time.h"

#include <memory.h>

time_t GetCurrentTimeStamp()
{
    return time(NULL);
}

time_t TimeStrToTimeStamp(const std::string& dateTime)
{
    struct tm tm;
    memset(&tm, 0, sizeof(tm));
    sscanf(dateTime.c_str(), "%d-%d-%d %d:%d:%d",
           &tm.tm_year, &tm.tm_mon, &tm.tm_mday,
           &tm.tm_hour, &tm.tm_min, &tm.tm_sec);
    tm.tm_year -= 1900;
    tm.tm_mon--;
    return mktime(&tm);
}

void TimeStampToTimeStr(time_t timeStamp, std::string& ret_dateTime)
{
    tm* tmp_tm = localtime(&timeStamp);
    char time_str[64] = {0};
    sprintf(time_str,"%04d-%02d-%02d %02d:%02d:%02d",
		tmp_tm->tm_year + 1900, tmp_tm->tm_mon + 1,tmp_tm->tm_mday,
		tmp_tm->tm_hour,tmp_tm->tm_min,tmp_tm->tm_sec);
    ret_dateTime=time_str;
}