#ifndef MYLIST_H
#define MYLIST_H
#include"mysequence.h"

template <typename T>
class My_list : public Sequence<T>
{
  private:

    struct list
    {
        T data;
        list* p_next;
        list* p_prev;
        int id;

    };
    list* head;
    list* end;




  public:

    //---------------------------------------------------------------//

    My_list ()
    {
        this->head=nullptr;
        this->end=head;
//        this->head->data=(T)0;
//        this->head->id=0;
//        this->head->p_next=nullptr;
//        this->head->p_prev=nullptr;
        this->set_length(0);

    }

    My_list (T* items,int size)
    {
       list* temp;
       this->end=nullptr;
       this->head=nullptr;
       this->set_length(size);
       for(int i=0;i<size;i++)
       {
           temp=new list;
           temp->id=i;
           temp->data=items[i];
           temp->p_next=nullptr;
           temp->p_prev=end;
           if(this->head==nullptr)
           {
               this->head=temp;
               this->end=head;
           }
           else
           {
               this->end->p_next=temp;
               this->end=temp;
           }




       }
    }

    My_list ( Sequence <T>&  other)
    {
        int size=other.get_length();
        list* temp;
        this->end=nullptr;
        this->head=nullptr;
        this->set_length(size);
        for(int i=0;i<size;i++)
        {
            temp=new list;
            temp->id=i;
            temp->data=other.get_index(i);
            temp->p_next=nullptr;
            temp->p_prev=end;
            if(this->head==nullptr)
            {
                this->head=temp;
                this->end=head;
            }
            else
            {
                this->end->p_next=temp;
                this->end=temp;
            }
        }

    }

    ~My_list()
    {
        list* temp=this->end;
        while(temp->p_prev!=nullptr)
        {
            temp=temp->p_prev;
            delete temp->p_next;
        }
        delete this->head;
    }

    //---------------------------------------------------------------//

    T get_first() override
    {
        return this->head->data;
    }

    T get_last() override
    {
        return this->end->data;
    }

    T get_index(int index) override
    {
        if(index<this->get_length())
        {
            list* temp=this->head;
            while (temp->id!=index)
            {
                temp=temp->p_next;
            }
            return temp->data;
        }
        else
            cout<<"IndexOutOfRange"<<endl;

    }

    void set_index(int index, T dat) override
    {
        if(index<this->get_length())
        {
            list* temp=this->head;
            while (temp->id!=index)
            {
                temp=temp->p_next;
            }
            temp->data=dat;
        }
        else
            cout<<"IndexOutOfRange"<<endl;

    }



    //---------------------------------------------------------------//

    void append(T item) override
    {
        int n_len=this->get_length()+1;
        this->set_length(n_len);
        list* temp=new list;
        temp->data=item;
        temp->id=0;
        temp->p_next=this->head;
        temp->p_prev=nullptr;
        if(this->head==nullptr)
        {
            this->head=temp;
            this->end=temp;
        }
        else
        {
            this->head->p_prev=temp;
            this->head=temp;
        }
        temp=temp->p_next;
        while(temp!=nullptr)
        {
            temp->id+=1;
            temp=temp->p_next;
        }

    }

    void prepend(T item) override
    {
        int n_len=this->get_length()+1;
        this->set_length(n_len);
        list* temp=new list;
        temp->data=item;
        temp->id=n_len-1;
        temp->p_next=nullptr;
        temp->p_prev=this->end;
        if(this->head==nullptr)
        {
            this->head=temp;
            this->end=temp;
        }
        else
        {
            this->end->p_next=temp;
            this->end=temp;
        }


    }

    void del_last()
    {
        int n_len=this->get_length();
        if(n_len>1)
        {
            n_len-=1;
            list*temp=this->end->p_prev;
            temp->p_next=nullptr;
            delete this->end;
            this->end=temp;
            this->set_length(n_len);

        }
        else if(n_len==1)
        {
            this->set_length(0);
            delete this->head;
            this->head=nullptr;
            this->end=nullptr;
        }
        else
            cout<<"список пуст"<<endl;

    }

    void del_first()
    {
        int n_len=this->get_length();
        if(n_len>1)
        {
            n_len-=1;
            list*temp=this->head->p_next;
            temp->p_prev=nullptr;
            delete this->head;
            this->head=temp;
            this->set_length(n_len);

            for(int i=0;i<n_len;i++)
            {
                temp->id-=1;
                temp=temp->p_next;
            }

        }
        else if(n_len==1)
        {
            this->set_length(0);
            delete this->head;
            this->head=nullptr;
            this->end=nullptr;
        }
        else
            cout<<"список пуст"<<endl;

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
                list* temp=this->head;
                while(temp->id!=index)
                    temp=temp->p_next;
                temp->p_prev->p_next=temp->p_next;
                temp->p_next->p_prev=temp->p_prev;
                temp=temp->p_next;
                for(int i=index;i<n_len;i++)
                {
                    temp->id=i;
                    temp=temp->p_next;
                }
                this->set_length(n_len);

            }
            else if(n_len==1)
            {
                this->set_length(0);
                delete this->head;
                this->head=nullptr;
                this->end=nullptr;
            }
            else
                cout<<"список пуст"<<endl;
        }
        else
            cout<<"IndexOutOfRange\n";
    }

    void insert_at(T item, int index) override
    {
        if(index==0)
            this->append(item);
        else if(index==this->get_length()-1)
            this->prepend(item);
        else if(index<this->get_length())
        {
            int n_len=this->get_length()+1;
            this->set_length(n_len);
            list* temp=new list;
            temp->data=item;
            temp->id=index;
            list* tp=this->head;
            while(tp->id!=index)
                tp=tp->p_next;
            temp->p_next=tp;
            temp->p_prev=tp->p_prev;
            tp->p_prev->p_next=temp;
            tp->p_prev=temp;

            while(tp!=nullptr)
            {
                tp->id+=1;
                tp=tp->p_next;
            }


        }
        else
            cout<<"IndexOutOfRange"<<endl;

    }

    Sequence<T>* get_subsequence(int startIndex, int endIndex) override
    {
        if((startIndex>=0) & (endIndex>=0) & (endIndex>=startIndex) & (startIndex<this->get_length()) & (endIndex<this->get_length()))
        {
            int len=endIndex-startIndex+1;
            T*arr=new T[len];
            for(int i=startIndex;i<=endIndex;i++)
            {
                *(arr+i-startIndex)=this->get_index(i);
            }
            My_list* temp= new My_list<T>(arr,len);
            return temp;
        }
        else
            cout<<"IndexOutOfRange"<<endl;
        return nullptr;


    }

    Sequence<T>* concat(Sequence<T> *list) override
    {
        int n_len=this->get_length()+list->get_length();
        int len=this->get_length();
        T* temp= new T[n_len];
        for(int i=0;i<this->get_length();i++)
        {
            *(temp+i)=this->get_index(i);
        }
        for(int i=0;i<list->get_length();i++)
        {
            *(temp+len+i)=list->get_index(i);
        }
        My_list* res= new My_list<T>(temp,n_len);
        return res;

    }

    bool operator ==(Sequence<T>& other) override
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
            list* temp=this->head;
            while (temp->id!=index)
            {
                temp=temp->p_next;
            }
            return temp->data;
        }
        else
            cout<<"IndexOutOfRange"<<endl;
    }

    void sort_buble()
    {
        int len=this->get_length();
        T t_data;
        for(int i=0;i<len;i++)
        {
            for(int k=len-1;k>i;k--)
            {
                if(this->get_index(k-1)>this->get_index(k))
                {
                    t_data=this->get_index(k-1);
                    this->set_index(k-1,this->get_index(k));
                    this->set_index(k,t_data);
                }
            }
        }
    }

        void sort_buble_ptr()
        {
            T t_data;
            list* t1=this->head;
            list* t2=this->end;
            while(t1!=nullptr)
            {

                while(t2->id>t1->id)
                {
                    if(t2->p_prev->data<t2->data)
                    {
                        t_data=t2->p_prev->data;
                        t2->p_prev->data=t2->data;
                        t2->data=t_data;
                    }
                    t2=t2->p_prev;
                }
                t2=this->end;
                t1=t1->p_next;

            }

        }







};








#endif // MYLIST_H
