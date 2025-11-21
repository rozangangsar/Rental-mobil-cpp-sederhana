#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H

#include "User.h"
#include <vector>
using namespace std;

class AuthenticationManager {
private:
    vector<User> users;
    User* currentUser;

public:
    // Constructor
    AuthenticationManager();

    // Authentication methods
    User* login(string username, string password);
    void logout();
    User* getCurrentUser();
    bool isLoggedIn();

    // User management
    void initializeDefaultUsers();
    void addUser(string username, string password, UserRole role);
    void printAvailableUsers();

    // Utility
    bool isAdminLoggedIn();
    bool isUserLoggedIn();

};

#endif
