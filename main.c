#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "funnel_a2.c"
#include "printinfo.c"
#include "gpa.c"
#include "graduate.c"

char(*funnel(char* _csvfile))[max];
char(*get_the_info(char* sub, void *_minor))[max];
void graduate();


int main()
{
 // input
 char name[100], std_num[20], grade = '\0', subj[50];
 char full_path[150];
 char* p;
 int i,j;

 FILE *fp = NULL;


 printf("Enter you NAME :\n"); 
 fgets(name,100, stdin);

 printf("Enter your STUDENT NUMBER :\n"); 
 fgets(std_num,20,stdin);


 //remove enter key
 if((p = strchr(name, '\n'))!= NULL)   *p = '\0';
 if((p = strchr(std_num, '\n'))!= NULL)   *p = '\0';



 // save in the text file.
 sprintf(full_path,"%s%s",std_num,".txt");
 fp = fopen(full_path,"at");
 if(fp != 0)
 {
  fclose(fp);
 }
 else  printf("fail\n");


  gpa(std_num);  
  graduate();


 /* for printing and handling arr: *arr[0][2], info[0][3]
    printf("HI THIS IS FROM MAIN*******************\n");
	for ( i = 0; i < 8;i++)
	{
	  for ( j = 0; j < max; j++)
	  {
	   printf("%c", info[i][j]);
	  }
	  printf("\n");
	}
*/

 return 0;
}
