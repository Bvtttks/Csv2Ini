#include "csv2ini.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        cout << "To set folder path, use --path key." << endl;
        return 1;
    }
    string str = argv[1];
    if (str != "--path") {
        cout << "To set folder path, use --path key." << endl;
        return 1;
    }
    IniConverter conv;
    conv.FolderToIni(argv[2]);
    return 0;
}
