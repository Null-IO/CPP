#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int main(int argc, char** argv) {
	const static size_t buffsize = 128;
	time_t t = time(nullptr);
	struct tm gmt;
	struct tm local;

	printf("On this system time is bits %I64u\n", sizeof(time_t) * 8);

	gmtime_s(&gmt, &t);
	localtime_s(&local, &t);

	printf("Universal time is now %04d-%02d-%02d %02d:%02d:%02d\n", gmt.tm_year + 1900, gmt.tm_mon + 1, gmt.tm_mday,
		gmt.tm_hour, gmt.tm_min, gmt.tm_sec);

	printf("Local time is now %04d-%02d-%02d %02d:%02d:%02d\n", local.tm_year + 1900, local.tm_mon + 1, local.tm_mday,
		local.tm_hour, local.tm_min, local.tm_sec);

	char buf[buffsize];
	size_t len = strftime(buf, buffsize, "%d-%m-%Y %H:%M:%S", &local);
	printf("Formatted local time now is %s\n", buf);
}