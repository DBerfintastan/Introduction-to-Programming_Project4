/*************************************************************************************************************************
**************************************************************************************************************************
*************************   ÖĞRENCİ ADI SOYADI: DENİZ BERFİN TAŞTAN             ******************************************
*************************   NUMARA: B181210010                                  ******************************************
*************************   GRUBU : D                                           ******************************************
***************************************************************************************************************************
***************************************************************************************************************************/


#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class DosyaYonetimi
{
public:
	string isimSec()  //İsim seçme fonksiyonu
	{

		ifstream dosyadanAktar("isimler.txt");  // İsimler dosyasından isim çeker
		string isim[5000];
		for (int a = 0; a < 5000; a++)
		{
			dosyadanAktar >> isim[a];
		}
		return isim[rand() % 4945]; // Çekilen ismin rastgele olmasını sağlar.
	}
	string soyisimSec()
	{

		ifstream dosyadanAktar("soyisimler.txt"); // Soyisimler dosyasından soyisim çeker.
		string soyisim[300];
		for (int a = 0; a < 300; a++)
		{
			dosyadanAktar >> soyisim[a];
		}
		return soyisim[rand() % 278]; // Çekilen soyismin rastgele olmasını sağlar.
	}
	string kayitSec()
	{
		string kayit = "";
		ifstream dosyadanAktar("kayitlar.txt");
		while (dosyadanAktar.good())      // dosyanın sonuna gelip gelmedğini kontrol eder.
		{
			string okuma;
			dosyadanAktar >> okuma;
			kayit = kayit + "\n" + okuma; //önceki kaydı silmesini engeller.
		}
		return kayit;
	}
	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;
	void ustYazdir(int elemanSayisi)
	{

		cout << solUstKose;
		for (int i = 0; i < elemanSayisi; i++)
		{
			cout << duz;
		}
		cout << sagUstKose;
	}

	void altYazdir(int elemanSayisi)
	{
		cout << solAltKose;
		for (int i = 0; i < elemanSayisi; i++)
		{
			cout << duz;
		}
		cout << sagAltKose;
	}
	string intStringCevir(int a) // Bir fonksiyonun içinde aynı tür değişke olmasını sağlamak için yazılır. (Bu kısmı internetten aldım hocam :))
	{
		string b;
		stringstream Stream;
		Stream.str(b);
		Stream << a;
		b = Stream.str();
		return b;
	}

};

class Ogrenci
{
private:
	string adi;
	string soyadi;
	int numara;
public:
	Ogrenci() // Başlangıç değeri atamak için yaratıcı fonksiyon.
	{
		adi = "";
		soyadi = "";
		numara = 0;
	}
	void ogrenciOlustur()  //dosya yönetim içindeki fonksiyonları kullanarak öğrenci bilgileri oluşturuyor.
	{
		DosyaYonetimi OgrenciBilgileri; // OgrenciBilgileri=Nesne sayesinde DosyaYonetimi classını ve içindeki fonksiyonları Ogrenci classının içine taşıdık.
		adi = OgrenciBilgileri.isimSec();
		soyadi = OgrenciBilgileri.soyisimSec();
		numara = rand() % 100 + 100;
	}
	void ogrenciEkle(string isim, string soyisim, int no) // adi,soyadi ve numaraya değer atar.
	{
		adi = isim;
		soyadi = soyisim;
		numara = no;
	}
	void ogrenciSil() // adi,soyadi ve numaradaki değerleri sıfırlar.
	{
		adi = "";
		soyadi = "";
		numara = 0;
	}
	string isimGoster()
	{
		return adi;
	}
	string soyisimGoster()
	{
		return soyadi;
	}
	int numaraGoster()
	{
		return numara;
	} // yukarıdaki 3 fonksiyon değer döndürmeye yarar.
};


class Sinif
{
private:
	string sinifIsmi = "";
	Ogrenci Ogrenciler[100]; // Sinif classında kullanılmak üzere Ogrenci claasından bir öğrenci listesi oluşturur.

public:
	void OgrenciEkle(Ogrenci rastgeleOgrencim) // Fonksiyon öğrenci listesindeki öğrencileri sayar. Eğer numarası 0 olan ( boş olan alan) varsa oraya öğrenci atar.
	{
		for (int a = 0; a < 100; a++)
		{
			if (Ogrenciler[a].numaraGoster() == 0)
			{
				Ogrenciler[a] = rastgeleOgrencim;
				return;
			}
		}
	}

	void OgrenciSil(int numara) // Fonksiyon öğrenci listesindeki öğrencileri sayar. Eğer numarası 0 olmayan ( boş olmayan alan) varsa oradan öğrenci siler.
	{
		for (int a = 0; a < 100; a++)
		{
			if (Ogrenciler[a].numaraGoster() == numara)
			{
				Ogrenciler[a].ogrenciSil();
			}
		}
	}

	string sinifIsmiGoster() // Sınıf ismini döndürür.
	{
		return sinifIsmi;
	}
	void sinifIsmiDegistir(string sinifinismi) // Sınıf isminin yerine başka bir sınıf ismi atar.
	{
		sinifIsmi = sinifinismi;
	}
	void sinifCiz(int a, string secenek) // sınıfın içine öğrencinin adını soyadını ve numarasını atar.
	{
		DosyaYonetimi b;
		if (secenek == "ismi")
			cout << setw(11) << Ogrenciler[a].isimGoster() << " ";
		else if (secenek == "soyismi")
			cout << setw(11) << Ogrenciler[a].soyisimGoster() << " ";
		else
			cout << setw(11) << Ogrenciler[a].numaraGoster() << " ";
	}
	string sinifYazdir(string Ogrencisayisi) // kayitlar.txt yazdırırken kullanılıyor.
	{
		DosyaYonetimi b;
		string yazdir = sinifIsmi + '\n' + Ogrencisayisi;
		for (int i = 0; i < 100; i++)
		{
			if (Ogrenciler[i].isimGoster() != "")
			{
				yazdir += '\n' + Ogrenciler[i].isimGoster();
				yazdir += ' ' + Ogrenciler[i].soyisimGoster();
				yazdir += ' ' + b.intStringCevir(Ogrenciler[i].numaraGoster());
			}
		}
		return yazdir;
	}
	int OgrenciSay()
	{
		int sayac = 0;
		for (int i = 0; i < 100; i++)
		{
			if (Ogrenciler[i].isimGoster() != "")
			{
				sayac++;
			}
		}
		return sayac;
	}
	int OgrenciSay2()
	{
		int i;
		for (i = 99; i > 0; i--)
		{
			if (Ogrenciler[i].isimGoster() != "")
			{
				return i + 1;
			}
		}
	}
	void OgrenciDuzenle(int no, Ogrenci ogr) // // Fonksiyon öğrenci listesindeki öğrencileri sayar. Eğer numara bir değere eşit olursa parça parça ad soyad ve numara yazdırır.
	{
		for (int i = 0; i < 100; i++)
		{
			if (Ogrenciler[i].numaraGoster() == no)
			{
				Ogrenciler[i].ogrenciEkle(ogr.isimGoster(), ogr.soyisimGoster(), ogr.numaraGoster());
			}
		}

	}
};
class Okul
{
private:
	Sinif siniflar[10]; // Sınıf classından Okul classı için sınıf listesi oluşturuyor.
public:
	void OgrenciDegistirme(int no, Ogrenci ogr)
	{
		for (int i = 0; i < 10; i++)
		{
			if (siniflar[i].sinifIsmiGoster() != "") // Sınıf boş değilse verilen numaradaki öğrenciye gidip onun yerine yeni öğrenci atıyor.
			{
				siniflar[i].OgrenciDuzenle(no, ogr);
			}
		}
	}

	void ogrEkle(string sinifIsmi, Ogrenci Ogrencim) // Eğer sınıf boş değilse sınıfa öğrenci ekliyor.
	{
		for (int i = 0; i < 10; i++)
		{
			if (siniflar[i].sinifIsmiGoster() == sinifIsmi)
			{
				siniflar[i].OgrenciEkle(Ogrencim);
				return;
			}
		}
	}
	string sinifaIsimVer()
	{
		DosyaYonetimi d;
		char harf[24] = "ABCDEFGHIJKLMNOPRSTUVYZ";
		int sayac = 0; // Sınıfa rastgele harf atar.
		for (int a = 0; a < 10; a++)
		{
			if (siniflar[a].sinifIsmiGoster() != "")
			{
				sayac++;
			} // Sınıfın kaçıncı sınıf olduğunu yazar.
		}
		return d.intStringCevir(sayac + 1) + harf[rand() % 23];
	}
	void isimVerSinifa(string eskiIsim, string isim)
	{
		for (int a = 0; a < 10; a++)
		{
			if (siniflar[a].sinifIsmiGoster() == eskiIsim)
			{
				siniflar[a].sinifIsmiDegistir(isim);
				return;
			}
		}
	}
	void sinifCiz() //sınıf şablonu çizmke için kullanılır.
	{
		DosyaYonetimi b;
		int sayac = 0;  // şekil için sutün sayısını sayar.
		int sayac2 = 0; // şekil için satır sayısını sayar.
		for (int a = 0; a < 10; a++)
		{
			if (siniflar[a].sinifIsmiGoster() != "")
			{
				if (siniflar[a].OgrenciSay2() > sayac2)
				{
					sayac2 = siniflar[a].OgrenciSay2();// maksimum kaç sütun olduğunu sayar
				}
				sayac++;    // kaç tane sınıf olduğunu öğreneceğiz.

				b.ustYazdir(10);
			}


		}
		cout << endl;
		for (int a = 0; a < sayac; a++)
		{
			cout << "     " << siniflar[a].sinifIsmiGoster() << "     ";
		}
		cout << endl;
		for (int a = 0; a < sayac; a++)
		{
			b.altYazdir(10);
		}
		cout << endl;
		for (int i = 0; i < sayac2; i++)
		{
			for (int a = 0; a < sayac; a++)
			{
				b.ustYazdir(10);
			}
			cout << endl;
			for (int a = 0; a < sayac; a++)
			{
				siniflar[a].sinifCiz(i, "ismi");
			}
			cout << endl;
			for (int a = 0; a < sayac; a++)
			{
				siniflar[a].sinifCiz(i, "soyismi");
			}
			cout << endl;
			for (int a = 0; a < sayac; a++)
			{
				siniflar[a].sinifCiz(i, "numara");
			}
			cout << endl;
			for (int a = 0; a < sayac; a++)
			{
				b.altYazdir(10);
			}
			cout << endl;
		}
	}
	void kayitAta() // kayıtlar dosyasından parça parça bilgi alır ve üstüne parça parça yazar.
	{
		DosyaYonetimi kayitNesnesi;
		string kayit = kayitNesnesi.kayitSec();
		stringstream Stream;
		Stream.str(kayit);
		for (int x = 0; x < 10; x++)
		{
			string sinifIsim;
			Stream >> sinifIsim;
			isimVerSinifa("", sinifIsim);
			int ogrsayi;
			Stream >> ogrsayi;
			if (siniflar[x].sinifIsmiGoster() == sinifIsim)
			{

				for (int a = 0; a < ogrsayi; a++)
				{
					string isim,
						soyisim;
					int no;

					Stream >> isim;
					Stream >> soyisim;
					Stream >> no;
					Ogrenci ogr;
					ogr.ogrenciEkle(isim, soyisim, no); // bağımsız öğrenci
					siniflar[x].OgrenciEkle(ogr); // bağladık
				}
			}
		}
	}
	string kayitBaslat()
	{
		DosyaYonetimi d;
		string kayit = "";
		for (int i = 0; i < 10; i++)
		{
			if (siniflar[i].sinifIsmiGoster() != "")
				kayit += '\n' + siniflar[i].sinifYazdir(d.intStringCevir(siniflar[i].OgrenciSay()));

		}
		return kayit;
	}
};
class Program
{
	Okul okulum;
public:
	void progCalistir()
	{
		okulum.kayitAta();

		while (true)
		{
			system("CLS");
			okulum.sinifCiz();
			menu();
		}
	}

	void menu()
	{
		cout << "1.Ogrenci Ekle" << endl;
		cout << "2.Sinif Ekle" << endl;
		cout << "3.Ogrenci Degistir" << endl;
		cout << "4.Ogrenci Sil" << endl;
		cout << "5.Sinif Sil" << endl;
		cout << "6.Cikis" << endl;
		int islem;
		cin >> islem;
		switch (islem) 
		{
		case 1:
			OgrenciEkle();
			break;
		case 2:
			okulum.isimVerSinifa("", okulum.sinifaIsimVer());
			break;
		case 3:
			OgrenciDegistir();
			break;
		case 4:
			OgrenciSil();
			break;
		case 5:
			sinifSil();
			break;
		case 6:
			kaydet();
			exit(0);
		}
	}
	void OgrenciEkle()
	{
		string secilensinif;
		cout << "Sinif Seciniz:";
		cin >> secilensinif;
		Ogrenci Ogrenci1;
		Ogrenci1.ogrenciOlustur();
		okulum.ogrEkle(secilensinif, Ogrenci1); //Seçilen sınıfa öğrenci eklemek için Ogrenci classından ogrenciOlustur fonksiyonunu çağırdık.
	}
	void OgrenciDegistir()
	{
		int degisecekNo;
		cout << "Numara giriniz:";
		cin >> degisecekNo;
		Ogrenci ogr;
		ogr.ogrenciOlustur();
		okulum.OgrenciDegistirme(degisecekNo, ogr); //Seçilen öğrenciyi değiştirmek için Okul classından OgrenciDegistirme fonksiyonunu çağırdık.
	}
	void OgrenciSil()
	{
		int silinecekNo;
		cout << "Numara giriniz:";
		cin >> silinecekNo;
		Ogrenci ogr;
		cout << ogr.isimGoster();
		okulum.OgrenciDegistirme(silinecekNo, ogr);
		system("pause"); // Seçilen numaradaki öğrenciyi silmek için Ogrenci classından isimGoster fonksiyonunu çağırdık ve o numaraya sahip öğrencinin bilgilerini gördükten sonra Okul classından çağırdığımız OgrenciDegistir fonksiyonunu çağırdık.
	}
	void sinifSil()
	{
		string silinecekSinif;
		cout << "Sinif Adi:";
		cin >> silinecekSinif;
		okulum.isimVerSinifa(silinecekSinif, "");
		system("pause");
	}
	void kaydet()
	{
		string kayit = okulum.kayitBaslat();
		ofstream dosyayaYaz("kayitlar.txt", ios::out);
		dosyayaYaz << kayit;
	}
};

int main()
{
	srand(time(0));
	Program a;
	a.progCalistir();
}