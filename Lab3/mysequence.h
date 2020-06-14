#ifndef MYSEQUENCE_H
#define MYSEQUENCE_H
#include <iostream>
#include <string>
#include <typeinfo.h>
#include <complex>
using namespace std;

//struct Complex
//{
//    int re;
//    int im;
//};

//bool operator ==(const Complex& a, const Complex& b)
//{
//    return ((a.re==b.re)&&(a.im==b.im));
//}
//bool operator !=(const Complex& a, const Complex& b)
//{
//    return !((a.re==b.re)&&(a.im==b.im));
//}


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
    virtual Sequence<T>* concat(Sequence <T> *list)=0;
    virtual void del_last()=0;
    virtual void del_first()=0;
    virtual int find_subsequence(Sequence<T>& other)=0;
    virtual void del_index(int index)=0;
    virtual bool operator ==(Sequence<T>& other)=0;
};


#endif // MYSEQUENCE_H
