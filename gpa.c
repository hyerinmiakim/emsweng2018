#include <string.h>

char full_path[150];
char subj[50];
char grade[10];
char *end = "finish";

void gpa(char* std_num)
{
 FILE *fp = NULL;

 // open the text file.
 sprintf(full_path,"%s%s",std_num,".txt");
 fp = fopen(full_path,"a");


 //if you want to finish saving grade, put 'e'
 //otherwise put your subject&grade

while(1)
{
  printf("Enter your subjects. if you want to finish, enter 'finish': \n");
  fgets(subj,50,stdin);
  *(subj +strlen(subj)-1)='\0';
  if(strcmp(subj,end) == 0) break;
  
  printf("Enter your grade : \n");
  fgets(grade,10,stdin);
  *(grade +strlen(grade)-1)='\0';
  if(strcmp(grade,end) == 0) break;

  // save data in the text file.
  if(fp != 0)
  {
   fprintf(fp, "%s %s \n",subj ,grade ); 
  }
  else  printf("fail\n");
}

 fclose(fp);
}
