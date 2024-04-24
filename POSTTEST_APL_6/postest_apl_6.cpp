#include <iostream>
#include <string>

using namespace std;

int jumlah_hewan = 2;

struct hewan
{
    string nama;
};

struct kebunBinatang
{
    hewan *hw[100]; // Menggunakan pointer untuk array hewan
};
kebunBinatang kb;

// insertion sort
void insertionSortDesc(hewan *arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        hewan *key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j]->nama < key->nama)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// bubble sort
void bubbleSortDesc(hewan *arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j]->nama < arr[j + 1]->nama)
            {
                hewan *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(hewan *arr[], int l, int r, string x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid]->nama == x)
            return mid;

        if (arr[mid]->nama < x)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

void tampilkanSetelahDiurutkan(hewan *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "." << arr[i]->nama << endl;
    }
}

void login()
{
    cout << "login" << endl;
    cout << "1. masuk" << endl;
    cout << "2. keluar" << endl;
}

void menu()
{
    cout << "=== MENU ===" << endl;
    cout << "1. tambah LIST" << endl;
    cout << "2. hapus LIST" << endl;
    cout << "3. edit list" << endl;
    cout << "4. lihat list" << endl;
    cout << "5. luas kandang dibutuhkan" << endl;
    cout << "6. pengurutan hewan secara descending(dari alphabet terbesar)" << endl;
    cout << "7. pecarian hewan " << endl;
    cout << "9. keluar" << endl;
}

int jumlahDataHewan()
{
    return jumlah_hewan;
}

// Fungsi dengan parameter dereference
void luasKandang(const int *jumlahHewan)
{
    int luasSatuHewan = 4;
    cout << "Total luas kandang yang dibutuhkan untuk " << *jumlahHewan << " hewan adalah " << *jumlahHewan * luasSatuHewan << "m^2" << endl;
}

// Fungsi dengan parameter address-of
void tambahHewan(kebunBinatang *kb, int *jumlah_hewan)
{
    kb->hw[*jumlah_hewan] = new hewan;
    string hewan_baru;
    cout << "masukan nama hewan: ";
    cin >> hewan_baru;
    kb->hw[*jumlah_hewan]->nama = hewan_baru;
    (*jumlah_hewan)++;
}

// Fungsi dengan parameter dereference
void hapusHewan(kebunBinatang *kb, int *jumlah_hewan)
{
    cout << "hapus list" << endl;
    for (int i = 0; i < *jumlah_hewan; i++)
    {
        cout << i + 1 << "." << kb->hw[i]->nama << endl;
    }
    string lanjut2 = "ya";
    while (lanjut2 == "ya")
    {
        string hewan_hapus;
        cout << "masukan nama hewan yang akan dihapus: ";
        cin >> hewan_hapus;
        int index_hapus = -1;
        for (int i = 0; i < *jumlah_hewan; i++)
        {
            if (kb->hw[i]->nama == hewan_hapus)
            {
                index_hapus = i;
                break;
            }
        }
        if (index_hapus != -1)
        {
            delete kb->hw[index_hapus];
            for (int i = index_hapus; i < *jumlah_hewan - 1; i++)
            {
                kb->hw[i] = kb->hw[i + 1];
            }
            (*jumlah_hewan)--;
            cout << "Data berhasil dihapus." << endl;
        }
        else
        {
            cout << "Data tidak ditemukan." << endl;
        }
        cout << "apakah ingin lanjut?[ya/tidak]: ";
        cin >> lanjut2;
    }
}

// Fungsi dengan parameter dereference
void editHewan(kebunBinatang *kb, int *jumlah_hewan)
{
    cout << "edit list" << endl;
    for (int i = 0; i < *jumlah_hewan; i++)
    {
        cout << i + 1 << "." << kb->hw[i]->nama << endl;
    }
    string lanjut3 = "ya";
    while (lanjut3 == "ya")
    {
        string hewan_edit;
        cout << "masukan nama hewan yang diganti: ";
        cin >> hewan_edit;
        int index_edit = -1;
        for (int i = 0; i < *jumlah_hewan; i++)
        {
            if (kb->hw[i]->nama == hewan_edit)
            {
                index_edit = i;
                break;
            }
        }
        if (index_edit != -1)
        {
            string hewan_baru;
            cout << "masukan nama hewan baru: ";
            cin >> hewan_baru;
            kb->hw[index_edit]->nama = hewan_baru;
            cout << "Data berhasil diubah." << endl;
        }
        else
        {
            cout << "Data tidak ditemukan." << endl;
        }
        cout << "apakah ingin lanjut?[ya/tidak]: ";
        cin >> lanjut3;
    }
}

// Fungsi dengan parameter dereference
void lihatHewan(kebunBinatang *kb, int *jumlah_hewan)
{
    cout << "Jumlah data hewan: " << jumlahDataHewan() << endl;
    cout << "lihat list" << endl;
    for (int i = 0; i < *jumlah_hewan; i++)
    {
        cout << i + 1 << "." << kb->hw[i]->nama << endl;
    }
}

int main()
{
    kb.hw[0] = new hewan; // Menggunakan operator new untuk mengalokasikan memori untuk hewan pertama
    kb.hw[0]->nama = "singa";
    kb.hw[1] = new hewan;
    kb.hw[1]->nama = "gajah";

    while (true)
    {
        login();
        cout << "masukan pilihan anda: ";
        int log;
        cin >> log;
        if (log == 1)
        {
            cout << "LIST DATA HEWAN DI KEBUN BINATANG" << endl;
            string nama_ = "zidan";
            string nama;
            cout << "masukan nama anda: ";
            cin >> nama;
            string nim = "084";
            string pass_ = nim.substr(nim.length() - 3);
            int percobaan = 0;
            while (percobaan < 3)
            {
                string passs;
                cout << "masukan password anda (password menggunakan 3 nomor akhir NIM): ";
                cin >> passs;
                if (passs == pass_ && nama == nama_)
                {
                    menu();
                    cout << "selamat datang " << nama << endl;
                    int pilih2;
                    cout << "masukan pilihan anda: ";
                    cin >> pilih2;
                    if (pilih2 == 1)
                    {
                        cout << "tambah list" << endl;
                        string lanjut1 = "ya";
                        while (lanjut1 == "ya")
                        {
                            tambahHewan(&kb, &jumlah_hewan); // Mengirim address-of dari kb dan jumlah_hewan
                            cout << "apakah ingin lanjut?[ya/tidak]: ";
                            cin >> lanjut1;
                        }
                    }
                    else if (pilih2 == 2)
                    {
                        hapusHewan(&kb, &jumlah_hewan); // Mengirim address-of dari kb dan jumlah_hewan
                    }
                    else if (pilih2 == 3)
                    {
                        editHewan(&kb, &jumlah_hewan); // Mengirim address-of dari kb dan jumlah_hewan
                    }
                    else if (pilih2 == 4)
                    {
                        lihatHewan(&kb, &jumlah_hewan); // Mengirim address-of dari kb dan jumlah_hewan
                    }
                    else if (pilih2 == 5)
                    {
                        cout << "Masukkan jumlah hewan: ";
                        int jumlahHewan;
                        cin >> jumlahHewan;
                        luasKandang(&jumlahHewan); // Mengirim address-of dari jumlahHewan
                    }
                    else if (pilih2 == 6)
                    {
                        insertionSortDesc(kb.hw, jumlah_hewan);
                        cout << "Data berhasil diurutkan dengan Insertion Sort secara descending:" << endl;
                        tampilkanSetelahDiurutkan(kb.hw, jumlah_hewan);
                    }
                    else if (pilih2 == 7)
                   
					{
					    bubbleSortDesc(kb.hw, jumlah_hewan);
					    
					
					    string cari_hewan;
					    cout << "Masukkan nama hewan yang ingin dicari: ";
					    cin >> cari_hewan;
					    int hasil = binarySearch(kb.hw, 0, jumlah_hewan - 1, cari_hewan);
					    if (hasil != -1)
					        cout << "Hewan ditemukan di posisi " << hasil + 1 << endl;
					    else
					        cout << "Hewan tidak ditemukan." << endl;
					}
                    else if (pilih2 == 8)
                    {
                        cout << "anda keluar program" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Pilihan tidak valid." << endl;
                    }
                }
                else
                {
                    cout << "sandi salah" << endl;
                    percobaan++;
                }
            }
        }
        else if (log == 2)
        {
            cout << "anda keluar program" << endl;
            break;
        }
        else
        {
            cout << "pilihan tidak ada" << endl;
        }
    }

    // Menghapus memori yang dialokasikan untuk setiap objek hewan
    for (int i = 0; i < jumlah_hewan; i++)
    {
        delete kb.hw[i];
    }

    return 0;
}
