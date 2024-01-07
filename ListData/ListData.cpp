#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List {
public:
    List();
    ~List();
    void push_back(T data);
    int GetSize() 
    {
        return Size;
    };


private:
    template<typename T>
    class Node {
    public:
        Node* pNext;
        T data;
        Node(T data=T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head;
};
template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}
template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr) 
    {
        head = new Node<T>(data);
    }
    else 
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr) 
        {
            current=current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}



int main()
{
    setlocale(LC_ALL, "ru");


    List<int>lst;
    cout << lst.GetSize() << endl;
    lst.push_back(5);
    cout << lst.GetSize() << endl;
    lst.push_back(4);
    cout << lst.GetSize() << endl;
    lst.push_back(56);
    cout << lst.GetSize() << endl;



    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

