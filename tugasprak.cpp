#include <iostream>
#include <iomanip>
using namespace std;
int pilihan,i;
char lanjut;
bool found = false;
string cari;

struct dataRoti {
    string kode;
    string nama;
    int harga;
};

// Array dari struktur dataRoti
dataRoti roti[5] = {
    {"001", "ROTI TAWAR", 15000},
    {"002", "ROTI COKLAT", 18000},
    {"003", "ROTI KEJU", 20000},
    {"004", "ROTI GANDUM", 22000},
    {"005", "ROTI PISANG", 17000}
};


    void pointer() {
        cout << setfill('=') << setw(30) << " " << endl;
        cout << "Nama\t\tKode\tHarga" << endl;
        cout << setfill('=') << setw(30) << " " << endl;
    
        for (i = 0; i < 5; i++) {
            dataRoti *ptr = &roti[i]; 
            cout << ptr->nama << "\t";
            cout << ptr->kode << "\t";
            cout << ptr->harga << endl;
        }
        cout << setfill('=') << setw(30) << " " << endl;
    }


void sequential(){
    i=0;
    found = false;
    cout << "Masukkan Kode:";
    cin >> cari;
    while (i < 5 && !found) {
        if (roti[i].kode == cari) {
            found = true;
        } else {
            i++;
        }
    }
    if (found) {
        cout << "Data ditemukan sebagai berikut : " << endl;
        cout << "Nama : " << roti[i].nama << ",";
        cout << "kode : " << roti[i].kode << ",";
        cout << "harga : " <<roti[i].harga<< endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void binary (){
    int k,j;
    int n=5;
    found = false;
    cout << "Masukkan nama :";
    cin.ignore(); 
    getline(cin, cari);
    j=4;
    i=0; 
    for(int i = 0; i < n -1; i++){
        for(int j = 0; j <n -1 -i;j++){
            if(roti[j].nama > roti[j+1].nama)
         {
            swap(roti[j], roti[j + 1]);

             
            }
        }
     }
    while (i <= j && !found){
        k=(i+j)/2;
        if (roti[k].nama == cari){
            found = true;
        }
        else if (roti[k].nama> cari){
            j = k-1;
         
        }
        else {
            i = k+1;
        }
    
}if (found){
    cout << "Data ditemukan sebagai berikut : " << endl;
    cout << "Nama : " << roti[k].nama << ",";
    cout << "kode : " << roti[k].kode << ",";
    cout << "harga : " << roti[k].harga<< endl;
}
else {
    cout << "Data tidak ditemukan" << endl;
}
}  

void quick_sort(dataRoti array[], int awal, int akhir) {
    int low = awal, high = akhir;
    dataRoti pivot = array[(awal + akhir) / 2];
    
    do {
        while (array[low].harga < pivot.harga)
            low++;
        while (array[high].harga > pivot.harga)
            high--;

        if (low <= high) {
            swap(array[low], array[high]);
            low++;
            high--;
        }

    } while (low <= high);
    if (awal < high)
        quick_sort(array, awal, high);
    if (low < akhir)
        quick_sort(array, low, akhir);

}

void bubble(){
    int n=5;
    for(int i = 0; i < n -1; i++){
        for(int j = 0; j <n -1 -i;j++){
            if(roti[j].harga < roti[j+1].harga)
         {
            swap(roti[j], roti[j + 1]);

             
            }
        }
     } cout << setfill('=') << setw(30) << " " << endl;
     cout << "Nama\t\tKode\tHarga" << endl;
     cout << setfill('=') << setw(30) << " " << endl;
     for (i = 0; i < 5; i++) {
 
          cout << roti[i].nama<< "\t";
          cout << roti[i].kode<< "\t";
          cout << roti[i].harga<< endl;
     }cout << setfill('=') << setw(30) << " " << endl;
}


int main() {
    system ("CLS");
    do {
        cout << "=============" << "TOKO ROTI RAHMAT" <<"===================="<< endl;
    cout << "1. TAMPILKAN ROTI" << endl;
    cout << "2. Cari berdasarkan kode" << endl;
    cout << "3. Cari berdasarkan nama" << endl;
    cout << "4. Sorting harga roti (ASC)" << endl;
    cout << "5. Sorting harga roti (DESC)" << endl;
    cout << setfill('=') << setw(50) << " " << endl;
    cout << "Pilih menu : ";
    cin  >> pilihan ;
        switch (pilihan) {
            case 1:
                pointer();
                break;
            case 2:
                sequential();
                break;
        
            case 3:
                binary();
                break;
            case 4:
            quick_sort(roti, 0, 5 - 1);
            cout << setfill('=') << setw(30) << " " << endl;
            cout << "Nama\t\tKode\tHarga" << endl;
            cout << setfill('=') << setw(30) << " " << endl;
            for (i = 0; i < 5; i++) {
        
                 cout << roti[i].nama<< "\t";
                 cout << roti[i].kode<< "\t";
                 cout << roti[i].harga<< endl;
            }cout << setfill('=') << setw(30) << " " << endl;
                break;
            case 5:
                bubble();
                break;
            case 6:
                cout << "Exit" << endl;
                cout << "Terima kasih telah menggunakan program ini" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
        cout << "Apakah anda ingin melanjutkan program? (y/t) : ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}