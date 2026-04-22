#include <iostream>
using namespace std;

int main() {
    char kode[9];   // kode transaksi (8 digit + null)
    int hariKode, loyalKode, belanjaUnit;
    int poin = 0;

    cout << "Masukkan kode transaksi: ";
    cin >> kode; // input kode

    // ambil kode hari (2 digit pertama)
    hariKode = (kode[0] - '0') * 10 + (kode[1] - '0');

    // ambil kode loyalitas (digit ke-3 & ke-4)
    loyalKode = (kode[2] - '0') * 10 + (kode[3] - '0');

    // ambil jumlah belanja (digit ke-5 s/d ke-8)
    belanjaUnit = (kode[4] - '0') * 1000 +
                  (kode[5] - '0') * 100 +
                  (kode[6] - '0') * 10 +
                  (kode[7] - '0');

    // validasi kodenya
    if (!((hariKode == 1 || hariKode == 2 || hariKode == 3) &&
          (loyalKode == 1 || loyalKode == 2 || loyalKode == 3))) {
        cout << "Kode tidak valid." << endl;
        return 0;
    }

    // tentukan jenis hari
    string jenisHari;
    if (hariKode == 1)
        jenisHari = "Hari kerja";
    else if (hariKode == 2)
        jenisHari = "Akhir pekan";
    else
        jenisHari = "Hari libur nasional";

    // tentukan jenis pelanggan
    string jenisPelanggan;
    if (loyalKode == 1)
        jenisPelanggan = "Pelanggan biasa";
    else if (loyalKode == 2)
        jenisPelanggan = "Member silver";
    else
        jenisPelanggan = "Member gold";

    // hitung poin
    if (hariKode == 1) { // hari kerja
        if (loyalKode == 1) poin = belanjaUnit * 1;
        else if (loyalKode == 2) poin = belanjaUnit * 2;
        else poin = belanjaUnit * 3;
    }
    else if (hariKode == 2) { // akhir pekan
        if (loyalKode == 1) poin = belanjaUnit * 2;
        else if (loyalKode == 2) poin = belanjaUnit * 3;
        else poin = belanjaUnit * 5;
    }
    else { // hari libur
        if (loyalKode == 1) poin = belanjaUnit * 3;
        else if (loyalKode == 2) poin = belanjaUnit * 5;
        else poin = belanjaUnit * 7;
    }

    // konversi belanja ke rupiah
    int totalBelanja = belanjaUnit * 100000;

    // output
    cout << "Jenis hari: " << jenisHari << endl;
    cout << "Jenis pelanggan: " << jenisPelanggan << endl;
    cout << "Jumlah belanja: Rp " << totalBelanja << endl;
    cout << "Total poin: " << poin << endl;

    return 0;
}

// di awal program saya minta input kode transaksi 8 digit
// kode ini menyimpan informasi hari, jenis pelanggan, dan jumlah belanja

// saya ambil tiap digit dari array char
// lalu saya ubah ke angka dengan cara (kode[i] - '0')

// 2 digit pertama saya gunakan untuk menentukan jenis hari
// apakah hari kerja, akhir pekan, atau hari libur nasional

// 2 digit berikutnya digunakan untuk menentukan jenis pelanggan
// yaitu pelanggan biasa, member silver, atau member gold

// 4 digit terakhir saya gabungkan menjadi jumlah belanja
// nilai ini masih dalam satuan kelipatan 100.000

// setelah itu saya cek apakah kode valid
// jika kode hari atau kode pelanggan tidak sesuai, program langsung berhenti

// jika valid, saya tentukan nama jenis hari dan jenis pelanggan
// menggunakan percabangan if else

// kemudian saya hitung poin berdasarkan kombinasi hari dan jenis pelanggan
// setiap kombinasi punya aturan poin yang berbeda

// jumlah poin dihitung dengan mengalikan unit belanja dengan poin per unit

// lalu saya konversi jumlah belanja ke rupiah (dikali 100.000)

// terakhir, semua hasil ditampilkan:
// jenis hari, jenis pelanggan, jumlah belanja, dan total poin
