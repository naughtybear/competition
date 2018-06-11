#include <iostream>

using namespace std;

void simple(int *a,int *b)
{
    int tmpa=max(*a,*b);
    int tmpb=min(*a,*b);
    while(tmpa&&tmpb){
        if(tmpa>tmpb)
            tmpa=tmpa%tmpb;
        else
            tmpb=tmpb%tmpa;
    }
    int factor=max(tmpa,tmpb);
    *a=(*a)/factor;
    *b=(*b)/factor;
}

bool compare(int atop,int adown,int btop,int bdown)
{
    return (atop*bdown>adown*btop);
}

int main()
{
    int n,mintop=1,mindown=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int height,width,depth;
        cin >> height >> width >> depth;
        int surface=2*(height*width+width*depth+depth*height);
        int volume=height*depth*width;
        simple(&surface,&volume);
        if(compare(mintop,mindown,surface,volume)){
            mintop=surface;
            mindown=volume;
        }
    }
    cout << mintop << "/" << mindown << endl;
    return 0;
}
