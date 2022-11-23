//
// Created by emil9 on 2022-11-19.
//

#include <algorithm>
#include <iostream>
#include "int_buffer.h"

int_buffer::int_buffer(size_t size) : first(new int[size]),last(first+size) {
}

int_buffer::int_buffer(const int *source, size_t size) : int_buffer(size)  {
    std::copy(source,source+size,first);
}

size_t int_buffer::size() const {
    return std::distance(first,last);
}

int_buffer::int_buffer(const int_buffer &rhs) : int_buffer(rhs.size()) {
    std::cout << "Copy Construtor is used!!!!" << std::endl;
    std::copy(rhs.begin(),rhs.end(),begin());

}

int_buffer::~int_buffer() {
    std::cout << "Stroy!!!" << std::endl;
    delete first;
}

int &int_buffer::operator[](size_t index) {
    std::cout<< "Not const!!!!" <<std::endl;
    return first[index];
}

const int &int_buffer::operator[](size_t index) const {
    std::cout << "Const!!!!" << std::endl;
    return first[index];
}

int *int_buffer::begin() {
    return first;
}

int * int_buffer::end() {
    return last;
}

const int *int_buffer::begin() const {
    return first;
}

const int *int_buffer::end() const {
    return last;
}


int_buffer &int_buffer::operator=(const int_buffer &rhs)   {
    int_buffer buffer(rhs);
    buffer.swap(*this);
    std::cout << "Assigntment Operator used" << std::endl;

    return *this;
}


void int_buffer::swap(int_buffer &buffer) {
    using std::swap;
    swap(first,buffer.first);
    swap(last,buffer.last);
}

int_buffer::int_buffer(int_buffer &&rhs) {
    first = rhs.first;
    last = rhs.last;

    rhs.first = nullptr;
    rhs.last = nullptr;
    std::cout << "MOVIE TIME!!!!" << std::endl;
}

int_buffer &int_buffer::operator=(int_buffer &&rhs) {

    //return Something;
}






