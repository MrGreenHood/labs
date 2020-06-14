#ifndef DEQUE_H
#define DEQUE_H
#include "mylist.h"
#include "myarray.h"
#include <functional>
using namespace std;


template <typename T>
class Deque
{

  private:

    Sequence<T>* data;
    string base_type;




  public:


    Deque(string type="list")
    {
        if(type=="array")
        {
            this->data= new D_Array<T>();
            this->base_type=type;
        }
        else
        {
           this->data= new My_list<T>();
           this->base_type=type;
        }

    }
    Deque(Deque<T>& other)
    {
        if(other.base_type=="array")
        {
            this->data= new D_Array<T>(*(other.data));
            this->base_type=other.base_type;
        }
        else
        {
           this->data= new My_list<T>(*(other.data));
           this->base_type=other.base_type;
        }
    }
    Deque(Sequence<T>* list,string type)
    {
        if(type=="array")
        {
            this->data= new D_Array<T>(*list);
            this->base_type=type;
        }
        else
        {
           this->data= new My_list<T>(*list);
           this->base_type=type;
        }
    }

    bool empty()
    {
        bool a=(this->data->get_length()==0);
        return a;
    }

    void push_back(T item)
    {
        this->data->prepend(item);
    }
    T pop_back()
    {
        if(!this->empty())
        {
            T item=this->data->get_last();
            this->data->del_last();
            return item;
        }
        else
            cout<<"дек пуст\n";
    }
    void push_front(T item)
    {
        this->data->append(item);
    }
    T pop_front()
    {
        if(!this->empty())
        {
            T item=this->data->get_first();
            this->data->del_first();
            return item;
        }
        else
            cout<<"дек пуст\n";

    }

    void map(T(*func)(T))
    {
        int len=this->data->get_length();
        for(int i=0;i<len;i++)
        {
            this->data->set_index(i,func(this->data->get_index(i)));
        }
    }
    void map(T(*func)(void))
    {
        int len=this->data->get_length();
        for(int i=0;i<len;i++)
        {
            this->data->set_index(i,func());
        }
    }

    Deque* where(bool(*func)(T))
    {
        Deque *temp=new Deque<T>();
        int data_t;
        int len=this->data->get_length();
        for(int i=0;i<len;i++)
        {
            data_t=this->data->get_index(i);
            if(func(data_t))
            {
                temp->push_back(data_t);
            }
        }
        return temp;
    }

    T reduce(T(*func)(T))
    {
        T res;
        int len=this->data->get_length();
        for(int i=0;i<len;i++)
        {
            res=func(this->data->get_index(i));
        }
        return res;
    }


    Deque* concat(Deque<T>* other)
    {
        Sequence<T>* temp=this->data->concat(other->data);

        Deque<T>* res=new Deque<T>(temp,this->base_type);
        return res;
    }

    Deque* get_subsequnce(int index1, int index2)
    {
        if((index1>=0) & (index2>=0) & (index2>=index1) & (index1<this->data->get_length()) & (index2<this->data->get_length()))
        {
            Sequence<T>* temp=this->data->get_subsequence(index1,index2);
            Deque<T>* res=new Deque<T>(temp,this->base_type);
            return res;
        }
        else
            cout<<"IndexOutOfRange"<<endl;
        return nullptr;
    }

    int find_subsequence (T* subsequnce, int len_sub)
    {
        int start_index=-1;
        if(this->base_type=="array")
        {
            D_Array<T>* temp= new D_Array<T>(subsequnce,len_sub);
            start_index=this->data->find_subsequence(*temp);
            return start_index;
        }
        else
        {
           My_list<T>* temp= new My_list<T>(subsequnce,len_sub);
           start_index=this->data->find_subsequence(*temp);
           return start_index;
        }

    }
    int find_subsequence (Deque<T>& other)
    {
        int start_index=-1;
        start_index=this->data->find_subsequence(*(other.data));
        return start_index;
    }


    bool operator ==(Deque<T>& other)
    {
        return (*(this->data)==(*(other.data)));
    }

    void print()
    {
        int len=this->data->get_length();
        cout<<"///////////////////////////////////"<<endl;
        for(int i=0;i<len;i++)
        {
            cout<<i<<": "<<this->data->get_index(i)<<"\n";
        }
        cout<<"///////////////////////////////////"<<endl;
    }

    void delete_subsequnce(function<bool(T)> func)
    {
        int len=this->data->get_length();

        for(int i=0;i<len;i++)
        {
            if(func(this->data->get_index(i)))
            {
                this->data->del_index(i);
                i--;
                len--;
            }
        }
    }






};





#endif // DEQUE_H
