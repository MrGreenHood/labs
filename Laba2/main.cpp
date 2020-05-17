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
        cout<<"Выберите тип данных(array/list): ";
        cin>>type;
        while(question!=0)
        {
            cout<<"Для завершения программы нажмите 0\nДля работы со строками введите 1\nДля работы с десятичными числами введите 2\nДля работы с комплексными числами введите 3\nДля запуска теста исходных классов введите 4\n";
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
                    cout<<"Заполните дек\nВведите длину: ";
                    int len;
                    cin>>len;
                    cout<<"Введите последоваельность\n";
                    for(int i=0;i<len;i++)
                    {
                        cin>>temps;
                        firsts.push_back(temps);
                    }
                }
                while(work!=0)
                {
                    cout<<"для добавления элемента в начало введите 1\nДля добавления элемента в конец введите 2\nДля извлечения элемента с начала введите 3\nДля извлечения элемента с конца введите 4\nДля извлечения одпоследовательности введите 5\nДля поиска подпоследовательности введите 6\nMap-7\nWhere-8\nReduce-9\nConcat-10\n";
                    cin>>function;
                    switch (function)
                    {

                    case 1:
                        cout<<"Введите строку: ";
                        cin>>temps;
                        firsts.push_front(temps);
                        firsts.print();
                        break;
                    case 2:
                        cout<<"Введите строку: ";
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
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }
                        firsts.print();
                        cout<<"Введите начало: ";
                        cin>>start_index;
                        cout<<"Введите конец: ";
                        cin>>end_index;

                        Deque<string>* seconds=firsts.get_subsequnce(start_index,end_index);
                        seconds->print();
                    }
                        break;
                    case 6:
                    {
                        if(firsts.empty())
                        {
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }
                        int size=0;
                        cout<<"Введите размер подпоследовательности: ";
                        cin>>size;
                        string temp[size];
                        cout<<"Введите подпоследовательность\n";
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
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
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
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
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
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
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
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }
                        int size=0;
                        cout<<"Введите размер последовательности: ";
                        cin>>size;
                        cout<<"Введите последовательность\n";
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
                    cout<<"Для продолжения введите 1, иначе 0: ";
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
                    cout<<"Заполните дек\nВведите длину: ";
                    int len;
                    cin>>len;
                    cout<<"Введите последоваельность\n";
                    for(int i=0;i<len;i++)
                    {
                        cin>>temps;
                        firsts.push_back(temps);
                    }
                }
                while (work!=0)
                {
                    cout<<"для добавления элемента в начало введите 1\nДля добавления элемента в конец введите 2\nДля извлечения элемента с начала введите 3\nДля извлечения элемента с конца введите 4\nДля извлечения одпоследовательности введите 5\nДля поиска подпоследовательности введите 6\nMap-7\nWhere-8\nReduce-9\nConcat-10\n";
                    cin>>function;
                    switch (function)
                    {

                    case 1:
                        cout<<"Введите число: ";
                        cin>>temps;
                        firsts.push_front(temps);
                        firsts.print();
                        break;
                    case 2:
                        cout<<"Введите число: ";
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
                            cout<<"Заполните дек\nВведите длину: ";
                            int len;
                            cin>>len;
                            cout<<"Введите последоваельность\n";
                            for(int i=0;i<len;i++)
                            {
                                cin>>temps;
                                firsts.push_back(temps);
                            }
                        }
                        firsts.print();

                        cout<<"Введите начало: ";
                        cin>>start_index;
                        cout<<"Введите конец: ";
                        cin>>end_index;

                        Deque<double>* seconds=firsts.get_subsequnce(start_index,end_index);
                        seconds->print();
                    }
                        break;
                    case 6:
                    {
                        Deque<double> first(type);
                        cout<<"Заполните дек\nВведите длину: ";
                        int len;
                        cin>>len;
                        cout<<"Введите последоваельность\n";
                        for(int i=0;i<len;i++)
                        {
                            cin>>temps;
                            first.push_back(temps);
                        }
                        int size=0;
                        cout<<"Введите размер подпоследовательности: ";
                        cin>>size;
                        double temp[size];
                        cout<<"Введите подпоследовательность\n";
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
                        cout<<"Заполните дек\nВведите длину: ";
                        int len;
                        cin>>len;
                        cout<<"Введите последоваельность\n";
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
                        cout<<"Заполните дек\nВведите длину: ";
                        int len;
                        cin>>len;
                        cout<<"Введите последоваельность\n";
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
                        cout<<"Заполните дек\nВведите длину: ";
                        int len;
                        cin>>len;
                        cout<<"Введите последоваельность\n";
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
                        cout<<"Заполните 1 дек\nВведите длину: ";
                        int len;
                        cin>>len;
                        cout<<"Введите последоваельность\n";
                        for(int i=0;i<len;i++)
                        {
                            cin>>temps;
                            first.push_back(temps);
                        }
                        first.print();
                        int size=0;
                        cout<<"Введите размер последовательности: ";
                        cin>>size;
                        cout<<"Введите последовательность\n";
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
                    cout<<"Для продолжения введите 1, иначе 0: ";
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
                    cout<<"Заполните дек\nВведите длину: ";
                    int len;
                    cin>>len;
                    cout<<"Введите последоваельность\n";
                    for(int i=0;i<len;i++)
                    {
                        cin>>temps;
                        firsts.push_back(temps);
                    }
                }
                while (work!=0)
                {
                    cout<<"для добавления элемента в начало введите 1\nДля добавления элемента в конец введите 2\nДля извлечения элемента с начала введите 3\nДля извлечения элемента с конца введите 4\nДля извлечения одпоследовательности введите 5\nДля поиска подпоследовательности введите 6\nMap-7\nWhere-8\nReduce-9\nConcat-10\n";
                    cin>>function;
                    switch (function)
                    {

                    case 1:
                        cout<<"Введите число(re,im): ";
                        cout<<"Введите последоваельность(re,im)\n";
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
                        cout<<"Введите строку: ";
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
                            cout<<"Введите последоваельность(re,im)\n";
                            cout<<"Заполните дек\nВведите длину: ";
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
                        cout<<"Введите начало: ";
                        cin>>start_index;
                        cout<<"Введите конец: ";
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
                            cout<<"Введите последоваельность(re,im)\n";
                            cout<<"Заполните дек\nВведите длину: ";
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
                        cout<<"Введите размер подпоследовательности: ";
                        cin>>size;
                        complex<double> temp[size];
                        cout<<"Введите подпоследовательность";
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
                            cout<<"Введите последоваельность(re,im)\n";
                            cout<<"Заполните дек\nВведите длину: ";
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
                            cout<<"Введите последоваельность(re,im)\n";
                            cout<<"Заполните дек\nВведите длину: ";
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
                            cout<<"Введите последоваельность(re,im)\n";
                            cout<<"Заполните дек\nВведите длину: ";
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
                            cout<<"Введите последоваельность(re,im)\n";
                            cout<<"Заполните дек\nВведите длину: ";
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
                        cout<<"Введите размер последовательности: ";
                        cin>>size;
                        cout<<"Введите последоваельность(re,im)";
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
                    cout<<"Для продолжения введите 1, иначе 0: ";
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
