#include<bits/stdc++.h>
using namespace std;

int main()
{
    int times;
    char keyin[200];
    scanf("%d\n",&times);
    while(times--)
    {
        int a[5][51] = {0};
        int n;
        int maxi=0;
        for(int i = 0; i < 5 ; i++)
        {
            gets(keyin);
            int temp = 0;
            for(int j = 0 ; j <= strlen(keyin) ; j++)
            {
                if('0' <= keyin[j] && keyin[j] <='9')
                {
                    if('0' <= keyin[j+1] && keyin[j+1] <='9')
                        temp += (keyin[j] - '0') * 10;
                    else
                        temp += keyin[j] - '0';
                }
                else
                {
                    a[i][temp]++;
                    maxi=max(maxi,temp);
                    temp = 0;
                }
            }
        }

        scanf("%d\n",&n);
        //cout << n << endl;
        while(n--)
        {
                int c, t[5];
                for(int i=0;i<=4;i++)
                    t[i]=0;
                char buf[100];
                char *delim=" \n";
                char *pt;
                fgets(buf,100,stdin);
               c=atoi(strtok(buf,delim));
                while(pt=strtok(NULL,delim)){
                    if(*pt == 'A')
                        t[0] = 1;
                    else if(*pt == 'B')
                        t[1] = 1;
                    else if(*pt == 'C')
                        t[2] = 1;
                    else if(*pt == 'D')
                        t[3] = 1;
                    else if(*pt == 'E')
                        t[4] = 1;
                }
               /* while(c--)
                {
                    scanf("%c%c",&A,&tmp);
                    //cout << "A:" << A << "tmp:" << tmp << endl;
                    if(A == 'A')
                        t[0] = 1;
                    else if(A == 'B')
                        t[1] = 1;
                    else if(A == 'C')
                        t[2] = 1;
                    else if(A == 'D')
                        t[3] = 1;
                    else if(A == 'E')
                        t[4] = 1;
                }*/
                /*for(int i=0;i<=4;i++)
                    cout << "i: " << t[i] << endl;*/
                int ans[51];
                for(int i=0;i<51;i++)
                    ans[i]=1;
                ans[0] = 0;
                for(int i = 0; i <= 4 ; i++)
                {
                    if(t[i] == 1)
                    {
                        for(int j = 1 ; j < 51 ; j++)
                        {
                            if(a[i][j] != 1)
                                ans[j] = 0;
                        }
                    }
                    if(t[i] == 0)
                    {
                        for(int j = 1 ; j < 51 ; j++)
                        {
                            if(a[i][j] == 1)
                                ans[j] = 0;
                        }
                    }
                 }
                 /*for(int i=0;i<52;i++)
                    cout << ans[i] << endl;*/
                 int cnt = 0;
                 for(int j = 1 ; j < 51 ; j++)
                 {
                    if(ans[j] == 1)
                        cnt++;
                 }
                 if(cnt > 1)
                    cout << "I don't know!" << endl;
                 else if (cnt == 1)
                 {
                    for(int j = 1 ; j < 51 ; j++)
                    {
                        if(ans[j] == 1)
                        {
                            cout << j << endl;
                            break;
                        }
                    }
                 }
                 else if(cnt == 0)
                    cout << "Impossible!" << endl;

        }
    }
}
