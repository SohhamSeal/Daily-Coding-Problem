#include <bits/stdc++.h>
using namespace std;

class Steps{
public: 
    // The answer to the basic question is the fibonacci series, starting as 1,2,3,5... so on.
    
    int fibo(int n)
    {
        /* calculating the nth fibonacci number using the matrix exponentiation method
              n
        |1  1|  = |F(n+1)  F(n) |
        |1  0|    | F(n)  F(n-1)|; for n>=1.
        
        But, we need to modify the matrix a little bit:
             
        |2 1| x times |1  1|  = |F(2+1)  F(2) |
        |1 1|         |1  0|    | F(2)  F(2-1)|; for n>=1.
        
        */
        vector<vector<int>> act{{2,1},{1,1}};
        int t=n-1; 
        while(t>1)
        {
            t--;
            vector<vector<int>> temp=act;
            act[0][0]=temp[0][0] + temp[0][1];
            act[0][1]=temp[0][0];
            act[1][0]=temp[1][0] + temp[1][1];
            act[1][1]=temp[1][0];
        }
        if(t)
            return act[0][0];
        return act[0][1];
    }
    
    void calculate(int n)
    {
        cout << "The number of possible steps are: " << fibo(n) << endl;
    }
    
    void driver()
    {
        int n;
        cout << "Enter the total number of steps: ";
        cin >> n;
        calculate(n);
    }
};

int main()
{
    Steps* obj=new Steps();
    obj->driver();
    return 0;
}