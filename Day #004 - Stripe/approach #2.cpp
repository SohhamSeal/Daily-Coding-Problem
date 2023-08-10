#include <bits/stdc++.h>
using namespace std;

/*
First, consider one index and keep on swapping, until we find a position for the +ve 
numbers where it is equal to it's index plus 1. Repeat this for all the values in the list.
Second, iterate the array and check the first number that is not present at its index-1 th position.
*/

void check(vector<int> &vec)
{
    for(int i=0;i<vec.size();i++) 
        while (vec[i]>=1 && vec[i]<=vec.size() && vec[i]!=vec[vec[i]-1]) 
            swap(vec[i],vec[vec[i]-1]);
    
    /*
    this will have placed all the numbers at their corresponding value-1 th index.
    so we now have to iterate and check. That's all!! 
    */
            
    int i=0;
    for(;i<vec.size();i++)
        if(vec[i]!=(i+1))
            break;
    cout << i+1 << endl;
}

int main() {
    int n;
    cout << "Enter list size: ";
    cin >> n;
    vector<int> vec(n,0);
    cout << "Enter the list elements::" << endl;
    for(int i=0;i<n;i++)
        cin >> vec[i];
    
    cout << "Result: ";
    check(vec);
    
    return 0;
}
