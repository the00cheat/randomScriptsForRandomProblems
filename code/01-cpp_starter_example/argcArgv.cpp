/**
 * Example program to show comand line params usage and
 * the ubiquitious (or notrious) params: argc and argv
 * 
 */

#include <filesystem>  // test if file exists
#include <fstream>     // read/write to files
#include <iostream>    // read/write to stdout
#include <string>      // use strings :)

using namespace std;

int main(int argc, char **argv) {
    string line = "";

    cout << "Number of arguments passed in on command line. Remember there is always" << endl
         << "at least one param passed in, the script name!  " << endl;
    cout << argc << endl;

    cout<<endl<<endl;

    cout << "Printing out each parameter passed in on the command line: " << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] => " << argv[i] << endl;
    }

    return 0;
}