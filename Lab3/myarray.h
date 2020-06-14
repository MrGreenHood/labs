#ifndef MYARRAY_H
#define MYARRAY_H
#include"mysequence.h"


template <typename T>
class D_Array : public Sequence<T>
{
  private:

    T* ptr;



  public:

    //---------------------------------------------------------------//
    D_Array ()
    {
        T* temp= new T[0];
        this->ptr=temp;
        this->set_length(0);

    }

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

    D_Array ( Sequence <T>& other)
    {
        int size=other.get_length();
        ptr= new T[size];
        this->set_length(size);
        for(int i=0;i<size;i++)
        {
            *(ptr+i)=other.get_index(i);
        }

    }
    ~D_Array()
    {
        delete[] this->ptr;
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
        this->resize(n_len);
        *(this->ptr+n_len-1)=item;


    }

    void del_last() override
    {
        int n_len=this->get_length();
        if(n_len>1)
        {
            n_len-=1;
            this->resize(n_len);

        }
        else if(n_len==1)
        {
            this->set_length(0);
            delete this->ptr;
        }
        else
            cout<<"массив пуст"<<endl;

    }

    void del_first() override
    {
        int n_len=this->get_length();
        if(n_len>1)
        {
            n_len-=1;
            T* temp=new T[n_len];

            for(int i=0;i<n_len;i++)
            {
                temp[i]=this->get_index(i+1);
            }
            this->ptr=temp;
            this->set_length(n_len);

        }
        else if(n_len==1)
        {
            this->set_length(0);
            delete this->ptr;
        }
        else
            cout<<"список пуст\n"<<endl;

    }

    void del_index(int index) override
    {
        int n_len=this->get_length();
        if(index<n_len)
        {
            if(index==0)
                this->del_first();
            else if(index==n_len-1)
                this->del_last();
            else if(n_len>1)
            {
                n_len-=1;
                T* temp=new T[n_len];
                for(int i=0;i<index;i++)
                {
                    temp[i]=this->get_index(i);
                }
                for(int i=index;i<n_len;i++)
                {
                    temp[i]=this->get_index(i+1);
                }
                this->set_length(n_len);
                this->ptr=temp;

            }
            else if(n_len==1)
            {
                this->set_length(0);
                delete this->ptr;
            }
            else
                cout<<"список пуст"<<endl;
        }
        else
            cout<<"IndexOutOfRange\n";
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
            delete[]this->ptr;
            this->ptr=temp;
        }
        else
            cout<<"IndexOutOfRange"<<endl;

    }

    Sequence<T>* get_subsequence(int startIndex, int endIndex) override
    {
        if((startIndex>=0) & (endIndex>=0) & (endIndex>=startIndex) & (startIndex<this->get_length()) & (endIndex<this->get_length()))
        {
            D_Array<T> *temp=new D_Array<T>((endIndex-startIndex+1));
            for(int i=startIndex;i<=endIndex;i++)
            {
                temp->set_index(i-startIndex,this->get_index(i));
            }
            return temp;
        }
        else
            cout<<"IndexOutOfRange"<<endl;


    }

    Sequence<T>* concat(Sequence<T> *list) override
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

    bool operator ==(Sequence<T>& other)
    {
        int t_len=this->get_length();
        int o_len=other.get_length();

        if(t_len==o_len)
        {
            for(int i=0;i<t_len;i++)
            {
                if(this->get_index(i)!=other.get_index(i))
                    return false;
            }
        }
        else
            return false;
        return true;
    }

    int find_subsequence(Sequence<T>& other) override
    {
        int t_len=this->get_length();
        int o_len=other.get_length();
        Sequence<T>* temp;

        if(t_len==o_len)
        {
            if(*this==other)
                return 0;
            else
                return -1;
        }
        else
        {
            for(int i=0;i<=t_len-o_len;i++)
            {
                temp=this->get_subsequence(i,i+o_len-1);
                if(*temp==other)
                    return i;
            }
            return -1;
        }
    }

    T& operator [](int index)
    {
        if(index<this->get_length())
        {
            return *(this->ptr+index);
        }
        else
            cout<<"IndexOutOfRange"<<endl;
    }



};

#endif // MYARRAY_H
