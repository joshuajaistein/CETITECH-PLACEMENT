#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;




class BinCoeff {
   public:

   int n;
   int k;
};

int binomialCoefficients(int n, int k) {
   int C[k+1];
   memset(C, 0, sizeof(C));
   C[0] = 1;
   for (int i = 1; i <= n; i++) {
      for (int j = min(i, k); j > 0; j--)
         C[j] = C[j] + C[j-1];
   }
   return C[k];
}
int main() {

   auto start = high_resolution_clock::now();
   //int n=34, k=15;
   BinCoeff varObj;
   varObj.n = 34;
   varObj.k = 15;
   cout<<"The value of C("<<varObj.n<<", "<<varObj.k<<") is "<<binomialCoefficients(varObj.n,varObj.k);
   cout<<"HERE";
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
   cout << "\nMULTIPLICATION TIME : "<< duration.count() << " microseconds";
   return 0;
}