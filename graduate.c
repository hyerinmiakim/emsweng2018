void graduate()
{
  int cnt = -48;
  int i;
  printf("Course Completed Type: "); 
  for (i = 0; i < max; i++)
  {
	cnt = cnt+info[4][i];
	printf("%c", info[0][i]);
  }
  printf(" and Credit is %d. \n", cnt);
}

