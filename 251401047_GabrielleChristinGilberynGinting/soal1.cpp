#include <iostream>
#include <string>    
using namespace std;

int main() {
    string NK, jenisKartu;  
    int panjang, total = 0; 

    cout << "Masukkan nomor kartu digital: ";
    cin >> NK;

    panjang = NK.length();        // hitung panjang kartu
    string awalan = NK.substr(0, 2); // ambil 2 digit awal

    // untuk menentukan jenis kartu
    if (panjang == 14 && awalan == "65") {
        jenisKartu = "NUSANTARA";
    }
    else if (panjang == 16 && (awalan == "77" || awalan == "78")) {
        jenisKartu = "GARUDA";
    }
    else if (panjang == 15 && awalan == "91") {
        jenisKartu = "MERDEKA";
    }
    else {
        jenisKartu = "TIDAK DIKENAL"; // jika tidak sesuai pola
    }

    cout << "Tipe kartu: " << jenisKartu << endl;

    if (jenisKartu == "TIDAK DIKENAL") { // jika kartu tidak dikenali
        cout << "Nomor kartu TIDAK VALID." << endl;
        return 0; // program selesai
    }

    // proses validasi (algoritma Luhn)
    for (int i = panjang - 1; i >= 0; i--) { // loop dari belakang
        int angka = NK[i] - '0'; // ubah char ke angka

        if ((panjang - i) % 2 == 0) { // posisi selang-seling
            angka *= 2; // dikali 2
            if (angka > 9)
                angka = (angka / 10) + (angka % 10); // jumlah digit
        }

        total += angka; // tambahkan ke total
    }

    if (total % 10 == 0) // cek kelipatan 10
        cout << "Nomor kartu VALID." << endl;
    else
        cout << "Nomor kartu TIDAK VALID." << endl;

    return 0; // akhir program
}

// di awal program saya langsung minta input nomor kartu dalam bentuk string
// supaya setiap digitnya bisa diakses satu per satu

// lalu saya ambil panjang kartu dan 2 digit awal (awalan)
// ini digunakan untuk menentukan jenis kartu (NUSANTARA, GARUDA, atau MERDEKA)

// kalau panjang dan awalan tidak sesuai aturan
// maka kartu dianggap "TIDAK DIKENAL" dan otomatis tidak valid

// untuk algoritma validasi, saya menggunakan versi sederhana dari algoritma luhn
// dan saya satukan dalam satu perulangan supaya lebih efisien

// perulangan ini:
// for (int i = panjang - 1; i >= 0; i--)
// digunakan untuk membaca digit dari belakang ke depan

// untuk digit selang-seling dari belakang (digit ke-2, ke-4, dst)
// nilainya saya kalikan 2

// jika hasil perkalian lebih dari 9
// maka digitnya dijumlahkan (contoh: 12 jadi 1 + 2)

// semua nilai kemudian dijumlahkan ke dalam variabel total

// terakhir, dicek apakah total habis dibagi 10
// jika iya berarti kartu valid, jika tidak berarti tidak valid
