#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("Contratiempo_2016_Castellano_BDrip_720p_X264.srt","r",stdin);
    locale china("chs");//use china character
    wcin.imbue(china);//use locale object
    wcout.imbue(china);
    wstring s;
    wchar_t wc=L'。';//wide character,wide string may be L"宽字符"
    while (getline(wcin,s,wc))
    {
        if(s[0]<'0'||s[0]>'9');
            wcout<<s<<endl;
    }
}
