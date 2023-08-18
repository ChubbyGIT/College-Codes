#include <stdio.h>
void BF(int bS[], int blocks, int pS[], int proccesses)
{
 int all[proccesses];
 int occupied[blocks];

 for(int i = 0; i < proccesses; i++){
 all[i] = -1;
 }

 for(int i = 0; i < blocks; i++){
 occupied[i] = 0;
 }
 for (int i = 0; i < proccesses; i++)
 {

 int index = -1;
 for (int j = 0; j < blocks; j++) {
 if (bS[j] >= pS[i] && !occupied[j])
 {
 if (index == -1)
 index = j;

 else if (bS[j] < bS[index])
 index = j;
 }
 }
 if (index != -1)
 {
 all[i] = index;

 occupied[index] = 1;
 }
 }
 printf("\nProcess No.\tProcess Size\tBlock no.\n");
 for (int i = 0; i < proccesses; i++)
 {
 printf("%d \t\t\t %d \t\t\t", i+1, pS[i]);
 if (all[i] != -1)
 printf("%d\n",all[i] + 1);
 else
 printf("Not Allocated\n");
 }
}
int main()
{
 int bS[] = {100, 50, 30, 120, 35};
 int pS[] = {40, 10, 30, 60};
 int blocks = sizeof(bS)/sizeof(bS[0]);
 int proccesses = sizeof(pS)/sizeof(pS[0]);
 BF(bS, blocks, pS, proccesses);
 return 0 ;
}