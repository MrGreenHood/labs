#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <functional>
#include <complex>
#include "poisk_tree.h"
#include "bin_heap_a.h"
#include "bin_heap_l.h"
#include "queue.h"
#include "func.h"

//        Poisk_tree<int> a(f,10);
//        a.klp_t();
//        a.add_el(-10);
//        Poisk_tree<int> b(a.klp_t());
//        b.klp_t();
//        cout<<b.find_el(-15)<<endl<<b.get_length()<<endl;
//        Poisk_tree<int>* c=b.get_subtree(38);
//        c->klp_t();
//        cout<<b.find_subtree(*c);
//        Poisk_tree<int>* d=new Poisk_tree<int>(b);
//        d->klp_t();



//    Bin_heap_l<int> e(f,16);
//    e.out_heap();
//    e.out();
//    cout<< e.get_max()<<endl;
//    cout<< e.get_max()<<endl;
//    cout<< e.get_max()<<endl;
//    cout<< e.get_max()<<endl;
//    cout<< e.get_max()<<endl;
//    cout<< e.get_max()<<endl;
//    cout<< e.get_max()<<endl;
//    cout<< e.get_max()<<endl;
//    cout<< e.get_max()<<endl;
//    e.out_heap();
//    e.out_pair();
//    e.out();
   // cout<<k->find_subtree(e)<<endl;
   // cout<<e.find_subtree(e);


using namespace std;




int main()
{
    setlocale(LC_ALL,"RUS");
    srand((time(0)));
    int f[16]={6,5,7,98,38,4,875,10,10,70,1,2,3,1,2,3};

    int work=-1;
    int question=-1;
    int function=0;
            Poisk_tree<int> a(f,10);
            a.klp_t();
            a.add_el(-10);
            Poisk_tree<int> b(a.klp_t());
            b.klp_t();
            cout<<b.find_el(-15)<<endl<<b.get_length()<<endl;
            Poisk_tree<int>* c=b.get_subtree(38);
            c->klp_t();
            cout<<b.find_subtree(*c);
            Poisk_tree<int>* d=new Poisk_tree<int>(b);
            d->klp_t();
    while(question!=0)
    {
        cout<<"Для завершения программы нажмите 0\nДля работы со строками введите 1\nДля работы с десятичными числами введите 2\nДля работы с комплексными числами введите 3\n";
        cin>>question;

        if(question==0)
            continue;
        else if(question==1)
        {

            Queue<string> firsts;
            string temps;
            int start_index,end_index;
            if(firsts.empty())
            {
                cout<<"Заполните очередь\nВведите длину: ";
                int len;
                cin>>len;
                cout<<"Введите последоваельность\n";
                for(int i=0;i<len;i++)
                {
                    cin>>temps;
                    firsts.add_el(temps);
                }
            }
            while(work!=0)
            {
                cout<<"для добавления элемента введите 1\nДля извлечения максимального элемента введите 2\nДля извлечения минимального элемента введите 3\nДля извлечения одпоследовательности введите 4\nДля поиска подпоследовательности введите 5\nMap-6\nWhere-7\nReduce-8\nConcat-9\n";
                cin>>function;
                switch (function)
                {

                case 1:
                    cout<<"Введите строку: ";
                    cin>>temps;
                    firsts.add_el(temps);
                    firsts.print();
                    break;
                case 2:
                    cout<<firsts.get_max()<<endl;
                    break;
                case 3:
                    cout<<firsts.get_min()<<endl;
                    break;
                case 4:
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
                            firsts.add_el(temps);
                        }
                    }
                    firsts.print();
                    cout<<"Введите начало: ";
                    cin>>start_index;
                    cout<<"Введите конец: ";
                    cin>>end_index;

                    Queue<string>* seconds=firsts.get_subsequence(start_index,end_index);
                    seconds->print();
                }
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
                            firsts.add_el(temps);
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
                            firsts.add_el(temps);
                        }
                    }
                    firsts.map(set_nul);
                    firsts.print();
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
                            firsts.add_el(temps);
                        }
                    }

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
                            firsts.add_el(temps);
                        }
                    }

                }

                    break;
                case 9:
                {
                    Queue<string> second;
                    Queue<string> *third;
                    if(firsts.empty())
                    {
                        cout<<"Заполните дек\nВведите длину: ";
                        int len;
                        cin>>len;
                        cout<<"Введите последоваельность\n";
                        for(int i=0;i<len;i++)
                        {
                            cin>>temps;
                            firsts.add_el(temps);
                        }
                    }
                    int size=0;
                    cout<<"Введите размер последовательности: ";
                    cin>>size;
                    cout<<"Введите последовательность\n";
                    for(int i=0;i<size;i++)
                    {
                        cin>>temps;
                        second.add_el(temps);
                    }
                    second.print();
                    third=firsts.concat(second);
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

            Queue<double> firsts;
            double temps;
            int start_index,end_index;
            if(firsts.empty())
            {
                cout<<"Заполните очередь\nВведите длину: ";
                int len;
                cin>>len;
                cout<<"Введите последоваельность\n";
                for(int i=0;i<len;i++)
                {
                    cin>>temps;
                    firsts.add_el(temps);
                }
            }
            while(work!=0)
            {
                cout<<"для добавления элемента введите 1\nДля извлечения максимального элемента введите 2\nДля извлечения минимального элемента введите 3\nДля извлечения одпоследовательности введите 4\nДля поиска подпоследовательности введите 5\nMap-6\nWhere-7\nReduce-8\nConcat-9\n";
                cin>>function;
                switch (function)
                {

                case 1:
                    cout<<"Введите строку: ";
                    cin>>temps;
                    firsts.add_el(temps);
                    firsts.print();
                    break;
                case 2:
                    cout<<firsts.get_max()<<endl;
                    break;
                case 3:
                    cout<<firsts.get_min()<<endl;
                    break;
                case 4:
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
                            firsts.add_el(temps);
                        }
                    }
                    firsts.print();
                    cout<<"Введите начало: ";
                    cin>>start_index;
                    cout<<"Введите конец: ";
                    cin>>end_index;

                    Queue<double>* seconds=firsts.get_subsequence(start_index,end_index);
                    seconds->print();
                }
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
                            firsts.add_el(temps);
                        }
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
                    cout<<firsts.find_subsequence(temp,size);
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
                            firsts.add_el(temps);
                        }
                    }
                    firsts.map(set_nul);
                    firsts.print();
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
                            firsts.add_el(temps);
                        }
                    }

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
                            firsts.add_el(temps);
                        }
                    }

                }

                    break;
                case 9:
                {
                    Queue<double> second;
                    Queue<double> *third;
                    if(firsts.empty())
                    {
                        cout<<"Заполните дек\nВведите длину: ";
                        int len;
                        cin>>len;
                        cout<<"Введите последоваельность\n";
                        for(int i=0;i<len;i++)
                        {
                            cin>>temps;
                            firsts.add_el(temps);
                        }
                    }
                    int size=0;
                    cout<<"Введите размер последовательности: ";
                    cin>>size;
                    cout<<"Введите последовательность\n";
                    for(int i=0;i<size;i++)
                    {
                        cin>>temps;
                        second.add_el(temps);
                    }
                    second.print();
                    third=firsts.concat(second);
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

            Queue<complex<double>> firsts;
            complex<double> temps;
            int start_index,end_index;
            if(firsts.empty())
            {
                cout<<"Заполните очередь\nВведите длину: ";
                int len;
                cin>>len;
                cout<<"Введите последоваельность\n";
                for(int i=0;i<len;i++)
                {
                    cin>>temps;
                    firsts.add_el(temps);
                }
            }
            while(work!=0)
            {
                cout<<"для добавления элемента введите 1\nДля извлечения максимального элемента введите 2\nДля извлечения минимального элемента введите 3\nДля извлечения одпоследовательности введите 4\nДля поиска подпоследовательности введите 5\nMap-6\nWhere-7\nReduce-8\nConcat-9\n";
                cin>>function;
                switch (function)
                {

                case 1:
                    cout<<"Введите строку: ";
                    cin>>temps;
                    firsts.add_el(temps);
                    firsts.print();
                    break;
                case 2:
                    cout<<firsts.get_max()<<endl;
                    break;
                case 3:
                    cout<<firsts.get_min()<<endl;
                    break;
                case 4:
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
                            firsts.add_el(temps);
                        }
                    }
                    firsts.print();
                    cout<<"Введите начало: ";
                    cin>>start_index;
                    cout<<"Введите конец: ";
                    cin>>end_index;

                    Queue<complex<double>>* seconds=firsts.get_subsequence(start_index,end_index);
                    seconds->print();
                }
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
                            firsts.add_el(temps);
                        }
                    }
                    int size=0;
                    cout<<"Введите размер подпоследовательности: ";
                    cin>>size;
                    complex<double> temp[size];
                    cout<<"Введите подпоследовательность\n";
                    for(int i=0;i<size;i++)
                    {
                        cin>>temp[i];
                    }
                    cout<<firsts.find_subsequence(temp,size);
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
                            firsts.add_el(temps);
                        }
                    }
                    firsts.map(set_nul);
                    firsts.print();
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
                            firsts.add_el(temps);
                        }
                    }

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
                            firsts.add_el(temps);
                        }
                    }

                }

                    break;
                case 9:
                {
                    Queue<complex<double>> second;
                    Queue<complex<double>> *third;
                    if(firsts.empty())
                    {
                        cout<<"Заполните дек\nВведите длину: ";
                        int len;
                        cin>>len;
                        cout<<"Введите последоваельность\n";
                        for(int i=0;i<len;i++)
                        {
                            cin>>temps;
                            firsts.add_el(temps);
                        }
                    }
                    int size=0;
                    cout<<"Введите размер последовательности: ";
                    cin>>size;
                    cout<<"Введите последовательность\n";
                    for(int i=0;i<size;i++)
                    {
                        cin>>temps;
                        second.add_el(temps);
                    }
                    second.print();
                    third=firsts.concat(second);
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
        question=-1;







    }

    return 0;
}
