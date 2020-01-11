#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <vector>


using namespace std;
 
 
int main()
{
 
    int a, n;
 
    while( cin >> a >> n)
    {
       
        if (a == 1 && n == 1) return 0;
 
        int f1=1;
        int Nn=1; 
        int f2a = 0;
         int f2n = 1; 
         int f1n = 0;
          int f1a = 1;
        string LR ="";
        
        double value = (double)a/n;
 
 
        for(;f1 != a || Nn != n;f1 = f2a + f1a,Nn = f2n + f1n){

            if (value > (double)f1/Nn)
                f2n = Nn,f2a = f1,
                LR += "R";
            else
                f1n = Nn,f1a = f1,
                LR += "L";
        }
        cout << LR << endl;
 
    }
    return 0;
}