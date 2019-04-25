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

void inList(string inputFile, int *&Arr1, int &n)
{

    ifstream myfile(inputFile, ios::in);
    if (myfile.is_open())
    {
        myfile >> n;
        Arr1 = new int[n];
        for (int i = 0; i < n; i++)
        {
            myfile >> Arr1[i];
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
        myfile << size << endl;
        while (i < size)
        {
            myfile << (outArr[i]) << " ";
            i++;
        }

        myfile.close();
    }
    else
        cout << "Unable to open file";
}

void outTime(double t, string timefile)
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

int height(int x)
{

    if (graph_map[x].empty())
    {
        return 0;
    }
    else
    {
        int size = graph_map[x].size();
        int *getMax = new int[size];
        for (int i = 0; i < size; i++)
        {

            getMax[i] = height((graph_map[x].front()));
            graph_map[x].pop_front();
        }
        int max = 0;
        for (int i = 0; i < size; i++)
        {
            if (getMax[i] > max)
            {
                max = getMax[i];
            }
        }

        return 1 + max;
    }
}
int main(int argc, char **argv)
{
    //int argc, char **argv
    //double duration;
    //auto start_time = std::chrono::high_resolution_clock::now();

    string inputFile = argv[1];
    string outputFile = argv[2];
    //string timefile = argv[3];
    //string inputFile = "input.txt";
    //string outputFile = "out.txt";
    int *Arr1;
    int root;
    int H;
    inList(inputFile, Arr1, n);

    for (int i = 0; i < n; i++)
    {
        if (Arr1[i] != -1)
        {
            graph_map[Arr1[i]].push_back(i);
        }
        else
        {
            root = i;
        }
    }

    H = height(root);
    H++;
    outTime(H, outputFile);
    //auto end_time = std::chrono::high_resolution_clock::now();
    //auto time = end_time - start_time;
    //duration = (std::chrono::duration_cast<std::chrono::milliseconds>(time).count());
    //outTime(duration, timefile);
}