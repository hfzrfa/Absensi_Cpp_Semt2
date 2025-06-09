Berikut adalah kode `README.md` untuk proyek GitHub kamu:

````markdown
# Aplikasi Absensi Mahasiswa

Aplikasi Absensi Mahasiswa ini adalah program berbasis **C++** yang memungkinkan pengguna untuk mengelola data absensi mahasiswa dengan fitur-fitur seperti menambah, mengurutkan, menyimpan, dan menghapus data absensi. Program ini menggunakan **warna teks** untuk memberikan pengalaman pengguna yang lebih menarik di terminal Windows.

## Fitur

1. **Tambah Absensi**  
   Menambahkan data absensi baru untuk mahasiswa, termasuk nama, status hadir/tidak hadir, dan tanggal absensi.

2. **Tampilkan Daftar Absensi**  
   Menampilkan semua data absensi mahasiswa yang telah dimasukkan, dengan tampilan yang rapi.

3. **Urutkan Berdasarkan Nama**  
   Mengurutkan daftar absensi berdasarkan nama mahasiswa menggunakan metode **Bubble Sort**.

4. **Urutkan Berdasarkan Tanggal**  
   Mengurutkan daftar absensi berdasarkan tanggal menggunakan metode **Bubble Sort**.

5. **Simpan Data ke File**  
   Menyimpan semua data absensi ke dalam file `absensi.txt` untuk referensi atau pemrosesan lebih lanjut.

6. **Hapus Absensi**  
   Menghapus data absensi berdasarkan ID absensi yang dimasukkan oleh pengguna.

7. **Muat Data dari File**  
   Memuat data absensi yang telah disimpan sebelumnya dari file `absensi.txt` saat program dijalankan.

## Cara Menggunakan

### Prasyarat

- **C++ Compiler** seperti **MinGW** atau **g++**.
- **Windows OS** (karena menggunakan `SetConsoleTextAttribute` untuk mengubah warna teks di terminal).

### Langkah-langkah Penggunaan

1. **Kloning Repository**  
   Pertama, kloning repositori ini ke mesin lokal Anda menggunakan perintah berikut:

   ```bash
   git clone https://github.com/username/repository-name.git
````

2. **Kompilasi Program**
   Kompilasi kode sumber `absensi.cpp` menggunakan **MinGW** atau **g++**:

   ```bash
   g++ absensi.cpp -o absensi.exe
   ```

3. **Jalankan Program**
   Setelah berhasil dikompilasi, jalankan program menggunakan perintah berikut:

   ```bash
   ./absensi.exe
   ```

   Program akan menampilkan menu utama dengan pilihan untuk menambahkan, menampilkan, mengurutkan, menyimpan, menghapus, atau keluar.

## Struktur Program

* **Absensi Struct**: Menyimpan informasi absensi, termasuk ID, nama mahasiswa, status (hadir/tidak hadir), dan tanggal absensi.
* **Fungsi-fungsi utama**:

  * `addAbsensi()`: Menambah data absensi baru.
  * `tampilkanAbsensi()`: Menampilkan seluruh data absensi.
  * `sortAbsensiByNama()`: Mengurutkan absensi berdasarkan nama mahasiswa.
  * `sortAbsensiByTanggal()`: Mengurutkan absensi berdasarkan tanggal.
  * `simpanAbsensiKeFile()`: Menyimpan data absensi ke dalam file.
  * `muatAbsensiDariFile()`: Memuat data absensi dari file.
  * `hapusAbsensi()`: Menghapus data absensi berdasarkan ID.

## Contoh Tampilan

### Menu Utama:

```
=== Menu Admin Absensi ===
1. Lihat Daftar Absensi
2. Tambah Absensi
3. Urutkan Absensi Berdasarkan Nama
4. Urutkan Absensi Berdasarkan Tanggal
5. Simpan Data Absensi ke File
6. Hapus Absensi
7. Keluar
Pilih menu:
```

### Daftar Absensi:

```
===== Daftar Absensi Mahasiswa =====
ID Absensi: 1, Nama: Hafiz, Status: Hadir, Tanggal: 10
ID Absensi: 2, Nama: Iqbal, Status: Tidak Hadir, Tanggal: 12
ID Absensi: 3, Nama: Fariz, Status: Hadir, Tanggal: 13
====================================
```

## Kontribusi

Kami sangat menghargai kontribusi dari komunitas! Jika Anda memiliki ide untuk fitur baru atau perbaikan, silakan buka **Issue** atau **Pull Request**.

## Lisensi

Proyek ini dilisensikan di bawah **MIT License**.

