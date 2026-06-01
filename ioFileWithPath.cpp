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

    while(true)
    {
        cout << "- ";//mendpdt setiap karakter dlm 1 baris
        getline(cin, baris);//kondisi false jika baris hanya berisi karakter q
        if (baris == "q") break;//menulis and memasukkan nilai varialbel baris kedlm file
        outfile << baris << endl;
    }

}