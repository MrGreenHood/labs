#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <functional>
#include "myarray.h"
#include "mylist.h"
#include "deque.h"
#include "func.h"
#include "test.h"

using namespace std;




int main()
{
    setlocale(LC_ALL,"RUS");
    srand((time(0)));
    string type="array";
        int work=-1;
        int question=-1;
        int function=0;
        cout<<"�������� ��� ������(array/list): ";
        cin>>type;
        while(question!=0)
        {
            cout<<"��� ���������� ��������� ������� 0\n��� ������ �� �������� ������� 1\n��� ������ � ����������� ������� ������� 2\n��� ������ � ������������ ������� ������� 3\n��� ������� ����� �������� ������� ������� 4\n";
            cin>>question;

            if(question==0)
                continue;
            else if(question==1)
            {

                Deque<string> firsts(type);
                string temps;
                int start_index,end_index;
                if(firsts.empty())
                {
                    cout<<"��������� ���\n������� �����: ";
                    int len;
                    cin>>len;
                    cout<<"������� �����������������\n";
                    for(int i=0;i<len;i++)
                    {
                        cin>>temps;
                        firsts.push_back(temps);
                    }
                }
                while(work!=0)
                {
                    cout<<"��� ���������� �������� � ������ ������� 1\n��� ���������� �������� � ����� ������� 2\n��� ���������� �������� � ������ ������� 3\n��� ���������� �������� � ����� ������� 4\n��� ���������� �������������������� ������� 5\n��� ������ ��������������������� ������� 6\nMap-7\nWhere-8\nReduce-9\nConcat-10\n";
                    cin>>function;
                    switch (function)
                    {

                    case 1:
                        cout<<"������� ������: ";
                        cin>>temps;
                        firsts.push_front(temps);
                        firsts.print();
                        break;
                    case 2:
                        cout<<"������� ������: ";
                        cin>>temps;
                        firsts.push_back(temps);
                        firsts.print();
                        break;
                    case 3:
                        cout<<firsts.pop_front()<<endl;
                        break;
                    case 4:
                        cout<<firsts.pop_front()<<endl;
                        break;
                    case 5:
                    {
                        if(firsts.empty())
                        {
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            cout<<"������� �����������������\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }
                        firsts.print();
                        cout<<"������� ������: ";
                        cin>>start_index;
                        cout<<"������� �����: ";
                        cin>>end_index;

                        Deque<string>* seconds=firsts.get_subsequnce(start_index,end_index);
                        seconds->print();
                    }
                        break;
                    case 6:
                    {
                        if(firsts.empty())
                        {
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            cout<<"������� �����������������\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }
                        int size=0;
                        cout<<"������� ������ ���������������������: ";
                        cin>>size;
                        string temp[size];
                        cout<<"������� ���������������������\n";
                        for(int i=0;i<size;i++)
                        {
                            cin>>temp[i];
                        }
                        cout<<firsts.find_subsequence(temp,size);
                    }
                        break;
                    case 7:
                    {
                        if(firsts.empty())
                        {
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            cout<<"������� �����������������\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }
                        firsts.map(set_nul);
                        firsts.print();
                    }
                        break;
                    case 8:
                    {
                        if(firsts.empty())
                        {
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            cout<<"������� �����������������\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }

                    }

                        break;
                    case 9:
                    {
                        if(firsts.empty())
                        {
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            cout<<"������� �����������������\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }

                    }

                        break;
                    case 10:
                    {
                        Deque<string> second(type);
                        Deque<string> *third;
                        if(firsts.empty())
                        {
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            cout<<"������� �����������������\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }
                        int size=0;
                        cout<<"������� ������ ������������������: ";
                        cin>>size;
                        cout<<"������� ������������������\n";
                        for(int i=0;i<size;i++)
                        {
                            cin>>temps;
                            second.push_back(temps);
                        }
                        second.print();
                        third=firsts.concat(&second);
                        third->print();
                    }

                        break;
                    default:
                        break;
                    }
                    cout<<"��� ����������� ������� 1, ����� 0: ";
                    cin>>work;



                }
            }

            /////////////////////////////////////////////////////////////////////////////////
            else if(question==2)
            {

                Deque<double> firsts(type);
                double temps;
                int start_index,end_index;
                if(firsts.empty())
                {
                    cout<<"��������� ���\n������� �����: ";
                    int len;
                    cin>>len;
                    cout<<"������� �����������������\n";
                    for(int i=0;i<len;i++)
                    {
                        cin>>temps;
                        firsts.push_back(temps);
                    }
                }
                while (work!=0)
                {
                    cout<<"��� ���������� �������� � ������ ������� 1\n��� ���������� �������� � ����� ������� 2\n��� ���������� �������� � ������ ������� 3\n��� ���������� �������� � ����� ������� 4\n��� ���������� �������������������� ������� 5\n��� ������ ��������������������� ������� 6\nMap-7\nWhere-8\nReduce-9\nConcat-10\n";
                    cin>>function;
                    switch (function)
                    {

                    case 1:
                        cout<<"������� �����: ";
                        cin>>temps;
                        firsts.push_front(temps);
                        firsts.print();
                        break;
                    case 2:
                        cout<<"������� �����: ";
                        cin>>temps;
                        firsts.push_back(temps);
                        firsts.print();
                        break;
                    case 3:
                        cout<<firsts.pop_front()<<endl;
                        break;
                    case 4:
                        cout<<firsts.pop_front()<<endl;
                        break;
                    case 5:
                    {
                        if(firsts.empty())
                        {
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            cout<<"������� �����������������\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }
                        firsts.print();

                        cout<<"������� ������: ";
                        cin>>start_index;
                        cout<<"������� �����: ";
                        cin>>end_index;

                        Deque<double>* seconds=firsts.get_subsequnce(start_index,end_index);
                        seconds->print();
                    }
                        break;
                    case 6:
                    {
                        Deque<double> first(type);
                        cout<<"��������� ���\n������� �����: ";
                        int len;
                        cin>>len;
                        cout<<"������� �����������������\n";
                        for(int i=0;i<len;i++)
                        {
                            cin>>temps;
                            first.push_back(temps);
                        }
                        int size=0;
                        cout<<"������� ������ ���������������������: ";
                        cin>>size;
                        double temp[size];
                        cout<<"������� ���������������������\n";
                        for(int i=0;i<size;i++)
                        {
                            cin>>temp[i];
                        }
                        cout<<first.find_subsequence(temp,size);
                    }
                        break;
                    case 7:
                    {
                        Deque<double> first(type);
                        cout<<"��������� ���\n������� �����: ";
                        int len;
                        cin>>len;
                        cout<<"������� �����������������\n";
                        for(int i=0;i<len;i++)
                        {
                            cin>>temps;
                            first.push_back(temps);
                        }
                        first.map(set_nul);
                        first.print();
                    }
                        break;
                    case 8:
                    {
                        Deque<double> first(type);
                        cout<<"��������� ���\n������� �����: ";
                        int len;
                        cin>>len;
                        cout<<"������� �����������������\n";
                        for(int i=0;i<len;i++)
                        {
                            cin>>temps;
                            first.push_back(temps);
                        }
                        first.delete_subsequnce([](double a){return (((int)a%2)==0);});
                        first.print();

                    }

                        break;
                    case 9:
                    {
                        Deque<double> first(type);
                        cout<<"��������� ���\n������� �����: ";
                        int len;
                        cin>>len;
                        cout<<"������� �����������������\n";
                        for(int i=0;i<len;i++)
                        {
                            cin>>temps;
                            first.push_back(temps);
                        }

                    }

                        break;
                    case 10:
                    {
                        Deque<double> first(type);
                        Deque<double> second(type);
                        Deque<double> *third;
                        cout<<"��������� 1 ���\n������� �����: ";
                        int len;
                        cin>>len;
                        cout<<"������� �����������������\n";
                        for(int i=0;i<len;i++)
                        {
                            cin>>temps;
                            first.push_back(temps);
                        }
                        first.print();
                        int size=0;
                        cout<<"������� ������ ������������������: ";
                        cin>>size;
                        cout<<"������� ������������������\n";
                        for(int i=0;i<size;i++)
                        {
                            cin>>temps;
                            second.push_back(temps);
                        }
                        second.print();
                        third=first.concat(&second);
                        third->print();
                    }

                        break;
                    default:
                        break;
                    }
                    cout<<"��� ����������� ������� 1, ����� 0: ";
                    cin>>work;

                }

            }
            /////////////////////////////////////////////////////////////////////////////////////////
            else if(question==3)
            {

                Deque<complex<double>> firsts(type);
                complex<double> temps;
                int start_index,end_index;
                if(firsts.empty())
                {
                    cout<<"��������� ���\n������� �����: ";
                    int len;
                    cin>>len;
                    cout<<"������� �����������������\n";
                    for(int i=0;i<len;i++)
                    {
                        cin>>temps;
                        firsts.push_back(temps);
                    }
                }
                while (work!=0)
                {
                    cout<<"��� ���������� �������� � ������ ������� 1\n��� ���������� �������� � ����� ������� 2\n��� ���������� �������� � ������ ������� 3\n��� ���������� �������� � ����� ������� 4\n��� ���������� �������������������� ������� 5\n��� ������ ��������������������� ������� 6\nMap-7\nWhere-8\nReduce-9\nConcat-10\n";
                    cin>>function;
                    switch (function)
                    {

                    case 1:
                        cout<<"������� �����(re,im): ";
                        cout<<"������� �����������������(re,im)\n";
                    {
                            double re=0;
                            double im=0;
                            cin>>re;
                            cin>>im;
                            complex<double>temp(re,im);
                            firsts.push_front(temp);
                        }
                        firsts.print();
                        break;
                    case 2:
                        cout<<"������� ������: ";
                        cin>>temps;
                        firsts.push_back(temps);
                        firsts.print();
                        break;
                    case 3:
                        cout<<firsts.pop_front()<<endl;
                        break;
                    case 4:
                        cout<<firsts.pop_front()<<endl;
                        break;
                    case 5:

                    {
                        if(firsts.empty())
                        {
                            cout<<"������� �����������������(re,im)\n";
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            double re=0;
                            double im=0;
                            for(int i=0;i<len;i++)
                            {
                                cin>>re;
                                cin>>im;
                                complex<double>temp(re,im);
                                firsts.push_back(temp);
                            }
                        }
                        firsts.print();
                        cout<<"������� ������: ";
                        cin>>start_index;
                        cout<<"������� �����: ";
                        cin>>end_index;
                    {
                        Deque<complex<double>>* seconds=firsts.get_subsequnce(start_index,end_index);
                        if(seconds!=nullptr)
                            seconds->print();
                    }
                    }
                        break;
                    case 6:
                    {
                        if(firsts.empty())
                        {
                            cout<<"������� �����������������(re,im)\n";
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            double re=0;
                            double im=0;
                            for(int i=0;i<len;i++)
                            {
                                cin>>re;
                                cin>>im;
                                complex<double>temp(re,im);
                                firsts.push_back(temp);
                            }
                        }
                        firsts.print();
                        int size=0;
                        cout<<"������� ������ ���������������������: ";
                        cin>>size;
                        complex<double> temp[size];
                        cout<<"������� ���������������������";
                        for(int i=0;i<size;i++)
                        {
                            cin>>temp[i];
                        }
                        cout<<firsts.find_subsequence(temp,size);
                    }
                        break;
                    case 7:
                    {
                        if(firsts.empty())
                        {
                            cout<<"������� �����������������(re,im)\n";
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            double re=0;
                            double im=0;
                            for(int i=0;i<len;i++)
                            {
                                cin>>re;
                                cin>>im;
                                complex<double>temp(re,im);
                                firsts.push_back(temp);
                            }
                        }
                        firsts.print();
                        firsts.map(set_nul);
                        firsts.print();
                    }
                        break;
                    case 8:
                    {
                        if(firsts.empty())
                        {
                            cout<<"������� �����������������(re,im)\n";
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            double re=0;
                            double im=0;
                            for(int i=0;i<len;i++)
                            {
                                cin>>re;
                                cin>>im;
                                complex<double>temp(re,im);
                                firsts.push_back(temp);
                            }
                        }
                        firsts.print();

                    }

                        break;
                    case 9:
                    {
                        if(firsts.empty())
                        {
                            cout<<"������� �����������������(re,im)\n";
                            cout<<"��������� ���\n������� �����: ";
                            int len;
                            cin>>len;
                            double re=0;
                            double im=0;
                            for(int i=0;i<len;i++)
                            {
                                cin>>re;
                                cin>>im;
                                complex<double>temp(re,im);
                                firsts.push_back(temp);
                            }
                        }
                        firsts.print();

                    }

                        break;
                    case 10:
                    {
                        Deque<complex<double>> second(type);
                        Deque<complex<double>> *third;
                        double re=0;
                        double im=0;
                        int len;
                        if(firsts.empty())
                        {
                            cout<<"������� �����������������(re,im)\n";
                            cout<<"��������� ���\n������� �����: ";
                            cin>>len;
                            for(int i=0;i<len;i++)
                            {
                                cin>>re;
                                cin>>im;
                                complex<double>temp(re,im);
                                firsts.push_back(temp);
                            }
                        }
                        firsts.print();
                        int size=0;
                        cout<<"������� ������ ������������������: ";
                        cin>>size;
                        cout<<"������� �����������������(re,im)";
                        for(int i=0;i<len;i++)
                        {
                            cin>>re;
                            cin>>im;
                            complex<double>temp(re,im);
                            second.push_back(temp);
                        }
                        second.print();
                        third=firsts.concat(&second);
                        third->print();
                    }

                        break;
                    default:
                        break;
                    }
                    cout<<"��� ����������� ������� 1, ����� 0: ";
                    cin>>work;
                }


            }
            else if(question==4)
            {
                test_d_arr();
                test_d_list();
            }
            question=-1;







    }




    return 0;
}
