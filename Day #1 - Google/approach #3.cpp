#include <bits/stdc++.h>
using namespace std;

/*
simply use a hashmap
*/

bool check(vector<int> &vec, int k)
{
    unordered_set<int> st;
    for(auto i: vec)
        if(st.find(k-i)!=st.end())
            return true;
        else 
            st.insert(i);
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