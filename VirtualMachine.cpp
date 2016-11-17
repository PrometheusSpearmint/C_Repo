#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    bool IN_flag = false;
    short op1, op2;
    unsigned char REG[8], MEM[32];

    ifstream bin("decryptor.bin", ios::in | ios::binary);
    for(int i = 0; i < 32; i++){
        MEM[i] = bin.get();
    } bin.close();



    return 0;
}
