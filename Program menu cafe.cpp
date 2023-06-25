#include <iostream>
#include <iomanip>
using namespace std;

struct Menu {
    int kode;
    string nama;
    string ukuran[3];
    int harga[3];
};

void tampilkanHeader() {
    cout << "======================================" << endl;
    cout << "      SELAMAT DATANG DI CAFE ENJOY" << endl;
    cout << "======================================" << endl;
}

void tampilkanFooter() {
    cout << "======================================" << endl;
    cout << " Terima kasih telah mengunjungi Cafe XYZ" << endl;
    cout << "       Silakan datang kembali!" << endl;
    cout << "======================================" << endl;
}

void tampilkanMenuCafe(Menu daftarMenu[], int jumlahMenu) {
    cout << "\n=== MENU CAFE ===" << endl;
    for (int i = 0; i < jumlahMenu; i++) {
        cout << setw(2) << daftarMenu[i].kode << ". " << setw(20) << left << daftarMenu[i].nama;
        for (int j = 0; j < 3; j++) {
            cout << "(" << daftarMenu[i].ukuran[j] << ") Rp" << setw(8) << right << daftarMenu[i].harga[j] << " ";
        }
        cout << endl;
    }
    cout << setw(2) << jumlahMenu + 1 << ". SELESAI" << endl;
}

void tampilkanMetodePembayaran() {
    cout << "\n=== METODE PEMBAYARAN ===" << endl;
    cout << "1. Tunai" << endl;
    cout << "2. Kartu Kredit" << endl;
    cout << "3. E-Wallet" << endl;
}

void pembayarantunai(int totalH){
	int tunai,kembalian;
	cout<<"\n Nominal uang anda :";
	cin>>tunai;
	kembalian = tunai - totalH;
	cout<<" Kembalian anda :"<<kembalian<<endl<<endl;
}
int main() {
    int pilihanMenu, pilihanUkuran, pilihanPembayaran;
    Menu daftarMenu[] = {
        {1, "Espresso", {"Regular", "Large", "Extra Large"}, {20000, 25000, 30000}},
        {2, "Cappuccino", {"Regular", "Large", "Extra Large"}, {22000, 27000, 32000}},
        {3, "Latte", {"Regular", "Large", "Extra Large"}, {23000, 28000, 33000}},
        {4, "Mocha", {"Regular", "Large", "Extra Large"}, {24000, 29000, 34000}},
        {5, "Macchiato", {"Regular", "Large", "Extra Large"}, {25000, 30000, 35000}}
    };
	
    int jumlahMenu = sizeof(daftarMenu) / sizeof(daftarMenu[0]);

    tampilkanHeader();
    tampilkanMenuCafe(daftarMenu, jumlahMenu);

    int totalHarga = 0;
    cout << "\nPilih nomor menu yang Anda inginkan (1-5) atau 6 untuk selesai\n"<<endl;
    cin >> pilihanMenu;

    while (pilihanMenu >= 1 && pilihanMenu <= jumlahMenu) {
        cout << "\nAnda memilih: " << daftarMenu[pilihanMenu - 1].nama << endl;
        cout << "Pilih nomor ukuran (1-3): ";
        cin >> pilihanUkuran;

        if (pilihanUkuran >= 1 && pilihanUkuran <= 3) {
            totalHarga += daftarMenu[pilihanMenu - 1].harga[pilihanUkuran - 1];
            cout << "Anda memilih ukuran " << daftarMenu[pilihanMenu - 1].ukuran[pilihanUkuran - 1] << endl;
            cout << "Harga: Rp" << daftarMenu[pilihanMenu - 1].harga[pilihanUkuran - 1] << endl;
        } else {
            cout << "Nomor ukuran yang Anda pilih tidak valid." << endl;
        }

        cout << "\nPilih nomor menu lain (1-5)" " atau " << jumlahMenu + 1 << " untuk selesai: ";
        cin >> pilihanMenu;
    }

    cout << "\n--------------------------------------" << endl;
    if (totalHarga > 0) {
        cout << "Total harga pesanan: Rp " << totalHarga << endl;
        tampilkanMetodePembayaran();
        cout << "Pilih nomor metode pembayaran (1-3): ";
        cin >> pilihanPembayaran;
		
        switch (pilihanPembayaran) {
            case 1:
                pembayarantunai(totalHarga);
                cout<<"Pesanan Anda sedang diproses. Mohon menunggu."<<endl;
                break;
            case 2:
                cout << "Anda memilih pembayaran kartu kredit." <<endl<<"Pesanan Anda sedang diproses. Mohon menunggu." <<endl;
                break;
            case 3:
                cout << "Anda memilih pembayaran e-wallet." <<endl<<"Pesanan Anda sedang diproses. Mohon menunggu." << endl;
                break;
            default:
                cout << "Nomor metode pembayaran yang Anda pilih tidak valid." << endl;
                break;
                
        }

        
    } else {
        cout << "Anda belum memesan apa pun. Terima kasih dan sampai jumpa kembali!" << endl;
    }
    cout << "--------------------------------------" << endl;

    tampilkanFooter();

    return 0;
}
