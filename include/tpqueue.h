// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include<string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T* arr;
    int first;
    int last;
    int count;
    
 public:
    TPQueue() : arr(new T[size]), first(0), last(0), count(0) {}
    ~TPQueue() { delete[] arr; }
    void push(const T& value) {
        if (count == size)
            throw std::string("full");
        else {
            int position;
            int i = first;
            int j = last;
            while (i < last) {
                if (arr[i].prior < value.prior) {
                    position = i;
                    break;
                }
                ++i;
            }
            while (j < position) {
                arr[i % size] = arr[(i - 1) % size];
            }
            arr[(position % size)] = value;
            ++count;
            ++last;
        }
    }
    T& pop() {
        if (0 == count)
            throw std::string("empty");
        else {
            --count;
            return arr[first++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
