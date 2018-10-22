#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

class Tester {
  public:
      Tester (const char* name) : name_(name) {
        cout << "Tester ctor:" << name_ << endl;
      }

      ~Tester() {
          cout << "Tester dtor:" << name_ << endl;
      }

  private:
    std::string name_;
};


void HoldRefFor10Seconds(std::shared_ptr<Tester> obj) {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    cout << "Thread 1 returns" << endl;
    return;
}

int main () {
    auto shared_obj = std::make_shared<Tester>("First");
    std::thread t1(HoldRefFor10Seconds, shared_obj);
    cout << "Thread 0 about to replace shared ptr" << endl;
    shared_obj = std::make_shared<Tester>("Second");        
    std::this_thread::sleep_for(std::chrono::seconds(15));
    cout << "Thread 0 returns" << endl;
    t1.join();
    return 0;
}
