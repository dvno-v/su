#ifndef STRING_CPP

#define STRING_CPP
#include "String.h"

void String::erase_memory()
{
    delete[] m_data;
    m_data = nullptr;
}

void String::copy_memory(const char* data)
{
    char* temp = new char[strlen(data) + 1];
    strcpy(temp, data);
    m_data = temp;
}

void String::resize(unsigned& n){
    char* temp = new char [n];
    if(m_data != nullptr) {
        for (int i = 0; i < n; ++i) {
            temp[i] = m_data[i];
        }
    }
    erase_memory();
    m_data = temp;
}


String::String()
{
    m_data = nullptr;
    m_curr_size = 0;
}

String::String(const char* data)
{
    copy_memory(data);
    m_curr_size = strlen(data) + 1;
}


String::String(const String& other)
{
    copy_memory(other.m_data);
    m_curr_size = strlen(other.m_data) + 1;
}


String::~String()
{
    erase_memory();
}

String& String::operator=(const String& other)
{
    if(&other != this){
        erase_memory();
        copy_memory(other.m_data);
        m_curr_size = other.m_curr_size;
    }
    return *this;
}

char& String::at(unsigned index) const {
    assert(index < m_curr_size);
    return m_data[index];
}

char& String::operator[](unsigned index) const {
    return at(index);
}

const char* String::front() const{
    return m_data;
}

const char* String::back() const{
    return m_data + m_curr_size;
}

const char* String::data() const{
    return m_data;
}

bool String::empty(){
    return m_curr_size == 0;
}

unsigned String::get_size() const {
    return m_curr_size;
}



void String::clear(){
    erase_memory();
    m_curr_size = 0;
}

void String::insert(const char& c, const unsigned& index){
    resize(++m_curr_size);

    for (int i = m_curr_size - 1; i > index; i--)
    {
        m_data[i] = m_data[i-1];
    }

    m_data[index] = c;
}

void String::erase(const unsigned& start, const unsigned& finish){
    assert(start >= 0 && finish < m_curr_size);
    unsigned diff = finish - start;
    unsigned help_counter = finish;
    for (unsigned i = 0; i < m_curr_size; i++)
    {
        if(i >= start && i <= finish && help_counter < m_curr_size){
            m_data[i] = m_data[help_counter++];
        }
    }
    m_curr_size -= diff;
    resize(m_curr_size);
}

void String::erase(const unsigned& start){
    erase(start, m_curr_size - 1);
}


void String::erase(const char* start, const char* finish){
    unsigned u_start = start - front();
    unsigned u_end = finish - back();
    erase(u_start, u_end);

}
void String::erase(const char* start){
    unsigned u_start = start - front();
    erase(u_start, m_curr_size - 1);
}
void String::push_back(const char& c){
    resize(++m_curr_size);
    m_data[m_curr_size - 1] = c;
}
char String::pop_back(){
    if(m_curr_size >= 0){
        char temp = m_data[m_curr_size - 1];
        resize(--m_curr_size);
        return temp;
    }
}
void String::append(const char& c){
    push_back(c);
}
void String::operator+=(const char& c){
    append(c);
}

int String::compare(const String& other){
    return strcmp(m_data, other.m_data);
}

std::ostream& operator<<(std::ostream& out, const String& str){
    for (int i = 0; i < str.get_size(); ++i) {
        out << str.data()[i];
    }
    std::cout << std::endl;
    return out;
}
#endif //!STRING_CPP