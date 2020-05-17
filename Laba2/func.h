#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <string.h>
#include "mysequence.h"
using namespace std;

void arr_rand(int*arr,int size)
{
    for(int i=0;i<size;i++)
        arr[i]=rand();
}

void print_arr(int*arr,int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void print_ob(Sequence<string>* ob)
{
    int size=ob->get_length();

    for(int i=0;i<size;i++)
    {
        cout<<i<<": "<<ob->get_index(i)<<"\n";
    }
    cout<<endl;

}
void print_ob(Sequence<double>* ob)
{
    int size=ob->get_length();

    for(int i=0;i<size;i++)
    {
        cout<<i<<": "<<ob->get_index(i)<<"\n";
    }
    cout<<endl;

}
void print_ob(Sequence<complex< double >>* ob)
{
    int size=ob->get_length();
    complex< double > temp;

    for(int i=0;i<size;i++)
    {
        temp=ob->get_index(i);
        cout<<i<<": "<<"re: "<<temp.real()<<"\n   im: "<<temp.imag()<<"\n";
    }
    cout<<endl;

}
void print_dek(Deque<int>& dek)
{
    Deque<int> temp(dek);
    cout<<"///////////////////////////////////"<<endl;
    while(!temp.empty())
    {
        cout<<temp.pop_front()<<"\n";
    }
    cout<<endl;
}
template<typename T>


T set_data(T data)
{
    return data+1;
}
template<typename T>
T set_nul()
{
    return (T)0;
}
template<typename T>
bool more_two(T data)
{
    bool res=(data>(T)2);
    return res;
}

int is_max(int data)
{
    static int res=-2147483648;
    if(data>res)
    {
        res=data;
    }
    return res;

}

#endif // FUNC_H
