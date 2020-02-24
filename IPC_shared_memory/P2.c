#include"p12.h"

char input[100];
int main(){
        int id=shmget(  memKey, sizeof(Data) , IPC_CREAT|0666);
        if(id==-1)
        {
                perror("Error\n");     
                exit(EXIT_FAILURE);   
        }
	Data* data=(Data*)shmat(id,NULL, 0);
	

	int done=0;
	while(!done){
		printf("Waiting for input from P1...\n");
		while(data->flag!=FLAG_DATA_RDY);
		printf("Received:\n[%s]\n",data->line);
		if(strcmp(data->line,"exit")==0)
		{
			done=1;
			continue;		
		}
		int caps=0,small=0;
		int i=0;
		for(;i<strlen(data->line);i++){
			char c=data->line[i];
			if(c>='a'&&c<='z')
				++small;
			else if(c>='A'&&c<='Z')
				++caps;
		}
	
		printf("%i caps and %i smalls\n",caps,small);
		data->flag=FLAG_DONE;
	}
	shmdt(data);
	shmctl(id,IPC_RMID,NULL);
	exit(EXIT_SUCCESS);
       
return 0;
}	

