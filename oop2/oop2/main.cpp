#include <iostream>
#include <cstring>

using namespace std;

class MyString{
private:
        char * str;
public:
    //конструктор без параметра
    MyString()
    {
        this -> str = nullptr;
    }
    
    MyString(const char *str) //конструктор с параметром
    {
        size_t len = strlen(str);
        this->str = new char[len+ 1];
        for (int i = 0; i < len; i++)
        {
            this->str[i] = str[i];
        }
        //закрываем строку терминирующим нулём
        this->str[len] = '\0';

    }
    //деструктор
    ~MyString()
    {
        delete[] this->str;
    }
    //копирование
    MyString(const MyString &other)
    {
        size_t len = strlen(other.str);
        this->str = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[len] = '\0';
    }
    //перегруженный оператор присваивания
    MyString &operator =(const MyString& other)
    {
    
        if (this->str != nullptr)
        {
            delete[] str;
        }

        size_t len = strlen(other.str);
        this->str = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[len] = '\0';

        return *this;

    }
    void print() const {
            if (str != nullptr) {
                cout << str;
            }
        }

};

int main() {
    MyString str;
    MyString str2 = "World";
    MyString str3 = str2;
    str.print();
        cout << endl;
        str2.print();
        cout << endl;
    str3.print();
    return 0;
}

