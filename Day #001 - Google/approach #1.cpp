#include <bits/stdc++.h>
using namespace std;

/*
simply use a nested loop and check for all the elements
*/

bool check(vector<int> &vec, int k)
{
    for(int i=0;i<vec.size()-1;i++)
        for(int j=i+1;j<vec.size();j++)
            if((vec[i]+vec[j])==k)
                return true;
    return false;
}

int main() {
    int n,k;
    cout << "Enter list size: ";
    cin >> n;
    vector<int> vec(n,0);
    cout << "Enter the list elements::" << endl;
    for(int i=0;i<n;i++)
        cin >> vec[i];
    cout << "Enter value of k: ";
    cin >> k;
    
    cout << "Result: ";
    if (check(vec,k))
        cout << "TRUE\n";
    else 
        cout << "FALSE\n";
    return 0;
}