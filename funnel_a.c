#define max 100000

void funnel()
{
  int fd;
  char ch[max];
  char minor[28][max];
  char mi;
  fd = open("2018-1_b.csv.0", O_RDWR);
  if (fd == -1)
  {
   perror("open error");
   exit(0);
  }

  read(fd, ch, max-1);
  ch[max-1] = '\0';
  int i = 0, j = 0;
  while(ch[i] != '\0')
  {
   if(ch[i] == 'a')
    {
	printf("helloo");
	int w = 0;
	for (int k=i; k<0; k--)
	{
 	printf("wt");
	 if (ch[w] == ',')
  	 { printf("tric");	continue;}
 	 
	minor[j][w] = ch[w];
	printf("hhhhhhhhhhhhhhh%c ", ch[w]);
	 w++;
	}
     }

   printf("%c", ch[i]);
   i++;
  }

printf("hyerin\n");
int w=0;
if(minor[0][w] == '\0')
{
	printf("empty");
	printf("%c", minor[0][w]);
	w++;
} 
}

