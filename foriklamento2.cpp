#include <iostream>
#include <fstream>
#include<iomanip>
#include<string>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include <vector>
using namespace std;

class Depo
{
public:
	string urun_ad;
	float urun_kalori;
	float urun_stok;
	float urun_fiyat;

	Depo() : urun_ad(""), urun_kalori(0.0f), urun_stok(0.0f), urun_fiyat(0.0f)
	{
	}

	Depo(string ua, float k, float s, float f) : urun_ad(ua), urun_kalori(k), urun_stok(s), urun_fiyat(f)
	{
	}

	void depo_yazdir() {

		cout << "\n     -urun bilgileri-     " << endl;
		cout << "\t urun adi         :" << urun_ad << endl;
		cout << "\t urun kalorisi    :" << urun_kalori << endl;
		cout << "\t urun stok miktari:" << urun_stok << endl;
		cout << "\t urun fiyati        :" << urun_fiyat << endl;
	}

	void depo_oku() {
		cout << "\n     -urun bilgileri-     " << endl;
		cout << "\t urun adi         :"; cin >> urun_ad;
		cout << "\t urun kalorisi    :"; cin >> urun_kalori;
		cout << "\t urun stok miktari:"; cin >> urun_stok;
		cout << "\t urun fiyati      :"; cin >> urun_fiyat;
	}

	~Depo() {}

};

class Yemek {
public:
	string yemek_ad;
	float yemek_fiyat;

	void yemek_yazdir() {
		cout << "\n      -yemek bilgileri-" << endl;
		cout << "\t yemek adi        :" << yemek_ad << endl;
		cout << "\t yemek fiyati         :" << yemek_fiyat << endl;
	}

	void yemek_oku() {
		cout << "\n      -yemek bilgileri- " << endl;
		cout << "\t yemek adi        :"; cin >> yemek_ad;
		cout << "\t yemek fiyati         :"; cin >> yemek_fiyat;
	}
};

void depo(); //bildirim 
void yemek_islem();//bildirim 
void yemek_uretim();
void yemek_satis();
void gelir_gider();

void yemek_malzeme(string);// yemek malzemeleri ekleme 
void yemek_malzeme_yazdir(string);
int urun_kontrol(string);


int main() {
	setlocale(LC_ALL, "Turkish");
	int secim;

	do {
		do {
			system("CLS");  //ekranı temizler
			cout << "---------Menü-----------" << endl;
			cout << "\t 1- Depo islemleri   :" << endl;
			cout << "\t 2- Yemek islemleri  :" << endl;
			cout << "\t 3- Yemek uretim     :" << endl;
			cout << "\t 4- Yemek satis      :" << endl;
			cout << "\t 5- gelir-gider      :" << endl;
			cout << "\t 6- cikis            :" << endl;
			cout << "\t Seciminizi ekrana giriniz:"; cin >> secim;
		} while (!(secim >= 1 && secim < 7));
		if (secim == 1) 
		{
			depo();
		}

		else if (secim == 2) 
		{
			yemek_islem();
		}

		else if (secim == 3)
		{
			yemek_uretim();
		}

		else if (secim == 4) {
			yemek_satis();
		}

		/*else if (secim == 5) {
			gelir_gider();
		}*/

	} while (secim != 6);
}

//MENU -> 1, DEPO İŞLEMLERİ
void depo()
{
	int secim;
	do {
		do {
			system("CLS");
			cout << "-----------Depo Menü----------" << endl;
			cout << "\t 1- Kayit ekle:             " << endl;
			cout << "\t 2- Kayit sil:              " << endl;
			cout << "\t 3- Kayit guncelle:         " << endl;
			cout << "\t 4- Ana menüye dön:         " << endl;
			cout << "\t Seciminizi konsola giriniz:"; cin >> secim;
		} while (!(secim >= 1 && secim < 5));

		// KAYIT EKLEME
		if (secim == 1) {
			string kontrol;
			Depo d;
			fstream depo_kayit;
			depo_kayit.open("depo.txt", ios::app);

			do {
				d.depo_oku();

				depo_kayit << d.urun_ad << "\n" << d.urun_kalori << "\n" << d.urun_stok << "\n" << d.urun_fiyat << "\n";
				cout << "Yeni kayit edilen urun:" << endl;
				cout << "Ad: " << d.urun_ad << endl;
				cout << "Kalori: " << d.urun_kalori << endl;
				cout << "Stok: " << d.urun_stok << endl;
				cout << "Fiyat: " << d.urun_stok << endl;

				cout << "Yeni kayit eklenecek mi? (y/n)"; cin >> kontrol;

			} while (!(kontrol == "n"));
			depo_kayit.close();
		}

		//KAYİT SİLME
		else if (secim == 2)
		{
			int kod;
			int satir_no;
			int a = 5;

			cout << "Depoda bulunan ürünler: " << endl;
			cout << "1- Elma" << endl;
			cout << "2- Armut" << endl;
			cout << "3- Kivi" << endl;
			cout << "4- Muz" << endl;
			cout << "5- Ayva" << endl;
			cout << "6- Erik" << endl;
			cout << "7- Kola" << endl;
			cout << "8- Fanta" << endl;
			cout << "9- Soda" << endl;
			cout << "10- Ayran" << endl;
			cout << "----------------" << endl;
			cout << "Silmek istediginiz urunun kodunu giriniz: "; cin >> kod;

			satir_no = (a * (kod - 1) + 1);

			// Open the file for reading
			ifstream file("depo.txt");

			if (!file.is_open())
			{
				cout << "Dosya basarili bir sekilde acilamadi." << endl;
			}

			//SATIRLAR OKUNUR
			vector<string> lines;
			string line;
			while (getline(file, line))
			{
				lines.push_back(line);
			}
			file.close();

			/*		int satir_no;
					cout << "Silmek istediğiniz urunun kodunu giriniz: ";
					cin >> satir_no;*/

					// OKUNAN SATİR VE SONRASİNDA GELEN 3 SATİRİ SİLER.
			lines.erase(lines.begin() + satir_no - 1, lines.begin() + satir_no - 1 + 4);

			ofstream outfile("depo.txt", ios::trunc);

			if (!outfile.is_open())
			{
				cerr << "Dosya acilamadi." << endl;
			}

			for (const string& s : lines)
			{
				outfile << s << endl;
			}

			outfile.close();

		}

		//KAYİT GUNCELLEME
		else if (secim == 3)
		{
			fstream file("depo.txt", ios::in | ios::out | ios::binary);

			// Check if the file was opened successfully
			if (!file) {
				cerr << "Error opening file" << endl;
			}

			// Ask the user which line they want to delete
			cout << "Enter the line number to delete: ";
			int lineToDelete;
			cin >> lineToDelete;

			// Go to the beginning of the file
			file.seekg(0, ios::beg);

			// Read each line of the file and store it in a string
			string line;
			int lineNumber = 1;
			while (getline(file, line)) {
				// If this is the line to delete, skip it and the next 3 lines
				if (lineNumber == lineToDelete) {
					for (int i = 0; i < 3; i++) {
						getline(file, line);
					}
					lineNumber += 4;
				}
				//else {
				//	// Otherwise, write the line back to the file
				//	file.seekp(file.tellp() - line.size() - 1, ios::beg);
				//	file << line << endl;
				//	lineNumber++;
				//}
			}

			// Go to the end of the file
			file.seekp(0, ios::end);

			// Ask the user for 4 inputs
			cout << "Enter 4 lines of text: " << endl;
			for (int i = 0; i < 4; i++) {
				getline(cin, line);
				file << line << endl;
			}

			// Close the file
			file.close();

		}

	} while (secim != 4);
}

//MENU -> 2 YEMEK İŞLEMLERİ
void yemek_islem()
{
	int secim;
	do
	{
		do
		{
			system("CLS");
			cout << "\n     -----Yemek Menüsü-----     " << endl;
			cout << "\n 1- Kayit ekle" << endl;
			cout << "\n 2- Kayit sil" << endl;
			cout << "\n 3- Kayit guncelle" << endl;
			cout << "\n 4- Ana menüye dön" << endl;
			cout << "\n Seciminizi konsola giriniz: "; cin >> secim;
		} while (!(secim >= 1 && secim < 5));

		//KAYİT EKLENİR
		if (secim == 1)
		{
			string kontrol;
			Depo d;
			Yemek y;
			fstream yemek_kayit;
			yemek_kayit.open("yemek_cesit.txt", ios::app);
			do
			{
				y.yemek_oku();
				yemek_kayit << y.yemek_ad << "\n" << y.yemek_fiyat << "\n";
				yemek_malzeme(y.yemek_ad);
				cout << "Yeni kayit edilen yemek:" << endl;
				cout << "Ad:" << y.yemek_ad << endl;
				cout << "Fiyat:" << y.yemek_fiyat << endl;

				cout << "Yeni kayıt eklenecek mi? (y/n)"; cin >> kontrol;
			} while (!(kontrol == "n"));
			yemek_kayit.close();


		}

		//KAYİT SİLİNİR
		else if (secim == 2)
		{
			int kod = 0;
			int satir_no;
			int a = 3;

			cout << "Yemek menusu: " << endl;
			cout << "1- Kebap" << endl;
			cout << "2- Çorba" << endl;
			cout << "3- Çigköfte" << endl;
			cout << "4- Makarna" << endl;
			cout << "5- Pilav" << endl;
			cout << "6- Döner" << endl;
			cout << "7- Türlü" << endl;
			cout << "8- Patates yemegi" << endl;
			cout << "9- Kuru Fasulye" << endl;
			cout << "10- Köfte" << endl;
			cout << "11- Püre" << endl;
			cout << "12- Baklava" << endl;
			cout << "13- Kadayif" << endl;
			cout << "14- Sütlaç" << endl;
			cout << "15- Muhallebi" << endl;
			cout << "16- Tulumba" << endl;
			cout << "17- Keskül" << endl;
			cout << "18- Kazandibi" << endl;
			cout << "19- Puding" << endl;
			cout << "20- Güllaç" << endl;
			cout << "-------------------" << endl;
			cout << "Silmek istediginiz yemegin kodunu giriniz: "; cin >> kod;

			satir_no = (a * (kod - 1) + 1);

			// Open the file for reading
			ifstream file("yemek_secim.txt");

			if (!file.is_open())
			{
				cout << "Dosya basarili bir sekilde acilamadi." << endl;
			}

			//SATIRLAR OKUNUR
			vector<string> lines;
			string line;
			while (getline(file, line))
			{
				lines.push_back(line);
			}
			file.close();

			/*		int satir_no;
					cout << "Silmek istediğiniz urunun kodunu giriniz: ";
					cin >> satir_no;*/

					// OKUNAN SATİR VE SONRASİNDA GELEN 3 SATİRİ SİLER.
			lines.erase(lines.begin() + satir_no - 1, lines.begin() + satir_no - 1 + 2);

			ofstream outfile("yemek_secim.txt", ios::trunc);

			if (!outfile.is_open())
			{
				cerr << "Dosya acilamadi." << endl;
			}

			for (const string& s : lines)
			{
				outfile << s << endl;
			}

			outfile.close();
		}

	} while (secim != 4);
}

//MENU -> 3 YEMEK URETİM İSLEMLERİ
void yemek_uretim()
{
	Yemek y;
	char cevap;
	int i = 0;
	int kisi_sayisi;
	float maliyet = 0.0;

	cout << "Kac kisilik yemek pisirilecek? "; cin >> kisi_sayisi;
	cout << "----------------------------------" << endl;

	string ad;
	cout << "\n Pisirilecek yemekler giriliyor " << endl;
	fstream yemek_uretim;
	yemek_uretim.open("yemek_cesit.txt", ios::in);
	do
	{
		
		cout << "Uretilecek yemek adini giriniz: "; cin >> ad;
		fstream yemek;
		yemek.open("yemek_cesit.txt", ios::in);
		yemek >> y.yemek_ad >> y.yemek_fiyat;
		while (!yemek.eof())
		{
			if (ad == y.yemek_ad)
			{
				cout << "Yemek maliyeti haziralaniyor..." << endl;
				string yemek_ad, malzeme_ad;
				float miktar;
				fstream malzeme;
				malzeme.open("malzeme.txt", ios::in);
				malzeme >> yemek_ad >> malzeme_ad >> miktar;
				while (!malzeme.eof())
				{
					if (ad == yemek_ad)
					{
						Depo d;
						fstream depo;
						depo.open("depo.txt", ios::in);
						depo >> d.urun_ad >> d.urun_kalori >> d.urun_stok >> d.urun_fiyat;
						while (!depo.eof())
						{
							if (ad == d.urun_ad)
							{
								maliyet += d.urun_fiyat * kisi_sayisi * miktar;
							}
							depo >> d.urun_ad >> d.urun_kalori >> d.urun_stok >> d.urun_fiyat;
						}
						depo.close();
					}
					malzeme >> yemek_ad >> malzeme_ad >> miktar;
				}
				malzeme.close();
				yemek_uretim << ad << " " << kisi_sayisi << " " << miktar << "\n";
			}
		}
		yemek.close();
		cout << "Yeni yemek eklencek mi? (e/h)"; cin >> cevap;
	} while (!cevap == 'h');
	yemek_uretim.close();
}


//MENU -> 4 YEMEK SATIŞ İŞLEMLERİ
void yemek_satis()
{

}

//MENU -> 5 GELİR GİDER
void gelir_gider()
{

}

int urun_kontrol(string malzeme_ad)
{
	int kontrol = 0;
	Depo d;

	fstream depo_kayit;
	depo_kayit.open("depo.txt", ios::in);
	depo_kayit >> d.urun_ad >> d.urun_kalori >> d.urun_stok >> d.urun_fiyat;

	while (!depo_kayit.eof())
	{
		if (malzeme_ad == d.urun_ad)
		{
			d.depo_yazdir();
			kontrol++;
		}
		depo_kayit >> d.urun_ad >> d.urun_kalori >> d.urun_stok >> d.urun_fiyat;
	}
	if (kontrol == 0)
		cout << "Urun stokta bulunamadi." << endl;
	depo_kayit.close();
	return kontrol;
}

void yemek_malzeme(string yemek_ad)
{
	char kontrol;
	int k = 0;
	string malzeme_ad;
	float miktar;

	cout << "\nYemek malzemeleri giriliyor" << endl;

	fstream malzeme_kayit;
	malzeme_kayit.open("malzeme.txt", ios::app);

	do
	{
		cout << "Malzeme adini giriniz: "; cin >> malzeme_ad;
		k = urun_kontrol(malzeme_ad);

		if (k == 1)
		{
			cout << "Miktar: "; cin >> miktar;
			malzeme_kayit << yemek_ad << " " << malzeme_ad << miktar << "\n";
		}
		cout << "Yeni malzeme eklemek istiyor musunuz? (y/n)"; cin >> kontrol;
	} while (!(kontrol == 'n'));
	malzeme_kayit.close();
}

void yemek_malzeme_yazdir(string ad)
{
	string yemek_ad;
	string malzeme_ad;
	float miktar;
	cout << "\nYemek malzemeleri listeleniyor" << endl;

	fstream depo_malzeme;
	depo_malzeme.open("malzeme.txt", ios::in);
	cout << setw(20) << " malzeme adi " << setw(20) << " malzeme miktari " << endl;

	depo_malzeme >> yemek_ad >> malzeme_ad >> miktar;

	while (!depo_malzeme.eof())
	{
		if (ad == yemek_ad)
		{
			cout << setw(20) << malzeme_ad << setw(20) << miktar << endl;
		}

		depo_malzeme >> yemek_ad >> malzeme_ad >> miktar;
	}
	depo_malzeme.close();
}

