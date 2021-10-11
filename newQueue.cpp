#include <iostream>
#include <string>
using namespace std;

template <class type> // to can use diff. data type
class queue
{
    int front, tail, length, maxsize;
    type *list; // will use pointer to make our queue dynamic

public:
    //default constructor
    queue(int size)
    {   
        if(size < 0){maxsize = 100; cout<<"Size of Queue: "<<maxsize<<endl;}
        else{maxsize = size;}
        list = new type[maxsize];
        front = 0; tail = maxsize -1; length = 0;  
    }
    //function to check queue is empty
    bool isempty(){return length == 0;}
    //function to check queue is full
    bool isFull(){return length == maxsize;}
    //function to store elemnets in queue
    void Enqueue(type data)
    {
        if(isFull()){cout<<"Queue is full!\n";}
        else
        {
            tail = (tail + 1) % maxsize; //this equation to make our queue circural.
            list[tail] = data;
            length++;
        }
    }
    //function to delete elements from queue
    void Dequeue()
    {
        if(isempty()){cout<<"Queue is Empty!\n";}
        else
        {
            front = (front +1) % maxsize;
            length--;
        }
    }
    //function to get front of queue
    void getFront()
    {
        if(isempty()){cout<<"Queue is empty!\n";}
        else
        {
            cout<<"Front of Queue: "<<list[front]<<"\n";
        }
    }
    //function to get tail of queue
    void getTail()
    {
        if(isempty()){cout<<"Queue is empty!\n";}
        else
        {
            cout<<"Tail of Queue: "<<list[tail]<<"\n";
        }
    }
    //Function to make search in queue
    void searchQueue(type data)
    {
        if(isempty()){cout<<"Queue is empty!, Can not make search\n";}
        else
        {
            for(size_t i=front; i<= tail; i =(i+1) % maxsize)
            {
                if(list[i] == data){cout<<"Element founded in index : "<<i<<endl;; break;}
                else if(i == tail){cout<<"Not found!\n"; break;}
            }
        }
    }
    //function to print Queue elements
    void print()
    {   
        if(isempty()){cout<<"Queue is empty!\n";}
        else
        {
            cout<<"Queue: [ ";
            for(int i=front; i <=tail; i=(i +1) % maxsize)
            {
                cout<<list[i]<<" ";
            }
            cout<<"]\n";
        }   
    }
};

int main()
{
    queue <int> q(15); 
    q.print();
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.print();
   // q.Dequeue();
    //q.print();
    q.getFront();
    q.Enqueue(40);
    q.print();
    q.getFront();
    q.getTail();
    q.searchQueue(30);
    cout<<"-----------------------\n";
    queue <string> q2(10);
    q2.Enqueue("Sara");
    q2.Enqueue("Nada");
    q2.Enqueue("Ali");
    q2.Enqueue("Ahmed");    
    q2.print();
    q2.getFront();
    q2.getTail();
    q2.searchQueue("Abdullah");
    q2.searchQueue("Nada");

}