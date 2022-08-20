#include <iostream>
using namespace std;

#define max_int 10000

template <class temp>
class deque
{
private:
    int frnt;
    int rear;
    temp arr[max_int] = {};
    int length;

public:
    deque()
    {
        frnt = -1;
        rear = -1;
        length = 0;
    }
    deque(int n, temp s)
    {
        frnt = 0;
        rear = n - 1;
        for (int i = 0; i < n; i++)
        {
            arr[i] = s;
        }
        length = n;
    }

    void push_back(temp);
    void pop_back();
    void push_front(temp);
    void pop_front();
    int front();
    int back();
    int operator[](temp);
    // int D[n];
    bool empty();
    int size();
    void resize(int, temp);
    void clear();
};
template <class temp>
int deque<temp>::size()
{
    return length;
}

template <class temp>
void deque<temp>::push_back(temp n)
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

template <class temp>
void deque<temp>::push_front(temp n)
{
    if (frnt == 0)
    {
        if (rear != max_int - 1)
        {
            frnt = max_int - 1;
            arr[frnt] = n;
        }
        else
        {
            return;
        }
    }
    else if (rear != frnt - 1)
    {
        frnt--;
        arr[rear] = n;
    }
    else
    {
        return;
    }

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

    if (rear == 0)
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

    if (frnt == max_int - 1)
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
    if (empty())
        exit;
    else
    {
        return arr[frnt];
    }
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
int deque<temp>::operator[](temp n)
{
    if (n > length)
        exit;
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
        while (length != x)
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
}