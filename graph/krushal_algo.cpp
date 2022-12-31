//// it only applicable for connect graph and use to find m.s.t 
#include<bits/stdc++.h>
using namespace std;

class E{
    public:
 int v1; 
 int v2;
  int value; 

 void push( int i , int j , int k )
{
     v1=i ; 
     v2=j ;
     value= k ; 
}
 

};
/// /// //////////////////

bool compare( E obj1 ,E obj2 )
 {
     return obj1.value <obj2.value ;
 }
////////////////////////////////////////////

 int real_parent(int i , vector<int>&parent)
 {
    if( parent[i]== i )
    {
         return i ;

    }
   parent[i]  = real_parent(parent[i], parent);
   return parent[i]; 
 }

 //////////////////////////////

bool is_cyclic(E obj , vector<int>&parent ,vector<int>&rank )
{
    int i1 = real_parent(obj.v1, parent); 
    int j1 =real_parent( obj.v2, parent); 
    
     if( i1== j1 )
              {
                
                return true;
               
              }
              else
              {
                 if( rank[i1]>rank[j1])
                 {
                     parent[j1]= i1;
                 }
                 else if(rank[i1]<rank[j1])
                 {
                     parent[i1]= j1; 
                 }

                 else
                 {
                    rank[max(i1,j1)]++; 
                    parent[i1]= parent[j1]= max(i1,j1);
                      }
                   }
                      
return false ;

}

 //////////////////////////////////////

 vector<E> krushal( E edges[], int v ,int e)
 { 
    vector<E>ans;
      vector<int> parent(v, 0); 
    vector<int>rank(v, 0 ); 
    for( int i = 0 ; i<v ;++i)
    {
     parent[i]=i;     
        }

  sort( edges, edges+e, compare); /// note sorting me n-->'e' hi dalna 'v' nhi warna answer
  // galt aayega 
  
  
  int count = 0;
  int i = 0;

  while( count!=v-1 )
  { 
    if(is_cyclic(edges[i] ,parent ,rank)==0)
    {
      
        ans.push_back(edges[i]);
        count++;
    }

    i++;
  }
 return ans ;
 }
 int main()
{
int v ,e ; 
 cout<<" enter the no. of vertex and edges "<<endl ; 
 cin>>v>>e; 
E edges[e]; 
        for(int k = 0 ; k<e ;++k)
        {
            int i , j ,value ; 
             cout<<" enter the edges  and value  "<<endl; 
             cin>>i>>j>> value ;
              
              edges[k].push(i,j, value);

        }

vector<E>ans;
 ans= krushal( edges, v ,e ); 

  for( auto it : ans)
  {
     cout<< it.v1 <<"--> "<< it.v2<<"--> "<<it. value <<endl;
  }
  
  return 0;
}
