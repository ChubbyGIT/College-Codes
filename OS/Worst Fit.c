#include <stdio.h>
void WF(int bS[], int blocks, int pS[], int processes)
{
 int all[processes];
 int occ[blocks];

 for(int i = 0; i < processes; i++){
 all[i] = -1;
 }

 for(int i = 0; i < blocks; i++){
 occ[i] = 0;
 }
 for (int i=0; i < processes; i++)
 {
int index = -1;
for(int j = 0; j < blocks; j++)
{
 if(bS[j] >= pS[i] && !occ[j])
 {
 if (index == -1)
 index = j;

 else if (bS[index] < bS[j])
 index = j;
 }
 }
 if (index != -1)
 {
 all[i] = index;

 occ[index] = 1;
 bS[index] -= pS[i];
 }
 }
 printf("\nProcess No.\tProcess Size\tBlock no.\n");
 for (int i = 0; i < processes; i++)
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
 int processes = sizeof(pS)/sizeof(pS[0]);
 WF(bS, blocks, pS, processes);
 return 0;
}