#include <iostream>

using namespace std;

int main()
{
    long long n,p,a,b,c;
    bool judge=true;
    while(cin >> n >> p >> a >> b >> c){
        if(judge==true)
            judge=false;
        else
            cout << endl;
        long long base_matrix[3][3]={0},ans_matrix[3][3]={0},tmp_matrix[3][3];
        base_matrix[0][0]=a;
        base_matrix[0][1]=b;
        base_matrix[0][2]=c;
        base_matrix[1][0]=base_matrix[2][1]=1;
        ans_matrix[0][0]=ans_matrix[1][1]=ans_matrix[2][2]=1;

        n-=3;
        while(n>0){ //¤£¯àwhile(n)
            if(n&1){
                /*for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++)
                        cout << base_matrix[i][j] << " ";
                    cout << endl;
                }*/
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        long long tmp=0;
                        for(int k=0;k<3;k++){
                            tmp+=ans_matrix[i][k]*base_matrix[k][j]%p;
                        }
                        tmp_matrix[i][j]=tmp;
                    }
                }
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++)
                        ans_matrix[i][j]=tmp_matrix[i][j];
                }
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    long long tmp=0;
                    for(int k=0;k<3;k++){
                        tmp+=base_matrix[i][k]*base_matrix[k][j]%p;
                    }
                    tmp_matrix[i][j]=tmp;
                }
            }
            for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++)
                        base_matrix[i][j]=tmp_matrix[i][j];
            }
            n>>=1;
        }
        //cout <<ans_matrix[0][0]%p<<" "<<ans_matrix[0][1]%p<<" "<<ans_matrix[0][2]%p<<endl;
        cout << (ans_matrix[0][2]+ans_matrix[0][1]+ans_matrix[0][0])%p;
    }
    return 0;
}
