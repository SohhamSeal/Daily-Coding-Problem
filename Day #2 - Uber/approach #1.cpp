#include <bits/stdc++.h>
using namespace std;

/*
using the total product and find each of them using the division operator
*/

void func(vector<int> &vec)
{
    int prod=1;
    for(auto &i: vec)
        prod*=i;
    cout << "Result:\n";
    for(auto &i:vec)
        cout << prod/i << " ";
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