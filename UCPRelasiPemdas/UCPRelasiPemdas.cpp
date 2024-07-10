#include <iostream>
#include <vector>
using namespace std;
//Mendeklarasi class pengarang
class Pengarang;
//Mendeklarasi class buku
class Buku;
//Mendeklarasi classs penerbit 
class Penerbit
{
public:
    //Membuat member dari class penerbit dengan variabel stirng dan vector
    string namaPenerbit;
    vector<Pengarang*> daftarPengarang;
    //Membuat konstruktor dan destruktor dari class penerbit
    Penerbit(string nama) : namaPenerbit(nama)
    {
    }
    ~Penerbit()
    {
    }
    //menambahkan beberapa prosedur untuk digunakan di class pengarang
    void tambahPengarang(Pengarang* pengarang);
    void cetakPengarang();

};

class Pengarang
{
public:
    //Membuat member dari class pengarang dengan variabel stirng dan vector
    string namaPengarang;
    vector<Buku*> daftarBuku; // Daftar buku yang ditulis oleh pengarang


    //Membuat konstruktor dan destruktor dari class pengarang
    Pengarang(string nama) : namaPengarang(nama)
    {
    }
    ~Pengarang()
    {
    }
    //menambahkan beberapa prosedur yang berkaitan  untuk digunakan di class bukuuu
    void tambahBuku(Buku* buku);
    void cetakBuku();
};

class Buku
{
public:

    /*!Membuat member dari class buku dengan variabel stirng dan vector*/
    string judulBuku;
    vector<Pengarang*> daftarPengarang; // Daftar pengarang yang menulis buku

    //Membuat konstruktor dan destruktor dari class buku
    Buku(string judul) : judulBuku(judul)
    {
    }
    ~Buku()
    {
    }
    //menambahkan beberapa prosedur yang berkaitan  untuk digunakan di class pengarang
    void tambahPengarang(Pengarang* pengarang)
    {
        daftarPengarang.push_back(pengarang);
    }

    void cetakPengarang()
    {
        cout << "Pengarang dari buku \"" << judulBuku << "\":\n";
        for (auto& pengarang : daftarPengarang)
        {
            cout << pengarang->namaPengarang << "\n";
        }
    }
};

//menambahkan beberapa prosedur yang berkaitan  untuk digunakan di class pengarang
void Penerbit::tambahPengarang(Pengarang* pengarang)
{
    daftarPengarang.push_back(pengarang);
}
void Penerbit::cetakPengarang() {

}

//menambahkan beberapa prosedur yang berkaitan  untuk digunakan di class buku
void Pengarang::tambahBuku(Buku* buku)
{
    daftarBuku.push_back(buku);
    buku->tambahPengarang(this);
}

void Pengarang::cetakBuku()
{


    //Membuat konstruktor dan destruktor dari void pengarang 
    cout << "\nBuku yang dikarang oleh \"" << namaPengarang << "\":\n";
    for (auto& buku : daftarBuku)
    {
        cout << buku->judulBuku << "\n";
    }
}
//Membuat integer mainn
int main()
{

    Pengarang* pengarang1 = new Pengarang("Joko");
    Pengarang* pengarang2 = new Pengarang("Lia");
    Pengarang* pengarang3 = new Pengarang("Asroni");
    Pengarang* pengarang4 = new Pengarang("Giga");

    Penerbit* penerbit1 = new Penerbit("Gama Press");
    Penerbit* penerbit2 = new Penerbit("Intan Pariwara");

    Buku* buku1 = new Buku("Fisika");
    Buku* buku2 = new Buku("Algoritma");
    Buku* buku3 = new Buku("Basis data");
    Buku* buku4 = new Buku("Dasar Pemograman");
    Buku* buku5 = new Buku("Matematika");
    Buku* buku6 = new Buku("Multimedia");

    pengarang1->tambahBuku(buku1);
    pengarang1->tambahBuku(buku2);
    pengarang2->tambahBuku(buku3);
    pengarang3->tambahBuku(buku4);
    pengarang4->tambahBuku(buku5);
    pengarang4->tambahBuku(buku6);

    pengarang1->cetakBuku();
    pengarang2->cetakBuku();
    pengarang3->cetakBuku();
    pengarang4->cetakBuku();

    return 0;
}