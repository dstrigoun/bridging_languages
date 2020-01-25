#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }
    
    fstream file(argv[1]);

    string a;
    file >> a;

    printf("%s\n", a.c_str());

    
    
    return 0;
}