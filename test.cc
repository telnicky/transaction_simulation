#include <string>
#include <iostream>

using namespace std;

class who {
public:
  who() {
    num = 0;
  }

  int num;
};

class what {
public:
  what(who *him) {
    jeez = him;
  }

  int get_jeez_num() {
    return jeez->num;
  }
private:
  who *jeez;
};

int main () {
  who w;
  what t(&w);
  cout << t.get_jeez_num() << endl;
  w.num++;
  cout << t.get_jeez_num() << endl;
}