#define max 10000
#include <string.h>

char(*funnel(char* _csvfile))[max]
{
  int fd;
  char ch[max];
  static char minor[8][max] = {"\0"};

  fd = open(_csvfile, O_RDWR);
  if (fd == -1)
  {
   perror("open error");
   exit(0);
  }

  read(fd, ch, max-1);
  ch[max-1] = '\0';
  int i = 0, j = 999, start = 0, temp = 0,k=0;
  while(ch[i] != '\0')
  {
	// classify data as alphabet
	if (ch[i] == 'a')
                j = 0;
	else if (ch[i] == 'b')
                j = 1;
 	else if (ch[i] == 'c')
                j = 2;
	else if (ch[i] == 'd')
                j = 3;
	else if (ch[i] == 'e')
		j = 4;
	
	//j will be 999 when data don't have alphabet (normal data)
	if (j!=999) // when data is alphabet, this code parses data.
	{
	 int w = 0; // let us know last index of each alphabet array.
	 while(minor[j][w] != '\0')
		w++;

	 for (k=start; k< (i+1); k++) // 'start' knows the locations we should read
	 { 
 	  //if (ch[k] == ',')
  	    //continue;
	  minor[j][w] = ch[k];
	  w++;
	//  temp = i;
	 }
	 i+=2;
	 start = i; //remember an index of last data.
	 j = 999; //back to status to be a normal parsing mode.
	}
  // printf("%c", ch[i]);
   i++;
  }
/*
int e = 0;
while(minor[3][e] != '\0')
{	printf("%c", minor[3][e]);
	e++;
}
*/
printf("reading finish. \n");
return minor;

}

