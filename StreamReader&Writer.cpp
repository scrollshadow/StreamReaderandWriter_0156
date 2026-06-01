#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string baris;
    ofstream outfile;
    outfile.open("contohfile.txt");
    cout << ">= Menulis file, \'q\' untuk keluar" << endl;
    while (true)
    {
        cout << "- ";//mendpdt setiap karakter dlm 1 baris
        getline(cin, baris);//kondisi false jika baris hanya berisi karakter q
        if (baris == "q") break;//menulis and memasukkan nilai varialbel baris kedlm file
        outfile << baris << endl;
    }
    outfile.close();//close jika penulisan tlh selesai

    ifstream infile;
    infile.open("contohfile.txt");
    
}