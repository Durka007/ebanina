#include <iostream>
#include <fstream>


using namespace std;
template<class t>
class op {
    t arr;
    op* next;
public:
    void open(op*& head, op*& end,t arr)
    {
        op* tmp = new op;
         tmp->arr =arr;
        tmp->next = head;
        if (head == NULL)
        {
            end = tmp;
            head = tmp;
        }
        else
        {
            head = tmp;
        }
    }
    void output(op* head, op* end)
    {
        op* p = head;
        do {
            cout << p->arr << endl;
            p = p->next;
        } while (p != end->next);
        cout << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    op<int> t1;
    op<string> t2;
    op<int>* head = NULL, *end = NULL;
    op<string>* head1 = NULL, * end1 = NULL;
    ifstream file("Text.txt");
    if (!file)
    {
        cout << "File not found\n";
        return 1;
    }

    string str;
    int a = 0;
    while (a != 4)
    {
        cout << "1.Запись" << endl;
        cout << "2.Вывод цифр" << endl;
        cout << "3.Вывод строк." << endl;
        cout << "4.Выход." << endl;
        cout << "Ваш выбор : "; cin >> a;
        system("cls");
        switch (a)
        {
        case 1: {
            file >> str;
            if (atoi(str.c_str()) > 0)
            {
                t1.open(head, end, atoi(str.c_str()));
            }
            else
            {
                t2.open(head1, end1, str);
            }
            break;

            }
        case 2: {
            t1.output(head, end);
            break;
            }
        case 3: {
            t2.output(head1, end1);
            break;
            }
        }
    }
    return 0;
}


