#include <string.h>
#include "graduate.c"

char full_path[150];
char subj[50];
char grade[10];
char *end = "finish";
char subarr[50];

void gpa(char* std_num)
{
 FILE *fp = NULL;
 int i,j;

 // open the text file.
 sprintf(full_path,"%s%s",std_num,".txt");
 fp = fopen(full_path,"a");

 // save information of subject in the text file.
  char *psubj = '\0';
  //char(*arr)[max] = funnel("new_2018_ese.csv.0");
  float grd = 0.0;
  int flag = 0;
  int a=0, b = 0, c = 0;
  strcpy(subarr,"\0");
while(1)
{
// input subject name.
  printf("과목명을 입력하세요(더이상 저장할 과목이 없을 때, 'finish'를 입력하세요)\n");
  fgets(subj,50,stdin);
  *(subj +strlen(subj)-1)='\0';

 if((strcmp(grade,end)==0) || (strcmp(subj, end)==0))
  {
        flag = 1;
        break;
  }

// input grade.
  printf("성적을 입력하세요 (A+,A0,B+ ..등)\n");
  fgets(grade,10,stdin);
  *(grade +strlen(grade)-1)='\0';

// make subject array
  strcat(subj,"--");
  strcat(subarr, subj);
  printf("%s\n", subarr);

  if(strcmp(grade,"A+")==0 || strcmp(grade,"a+")==0) grd = 4.5;
  if(strcmp(grade,"A0")==0 || strcmp(grade,"a0")==0) grd = 4.0;
  if(strcmp(grade,"B+")==0 || strcmp(grade,"b+")==0) grd = 3.5;
  if(strcmp(grade,"B0")==0 || strcmp(grade,"b0")==0) grd = 3.0;
  if(strcmp(grade,"C+")==0 || strcmp(grade,"c+")==0) grd = 2.5;
  
  
// save data in the text file.
  if(fp != 0)
  {
    fprintf(fp, "%s %.1f %d %c\n", subj ,grd, (info[3][0]-48), info[2][0]);  
  }
  else  printf("fail\n");
 }

// after receive subjects from user 
if (flag == 1)
{
	graduate(subarr, flag);
	/*int hy = 0;
	printf("HERE!!\n");
	//while(subarr[hy] != '\0')
	
	 printf("%s\n", subarr);
//	 graduate(subarr); 
	*/
}

/*int st = 0;
for (int i = 0; i < strlen(subarr); i++)
{
	if(subarr[i] == '-')
	{
	 char frag[50] = {"\0"};
	 int index = 0;
	 for(int j = st; j < i; j++)
	 {
	  frag[index] = subarr[j];
	  index++;
	 }
	 printf("This is frag: %s\n", frag);
	 get_the_info(frag, &arr[0]);
	 graduate(frag);
	i+=2; 
	st=i;
	continue;
	// break;
	}
	//printf("%c", subarr[i]);
	

}
	//get_the_info(subarr, &arr[0]);

*/
 fclose(fp);

 return;
}
