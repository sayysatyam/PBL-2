#include <iostream>

#include <algorithm>

#include <string>

#include <cmath>

 

using namespace std;

 

class knapsack

{

   int n, m;

   int p[10], w[10], b[11][11];

 

public:

   void knapsacksolve();

   void display();

   void finditem();

};

 

void knapsack::knapsacksolve()

{

   cout << "enter the no of items: " << endl;

   cin >> n;

 

   cout << "enter the max capacity of knapsack : " << endl;

   cin >> m;

 

   cout << "enter the weight of the items : " << endl;

   for (int i = 0; i < n; i++)

       cin >> w[i];

 

   cout << "enter the profit of the items : " << endl;

   for (int i = 0; i < n; i++)

       cin >> p[i];

 

   // initialize row 0

   for (int j = 0; j <= m; j++)

       b[0][j] = 0;

 

   // initialize column 0

   for (int i = 0; i <= n; i++)

       b[i][0] = 0;

 

   // fill DP table

   for (int i = 1; i <= n; i++)

   {

       for (int j = 1; j <= m; j++)

       {

           if (w[i - 1] <= j)

           {

               if (p[i - 1] + b[i - 1][j - w[i - 1]] > b[i - 1][j])

                   b[i][j] = p[i - 1] + b[i - 1][j - w[i - 1]];

               else

                   b[i][j] = b[i - 1][j];

           }

           else

           {

               b[i][j] = b[i - 1][j];

           }

       }

   }

}

 

void knapsack::finditem()

{

   int i = n, j = m;

   int x[10] = {0};

 

   while (i > 0)

   {

       if (b[i][j] != b[i - 1][j])

       {

           x[i - 1] = 1;

           j = j - w[i - 1];

       }

       else

       {

           x[i - 1] = 0;

       }

       i--;

   }

 

   cout << "Items selected: ";

   for (int i = 0; i < n; i++)

       cout << x[i] << " ";

 

   cout << endl;

}

 

void knapsack::display()

{

   cout << "Table:\n";

 

   for (int i = 0; i <= n; i++)

   {

       for (int j = 0; j <= m; j++)

       {

           cout << b[i][j] << "\t";

       }

       cout << endl;

   }

 

   cout << "Maximum Profit: " << b[n][m] << endl;

}

 

int main()

{

   knapsack k;

 

   k.knapsacksolve();

   k.display();

   k.finditem();

 

   return 0;

}