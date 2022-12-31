#include<bits/stdc++.h>
#include<stack>
using namespace std;
bool check(char k,stack<char>s1)
{ 
if(k==']'&& s1.top()=='[')
{ 
return true;
}
if(k==')'&& s1.top()=='(')
{ 
return true;
}
if(k=='}'&& s1.top()=='{')
{ 
return true;
}
return false;
}
int main()
{
stack<char>s1;
char eq[]="{[([])]}";
 int index=0;
while(eq[index]!='\0')
{
	if( eq[index]=='('||eq[index]=='['||eq[index]=='{')
	 {
	 s1.push(eq[index]);	 
	 }
	 if( eq[index]==')'||eq[index]==']'||eq[index]=='}')
	 { 
	 	 if(!check(eq[index],s1))
	 	 { 
	 	 cout<<"inbalance equation"<<endl;
		   return-1;}
		s1.pop();
	 }
	 index++;
}
if( s1.empty())
{
	 cout<<"balance equation "<<endl;
	 return 0;
}
cout<<"parenthesis are not match"<<endl;
return -1;}

