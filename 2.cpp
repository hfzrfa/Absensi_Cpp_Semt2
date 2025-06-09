#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>  // Untuk manipulasi lebar kolom

using namespace std;

struct Absensi {
    int idAbsensi;
    string nama;
    string status; // "Hadir" atau "Tidak Hadir"
    string tanggal; // Tanggal absensi (format: DD-MM-YYYY)
};

Absensi daftarAbsensi[100];  // Menyimpan daftar absensi mahasiswa, dengan kapasitas 100 data
int jumlahAbsensi = 0; // Jumlah data absensi yang telah dimasukkan
int idAbsensi = 1; // ID absensi pertama

// Fungsi untuk mengubah warna teks di terminal (untuk Windows)
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Fungsi untuk menambah absensi mahasiswa
void addAbsensi(Absensi &absensi) {
    absensi.idAbsensi = idAbsensi;  // Set ID absensi yang baru

    setColor(10);  // Mengubah warna teks menjadi hijau
    cout << "Masukkan Nama Mahasiswa: ";
    setColor(15);  // Kembali ke warna teks standar
    cin.ignore();  // Membersihkan buffer input
    getline(cin, absensi.nama);

    setColor(10);
    cout << "Status (Hadir/Tidak Hadir): ";
    setColor(15);
    cin >> absensi.status;

    setColor(10);
    cout << "Masukkan Tanggal Absensi: ";
    setColor(15);
    cin >> absensi.tanggal;

    daftarAbsensi[jumlahAbsensi] = absensi;  // Menambahkan absensi mahasiswa ke daftar
    jumlahAbsensi++;  // Meningkatkan jumlah absensi yang telah dimasukkan
    idAbsensi++;  // Increment ID untuk absensi berikutnya
}

// Fungsi untuk menampilkan daftar absensi
void tampilkanAbsensi() {
    if (jumlahAbsensi == 0) {
        setColor(12);  // Merah untuk menandakan tidak ada data
        cout << "Belum ada data absensi.\n";
        setColor(15);
        return;
    }

    setColor(14);  // Kuning
    cout << "\n===== Daftar Absensi Mahasiswa =====\n";
    setColor(15);  // Warna teks normal
    for (int i = 0; i < jumlahAbsensi; i++) {
        cout << "ID Absensi: " << daftarAbsensi[i].idAbsensi << ", Nama: " << daftarAbsensi[i].nama 
             << ", Status: " << daftarAbsensi[i].status << ", Tanggal: " << daftarAbsensi[i].tanggal << endl;
    }
    setColor(14);
    cout << "====================================\n";
    setColor(15);  // Kembali ke warna teks normal
}

// Fungsi untuk mengurutkan absensi berdasarkan nama mahasiswa menggunakan Bubble Sort
void sortAbsensiByNama() {
    for (int i = 0; i < jumlahAbsensi - 1; i++) {
        for (int j = i + 1; j < jumlahAbsensi; j++) {
            if (daftarAbsensi[i].nama > daftarAbsensi[j].nama) {
                // Menukar data absensi jika urutannya salah
                Absensi temp = daftarAbsensi[i];
                daftarAbsensi[i] = daftarAbsensi[j];
                daftarAbsensi[j] = temp;
            }
        }
    }
    setColor(10);  // Hijau
    cout << "Absensi telah diurutkan berdasarkan nama mahasiswa.\n";
    setColor(15);  // Kembali ke warna teks normal
}

// Fungsi untuk mengurutkan absensi berdasarkan tanggal absensi menggunakan Bubble Sort
void sortAbsensiByTanggal() {
    for (int i = 0; i < jumlahAbsensi - 1; i++) {
        for (int j = i + 1; j < jumlahAbsensi; j++) {
            // Membandingkan tanggal (DD-MM-YYYY)
            if (daftarAbsensi[i].tanggal > daftarAbsensi[j].tanggal) {
                // Menukar data absensi jika urutannya salah
                Absensi temp = daftarAbsensi[i];
                daftarAbsensi[i] = daftarAbsensi[j];
                daftarAbsensi[j] = temp;
            }
        }
    }
    setColor(10);  // Hijau
    cout << "Absensi telah diurutkan berdasarkan tanggal absensi.\n";
    setColor(15);  // Kembali ke warna teks normal
}

// Fungsi untuk menyimpan daftar absensi ke dalam file
void simpanAbsensiKeFile() {
    ofstream file("./absensi.txt");  // Tanda titik berarti di direktori yang sama dengan program

    if (!file) {
        setColor(12);  // Merah untuk menandakan kesalahan
        cout << "Gagal membuka file untuk menyimpan data.\n";
        setColor(15);
        return;
    }

    for (int i = 0; i < jumlahAbsensi; i++) {
        file << daftarAbsensi[i].idAbsensi << "\n"
             << daftarAbsensi[i].nama << "\n"
             << daftarAbsensi[i].status << "\n"
             << daftarAbsensi[i].tanggal << "\n";
    }

    file.close();
    setColor(10);  // Hijau
    cout << "Data absensi telah disimpan ke dalam file absensi.txt\n";
    setColor(15);  // Kembali ke warna teks normal
}

// Fungsi untuk memuat daftar absensi dari file
void muatAbsensiDariFile() {
    ifstream file("absensi.txt");
    if (!file) {
        setColor(12);  // Merah untuk menandakan kesalahan
        cout << "Tidak ada data absensi yang ditemukan.\n";
        setColor(15);
        return;
    }

    Absensi absensi;
    while (file >> absensi.idAbsensi) {
        file.ignore(); // Mengabaikan newline setelah idAbsensi
        getline(file, absensi.nama);
        getline(file, absensi.status);
        getline(file, absensi.tanggal);
        
        daftarAbsensi[jumlahAbsensi] = absensi;
        jumlahAbsensi++;

        idAbsensi = absensi.idAbsensi + 1; // Set ID Absensi berikutnya berdasarkan ID terakhir
    }

    file.close();
    setColor(10);  // Hijau
    cout << "Data absensi telah dimuat dari file absensi.txt\n";
    setColor(15);  // Kembali ke warna teks normal
}

// Fungsi untuk menghapus absensi berdasarkan ID
void hapusAbsensi() {
    int id;
    setColor(12);  // Merah
    cout << "Masukkan ID Absensi yang ingin dihapus: ";
    setColor(15);  // Kembali ke warna teks normal
    cin >> id;

    bool ditemukan = false;
    for (int i = 0; i < jumlahAbsensi; i++) {
        if (daftarAbsensi[i].idAbsensi == id) {
            // Menghapus data dengan menggeser data setelahnya ke depan
            for (int j = i; j < jumlahAbsensi - 1; j++) {
                daftarAbsensi[j] = daftarAbsensi[j + 1];
            }
            jumlahAbsensi--; // Mengurangi jumlah absensi
            ditemukan = true;
            break;
        }
    }

    // Setelah penghapusan, perbarui ID Absensi
    if (ditemukan) {
        // Set ulang ID Absensi dari 1
        for (int i = 0; i < jumlahAbsensi; i++) {
            daftarAbsensi[i].idAbsensi = i + 1; // Mengatur ID absensi dimulai dari 1
        }
        setColor(10);  // Hijau
        cout << "Absensi dengan ID " << id << " telah dihapus.\n";
        setColor(15);  // Kembali ke warna teks normal
    } else {
        setColor(12);  // Merah
        cout << "ID Absensi tidak ditemukan.\n";
        setColor(15);  // Kembali ke warna teks normal
    }
}

int main() {
    Absensi absensi;
    int choice;

    // Memuat data absensi jika file ada
    muatAbsensiDariFile();

    do {
        setColor(14);  // Kuning untuk tampilan menu
        cout << "\n=== Menu Admin Absensi ===\n";
        setColor(15);  // Kembali ke warna teks normal
        cout << "1. Lihat Daftar Absensi\n";
        cout << "2. Tambah Absensi\n";
        cout << "3. Urutkan Absensi Berdasarkan Nama\n";
        cout << "4. Urutkan Absensi Berdasarkan Tanggal\n";
        cout << "5. Simpan Data Absensi ke File\n";
        cout << "6. Hapus Absensi\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tampilkanAbsensi();
                break;
            case 2:
                addAbsensi(absensi);
                break;
            case 3:
                sortAbsensiByNama();
                break;
            case 4:
                sortAbsensiByTanggal();
                break;
            case 5:
                simpanAbsensiKeFile();
                break;
            case 6:
                hapusAbsensi();
                break;
            case 7:
                setColor(12);  // Merah untuk keluar
                cout << "Keluar dari program.\n";
                setColor(15);  // Kembali ke warna teks normal
                break;
            default:
                setColor(12);  // Merah untuk pilihan yang salah
                cout << "Pilihan tidak valid.\n";
                setColor(15);  // Kembali ke warna teks normal
        }

    } while (choice != 7);

    return 0;
}
