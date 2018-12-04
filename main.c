#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "funnel_a2.c"
char** funnel(char* _csvfile);
int main()
{
 // input
 char name[100], std_num[20], ch;
 char full_path[150];
 char* p;
 char (**arr)[28][max] = malloc(sizeof(char *)*28);

 FILE *fp = NULL;

 for (int i=0; i<28;i++) {
	arr[i] = malloc(sizeof(char)*max);
 }
 arr = funnel("2018_ese.csv.0");

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
 
 return 0;
}
