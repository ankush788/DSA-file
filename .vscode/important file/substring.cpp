
#include<bits/stdc++.h>
using namespace std;
int subs(string input ,string output[])
{
	 if(input.empty())
	 {return 1;
	 
	}
	string s=input.substr(1);
	 int output1=subs(s,output);
	 for(int i=0;i<output1;i++)
	 {
	 	output[i+output1]=input[0]+output[i];
	 }

return 2*output1;}
int main()
{
string input;
cin>>input;
string* output= new string[1000] ;
subs(input,output);
int l= input.size();
int c= pow(2,l);
for(int i=0;i<c;i++)
{

cout<<output[i]<<endl;
}

return 0 ;}

