#include <iostream>
using namespace std;

class String
{
    char *data;
    size_t size;

public:

///@brief Construct a new String object and it should have a default value of ""**/
    String(){
      size = 0;
      data = new char[1];
      data[0]='\0';
    }

///@brief Construct a new String object with the provided value*
///@param str/
    String(const char* str){ ///стринговете могат да имат произволна дължина, затова отделяме дин. памет за тях
        size=0;
        while(str[size] != '\0'){ ///има функция strlen()
            size++;
        }
        data = new char[size+1];
        for (size_t i=0; i<size; i++){
            data[i]=str[i];
        }
        data[size]='\0';
    }

///@brief Construct a new String object by copying another string*
///@param other*/
    String(const String &other){///копи-конструктор
        size=other.size;
        data = new char[size+1];
         for (size_t i=0; i<size; i++){
            data[i]=other.data[i];
        }
        data[size]='\0';
    }

///@brief Copies the values from the other string in this string*
///@param other
///@return String&*/
    String &operator=(const String &other){ ///Предефиниране на оператора за присвояване =
        if (this != &other){ ///ако направим str1=str1, да не изтрием обекта
            delete[] data;
            size=other.size;
            for (size_t i=0; i<size; i++){
            data[i]=other.data[i];
            }
            data[size]='\0';
        }
        return *this;
    }

///@brief Destroy the String object**/
    ~String(){
        delete[] data;
        cout << "The object is destroyed."<<endl;
    }

///@brief Returns the string as a C-style string - char**
///@return const char*/
    const char *toCString() const{
        return data;
    }

///@brief Returns the length of the string*
///@return size_t*/
    size_t length() const{
        return size;
    }
};

int main(){
    String str1;
    String str2("Hello");
    String str3=str2; ///kopi-konstr
    cout << "str1 " << str1.toCString() << " Len: " << str1.length()<< endl;
    cout << "str2 " << str2.toCString() << " Len: " << str2.length()<< endl;
    cout << "str3 " << str3.toCString() << " Len: " << str3.length()<< endl;
    str1=str2;
    cout << "str1 " << str1.toCString() << " Len: " << str1.length()<< endl;
    return 0;
}