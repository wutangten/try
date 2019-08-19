#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int GLOBAL_SIZE=50;

//find the range of words and writes into array from file
void readFromFile(int list[], int& size, ifstream& infile){
    size=0;
    //while the file is opened
    infile>>list[size];
    while (!infile.eof()) {
    //writes file into array
        size++; //after a successful read, move the size counter over to the next item
        infile >> list[size]; //read next item from input
        }
    infile.close();
    return;
}

bool getToLastIndex(int list[], int size){
    int listArr[GLOBAL_SIZE];
    //assign 1st array into 2nd array
    for (int i=0; i<size; i++) {
        listArr[i]=list[i];
    }
    //Conditions for ture or false.
    int adjust=0, counter=0;
    while (counter<size) {
        if (listArr[counter-1]==0) {
            return false;
        }
        while (listArr[counter-1] <= listArr[counter]) {
            listArr[counter-1] = listArr[counter-1+adjust];
            if (listArr[counter-1+adjust]==0) {
                return false;
            }
            adjust++;
        }
        counter++;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    int size=0;
    int list[GLOBAL_SIZE];
    string filename;
    ifstream infile;
    do
    {
        cout << "Enter an input file: ";
        cin >> filename;
        infile.open(filename.c_str()); //attempts to open filestream
    }
    while (!infile.is_open()); //checks if the file is found */
    
    //find the range of words and writes into array from file
    readFromFile(list, size, infile);

    //Final output depends on the bool
    if (getToLastIndex(list, size)) {
        cout<<endl<<"Mario FTW"<<endl;
    }else if(!getToLastIndex(list, size)){
        cout<<endl<<"This bridge has the workings of bowser all over it >: ("<<endl;
    }

    
    return 0;
}
