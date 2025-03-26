#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string user_input;
    string file_input;

    cout << " type any text to be outputed to the fil, then press ENTER" << endl;
    getline(cin, user_input);
    cout << "You entered: " << user_input << endl;
    cout << "... writing to the file..." << endl;

    ofstream my_file_write ("output_file.txt", ios::app); //ios::app - do not owerwrite existed text, append new text.
    my_file_write << "Some text added by program." << endl;
    my_file_write << user_input << endl;
    my_file_write.close();

    cout << "... reading from file..." << endl;
    ifstream my_file_read ("output_file.txt");
    while (getline(my_file_read, file_input)){
        cout << file_input << endl;
    }
    
    my_file_read.close();

    
}