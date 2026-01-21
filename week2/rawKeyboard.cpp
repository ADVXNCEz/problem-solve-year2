#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

int main()
{  
    string str;
    while (getline(cin, str))
    {
        list<char> nub;
        list<char>::iterator iter(nub.begin());
        for (size_t i = 0; i < str.size(); ++i)
        {
            if (str[i] == '[')iter = nub.begin();
            else if (str[i] == ']')iter = nub.end();
            else nub.insert(iter, str[i]);                
        }
        copy(nub.begin(), nub.end(), ostream_iterator<char>(cout, ""));
        cout << endl;
    }
    return 0;
}