#include <iostream>
#include <string>
using namespace std;

//isi disini
const int MAX_MAHASISWA = 100;

int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];

int jumlahMahasiswa = 0, i;


//isi disini
void tambahMahasiswa() {
	jumlahMahasiswa++;
	/*cout << jumlahMahasiswa;*/
	cout << "Nim		: ";
	cin >> NIM[jumlahMahasiswa];
	cout << "Nama		: ";
	cin >> nama[jumlahMahasiswa];
	cout << "Tahun Masuk	: ";
	cin >> tahunMasuk[jumlahMahasiswa];

};
//isi disini
void tampilkanSemuaMahasiswa() {
	for (int i = 1; i < jumlahMahasiswa; i++){
		cout << "Nim		: " << NIM[i] << endl;
		cout << "Nama		: " << nama[i] << endl;
		cout << "Tahun Masuk	: " << tahunMasuk[i] << endl;
		cout << "\n";
	}
};
//isi disini
void algorithmacariMahasiswaByNIM() {
	//linear search
	while (true){
		int nim;
		cout << "\n masukan nim yang ingin di cari: ";
		cin >> nim;
		for (int i = 0; i < jumlahMahasiswa; i++) {
			if (NIM[i] == nim) {
				cout << "Nim		: " << NIM[i] << endl;
				cout << "Nama		: " << nama[i] << endl;
				cout << "Tahun Masuk	: " << tahunMasuk[i] << endl;
				break;
			}
		}
		if (i == jumlahMahasiswa)
			cout << "\n" << nim << "nim yang anda masukan tidak di temukan \n";

		break;
	}
};
//isi disini
/*quick sort*/
void swap(int x, int y) {
	int temp;
	temp = NIM[x];
	NIM[x] = NIM[y];
	NIM[y] = temp;
}

void algorithmaSortByTahunMasuk(int low, int high) {
	int pivot, i, j;

	if (low > high)                                                 // langkah 1
		return;

	pivot = NIM[low];                                               // langkah 2

	i = low + 1;                                                    // langkah 3
	j = high;                                                       // langkah 4

	while (i <= j) {                                                 // langkah 10

		while ((NIM[i] <= pivot) && (i <= high)) {                   // langkah 5
			i++;                                                    // langkah 6
		}

		while ((NIM[j] > pivot) && (j >= low)) {                     // langkah 7
			j--;                                                    // langkah 8
		}


		if (i < j) {                                                // langkah 9
			swap(i, j);
		}
	}
	if (low < j) {                                                  // langkah 11
		swap(low, j);
	}

	algorithmaSortByTahunMasuk(low, j - 1);                                            // langkah 12
	algorithmaSortByTahunMasuk(j + 1, high);
};


int main() {
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			tambahMahasiswa();
			break;
		case 2:
			tampilkanSemuaMahasiswa();
			break;
		case 3:
			algorithmacariMahasiswaByNIM();
			break;
		case 4:
			algorithmaSortByTahunMasuk(0, jumlahMahasiswa - 1);
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}


/*soal*/
/*
2. Berdasarkan studi kasus diatas, algoritma apa saja yang anda gunakan ? (10 Poin)
	ada dua yaitu untuk short by nim saya menggunaka linear search dan untuk tahun masuk saya menggunakan Quick Sort
3. Jelaskan perbedaan mendasar antara algorithma stack dan queue! (15 Poin)
	pada tampilan data dimana stack filo (frist in last out), dan queue fifo(frist in frist out)
4. Jelaskan pada saat bagaimana harus menggunakan algorithma stack?(15 poin)
	jika kita ingin data terakhir yang di keluarkan seperti fungsi undo
5. a Seberapa banyak kedalaman yang dimiliki struktur tersebut?
	4
   b Bagaimana cara membaca struktur pohon di atas? (Pilih salah satu metode yaitu Inorder, Preorder atau Postorder Traversal)
	sebagai contoh inorder
	left subtree - root - right subtree (1 - 5 - 8)
*/
