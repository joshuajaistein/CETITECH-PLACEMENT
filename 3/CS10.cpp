

#define CATCH_CONFIG_MAIN

#include <iostream>
#include <fstream>
#include <vector>
#include <catch.hpp>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;
std::ofstream fileGeneration;

using namespace std;

TEST_CASE(" TESTING THE CODE")
{


    // STEP 1 : USER INPUT THROUGH TEXT FILE

    string filename("input.txt");
    vector<string> lines;
    string line;
    int checker1 = 0;
    int a[2][2], i, j,q;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        checker1 = 1;
    }

    REQUIRE(checker1 == 0);

    while (getline(input_file, line)){
        lines.push_back(line);
    }

    for (const auto &i : lines)
        cout << i << endl;

    input_file.close();

    cout<<i;


    // STEP 2 : MATRIX CALCULATION APPROACH
    for(q = 0; q < 2; ++q)
    {
        for(j = 0; j < 2; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[q][j];
        }
    }

    // ADDITION OPERATION

    for(q = 0; q < 2; ++q)
    {
        for(j = 0; j < 2; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[q][j];
        }
    }


    // STEP 3 : PRINT RESULT TO CSV FILE FORMAT
    std::ofstream fileGeneration;

    fileGeneration.open("output.csv");

    fileGeneration << a[q][j];

    cout<<a[q][j];
    
    fileGeneration.close();




}