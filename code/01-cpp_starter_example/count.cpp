/**
 * Example program to count lines words and characters in a file.
 * 
 */

#include <filesystem>  // test if file exists
#include <fstream>     // read/write to files
#include <iostream>    // read/write to stdout
#include <string>      // use strings :)
#include <vector>

using namespace std;

// original split function I found somewhere
vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

// simplified version to return count of words (kind of) in a string.
int splitCount(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res.size();
}


int main(int argc, char **argv) {
    string line = "";
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    // check to make sure there are is a parameter on command line.
    if (argc > 1) {
        // check to see if file exists
        if (std::filesystem::exists(argv[1])) {
            ifstream fin;
            fin.open(argv[1]);

            while (!fin.eof()) {
                getline(fin, line);
                lineCount++;
                //cout << line << endl;
                wordCount += splitCount(line," ");
                charCount += line.length();
                
            }
        }
    }

    cout<<"Lines: "<<lineCount<<" Words: "<<wordCount<<" Chars: "<<charCount+lineCount<<endl;

    return 0;
}