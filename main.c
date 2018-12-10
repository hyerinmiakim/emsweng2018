#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "printGrades.c"
#include "funnel_a2.c"
#include "printinfo.c"
#include "gpa.c"
//#include "graduate.c"

//char(*funnel(char* _csvfile))[max];
//char(*get_the_info(char* sub, void *_minor))[max];


int main()
{
 // input
 char name[100], std_num[20];
 char full_path[150];
 char* p;
 FILE *fp = NULL;
 


 printf("● 이름을 입력하세요:\n"); 
 fgets(name,100, stdin);

 printf("● 학번을 입력하세요:\n"); 
 fgets(std_num,20,stdin);

 //remove enter key
 if((p = strchr(name, '\n'))!= NULL)   *p = '\0';
 if((p = strchr(std_num, '\n'))!= NULL)   *p = '\0';

 // save in the text file.
 sprintf(full_path,"%s%s",std_num,".txt");
 fp = fopen(full_path,"at");
 if(fp != 0)
 {
  fclose(fp); // create txt file
 }
 else printf("fail\n");

 gpa(std_num);
 printGrades(std_num);
 


 return 0;
}
