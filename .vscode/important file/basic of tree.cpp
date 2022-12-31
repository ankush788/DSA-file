#include<bits/stdc++.h>
using namespace std; 
 template<typename t>
 class tree{
 	public:
 	t data ; //tree ke node  ( tree node) ka value store karega
    vector<tree<t>*>children ;/// child node  ka address store karega  (tree pointer data type ka vector)  
    tree( t data)
    {
    	this->data= data;
	}
 	
 };
 
int main()
{ 
tree<int> t1(10);                  //root
 tree<int>t2(20);                 //child 1
  tree<int>t3( 40);              /////child 2
  t1.children.push_back(&t2);   ////child 1 ka address push kiya root kke vector me push kiya
  t1.children.push_back(&t3);  //////child 2 ka address push kiya root ke vector me push kiya
for( int i =0;i<t1.children.size();i++)
{
	 cout<<(t1.children[i])->data <<endl;
}
return 0 ;}


