#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

int main()
{   
	setlocale(LC_ALL, "Turkish");
	string okunan;
	vector<string> cevap_anahtari(5);
	int sayac = 0, sayac2 = 0, soru_sayisi, puan = 0, ogrsayisi = 0, puansay = 0;
	string s, parca, sayilan;;
	ifstream sayma("input.txt");
	while (getline(sayma,sayilan)) // tüm satýrlarý sayýp ilk 2 satýrý çýkararak öðrenci sayýsý buluyoruz. 
	{
		ogrsayisi++;
	}
	sayma.close();
	ogrsayisi -= 2;
	vector<int> puanlar(ogrsayisi);
    ifstream oku("input.txt");
	while (getline(oku,okunan))
	{
		puan = 0;
		int ssay = 0;
		if (sayac==0)// soru sayýsý deðiþkene atama
		{
			
			soru_sayisi = stoi(okunan);
			sayac++;
		}
		if (sayac2==1) // cevap anahtarý diziye atama
		{
			
			s = okunan;
			
			cevap_anahtari.resize(soru_sayisi);
			int p=0;
			for (int w = 0; w < okunan.length(); w++)
			{
				
				
				parca = s.substr(w, 1);
				if (parca != ",")
				{
					cevap_anahtari[p] = parca;
					p++;
				}
				
			
			}
			sayac2++;
			

		}
		if (sayac == 1 && sayac2 > 2)
		{
			s = okunan;
			
			for (int r = 10; r < s.length(); r++)
			{
				parca = s.substr(r, 1);
				if (parca!=",")
				{
					
					
					if (parca==cevap_anahtari[ssay])
					{
						puan = puan + 4;
					}
					else if (parca == " ")
					{
						puan = puan + 0;
					}
					else
					{
						puan = puan - 1;
					}
					
					ssay++;
				}
				
				
			}
			
			
			puanlar[puansay] = puan;
			puan = 0;
			puansay++;
		}
		sayac2++;
	}
	
	int buyuk=0, kucuk=0, medyan, aciklik,toplam=0,ortalama=0,medyan2;
	
	
	int tut;
	for (int sr = 0; sr < ogrsayisi; sr++)
	{
		toplam += puanlar[sr];
		for (int sr1 = 0; sr1 < ogrsayisi; sr1++)
		{
			if (puanlar[sr1]>puanlar[sr])
			{
				tut = puanlar[sr];
				puanlar[sr] = puanlar[sr1];
				puanlar[sr1] = tut;
			}
		}
	}
	kucuk = puanlar[0];
	buyuk = puanlar[ogrsayisi - 1];
	aciklik = buyuk - kucuk;
	ortalama = toplam / ogrsayisi;

	for (int ogr = 0; ogr < ogrsayisi; ogr++)
	{
		cout << puanlar[ogr] << ",";
	
	}
	cout << "Output.txt dosyasý oluþturulmuþtur.";
	ofstream kayit("output.txt");

	kayit << "En yüksek not = " << buyuk <<endl;
	kayit << "En düþük not = " << kucuk << endl;
	kayit << "Ortalama =" << ortalama << endl;
	kayit << "Açýklýk = " << aciklik << endl;
	if (ogrsayisi%2==0)
	{
		medyan = puanlar[ogrsayisi  / 2 -1];
		medyan2 = puanlar[ogrsayisi / 2];
		kayit << "Medyan = " << medyan << " " << medyan2 <<endl;
	}
	else
	{
		medyan = puanlar[ogrsayisi  / 2  ];
		kayit << "Medyan = " << medyan<< endl;
	}
	
	kayit.close();

	


	
	

}

