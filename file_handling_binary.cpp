#include<iostream>
#include<fstream>
using namespace std;

struct PictureSettings {
    int profileID;
    int brigthness;
    int contrast;
};

int main() {
    // Data to save
    PictureSettings psw[3];
    psw[0] = {1, 50, 50};
    psw[1] = {2, 40, 70};
    psw[2] = {3, 60, 60};

    // save to file
    ofstream wfb("picture_settings.dat", ios::out | ios::binary);
    if(wfb.is_open()) {
        for(auto item : psw){
            wfb.write( (char*)&item, sizeof(item) );
        }

        wfb.close();
        if(!wfb.good()) {
            cout << "Error while writing file" << endl;
            return 1;
        }
    } else {
        cout << "Error openening file for write" << endl;
        return 1;
    }


    //container for data
    PictureSettings psr[3];

    // read file
    ifstream rfb("picture_settings.dat", ios::out | ios::binary);
    if(rfb.is_open()) {
        for(int i = 0; i < 3; i++) {
            rfb.read( (char*)&psr[i], sizeof(PictureSettings) );
        }
        rfb.close();
        if(!rfb.good()) {
            cout << "Error during reading file" << endl;
            return 1;
        }
    } else {
        cout << "Error reading file" << endl;
        return 1;
    }

    for(auto item : psr) {
        cout << "-------------" << endl;
        cout << "Profile ID: " << item.profileID << endl;
        cout << "Brightness:" << item.brigthness << endl;
        cout << "Contrast:" << item.contrast << endl;
    }
  
  return 0;
}