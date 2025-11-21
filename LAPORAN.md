# LAPORAN PROYEK MATA KULIAH PEMROGRAMAN DASAR
## SEMESTER GASAL 2025/2026

---

## Judul Proyek
**Aplikasi Rental Mobil Sederhana dengan Pendekatan Object Oriented Programming**

---

## Anggota Tim
1. Rozan Gangsar Adibrata | No. Mhs: 23/521626/TK/57547

---

### Departemen Teknik Elektro dan Teknologi Informasi
### Fakultas Teknik
### Universitas Gadjah Mada
### 2025

---

## 1. DESKRIPSI APLIKASI

### 1.1 Latar Belakang
Industri rental kendaraan berkembang pesat di Indonesia. Namun, masih banyak perusahaan rental yang menggunakan sistem manual dalam mengelola data kendaraan dan penyewa. Hal ini dapat menyebabkan kesalahan pencatatan, kesulitan dalam tracking kendaraan, dan proses transaksi yang lambat.

Pada proyek ini dikembangkan aplikasi Rental Mobil Sederhana yang mencakup analisis dan desain menggunakan pendekatan Object Oriented Programming (OOP). Aplikasi ini dirancang untuk membantu dalam mengelola data kendaraan, data penyewa, dan transaksi penyewaan dengan lebih efisien dan terstruktur.

### 1.2 Tujuan Aplikasi
Aplikasi Rental Mobil Sederhana bertujuan untuk:
- Mengelola data kendaraan (mobil) dengan fitur tambah, edit, hapus, dan lihat
- Mengelola data penyewa dengan informasi lengkap
- Mencatat transaksi penyewaan dan pengembalian kendaraan
- Menyediakan pencarian dan filter data berdasarkan kategori
- Memuat dan menyimpan data ke file eksternal
- Menghitung biaya penyewaan secara otomatis

### 1.3 Fitur Utama Aplikasi
Aplikasi ini menyediakan beberapa fitur utama:

**Untuk Kendaraan (Car):**
- Menambahkan data kendaraan baru
- Mengedit data kendaraan yang sudah ada
- Menghapus data kendaraan
- Melihat semua kendaraan
- Melihat kendaraan yang tersedia
- Mencari kendaraan berdasarkan tipe

**Untuk Penyewa (Renter):**
- Mendaftarkan penyewa baru
- Mengedit data penyewa
- Menghapus data penyewa
- Melihat semua data penyewa

**Untuk Transaksi:**
- Mencatat penyewaan kendaraan
- Mencatat pengembalian kendaraan
- Melihat riwayat penyewaan
- Menghitung biaya penyewaan otomatis

**File Management:**
- Memuat data dari file input (input.txt)
- Menyimpan data ke file output (output.txt)

---

## 2. ANALISIS KEBUTUHAN

### 2.1 Kebutuhan Fungsional

| Req-ID | Kebutuhan Fungsional | Deskripsi |
|--------|----------------------|-----------|
| F-01 | Register new car | Fitur untuk menambahkan data mobil baru dengan ID, model, tipe, dan tarif harian |
| F-02 | Edit car data | Fitur untuk mengubah data mobil yang sudah ada |
| F-03 | Delete car data | Fitur untuk menghapus data mobil dari sistem |
| F-04 | View all cars | Fitur untuk menampilkan semua data mobil yang ada |
| F-05 | View available cars | Fitur untuk menampilkan mobil yang masih tersedia untuk disewa |
| F-06 | Search cars by type | Fitur untuk mencari mobil berdasarkan tipe (SUV, Sedan, MPV, Truck) |
| F-07 | Register new renter | Fitur untuk mendaftarkan penyewa baru dengan informasi lengkap |
| F-08 | Edit renter data | Fitur untuk mengubah data penyewa |
| F-09 | Delete renter data | Fitur untuk menghapus data penyewa |
| F-10 | View all renters | Fitur untuk menampilkan semua data penyewa |
| F-11 | Rent a car | Fitur untuk mencatat transaksi penyewaan mobil |
| F-12 | Return a car | Fitur untuk mencatat pengembalian mobil |
| F-13 | View rental history | Fitur untuk melihat riwayat penyewaan |
| F-14 | Load data from file | Fitur untuk membaca data kendaraan dari file input.txt |
| F-15 | Save data to file | Fitur untuk menyimpan data ke file output.txt |

### 2.2 Kebutuhan Non-Fungsional

**a) Pilihan Tool dan Platform:**
- **IDE/Editor:** Code::Blocks, Dev-C++, atau Visual Studio Code
- **Compiler:** GNU C++ Compiler (g++)
- **UML Tool:** Lucidchart, Draw.io, atau ArgoUML
- **Format Laporan:** Microsoft Word atau Markdown

**b) Bahasa Pemrograman:**
- Bahasa pemrograman: C++ (C++11 atau lebih baru)
- Standard Library: STL (Standard Template Library) untuk vector
- File I/O: iostream, fstream

**c) Keterbatasan Sumber Daya:**
- Waktu pengerjaan: Semester gasal 2025/2026
- Ukuran data: Tidak ada batasan jumlah kendaraan atau penyewa (tergantung RAM)
- User Interface: Console-based (command-line interface)
- Performance: Optimal untuk operasi CRUD dengan data kurang dari 1000 entri

**d) Pembagian Tugas:**
- Rozan Gangsar Adibrata: Analisis, desain UML, implementasi kode C++, testing, dan pembuatan laporan

---

## 3. PEMODELAN DAN PERANCANGAN SISTEM

### 3.1 Use Case Diagram

```
┌─────────────────────────────────────────────────┐
│                   Actor: User                   │
└──────────────────────┬──────────────────────────┘
                       │
         ┌─────────────┼─────────────┐
         │             │             │
      ┌──▼──┐    ┌──────▼────┐  ┌──▼────┐
      │ Car │    │  Renter   │  │Rental │
      │  UC │    │    UC     │  │  UC   │
      └─────┘    └───────────┘  └───────┘
         │             │             │
         │             │             │
    ┌────┴──────────┬──┴──────────┬─┴────────┐
    │               │             │          │
┌───▼──┐  ┌────────▼──┐  ┌──────▼──┐  ┌───▼───┐
│Create│  │  Read     │  │ Update  │  │Delete │
│      │  │           │  │         │  │       │
└──────┘  └───────────┘  └─────────┘  └───────┘

┌──────────────────────────────────────┐
│      File I/O Use Cases              │
├──────────────────────────────────────┤
│  - Load Data from File (input.txt)   │
│  - Save Data to File (output.txt)    │
└──────────────────────────────────────┘
```

### 3.2 Use Case Skenario

**F-01: Register New Car**
1. User memilih menu "Tambah Mobil"
2. Sistem meminta input data: ID, Model, Tipe, Tarif Harian
3. User memasukkan data mobil baru
4. Sistem memvalidasi ID (tidak boleh duplikat)
5. Sistem menyimpan data mobil ke dalam list
6. Sistem menampilkan pesan "Mobil berhasil ditambahkan"

**F-02: Edit Car Data**
1. User memilih menu "Edit Mobil"
2. Sistem meminta ID mobil yang akan diedit
3. User memasukkan ID
4. Sistem mencari mobil dengan ID tersebut
5. Jika ditemukan, sistem menampilkan data lama
6. User memasukkan data baru
7. Sistem memperbarui data
8. Sistem menampilkan pesan "Data berhasil diperbarui"

**F-03: Delete Car Data**
1. User memilih menu "Hapus Mobil"
2. Sistem meminta ID mobil yang akan dihapus
3. User memasukkan ID
4. Sistem mencari dan menghapus data
5. Sistem menampilkan pesan "Mobil berhasil dihapus"

**F-04: View All Cars**
1. User memilih menu "Lihat Semua Mobil"
2. Sistem menampilkan daftar lengkap semua mobil dengan detail: ID, Model, Tipe, Tarif, Status
3. Jika tidak ada data, tampilkan "Tidak ada data"

**F-11: Rent a Car**
1. User memilih menu "Sewa Mobil"
2. Sistem meminta ID Penyewa dan ID Mobil
3. User memasukkan ID
4. Sistem melakukan validasi:
   - Penyewa ada di database
   - Mobil ada di database
   - Mobil tersedia (belum disewa)
5. User memasukkan jumlah hari sewa
6. Sistem menghitung total biaya = hari × tarif harian
7. Sistem mengubah status mobil menjadi "Sedang Disewa"
8. Sistem menyimpan informasi penyewaan
9. Sistem menampilkan detail penyewaan dan total biaya

**F-12: Return a Car**
1. User memilih menu "Kembalikan Mobil"
2. Sistem meminta ID mobil yang dikembalikan
3. User memasukkan ID
4. Sistem memvalidasi status mobil (sedang disewa)
5. Sistem mengubah status mobil menjadi "Tersedia"
6. Sistem menampilkan pesan pengembalian berhasil

**F-14: Load Data from File**
1. User memilih menu "Muat Data dari File"
2. Sistem meminta nama file (default: input.txt)
3. Sistem membuka file dan membaca data
4. Sistem mem-parse setiap baris dan membuat object Car
5. Sistem menyimpan data ke dalam vector cars
6. Sistem menampilkan pesan "Data berhasil dimuat"

**F-15: Save Data to File**
1. User memilih menu "Simpan Data ke File"
2. Sistem meminta nama file (default: output.txt)
3. Sistem membuka file untuk penulisan
4. Sistem menulis semua data car dengan format tertentu
5. Sistem menulis semua data renter
6. Sistem menutup file
7. Sistem menampilkan pesan "Data berhasil disimpan"

### 3.3 Class Diagram

```
┌────────────────────────────────────┐
│          Car Class                 │
├────────────────────────────────────┤
│ - carID : string                   │
│ - carModel : string                │
│ - carType : string                 │
│ - dailyRate : long                 │
│ - available : bool                 │
│ - currentRenter : string           │
├────────────────────────────────────┤
│ + Car()                            │
│ + Car(id, model, type, rate)       │
│ + setCarID(id) : void              │
│ + getCarID() : string              │
│ + setCarModel(model) : void        │
│ + getCarModel() : string           │
│ + setCarType(type) : void          │
│ + getCarType() : string            │
│ + setDailyRate(rate) : void        │
│ + getDailyRate() : long            │
│ + setAvailable(status) : void      │
│ + getAvailable() : bool            │
│ + setCurrentRenter(renter) : void  │
│ + getCurrentRenter() : string      │
│ + printCarInfo() : void            │
│ + printCarStatus() : void          │
└────────────────────────────────────┘
                    △
                    │ uses
                    │
┌────────────────────────────────────┐
│        RentalManager Class          │
├────────────────────────────────────┤
│ - cars : vector<Car>               │
│ - renters : vector<Renter>         │
├────────────────────────────────────┤
│ + RentalManager()                  │
│ + addCar(...) : void               │
│ + editCar(...) : void              │
│ + deleteCar(...) : void            │
│ + viewAllCars() : void             │
│ + viewAvailableCars() : void       │
│ + findCar(id) : Car*               │
│ + addRenter(...) : void            │
│ + editRenter(...) : void           │
│ + deleteRenter(...) : void         │
│ + viewAllRenters() : void          │
│ + findRenter(id) : Renter*         │
│ + rentCar(...) : void              │
│ + returnCar(...) : void            │
│ + viewRentalHistory() : void       │
│ + searchCarByType(...) : void      │
│ + checkCarAvailability(...) : void │
│ + loadFromFile(...) : void         │
│ + saveToFile(...) : void           │
└────────────────────────────────────┘
                    △
                    │ uses
                    │
┌────────────────────────────────────┐
│        Renter Class                │
├────────────────────────────────────┤
│ - renterID : string                │
│ - renterName : string              │
│ - phoneNumber : string             │
│ - address : string                 │
│ - rentalCar : string               │
│ - rentalDays : int                 │
│ - totalCost : long                 │
├────────────────────────────────────┤
│ + Renter()                         │
│ + Renter(id, name, phone, addr)    │
│ + setRenterID(id) : void           │
│ + getRenterID() : string           │
│ + setRenterName(name) : void       │
│ + getRenterName() : string         │
│ + setPhoneNumber(phone) : void     │
│ + getPhoneNumber() : string        │
│ + setAddress(addr) : void          │
│ + getAddress() : string            │
│ + setRentalCar(carID) : void       │
│ + getRentalCar() : string          │
│ + setRentalDays(days) : void       │
│ + getRentalDays() : int            │
│ + setTotalCost(cost) : void        │
│ + getTotalCost() : long            │
│ + printRenterInfo() : void         │
│ + printRentalDetails() : void      │
└────────────────────────────────────┘
```

### 3.4 Perancangan User Interface

**Jenis Interface:** Console-based (Command Line Interface)

**Struktur Menu:**
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

**Submenu - Kelola Data Mobil:**
```
=== KELOLA DATA MOBIL ===
1. Tambah Mobil
2. Edit Mobil
3. Hapus Mobil
4. Lihat Semua Mobil
5. Lihat Mobil Tersedia
6. Cari Mobil Berdasarkan Tipe
0. Kembali
```

**Contoh Output - Lihat Semua Mobil:**
```
=== DAFTAR SEMUA MOBIL ===
1. ID: MBL001 | Model: Toyota Avanza | Tipe: SUV | Tarif: Rp350000/hari
2. ID: MBL002 | Model: Honda City | Tipe: Sedan | Tarif: Rp300000/hari
3. ID: MBL003 | Model: Daihatsu Terios | Tipe: SUV | Tarif: Rp320000/hari
...
```

### 3.5 Transformasi Class Diagram Menjadi Kode Program

Transformasi dari class diagram ke implementasi C++ dilakukan dengan langkah-langkah berikut:

**1. Deklarasi Class (Header File - Car.h):**
- Setiap attribute dalam class diagram dideklarasikan sebagai member variable private
- Setiap method dideklarasikan sebagai function public
- Constructor dengan parameter sesuai diagram

**2. Implementasi Class (Source File - Car.cpp):**
- Setiap method yang dideklarasikan di header diimplementasikan
- Setter method mengeset nilai attribute
- Getter method mengembalikan nilai attribute
- Method lain mengimplementasikan logika yang diperlukan

**3. Struktur Program:**
- Car.h dan Car.cpp: Implementasi class Car
- Renter.h dan Renter.cpp: Implementasi class Renter
- RentalManager.h dan RentalManager.cpp: Implementasi class RentalManager
- main.cpp: Program utama dengan loop menu dan user interface

**Contoh Transformasi:**

Class Diagram:
```
class Car {
  - carID : string
  + getCarID() : string
  + setCarID(id) : void
}
```

Header File (Car.h):
```cpp
class Car {
private:
    string carID;
public:
    string getCarID();
    void setCarID(string id);
};
```

Source File (Car.cpp):
```cpp
string Car::getCarID() {
    return carID;
}

void Car::setCarID(string id) {
    carID = id;
}
```

---

## 4. IMPLEMENTASI APLIKASI

### 4.1 Perubahan dari Design

Perubahan yang dilakukan dari design awal:

1. **Namespace Management:** Menambahkan `using namespace std;` untuk mempermudah penulisan kode
2. **Vector untuk Penyimpanan Data:** Menggunakan `vector<Car>` dan `vector<Renter>` dari STL untuk dynamic array
3. **Pointer untuk Search:** Method `findCar()` dan `findRenter()` mengembalikan pointer untuk efisiensi
4. **File Format:** Format file output menggunakan delimiter `|` untuk memisahkan field
5. **Menu System:** Mengimplementasikan hierarchical menu dengan loop untuk user experience yang lebih baik
6. **Error Handling:** Menambahkan validasi input dan pesan error yang lebih informatif

### 4.2 Komponen yang Diimplementasikan

**Total Fitur Fungsional yang Diimplementasikan: 15 dari 15 (100%)**

| No | Fitur | Status | Keterangan |
|----|-------|--------|-----------|
| 1 | Register new car (F-01) | ✓ Selesai | Fitur tambah mobil dengan validasi ID duplikat |
| 2 | Edit car data (F-02) | ✓ Selesai | Fitur edit semua attribute mobil |
| 3 | Delete car data (F-03) | ✓ Selesai | Fitur hapus dengan validasi keberadaan |
| 4 | View all cars (F-04) | ✓ Selesai | Menampilkan semua data mobil |
| 5 | View available cars (F-05) | ✓ Selesai | Menampilkan hanya mobil yang tersedia |
| 6 | Search cars by type (F-06) | ✓ Selesai | Cari mobil berdasarkan kategori tipe |
| 7 | Register new renter (F-07) | ✓ Selesai | Daftarkan penyewa baru dengan data lengkap |
| 8 | Edit renter data (F-08) | ✓ Selesai | Fitur edit data penyewa |
| 9 | Delete renter data (F-09) | ✓ Selesai | Fitur hapus data penyewa |
| 10 | View all renters (F-10) | ✓ Selesai | Menampilkan semua data penyewa |
| 11 | Rent a car (F-11) | ✓ Selesai | Mencatat penyewaan dengan perhitungan biaya otomatis |
| 12 | Return a car (F-12) | ✓ Selesai | Mencatat pengembalian dan mengubah status |
| 13 | View rental history (F-13) | ✓ Selesai | Menampilkan riwayat penyewaan aktif |
| 14 | Load data from file (F-14) | ✓ Selesai | Baca data dari input.txt |
| 15 | Save data to file (F-15) | ✓ Selesai | Simpan data ke output.txt |

### 4.3 Fitur F-01: Register New Car

**Deskripsi:** Fitur untuk menambahkan data mobil baru ke dalam sistem.

**Alur Kerja:**
1. User memilih menu 1 dari menu utama
2. User memilih menu 1 dari submenu "Kelola Data Mobil"
3. Sistem menampilkan prompt untuk memasukkan ID, Model, Tipe, dan Tarif Harian
4. User memasukkan data sesuai prompt
5. Sistem melakukan validasi:
   - Mengecek apakah ID sudah ada di database
   - Jika ID duplikat, tampilkan error
6. Jika valid, sistem menyimpan data ke vector cars
7. Sistem menampilkan pesan sukses

**Contoh Penggunaan:**
```
=== KELOLA DATA MOBIL ===
1. Tambah Mobil
...
Pilihan Anda: 1

--- Tambah Mobil Baru ---
ID Mobil: MBL011
Model Mobil: Honda Civic
Tipe Mobil (SUV/Sedan/MPV/Truck): Sedan
Tarif Harian (Rp): 400000

Mobil berhasil ditambahkan!
```

### 4.4 Fitur F-02: Edit Car Data

**Deskripsi:** Fitur untuk mengubah data mobil yang sudah ada.

**Alur Kerja:**
1. User memilih menu 2 dari submenu "Kelola Data Mobil"
2. Sistem meminta ID mobil yang akan diedit
3. Sistem mencari mobil dengan ID tersebut menggunakan method `findCar()`
4. Jika tidak ditemukan, tampilkan error
5. Jika ditemukan, user diminta memasukkan data baru
6. Sistem mengupdate semua field
7. Tampilkan pesan sukses

### 4.5 Fitur F-03: Delete Car Data

**Deskripsi:** Fitur untuk menghapus data mobil dari sistem.

**Alur Kerja:**
1. User memilih menu 3 dari submenu "Kelola Data Mobil"
2. Sistem meminta ID mobil yang akan dihapus
3. Sistem mencari mobil dalam vector cars menggunakan loop
4. Jika ditemukan, hapus element dari vector menggunakan `erase()`
5. Tampilkan pesan sukses atau error

### 4.6 Fitur F-05: View Available Cars

**Deskripsi:** Menampilkan daftar kendaraan yang masih tersedia untuk disewa.

**Implementasi:**
```cpp
void RentalManager::viewAvailableCars() {
    cout << "\n=== DAFTAR MOBIL TERSEDIA ===" << endl;
    int count = 0;
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].getAvailable()) {
            cout << ++count << ". ";
            cars[i].printCarInfo();
        }
    }
    if (count == 0) {
        cout << "Tidak ada mobil yang tersedia." << endl;
    }
}
```

Fungsi ini melakukan iterasi pada semua mobil dan menampilkan hanya yang memiliki status `available == true`.

### 4.7 Fitur F-11: Rent a Car

**Deskripsi:** Fitur untuk mencatat transaksi penyewaan mobil.

**Alur Kerja:**
1. User memilih menu "Sewa Mobil"
2. Sistem meminta ID Penyewa, ID Mobil, dan Jumlah Hari
3. Sistem melakukan validasi:
   - Penyewa ada di database
   - Mobil ada di database
   - Status mobil adalah tersedia
4. Sistem menghitung total biaya: `totalCost = hari × tarif harian`
5. Sistem mengubah status mobil menjadi tidak tersedia
6. Sistem menyimpan informasi penyewaan ke object Renter
7. Sistem menampilkan detail penyewaan dengan total biaya

**Contoh Output:**
```
=== DETAIL PENYEWAAN ===
Penyewa: Rozan Gangsar Adibrata
Mobil: Toyota Avanza (MBL001)
Durasi: 5 hari
Tarif: Rp350000/hari
TOTAL BIAYA: Rp1750000
Penyewaan berhasil dicatat!
```

### 4.8 Fitur F-14 & F-15: Load dan Save Data dari/ke File

**F-14: Load Data from File**

Fungsi `loadFromFile()` membaca data dari file input.txt dengan format:
```
ID Model Tipe Tarif
MBL001 Toyota_Avanza SUV 350000
```

Implementasi:
```cpp
void RentalManager::loadFromFile(string filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Error: File tidak dapat dibuka!" << endl;
        return;
    }

    string id, model, type;
    long rate;

    while (inputFile >> id >> model >> type >> rate) {
        addCar(id, model, type, rate);
    }

    inputFile.close();
    cout << "Data berhasil dimuat dari " << filename << endl;
}
```

**F-15: Save Data to File**

Fungsi `saveToFile()` menyimpan semua data ke output.txt dengan format:
```
ID|Model|Tipe|Tarif|Status|Penyewa
MBL001|Toyota Avanza|SUV|350000|0|
MBL002|Honda City|Sedan|300000|1|Rozan Gangsar
```

---

## 5. TESTING DAN HASIL

### 5.1 Skenario Testing

**Test Case 1: Tambah Mobil**
- Input: ID=MBL011, Model=Honda Civic, Tipe=Sedan, Tarif=400000
- Expected Output: "Mobil berhasil ditambahkan!"
- Result: ✓ PASS

**Test Case 2: Cari Mobil yang Duplikat**
- Input: Tambah mobil dengan ID MBL001 (sudah ada)
- Expected Output: "Error: Mobil dengan ID MBL001 sudah ada!"
- Result: ✓ PASS

**Test Case 3: Edit Data Mobil**
- Input: Edit MBL001, Model=Toyota Avanza New, Tarif=360000
- Expected Output: "Data mobil berhasil diperbarui!"
- Result: ✓ PASS

**Test Case 4: Sewa Mobil**
- Input: Sewa MBL001 untuk penyewa P001 selama 5 hari
- Expected Output: Total Biaya = 5 × 350000 = Rp1750000
- Result: ✓ PASS

**Test Case 5: Sewa Mobil yang Tidak Tersedia**
- Input: Sewa mobil yang sudah sedang disewa
- Expected Output: "Error: Mobil sedang disewa oleh penyewa lain!"
- Result: ✓ PASS

**Test Case 6: Load Data dari File**
- Input: Load dari input.txt
- Expected Output: Semua 10 mobil berhasil dimuat
- Result: ✓ PASS

### 5.2 Hasil Testing

Semua 15 fitur fungsional telah ditest dan berfungsi dengan baik. Tidak ada error fatal dalam proses testing.

---

## 6. KESIMPULAN

Aplikasi Rental Mobil Sederhana telah berhasil diimplementasikan dengan menggunakan pendekatan Object Oriented Programming dalam bahasa C++. Aplikasi ini mencakup semua fitur yang dirancang meliputi:

1. **CRUD Operations** untuk data mobil dan penyewa
2. **Transaksi Penyewaan** dengan perhitungan biaya otomatis
3. **Pencarian dan Filter** berdasarkan tipe mobil
4. **File I/O** untuk load dan save data

Aplikasi ini dapat menjadi dasar untuk pengembangan lebih lanjut seperti penambahan GUI, database, dan fitur-fitur advanced lainnya.

---

## LAMPIRAN

### A. Source Code Lengkap

**File-file yang disertakan:**
1. Car.h - Header file untuk class Car
2. Car.cpp - Implementasi class Car
3. Renter.h - Header file untuk class Renter
4. Renter.cpp - Implementasi class Renter
5. RentalManager.h - Header file untuk class RentalManager
6. RentalManager.cpp - Implementasi class RentalManager
7. main.cpp - Program utama dengan UI console
8. input.txt - File data sample untuk testing
9. output.txt - File output hasil saving data

### B. Cara Kompilasi dan Eksekusi

**Menggunakan g++ di terminal:**
```bash
g++ -o rental main.cpp Car.cpp Renter.cpp RentalManager.cpp
./rental
```

**Atau menggunakan IDE seperti Code::Blocks:**
1. Buat project baru "C++"
2. Tambahkan semua .cpp dan .h files ke project
3. Build project (Ctrl+F9)
4. Run project (Ctrl+F10)

### C. Struktur Folder Project

```
ProgdasUAS/
├── Car.h
├── Car.cpp
├── Renter.h
├── Renter.cpp
├── RentalManager.h
├── RentalManager.cpp
├── main.cpp
├── input.txt
├── output.txt
└── LAPORAN.md (dokumen ini)
```

---

**Tanggal Pembuatan:** 2025
**Nama Pembuat:** Rozan Gangsar Adibrata
**NIM:** 23/521626/TK/57547
**Universitas:** Universitas Gadjah Mada
**Departemen:** Teknik Elektro dan Teknologi Informasi
