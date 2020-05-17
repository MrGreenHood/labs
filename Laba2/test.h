#ifndef TEST_H
#define TEST_H

#include "myarray.h"
#include "mylist.h"
#include "deque.h"
#include "func.h"
using namespace std;


void test_d_arr(void)
{
    cout<<"TEST ARRAY\n";
    double arrf[5]={1,-2,3,-4,5};
    complex< double > arrc[10]={1,-2,3,-4,5,-6,7,-8,9,0};
    string arrs[5]=
    {
        "abcd",
        "qweerty",
        "point",
        "hk",
        ""
    };
    D_Array<double>* df1=new D_Array<double>(arrf,5);
    Sequence<double>* df2;
    D_Array<complex< double >>* dc1=new D_Array<complex< double >>(arrc,5);
    Sequence<complex< double >>* dc2;
    D_Array<string>* ds1=new D_Array<string>(arrs,5);
    Sequence<string>* ds2;

    print_ob(df1);
    print_ob(dc1);
    print_ob(ds1);


    cout<<"append:"<<endl;
    df1->append(5.4);
    cout<<"double: "<<(df1->get_first()==5.4)<<endl;
    ds1->append("ddt");
    cout<<"string: "<<(ds1->get_first()=="ddt")<<endl;
    dc1->append(arrc[7]);
    cout<<"complex: "<<(dc1->get_first()==arrc[7])<<endl;

    cout<<endl<<"prepend:"<<endl;
    df1->prepend(7.4);
    cout<<"double: "<<(df1->get_last()==7.4)<<endl;
    ds1->prepend("thhj");
    cout<<"string: "<<(ds1->get_last()=="thhj")<<endl;
    dc1->prepend(arrc[6]);
    cout<<"complex: "<<(dc1->get_last()==arrc[6])<<endl;

    cout<<endl<<"insert:"<<endl;
    df1->insert_at(3.4,2);
    cout<<"double: "<<(df1->get_index(2)==3.4)<<endl;
    ds1->insert_at("thj",3);
    cout<<"string: "<<(ds1->get_index(3)=="thj")<<endl;
    dc1->insert_at(arrc[8],6);
    cout<<"complex: "<<(dc1->get_index(6)==arrc[8])<<endl;

    cout<<endl<<"get_subsequnce:"<<endl;
    df2=df1->get_subsequence(1,7);
    cout<<"df1:"<<endl;
    print_ob(df1);
    cout<<endl<<"df2(1-7):"<<endl;
    print_ob(df2);
    ds2=ds1->get_subsequence(0,3);
    cout<<endl<<"ds1:"<<endl;
    print_ob(ds1);
    cout<<endl<<"ds2(0-3):"<<endl;
    print_ob(ds2);
    dc2=dc1->get_subsequence(0,7);
    cout<<endl<<"dc1:"<<endl;
    print_ob(dc1);
    cout<<endl<<"dc2(0-7):"<<endl;
    print_ob(dc2);

    cout<<endl<<"concat:"<<endl;
    df2=df1->concat(df2);
    cout<<endl<<"df3:"<<endl;
    print_ob(df2);
    ds2=ds1->concat(ds2);
    cout<<endl<<"ds3:"<<endl;
    print_ob(ds2);
    dc2=dc1->concat(dc2);
    cout<<endl<<"dc3:"<<endl;
    print_ob(dc2);

    cout<<endl<<"del_index:"<<endl;

    print_ob(df1);
    df1->del_index(0);
    print_ob(df1);
    ds1->del_index(0);
    print_ob(ds1);
    dc1->del_index(0);
    print_ob(dc1);

    print_ob(df1);
    df1->del_index(df1->get_length()-1);
    print_ob(df1);
    ds1->del_index(ds1->get_length()-1);
    print_ob(ds1);
    dc1->del_index(dc1->get_length()-1);
    print_ob(dc1);

    print_ob(df1);
    df1->del_index(2);
    print_ob(df1);
    ds1->del_index(2);
    print_ob(ds1);
    dc1->del_index(2);
    print_ob(dc1);

}


void test_d_list(void)
{
    cout<<"TEST LIST\n";
    double arrf[5]={1,-2,3,-4,5};
    complex< double > arrc[10]={1,-2,3,-4,5,-6,7,-8,9,0};
    string arrs[5]=
    {
        "abcd",
        "qweerty",
        "point",
        "hk",
        ""
    };
    My_list<double>* df1=new My_list<double>(arrf,5);
    Sequence<double>* df2;
    My_list<complex< double >>* dc1=new My_list<complex< double >>(arrc,5);
    Sequence<complex< double >>* dc2;
    My_list<string>* ds1=new My_list<string>(arrs,5);
    Sequence<string>* ds2;

    print_ob(df1);
    print_ob(dc1);
    print_ob(ds1);


    cout<<"append:"<<endl;
    df1->append(5.4);
    cout<<"double: "<<(df1->get_first()==5.4)<<endl;
    ds1->append("ddt");
    cout<<"string: "<<(ds1->get_first()=="ddt")<<endl;
    dc1->append(arrc[7]);
    cout<<"complex: "<<(dc1->get_first()==arrc[7])<<endl;

    cout<<endl<<"prepend:"<<endl;
    df1->prepend(7.4);
    cout<<"double: "<<(df1->get_last()==7.4)<<endl;
    ds1->prepend("thhj");
    cout<<"string: "<<(ds1->get_last()=="thhj")<<endl;
    dc1->prepend(arrc[6]);
    cout<<"complex: "<<(dc1->get_last()==arrc[6])<<endl;

    cout<<endl<<"insert:"<<endl;
    df1->insert_at(3.4,2);
    cout<<"double: "<<(df1->get_index(2)==3.4)<<endl;
    ds1->insert_at("thj",3);
    cout<<"string: "<<(ds1->get_index(3)=="thj")<<endl;
    dc1->insert_at(arrc[8],6);
    cout<<"complex: "<<(dc1->get_index(6)==arrc[8])<<endl;

    cout<<endl<<"get_subsequnce:"<<endl;
    df2=df1->get_subsequence(1,7);
    cout<<"df1:"<<endl;
    print_ob(df1);
    cout<<endl<<"df2(1-7):"<<endl;
    print_ob(df2);
    ds2=ds1->get_subsequence(0,3);
    cout<<endl<<"ds1:"<<endl;
    print_ob(ds1);
    cout<<endl<<"ds2(0-3):"<<endl;
    print_ob(ds2);
    dc2=dc1->get_subsequence(0,7);
    cout<<endl<<"dc1:"<<endl;
    print_ob(dc1);
    cout<<endl<<"dc2(0-7):"<<endl;
    print_ob(dc2);

    cout<<endl<<"concat:"<<endl;
    df2=df1->concat(df2);
    cout<<endl<<"df3:"<<endl;
    print_ob(df2);
    ds2=ds1->concat(ds2);
    cout<<endl<<"ds3:"<<endl;
    print_ob(ds2);
    dc2=dc1->concat(dc2);
    cout<<endl<<"dc3:"<<endl;
    print_ob(dc2);

    cout<<endl<<"del_index:"<<endl;

    print_ob(df1);
    df1->del_index(0);
    print_ob(df1);
    ds1->del_index(0);
    print_ob(ds1);
    dc1->del_index(0);
    print_ob(dc1);

    print_ob(df1);
    df1->del_index(df1->get_length()-1);
    print_ob(df1);
    ds1->del_index(ds1->get_length()-1);
    print_ob(ds1);
    dc1->del_index(dc1->get_length()-1);
    print_ob(dc1);

    print_ob(df1);
    df1->del_index(2);
    print_ob(df1);
    ds1->del_index(2);
    print_ob(ds1);
    dc1->del_index(2);
    print_ob(dc1);


}



#endif // TEST_H
