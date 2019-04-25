#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stack>
#include <iostream>
#include <iterator>
#include <map>
#include <list>

using namespace std;
int n;
int m;
map<int, list<int>> graph_map;

void inList(string inputFile)
{

    ifstream myfile(inputFile, ios::in);
    if (myfile.is_open())
    {
        myfile >> n >> m;
        int x, y;
        for (int i = 0; i < m; i++)
        {
            myfile >> x >> y;
            graph_map[x].push_back(y);
            graph_map[y].push_back(x);
        }
    }

    else
        cout << "Unable to open file";
}

void outList(int *outArr, int size, string outputfile)
{

    ofstream myfile(outputfile, ios::out);
    int i = 0;
    if (myfile.is_open())
    {

        while (i < size)
        {
            myfile << i << " " << (outArr[i]) << endl;
            i++;
        }

        myfile.close();
    }
    else
        cout << "Unable to open file";
}

int main(int argc, char **argv)
{

    string inputFile = argv[1];
    string outputFile = argv[2];

    //string inputFile = "input.txt";
    //string outputFile = "out.txt";
    inList(inputFile);

    map<int, list<int>>::iterator itr;
    int d = 0;
    for (itr = graph_map.begin(); itr != graph_map.end(); ++itr)
    {
        if ((itr->second.size()) > d)
            d = itr->second.size();
    }
    int *FinalcolorsArr = new int[n];
    for (int i = 0; i < n; i++)
    {
        FinalcolorsArr[i] = -1;
    }
    int *checkColorArr = new int[d];
    for (int i = 0; i < d; i++)
    {
        checkColorArr[i] = -1;
    }
    int index;
    map<int, list<int>>::iterator itr2;
    for (itr2 = graph_map.begin(); itr2 != graph_map.end(); ++itr2)
    {
        for (int i = 0; i < d; i++)
        {
            checkColorArr[i] = -1;
        }
        int sizeOfList = itr2->second.size();
        for (int i = 0; i < sizeOfList; i++)
        {
            index = itr2->second.front();
            itr2->second.pop_front();
            if (FinalcolorsArr[index] != -1)
            {
                checkColorArr[FinalcolorsArr[index]] = 0;
            }
        }
        for (int j = 0; j < d; j++)
        {
            if (checkColorArr[j] == -1)
            {
                FinalcolorsArr[itr2->first] = j;
                break;
            }
        }
    }

    outList(FinalcolorsArr, n, outputFile);
}
