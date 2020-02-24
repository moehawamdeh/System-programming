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
		printf("Enter line or 'exit':\n>> ");
		scanf("%s",input);
		strcpy(data->line,input);
		//set ready
		data->flag=FLAG_DATA_RDY;
		if(0==strcmp(input,"exit"))
		{
			
			done=1;
			continue;		
		}
		//wait until done
		while(data->flag!=FLAG_DONE);
		

	}
	shmdt(data);
	//shmctl(id,IPC_RMID,NULL);
	exit(EXIT_SUCCESS);
       
return 0;
}	

