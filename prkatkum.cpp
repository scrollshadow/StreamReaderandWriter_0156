
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>

using namespace std;

class TokoElektronik {
private:
    array<string, 3> etalase;

public:
    // Constructor
    TokoElektronik() {
        etalase[0] = "Laptop ASUS";
        etalase[1] = "Smartphone Samsung";
        etalase[2] = "Headset Logitech";
    }

    // Method mengambil produk
    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        }
        catch (const out_of_range&) {
            throw string(
                "Gagal Mengambil Barang : Rak nomor "
                + to_string(nomorRak)
                + " kosong atau tidak tersedia!"
            );
        }
    }
};

// ================= FILE CRUD =================

// CREATE
void tambahBarang() {
    ofstream file("gudang.txt", ios::app);

    string barang;

    cin.ignore();

    cout << "Masukkan nama barang : ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Barang berhasil ditambahkan!\n";
}

// READ
void tampilkanBarang() {
    ifstream file("gudang.txt");

    string barang;
    int nomor = 1;

    cout << "\n===== DATA GUDANG =====\n";

    while (getline(file, barang)) {
        cout << nomor++ << ". " << barang << endl;
    }

    file.close();
}

// UPDATE
void updateBarang() {
    ifstream file("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(file, barang)) {
        data.push_back(barang);
    }

    file.close();

    tampilkanBarang();

    int index;

    cout << "\nPilih nomor barang yang ingin diupdate : ";
    cin >> index;

    cin.ignore();

    if (index < 1 || index > data.size()) {
        cout << "Data tidak ditemukan!\n";
        return;
    }

    cout << "Masukkan nama barang baru : ";
    getline(cin, barang);

    data[index - 1] = barang;

    ofstream outFile("gudang.txt");

    for (string item : data) {
        outFile << item << endl;
    }

    outFile.close();

    cout << "Data berhasil diupdate!\n";
}

// DELETE
void hapusBarang() {
    ifstream file("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(file, barang)) {
        data.push_back(barang);
    }

    file.close();

    tampilkanBarang();

    int index;

    cout << "\nPilih nomor barang yang ingin dihapus : ";
    cin >> index;

    if (index < 1 || index > data.size()) {
        cout << "Data tidak ditemukan!\n";
        return;
    }

    data.erase(data.begin() + (index - 1));

    ofstream outFile("gudang.txt");

    for (string item : data) {
        outFile << item << endl;
    }

    outFile.close();

    cout << "Data berhasil dihapus!\n";
}

// SIMULASI ETALASE
void simulasiEtalase() {
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    // Skenario 1
    try {
        cout << "Rak indeks ke-1 : ";
        cout << toko.ambilProduk(1) << endl;
    }
    catch (string error) {
        cout << error << endl;
    }

    // Skenario 2
    try {
        cout << "Rak indeks ke-5 : ";
        cout << toko.ambilProduk(5) << endl;
    }
    catch (string error) {
        cout << error << endl;
    }
}

// MAIN
int main() {

    int pilihan;

    do {

        cout << "\n============================\n";
        cout << " SISTEM TOKO GIBRAN JAYA\n";
        cout << "============================\n";
        cout << "1. Tampilkan Barang\n";
        cout << "2. Tambah Barang\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Simulasi Etalase\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            tampilkanBarang();
            break;

        case 2:
            tambahBarang();
            break;

        case 3:
            updateBarang();
            break;

        case 4:
            hapusBarang();
            break;

        case 5:
            simulasiEtalase();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak tersedia!\n";
        }

    } while (pilihan != 0);

    return 0;
}
