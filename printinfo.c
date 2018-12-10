#define max 10000
#include <string.h>
char info[8][max] = {"\0"}; //return array. it has only info of subject that user wants to know.

char(*get_the_info(char* sub, void *_minor))[max]
{
  
  if(*sub == '\0')
  {
	perror("READING SUBJECT ERROR");
	exit(0);
  }
 for (int a = 0; a < 7;a++)
{
	for (int b=0;b<max/2;b++)
	{
		info[a][b] = '\0';
	}
}
//printf("\n●  START PRINTINFO ● \n");
char (*arr)[max];
arr = _minor;
int len = strlen(sub);
int h,i,j=0;
char str[len]; //for searching
//printf("%s", sub);
for (h = 0; h < 7; h++)
{
for (i = 0; i < max/2; i++)
{
	for (j = 0; j < len; j++)
		str[j] = arr[h][i+j]; // now searching at section 'b' 

	//compare user's parameter with data in minor arr.
	if (!strncmp(sub, str,len-1))
	{
	 // printf("str is same w/ str --- %s\n",str);
	 int temp = i;	//remember the index of 'a start point of subject'
	 int cnt = 0; 
	 while (cnt < 5) //count the number of ','
	 {
	   if (arr[h][temp] == ',')
		cnt++;
 	   temp--;
	 }
	 // temp will know where the first comma is.
	 int n = 0, v = 0, k = 0; // n for column, v for row
	 for (k = temp - 11; k < i+(len+3);k++)
	 {
//the reason why 12 is 'size of each korean character(3)' * 'number of korean character(4)' 
		if (arr[h][k] == ',')
                        {printf(" "); n++; v=0; continue;}
                info[n][v] = arr[h][k];
		v++;
	 }
	 info[n][v]='\n';
        }
}
}

/*for (int i = 0; i < 8;i++)
        {
         for (int j = 0; j < max; j++)
         {
                printf("%c", info[i][j]);
         }
        printf("\n");
        }
*/
return info;
}

