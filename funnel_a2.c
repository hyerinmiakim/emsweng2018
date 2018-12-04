#define max 100000

void funnel(char* _csvfile)
{
  int fd;
  char ch[max];
  char minor[28][max];
  char mi;
  fd = open(_csvfile, O_RDWR);
  if (fd == -1)
  {
   perror("open error");
   exit(0);
  }

  read(fd, ch, max-1);
  ch[max-1] = '\0';
  int i = 0, j = 999;
  while(ch[i] != '\0')
  {
	if (ch[i] == 'a')
                j = 0;
	else if (ch[i] == 'b')
                j = 1;
 	else if (ch[i] == 'c')
                j = 2;
	else if (ch[i] == 'd')
                j = 3;

	if (j!=999)
	{
	 int w = 0;
	 for (int k=0; k<(i-1); k++)
	 {
 	  if (ch[k] == ',')
  	    continue;
	  minor[j][w] = ch[k];
	  w++;
	 }
	 j = 999;
	}
   printf("%c", ch[i]);
   i++;
  }

printf("reading finish. \n");
int h=0;
while(minor[3][h] != '\0')
{
	printf("%c", minor[3][h]);
	h++;
}

}

