#pragma once
#include <stdexcept>

namespace linked_list {

template<typename T>
class List{
    struct Node{
        T value;
        Node* next;
        Node* prev;
        Node(const T& v) : value(v), next(nullptr), prev(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    public:
        ~List() { while(tail) pop();}

        void push(const T& v){
            // adds an element to the end of the list
            Node* n = new Node(v);
            n->prev = tail;
            if(tail) tail->next = n;
            tail = n;
            if(!head) head = tail;
        }

        void unshift(const T& v){
            // adds an element to the start of the list
            Node* n = new Node(v);
            if(head) head->prev = n;
            n->next = head;
            n->prev = nullptr;
            head = n;
        } 

        T pop(){
            // removes and returns the last element of the list
            if (!tail) throw std::runtime_error("empty list");
            Node* node_to_delete = tail;
            tail = node_to_delete->prev;

            if(tail) tail->next = nullptr; 
            else head = nullptr;

            T result = node_to_delete->value;
            delete(node_to_delete);
            return result;
        }

        T shift(){
            // removes and returns the first element of the list
            if(!head) throw std::runtime_error("empty list");
            Node* node_to_delete = head;
            head = node_to_delete->next;

            if(head) head->prev = nullptr;
            else tail = nullptr;

            T result = node_to_delete->value;
            delete(node_to_delete);
            return result;
        } 

        int count(){
            // returns the total number of elements in the current list
            int result(0);
            Node* pointer = head; 
            while(pointer){
                result++;
                pointer = pointer->next;
            }
            return result;
        }

        void erase(const T& v){
            // remove first occurence of value
            Node* pointer = head; 
            while(pointer){
                if(pointer->value == v){
                    if(pointer->prev) pointer->prev->next = pointer->next;
                    else head = pointer->next;
                    if(pointer->next) pointer->next->prev = pointer->prev;
                    else tail = pointer->prev;
                    delete(pointer);
                    return;
                }
                pointer = pointer->next;
            }
        } 
};

}  // namespace linked_list
