#include <iostream>

using namespace std;

int main()
{
    long long n,p,a,b,c;
    while(cin >> n >> p >> a >> b >> c){
        long long array[n];
        array[0]=array[1]=array[2]=1;
        for(int i=3;i<n;i++){
            array[i]=(a*array[i-1]+b*array[i-2]+c*array[i-3])%p;
        }
        cout << array[n-1] << " "<<array[n-2]<<" " << array[n-3] << endl;
    }
    return 0;
}
