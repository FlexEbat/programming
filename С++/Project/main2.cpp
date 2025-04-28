#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

struct UserSession {
    std::string name;
    std::string sex;
    std::string email;
    std::string username;
    std::string password;
};

UserSession currentSession; // глобальная помойка для текущего юзера

void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void UserProfile() {
    ClearScreen();
    std::cout << "[User Profile]" << std::endl;
    std::cout << "Name: " << currentSession.name << std::endl;
    std::cout << "Sex: " << currentSession.sex << std::endl;
    std::cout << "Email: " << currentSession.email << std::endl;
    std::cout << "Username: " << currentSession.username << std::endl;
    std::cout << "Password: " << currentSession.password << std::endl;
}

void ChoiceNews() {
    std::ifstream newsFile("news.txt");
    if (!newsFile.is_open()) {
        std::cout << "[!Couldn't open news file, you useless fuck.]" << std::endl;
        return;
    }

    std::cout << "\n[Latest News]" << std::endl;
    std::string line;
    while (std::getline(newsFile, line)) {
        std::cout << "- " << line << std::endl;
    }
    newsFile.close();
}

void MainMenu() {
    while (true) {
        std::cout << "[Main Menu for " << currentSession.username << "]" << std::endl;
        std::cout << "[1] View Profile" << std::endl;
        std::cout << "[2] Read News" << std::endl;
        std::cout << "[3] Logout" << std::endl;
        std::cout << "[Enter your choice -> ";

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            UserProfile();
        } else if (choice == "2") {
            ChoiceNews();
        } else if (choice == "3") {
            std::cout << "[Fuck off to main screen, bitch.]" << std::endl;
            break;
        } else {
            std::cout << "[!Invalid choice, you brainless fuckwit.]" << std::endl;
        }
    }
}

bool isUsernameTaken(const std::string& username) {
    std::ifstream inFile("users.txt");
    if (!inFile.is_open()) {
        return false; 
    }
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string name, sex, email, storedUsername, storedPassword;
        iss >> name >> sex >> email >> storedUsername >> storedPassword;
        if (storedUsername == username) {
            return true;
        }
    }
    return false;
}

void Register() {
    std::cout << "[Enter your personal information]" << std::endl;

    std::string name, username, sex, email, password, password2;

    while (true) {
        std::cout << "[!Enter your Login -> ";
        std::getline(std::cin, username);

        if (isUsernameTaken(username)) {
            std::cout << "[!This login is already taken, dumbass. Try another.]" << std::endl;
        } else {
            break;
        }
    }

    std::cout << "[!Enter your name -> ";
    std::getline(std::cin, name);

    while (true) {
        std::cout << "[!Enter your sex (M/F) -> ";
        std::getline(std::cin, sex);
        if (sex == "M" || sex == "F") {
            break;
        } else {
            std::cout << "[!Learn the fucking alphabet and type M or F]" << std::endl;
        }
    }

    std::cout << "[!Enter your email -> ";
    std::getline(std::cin, email);

    std::cout << "[!Enter your password -> ";
    std::getline(std::cin, password);

    std::cout << "[!Enter your password again -> ";
    while (true) {
        std::getline(std::cin, password2);
        if (password == password2) {
            break;
        } else {
            std::cout << "[!You useless fuck, passwords don't match. Try again]" << std::endl;
        }
    }

    std::ofstream outFile("users.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << std::left
                << std::setw(15) << name
                << std::setw(5)  << sex
                << std::setw(30) << email
                << std::setw(20) << username
                << std::setw(20) << password
                << std::endl;
        outFile.close();
        std::cout << "[Registration complete, welcome to the shitshow.]" << std::endl;
    } else {
        std::cout << "[!Error: Unable to open file, guess you're fucked.]" << std::endl;
    }
}

bool Login() {
    std::string username, password;
    std::cout << "[!Enter your login -> ";
    std::getline(std::cin, username);
    std::cout << "[!Enter your password -> ";
    std::getline(std::cin, password);

    std::ifstream inFile("users.txt");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string name, sex, email, storedUsername, storedPassword;
            iss >> name >> sex >> email >> storedUsername >> storedPassword;

            if (storedUsername == username && storedPassword == password) {
                std::cout << "[Login successful, you miserable fuck.]" << std::endl;
                currentSession.name = name;
                currentSession.sex = sex;
                currentSession.email = email;
                currentSession.username = storedUsername;
                currentSession.password = storedPassword;
                inFile.close();
                ClearScreen();
                MainMenu();
                return true;
            }
        }
        std::cout << "[!Invalid username or password, dickhead.]" << std::endl;
        inFile.close();
        return false;
    } else {
        std::cout << "[!Error: Unable to open file]" << std::endl;
        return false;
    }
}

int Greetings() {
    auto now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    std::cout << "[Welcome to TestLabs Project! " << std::put_time(std::localtime(&time_now), "%H:%M:%S") << "]" << std::endl;
    std::cout << "[This is a test project for C++ programming.]" << std::endl;
    std::cout << "[Here you can read the news without using a browser - only pure fucking text!]" << std::endl;

    std::string choice;
    std::cout << "[Do you want to login or register? (enter 'L' or 'R') -> ";
    std::getline(std::cin, choice);

    if (choice == "L") {
        return Login() ? 0 : 1;
    } else if (choice == "R") {
        Register();
        return 0;
    } else {
        std::cout << "[!Invalid choice, you fucking donkey.]" << std::endl;
        return 1;
    }
}

int main() {
    while (true) {
        if (Greetings() == 0) {
            std::cout << "[!Press Enter to return to main menu...]" << std::endl;
            std::cin.get();
        }
        ClearScreen();
    }
    return 0;
}
