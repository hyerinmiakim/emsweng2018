#include <string.h>

int printGrades(char* std_num)
{
  FILE *sfp;
  sprintf(path,"%s%s",std_num,".txt");
  fp = fopen(path,"rt");
  fgets(studentData, sizeof(studentData), sfp);
  printf("%s\n", studentData);

  fclose(sfp);
 return 0;
}
