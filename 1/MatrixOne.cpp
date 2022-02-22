#define CATCH_CONFIG_MAIN
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <catch.hpp>

using namespace std;
using namespace std::chrono;

#define n 4096

double A[n][n], B[n][n], C[n][n];

TEST_CASE("TESTCASE1")
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
      A[i][j] = (double)rand()/ (double)RAND_MAX;
	    B[i][j] = (double)rand()/ (double)RAND_MAX;
	    C[i][j] = 0;
        }

    REQUIRE(n == 4096);
    // START THE TIMER CLOCK
    auto start = high_resolution_clock::now();
    //LOOP INTERCHANGE
    for(int i = 0; i < n; ++i)
        for(int k = 0; k < n; ++k)
            for(int j = 0; j < n; ++j)
            {
                C[i][j] += A[i][k] * B[k][j];
                cout<<"Running !"<<"\n"<<k;
            }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nMULTIPLICATION TIME : "<< duration.count() << " seconds";
}
