#pragma once
#include <vector>
#include <stdexcept>

namespace circular_buffer {

// TODO: add your solution here
template <typename T>
class circular_buffer{
    private:
        int head, tail, size, used;
        std::vector<T> buffer;

    public:
        circular_buffer(int s) : head{0}, tail{-1}, size{s}, used{0}, buffer(s) {}

        void write(T data){
            if(used == size) throw std::domain_error("Ops...");
            tail = (tail + 1) % size;
            used++;
            buffer[tail] = data;
        }

        T read(){
            if(used == 0) throw std::domain_error("Ops...");
            T value = buffer[head];
            head = (head + 1) % size;
            used--;
            return value;
        }

        void clear() {
            head = 0;
            tail = -1;
            used = 0;
        }

        void overwrite(T data) {
            if(used == size){
                buffer[head] = data;
                head = (head + 1) % size;
                tail = (tail + 1) % size;                
            } else { write(data); };        
        }
};

}  // namespace circular_buffer
