# Aplikasi Rental Mobil Sederhana

Aplikasi manajemen rental mobil berbasis console yang dikembangkan menggunakan C++ dengan pendekatan Object Oriented Programming (OOP).

## Deskripsi Singkat

Aplikasi ini menyediakan sistem manajemen lengkap untuk bisnis rental mobil dengan fitur:
- Manajemen data kendaraan (tambah, edit, hapus, lihat)
- Manajemen data penyewa
- Transaksi penyewaan dan pengembalian kendaraan
- Perhitungan biaya sewa otomatis
- Pencarian dan filter berdasarkan tipe kendaraan
- Load dan save data ke file

## Fitur Utama

### 1. Manajemen Kendaraan
- **Tambah Mobil**: Daftarkan kendaraan baru dengan ID, model, tipe, dan tarif harian
- **Edit Mobil**: Ubah informasi kendaraan yang sudah ada
- **Hapus Mobil**: Hapus data kendaraan dari sistem
- **Lihat Semua Mobil**: Tampilkan daftar lengkap semua kendaraan
- **Lihat Mobil Tersedia**: Filter hanya kendaraan yang masih bisa disewa
- **Cari Berdasarkan Tipe**: Cari kendaraan dengan tipe tertentu (SUV, Sedan, MPV, Truck)

### 2. Manajemen Penyewa
- **Daftar Penyewa Baru**: Catat informasi penyewa baru
- **Edit Data Penyewa**: Ubah informasi penyewa
- **Hapus Data Penyewa**: Hapus data penyewa dari sistem
- **Lihat Semua Penyewa**: Tampilkan daftar semua penyewa

### 3. Transaksi Penyewaan
- **Sewa Mobil**: Catat penyewaan dengan validasi otomatis
- **Kembalikan Mobil**: Proses pengembalian kendaraan
- **Lihat Riwayat Penyewaan**: Tampilkan riwayat transaksi aktif
- **Perhitungan Biaya Otomatis**: Sistem menghitung total biaya berdasarkan durasi dan tarif

### 4. File Management
- **Load Data dari File**: Baca data kendaraan dari input.txt
- **Simpan Data ke File**: Simpan semua data ke output.txt

## Struktur Proyek

```
ProgdasUAS/
├── Car.h                    # Header file class Car
├── Car.cpp                  # Implementasi class Car
├── Renter.h                 # Header file class Renter
├── Renter.cpp               # Implementasi class Renter
├── RentalManager.h          # Header file class RentalManager
├── RentalManager.cpp        # Implementasi class RentalManager
├── main.cpp                 # Program utama dengan UI
├── input.txt                # File data sample
├── Makefile                 # Makefile untuk kompilasi
├── README.md                # File dokumentasi ini
└── LAPORAN.md               # Laporan lengkap proyek
```

## Persyaratan Sistem

- **Compiler**: GNU C++ (g++) atau compiler C++ lainnya yang mendukung C++11
- **OS**: Linux, Windows (dengan MinGW), atau macOS
- **RAM**: Minimal 256 MB
- **Disk Space**: Minimal 5 MB

## Cara Instalasi dan Menjalankan

### Opsi 1: Menggunakan Makefile (Linux/macOS)
```bash
cd ProgdasUAS
make              # Kompilasi
./rental          # Jalankan aplikasi
make clean        # Hapus file object dan executable
```

### Opsi 2: Kompilasi Manual dengan g++
```bash
g++ -std=c++11 -o rental main.cpp Car.cpp Renter.cpp RentalManager.cpp
./rental          # Linux/macOS
rental.exe        # Windows
```

### Opsi 3: Menggunakan IDE (Code::Blocks, Dev-C++, Visual Studio)
1. Buat project baru C++
2. Tambahkan semua file .cpp dan .h ke project
3. Set compiler ke g++ dengan standard C++11
4. Build dan Run

## Cara Penggunaan

Setelah menjalankan aplikasi, Anda akan melihat menu utama:

```
╔════════════════════════════════════════╗
║   APLIKASI RENTAL MOBIL SEDERHANA     ║
╚════════════════════════════════════════╝

=== MENU UTAMA ===
1. Kelola Data Mobil
2. Kelola Data Penyewa
3. Transaksi Penyewaan
4. Lihat Informasi
5. Muat Data dari File
6. Simpan Data ke File
0. Keluar

Pilihan Anda: _
```

### Contoh Penggunaan

**Menambah Mobil:**
1. Pilih menu 1 (Kelola Data Mobil)
2. Pilih sub-menu 1 (Tambah Mobil)
3. Masukkan data sesuai prompt

**Sewa Mobil:**
1. Pilih menu 3 (Transaksi Penyewaan)
2. Pilih sub-menu 1 (Sewa Mobil)
3. Masukkan ID penyewa, ID mobil, dan jumlah hari
4. Sistem akan menghitung total biaya otomatis

**Simpan Data:**
1. Pilih menu 6 (Simpan Data ke File)
2. Masukkan nama file (default: output.txt)
3. Data akan disimpan dalam format terstruktur

## Format File

### input.txt (Format: ID Model Tipe Tarif)
```
MBL001 Toyota_Avanza SUV 350000
MBL002 Honda_City Sedan 300000
MBL003 Daihatsu_Terios SUV 320000
...
```

### output.txt (Format: ID|Model|Tipe|Tarif|Status|Penyewa)
```
MBL001|Toyota Avanza|SUV|350000|0|
MBL002|Honda City|Sedan|300000|1|Rozan Gangsar
...
```

## Class Diagram

### Class Car
```
Car
├── Properties
│   ├── carID : string
│   ├── carModel : string
│   ├── carType : string
│   ├── dailyRate : long
│   ├── available : bool
│   └── currentRenter : string
└── Methods
    ├── Setter & Getter untuk semua properties
    ├── printCarInfo()
    └── printCarStatus()
```

### Class Renter
```
Renter
├── Properties
│   ├── renterID : string
│   ├── renterName : string
│   ├── phoneNumber : string
│   ├── address : string
│   ├── rentalCar : string
│   ├── rentalDays : int
│   └── totalCost : long
└── Methods
    ├── Setter & Getter untuk semua properties
    ├── printRenterInfo()
    └── printRentalDetails()
```

### Class RentalManager
```
RentalManager
├── Properties
│   ├── cars : vector<Car>
│   └── renters : vector<Renter>
├── Car Management
│   ├── addCar()
│   ├── editCar()
│   ├── deleteCar()
│   ├── viewAllCars()
│   ├── viewAvailableCars()
│   ├── findCar()
│   └── searchCarByType()
├── Renter Management
│   ├── addRenter()
│   ├── editRenter()
│   ├── deleteRenter()
│   ├── viewAllRenters()
│   └── findRenter()
├── Transaction
│   ├── rentCar()
│   ├── returnCar()
│   └── viewRentalHistory()
└── File I/O
    ├── loadFromFile()
    └── saveToFile()
```

## Fitur-Fitur Teknis

- **Vector Container**: Menggunakan `vector<Car>` dan `vector<Renter>` untuk dynamic array
- **Pointer**: Menggunakan pointer untuk return value pada fungsi pencarian
- **File Handling**: Menggunakan `ifstream` dan `ofstream` untuk baca/tulis file
- **Input Validation**: Validasi untuk mencegah duplikasi ID dan error input
- **Hierarchical Menu**: Sistem menu berlapis dengan loop untuk user experience

## Pengembangan Lebih Lanjut

Aplikasi ini dapat dikembangkan lebih lanjut dengan:
- Implementasi GUI menggunakan Qt atau WinForms
- Integrasi dengan database (MySQL, PostgreSQL)
- Sistem authentication dan user roles
- Laporan dan statistik penyewaan
- SMS/Email notification
- QR code untuk tracking kendaraan
- Mobile app version

## Testing

Aplikasi telah ditest dengan berbagai scenario:
- Tambah/Edit/Hapus data mobil dan penyewa
- Validasi duplikasi ID
- Transaksi sewa dengan perhitungan biaya
- Load/Save data dari/ke file
- Pencarian berdasarkan tipe

Semua fitur berfungsi dengan baik tanpa error fatal.

## Kontribusi

Proyek ini dikembangkan sebagai tugas mata kuliah Pemrograman Dasar di Universitas Gadjah Mada.

## Author

**Rozan Gangsar Adibrata**
- NIM: 23/521626/TK/57547
- Departemen: Teknik Elektro dan Teknologi Informasi
- Universitas: Universitas Gadjah Mada

## Lisensi

Proyek ini bebas untuk digunakan dan dimodifikasi untuk keperluan pembelajaran.

---

Untuk dokumentasi lebih lengkap, silakan lihat file **LAPORAN.md**
