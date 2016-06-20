#include "types.h"

struct uproc {
	char state[10];   // Process state
	int pid;                // Process ID
	uint uid;
  	uint gid;
  	uint ppid;
  	uint size;   			// Size of file in bytes
	char name[16];          // Process name (debugging)
};

