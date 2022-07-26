#include <iostream>
#include <cstring>

using namespace std;

int &getValue()
{
    static int i = 10;
    return i;
}

void setValue(const int &i)
{
}

void detect(int &i)
{
    cout << "[lvalue] " << i << endl;
}

void detect(int &&i)
{
    cout << "[rvalue] " << i << endl;
}

class String
{
public:
    String()
        : m_array(nullptr), m_size(0)
    {
        cout << "default constructor\n";
    };

    String(const char *charArray)
    {
        cout << "constructor\n";
        m_size = strlen(charArray);
        m_array = new char[m_size];
        memcpy(m_array, charArray, m_size);
    }

    String(const String &other) // copy constructor
    {
        cout << "copy constructor\n";
        m_size = other.m_size;
        m_array = new char[m_size];
        memcpy(m_array, other.m_array, m_size);
    }

    String(String &&other) noexcept // move constructor
    {
        cout << "move constructor\n";
        m_size = other.m_size;
        m_array = other.m_array;

        other.m_array = nullptr;
        other.m_size = 0;
    }

    String &operator=(String &&other) noexcept // move assignment
    {
        if (this != &other)
        {
            delete[] m_array;

            cout << "move assignment\n";
            m_size = other.m_size;
            m_array = other.m_array;

            other.m_array = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    String &operator=(const String &other) // copy assignment
    {
        if (this != &other)
        {
            delete[] m_array;

            cout << "copy assignment\n";
            m_size = other.m_size;
            m_array = new char[m_size];
            memcpy(m_array, other.m_array, m_size);
        }
        return *this;
    }

    void print()
    {
        cout << m_array << endl;
    }

    ~String()
    {
        cout << "destroy\n";
        delete[] m_array;
    }

private:
    int m_size;
    char *m_array;
};

class Entity
{
public:
    Entity(const String &s) // lvalue reference
        : m_string(s)       // calls the copy constructor
    {
    }

    Entity(String &&s)           // rvalue reference
        : m_string(std::move(s)) // calls the move constructor
    {
    }

private:
    String m_string;
};

int main()
{
    int i = 10; // i lvalue (got a location), 10 rvalue(temporary)

    int a = getValue();
    getValue() = 3; // lvalue reference
    cout << getValue() << endl;

    int x1 = 10;
    // int& x2 = 10; //cannot have an lvalue reference for an rvalue, exceptions exist
    const int &x3 = 10;

    ////const lvalue references work both with lvalue and rvalue
    setValue(a);
    setValue(3);

    int p = 5;
    int q = 10;
    int r = p + q;

    detect(r);
    detect(p + q); // do not need a variable to hold an rvalue

    // move semantics

    Entity entity(String("imdaad"));

    // move constructor and move assignment

    String old = "apple";

    String newA = old; // copy constructor
    String newB(old);

    String newC(std::move(old)); // move constructor
    String newD = std::move(old);

    newC = old; // copy assignment

    newC = std::move(old); //move assignment

    return 0;
}