#include <stdio.h>
#include <stdlib.h>


//struct yap�lar�nda typedef kullanarak 'bid' ismini 'int teklifveren_no , double teklif' ile e�de�er hale getirdim.Ayn� �ekilde 'Artirma' ismi i�in de yapt�m.
//Yani art�k 'bid' zaten struct tan�m�n� temsil ediyor ve i�inde tan�mlananlar� kaps�yor,k�saca bu �ekilde yaz�yorum.
typedef struct
{
    int teklifveren_no;
    double teklif;
} bid;

typedef struct
{
    int teklifveren_sayisi;
    bid* teklifler;
} Artirma;

//'bid* teklifler' ifadesi, Artirma yap�s�n�n i�inde teklifler adl� bir i�aret�i oldu�unu belirtir. Bu i�aret�i,bid t�r�ndeki verilere i�aret eder. 

//�demeyi hesaplamas� i�in double tipinde bir fonksiyon olu�turuyorum.

// Fonksiyon, belirli bir art�rma durumunda kazanan teklif verenin �demesini hesaplar.Parantezin i�inde ise parametreleri yer al�yor.
//a: Artirma t�r�ndeki yap�.
//kazanan_no: Kazanan teklif verenin indeksi.
//Geriye ise �demenin de�erini d�nd�r�yor.


//double cinsinden �demeyi tan�ml�yorum.For d�ng�s� ile her teklife kontrol sa�lan�yor.
//E�er i de�eri kazanan no'ya e�it ise bu teklif kazanan teklif oluyor ve kazanan teklif 'odeme' de�i�kenine ekleniyor.

double odemeyi_hesapla(Artirma a, int kazanan_no)
{
    double odeme = 0.0;

    for (int i = 0; i < a.teklifveren_sayisi; i++)
    {
        if (i == kazanan_no)
        {
            odeme += a.teklifler[i].teklif;
        }
    }
    return odeme;
}


//Sonra bir a��k art�rma fonksiyonu olu�turuyorum.
//a: Artirma t�r�ndeki bir yap�. Bu yap�; art�rman�n genel bilgilerini,teklif veren say�s�n� (`teklifveren_sayisi`) ve teklifleri (`teklifler`) i�erir.

//'enyuksek_teklif` ve `kazanan_no` adl� de�i�kenleri tan�mlad�m.En y�ksek teklifi -1 ve kazanan teklif verenin indeksini de -1 ile ba�latt�m.
//For d�ng�s� ile her teklifi kontrol ettim. E�er teklif, o ana kadar g�r�len en y�ksek tekliften b�y�kse, en y�ksek teklif ve kazanan�n indeksi g�ncellenmesini sa�lad�m.
//Kazanan bulununca, kazanan teklif sahibinin numaras� ekranda yazd�r�lacak.Kazanan bulunamazsa else blo�u �al��acak ve ekranda 'Acik artirmada kazanan yok!' uyar�s� yazacak.
//Ard�ndan `odemeyi_hesapla` fonksiyonu �a�r�l�p kazanan teklif verenin �demesi hesaplanacak ve ekrana yazd�r�lacak.

void acikarttirma(Artirma a)
{
    double enyuksek_teklif = -1.0;
    int kazanan_no = -1;

    for (int i = 0; i < a.teklifveren_sayisi; i++)
    {
        if (a.teklifler[i].teklif > enyuksek_teklif)
        {
            enyuksek_teklif = a.teklifler[i].teklif;
            kazanan_no = i;
        }
    }

    if (kazanan_no != -1)
    {
        printf("Kazanan Teklif Sahibi: %d\n", a.teklifler[kazanan_no].teklifveren_no);

        double odeme = odemeyi_hesapla(a, kazanan_no);

        printf("Odeme: %.2f\n", odeme);
    }
    else
    {
        printf("Acik artirmada kazanan/katilimci yok!\n");
    }
}

//Son olarak, bir art�rma sim�lasyonunu ger�ekle�tiriliyor. Art�rmaya kat�lan teklif verenlerin tekliflerini i�eren bir dizi olu�turdum.
// Ard�ndan, bu teklifler aras�nda en y�ksek teklifi veren teklif verenin belirlenmesi i�in acikarttirma fonksiyonunu �a��rd�m.
// �nce `Artirma` t�r�ndeki yap� olan `artirma` tan�mlad�m ve bellekte teklif veren say�s� kadar yer ayr�lm�� oldu.Teklif veren say�s� belirledim.(�rn:5)
// `artirma.teklifler` adl� dinamik bellek alan�na teklif verenlerin bilgilerini i�eren `bid` t�r�ndeki yap�lar� yerle�tirdim.
// Her bir teklif verenin numaras� ve teklifi belirlenir.
//`acikarttirma` fonksiyonu �a��r�p, en y�ksek teklifi veren teklif verenin belirlenmesini ve �deme miktar�n�n hesaplanmas�n� sa�lad�m.
//Son olarak,'free' ile dinamik bellek alan�n� serbest b�rakarak bellek s�z�nt�s�n�n �nlenmesini sa�lad�m.
//malloc (Memory Allocation),dinamik bellek tahsisini sa�layan bir standart k�t�phane fonksiyonu oldu�u i�in bu fonksiyonu kulland�m.


int main()
{
    Artirma artirma;
    artirma.teklifveren_sayisi = 5;
    artirma.teklifler = (bid*)malloc(artirma.teklifveren_sayisi * sizeof(bid));
    
    artirma.teklifler[0] = (bid){1, 140.0};   // 1. teklif veren, 140 birim teklif
    artirma.teklifler[1] = (bid){2, 300.0};   // 2. teklif veren, 300 birim teklif
    artirma.teklifler[2] = (bid){3, 180.0};   // 3. teklif veren, 180 birim teklif
    artirma.teklifler[3] = (bid){4, 305.0};	  // 4. teklif veren, 305 birim teklif
    artirma.teklifler[4] = (bid){5, 190.0};	  // 5. teklif veren, 190 birim teklif
    
	
    acikarttirma(artirma);

    free(artirma.teklifler);

    return 0;
}
