#include <bits/stdc++.h>
using namespace std;

class XORLList{
public:

    //create a struct for linked list
    struct XORL
    {
      int val;
      XORL* both;
      XORL (): val(0), both(nullptr) {}
      XORL (int v): val(v), both(nullptr) {}
    }*head;
    int size;
    
    XORLList()
    {
        size=0;
        head=nullptr;
    }
    
    XORL* Xor(XORL* x,XORL* y)
    {
        return reinterpret_cast<XORL*>(reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
    }

    void add(int element)
    {
        XORL *newptr=new XORL(element);
        if(!head)
            head=newptr;
        else
        {
            XORL *ptr=head, *temp=nullptr, *prev=nullptr;
            // cout << ptr->val << " " << ptr->both << " " << prev; 
            while(ptr->both!=prev)
            {
                temp=ptr;
                ptr=Xor(ptr->both,prev);
                prev=temp;
            }
            newptr->both=Xor(newptr->both,ptr);
            ptr->both=Xor(ptr->both,newptr);
        }
        size++;
        cout << "New XORList:\n";
        display();
    }
    
    int get(int index)
    {
        if(index<1 || index>size) return INT_MIN;
        if(index==1) return head->val;
        else
        {
            index--;
            XORL *ptr=head, *temp=nullptr, *prev=nullptr;
            while(index)
            {
                index--;
                temp=ptr;
                ptr=Xor(ptr->both,prev);
                prev=temp;
            }
            return ptr->val;
        }
    }
    
    void display()
    {
        XORL *ptr=head, *temp=nullptr, *prev=nullptr;
        while(ptr)
        {
            cout << ptr->val;
            if(ptr->both!=prev)
                cout << " --> ";
            temp=ptr;
            ptr=Xor(ptr->both,prev);
            prev=temp;
        }
        cout << endl << endl;
    }
};
    
int main() 
{
    char ch='y';
    int choice,ele,ind;
    XORLList* obj=new XORLList();
    do{
        cout << "1>> Insert an element at the end of the list\n";
        cout << "2>> Get the element at some index\n";
        cout << "Enter your choice :: ";
        cin >> choice;
        if(choice==1)
        {   
            cout << "\nEnter element to be inserted: ";
            cin >> ele;
            obj->add(ele);
        }
        else if(choice==2)
        {
            cout << "\nEnter index to get the element from: ";
            cin >> ind;
            int ret=obj->get(ind);
            if(ret==INT_MIN)
                cout << "Index out of Bounds!!\n" << endl;
            else
                cout << "Value at index " << ind << " is " << ret << endl;
        }
        else
        {
            cout << "\nWrong input!! Choose again...\n" << endl;
            continue;
        }
        cout << "Do you want to continue? [y/n]: ";
        cin >> ch;
        cout << endl;
    }while(ch=='y' || ch=='Y');
    cout << "\nexit...";
    return 0;
}