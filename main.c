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

char(*funnel(char* _csvfile))[max];
char(*get_the_info(char* sub, void *_minor))[max];

int main()
{
 // input
 char name[100], std_num[20], grade = '\0', subj[50];
 char full_path[150];
 char* p;


 FILE *fp = NULL;


 printf("Enter you NAME :\n"); 
 fgets(name,100, stdin);

 printf("Enter your STUDENT NUMBER :\n"); 
 fgets(std_num,20,stdin);

/*
 printf("Enter your subjects : \n");
 fgets(subj,50,stdin);

 printf("Enter your grade : \n");
 fgets(&grade,2,stdin);
*/

 //remove enter key
 if((p = strchr(name, '\n'))!= NULL)   *p = '\0';
 if((p = strchr(std_num, '\n'))!= NULL)   *p = '\0';
 if((p = strchr(subj, '\n'))!= NULL)   *p = '\0';
 //if(!(grade == '\n'))   *p = '\0';

 // save in the text file.
 sprintf(full_path,"%s%s",std_num,".txt");
 fp = fopen(full_path,"w");
 if(fp != 0)
 {
  fprintf(fp, "%s %s %s\n", name,std_num, subj);   
  //fprintf(fp, "%s %s", name,std_num);   
  fclose(fp);
 }
 else  printf("fail\n");
 

/* call the functions.
  char *psubj = '\0';
        psubj = subj;
  char(*arr)[max] = funnel("2018_ese.csv.0");
  char(*info2)[max] = get_the_info(psubj, &arr[0]);
*/
 gpa(std_num);


 // for printing and handling arr: *arr[0][2], info[0][3]

 return 0;
}
