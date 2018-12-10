#include <stdio.h>
void graduate(char* subarr)
{
  char(*arr)[max] = funnel("new_2018_ese.csv.0"); 
<<<<<<< HEAD
//  printf("********HELLO THIS IS GRADUATE*********\n%s\n", subarr);
   int cnt[5] = {0,0,0,0,0}; 
  int i, j = 0, q=0,w=0;
=======
  printf("********HELLO THIS IS GRADUATE*********\n%s\n", subarr);
  int hy = 0;
  int cnt[5] = {0,0,0,0,0}; 
  int i, j;
>>>>>>> e3dd49d2eb12219ec37a74a835a98ff213cd4413
  int st = 0;

for (i = 0; i < strlen(subarr); i++)
{
	if(subarr[i] == '-')
	{
	 char frag[50] = {"\0"};
	 int index = 0;
	 for(j = st; j < i; j++)
	 {
	  frag[index] = subarr[j];
	  index++;
	 }
	
//	 printf("This is frag: %s\n", frag);
	 printf("**********INFORMATION************\n");	 
	 get_the_info(frag, &arr[0]);
         for (q = 0; q < 8;q++)
        {
         for (w = 0; w < max; w++)
         {
                printf("%c", info[q][w]);
         }
        printf("\n");
        }

	// check cnt from info	
	switch(info[6][1])
	 {
		case  97:
			cnt[0] = cnt[0] + (info[4][0] - 48);	
			break;
		case  98: 
                        cnt[1] = cnt[1] + (info[4][0] - 48);   
                        break; 
 		case  99: 	
                        cnt[2] = cnt[2] + (info[4][0] - 48);  
                        break; 
 		case  100: 
                        cnt[3] = cnt[3] + (info[4][0] - 48);
                        break; 
 		case 101:
                        cnt[4] = cnt[4] + (info[4][0] - 48);
                        break;
		default: 
			printf("%d    %c\n", info[6][1], info[6][1]);
			break; 
	  }
	i+=2; 
	st=i;
	continue;
	}


}
printf("현재 교양필수는 %d점, 전공기초는 %d점, 전공선택은 %d점, 전공필수는 %d점, 일반선택은 %d점 이수함. \n", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);
printf("졸업을 위해서는 총 140점을 이수해야하며. 전공은 72학점 이상, 교양은 30~55학점 이내로 이수하여야 합니다. \n 졸업요건을 충족하기 위해선 전공 %d학점, 교양 %d학점이 남았습니다. 또한, 전체충족학점을 채우기 위해선 %d학점이 남았습니다. ", (72-(cnt[1]+cnt[2]+cnt[3])), (55 - cnt[0]), (140 - (cnt[0]+cnt[1]+cnt[2]+cnt[3]+cnt[4])));
	//get_the_info(subarr, &arr[0]);


}
