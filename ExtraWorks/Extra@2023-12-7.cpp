#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int m,n;
    cin >> n >> m;
    vector<bool> People(n);
    vector<int> Output;
    for (int i=0,total=0,count=0; total!=n; i=(i+1)%n) {
        if (People[i]) continue;
        else count++;
        if (count == m) {
            count = 0;
            total++;
            Output.push_back(i+1);
            People[i] = true;
        }
    }
    for (auto &num: Output)
        cout << num << ' ';
}