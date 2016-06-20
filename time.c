#include "types.h"
#include "user.h"
#include "date.h"

int 
main(int argc, char *argv[])
{
   struct rtcdate startDate;
   struct rtcdate endDate;

   date(&startDate);

   int pid = fork();

   if (pid < 0){ //invalid, throw error 
	printf(2, "time_failed: invalid pid\n");
	exit();
   }
   if (pid>0) //parent
	wait();
   if (pid == 0){ // in child
 	if(exec(argv[1],argv+1)){
	    printf(2, "time_failed: exec failed\n");
	    exit();
        }
   }

   date(&endDate);

   long startSec = startDate.hour * 60 * 60 + startDate.minute * 60 + startDate.second;
   long endSec = endDate.hour * 60 * 60 + endDate.minute * 60 + endDate.second;

   long totalMin = (endSec - startSec)/60;
   long totalSec = (endSec - startSec)%60;

   printf(1,"%s ran in %d minutes and %d seconds.\n",argv[1], totalMin, totalSec);

   exit();
}
