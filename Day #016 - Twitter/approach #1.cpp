#include<bits/stdc++.h>
using namespace std;

class eCommerce{
    /*
    using a circular queue (ring/circular buffer) implemented using a vector
    This implementation requires:
    Time-> O(1)
    Space-> O(n): only the log
    */
    
    vector<int> *cq;
    int front,rear;
public:
    eCommerce(int n)
    {
        cq=new vector<int>(n);
        front=-1;
        rear=-1;
    }
    
    void record(int ord_id)
    {
        
    }
    
    int get_last(int i)
    {
        return -1;
    }
    
    void driver()
    {
        char cont;
        int choice,val;
        do
        {
            cout << "1>> Add an order_id to the log\n";
            cout << "2>> Get the ith last element from the log\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1: cout << "Enter order_id to be inserted into the log: ";
                        cin >> val;
                        record(val);
                        cout << "Order id successfully inserted!\n";
                        break;
                case 2: cout << "Enter index i: ";
                        cin >> val;
                        cout << "Value at " << val << "= " << get_last(val);
                        break;
                default: cout << "\nWrong choice!!\n";
            }
            cout << "\nDo you want to continue? (y/n): ";
            cin >> cont;
            
        }while(cont=='y' || cont=='Y');
    }
};

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    eCommerce *obj=new eCommerce(n);
    obj->driver();
    return 0;
}