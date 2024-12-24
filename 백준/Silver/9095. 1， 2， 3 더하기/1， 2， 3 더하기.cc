#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> numbers;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    int Arr[11];
    Arr[0] = 1;
    Arr[1] = 2;
    Arr[2] = 4;

    for (int i = 3; i < 11; i++)
    {
        Arr[i] = Arr[i - 3] + Arr[i - 2] + Arr[i - 1];
    }

    for (int i : numbers)
    {
        cout << Arr[i - 1] << endl;
    }

    return 0;
}