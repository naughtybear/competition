#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int array[100000];
    int min=INT_MAX,count=0;
    while(scanf("%d",&array[count])!=EOF){
        if(array[count]<min)
            min=array[count];
        count++;
    }

    cout<<"Common factor in ascending order:";
    int count2=0,array2[10000];
    for(int i=2;i<=min;i++){
        bool flag=true;
        for(int j=0;j<count;j++)
            if(array[j]%i)
                flag=false;
        if(flag){
            //cout<< i<<" ";
            array2[count2]=i;
            count2++;
        }
    }
    for(int i=0;i<count2-1;i++)
        cout<<array2[i]<<" ";
    cout<<array2[count2-1];
    return 0;
}
