#include <string.h>

char full_path[150];
char subj[50];
char grade[10];

void gpa(char* std_num)
{
 FILE *fp = NULL;

 // open the text file.
 sprintf(full_path,"%s%s",std_num,".txt");
 fp = fopen(full_path,"at");


 //if you want to finish saving grade, put 'z'
 //otherwise put your subject&grade
// do{

  printf("Enter your subjects : \n");
  fgets(subj,50,stdin);

  printf("Enter your grade : \n");
  fgets(grade,10,stdin);
 
  // save data in the text file.
  if(fp != 0)
  {
   fprintf(fp, "%s %s \n",subj ,grade ); 
  }
  else  printf("fail\n");
  
  if(subj == "0")
//    break;
// }while(1);


 fclose(fp);
}
