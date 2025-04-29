#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return List::current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    List::Element *new_element = new List::Element(entry);
    new_element->next = List::head;
    List::head = new_element;
    List::current_size++;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if(List::head == nullptr) throw std::runtime_error("can't pop empty list");

    int val = List::head->data;
    List::Element* ptr_to_next = List::head->next;

    delete head;
    head = ptr_to_next;
    List::current_size--;
    return val;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
    List::Element* priv_el = nullptr;
    List::Element* next_el = nullptr;
    List::Element* curr_el = head;
    for(int n = current_size; n > 0; n--){
        next_el = curr_el->next;
        curr_el->next = priv_el;
        priv_el = curr_el;
        curr_el = next_el;
    }
    head = priv_el;
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    while (List::current_size)
    {
        pop();
    }
}

}  // namespace simple_linked_list
