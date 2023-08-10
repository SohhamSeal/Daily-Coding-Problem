#include <bits/stdc++.h>
using namespace std;

/*
using prefix and suffix products (1 new array) for each element
*/

void func(vector<int> &vec)
{
    vector<int> suff(vec.size(),1);
    int pre=1;
    for(int i=vec.size()-2;i>=0;i--)
        suff[i]=suff[i+1]*vec[i+1];
    cout << "Result:\n";
    cout << suff[0] << " ";
    for(int i=1;i<suff.size();i++)
    {    
        pre*=vec[i-1];
        cout << pre*suff[i]<< " ";
    }
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