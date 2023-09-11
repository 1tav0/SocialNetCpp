int main(){
    FileIO file;                    // FileIO object - handles loading/saving data to/from text file
    BST<User> userBST;              // Ordered User List - used for printing
    HashUser hashUser;              // Hashed Users - to search user by name
    HashInterest hashInterests;     // Hashes Interests - to search user by Interest
    HashLogin hashLogin;            // Hashed Logins - to Search users by Login + pass
    Graph userNetWork(15);          // Network of Users - used for recommended friends
    User sourceUser;                // Source User - the user currently logged in
    int input = 4;                  // Menu Selection - used to traverse the menu;
}