#include "RentalManager.h"
#include <iostream>
#include <string>
using namespace std;

void displayMainMenu() {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║   APLIKASI RENTAL MOBIL SEDERHANA     ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "\n=== MENU UTAMA ===" << endl;
    cout << "1. Kelola Data Mobil" << endl;
    cout << "2. Kelola Data Penyewa" << endl;
    cout << "3. Transaksi Penyewaan" << endl;
    cout << "4. Lihat Informasi" << endl;
    cout << "5. Muat Data dari File" << endl;
    cout << "6. Simpan Data ke File" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan Anda: ";
}

void displayCarMenu() {
    cout << "\n=== KELOLA DATA MOBIL ===" << endl;
    cout << "1. Tambah Mobil" << endl;
    cout << "2. Edit Mobil" << endl;
    cout << "3. Hapus Mobil" << endl;
    cout << "4. Lihat Semua Mobil" << endl;
    cout << "5. Lihat Mobil Tersedia" << endl;
    cout << "6. Cari Mobil Berdasarkan Tipe" << endl;
    cout << "0. Kembali" << endl;
    cout << "Pilihan Anda: ";
}

void displayRenterMenu() {
    cout << "\n=== KELOLA DATA PENYEWA ===" << endl;
    cout << "1. Daftarkan Penyewa Baru" << endl;
    cout << "2. Edit Data Penyewa" << endl;
    cout << "3. Hapus Data Penyewa" << endl;
    cout << "4. Lihat Semua Penyewa" << endl;
    cout << "0. Kembali" << endl;
    cout << "Pilihan Anda: ";
}

void displayTransactionMenu() {
    cout << "\n=== TRANSAKSI PENYEWAAN ===" << endl;
    cout << "1. Sewa Mobil" << endl;
    cout << "2. Kembalikan Mobil" << endl;
    cout << "3. Lihat Riwayat Penyewaan" << endl;
    cout << "0. Kembali" << endl;
    cout << "Pilihan Anda: ";
}

void displayViewMenu() {
    cout << "\n=== LIHAT INFORMASI ===" << endl;
    cout << "1. Cek Ketersediaan Mobil" << endl;
    cout << "2. Lihat Semua Mobil" << endl;
    cout << "3. Lihat Semua Penyewa" << endl;
    cout << "0. Kembali" << endl;
    cout << "Pilihan Anda: ";
}

int main() {
    RentalManager manager;
    int mainChoice, carChoice, renterChoice, transChoice, viewChoice;
    string carID, carModel, carType, renterID, renterName, phone, address, days, rate;

    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║  SELAMAT DATANG DI APLIKASI RENTAL    ║" << endl;
    cout << "║            MOBIL SEDERHANA            ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    while (true) {
        displayMainMenu();
        cin >> mainChoice;
        cin.ignore();

        switch (mainChoice) {
            case 1: {
                // Kelola Data Mobil
                while (true) {
                    displayCarMenu();
                    cin >> carChoice;
                    cin.ignore();

                    switch (carChoice) {
                        case 1: {
                            // Tambah Mobil
                            cout << "\n--- Tambah Mobil Baru ---" << endl;
                            cout << "ID Mobil: ";
                            getline(cin, carID);
                            cout << "Model Mobil: ";
                            getline(cin, carModel);
                            cout << "Tipe Mobil (SUV/Sedan/MPV/Truck): ";
                            getline(cin, carType);
                            cout << "Tarif Harian (Rp): ";
                            getline(cin, rate);
                            manager.addCar(carID, carModel, carType, stol(rate));
                            break;
                        }
                        case 2: {
                            // Edit Mobil
                            cout << "\n--- Edit Data Mobil ---" << endl;
                            cout << "ID Mobil yang akan diedit: ";
                            getline(cin, carID);
                            cout << "Model Mobil Baru: ";
                            getline(cin, carModel);
                            cout << "Tipe Mobil Baru: ";
                            getline(cin, carType);
                            cout << "Tarif Harian Baru (Rp): ";
                            getline(cin, rate);
                            manager.editCar(carID, carModel, carType, stol(rate));
                            break;
                        }
                        case 3: {
                            // Hapus Mobil
                            cout << "\n--- Hapus Mobil ---" << endl;
                            cout << "ID Mobil yang akan dihapus: ";
                            getline(cin, carID);
                            manager.deleteCar(carID);
                            break;
                        }
                        case 4: {
                            // Lihat Semua Mobil
                            manager.viewAllCars();
                            break;
                        }
                        case 5: {
                            // Lihat Mobil Tersedia
                            manager.viewAvailableCars();
                            break;
                        }
                        case 6: {
                            // Cari Mobil Berdasarkan Tipe
                            cout << "\nMasukkan tipe mobil (SUV/Sedan/MPV/Truck): ";
                            getline(cin, carType);
                            manager.searchCarByType(carType);
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                    }
                    if (carChoice == 0) break;
                }
                break;
            }

            case 2: {
                // Kelola Data Penyewa
                while (true) {
                    displayRenterMenu();
                    cin >> renterChoice;
                    cin.ignore();

                    switch (renterChoice) {
                        case 1: {
                            // Daftarkan Penyewa Baru
                            cout << "\n--- Daftarkan Penyewa Baru ---" << endl;
                            cout << "ID Penyewa: ";
                            getline(cin, renterID);
                            cout << "Nama Penyewa: ";
                            getline(cin, renterName);
                            cout << "Nomor Telepon: ";
                            getline(cin, phone);
                            cout << "Alamat: ";
                            getline(cin, address);
                            manager.addRenter(renterID, renterName, phone, address);
                            break;
                        }
                        case 2: {
                            // Edit Penyewa
                            cout << "\n--- Edit Data Penyewa ---" << endl;
                            cout << "ID Penyewa yang akan diedit: ";
                            getline(cin, renterID);
                            cout << "Nama Baru: ";
                            getline(cin, renterName);
                            cout << "Nomor Telepon Baru: ";
                            getline(cin, phone);
                            cout << "Alamat Baru: ";
                            getline(cin, address);
                            manager.editRenter(renterID, renterName, phone, address);
                            break;
                        }
                        case 3: {
                            // Hapus Penyewa
                            cout << "\n--- Hapus Data Penyewa ---" << endl;
                            cout << "ID Penyewa yang akan dihapus: ";
                            getline(cin, renterID);
                            manager.deleteRenter(renterID);
                            break;
                        }
                        case 4: {
                            // Lihat Semua Penyewa
                            manager.viewAllRenters();
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                    }
                    if (renterChoice == 0) break;
                }
                break;
            }

            case 3: {
                // Transaksi Penyewaan
                while (true) {
                    displayTransactionMenu();
                    cin >> transChoice;
                    cin.ignore();

                    switch (transChoice) {
                        case 1: {
                            // Sewa Mobil
                            cout << "\n--- Sewa Mobil ---" << endl;
                            cout << "ID Penyewa: ";
                            getline(cin, renterID);
                            cout << "ID Mobil yang disewa: ";
                            getline(cin, carID);
                            cout << "Jumlah Hari: ";
                            getline(cin, days);

                            Car* car = manager.findCar(carID);
                            if (car != NULL) {
                                manager.rentCar(renterID, carID, stoi(days), car->getDailyRate());
                            }
                            break;
                        }
                        case 2: {
                            // Kembalikan Mobil
                            cout << "\n--- Kembalikan Mobil ---" << endl;
                            cout << "ID Mobil yang dikembalikan: ";
                            getline(cin, carID);
                            manager.returnCar(carID);
                            break;
                        }
                        case 3: {
                            // Lihat Riwayat Penyewaan
                            manager.viewRentalHistory();
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                    }
                    if (transChoice == 0) break;
                }
                break;
            }

            case 4: {
                // Lihat Informasi
                while (true) {
                    displayViewMenu();
                    cin >> viewChoice;
                    cin.ignore();

                    switch (viewChoice) {
                        case 1: {
                            cout << "ID Mobil: ";
                            getline(cin, carID);
                            manager.checkCarAvailability(carID);
                            break;
                        }
                        case 2: {
                            manager.viewAllCars();
                            break;
                        }
                        case 3: {
                            manager.viewAllRenters();
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                    }
                    if (viewChoice == 0) break;
                }
                break;
            }

            case 5: {
                // Muat Data dari File
                string filename;
                cout << "Masukkan nama file (default: input.txt): ";
                getline(cin, filename);
                if (filename.empty()) filename = "input.txt";
                manager.loadFromFile(filename);
                break;
            }

            case 6: {
                // Simpan Data ke File
                string filename;
                cout << "Masukkan nama file (default: output.txt): ";
                getline(cin, filename);
                if (filename.empty()) filename = "output.txt";
                manager.saveToFile(filename);
                break;
            }

            case 0: {
                cout << "\nTerima kasih telah menggunakan aplikasi ini. Sampai jumpa!" << endl;
                return 0;
            }

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}
