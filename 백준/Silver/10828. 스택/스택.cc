#include <iostream>
#include <cstring>

using namespace std;

void push(int* numArray, int newNum);
int pop(int* numArray);
int size(int* numArray);
bool empty(int* numArray);
int top(int* numArray);

int main()
{
    int count, newNum;
    int* numArray;
    char* order;

    cin >> count;

    numArray = new int[10000]{ 0 };
    order = new char[6];

    for (int i = 0; i < count; i++)
    {
        cin >> order;
        if (!strcmp(order, "push"))
        {
            cin >> newNum;
            push(numArray, newNum);
        }
        else if (!strcmp(order, "pop"))
            cout << pop(numArray) << endl;
        else if (!strcmp(order, "size"))
            cout << size(numArray) << endl;
        else if (!strcmp(order, "empty"))
            cout << empty(numArray) << endl;
        else if (!strcmp(order, "top"))
            cout << top(numArray) << endl;
        else
            cout << "input error" << endl;
    }

    return 0;
}

void push(int* numArray, int newNum)
{
    int index;
    index = size(numArray);
    numArray[index] = newNum;
}

int pop(int* numArray)
{
    int index, result;
    index = size(numArray);
    if (index == 0) return -1;
    result = numArray[index - 1];
    numArray[index - 1] = 0;
    return result;
}

int size(int* numArray)
{
    int i = 0;
    while (numArray[i] != 0)
        i++;
    return i;
}

bool empty(int* numArray)
{
    int index;
    index = size(numArray);
    if (index == 0) return 1;
    return 0;
}

int top(int* numArray)
{
    int index;
    index = size(numArray);
    if (index == 0) return -1;
    return numArray[index - 1];
}
