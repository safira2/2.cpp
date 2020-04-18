// Soal ke-2
// 2.cpp
// Oleh: Safira Khoirunnisa

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Kelas Form
class Form{
public:
    char *Username;
    char *Password;
    Form(){
        Username = nullptr;
        Password = nullptr;
    }
    ~Form(){
        Username = nullptr;
        Password = nullptr;
    }
    bool usernameCheck(char *username);
    bool passwordCheck(char *password);
};

// Fungsi usernameCheck()
bool Form::usernameCheck(char *username){
    Username = username;
    int i = 0;
    while(*username != '\0'){
        if(i == 0 && Username[i] != '@'){
            return 1;
            break;
        }
        if(i > 12){
            return 1;
            break;
        }
        ++i;
        ++username;
    }
    if(i<1){
        return 1;
    }
    return 0;
}

// Fungsi passwordCheck()
bool Form::passwordCheck(char *password){
    Password = password;
    int i = 0;
    while(*password != '\0'){
        if(!(Password[i] >= 49 && Password[i] <= 57)){
            return 1;
            break;
        }
        if(i > 6){
            return 1;
            break;
        }
        ++i;
        ++password;
    }
    if(i<1){
        return 1;
    }
    return 0;
}

// Fungsi main()
// Memasukkan Username dan Password dari argumen program atau dari beberapa pertanyaan
int main(int argc, char **argv){
    if(argc>3){
        cout << "You cannot enter arguments more than two." << endl;
        return 1;
    }
    char *username = nullptr, *password = nullptr; // username dan password
    string usernameStr, passwordStr; // std::getline membutuhkan keyword string, bukan char* atau const char*
    if(argc==1){
        // Memasukkan username dan password
        cout << "Enter your username: ";
        getline(std::cin, usernameStr);
        username = new char[usernameStr.length()+1];
        strcpy(username, usernameStr.c_str());
        cout << "Enter your password: ";
        getline(std::cin, passwordStr);
        password = new char[passwordStr.length()+1];
        strcpy(password, passwordStr.c_str());
    } else if(argc>1 && (argv[1] && argv[2])){
        username = new char[strlen(argv[1])+1];
        password = new char[strlen(argv[2])+1];
        username = argv[1];
        password = argv[2];
    } else {
        cout << "Please enter your arguments completely." << endl;
        return 1;
    }
    Form form;
    bool run_usernameCheck = form.usernameCheck(username); // Menjalankan fungsi usernameCheck() dari kelas Form
    bool run_passwordCheck = form.passwordCheck(password); // Menjalankan fungsi passwordCheck() dari kelas Form
    // Menentukan beberapa kemungkinan yang akan terjadi
    if(run_usernameCheck && run_passwordCheck){
        cout << "Your username \"" << form.Username << "\" and your password \"" << form.Password << "\" is invalid." << endl;
        return 1;
    } else if(run_usernameCheck || run_passwordCheck){
        if(run_usernameCheck){
            cout << "Your username \"" << form.Username << "\" is invalid." << endl;
            return 1;
        } else if(run_passwordCheck){
            cout << "Your password \"" << form.Password << "\" is invalid." << endl;
            return 1;
        }
    } else {
        cout << "Your username and your password are correct." << endl;
        return 0;
    }
}
