#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
#include <sys/types.h>    
#include <unistd.h>

int main(int argc, char** argv)
{
	uid_t uid ,euid;
	
	char cmd[2048] = {0};
	
	int i,ret=0;
 	
	FILE * fp;
 
	if(argc < 2)
	{
		printf("Usage:super cmd \n");
		
		exit(0);
	}
 	
	uid = getuid() ;

	if(uid != 48 )
	{
		printf("Process no grant\n");
	
		exit(0);	
	}

	euid = geteuid();
 
 	
	setreuid(euid, uid);  
 
 	
	ret = system(cmd); 
 	
	
	return ret;
 }  
