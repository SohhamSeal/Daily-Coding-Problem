#include <bits/stdc++.h>
using namespace std;

class Steps{
public: 
    // The answer to the basic question is the fibonacci series, starting as 1,2,3,5... so on.
    
    int fibo(int n)
    {
        //calculating the nth fibonacci number in iterative manner
        int a=1,b=2,c=0;
        n--;
        while(n)
        {   
            n--;
            c=a+b;
            a=b;
            b=c;
        }
        return a;
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