#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;

void read_input()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    int xx;
    cin >> xx;
    x.push_back(xx);
  }
}

int find_max_index(vector<int>& x, int n)
{
  // TODO: return the index of the maximum element in x[0], x[1],... x[n-1]
  //       don't use any loop control structures
    if(n == 1) {
        return 0;
    }
    auto first = x.begin();
    auto second = x.begin() + 1;
    if(*first > *second) {
        x.erase(second);
    } else {
        x.erase(first);
    }
  return find_max_index(x, n-1);
}
    


void swap(int& x, int& y)
{
  int t = x;
  x = y;
  y = t;
}

void selection_sort(vector<int>& x, int n)
{
  // TODO: don't use any loop control structures
    if(n == 0)return;
    int max_index = find_max_index(x, n);
    swap(x[max_index], x[n-1]);
    selection_sort(x, n-1);
}

int main()
{
  read_input();
  selection_sort(x, n);
  for(int i=0; i<n; i++) {
    cout << x[i] << endl;
  }
}