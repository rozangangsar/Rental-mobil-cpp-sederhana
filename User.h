#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

// Enum untuk role pengguna
enum UserRole {
    ADMIN = 1,
    USER = 2
};

class User {
private:
    string username;
    string password;
    UserRole role;

public:
    // Constructor
    User();
    User(string uname, string pwd, UserRole r);

    // Setter methods
    void setUsername(string uname);
    void setPassword(string pwd);
    void setRole(UserRole r);

    // Getter methods
    string getUsername();
    string getPassword();
    UserRole getRole();

    // Utility methods
    string getRoleAsString();
    bool verifyPassword(string inputPassword);

};

#endif
