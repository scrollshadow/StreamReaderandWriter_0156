#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string baris, Namafile;
    cout << "Masukan nama file : ";
    cin >> Namafile;

    ofstream outfile;
    outfile.open(Namafile + ".txt", ios::out);
    cout << ">= Menulis file, \'q\' Untuk kluar" << endl;

}