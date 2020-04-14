#ifndef STRING_CPP

#define STRING_CPP

void String::erase_memory()
{
    delete[] m_data;
}

void String::copy_memory(const char* data)
{
    char* temp = new char[strlen(data) + 1];
    strcpy(temp, data);
    m_data = temp;
}

void String::resize(){
    m_max_capacity *= 2; 
    char* temp = new char [m_max_capacity];
    strcpy(temp, m_data);
    erase_memory();
    m_data = temp;
}


String::String()
{
    m_data = nullptr;
    m_curr_size = 0;
    m_max_capacity = 0;
}

String::String(const char* data)
{
    copy_memory(data);
    m_curr_size = strlen(data) + 1;
    m_max_capacity = m_curr_size * 2;
}


String::String(const String& other)
{
    copy_memory(other.m_data);
    m_curr_size = strlen(other.m_data) + 1;
    m_max_capacity = m_curr_size * 2;
}


String::~String()
{
    erase_memory();
}

String& String::operator=(const String& other)
{
    erase_memory();
    copy_memory(other.m_data);
    m_curr_size = other.m_curr_size;
    m_max_capacity = other.m_max_capacity;
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

bool String::empty() const{
    return m_curr_size == 0;
}

unsigned String::get_size() const {
    return m_curr_size;
}

unsigned String::get_max_capacity() const {
    return m_max_capacity;
}

void String::clear(){
    erase_memory();
    m_data = new char[m_curr_size];
}

void String::insert(const char& c, const unsigned& index){
    if(m_curr_size + 1 >= m_max_capacity){
        resize();
    }
    bool passed_index = false;

    for (int i = m_curr_size - 1; i > index; i--)
    {
        m_data[i] = m_data[i-1];
    }

    m_data[index] = c;
    m_data[m_curr_size++] = '\0';    
}

std::ostream& operator<<(std::ostream& out, const String& str){
    out << str.data() << std::endl;
    return out;
}
#endif //!STRING_CPP