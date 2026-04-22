#include <iostream>
using namespace std;

int main() {
    int N;                 // jumlah babak
    char S[101];           // string hasil pertandingan
    int poinA = 0, poinB = 0; // total poin
    int streakA = 0, streakB = 0; // hitung kemenangan beruntun

    cin >> N;      // input jumlah babak
    cin >> S;      // input hasil pertandingan

    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            poinA += 3;     // A menang ? +3 poin
            streakA++;      // tambah streak A
            streakB = 0;    // reset streak B

            if (streakA == 3) {
                poinA += 2; // bonus 3 kali menang beruntun
                streakA = 0; // reset supaya hitung ulang
            }
        }
        else if (S[i] == 'B') {
            poinB += 3;     // B menang ? +3 poin
            streakB++;      // tambah streak B
            streakA = 0;    // reset streak A

            if (streakB == 3) {
                poinB += 2; // bonus
                streakB = 0;
            }
        }
        else if (S[i] == 'C') {
            poinA += 1;     // seri ? A +1
            poinB += 1;     // seri ? B +1
            streakA = 0;    // reset streak
            streakB = 0;
        }
    }

    // output poin
    cout << "Poin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;

    // menentukan pemenang
    if (poinA > poinB)
        cout << "Pemenangnya adalah pemain A";
    else if (poinB > poinA)
        cout << "Pemenangnya adalah pemain B";
    else
        cout << "Hasil pertandingan seri";

    return 0;
}

// di awal program saya minta input jumlah babak dan hasil pertandingan
// hasil pertandingan disimpan dalam array karakter (char)

// setiap karakter menunjukkan hasil satu babak:
// 'A' untuk pemain A menang, 'B' untuk pemain B menang, dan 'C' untuk seri

// saya menggunakan perulangan untuk membaca setiap hasil babak satu per satu

// jika A menang, maka poin A ditambah 3 dan streak A bertambah
// streak B akan direset karena tidak menang

// jika B menang, maka poin B ditambah 3 dan streak B bertambah
// streak A direset

// jika hasilnya seri, kedua pemain mendapat 1 poin
// dan kedua streak direset

// saya juga menyimpan jumlah kemenangan beruntun (streak)
// jika salah satu pemain menang 3 kali berturut-turut,
// maka dia mendapat bonus tambahan 2 poin

// setelah mendapatkan bonus, streak direset agar bisa dihitung lagi

// setelah semua babak selesai diproses,
// program menampilkan total poin masing-masing pemain

// terakhir, program membandingkan poin A dan B
// untuk menentukan siapa pemenang pertandingan
// jika poin sama, maka hasilnya seri
