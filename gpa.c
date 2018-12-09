#include <string.h>

char full_path[150];
char subj[50];
char grade[10];
char *end = "finish";

void gpa(char* std_num)
{
 FILE *fp = NULL;
 int i,j;
  char studentData[50];    // 파일을 읽을 때 사용할 임시 공간
  char path[150];


 // open the text file.
 sprintf(full_path,"%s%s",std_num,".txt");
 fp = fopen(full_path,"a");

 // save information of subject in the text file.
  char *psubj = '\0';
  char(*arr)[max] = funnel("2018_ese.csv.0");
  float grd = 0.0;

while(1)
{
// input subject name.
  printf("과목명을 입력하세요(더이상 저장할 과목이 없을 때, 'finish'를 입력하세요)\n");
  fgets(subj,50,stdin);
  *(subj +strlen(subj)-1)='\0';
  //after 'finish'
  if(strcmp(subj,end) == 0) break;

// input grade.
  printf("성적을 입력하세요 (A+,A0,B+ ..등)\n");
  fgets(grade,10,stdin);
  *(grade +strlen(grade)-1)='\0';
  if(strcmp(grade,end) == 0) break;

  psubj = subj;
  get_the_info(psubj, &arr[0]);

	if(strcmp(grade,"A+")==0) grd = 4.5;
	if(strcmp(grade,"A0")==0) grd = 4.0;
	if(strcmp(grade,"B+")==0) grd = 3.5;
	if(strcmp(grade,"B0")==0) grd = 3.0;
	if(strcmp(grade,"C+")==0) grd = 2.5;

// save data in the text file.
  if(fp != 0)
  {
    fprintf(fp, "%s,%.1f,%d\n", subj ,grd, (info[4][0]-48)); 
  }
  else  printf("fail\n");
 }
 fclose(fp);

 return;
}
