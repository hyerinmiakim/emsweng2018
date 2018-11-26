#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

int main()
{
 // input
 char path[] = "./home/chaeyujin/sw_eng/project";
 char name[100], std_num[20], ch;
 char full_path[150];
 char* p;
 FILE *fp = NULL;

 printf("Enter you name :\n"); 
 fgets(name,100, stdin);

 printf("Enter your student number :\n"); 
 fgets(std_num,20,stdin);



 //remove enter key

 if((p = strchr(name, '\n'))!= NULL)   *p = '\0';
 if((p = strchr(std_num, '\n'))!= NULL)   *p = '\0';



 // save in the text file.
 sprintf(full_path,"%s%s",std_num,".txt");
 printf("%s",full_path);

 fp = fopen(full_path,"w");
 if(fp != 0)
 {
  fprintf(fp, "%s %s\n", name,std_num);   
  fclose(fp);
 }
 else
  printf("fail\n");

 return 0;

}
