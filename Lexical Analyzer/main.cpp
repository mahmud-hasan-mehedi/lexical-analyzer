#include<bits/stdc++.h>
using namespace std;
int Keycheck(char curr[]){
char keywords[32][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};
int i, flag = 0;
for(i = 0; i < 32; ++i){
if(strcmp(keywords[i], curr) == 0){
flag = 1;
break;
}
}
return flag;
}
int main(){
char ch, curr[15], operators[] = "+-*/%=";
ofstream MyFile("output.txt");
string keyarr[50];
string optarr[50];
string idtarr[50];
FILE *fp;
int i,j=0,l=0,m=0,z=0;
fp = fopen("input.txt","r");
if(fp == NULL){
MyFile<<"Error opening the file\n";
exit(0);
}
while((ch = fgetc(fp)) != EOF){
for(i = 0; i < 6; ++i)
    {
    if(ch == operators[i])
        {
        optarr[z] = ch; z++;
        }
    }
if(isalnum(ch)){
curr[j++] = ch;
}
else if((ch == ' ' || ch == '\n') && (j != 0)){
curr[j] = '\0';
j = 0;
if(Keycheck(curr) == 1){
keyarr[l] = curr;
l++;
}
// cout<<("%s is keyword\n", curr);
else{idtarr[m] = curr;m++;}
}
}
MyFile<<"Keywords are:"<<endl;
for(int u=0;u<(sizeof(keyarr)/sizeof(string));u++)
{
MyFile<<keyarr[u]<<"\t";
}
MyFile<<"\nIdentifiers are:"<<endl;
for(int u=0;u<(sizeof(idtarr)/sizeof(string));u++)
{
MyFile<<idtarr[u]<<"\t";
}
MyFile<<"\nOperators are:"<<endl;
for(int u=0;u<(sizeof(optarr)/sizeof(string));u++)
{
MyFile<<optarr[u]<<"\t";
}
fclose(fp);
return 0;
}
