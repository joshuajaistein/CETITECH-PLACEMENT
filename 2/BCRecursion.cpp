#include <iostream>
#include <chrono>

#include <catch.hpp>

using namespace std;
using namespace std::chrono;


class Recursion {
   public:
      int n;
      int k;
};



int binomialCoefficients(int n, int k) {

   if (k == 0 || k == n)
   return 1;
   return binomialCoefficients(n - 1, k - 1) + binomialCoefficients(n - 1, k);
}
   

int main() {
   auto start = high_resolution_clock::now();

   //int n= 34 , k=15;
   Recursion variableObject;
   variableObject.n = 34;
   variableObject.k = 15;
   
   cout<<"The value is "<<binomialCoefficients(variableObject.n, variableObject.k);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
   cout << "\nFUNCTION TIME : "<< duration.count() << " microseconds";
   return 0;
}
