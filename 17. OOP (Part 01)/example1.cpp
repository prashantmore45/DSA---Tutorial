/*
Create a User class with properties : id(private), username(public) & password(private).
Its id should be initialized in a parameterized construtor.
It should have a Getter & Setter for password.
*/

#include<iostream> 
using namespace std;

class User {
    private:
        int id;
        string password;

    public:
        string username;

        User(int id) {
            this->id = id;
            cout << "constructor with parameter\n";
        }

        //Setter
        void setPassword(string password) {
            this->password = password;
        }

        //Getter
        string getPassword() {
            return password;
        }
};

int main() {
    User user1(101);
    user1.username = "prashantmore";
    user1.setPassword("Admin");

    cout << "Name: " << user1.username << endl; 
    cout << "Password: " << user1.getPassword() << endl;
    return 0;
}