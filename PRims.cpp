#include <iostream>

using namespace std;

 

class graph{

 

public:

   int n;

   int cost[10][10];

 

   graph();

   void create();

   void display();

   void prim(int start_v);

};

 

graph::graph(){

 

   cout<<"Enter total number of cities:\n";

   cin>>n;

 

   for(int i=0;i<n;i++){

       for(int j=0;j<n;j++){

           cost[i][j]=999;

       }

   }

}

 

void graph::create(){

 

   int c1,c2,d;

   char ch;

 

   do{

 

       cout<<"Enter indices of cities to connect:\n";

       cin>>c1>>c2;

 

       cout<<"Enter distance:\n";

       cin>>d;

 

       if(c1<0 || c1>=n || c2<0 || c2>=n){

           cout<<"Invalid city index\n";

           continue;

       }

 

       if(cost[c1][c2]==999){

           cost[c1][c2]=d;

           cost[c2][c1]=d;

       }

       else{

           cout<<"Cities already connected\n";

       }

 

       cout<<"Connect more cities? (y/n)\n";

       cin>>ch;

 

   }while(ch=='y' || ch=='Y');

}

 

void graph::display(){

 

   cout<<"Cost Adjacency Matrix:\n";

 

   for(int i=0;i<n;i++){

       for(int j=0;j<n;j++){

           cout<<cost[i][j]<<" ";

       }

       cout<<endl;

   }

}

 

void graph::prim(int start_v){

 

   int nearest[10], t[10][3];

   int r=0;

   int mincost=0;

   int j,min;

 

   nearest[start_v]=-1;

 

   for(int i=0;i<n;i++){

       if(i!=start_v)

           nearest[i]=start_v;

   }

 

   for(int i=1;i<n;i++){

 

       min=999;

 

       for(int k=0;k<n;k++){

           if(nearest[k]!=-1 && cost[k][nearest[k]] < min){

               j=k;

               min=cost[k][nearest[k]];

           }

       }

 

       t[r][0]=nearest[j];

       t[r][1]=j;

       t[r][2]=min;

       r++;

 

       mincost+=min;

 

       nearest[j]=-1;

 

       for(int k=0;k<n;k++){

           if(nearest[k]!=-1 && cost[k][nearest[k]] > cost[j][k]){

               nearest[k]=j;

           }

       }

   }

 

   cout<<"\nWeight of MST = "<<mincost<<endl;

 

   cout<<"Edges in MST:\n";

 

   for(int i=0;i<n-1;i++){

       cout<<t[i][0]<<" - "<<t[i][1]

           <<"  Cost: "<<t[i][2]<<endl;

   }

}

 

int main(){

 

   graph g;

   int v;

 

   g.create();

   g.display();

 

   cout<<"Enter start vertex index:\n";


   cin>>v;

 

   g.prim(v);

 

   return 0;

}