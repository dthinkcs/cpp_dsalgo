#include <iostream>
using namespace std;
#define MAX 50

class spme
{
public:

    int r;
    int c;
    int v;

    spme()
    {
        r = c = v = 0;
    }

    spme(int row, int col, int val)
    {
        r = row;
        c = col;
        v = val;
    }
};

class Spm
{
    spme a[MAX];

public:

    Spm fastTranspose()
    {
        Spm b;

    }
};


