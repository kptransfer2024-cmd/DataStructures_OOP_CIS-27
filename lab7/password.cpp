#include <iostream>
#include <string>
using namespace std;

class Password{
    private:
        int length;
    public:
        string password;
        Password(string pass){
            password = pass;
            length = pass.length();
        }

        bool lengthValid(){
            return length >= 12;
        }

        bool hasSpecial(){
            int count = 0;
            for (char c : password) {
                if (c >= 0 && c <= 47 || c >= 58 && c <= 64 || c >= 91 && c <= 96 || c >= 123 && c <= 127) {
                    count++;
                }
            }
            return count >= 1;
        }

        bool oneUpper(){
            int count = 0;
            for (char c : password) {
                if (c >= 65 && c <= 90) {
                    count++;
                }
            }
            return count == 1;
        }

        bool oneNumeric(){
            int count = 0;
            for (char c : password) {
                if (c >= 48 && c <= 57) {
                    count++;
                }
            }
            return count == 1;
        }

        int passwordValidation(){
            if (!lengthValid()){
                cout << "Password must be at least 12 characters long." << endl;
            }
            if (!hasSpecial()){
                cout << "Password must contain at least 1 special, non numeric, non alphabet character." << endl;
            }
            if (!oneUpper()){
                cout << "Password must contain 1 Upper Case letter." << endl;
            }
            if (!oneNumeric()){
                cout << "Password must contain 1 numeric character." << endl;
            }
            if (lengthValid() && hasSpecial() && oneUpper() && oneNumeric()){
                cout << "Password is valid." << endl;
                return 1;
            } else {
                cout << "Password is invalid." << endl;
                return 0;
            }
        }

};

int main() {
    string pass;
    cout << "Enter a password: ";
    cin >> pass;
    Password password(pass);

    while (password.passwordValidation() == 0){
        cout << "Please try again: " << endl;
        cin >> pass;
        password = Password(pass);
    }

    cout << endl;
    cout << "Re-enter Password to confirm: " << endl;
    string confirmPass;
    cin >> confirmPass;
    if (confirmPass == pass){
        cout << endl;
        cout << "Password confirmed and stored!" << endl;
    }
    else {
        cout << "Passwords do not match." << endl;
        cout << "Exiting..." << endl;
        cout << endl;
    }

    return 0;
}

