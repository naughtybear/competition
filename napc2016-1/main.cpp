#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(1){
        int n;
        cin >> n;
        if(n==0)
            break;
        int input[n][n+1];
        //int total[n][n];
        int max = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n+1;j++)
                input[i][j]=0;
        }
        for(int i=0;i<n;i++)
            for(int j=1;j<i+2;j++)
                cin >>input[i][j];
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << input[i][j];
        }*/
        for(int i = 1 ; i < n; i++)
            for(int j = 1 ; j < i+2; j++)
            {
               if(input[i-1][j]>input[i-1][j-1])
                    input[i][j]+=input[i-1][j];
               else
                    input[i][j]+=input[i-1][j-1];
            }
        /*for(int i=0;i<n;i++){
            cout << endl;
            for(int j=0;j<n+1;j++)
                cout << input[i][j];
        }*/
        for(int i = 0 ; i < n+1 ; i++)
            if(max < input[n-1][i])
                max = input[n-1][i];
        cout << max << endl;
    }
    return 0;
}
