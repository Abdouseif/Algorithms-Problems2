#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

long long *arr;
int n;
long long **Table;

void inList(string inputFile)
{

    ifstream myfile(inputFile, ios::in);
    if (myfile.is_open())
    {
        myfile >> n;
        arr = new long long[n];
        for (int i = 0; i < n; i++)
        {
            myfile >> arr[i];
        }
    }

    else
        cout << "Unable to open file";
}

void outTime(long long t, string timefile)
{
    ofstream myfile(timefile, ios::out);
    if (myfile.is_open())
    {
        myfile << t << endl;
        myfile.close();
    }
    else
        cout << "Unable to open file";
}

long Winner(int i, int j)
{

    if (i == j)
    {
        return arr[i];
    }

    else if (j == i + 1)
    {
        return max(arr[i], arr[i + 1]);
    }

    if (Table[i][j] == -1)
    {

        Table[i][j] = max((arr[i] + (min(Winner(i + 2, j), Winner(i + 1, j - 1)))), (arr[j] + min(Winner(i, j - 2), Winner(i + 1, j - 1))));
    }

    return Table[i][j];
}

int main(int argc, char **argv)
{

    //double duration;
    // auto start_time = std::chrono::high_resolution_clock::now();

    string inputFile = argv[1];
    string outputFile = argv[2];
    string timefile = argv[3];

    inList(inputFile);

    Table = new long long *[n];
    for (int i = 0; i < n; i++)
        Table[i] = new long long[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Table[i][j] = -1;
        }
    }

    int Start = 0;
    int end = n - 1;

    long long User1;
    User1 = Winner(Start, end);

    outTime(User1, outputFile);
}