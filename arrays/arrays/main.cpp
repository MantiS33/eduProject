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
    List();
    
    //деструктор
    ~List();
    
    //добавление элемента
    void add(T addData);
    
    //показать все элементы
    void show();
    
    //вывод количества элементов
    int getCount();
    
    //вставить на определенную позицию
    void insert(unsigned int pos, T addData);
    
    //удалить по значению
    void removeByValue(T value);
    
    //удалить по номеру позиции
    void removeByCount(unsigned int pos);
    
    //удалить голову списка
    void removeHead();
    
    //удалить конец списка
    void removeTail();
    
    //удалить весь список
    void clear();
    
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
List<T>::List()
{
    head = NULL;
    tail = NULL;
    tmp = NULL;
    count = 0;
}

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
int List<T>::getCount()
{
    return count;
}

//вставить в определенную позицию
template<class T>
void List<T>::insert(unsigned int pos, T addData)
{
    node *tmpInsert = new node;
    tmpInsert->data = addData;
    tmp = head;
    int counter = 1;
    while(tmp != NULL)
    {
        if(pos == counter && tmp == head)
        {
            tmpInsert->prev = NULL;
            tmpInsert->next = head;
            head->prev = tmpInsert;
            count += 1;
            return;
        }
        else if(pos >= counter && tmp == tail)
        {
            tmpInsert->prev = tail;
            tmpInsert->next = NULL;
            tail->next = tmpInsert;
            count += 1;
            return;
        }
        else if(pos == counter && (tmp != head || tmp != tail))
        {
            tmpInsert->prev = tmp->prev;
            tmpInsert->next = tmp->next;
            tmp->prev->next = tmpInsert;
            tmp->next->prev = tmpInsert;
            count += 1;
            return;
        }
        tmp = tmp->next;
    }
}

//удалить по значению
template<class T>
void List<T>::removeByValue(T value)
{
    
}

//удалить по позиции
template<class T>
void List<T>::removeByCount(unsigned int pos)
{
    
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
    }
    else
    {
        tmp = head;
        head = head->next;
        head->prev = NULL;
        delete tmp;
        tmp = NULL;
        count -= 1;
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
    }
    else
    {
        tmp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete tmp;
        count -= 1;
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
    listArray.insert(2, 666);
    cout << "count: "s << listArray.getCount() << endl << "list"s << endl << listArray << endl;
    return 0;
}
