#include <bits/stdc++.h>
using namespace std;

/*
using prefix and suffix products (2 new arrays) for each element
*/

void func(vector<int> &vec)
{
    vector<int> pre(vec.size(),1),suff(vec.size(),1);
    for(int i=1;i<vec.size();i++)
        pre[i]=pre[i-1]*vec[i-1];
    for(int i=vec.size()-2;i>=0;i--)
        suff[i]=suff[i+1]*vec[i+1];
    cout << "Result:\n";
    for(int i=0;i<vec.size();i++)
        cout << pre[i]*suff[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter list size: ";
    cin >> n;
    vector<int> vec(n,0);
    cout << "Enter the list elements::" << endl;
    for(int i=0;i<n;i++)
        cin >> vec[i];
    func(vec);
    return 0;
}