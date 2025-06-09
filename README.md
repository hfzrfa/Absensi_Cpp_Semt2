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
