#include <iostream>
using namespace std;

int main() {
    char NK[20];   // menyimpan nomor kartu
    int panjang = 0, total = 0;

    cout << "Masukkan nomor kartu digital: ";
    cin >> NK;

    while (NK[panjang] != '\0') {
        panjang++;
    }

    // cek jenis kartu berdasarkan panjang & awalan
    if (panjang == 14 && NK[0] == '6' && NK[1] == '5') {
        cout << "Tipe kartu: NUSANTARA" << endl;
    }
    else if (panjang == 16 &&
            ((NK[0] == '7' && NK[1] == '7') ||
             (NK[0] == '7' && NK[1] == '8'))) {
        cout << "Tipe kartu: GARUDA" << endl;
    }
    else if (panjang == 15 && NK[0] == '9' && NK[1] == '1') {
        cout << "Tipe kartu: MERDEKA" << endl;
    }
    else {
        cout << "Tipe kartu: TIDAK DIKENAL" << endl;
        cout << "Nomor kartu TIDAK VALID." << endl;
        return 0;
    }

    // algoritma Luhn
    for (int i = panjang - 1; i >= 0; i -= 2) {
        total += NK[i] - '0'; // ambil digit langsung
    }

    for (int i = panjang - 2; i >= 0; i -= 2) {
        int angka = (NK[i] - '0') * 2;
        if (angka > 9)
            angka = (angka / 10) + (angka % 10);
        total += angka;
    }

    // cek validasi
    if (total % 10 == 0)
        cout << "Nomor kartu VALID." << endl;
    else
        cout << "Nomor kartu TIDAK VALID." << endl;

    return 0;
}

// di awal program saya minta input nomor kartu digital
// nomor kartu disimpan dalam bentuk array karakter (char)

// saya menghitung panjang kartu secara manual
// dengan membaca satu per satu sampai menemukan '\0'

// setelah panjang didapat, saya cek jenis kartu
// berdasarkan jumlah digit dan 2 digit awal kartu

// pengecekan awalan dilakukan langsung dengan membandingkan karakter,
// misalnya NK[0] == '6' dan NK[1] == '5'

// jika tidak memenuhi salah satu kondisi,
// maka kartu dianggap tidak dikenal dan langsung dinyatakan tidak valid

// jika jenis kartu valid, program lanjut ke proses algoritma luhn

// pada perulangan pertama, saya menjumlahkan digit dari belakang
// dengan selang satu digit (kanan ke kiri)

// pada perulangan kedua, digit yang tersisa saya kalikan 2
// jika hasilnya lebih dari 9, maka dijumlahkan kembali per digit

// setiap digit diubah dari karakter ke angka menggunakan (NK[i] - '0')
// karena input awal berupa ASCII, bukan angka langsung

// setelah semua digit diproses, total akan dicek
// jika total habis dibagi 10, maka kartu dinyatakan valid

// jika tidak habis dibagi 10, maka kartu tidak valid

// terakhir, program menampilkan hasil tipe kartu dan status validasinya
