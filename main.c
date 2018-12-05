#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "funnel_a2.c"
#include "printinfo.c"
char(*funnel(char* _csvfile))[max];
char(*get_the_info(char* _subject, char** _minor))[max];

int main()
{
 // input
 char name[100], std_num[20], ch;
 char full_path[150];
 char* p;


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
 fp = fopen(full_path,"w");
 if(fp != 0)
 {
  fprintf(fp, "%s %s\n", name,std_num);   
  fprintf(fp, "%s %s", name,std_num);   
  fclose(fp);
 }
 else  printf("fail\n");
 

 // call the func named funnel 
 char(*arr)[max] = funnel("2018_ese.csv.0");
 //char(*info)[max] = get_the_info(NULL,arr);

 // for printing and handling arr: *arr[0][2]...


 return 0;
}
