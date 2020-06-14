#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
#include "poisk_tree.h"
using namespace std;

template <typename T>
class Queue
{
private:

    Poisk_tree<T>* data;


public:

    Queue()
    {
        data = new Poisk_tree<T>();
    }
    Queue(T* item, int len)
    {
        data = new Poisk_tree<T>(item,len);
    }
    Queue(Poisk_tree<T>& other)
    {
        data = new Poisk_tree<T>(other);
    }
    Queue(Queue<T>& other)
    {
        data = new Poisk_tree<T>(other.data);
    }

    bool empty()
    {
        bool a=(this->data->get_length()==0);
        return a;
    }

    void add_el(T data)
    {
        this->data->add_el(data);
    }

    T get_max()
    {
        Deque<T> *r= this->data->lkp_t();
        T res = r->pop_back();
        this->data= new Poisk_tree<T>(r);
        return res;
    }

    T get_min()
    {
        Deque<T> *r= this->data->lkp_t();
        T res= r->pop_front();
        this->data= new Poisk_tree<T>(r);
        return res;
    }

    Queue<T>* concat(Queue<T>& other)
    {
        Deque<T>* d1= this->data->klp_t();
        Deque<T>* d2= other.data->klp_t();
        Deque<T>* d3= d1->concat(d2);
        Poisk_tree<T>* p= new Poisk_tree<T>(d3);
        Queue<T> * res= new Queue<T>(*p);
        return res;
    }

    Queue<T>* map(T(*func)(T))
    {
        Poisk_tree<T>* p1= this->data->map(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    Queue<T>* map(T(*func)(void))
    {
        Poisk_tree<T>* p1= this->data->map(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    Queue<T>* where(bool(*func)(T))
    {
        Poisk_tree<T>* p1= this->data->where(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    T reduce(T(*func)(T))
    {
        Poisk_tree<T>* p1= this->data->reduce(func);
        Queue<T>* res= new Queue<T>(*p1);
        return res;
    }

    void print()
    {
        Deque<T>* temp = this->data->klp_t();
        temp->print();
    }


    int find_subsequence(Queue<T>& other)
    {
        Deque<T> * d1=this->data->klp_t();
        Deque<T> * d2=other.data->klp_t();
        int index = d1->find_subsequence(*d2);
        return index;
    }

    int find_subsequence(T* item, int len)
    {
        Deque<T> * d1=this->data->klp_t();
        int index = d1->find_subsequence(item,len);
        return index;
    }

    Queue* get_subsequence(int start, int end)
    {
        Deque<T> * d1=this->data->klp_t();
        Deque<T> * d2=d1->get_subsequnce(start, end);
        Poisk_tree<T>* p= new Poisk_tree<T>(d2);
        Queue<T> * res= new Queue<T>(*p);
        return res;
    }



};



#endif // QUEUE_H
