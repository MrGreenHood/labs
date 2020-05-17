#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>

using namespace std;


template <typename T>
class Sequence
{
  private:

    int length;


  public:

    Sequence()
    {
        length=0;

    }

    int get_length()
    {
        return length;
    }


    void set_length(int len)
    {
        this->length=len;
    }

    virtual T get_first()=0;
    virtual T get_last()=0;
    virtual T get_index(int index)=0;
    virtual void set_index(int index, T dat)=0;
    virtual Sequence<T>* get_subsequence(int startIndex, int endIndex)=0;
    virtual void append(T item)=0;
    virtual void prepend(T item)=0;
    virtual void insert_at(T item, int index)=0;
    virtual Sequence <T>* concat(Sequence <T> *list)=0;

};


template <typename T>
class D_Array : public Sequence<T>
{
  private:

    T* ptr;



  public:

    //---------------------------------------------------------------//

    D_Array (int size)
    {
        T* temp= new T[size];
        this->ptr=temp;
        this->set_length(size);

    }

    D_Array (T* items,int size) : D_Array(size)
    {
        for(int i=0;i<size;i++)
        {
           *(ptr+i)=items[i];
        }

    }

    D_Array (const D_Array <T>& other)
    {
        int size=other.get_length();
        ptr= new T[size];
        this->set_length(size);
        for(int i=0;i<size;i++)
        {
            *(ptr+i)=other.get_index(i);
        }

    }

    //---------------------------------------------------------------//

    T get_first() override
    {
        return*(this->ptr);
    }

    T get_last() override
    {
        return*(this->ptr+this->get_length()-1);
    }

    T get_index(int index) override
    {
        if(index<this->get_length())
        {
            return *(this->ptr+index);
        }
        else
            cout<<"IndexOutOfRange"<<endl;

    }

    void set_index(int index, T dat) override
    {
        if(index<this->get_length())
        {
            *(this->ptr+index)=dat;
        }
        else
            cout<<"IndexOutOfRange"<<endl;

    }

    void resize(int newsize)
    {
        T* temp= new T[newsize];

        if(newsize<=this->get_length())
        {
            for(int i=0;i<newsize;i++)
            {
                *(temp+i)=*(this->ptr+i);
            }
        }
        else
        {
            for(int i=0;i<this->get_length();i++)
            {
                *(temp+i)=*(this->ptr+i);
            }
            for(int i=this->get_length();i<newsize;i++)
            {
                *(temp+i)=0;
            }
        }
        this->set_length(newsize);
        delete[] this->ptr;
        this->ptr=temp;
    }

    //---------------------------------------------------------------//

    void append(T item) override
    {
        int n_len=this->get_length()+1;
        T* temp = new T [n_len];
        this->set_length(n_len);
        *temp=item;
        for(int i=1;i<n_len;i++)
        {
            *(temp+i)=*(this->ptr+i-1);
        }
        delete[]this->ptr;
        this->ptr=temp;


    }

    void prepend(T item) override
    {
        int n_len=this->get_length()+1;
        this->set_length(n_len);
        this->resize(n_len);
        *(this->ptr+n_len-1)=item;


    }
    void insert_at(T item, int index) override
    {
        if(index<this->get_length())
        {
            int n_len=this->get_length()+1;
            T* temp = new T [n_len];
            this->set_length(n_len);
            for(int i=0;i<index;i++)
            {
                *(temp+i)=*(this->ptr+i);
            }
            *(temp+index)=item;
            for(int i=index+1;i<n_len;i++)
            {
                *(temp+i)=*(this->ptr+i-1);
            }
        }
        else
            cout<<"IndexOutOfRange"<<endl;

    }

    D_Array* get_subsequence(int startIndex, int endIndex) override
    {
        if((startIndex>0) & (endIndex>0) & (endIndex>=startIndex) & (startIndex<this->get_length()) & (endIndex<this->get_length()))
        {
            D_Array<T> *temp=new D_Array<T>((endIndex-startIndex+1));
            for(int i=startIndex;i<=endIndex;i++)
            {
                *(temp->ptr+i)=*(this->ptr+i);
            }
            return temp;
        }
        else
            cout<<"IndexOutOfRange"<<endl;


    }

    D_Array* concat(Sequence<T> *list) override
    {
        int n_len=this->get_length()+list->get_length();
        int len_t=this->get_length();
        int len_l=list->get_length();
        T* temp= new T[n_len];
        for(int i=0;i<len_t;i++)
        {
            *(temp+i)=this->get_index(i);
        }
        for(int i=0;i<len_l;i++)
        {
            *(temp+len_t+i)=list->get_index(i);
        }
        D_Array<T> *res= new D_Array<T>(temp,n_len);
        return res;
    }



};











#endif // MYCLASS_H
