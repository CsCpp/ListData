#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List {                            //Класс СПИСОК
public:
    List();
    ~List();
    void insert(T value, int index);    //добовление элемента по индексу
    void removeAt(int index);           //удаление элемента по индексу
    void pop_front();                   //удалить первый элемент в списке
    void push_back(T data);             //добавить данные в конец списка
    void clear();                       //очистить список
    int GetSize()                       //отдает количество элементов
    {
        return Size;
    };
    void push_front(T data);
    T& operator[](const int index);     //перезагрузка оператора []


private:
    template<typename T>
    class Node {                        // класс с данными
    public:
        Node* pNext;                    //указатель на следующие данные в списке
        T data;                         //данные
        Node(T data=T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;                           //количество элементов в списке
    Node<T> *head;                      //указатель на первый 
};

template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++) 
        {
            previous = previous->pNext;
        }
        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        //  previous->pNext = new Node<T>(value, previous->pNext);
        delete toDelete;
        Size--;
    }

}

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    cout << "Вызвался деструктор "<< endl;
    clear();
}

template<typename T>
void List <T>::insert(T value, int index)
{
    if (index == 0) 
    {
        push_front(value);
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node<T>* newNode = new Node<T>(value, previous->pNext);
        previous->pNext = newNode;
        //  previous->pNext = new Node<T>(value, previous->pNext);
        Size++;

    }


}


template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;       //указатель temp хранит адрес первого элемента 
    head = head->pNext;         //указатель head хранит адрес второго элемента 
    delete temp;                //удаляем данные по адресу указателя temp 
    Size--;
}

template<typename T>
void List<T>::clear() 
{
    while (Size) pop_front();
}
template<typename T>
void List<T>::push_front(T data) 
{
    head = new Node<T>(data, head);
    Size++;
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
        Node<T>* current = this->head; // временный указатель на текущий адрес в списке
        while (current->pNext != nullptr) 
        {
            current=current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;                //текущая позиция в списке
    Node<T>* current = this->head;  // временный указатель на текущий адрес в списке
    while (current != nullptr) 
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;

    }
    
   }



int main()
{
    setlocale(LC_ALL, "ru");


    List<int>lst;
 
    lst.push_front(34);
    lst.push_front(12);
    lst.push_front(32);
    lst.push_front(75);
    lst.push_front(125);

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
       
    }
    cout << endl << endl<< "_________ removeAt _________" << endl << endl << endl;
    lst.removeAt(12);

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;

    }

    return 0;
}

