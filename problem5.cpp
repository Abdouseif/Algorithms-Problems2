#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

void inList(string inputFile, string &x, int &y)
{

    ifstream myfile(inputFile, ios::in);
    if (myfile.is_open())
    {
        myfile >> y;
        myfile >> x;
    }

    else
        cout << "Unable to open file";
}

void outList(string x, int size, string outputfile)
{

    ofstream myfile(outputfile, ios::out);
    int i = 0;
    if (myfile.is_open())
    {
        myfile << size << endl;
        myfile << x;

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
    string orig;
    int origSize;

    int newSize;
    inList(inputFile, orig, origSize);

    bool **table = new bool *[origSize];
    for (int i = 0; i < origSize; ++i)
    {
        table[i] = new bool[origSize];
    }

    for (int i = 0; i < origSize; i++)
    {
        for (int j = 0; j < origSize; j++)
        {
            table[i][j] = false;
        }
    }

    int maxLength = 1;
    for (int i = 0; i < origSize; ++i)
        table[i][i] = true;

    int start = 0;
    for (int i = 0; i < origSize - 1; ++i)
    {
        if (orig[i] == orig[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= origSize; k++)
    {
        for (int i = 0; i < origSize - k + 1; ++i)
        {

            int j = i + k - 1;

            if (table[i + 1][j - 1] && orig[i] == orig[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    newSize = maxLength;
    char *newStr = new char[maxLength];

    int j = 0;
    for (int i = start; i < (start + maxLength); i++)
    {
        newStr[j] = orig[i];
        j++;
    }
    newStr[maxLength] = '\0';
    outList(newStr, newSize, outputFile);
}
