#include <stdio.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main(void){
	struct utsname uts;
	struct sysinfo si;

	if (uname(&uts)==-1){
		perror("uname");
		return 1;
	}
	
	if (sysinfo(&si)==-1){
		perror("sysinfo");
		return 1;
	}
	
	printf("system info\n\n");
	printf("SYS NAME: %s\n",uts.sysname);
	printf("Node name: %s\n", uts.nodename);
	printf("Release: %s\n", uts.release);
	printf("Version: %s\n", uts.version);
	printf("Machine: %s\n", uts.machine);

	printf("\nsystem stats\n\n");
	printf("Uptime: %ld seconds\n", si.uptime);
	printf("Total RAM: %lu MB\n", si.totalram / 1024 / 1024);
	printf("Free RAM: %lu MB\n", si.freeram /1024 /1024);
	printf("number of processes: %d\n", si.procs);

	return 0;
}
