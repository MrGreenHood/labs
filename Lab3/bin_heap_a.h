#ifndef BIN_HEAP_H
#define BIN_HEAP_H
#include <iostream>
#include <string>
#include "myarray.h"

using namespace std;

template<typename T>
class Bin_heap_a
{
private:

    D_Array<T> *data;

    void klp(int id, Bin_heap_a<T>* res)
    {
        int size= this->data->get_length();
        if(id>=size)
            return;
        res->add_el(this->data->get_index(id));
        klp(id*2+1,res);
        klp(id*2+2,res);
    }







public:
    Bin_heap_a()
    {
        data=new D_Array<T>();
    }
    Bin_heap_a(T* item, int len)
    {
        data = new D_Array<T>();
        for(int i=0; i<len;i++)
            this->add_el(*(item+i));
    }
    Bin_heap_a(Bin_heap_a<T>& other)
    {
        this->data=new D_Array<T>(other.data);
    }

    void put_in_oder(int i=0)
    {
        int left, right;
        T temp;
        int HeapSize = this->data->get_length();
        left = 2*i+1;
        right = 2*i+2;
        if(left < HeapSize)
        {
            if(this->data->get_index(i) < this->data->get_index(left))
            {

                temp = this->data->get_index(i);
                this->data->set_index(i,this->data->get_index(left));
                this->data->set_index(left,temp);
                put_in_oder(left);
            }

        }
        if(right < HeapSize)
        {
            if(this->data->get_index(i) < this->data->get_index(right))
            {

                temp = this->data->get_index(i);
                this->data->set_index(i,this->data->get_index(right));
                this->data->set_index(right,temp);
                put_in_oder(right);
            }

        }
    }


    void add_el(T item)
    {
        int i, parent;
        i = this->data->get_length();
        this->data->prepend(item);
        parent = (i-1)/2;
        while(parent >= 0 && i > 0)
        {
            if((*this->data)[i] > (*this->data)[parent])
            {
                int temp = (*this->data)[i];
                (*this->data)[i] = (*this->data)[parent];
                (*this->data)[parent] = temp;
            }
            i = parent;
            parent = (i-1)/2;
        }
    }

     T get_max()
     {
         T max = this->data->get_first();
         (*this->data)[0]=this->data->get_last();
         this->data->del_last();
         this->put_in_oder();
         return max;
     }

     void out_heap()
     {
         int i = 0;
         int k = 1;
         int HeapSize = this->data->get_length();
         while(i < HeapSize)
         {
             while((i < k) && (i < HeapSize))
             {
                 cout << ((*this->data)[i]) << " ";
                 i++;
             }
             cout << endl;
             k = k * 2 + 1;
         }
     }

     void out(void)
     {
         int HeapSize = this->data->get_length();
         for(int i=0; i< HeapSize; i++)
         {
             cout << (*this->data)[i] << " ";
         }
         cout << endl;
     }
     void out_pair()
     {
         int size= this->data->get_length();
         int left, right;
         for(int i=0; i<size; i++)
         {
             left=2*i+1;
             right=2*i+2;
             cout<<"Родитель: "<<this->data->get_index(i)<<endl;
             if(left<size)
                 cout<<"Левый потомок: "<<this->data->get_index(left);
             if(right<size)
                 cout<<" Правый потомок: "<<this->data->get_index(right);
             cout<<endl;

         }
     }
     int find_el(T el)
     {

         int size=this->data->get_length();
         int index=0;
         int left, right;
         while((index<size)&(this->data->get_index(index)!=el))
             index++;
         if(index==size)
         {
             cout<<"Элемента нет"<<endl;
             return nullptr;
         }

         return index;
     }








};
#endif // BIN_HEAP_H
