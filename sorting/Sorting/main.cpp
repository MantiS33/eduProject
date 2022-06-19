//this is cod for learning different sorting
#include <iostream>
using namespace std;


//---bubble sorting---
void bubble(int arr[], int n)
{
    int tmp = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j<(n-1); j++)
        {
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
//-------------------

//---selection sorting---
void selection(int arr[], int n)
{
    int k = 0;
    int tmp = 0;
    for(int i = 0; i < n; i++)
    {
        k = i;
        for(int j = i; j < n; j++)
        {
            if(arr[k]>arr[j])
            {
                k = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[k];
        arr[k] = tmp;
    }
}
//-----------------------

//---insertion sort---
void insertion(int arr[], int n)
{
    int key = 0;
    int i = 0;
    for(int j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;
        while(i>=0 && arr[i]>key)
        {
            arr[i+1] = arr[i];
            i -= 1;
            arr[i+1] = key;
        }
    }
    
}
//--------------------


int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    int n = 10;
    int arr[n], tmpArray[n];
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Array value before sorting: "s;
    
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    
    for(int i = 0; i < n; i++)
    {
        tmpArray[i] = arr[i];
    }
    cout << endl << "Array value after bubble sorting: "s;
    bubble(tmpArray, n);
    for(int i = 0; i < n; i++)
    {
        cout << tmpArray[i] << ' ';
    }
    
    for(int i = 0; i < n; i++)
    {
        tmpArray[i] = arr[i];
    }
    cout << endl << "Array value after selection sorting: "s;
    selection(tmpArray,n);
    for(int i = 0; i < n; i++)
    {
        cout << tmpArray[i] << ' ';
    }
    
    for(int i = 0; i < n; i++)
    {
        tmpArray[i] = arr[i];
    }
    cout << endl << "Array value after insertion sorting: "s;
    insertion(tmpArray, n);
    for(int i = 0; i < n; i++)
    {
        cout << tmpArray[i] << ' ';
    }
    
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
