
#include <iostream>
#include <cstring>

class myString
{
    char *m_array;
    int m_size;

public:
    myString(const char *arr)
    {
        m_size = strlen(arr);
        m_array = new char[m_size + 1];
        memcpy(m_array, arr, m_size);
        m_array[m_size] = 0; // to include the null terminator
    }

    myString(const myString &other) : m_size(other.m_size)
    {
        std::cout << "copy constructor called\n";
        /* below line is what happens in the default copy constructor, its a shallow copy. therefore in our case it's basically copy the array pointer into this. So both of them now points to the same dynamic array. therefore we need to explicitly say that do a deep copy*/
        // memcpy(this, &other, sizeof(myString));
        m_array = new char[m_size + 1];
        memcpy(m_array, other.m_array, m_size + 1); // since this actually comes from a myString object null terminator is there
    };

    myString &operator=(const myString &other)
    {
        std::cout << "copy assignment called\n";
        if (this != &other) // to avoid self assignment
        {
            m_size = other.m_size;
            delete[] m_array;
            m_array = new char[m_size + 1];
            memcpy(m_array, other.m_array, m_size + 1);
        }
        return *this;
    }

    char &operator[](unsigned int i)
    {
        return m_array[i];
    }

    myString operator+(const myString &other)
    {
        int new_size = m_size + other.m_size;
        char *new_array = new char[new_size + 1];
        memcpy(new_array, m_array, m_size);
        memcpy(new_array + m_size, other.m_array, other.m_size + 1);
        myString newstring(new_array);
        return newstring;
    }

    friend std::ostream &operator<<(std::ostream &stream, const myString &string); // friend can access private members

    ~myString()
    {
        delete[] m_array;
    }
};

std::ostream &operator<<(std::ostream &stream, const myString &string) // override the default cout function
{
    stream << string.m_array; // since m_array is a private member, the myString class need to add this function as a friend in class declaration
    return stream;
}

void printBuffer(const myString &arr) // if the value was passed copy constructor make a copy. by referencing, we do not copy.
{
    std::cout << arr << std::endl;
}

int main()

{
    myString firststring("hi I am Imdaad");
    myString secondstring(firststring);
    myString thirdstring = secondstring;

    secondstring[2] = ',';
    thirdstring = secondstring;

    myString forthstring = secondstring + firststring;
    printBuffer(firststring);
    printBuffer(secondstring);
    printBuffer(thirdstring);
    printBuffer(forthstring);

    return 0;
}