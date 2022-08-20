#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

void swap_func(string *x, string *y)
{
    string *temp = x;
    x = y;
    y = temp;
}

string multiplication(string x, string y)
{

    int len_x = x.length();
    int len_y = y.length();

    int index_x = 0;
    int index_y = 0;

    if (len_x == 0 || len_y == 0)
        return "";

    int arr[len_x + len_y] = {};

    for (int i = len_x - 1; i >= 0; i--)
    {
        int carry = 0;
        index_y = 0;
        int n = x[i] - '0';
        for (int j = len_y - 1; j >= 0; j--)
        {
            int m = y[j] - '0';

            int sum = (n * m) + arr[index_x + index_y] + carry;

            arr[index_y + index_x] = sum % 10;

            carry = sum / 10;

            index_y++;
        }
        if (carry > 0)
        {
            arr[index_x + index_y] += carry;
        }
        index_x++;
    }

    int i = len_x + len_y - 1;

    while (arr[i] == 0)
        i--;

    if (i == -1)
        return "";

    string s = "";
    while (i >= 0)
    {
        s += to_string(arr[i]);
        i--;
    }
    return s;
}

string addition(string x, string y)
{

    int len_x = x.length();
    int len_y = y.length();

    if (len_x == 0 && len_y == 0)
    {
        return "";
    }
    else if (len_x == 0)
        return y;
    else if (len_y == 0)
        return x;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    int arr[len_x + len_y] = {};

    if (len_x <= len_y)
    {
        int carry = 0;
        for (int i = 0; i < len_x; i++)
        {
            int n = x[i] - '0';
            int m = y[i] - '0';
            int sum = n + m + carry;
            carry = sum / 10;
            arr[i] = sum % 10;
        }
        for (int i = len_x; i < len_y; i++)
        {
            int m = y[i] - '0';
            int sum = m + carry;
            carry = sum / 10;
            arr[i] = sum % 10;
        }
        if (carry > 0)
        {
            int ii = len_y;
            while (carry > 0)
            {
                arr[ii] = carry % 10;
                carry = carry / 10;
            }
        }
    }
    else
    {
        int carry = 0;
        for (int i = 0; i < len_y; i++)
        {
            int n = x[i] - '0';
            int m = y[i] - '0';
            int sum = n + m + carry;
            carry = sum / 10;
            arr[i] = sum % 10;
        }
        for (int i = len_y; i < len_x; i++)
        {
            int m = y[i] - '0';
            int sum = m + carry;
            carry = sum / 10;
            arr[i] = sum % 10;
        }
        if (carry > 0)
        {
            int ii = len_x;
            while (carry > 0)
            {
                arr[ii] = carry % 10;
                carry = carry / 10;
            }
        }
    }

    int i = len_x + len_y - 1;

    while (arr[i] == 0)
        i--;

    if (i == -1)
        return "";

    string s = "";
    while (i >= 0)
    {
        s += to_string(arr[i]);
        i--;
    }
    return s;
}

string substraction(string x, string y)
{
    int len_x = x.length();
    int len_y = y.length();

    if (len_x == 0 && len_y == 0)
    {
        return "";
    }
    else if (len_x == 0)
        return y;
    else if (len_y == 0)
        return x;

    int arr[len_x + len_y] = {};

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    if (len_x >= len_y)
    {
        if (len_x == len_y)
        {
            int a = stoi(x);
            int b = stoi(y);
            if (b > a)
            {
                swap_func(&x, &y);
            }
        }
        int borrow = 0;
        for (int i = 0; i < len_y; i++)
        {
            int n = x[i] - '0';
            int m = y[i] - '0';
            int sum = n - m - borrow;

            if (sum < 0)
            {
                sum = sum + 10;
                borrow = 1;
            }
            else
                borrow = 0;

            arr[i] = sum;
        }
        for (int i = len_y; i < len_x; i++)
        {
            int m = x[i] - '0';
            int sum = m - borrow;
            if (sum < 0)
            {
                sum = sum + 10;
                borrow = 1;
            }
            else
                borrow = 0;

            arr[i] = sum;
        }
    }
    else
    {
        int borrow = 0;
        for (int i = 0; i < len_x; i++)
        {
            int n = x[i] - '0';
            int m = y[i] - '0';
            int sum = m - n - borrow;

            if (sum < 0)
            {
                sum = sum + 10;
                borrow = 1;
            }
            else
                borrow = 0;

            arr[i] = sum;
        }
        for (int i = len_x; i < len_y; i++)
        {
            int m = y[i] - '0';
            int sum = m - borrow;
            if (sum < 0)
            {
                sum = sum + 10;
                borrow = 1;
            }
            else
                borrow = 0;

            arr[i] = sum;
        }
    }

    int i = len_x + len_y - 1;

    while (arr[i] == 0)
        i--;

    if (i == -1)
        return "";

    string s = "";
    while (i >= 0)
    {
        s += to_string(arr[i]);
        i--;
    }
    return s;
}

string arth_operation(string s)
{

    int n = s.length();
    int j = 0;
    int i = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+' || s[i] == '*' || s[i] == '-')
            cnt++;
    }

    while (i < n && cnt > 0)
    {

        if (s[i] == '+' || s[i] == '*' || s[i] == '-')
        {
            if (s[i] == '*')
            {
                int n1 = i - j;
                string s1 = s.substr(j, n1);
                int k = i + 1;
                while (s[k] != '+' && s[k] != '-' && s[k] != '*' && k < n)
                {
                    k++;
                }
                n1 = k - i - 1;
                string s2 = s.substr(i + 1, n1);
                string ans = multiplication(s1, s2);

                string s3 = s.substr(0, j);
                n1 = n - k + 1;
                string s4 = s.substr(k, n1);

                s = s3 + ans + s4;

                j = i + 1;
                n = s.length();
                i = 0;
                cnt--;
                j = 0;
            }
            else
            {
                j = i + 1;
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    i = 0;
    j = 0;
    while (i < n && cnt > 0)
    {

        if (s[i] == '+' || s[i] == '-')
        {
            int f;
            if (s[i] == '+')
                f = 1;
            if (s[i] == '-')
                f = 2;
            int n1 = i - j;
            string s1 = s.substr(j, n1);
            int k = i + 1;
            while (s[k] != '+' && s[k] != '-' && k < n)
            {
                k++;
            }
            n1 = k - i - 1;
            string s2 = s.substr(i + 1, n1);
            string ans;
            if (f == 1)
            {
                ans = addition(s1, s2);
            }
            else
            {
                ans = substraction(s1, s2);
            }

            string s3 = s.substr(0, j);
            n1 = n - k + 1;
            string s4 = s.substr(k, n1);

            s = s3 + ans + s4;
            j = i + 1;
            n = s.length();
            i = 0;
            j = 0;
            cnt--;
        }
        else
        {
            i++;
        }
    }
    return s;
}

string exponentiation(string s1, string s2)
{
    int power = stoi(s2);
    string s = multiplication(s1, s1);
    power -= 2;
    while (power--)
    {
        s = multiplication(s, s1);
    }
    return s;
}

string gcd(string s1, string s2)
{
    if (stoi(s1) == 0)
        return s2;
    if (stoi(s2) == 0)
        return s1;
    if (stoi(s2) == stoi(s1))
    {
        return s1;
    }
    if (stoi(s1) > stoi(s2))
        return gcd(substraction(s1, s2), s2);
    return gcd(s1, substraction(s2, s1));
}

string fact(string s)
{
    string s1="1";
    if(s=="1") return s;
    else
        return multiplication(s,fact(substraction(s,s1)));

}

int main()
{
    int n;
    cin >> n;
    string s1, s2, s;
    switch (n)
    {
    case 1:

        cin >> s1;
        cout << arth_operation(s1) << endl;
        ;
        /* code */
        break;

    case 2:
        cin >> s1;
        cin >> s2;
        cout << exponentiation(s1, s2) << endl;
        ;
        break;

    case 3:
        cin >> s1;
        cin >> s2;
        cout << gcd(s1, s2) << endl;
        break;

    case 4:
        cin >> s1;
        cout<<fact(s1)<<endl;
        break;

        // case 5:
        //     cin >> s1;
        //     cin >> s2;
        //     s = substraction(s1, s2);
        //     cout << s << endl;
        //     break;

    default:
        break;
    }
}