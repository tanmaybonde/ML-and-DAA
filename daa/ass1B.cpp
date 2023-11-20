#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct item
{
    int weight, profit;
    item()
    {
        weight = 0;
        profit = 0;
    }

    item(int a, int b)
    {
        weight = a;
        profit = b;
    }
};

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
    }
    cout << "--------------------------------------------" << endl;
}

void sort(item arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].weight > arr[j].weight)
            {
                item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void zeroknaosack(item arr[], int n, int capacity)
{
    input(arr, n);
    sort(arr, n);
    int knaparr[n + 1][capacity + 1];
    // for (int i = 0; i < capacity + 1; i++)
    // {
    //     knaparr[0][i] = 0;
    // }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     knaparr[i][0] = 0;
    // }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                knaparr[i][j] = 0;
            }
            // actual array is startingq
            else
            {
                if (j < arr[i - 1].weight)
                {
                    knaparr[i][j] = knaparr[i - 1][j];
                }
                else
                {
                    int x = knaparr[i - 1][j - arr[i - 1].weight];
                    knaparr[i][j] = max(knaparr[i - 1][j], (arr[i - 1].profit + x));
                }
            }
        }
    }
    cout << endl;
    cout << "Maximum Profit:" << knaparr[n][capacity] << endl;
    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << endl;
    cout << "Selected element are:-" << endl;
    cout << endl;
    cout << "Weight"
         << "      "
         << "Profit" << endl;
    int i = n;
    int j = capacity;
    while (i != 0)
    {
        if (knaparr[i][j] == knaparr[i - 1][j])
        {
            i = i - 1;
        }
        else
        {
            cout << arr[i - 1].weight << "           " << arr[i - 1].profit << endl;
            j = j - arr[i - 1].weight;
            i = i - 1;
        }
    }
    cout << endl;
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
    item arr[n];
    zeroknaosack(arr, n, capacity);
    return 0;
}