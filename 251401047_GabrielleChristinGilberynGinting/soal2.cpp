#include <iostream>
using namespace std;

int main() {
    char kode[11];   // menyimpan 10 digit kode parkir
    int jamKeluar;   // input jam keluar (HHMM)

    int jenisKode, jamMasuk, lokasi;
    int jmMasuk, mnMasuk, jmKeluar, mnKeluar;
    int lamaJam, biaya = 0;

    cout << "Masukkan kode parkir: ";
    cin >> kode;

    cout << "Masukkan jam keluar: ";
    cin >> jamKeluar;

    // ambil 2 digit pertama (jenis kendaraan)
    jenisKode = (kode[0] - '0') * 10 + (kode[1] - '0');

    // ambil waktu masuk (HHMM)
    jamMasuk = (kode[2] - '0') * 1000 +
               (kode[3] - '0') * 100 +
               (kode[4] - '0') * 10 +
               (kode[5] - '0');

    // ambil lokasi parkir
    lokasi = (kode[6] - '0') * 1000 +
             (kode[7] - '0') * 100 +
             (kode[8] - '0') * 10 +
             (kode[9] - '0');

    // tentukan jenis kendaraan
    string jenis;
    if (jenisKode == 10)
        jenis = "Mobil pribadi";
    else if (jenisKode == 20)
        jenis = "Motor";
    else if (jenisKode == 30)
        jenis = "Bus";
    else
        jenis = "Tidak diketahui";

    // pisahkan jam & menit masuk
    jmMasuk = jamMasuk / 100;
    mnMasuk = jamMasuk % 100;

    // pisahkan jam & menit keluar
    jmKeluar = jamKeluar / 100;
    mnKeluar = jamKeluar % 100;

    // ubah ke menit total
    int totalMasuk = jmMasuk * 60 + mnMasuk;
    int totalKeluar = jmKeluar * 60 + mnKeluar;

    int selisih = totalKeluar - totalMasuk;

    // pembulatan ke atas (jam)
    lamaJam = (selisih + 59) / 60;

    // hitung biaya
    if (jenisKode == 10) {
        biaya = 5000;
        if (lamaJam > 1)
            biaya += (lamaJam - 1) * 3000;
    }
    else if (jenisKode == 20) {
        biaya = 3000;
        if (lamaJam > 1)
            biaya += (lamaJam - 1) * 2000;
    }
    else if (jenisKode == 30) {
        biaya = 10000;
        if (lamaJam > 1)
            biaya += (lamaJam - 1) * 7000;
    }

    // OUTPUT (format waktu sudah HH:MM)
    cout << "Jenis kendaraan: " << jenis << endl;

    cout << "Waktu masuk: "
         << jmMasuk << ":"
         << (mnMasuk < 10 ? "0" : "") << mnMasuk << endl;

    cout << "Waktu keluar: "
         << jmKeluar << ":"
         << (mnKeluar < 10 ? "0" : "") << mnKeluar << endl;

    cout << "Lokasi parkir: " << lokasi << endl;
    cout << "Lama parkir: " << lamaJam << " jam" << endl;
    cout << "Total biaya: Rp " << biaya << endl;

    return 0;
}

// di awal program saya minta input kode parkir 10 digit dan jam keluar
// kode disimpan dalam bentuk array karakter (char), bukan string

// karena tidak pakai string, saya ambil tiap digit langsung dari index array
// misalnya kode[0], kode[1], dan seterusnya

// untuk menentukan jenis kendaraan, saya ambil 2 digit pertama
// lalu saya ubah ke angka dengan (kode[i] - '0') supaya bisa dihitung

// untuk waktu masuk (digit ke-3 sampai ke-6), saya gabungkan manual
// dengan cara mengalikan setiap digit sesuai posisinya (ribuan, ratusan, dll)

// hal yang sama juga saya lakukan untuk lokasi parkir (4 digit terakhir)

// setelah itu, saya gunakan percabangan if else
// untuk menentukan jenis kendaraan (mobil, motor, atau bus)

// waktu masuk dan keluar dipisahkan menjadi jam dan menit
// menggunakan operasi bagi 100 dan modulus 100

// lalu waktu diubah ke menit total
// supaya lebih mudah saat menghitung selisih waktu

// selisih waktu dihitung dari total keluar dikurangi total masuk

// untuk lama parkir, saya ubah ke jam dengan pembulatan ke atas
// supaya jika ada sisa menit tetap dihitung 1 jam

// setelah itu saya hitung biaya parkir berdasarkan jenis kendaraan
// karena tiap jenis punya tarif yang berbeda

// saat menampilkan waktu, saya tambahkan tanda ":"
// dan memastikan menit tetap 2 digit (misalnya 05, bukan 5)

// terakhir, semua hasil ditampilkan:
// jenis kendaraan, waktu masuk, waktu keluar, lokasi, lama parkir, dan total biaya
