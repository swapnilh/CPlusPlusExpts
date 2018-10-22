#include <iostream>

class DummyClass {
  public:
      DummyClass (int A, int B) : A_(A), B_(B) {}

      int* getAddr() {
          return &A_;
      }

  private:
      int A_;
      int B_;
};

struct DummyStruct {
      DummyStruct (int A, int B) : A_(A), B_(B) {}

      int* getAddr() {
          return &A_;
      }

      int A_;
      int B_;
};


int main () {
    void *mem = malloc(sizeof(DummyClass));
    auto *dummy_object = new (mem) DummyClass(1, 2);
    std::cout << "Addr of A:" << (void*) dummy_object->getAddr() << std::endl;
    std::cout << "Addr of mem:" << mem << std::endl;
    std::cout << "Addr of object:" << (void *) dummy_object << std::endl;

    void *mem2 = malloc(sizeof(DummyStruct));
    auto *dummy_object2 = new (mem2) DummyStruct(1, 2);
    std::cout << "Addr of A:" << (void*) dummy_object2->getAddr() << std::endl;
    std::cout << "Addr of mem:" << mem2 << std::endl;
    std::cout << "Addr of object:" << (void *) dummy_object2 << std::endl;

    return 0;
}
