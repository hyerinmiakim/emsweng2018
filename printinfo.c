#define max 10000
#include <string.h>
char(*get_the_info(char* _subject, char** _minor))[max]
{

 printf("%ld\n", strlen("창의설계입문"));

system("cat 2018-1_b.csv.0 | grep 창의설계입문");

char param[] = "현장교육";
char (*hyr)[];
hyr = &param;
printf("%s\n", (*hyr));
//for (int i = 0; i<(int)strlen(*hyr); i++)
//	printf("%c", (*hyr)[i]);

int len = strlen(*hyr);
//printf("subject length: %d\n",len);
char str[len]; //for searching
char info[8][max];  //return arr

for (int i = 0; i < 400; i++)
{
	for (int j = 0; j < len; j++)
	{
		str[j] = _minor[1][i+j];

	}

	//compare user's parameter with data in minor arr.
	if (!strncmp((*hyr), str,len-1))
	{
	 printf("str is same w/ str --- %s\n",str);
	 char temp = i;	//remember the index of 'a start point of subject'
	 int cnt = 0; 
	 while (cnt < 3) //count the number of ','
	 {
	   if (_minor[1][temp] == ',')
		cnt++;
 	   temp--;
	 }
	 // temp will know where the first comma is.
	 int n = 0, v = 0; // n for column, v for row
	 for (int k = temp - 12; k < i;k++)
	 {//the reason why 12 is 'size of each korean character(3)' * 'number of korean character(4)' 
		if (_minor[1][k] == ',')
                        {printf(" "); n++; v=0; continue;}
                printf("%c", _minor[1][k]);
		info[n][v] = _minor[1][k];
		v++;

	 }
        }
}

return info;
}

