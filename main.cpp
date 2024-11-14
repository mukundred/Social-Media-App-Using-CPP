
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

bool printedCredit = false; // Flag to track whether the credits have been printed

/********************************************
 *          Social Media App Credits         *
 ********************************************/
void printCredits()
{
    if (!printedCredit)
    {
        cout << setw(75) << "\n";
        cout << setw(75) << "*          Social Media App Credits         *\n";
        cout << setw(75) << "\n";
        cout << setw(75) << "*                                           *\n";
        cout << setw(75) << "*  Project: Social Media App                *\n";
        cout << setw(75) << "*  Contributors:                            *\n";
        cout << setw(75) << "*  - Mukund: Contributed significantly to   *\n";
        cout << setw(75) << "*            user registration, login, and  *\n";
        cout << setw(75) << "*            profile management and the file*\n";
        cout << setw(75) << "*            handling systems.               *\n";
        cout << setw(75) << "*  - Tushar: Contributed to the             *\n";
        cout << setw(75) << "*            implementation of posting,     *\n";
        cout << setw(75) << "*            reading posts, and following   *\n";
        cout << setw(75) << "*            users functionalities.         *\n";
        cout << setw(75) << "*  - Manas: Contributed to the development  *\n";
        cout << setw(75) << "*           of the file handling system.    *\n";
        cout << setw(75) << "*  - Moksh: Contributed to the overall      *\n";
        cout << setw(75) << "*           design and testing.             *\n";
        cout << setw(75) << "*                                           *\n";
        cout << setw(75) << "*  Version: 1.0                             *\n";
        cout << setw(75) << "*  Date: 21/04/2004                         *\n";
        cout << setw(75) << "*                                           *\n";
        cout << setw(75) << "\n";
        cout << "\n";

        printedCredit = true; // Set the flag to true to indicate credits have been printed
        cout << setw(44) << "Press Enter to continue...";
        cin.ignore(); // Clear the input buffer
        cin.get();    // Wait for Enter key press
    }
}

class User
{
private:
    string username;
    string password;
    bool isLoggedIn; // to check if user is logged in
    string nationalityFile;
    string dobFile;
    string bioFile;

public:
    User() : isLoggedIn(false) {}
    User(string u, string p) : username(u), password(encrypt(p)), isLoggedIn(false) {}

    void login();
    void registr();
    void forgot();
    void writePost();
    void readPosts();
    void followID();
    void showFollowing();
    void viewProfileAndPosts();
    void showFriends();
    void viewMyProfile();
    void editProfile();
    bool getIsLoggedIn() const { return isLoggedIn; }
    void updateNationality(const string &newValue);
    void updateDOB(const string &newValue);
    void updateBio(const string &newValue);
     void sendMessage();
    void readMessages();
     void replyToMessage(const string& sender);

private:
    string encrypt(const string &text);
    string decrypt(const string &cipherText);
};

string User::encrypt(const string &text)
{
    string encryptedText = text;
    for (char &c : encryptedText)
    {
        if (isalpha(c))
        {
            c = (c - 'a' + 3) % 26 + 'a'; // Shift each character by 3 places
        }
    }
    return encryptedText;
}

string User::decrypt(const string &cipherText)
{
    string decryptedText = cipherText;
    for (char &c : decryptedText)
    {
        if (isalpha(c))
        {
            c = (c - 'a' - 3 + 26) % 26 + 'a'; // Shift each character back by 3 places
        }
    }
    return decryptedText;
}

void User::login()
{
    int count = 0;
    string user, pass, u, p;
    system("cls");
    cout << "please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)
        {
            count = 1;
            isLoggedIn = true; // set isLoggedIn to true upon successful login
            username = u;      // set the username upon successful login
            system("cls");
            break;
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "\nHello " << user << "\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
        cin.get();
        cin.get();
    }
    else
    {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
    }

    while (input >> u >> p)
    {
        if (u == user && p == encrypt(pass))
        { // Decrypt stored password and compare
            count = 1;
            isLoggedIn = true; // set isLoggedIn to true upon successful login
            username = u;      // set the username upon successful login
            system("cls");
            break;
        }
    }
}

void User::registr()
{
    string reguser, regpass, nationality, dob, fullName, bio, gender;
    system("cls");
    cout << "Enter the following details to register:\n";
    cout << "Username :";
    cin >> reguser;
    cout << "\nPassword :";
    cin >> regpass;
    cout << "\nNationality :";
    cin.ignore();
    getline(cin, nationality);
    cout << "\nDate of Birth (DD/MM/YYYY) :";
    cin >> dob;
    cout << "\nFull Name :";
    cin.ignore();
    getline(cin, fullName);
    cout << "\nBio :";
    getline(cin, bio);
    cout << "\nGender :";
    cin >> gender;

    ofstream reg("database.txt", ios::app);
    reg << reguser << ' ' << regpass << ' ' << nationality << ' ' << dob << ' ' << fullName << ' ' << bio << ' ' << gender << endl;
    reg.close();
    system("cls");
    cout << "\nRegistration Sucessful\n";
}

void User::forgot()
{
    int ch;
    system("cls");
    cout << "Forgotten ? We're here for help\n";
    cout << "1.Search your id by username" << endl;
    cout << "2.Search your id by password" << endl;
    cout << "3.Main menu" << endl;
    cout << "Enter your choice :";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        int count = 0;
        string searchuser, su, sp;
        cout << "\nEnter your remembered username :";
        cin >> searchuser;

        ifstream searchu("database.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                count = 1;
            }
        }
        searchu.close();
        if (count == 1)
        {
            cout << "\n\nHurray, account found\n";
            cout << "\nYour password is " << sp;
            cin.get();
            cin.get();
            system("cls");
        }
        else
        {
            cout << "\nSorry, Your userID is not found in our database\n";
            cout << "\nPlease kindly contact your system administrator for more details \n";
            cin.get();
            cin.get();
        }
        break;
    }
    case 2:
    {
        int count = 0;
        string searchpass, su2, sp2;
        cout << "\nEnter the remembered password :";
        cin >> searchpass;

        ifstream searchp("database.txt");
        while (searchp >> su2 >> sp2)
        {
            if (sp2 == searchpass)
            {
                count = 1;
            }
        }
        searchp.close();
        if (count == 1)
        {
            cout << "\nYour password is found in the database \n";
            cout << "\nYour Id is : " << su2;
            cin.get();
            cin.get();
            system("cls");
        }
        else
        {
            cout << "Sorry, We cannot found your password in our database \n";
            cout << "\nkindly contact your administrator for more information\n";
            cin.get();
            cin.get();
        }
        break;
    }

    case 3:
    {
        cin.get();
    }
    default:
        cout << "Sorry, You entered wrong choice. Kindly try again" << endl;
        forgot();
    }
}

void User::writePost()
{
    if (!isLoggedIn)
    {
        cout << "Please log in first!\n";
        return;
    }
    string postContent;
    cout << "Write your post:\n";
    cin.ignore();
    getline(cin, postContent);

    ofstream postFile("posts.txt", ios::app);
    postFile << username << ": " << postContent << endl;
    postFile.close();

    cout << "\nPost added successfully!\n";
}

void User::readPosts()
{
    if (!isLoggedIn)
    {
        cout << "Please log in first!\n";
        return;
    }

    int choice;
    cout << "Choose an option:\n";
    cout << "1. View all posts\n";
    cout << "2. View posts from people you are following\n";
    cout << "Enter your choice: ";
    cin >> choice;

    string line;
    ifstream postFile("posts.txt");
    cout << "\n** Posts **\n";

    switch (choice)
    {
    case 1:
        while (getline(postFile, line))
        {
            cout << line << endl;
        }
        break;
    case 2:
    {
        ifstream followingFile("following.txt");
        string followingLine;
        vector<string> followingList;

        while (getline(followingFile, followingLine))
        {
            if (followingLine.substr(0, username.length()) == username)
            {
                followingList.push_back(followingLine.substr(username.length() + 1));
            }
        }
        followingFile.close();

        while (getline(postFile, line))
        {
            for (const auto &user : followingList)
            {
                if (line.substr(0, user.length()) == user)
                {
                    cout << line << endl;
                    break;
                }
            }
        }
    }
    break;
    default:
        cout << "Invalid choice!\n";
        break;
    }

    postFile.close();
}

void User::followID()
{
    if (!isLoggedIn)
    {
        cout << "Please log in first!\n";
        return;
    }
    string followUsername;
    cout << "Enter the username you want to follow: ";
    cin >> followUsername;

    ifstream inputFile("following.txt");
    string line;
    bool exists = false;
    while (getline(inputFile, line))
    {
        if (line == username + " " + followUsername)
        {
            exists = true;
            break;
        }
    }
    inputFile.close();

    if (exists)
    {
        cout << "\nYou are already following " << followUsername << "!\n";
        return;
    }

    ofstream outputFile("following.txt", ios::app);
    outputFile << username << " " << followUsername << endl;
    outputFile.close();

    cout << "\nYou are now following " << followUsername << "!\n";
}


void User::showFollowing()
{
    if (!isLoggedIn)
    {
        cout << "Please log in first!\n";
        return;
    }
    ifstream inputFile("following.txt");
    string line;
    int count = 0;
    cout << "\nPeople you are following:\n";
    while (getline(inputFile, line))
    {
        if (line.substr(0, username.length()) == username)
        {
            cout << line.substr(username.length() + 1) << endl;
            count++;
        }
    }
    inputFile.close();

    cout << "\nTotal number of people you are following: " << count << "\n";
}

void User::viewProfileAndPosts()
{
    if (!isLoggedIn)
    {
        cout << "Please log in first!\n";
        return;
    }

    string searchUsername;
    cout << "Enter the username you want to search for: ";
    cin >> searchUsername;

    ifstream inputFile("database.txt");
    string line;
    bool found = false;

    cout << "\nProfile and Posts of " << searchUsername << ":\n";

    while (getline(inputFile, line))
    {
        if (line.substr(0, searchUsername.length()) == searchUsername)
        {
            stringstream ss(line);
            string token;
            vector<string> tokens;
            while (ss >> token)
            {
                tokens.push_back(token);
            }

            if (tokens.size() >= 7)
            {
                cout << "Username: " << tokens[0] << endl;
                cout << "Nationality: " << tokens[2] << endl;
                cout << "Date of Birth: " << tokens[3] << endl;

                // Concatenate the full name tokens
                cout << "Full Name: ";
                for (size_t i = 4; i < tokens.size() - 2; ++i)
                {
                    cout << tokens[i];
                    if (i < tokens.size() - 3)
                        cout << " ";
                }
                cout << endl;

                // Display gender and bio
                cout << "Gender: " << tokens[tokens.size() - 1] << endl;
                cout << "Bio: " << tokens[tokens.size() - 2] << endl;
                cout << "------------------------------------------\n";
            }
            found = true;
            break;
        }
    }

    inputFile.close();

    if (!found)
    {
        cout << "No profile found for the username " << searchUsername << ".\n";
        return;
    }

    ifstream postFile("posts.txt");
    string userPost;

    cout << "\n*** Posts of " << searchUsername << " ***\n";
    cout << "------------------------------------------\n";

    while (getline(postFile, userPost))
    {
        if (userPost.substr(0, searchUsername.length()) == searchUsername)
        {
            cout << userPost << endl;
        }
    }
    postFile.close();

    if (!found)
    {
        cout << "No posts found for " << searchUsername << ".\n";
    }
}

void User::viewMyProfile()
{
    if (!isLoggedIn)
    {
        cout << "Please log in first!\n";
        return;
    }

    string searchUsername = username;
    string line;
    vector<string> userData;

    ifstream inputFile("database.txt");
    while (getline(inputFile, line))
    {
        if (line.substr(0, searchUsername.length()) == searchUsername)
        {
            userData.push_back(line);
        }
    }
    inputFile.close();

    if (userData.empty())
    {
        cout << "No profile found for the username " << username << ".\n";
        return;
    }

    cout << "\n*** My Profile ***\n";
    cout << "------------------------------------------\n";

    for (const auto &data : userData)
    {
        stringstream ss(data);
        string token;
        vector<string> tokens;
        while (ss >> token)
        {
            tokens.push_back(token);
        }

        if (tokens.size() >= 7)
        {
            cout << "Username: " << tokens[0] << endl;
            cout << "Nationality: " << tokens[2] << endl;
            cout << "Date of Birth: " << tokens[3] << endl;

            // Concatenate the full name tokens
            cout << "Full Name: ";
            for (size_t i = 4; i < tokens.size() - 2; ++i)
            {
                cout << tokens[i];
                if (i < tokens.size() - 3)
                    cout << " ";
            }
            cout << endl;

            // Display gender and bio
            cout << "Gender: " << tokens[tokens.size() - 1] << endl;
            cout << "Bio: " << tokens[tokens.size() - 2] << endl;
            cout << "------------------------------------------\n";
        }
    }

    ifstream postFile("posts.txt");
    string userPost;
    bool found = false;

    cout << "\n*** My Posts ***\n";
    cout << "------------------------------------------\n";

    while (getline(postFile, userPost))
    {
        if (userPost.substr(0, searchUsername.length()) == searchUsername)
        {
            cout << userPost << endl;
            found = true;
        }
    }
    postFile.close();

    if (!found)
    {
        cout << "No posts found for " << username << ".\n";
    }
}

void User::updateNationality(const string &newValue)
{
    ofstream outFile(nationalityFile);
    outFile << username << ' ' << newValue << endl;
    outFile.close();
}

void User::updateDOB(const string &newValue)
{
    ofstream outFile(dobFile);
    outFile << username << ' ' << newValue << endl;
    outFile.close();
}

void User::updateBio(const string &newValue)
{
    ofstream outFile(bioFile);
    outFile << username << ' ' << newValue << endl;
    outFile.close();
}

//send message fuction 

void User::sendMessage()
{
    if (!isLoggedIn)
    {
        cout << "Please log in first!\n";
        return;
    }

    string receiver;
    cout << "Enter the username of the receiver: ";
    cin >> receiver;

    cin.ignore(); // Clear the input buffer
    string messageContent;
    cout << "Enter your message:\n";
    getline(cin, messageContent);

    ofstream messageFile("messages.txt", ios::app);
    messageFile << username << " -> " << receiver << ": " << messageContent << endl;
    messageFile.close();

    cout << "\nMessage sent successfully!\n";
}

//reading message function

void User::readMessages()
{
    if (!isLoggedIn)
    {
        cout << "Please log in first!\n";
        return;
    }

    ifstream messageFile("messages.txt");
    string line;
    vector<string> receivedMessages;
    cout << "\n** Messages **\n";

    while (getline(messageFile, line))
    {
        if (line.find(" -> " + username + ": ") != string::npos)  // Check if the message was sent to the user
        {
            cout << line << endl;
            receivedMessages.push_back(line);
        }
    }

    messageFile.close();

    // Check if there are messages to reply to
    if (!receivedMessages.empty())
    {
        cout << "\nDo you want to reply to any of the messages? (yes/no): ";
        string replyChoice;
        cin >> replyChoice;

        if (replyChoice == "yes")
        {
            string sender;
            cout << "Enter the username of the sender you want to reply to: ";
            cin >> sender;
            replyToMessage(sender);
        }
    }
}

//reply to message function

void User::replyToMessage(const string& sender)
{
    cin.ignore(); // Clear the input buffer
    string replyContent;
    cout << "Enter your reply:\n";
    getline(cin, replyContent);

    ofstream messageFile("messages.txt", ios::app);
    messageFile << username << " -> " << sender << ": " << replyContent << endl;
    messageFile.close();

    cout << "\nReply sent successfully!\n";
}

int main()
{
    printCredits();
    User user;
    int choice;

    while (true)
    {
        system("cls"); // Clear screen

        cout << "\n";
        cout << "*               Welcome to the                       *\n";
        cout << "*                  Login page                        *\n";
        cout << "\n\n";

        cout << "****** MENU ********\n";
        cout << "1. LOGIN\n";
        cout << "2. REGISTER\n";
        cout << "3. FORGOT PASSWORD (or) USERNAME\n";
        cout << "4. WRITE POST\n";
        cout << "5. READ POSTS\n";
        cout << "6. FOLLOW ID\n";
        cout << "7. SHOW FOLLOWING\n";
        cout << "8. VIEW PROFILE AND POSTS\n";
        cout << "9. VIEW MY PROFILE\n";
        cout << "10. SEND MESSAGE\n";
        cout << "11. READ MESSAGES\n";
        cout << "12. LOGOUT\n";
        cout << "13. EXIT\n";
         
        cout << "\n";

        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            user.login();
            break;
        case 2:
            user.registr();
            break;
        case 3:
            user.forgot();
            break;
        case 4:
            user.writePost();
            break;
        case 5:
            user.readPosts();
            break;
        case 6:
            user.followID();
            break;
        case 7:
            user.showFollowing();
            break;
        case 8:
            user.viewProfileAndPosts();
            break;
        case 9:
            user.viewMyProfile();
            break;
        case 10:
                user.sendMessage();
                break;
            case 11:
                user.readMessages();
                break;
        case 12:
            user = User();
            cout << "Logged out successfully!\n";
            break;
        case 13:
            cout << "Thanks for using this program.\n";
            exit(0);
            
        default:
            cout << "You've made a mistake, try again..\n\n";
        }
        system("pause"); // Pause screen
    }

    return 0;
}
