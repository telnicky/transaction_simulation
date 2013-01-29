#include <map>
#include <string>
#include <iostream>

using namespace std;
int main() {
 std::map<std::string, int> counters;
 cout << counters["v"] + 1 << endl;
 return 0;
}
