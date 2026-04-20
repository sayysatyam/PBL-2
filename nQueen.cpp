#include <iostream>

#include <cmath>

using namespace std;

 

class queen {

public:

   int x[20];

   int n;

   int count;

 

   bool place(int i, int j);

   void nqueen(int i);

   void display();

   void chess();

};

 

bool queen::place(int i, int j) {

   for (int k = 1; k <= i - 1; k++) {

       if (x[k] == j || abs(x[k] - j) == abs(k - i))

           return false;

   }

   return true;

}

 

void queen::display() {

   count++;

   cout << "Solution " << count << ": ";

 

   for (int i = 1; i <= n; i++) {

       cout << "x" << i << "=" << x[i];

       if (i < n)

           cout << ", ";

   }

 

   cout << endl;

   chess();

}

 

void queen::nqueen(int i) {

   for (int j = 1; j <= n; j++) {

       if (place(i, j)) {

           x[i] = j;

 

           if (i == n) {

               display();

           } else {

               nqueen(i + 1);

           }

       }

   }

}

 

void queen::chess() {

   for (int i = 1; i <= n; i++) {

       for (int j = 1; j <= n; j++) {

           if (x[i] == j)

               cout << "Q ";

           else

               cout << ". ";

       }

       cout << endl;

   }

}

 

int main() {

   queen q;

 

   cout << "Enter n: ";

   cin >> q.n;

 

   q.count = 0;

 

   q.nqueen(1);

 

   cout << "Total solutions = " << q.count << endl;

 

   return 0;

}