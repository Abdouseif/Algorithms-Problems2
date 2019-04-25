#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

void inList(string inputFile, int *&Arr1, int *&Arr2, int &n, int &m)
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
        myfile >> m;
        Arr2 = new int[m];
        for (int i = 0; i < m; i++)
        {
            myfile >> Arr2[i];
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
            myfile << (outArr[i]);
            if (i != (size - 1))
                myfile << " ";
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

    int *Arr1;
    int *Arr2;
    int n, m;

    //string inputFile = "input.txt";
    //string outputFile = "out.txt";
    inList(inputFile, Arr1, Arr2, n, m);
    stack<int> stack_arr1;
    stack<int> stack_arr2;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (Arr1[i] != -1)
        {
            stack_arr1.push(Arr1[i]);
        }
        else
        {
            if (stack_arr1.empty())
            {
                Arr1[count1] = -1;
                i = n;
            }
            else
            {
                Arr1[count1] = stack_arr1.top();
                count1++;
                stack_arr1.pop();
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (Arr2[i] != -1)
        {
            stack_arr2.push(Arr2[i]);
        }
        else
        {
            if (stack_arr2.empty())
            {
                Arr2[count2] = -1;
                i = m;
            }
            else
            {
                Arr2[count2] = stack_arr2.top();
                count2++;
                stack_arr2.pop();
            }
        }
    }

    int x = 0;
    int y = 0;
    int count = 0;
    int *commonArr;
    if (count1 > count2)
        commonArr = new int[count1];
    else
        commonArr = new int[count2];

    while ((Arr1[x] != -1) && (Arr2[y] != -1))
    {
        if (Arr1[x] > Arr2[y])
        {
            y++;
        }
        else if (Arr1[x] < Arr2[y])
        {
            x++;
        }
        else
        {
            commonArr[count] = Arr1[x];
            count++;
            x++;
            y++;
        }
    }

    outList(commonArr, count, outputFile);
}