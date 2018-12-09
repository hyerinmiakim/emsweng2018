#include <stdio.h>
void graduate()
{
 int cnt[4] = {-48, -48, -48, -48}; 
  int i, flag=0;
  printf("\n이수구분: ");
  for (i = 0; i < max; i++)
  {
	if(flag == 0)
	{
	 switch(info[6][i])
	 {
		case  97:
			cnt[0] = cnt[0] + info[4][i];	
			break;
		case  98: 
                        cnt[1] = cnt[1] + info[4][i];   
                        break; 
 		case  99: 
			printf("%c", 99);	
                        cnt[2] = cnt[2] + info[4][i];   
                        break; 
 		case  100: 
                        cnt[3] = cnt[3] + info[4][i];   
                        break; 
 		case 101:
                        cnt[4] = cnt[4] + info[4][i];   
                        break;
		default: 
			break; 
	  }
          flag = 1;
	}
	printf("%c", info[0][i]);
  }
 for (int i = 0; i < 4; i++)
 {
	if(cnt[i] != -48)
	{	
		printf("\n이수학점: %d\n", cnt[i]);
		break;
	}
 }
}
