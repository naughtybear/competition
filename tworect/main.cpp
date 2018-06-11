#include <bits/stdc++.h>

using namespace std;

int detect(int array[],int size)
{
    int max=array[0];
    for(int i=0;i<size;i++){
        if(array[i]>=0)
            return 0;
        if(max<array[i])
            max=array[i];
    }
    return max;
}

int getmax(int array[],int size)
{
    int sum=detect(array,size);
    if(sum<0)
        return sum;
    int max=array[0];
    for(int i=0;i<size;i++){
        sum+=array[i];
        if(sum<0)
            sum=0;
        if(sum>max)
            max=sum;
    }
    return max;
}

int matrixmax(int matrix[500][500],int size)
{
    int tmpup[size],tmpbot[size];
    int maxtop=-INT_MAX,maxbot,ans=-INT_MAX;
    for(int barrier=0;barrier<size-1;barrier++){
        maxbot=-INT_MAX;
        for(int i=barrier;i>=0;i--){
            for(int j=0;j<size;j++)
                tmpup[j]=0;
            for(int j=barrier;j>=i;j--){
                for(int k=0;k<size;k++){
                    tmpup[k]+=matrix[j][k];
                }
            }
            int tmp=getmax(tmpup,size);
            if(tmp>maxtop)
                maxtop=tmp;
        }
        for(int i=barrier+1;i<size;i++){
            for(int j=0;j<size;j++)
                tmpbot[j]=0;
            for(int j=size-1;j>=i;j--){
                for(int k=0;k<size;k++)
                    tmpbot[k]+=matrix[j][k];
            }
            int tmp=getmax(tmpbot,size);
            if(tmp>maxbot)
                maxbot=tmp;
        }
        if(maxtop+maxbot>ans)
            ans=maxbot+maxtop;
    }
    return ans;
}

void inverse(int matrix[500][500],int size)
{
    for(int i=1;i<size;i++){
        for(int j=0;j<i;j++){
            int tmp=matrix[j][i];
            matrix[j][i]=matrix[i][j];
            matrix[i][j]=tmp;
        }
    }
}

int main()
{
    freopen("out.txt","r",stdin);
    int size;
    while(cin >> size){
        if(size==0)
            break;
        int matrix[500][500];
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                scanf("%d",&matrix[i][j]);
        int ans1,ans2;

        ans1=matrixmax(matrix,size);
        inverse(matrix,size);
        /*for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }*/
        ans2=matrixmax(matrix,size);
        int ans;
        (ans1>ans2)?ans=ans1:ans=ans2;
        cout << ans << endl;
    }
    return 0;
}
