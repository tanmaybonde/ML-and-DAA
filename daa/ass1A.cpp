#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct item
{
    float weight, profit, ratio;
    item()
    {
        weight = 0;
        profit = 0;
        ratio = 0;
    }
    item(float a, float b)
    {
        weight = a;
        profit = b;
        ratio = profit / weight;
    }
};

struct item1
{
    float sweight, sprofit, rem_capacity, t_profit;
    item1()
    {
        sweight = 0;
        sprofit = 0;
        rem_capacity = 0;
        t_profit = 0;
    }
};

void sort(item arr[], int n)
{
    item temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].ratio < arr[j].ratio)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void display(item1 arr1[], int n)
{

    cout << "s-weight"
         << "  "
         << "s-profit"
         << "  "
         << "rem-capacity"
         << "   "
         << "t-profit" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "   " << arr1[i].sweight << "      "
             << "   " << arr1[i].sprofit << "     "
             << "     " << arr1[i].rem_capacity << "     "
             << "     " << arr1[i].t_profit << "   " << endl;
    }
    cout << endl;
    cout << "--------------------------------------------" << endl;
}

void input(item arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool a = true;
        while (a)
        {
            cout << endl
                 << "Enter weight of " << i + 1 << "th element:" << endl;
            cin >> arr[i].weight;
            if (arr[i].weight < 0)
            {
                cout << "You have Entered negative Value." << endl;
            }
            else
            {
                a = false;
            }
        }

        a = true;
        while (a)
        {
            cout << endl
                 << "Enter profit of " << i + 1 << "th element:" << endl;
            cin >> arr[i].profit;
            if (arr[i].profit < 0)
            {
                cout << "You have Entered negative Value." << endl;
            }
            else
            {
                a = false;
            }
        }
        arr[i].ratio = arr[i].profit / arr[i].weight;
    }
    cout << "--------------------------------------------" << endl;
}

void knapsack(item arr[], item1 arr1[], int n, int capacity)
{
    float sum = 0;
    item1 temp;
    input(arr, n);
    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight < capacity)
        {
            temp.sweight = arr[i].weight;
            temp.sprofit = arr[i].profit;
            sum = sum + arr[i].profit;
            capacity = capacity - arr[i].weight;
            temp.rem_capacity = capacity;
            temp.t_profit = sum;
            arr1[i] = temp;
        }
        else
        {
            temp.sweight = capacity;
            temp.sprofit = (capacity / arr[i].weight) * arr[i].profit;
            capacity = 0;
            sum = sum + temp.sprofit;
            temp.rem_capacity = capacity;
            temp.t_profit = sum;
            arr1[i] = temp;
            n = i + 1;
            break;
        }
    }

    display(arr1, n);
}

int main()
{
    int capacity, n;
    bool a = true;
    while (a)
    {
        cout << endl
             << "Enter capacity of  bag:" << endl;
        cin >> capacity;
        if (capacity < 0)
        {
            cout << "You have Entered negative Value." << endl;
        }
        else
        {
            a = false;
        }
    }
    a = true;
    while (a)
    {
        cout << endl
             << "Enter Number of element:" << endl;
        cin >> n;
        if (n < 0)
        {
            cout << "You have Entered negative Value." << endl;
        }
        else
        {
            a = false;
        }
    }

    cout << "------------------------------------------" << endl;
    item1 arr1[n];
    item arr[n];
    knapsack(arr, arr1, n, capacity);
    return 0;
}