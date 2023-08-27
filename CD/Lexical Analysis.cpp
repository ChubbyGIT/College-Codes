#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int IK(char Buffer[]){
char kw[32][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};
int i, f = 0;
for(i = 0; i < 32; ++i){
if(strcmp(kw[i], Buffer) == 0){
f = 1;
break;
}
}
return f;
}
int main(){
char c, Buffer[15], op[] = "+-*/%=";
ifstream fin("P.txt");
int i,j=0;
if(!fin.is_open()){
cout<<"error while opening the file\n";
exit(0);
}
while(!fin.eof()){
 c = fin.get();

for(i = 0; i < 6; ++i){
 if(c == op[i])
 cout<<c<<" is operator\n";
 }

 if(isalnum(c)){
 Buffer[j++] = c;
 }
 else if((c == ' ' || c == '\n') && (j != 0)){
 Buffer[j] = '\0';
 j = 0;

 if(IK(Buffer) == 1)
 cout<<Buffer<<" is keyword\n";
 else
 cout<<Buffer<<" is indentifier\n";
 }

}
fin.close();
return 0;
}

/*Program file:- (Name:- P.txt)
Content :-
void main()
{
int a, b, c;
c = a – b;
}*/