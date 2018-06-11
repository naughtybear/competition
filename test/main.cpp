#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a=10;
    int *add_a=&a;
    queue<int*> vec;
    vec.push(add_a);
    cout << vec.front() << endl;
    return 0;
}
