#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include "deque.h"

bool operator >(const complex<double>& c1, const complex<double>& c2)
{
    double p11= pow(c1.imag(),2);
    double p12= pow(c1.real(),2);
    double p21= pow(c2.imag(),2);
    double p22= pow(c2.real(),2);
    double mc1=sqrt((p11+p12));
    double mc2=sqrt((p21+p22));
    bool res=mc1>mc2;
    return res;
}

using namespace std;

template<typename T>
class Poisk_tree
{
private:

    struct el
    {
        T data = 0;
        el *pLeft = nullptr;
        el *pRight = nullptr;
    };

    el* root;
    int length;

     void print_t(el* point)
     {
         el*temp=point;
         if(temp==nullptr)
             return;
         print_t(temp->pLeft);
         cout<<temp->data<< " ";
         print_t(temp->pRight);

     }

     void klp(el* point, Deque<T>* res)
     {
         if(point==nullptr)
             return;
         res->push_back(point->data);
         klp(point->pLeft,res);
         klp(point->pRight,res);
     }
     void kpl(el* point, Deque<T>* res)
     {
         if(point==nullptr)
             return;
         res->push_back(point->data);
         kpl(point->pRight,res);
         kpl(point->pLeft,res);
     }
     void lpk(el* point, Deque<T>* res)
     {
         if(point==nullptr)
             return;
         lpk(point->pLeft,res);
         lpk(point->pRight,res);
         res->push_back(point->data);
     }
     void lkp(el* point, Deque<T>* res)
     {
         if(point==nullptr)
             return;
         lkp(point->pLeft,res);
         res->push_back(point->data);
         lkp(point->pRight,res);
     }
     void pkl(el* point, Deque<T>* res)
     {
         if(point==nullptr)
             return;
         pkl(point->pRight,res);
         res->push_back(point->data);
         pkl(point->pLeft,res);
     }
     void plk(el* point, Deque<T>* res)
     {
         if(point==nullptr)
             return;
         plk(point->pRight,res);
         plk(point->pLeft,res);
         res->push_back(point->data);
     }

public:

    Poisk_tree()
    {
        this->root=nullptr;
        length=0;
    }

    Poisk_tree(T* item, int len)
    {
        bool fl=true;
        this->root= new el;
        this->root->data=item[0];
        this->length=len;

        for(int i=1; i<len;i++)
        {
            el* temp=this->root;
            fl=true;
            while (fl)
            {
                if(temp->data>item[i])
                {
                    if(temp->pLeft==nullptr)
                    {
                        temp->pLeft=new el;
                        temp=temp->pLeft;
                        temp->data=item[i];
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pLeft;
                    }
                }
                else
                {
                    if(temp->pRight==nullptr)
                    {
                        temp->pRight=new el;
                        temp=temp->pRight;
                        temp->data=item[i];
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pRight;
                    }
                }
            }
        }
    }
    Poisk_tree(Deque<T>* que)
    {
        bool fl=true;
        int len=1;
        this->root= new el;
        this->root->data=que->pop_front();
        T data;

        while(!que->empty())
        {
            len++;
            data=que->pop_front();
            el* temp=this->root;
            fl=true;
            while (fl)
            {
                if(temp->data>data)
                {
                    if(temp->pLeft==nullptr)
                    {
                        temp->pLeft=new el;
                        temp=temp->pLeft;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pLeft;
                    }
                }
                else
                {
                    if(temp->pRight==nullptr)
                    {
                        temp->pRight=new el;
                        temp=temp->pRight;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pRight;
                    }
                }
            }
        }
        this->length=len;
    }
    Poisk_tree(Poisk_tree<T>& other)
    {
        Deque<T>* que = other.klp_t();
        bool fl=true;
        int len=1;
        this->root= new el;
        this->root->data=que->pop_front();
        T data;

        while(!que->empty())
        {
            len++;
            data=que->pop_front();
            el* temp=this->root;
            fl=true;
            while (fl)
            {
                if(temp->data>data)
                {
                    if(temp->pLeft==nullptr)
                    {
                        temp->pLeft=new el;
                        temp=temp->pLeft;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pLeft;
                    }
                }
                else
                {
                    if(temp->pRight==nullptr)
                    {
                        temp->pRight=new el;
                        temp=temp->pRight;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pRight;
                    }
                }
            }
        }
        this->length=len;

    }

    int get_length()
    {
        return this->length;
    }

    Deque<T>* klp_t()
    {
        el* temp=this->root;
        Deque<T>*res=new Deque<T>();
        this->klp(temp,res);
        res->print();
        return res;

    }
    Deque<T>* lkp_t()
    {
        el* temp=this->root;
        Deque<T>*res=new Deque<T>();
        this->lkp(temp,res);
        res->print();
        return res;

    }

    void print()
    {
        this->print_t(this->root);
        el* temp=this->root;
        Deque<T>*res=new Deque<T>();
        ///////////////////////
        this->klp(temp,res);
        res->print();
        delete res;
        ///////////////////////
        res=new Deque<T>();
        this->kpl(temp,res);
        res->print();
        delete res;
        ///////////////////////
        res=new Deque<T>();
        this->lkp(temp,res);
        res->print();
        delete res;
        ///////////////////////
        res=new Deque<T>();
        this->lpk(temp,res);
        res->print();
        delete res;
        ///////////////////////
        res=new Deque<T>();
        this->pkl(temp,res);
        res->print();
        delete res;
        ///////////////////////
        res=new Deque<T>();
        this->plk(temp,res);
        res->print();
        delete res;
    }

    void add_el(T data)
    {
        this->length+=1;
        if(this->root==nullptr)
        {
            this->root=new el;
            this->root->data=data;
            this->root->pLeft=nullptr;
            this->root->pRight=nullptr;
        }
        else
        {
            bool fl=true;
            el* temp=this->root;
            while (fl)
            {
                if(temp->data>data)
                {
                    if(temp->pLeft==nullptr)
                    {
                        temp->pLeft=new el;
                        temp=temp->pLeft;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pLeft;
                    }
                }
                else
                {
                    if(temp->pRight==nullptr)
                    {
                        temp->pRight=new el;
                        temp=temp->pRight;
                        temp->data=data;
                        fl=false;
                    }
                    else
                    {
                        temp=temp->pRight;
                    }
                }
            }
        }

    }

    bool find_el(T data)
    {
        el* temp=this->root;
        if(temp==nullptr)
        {
            cout<<"Дерево пусто";
            return false;
        }
        while (true)
        {
            if(temp->data>data)
            {
                if(temp->pLeft==nullptr)
                    return false;
                temp=temp->pLeft;
            }
            else if(temp->data<data)
            {
                if(temp->pRight==nullptr)
                    return false;
                temp=temp->pRight;
            }
            else if(temp->data==data)
                return true;
        }
    }

    void obhod_str(string obh)
    {
        el* temp=this->root;
        Deque<T>* deq = new Deque<T>();
        switch (obh) {
        case "klp":
            this->klp(temp,deq);
            deq->print();
            break;
        case "kpl":
            this->kpl(temp,deq);
            deq->print();
            break;
        case "lpk":
            this->lpk(temp,deq);
            deq->print();
            break;
        case "lkp":
            this->lkp(temp,deq);
            deq->print();
            break;
        case "pkl":
            this->klp(temp,deq);
            deq->print();
            break;
        case "plk":
            this->klp(temp,deq);
            deq->print();
            break;
        default:
            cout<<"Такого обхода нет"<<endl;
            break;
        }
    }


    Poisk_tree* get_subtree(T data)
    {
        el* temp=this->root;
        if(temp==nullptr)
        {
            cout<<"Дерево пусто";
            return nullptr;
        }
        bool fl=true;
        while (fl)
        {
            if(temp->data>data)
            {
                if(temp->pLeft==nullptr)
                {
                    cout<<"такого поддерева нет\n";
                    return nullptr;
                }
                temp=temp->pLeft;
            }
            else if(temp->data<data)
            {
                if(temp->pRight==nullptr)
                {
                    cout<<"такого поддерева нет\n";
                    return nullptr;
                }
                temp=temp->pRight;
            }
            else if(temp->data==data)
                fl=false;
        }
        Deque<T>* res= new Deque<T>();
        this->klp(temp,res);
        Poisk_tree<T> *ret=new Poisk_tree<T>(res);
        return ret;
    }

    bool find_subtree(Poisk_tree<T>& other)
    {
        Deque<T> *que1=new Deque<T>();
        Deque<T> *que2=new Deque<T>();
        que1=this->klp_t();
        que2=other.klp_t();

        int fl=que1->find_subsequence(*que2);
        return fl!=0;
    }

    Poisk_tree* concat(Poisk_tree<T>& other)
    {
        Deque<T> *que1=new Deque<T>();
        Deque<T> *que2=new Deque<T>();
        que1=this->klp_t();
        que2=other.klp_t();
        Deque<T> *que=que1->concat(que2);
        Poisk_tree<T> *res=new Poisk_tree<T>(que);
        return res;
    }

    Poisk_tree* map(T(*func)(T))
    {
        Deque<T> *que=this->klp_t();
        que->map(func);
        Poisk_tree<T>* res=new Poisk_tree<T>(que);
        return res;
    }

    Poisk_tree* map(T(*func)(void))
    {
        Deque<T> *que=this->klp_t();
        que->map(func);
        Poisk_tree<T>* res=new Poisk_tree<T>(que);
        return res;
    }

    Poisk_tree* where(bool(*func)(T))
    {
        Deque<T> *que=this->klp_t();
        que->where(func);
        Poisk_tree<T>* res=new Poisk_tree<T>(que);
        return res;
    }

    T reduce(T(*func)(T))
    {
        Deque<T>* d1=this->klp_t();
        int res = d1->reduce(func);
        return res;
    }

};

#endif // TREE_H
