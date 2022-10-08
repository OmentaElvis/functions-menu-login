#include <iostream>
#include <limits>

using namespace std;


// enum for the menu options
enum menu_options {
    PATTERNS =  1,
    LOGIN    =  2,
    TERMINATE = 3
};

// Login function
void login(){
    
    // default and correct username and password
    string default_username = "Student";
    string default_pin = "1234";

    int attempts = 3;
    
    while (attempts > 0)
    {
        string username;
        string pin;

        // prompt for username
        cout<<"Enter username: ";
        cin>>username;

        // prompt for PIN
        cout<<"Enter PIN: ";
        cin>>pin;

        // check the username and password
        if (username == default_username && pin == default_pin )
        {
            cout<<"__________________\nWelcome "<<username<<endl<<endl;
            return;
        }else{
            cout<<"__________________\nWrong username or PIN "<<(attempts - 1)<<" attempt(s) remaining\n\n";
        }
        
        //decrement the number of attempts remaining
        attempts--;
    }

    // only reachable when the attempts run out
    cout<<"You are not the owner"<<endl;
    return ;

}
// Patterns function
void patterns(){

    // shapes enum
    enum {
        SQUARE = 1,
        TRIANGLE = 2
    };

    char pattern;
    int size;
    int shape;

    cout<<"Patterns"<<endl<<"__________________"<<endl;
    cout<<"Enter pattern character: ";

    // Read a single character from the console
    cin>>pattern;

    // cheeck if EOF was emcountered before we could read our pattern
    if (cin.eof())
    {
        // no character was set
        cout<<"No pattern was provided"<<endl;

        // Recall the function to force the user to re-enter the pattern
        // pattern(); // commented out due to risk of stack overflow due to infinite recursive calls
        return; // exit
    }

    /*====== Shape size ======= */
    // prompt the user to enter the shape size
    cout<<"Enter shape size: ";
    // Read the size of the pattern
    cin>>size;

    // ensure the user has input an integer instead of a string by checking for error on cin
    if(!cin){
        cout<<"Invalid size provided "<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    /*======= Shape ======= */
    //Prompt the user to select shape
    /*
        Select shape
        1. Square
        2. Triangle
        > |
    */
    cout<<"\nSelect shape\n1. Square\n2. Triangle\n> ";
    cin>>shape;

    // ensure the user has input an integer instead of a string by checking for error on cin
    if(!cin){
        cout<<"Invalid size provided "<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    switch (shape)
    {
        case SQUARE:
            // render the square shape
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    // print out the shape while accounting for the console line height with an extra space character
                    cout<<pattern<<" ";
                }
                cout<<endl;
            }

            break;
        case TRIANGLE:
            // render the triangle shape
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    // print out the shape while accounting for the console line height with an extra space character
                    cout<<pattern<<" ";
                }
                cout<<endl;
            }
            break;

        default:
            cout<<"Invalid shape selected\n";
            break;
    }
    // check if the shape size is < 0
    if(size < 0){
        cout<<"Shape size should be greater than 0"<<endl;
        return;
    }

    
    
}

//terminate the program
void terminate_program(){
    // perform stdio cleanup and terminate program with exit code 0;
    exit(0);
}

// display menu
void menu(){
    /*
        Menu
        ==========================
        1. Create Patterns
        2. Login Demo
        3. Terminate the program
        > |
    */

    cout<<endl;
    cout<<"Menu"<<endl<<"======================="<<endl;
    cout<<"1. Create Patterns"<<endl;
    cout<<"2. Login Demo"<<endl;
    cout<<"3. Terminate the program"<<endl;
    cout<<"> ";

}

int main(){

    // user input menu optio variable
    int menu_option;

    // infinately loop through the options until the user terminates the program
    while(true){
        //show the menu
        menu();

        // Read the menu option allowing only integer values
        cin>>menu_option;

        if(!cin){
            // user input non integer value e.g a string
            cout<<"\nInvalid value provided. Try again!\n";
            // clear input buffer
            cin.clear();
            // ignore non integers
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //skip current loop execution to force the user to input the option again
            continue;
        }

        // check the options provided
        switch (menu_option)
        {
            case PATTERNS:
                patterns();                     // Create patterns
                break;
            case LOGIN:
                login();                        // Login demo
                break;
            case TERMINATE:
                terminate_program();            // Exit the program
                break;
            default:
                cout<<"Invalid option "<<endl;  // Invalid option
                break;
        }
    }

    return 0;
}
// we are done here