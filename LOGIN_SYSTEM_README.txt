================================================================================
                        LOGIN SYSTEM - IMPLEMENTASI
                      Aplikasi Rental Mobil Sederhana
================================================================================

FITUR BARU YANG DITAMBAHKAN:
================================================================================

1. SISTEM AUTENTIKASI
   - Login dengan Username & Password
   - Role-based Access Control (Admin vs User)
   - Session management (logout)

2. CLASS BARU:
   - User.h / User.cpp - Menyimpan data user (username, password, role)
   - AuthenticationManager.h / AuthenticationManager.cpp - Handle login/logout

3. FITUR YANG BERBEDA:

   ADMIN CAN:
   ✓ Kelola Data Mobil (Tambah, Edit, Hapus, Lihat semua)
   ✓ Kelola Data Penyewa (Tambah, Edit, Hapus, Lihat semua)
   ✓ Transaksi Penyewaan (Sewa, Kembalikan, Lihat Riwayat)
   ✓ Muat & Simpan Data dari/ke File
   ✓ Lihat semua informasi sistem
   ✓ Lihat akun yang tersedia

   USER CAN:
   ✓ Lihat Daftar Mobil Tersedia SAJA
   ✓ Cari Mobil Berdasarkan Tipe
   ✓ Sewa Mobil
   ✓ Lihat Riwayat Penyewaan Mereka

   USER TIDAK BISA:
   ✗ Edit/Hapus Mobil
   ✗ Kelola Data Penyewa
   ✗ Kembalikan Mobil
   ✗ Akses File Management

================================================================================
                        AKUN YANG TERSEDIA
================================================================================

ADMIN ACCOUNTS:
  Username: admin        | Password: admin123
  Username: administrator| Password: pass123456

USER ACCOUNTS:
  Username: user         | Password: user123
  Username: rozan        | Password: 12345678
  Username: john         | Password: johndoe

Akun ini tersimpan langsung di kode (hardcoded) tanpa database.

================================================================================
                        CARA IMPLEMENTASI
================================================================================

LANGKAH 1: TAMBAH FILE BARU
-----------------------------------
File yang harus ditambahkan ke project:
  ✓ User.h
  ✓ User.cpp
  ✓ AuthenticationManager.h
  ✓ AuthenticationManager.cpp
  ✓ main_with_login.cpp (ini akan menggantikan main.cpp yang lama)

LANGKAH 2: UPDATE PROJECT
-----------------------------------
Opsi A - Rename File:
  1. Rename main.cpp menjadi main_original.cpp (backup)
  2. Rename main_with_login.cpp menjadi main.cpp

Opsi B - Edit Makefile/Compile Command:
  Gunakan: g++ -std=c++11 -o rental main_with_login.cpp Car.cpp Renter.cpp
           RentalManager.cpp User.cpp AuthenticationManager.cpp

LANGKAH 3: KOMPILASI
-----------------------------------
Setelah update, compile dengan:

  Jika sudah rename main.cpp:
  $ g++ -std=c++11 -o rental main.cpp Car.cpp Renter.cpp RentalManager.cpp User.cpp AuthenticationManager.cpp

  Atau:
  $ make clean && make (jika update Makefile)

LANGKAH 4: TEST
-----------------------------------
1. Jalankan: ./rental atau rental.exe
2. Pilih role (1=Admin atau 2=User)
3. Masukkan akun dari list di atas
4. Test fitur-fitur sesuai role

================================================================================
                        UPDATE MAKEFILE
================================================================================

Jika ingin update Makefile untuk compile dengan login system:

```makefile
# Makefile untuk Aplikasi Rental Mobil dengan Login System
CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = rental

OBJS = main.o Car.o Renter.o RentalManager.o User.o AuthenticationManager.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build successful! Run with: ./$(TARGET)"

main.o: main.cpp RentalManager.h AuthenticationManager.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Car.o: Car.cpp Car.h
	$(CXX) $(CXXFLAGS) -c Car.cpp

Renter.o: Renter.cpp Renter.h
	$(CXX) $(CXXFLAGS) -c Renter.cpp

RentalManager.o: RentalManager.cpp RentalManager.h Car.h Renter.h
	$(CXX) $(CXXFLAGS) -c RentalManager.cpp

User.o: User.cpp User.h
	$(CXX) $(CXXFLAGS) -c User.cpp

AuthenticationManager.o: AuthenticationManager.cpp AuthenticationManager.h User.h
	$(CXX) $(CXXFLAGS) -c AuthenticationManager.cpp

clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Clean successful!"

run: $(TARGET)
	./$(TARGET)

rebuild: clean all

.PHONY: all clean run rebuild
```

================================================================================
                        FLOW LOGIN SYSTEM
================================================================================

1. STARTUP
   └─ Program dimulai, tampilkan Login Screen
      ├─ Option 1: Login as Admin
      ├─ Option 2: Login as User
      ├─ Option 3: View Available Accounts
      └─ Option 0: Exit

2. LOGIN PROCESS
   ├─ User pilih role (Admin atau User)
   ├─ Input Username
   ├─ Input Password
   ├─ System check di vector users
   │  ├─ Jika username tidak ada → "Username tidak ditemukan"
   │  ├─ Jika password salah → "Password salah"
   │  └─ Jika benar → "Login berhasil!"
   └─ Load Menu sesuai Role

3. ADMIN MENU
   ├─ 1: Kelola Data Mobil (Full CRUD)
   ├─ 2: Kelola Data Penyewa (Full CRUD)
   ├─ 3: Transaksi (Sewa, Kembalikan, History)
   ├─ 4: Lihat Info
   ├─ 5: Load File
   ├─ 6: Save File
   ├─ 7: View Available Accounts
   └─ 0: Logout → kembali ke Login Screen

4. USER MENU
   ├─ 1: Lihat Mobil Tersedia
   ├─ 2: Cari Mobil Tipe
   ├─ 3: Sewa Mobil
   ├─ 4: Lihat Riwayat Sewa
   └─ 0: Logout → kembali ke Login Screen

5. LOGOUT
   └─ Kembali ke Login Screen
      Bisa login dengan akun berbeda atau exit

================================================================================
                        STRUKTUR CLASS BARU
================================================================================

USER CLASS:
  Private:
    - username : string
    - password : string
    - role : UserRole (enum: ADMIN=1, USER=2)
  Public:
    - Constructor (default & parameterized)
    - Setter/Getter untuk semua private members
    - getRoleAsString() : string
    - verifyPassword(input) : bool

AUTHENTICATIONMANAGER CLASS:
  Private:
    - users : vector<User>
    - currentUser : User*
  Public:
    - Constructor (initialize default users)
    - login(username, password) : User*
    - logout() : void
    - getCurrentUser() : User*
    - isLoggedIn() : bool
    - isAdminLoggedIn() : bool
    - isUserLoggedIn() : bool
    - addUser() : void
    - printAvailableUsers() : void
    - initializeDefaultUsers() : void

================================================================================
                        KEAMANAN CATATAN
================================================================================

Sistem ini TIDAK menggunakan enkripsi password karena:
- Ini adalah pembelajaran educational
- Password disimpan plain text di vector memory
- Untuk production, harus:
  ✓ Hash password (bcrypt, SHA-256)
  ✓ Gunakan database yang aman
  ✓ Implement SSL/TLS
  ✓ Add rate limiting untuk login attempts
  ✓ Implement session tokens

Untuk sekarang, ini sudah cukup untuk mata kuliah Pemrograman Dasar!

================================================================================
                        TESTING CHECKLIST
================================================================================

[ ] File User.h & User.cpp ada
[ ] File AuthenticationManager.h & AuthenticationManager.cpp ada
[ ] main_with_login.cpp ada
[ ] Compile berhasil dengan semua 6 file object
[ ] Login dengan akun admin berhasil
[ ] Login dengan akun user berhasil
[ ] Login dengan password salah → error message
[ ] Login dengan username salah → error message
[ ] Admin bisa akses semua menu
[ ] User hanya bisa akses menu terbatas
[ ] Admin bisa tambah/edit/hapus mobil
[ ] User tidak bisa akses menu mobil
[ ] Admin bisa load/save file
[ ] User tidak bisa load/save file
[ ] Logout & login dengan akun berbeda berfungsi
[ ] Data tetap persisten setelah logout & login lagi

================================================================================
                        FREQUENTLY ASKED QUESTIONS
================================================================================

Q: Apakah password ini aman?
A: Tidak. Password plain text hanya untuk pembelajaran. Di production gunakan hashing.

Q: Bagaimana jika ingin menambah akun baru?
A: Edit function initializeDefaultUsers() di AuthenticationManager.cpp
   Tambah line: users.push_back(User("username", "password", ADMIN/USER));

Q: Bagaimana jika lupa password?
A: Lihat akun di kode atau run aplikasi, pilih option 3 untuk lihat semua akun.

Q: Bisa simpan akun ke file?
A: Bisa, tapi harus edit AuthenticationManager untuk add file I/O features.

Q: Bagaimana jika ada multiple admin?
A: Bisa, cukup tambah lebih banyak akun di initializeDefaultUsers()

Q: Apakah bisa register akun baru?
A: Belum ada feature register. User harus daftarkan admin di kode.

================================================================================
                        NEXT STEPS
================================================================================

Untuk enhancement lebih lanjut:
1. Add register/signup feature untuk user baru
2. Save users ke file (user credentials)
3. Implement password hashing dengan simple hash function
4. Add audit log untuk login attempts
5. Add user profile/dashboard
6. Session timeout setelah X menit idle
7. Multi-session atau single session limit

================================================================================
                        CONTACT & SUPPORT
================================================================================

Untuk pertanyaan tentang login system:
- Cek class User.cpp untuk understand user properties
- Cek AuthenticationManager.cpp untuk understand authentication logic
- Cek main_with_login.cpp untuk understand menu flow

================================================================================
                        SUMMARY
================================================================================

LOGIN SYSTEM MEMBERIKAN:
✓ Role-based access control (Admin vs User)
✓ Username & password authentication
✓ Different features untuk different roles
✓ Clean separation of concerns
✓ Easy to extend dengan fitur lain

SIAP UNTUK DIKUMPULKAN!

================================================================================
Dibuat: November 22, 2025
Status: READY - Enhance existing project dengan login system
================================================================================
