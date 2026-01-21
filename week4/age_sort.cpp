#include <iostream>
using namespace std;

const int Max = 100;
const int Min = 1;

int nub[105];

int main()
{
    int N;
    while (cin >> N, N)
    {
        int age;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> age;
            ++nub[age];
        }
        
        string sep = "";
        for (int i = Min; i <= Max; ++i)
        {

            ++nub[i];
            
            while (--nub[i])
            {
                cout << sep << i;
                sep = " ";
            }
        }
        
        cout << '\n';
    }
}