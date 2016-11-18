#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int to_dec(string str){
    int temp = 0;
    for(int i = str.length(); i > 0; i--){
        if(str[i] == '1') temp += pow(2, i);
    }
    return temp;
}

void LSR(unsigned char& OP)
{
    string r;
    int n = (int)OP;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    for(int i = r.length(); i >=0; i--){
        if(i = 0){
            r[i] = '0';
        }else r[i] = r[i-1];
    }
    OP = (unsigned char)to_dec(r);
}

void LSL(unsigned char& OP)
{
    string r;
    int n = (int)OP;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    for(int i = 0; i < r.length(); i++){
        if(i = r.length()-1){
            r[i] = '0';
        }else r[i] = r[i+1];
    }
    OP = (unsigned char)to_dec(r);
}

void to_op(unsigned char OP, int& op1, int& op2)
{
    int n = (int)OP;
    string r, op;

    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    for(int i = 0; i < 4; i++){
        op = r[i] + op;
    }
    op2 = to_dec(op);
    for(int i = 4; i < 8; i++){
        op = r[i] + op;
    }
    op1 = to_dec(op);
}

int main()
{
    int temp;
    bool RET = false, IN_flag = false;
    int op1, op2;
    unsigned char REG[8] = {0}, MEM[32] = {0};

    ifstream bin("decryptor.bin", ios::in | ios::binary);
    for(int i = 0; i < 32; i++){
        MEM[i] = bin.get();
        cout << (int)MEM[i] << " ";
    } bin.close();

    /*int memptr = 0;
    while(!RET){
        switch((int)MEM[memptr])
        {
        case 1:
            to_op(MEM[memptr+1], op1, op2);
            temp = (int)REG[op1];
            temp++;
            REG[op1] = (unsigned char)temp;
            break;
        case 2:
            to_op(MEM[memptr+1], op1, op2);
            temp = (int)REG[op1];
            temp--;
            REG[op1] = (unsigned char)temp;
            break;
        case 3:
            to_op(MEM[memptr+1], op1, op2);
            REG[op1] = REG[op2];
            break;
        case 4:
            REG[0] = MEM[memptr+1];
            break;
        case 5:
            to_op(MEM[memptr+1], op1, op2);
            LSL(REG[op1]);
            break;
        case 6:
            to_op(MEM[memptr+1], op1, op2);
            LSR(REG[op1]);
            break;
        case 7:
            memptr += MEM[memptr+1];
            break;
        case 10:
            to_op(MEM[memptr+1], op1, op2);
            break;
        case 11:
            to_op(MEM[memptr+1], op1, op2);
            break;
        case 12:
            to_op(MEM[memptr+1], op1, op2);
            break;
        case 13:
            to_op(MEM[memptr+1], op1, op2);
            break;
        case 14:
            to_op(MEM[memptr+1], op1, op2);
            break;
        case 15:
            to_op(MEM[memptr+1], op1, op2);
            break;
        case 16:
            to_op(MEM[memptr+1], op1, op2);
            break;
        case 17:
            to_op(MEM[memptr+1], op1, op2);
            break;
        }
    }
    */
    return 0;
}
