#include <iostream>
using namespace std;

class My_String {
    private:
        // int length = 0;
    public:
        char str[100];
        My_String(){
        // for (int i = 0; i < 100; i++){
        //     str[i] = nullptr;
        // }
        //length = length();
        str[0] = '\0';
    }

        int length(){
            int len = 0;
            while (str[len]){
                len++;
            }
            // cout << "The length of the string is: " << len << endl;
            return len;
        }

        void display(){
            cout << "The string is: " << str << endl;
        }

        void toUpper(){
            int i = 0;
            while (str[i]){
                if (str[i] >= 97 && str[i] <= 122){
                    str[i] -= 32;
                }
                i++;
            }
            cout << "The string in uppercase is: " << str << endl;
        }

        void push_back(char c){
            int len = length();
            str[len] = c;
            str[len + 1] = '\0';
            // cout << "The string after adding the character is: " << str << endl;
        }
};

int main() {

    My_String s;
    cout << "Enter a string: ";
    cin >> s.str;


    cout << "The length of the string is: " << s.length() << endl;
    s.display();

    s.toUpper();
    s.display();

    cout << "Enter a character to add to the end of the string: ";
    char c;
    cin >> c;
    
    s.push_back(c);
    s.display();
    cout << "The length of the string is: " << s.length() << endl;
  
}
