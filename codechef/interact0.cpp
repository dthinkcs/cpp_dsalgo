#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--!=0)
    {
        int n;
        cin >> n;
        int f;
        cout << "1 1 2 3" <<endl;
        fflush(stdout);
        cin >> f;
        int s;
        cout << "1 1 2 4" << endl;
        fflush(stdout);
        cin >> s;
        int ans;
        ans = f^s;
        int result[n+1]= {};
        for(int i = 5; i<=n;i++)
        {
            int out;
            cout << "1 3 4 "<<i << endl;
            fflush(stdout);
            cin >> out;
            result[i] = ans^out;
        }
        for(int i =1;i<=2;i++)
        {
            int out;
            cout << "1 3 4 "<<i << endl;
            fflush(stdout);
            cin >> out;
            result[i] = ans^out;
        }
        
        int del = result[1] ^ result[2];
        result[3] = del^f;
        result[4] = del^s;
        cout << "2" << endl;
        
        for(int i=1;i<=n;i++)
        {
            cout << result[i] << " ";
            fflush(stdout);
        }
        cout << endl;
        int flag;
        cin >> flag;
    }
}
