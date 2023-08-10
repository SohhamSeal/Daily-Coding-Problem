#include <bits/stdc++.h>
using namespace std;

/*
sort the list and use a two-pointer approach
*/

bool check(vector<int> &vec, int k)
{
    int i=0,j=vec.size()-1;
    while(i<j)
    {
        int sum=vec[i]+vec[j];
        if(sum==k)
            return true;
        else if(sum<k)
            i++;
        else
            j--;
    }
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
    sort(vec.begin(),vec.end());
    cout << "Result: ";
    if (check(vec,k))
        cout << "TRUE\n";
    else 
        cout << "FALSE\n";
    return 0;
}