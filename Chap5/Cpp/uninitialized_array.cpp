#include <iostream>
#include <cassert>

template <class T>
class UnArr {
public:
  UnArr(int len) : _validRange(0), _len(len) {
    _array = new T[len];
    _initializedIndex = new T[len];
    _reverseLookup = new T[len];
  }

  ~UnArr() {
    delete[] _array;
    delete[] _initializedIndex;
    delete[] _reverseLookup;
  }

  bool isValid(int i) {
    return i >= 0 && _reverseLookup[i] < _validRange && _initializedIndex[_reverseLookup[i]] == i;
  }

  bool read(int i, T& val) {
    if (isValid(i)) {
      val = _array[i];
      return true;
    }
    return false;
  }

  void write(int i, T val) {
    if (!isValid(i)) {
      _initializedIndex[_validRange] = i;
      _reverseLookup[i] = _validRange++;
    }
    _array[i] = val;
  }

private:
  T *_array;
  T *_initializedIndex;
  T *_reverseLookup;
  int _validRange;
  int _len;
};

int main() {
  UnArr<int> arr(100);
  int val;
  assert(!arr.read(-1, val));
  assert(!arr.read(100, val));

  assert(!arr.read(5, val));
  arr.write(5, 100);
  assert(arr.read(5, val));
  assert(val == 100);

  return 0;
}