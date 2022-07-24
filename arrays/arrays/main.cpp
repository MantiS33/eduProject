/*
 *
 *реализация двухсвязного шаблонного списка
 *с перегрузкой операторов ввода/вывода
 *
 */

#include <iostream>
using namespace std;

template<class T>
class List
{
private:
    struct node
    {
        T data;
        node *next;
        node *prev;
    };
    unsigned int count;
    node *head, *tail, *tmp;
public:
    //конструктор по умолчанию
    explicit List();
    
    //конструкток копирования
    
    
    //деструктор
    ~List();
    
    //добавление элемента
    void add(T addData);
    
    //показать все элементы
    void show();
    
    //вывод количества элементов
    int getCount() const;
    
    //вставить на определенную позицию
    void insert(unsigned int i, T addData);
    
    //удалить по значению
    void removeByValue(T value);
    
    //удалить по номеру позиции
    void removeByCount(unsigned int i);
    
    //удалить голову списка
    void removeHead();
    
    //удалить конец списка
    void removeTail();
    
    //удалить весь список
    void clear();
    
    //получения элемента по его порядку в списке
    T& getItem(uint i);
    
    //перегрузка оператора []
    T& operator [](uint i);
    
    //перегрузка вывода
    friend ostream &operator<<(ostream &out, List &elem)
    {
        elem.tmp = elem.head;
        while(elem.tmp != NULL)
        {
            out << elem.tmp->data << "\n";
            elem.tmp = elem.tmp->next;
        }
        return out;
    }
    
    //перегрузка ввода
    friend istream &operator>>(istream &in, List &elem)
    {
        elem.tmp = new node;
        elem.tmp->next = NULL;
        in >> elem.tmp->data;
                
        if(elem.head != NULL)
        {
            elem.tail->next = elem.tmp;
            elem.tmp->prev = elem.tail;
            elem.tail = elem.tmp;
            elem.count += 1;
        }
        else
        {
            elem.tmp->prev = NULL;
            elem.head = elem.tail = elem.tmp;
            elem.count += 1;
        }
        return in;
    }
    
};


//конструктор по умолчанию
template<class T>
List<T>::List(): head(NULL), tail(NULL), tmp(NULL), count(0) {}

//деструктор
template<class T>
List<T>::~List()
{
    clear();
}

//добваление элемента, добавляется в конец
template<class T>
void List<T>::add(T addData)
{
    
    tmp = new node;
    tmp->data = addData;
    tmp->next = NULL;
    
    if(head != NULL)
    {
        
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
        count += 1;
    }
    else
    {
        
        tmp->prev = NULL;
        head = tail = tmp;
        count += 1;
    }
}

//вывести все элементы
template<class T>
void List<T>::show()
{
    
    tmp = head;
    while(tmp != NULL)
    {
        
        cout << tmp->data << endl;
        tmp=tmp->next;
    }
}

//вывести количество элементов в списке
template<class T>
int List<T>::getCount() const
{
    return count;
}

//вставить в определенную позицию
template<class T>
void List<T>::insert(unsigned int i, T addData)
{
    if(i >= count)
    {
        this->add(addData);
        return;
    }
    
    unsigned int currentPosition = 0;
    node *tmpInsert = new node;
    tmpInsert->data = addData;
    tmp = head;
    
    while(tmp != NULL)
    {
        if(currentPosition == i || currentPosition == count)
        {
            if(tmp == head)
            {
                tmpInsert->next = tmp;
                tmp->prev = tmpInsert;
                head = tmpInsert;
                count += 1;
                return;
            }
            else
            {
                tmpInsert->prev = tmp->prev;
                tmpInsert->next = tmp;
                tmp->prev->next = tmpInsert;
                tmp->prev = tmpInsert;
                count += 1;
                return;
            }
        }
        tmp = tmp->next;
        currentPosition += 1;
    }
}

//удалить по значению
template<class T>
void List<T>::removeByValue(T value)
{
    tmp = head;
    while(tmp != NULL)
    {
        if(tmp->data == value)
        {
            if(tmp == head)
            {
                this->removeHead();
                return;
            }
            else if (tmp == tail)
            {
                this->removeTail();
                return;
            }
            else
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                count -= 1;
                return;
            }
        }
        tmp = tmp->next;
    }
    
}

//удалить по позиции
template<class T>
void List<T>::removeByCount(unsigned int i)
{
    unsigned int currentPosition = 0;
    tmp = head;
    if(i >= count)
    {
        return;
    }
    while(tmp != NULL)
    {
        if(currentPosition == i)
        {
            if(tmp == head)
            {
                this->removeHead();
                return;
            }
            else if(tmp == tail)
            {
                this->removeTail();
                return;
            }
            else
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                count -= 1;
                return;
            }
        }
        tmp = tmp->next;
        currentPosition += 1;
    }
}

//удалить голову
template<class T>
void List<T>::removeHead()
{
    if(head == tail)
    {
        tail = NULL;
        delete head;
        count = 0;
        return;
    }
    else
    {
        tmp = head;
        head = head->next;
        head->prev = NULL;
        delete tmp;
        tmp = NULL;
        count -= 1;
        return;
    }
}

//удалить конец
template<class T>
void List<T>:: removeTail()
{
    if(head == tail)
    {
        tail = NULL;
        delete head;
        count = 0;
        return;
    }
    else
    {
        tmp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete tmp;
        count -= 1;
        return;
    }
}

//очистить список
template<class T>
void List<T>::clear()
{
    if(head != NULL)
    {
        if(head == tail)
        {
            tail = NULL;
            delete head;
        }
        else
        {
            tmp = head;
            while(tmp != NULL)
            {
                head = head->next;
                delete tmp;
                tmp = head;
            }
        }
    }
}

//функция получения элемента по его порядковому номеру в списке
template<class T>
T& List<T>::getItem(uint i)
{
    uint curretPosition = 0;
    tmp = head;
    
    
    while(tmp != NULL)
    {
        if(curretPosition == i)
        {
            return tmp->data;
        }
        else if(curretPosition > i || i > count)
        {
            return tail->data;
        }
        tmp = tmp->next;
        curretPosition += 1;
    }
    return head->data;
}

//перегрузка оператора []
template <class T>
T& List<T>::operator[](uint i)
{
    return this->getItem(i);
}


int main(int argc, const char * argv[])
{
    List<int> listArray;
    listArray.add(10);
    listArray.add(30);
    listArray.add(40);
    
    cin >> listArray;
    cout << "list:"s << endl << listArray << endl;
    listArray.show();
    cout << endl;
    cout << "count: "s << listArray.getCount() << endl;
    listArray.removeHead();
    cout << "count: "s << listArray.getCount() << endl << "list"s << endl << listArray << endl;
    listArray.removeTail();
    cout << "count: "s << listArray.getCount() << endl << "list"s << endl << listArray << endl;
    listArray.add(20);
    cout << "count: "s << listArray.getCount() << endl << "list"s << endl << listArray << endl;
    listArray.insert(2, 666);
    
    listArray.add(20);
    cout << "count: "s << listArray.getCount() << endl << "list"s << endl << listArray << endl;
    cout << listArray.getItem(2) << endl;
    cout << listArray[3] << endl;
    cout << "count: "s << listArray.getCount() << endl << "list"s << endl << listArray << endl;
    listArray.removeByCount(2);
    cout << "count: "s << listArray.getCount() << endl << "list"s << endl << listArray << endl;
    listArray.removeByValue(20);
    cout << "count: "s << listArray.getCount() << endl << "list"s << endl << listArray << endl;
    return 0;
}
