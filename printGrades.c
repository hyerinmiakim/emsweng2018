#include <string.h>

int printGrades(char* std_num)
{
  char path[150];
  FILE *sfp;
  int count=0;
  float sum=0.0;

  sprintf(path,"%s%s",std_num,".txt");
  sfp = fopen(path,"rt");

 if(sfp == NULL)
 {
    //error
 }
 else
 {
  char subject[50];
  float grade = 0.0;
  int credit=0;
  fscanf(sfp,"%s %f %d",subject,&grade,&credit);

  while( !feof( sfp ) )
  {
//    printf("%s\n", subject);
//    printf("%.1f\n", grade);
//    printf("%d\n", credit);

    sum = sum + grade*credit;
    count = count + credit;
    fscanf(sfp,"%s %f %d",subject,&grade,&credit);
  }
  printf("%d과목의 전체 성적은 %.3f 입니다.\n", credit, sum/(float)count);  
  fclose(sfp);
 }
 return 0;
}


