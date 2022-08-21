#include <iostream>
using namespace std;

// #define max_int 10000
long long int max_int = 100;

template <class temp>
class deque
{

    int frnt;
    int rear;
    temp *arr;
    int length;

public:
    deque()
    {
        arr = new int[max_int]{};
        frnt = -1;
        rear = -1;
        length = 0;
    }
    deque(int n, temp s)
    {
        if (n > max_int)
        {
            arr = new int[2 * n];
            max_int = 2 * n;
        }
        frnt = 0;
        rear = n - 1;
        for (int i = 0; i < n; i++)
        {
            arr[i] = s;
        }
        length = n;
    }

    void push_back(temp); ///checked
    void pop_back(); //checked
    void push_front(temp);//checked
    void pop_front();//checked
    int front();//checked
    int back();//checked
    int operator[](int);//checked
    
    bool empty();//checked
    bool full();//checked
    int size();//checked
    void resize(int, temp);//checked
    void clear();//checked
    void display();//checked
};
// template <class temp>
// void deque<temp>::update_array(temp *a, int m)
// {
//     temp *arr = new temp(m);
//     delete [] a;
//     a = arr;
// }

template <class temp>
int deque<temp>::size()
{
    return length;
}
template <class temp>
bool deque<temp>::full()
{
    if ((frnt == 0 && rear == length - 1) || frnt == rear + 1)
        return true;
    else
        return false;
}
template <class temp>
void deque<temp>::push_back(temp n)
{
    if (full())
    {
        exit;
    }
    if (rear == -1)
    {
        // cout<<rear<<frnt<<endl;
        rear = 0;
        frnt = 0;
    }
    else if (rear == max_int - 1)
    {
        rear = 0;
    }
    else
        rear++;

    arr[rear] = n;

    length++;
}

template <class temp>
void deque<temp>::display()
{
    if (frnt == -1 && rear == -1)
    {
        cout << "empty" << endl;
    }
    else if (frnt <= rear)
    {
        int i = frnt;
        while (i <= rear)
        {
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }
    else
    {
        int i = frnt;
        while (i > rear)
        {

            cout << arr[i] << " ";
            if (i != max_int - 1)
                i++;
            else
                i = 0;
        }
        while (i <= rear)
        {
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }
}

template <class temp>
void deque<temp>::push_front(temp n)
{
    if (full())
    {
        exit;
    }

    if (frnt == -1)
    {
        frnt = rear = 0;
    }
    else if (frnt == 0)
    {
        frnt = max_int - 1;
    }
    else
        frnt--;

    arr[frnt] = n;
    length++;
}

template <class temp>
bool deque<temp>::empty()
{

    if (frnt == -1)
        return true;
    else
        return false;
}

template <class temp>
void deque<temp>::pop_back()
{
    if (empty())
        return;

    if (frnt == rear)
    {
        rear = -1;
        frnt = -1;
    }

    else if (rear == 0)
        rear = max_int - 1;
    else
        rear -= 1;

    length--;
}

template <class temp>
void deque<temp>::pop_front()
{
    if (empty())
        return;

    if (frnt == rear)
    {
        frnt = -1;
        rear = -1;
    }

    else if (frnt == max_int - 1)
    {
        frnt = 0;
    }
    else
    {
        frnt++;
    }

    length--;
}

template <class temp>
int deque<temp>::front()
{
    // if (empty())
    //     cout<<"empty"<<endl;
    // else
    // {
    return arr[frnt];
    //}
}

template <class temp>
int deque<temp>::back()
{
    if (empty())
        exit;
    else
    {
        return arr[rear];
    }
}

template <class temp>
void deque<temp>::clear()
{
    frnt = -1;
    rear = -1;
    length = 0;
}

template <class temp>
int deque<temp>::operator[](int n)
{
    if (n > length || n == 0 )
        return -1;
    else if (n == 1)
        return arr[frnt];
    else if (n == length)
        return arr[rear];
    else if (frnt <= rear)
    {
        return arr[frnt + n - 1];
    }
    else if (n >= (max_int - frnt + 1))
        return arr[n - max_int + frnt - 1];
    else
        return arr[n + frnt - 1];
}

template <class temp>
void deque<temp>::resize(int x, temp n)
{
    if (x == length)
        return;
    if (x > length)
        while (length != x)
        {
            if (rear == max_int - 1)
            {
                if (frnt != 0)
                {
                    rear = 0;
                    arr[rear] = n;
                }
                else
                {
                    return;
                }
            }
            else if (rear != frnt - 1)
            {
                rear++;
                arr[rear] = n;
            }
            else
            {
                return;
            }

            length++;
        }
    else
    {    while (length != x)
        {
            if (empty())
                return;

            if (frnt == rear)
            {
                rear = -1;
                frnt = -1;
            }

            if (rear == 0)
                rear = max_int - 1;
            else
                rear -= 1;

            length--;
        }
        if (frnt <= rear)
        {
            int i = frnt;
            while (i <= rear)
            {
                arr[i]=n;
                i++;
            }
            
        }
        else
        {
            int i = frnt;
            while (i > rear)
            {

                arr[i]=n;
                if (i != max_int - 1)
                    i++;
                else
                    i = 0;
            }
            while (i <= rear)
            {
                arr[i]=n;
                i++;
            }
            
        }
    }
}

int main()
{
    int n;
    // cout<<"Select 1 for push_back"<<endl;
    // cout<<"Select 2 for push_front"<<endl;
    // cout<<"Select 3 for pop_back"<<endl;
    // cout<<"Select 4 for pop_front"<<endl;
    // cout<<"Select 5 to resize deque"<<endl;
    // cout<<"Select 6 for push_back"<<endl;
    // cout<<"Select 7 for push_back"<<endl;
    // cout<<"Select 8 for push_back"<<endl;

    deque<int> dq;
    int m = 1;

    dq.push_front(m);
    dq.push_front(m + 1);
    dq.push_front(m + 2);
    
    // dq.push_back(m);
    // dq.push_back(m + 1);
    // dq.push_back(m + 2);
    
    dq.clear();
    dq.display();
}