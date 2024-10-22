#include <iostream>
#include <vector>
#include <memory>

void body();

// Big ass object class.
class Obj {
public:
  Obj(int i) 
  : ip{new int{2}}
  {
    for (int j=0; j<10000; j++)
    {
      x[j] = static_cast<double>(i);
    }
    std::cout << "ctor " << i << "\n";
  };
  ~Obj() {
    std::cout << "dtor\n";
  }
  Obj(Obj && a) noexcept = default;
private:
  double x[10000];
  std::unique_ptr<int> ip;
};

int main()
{
  body();
  std::cout << "\nBack in Main\n";
  return 0;
}

void body()
{
  std::vector<Obj> big_data;

  // Vector sometimes enlarges it's allocated area and must copy
  // old values over to new positions in which it calls the copy
  // constructor. Remove comments below to reserve and fix ctors
  // and dtors.

  // big_data.reserve(3);
  big_data.emplace_back(1);
  big_data.emplace_back(2);
  big_data.emplace_back(3);
  std::cout << "END\n";
}