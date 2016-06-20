#include "ps.h"
#include "types.h"
#include "user.h"

int 
main(int argc, char *argv[])
{
	static int MAX = 20;
	struct uproc tbl[MAX];
	
	int size = getprocs(MAX, tbl);
	
	if(size==0){
		printf(2, "uproc_failed: get table for uproc failed\n");
	    exit();
    }
	
	printf(1,"PID UID GID PPID STATE    SIZE   NAME\n");
	int i;
	for (i=0; i < size;i++){
		printf(1,"%d   %d   %d   %d    %s %d  %s\n",
		tbl[i].pid,tbl[i].uid, tbl[i].gid,tbl[i].ppid, tbl[i].state, tbl[i].size, tbl[i].name);
	}
	
   exit();
}
