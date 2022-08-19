#include <iostream>
using namespace std;

#define max_int 10000

class deque
{
private:
    int frnt;
    int rear;
    int arr[max_int] = {};
    int length;

public:
    deque()
    {
        frnt = -1;
        rear = -1;
        length = 0;
    }
    deque(int n, int s)
    {
        frnt = 0;
        rear = n - 1;
        for (int i = 0; i < n; i++)
        {
            arr[i] = s;
        }
        length=n;
    }

    void push_back(int);
    void pop_back();
    void push_front(int);
    void pop_front();
    int front();
    int back();
    int operator [](int);
    //int D[n];
    bool empty();
    int size();
    void resize(int, int);
    void clear();
};

int deque::size()
{
    return length;
}

void deque::push_back(int n)
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
    else if(rear != frnt -1)
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
void deque::push_front(int n)
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
    else if(rear != frnt -1)
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

bool deque::empty()
{

    if (frnt == -1)
        return true;
    else
        return false;
}

void deque::pop_back()
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

void deque::pop_front()
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

int deque::front()
{
    if (empty())
        exit;
    else
    {
        return arr[frnt];
    }
}

int deque::back()
{
    if (empty())
        exit;
    else
    {
        return arr[rear];
    }
}

void deque::clear() {
    frnt=-1;
    rear=-1;
    length=0;
}

int deque::operator [](int n) {
    if(n>length)
        exit;
    else if(n==1)
        return arr[frnt];
    else if(n==length)
        return arr[rear];
    else if (frnt<=rear)
    {
        return arr[frnt+n-1];
        
    }
    else if (n>=(max_int-frnt +1))
        return arr[n-max_int+frnt -1];
    else    return arr[n+frnt-1];
}

void deque::resize(int x, int n){
    if(x==length)
    return;
    if(x>length)
        while(length!=x)
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
            else if(rear != frnt -1)
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
        while(length!=x)
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