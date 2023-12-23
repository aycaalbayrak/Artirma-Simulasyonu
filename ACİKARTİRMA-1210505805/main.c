#include <stdio.h>
#include <stdlib.h>


//struct yapýlarýnda typedef kullanarak 'bid' ismini 'int teklifveren_no , double teklif' ile eþdeðer hale getirdim.Ayný þekilde 'Artirma' ismi için de yaptým.
//Yani artýk 'bid' zaten struct tanýmýný temsil ediyor ve içinde tanýmlananlarý kapsýyor,kýsaca bu þekilde yazýyorum.
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

//'bid* teklifler' ifadesi, Artirma yapýsýnýn içinde teklifler adlý bir iþaretçi olduðunu belirtir. Bu iþaretçi,bid türündeki verilere iþaret eder. 

//Ödemeyi hesaplamasý için double tipinde bir fonksiyon oluþturuyorum.

// Fonksiyon, belirli bir artýrma durumunda kazanan teklif verenin ödemesini hesaplar.Parantezin içinde ise parametreleri yer alýyor.
//a: Artirma türündeki yapý.
//kazanan_no: Kazanan teklif verenin indeksi.
//Geriye ise ödemenin deðerini döndürüyor.


//double cinsinden ödemeyi tanýmlýyorum.For döngüsü ile her teklife kontrol saðlanýyor.
//Eðer i deðeri kazanan no'ya eþit ise bu teklif kazanan teklif oluyor ve kazanan teklif 'odeme' deðiþkenine ekleniyor.

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


//Sonra bir açýk artýrma fonksiyonu oluþturuyorum.
//a: Artirma türündeki bir yapý. Bu yapý; artýrmanýn genel bilgilerini,teklif veren sayýsýný (`teklifveren_sayisi`) ve teklifleri (`teklifler`) içerir.

//'enyuksek_teklif` ve `kazanan_no` adlý deðiþkenleri tanýmladým.En yüksek teklifi -1 ve kazanan teklif verenin indeksini de -1 ile baþlattým.
//For döngüsü ile her teklifi kontrol ettim. Eðer teklif, o ana kadar görülen en yüksek tekliften büyükse, en yüksek teklif ve kazananýn indeksi güncellenmesini saðladým.
//Kazanan bulununca, kazanan teklif sahibinin numarasý ekranda yazdýrýlacak.Kazanan bulunamazsa else bloðu çalýþacak ve ekranda 'Acik artirmada kazanan yok!' uyarýsý yazacak.
//Ardýndan `odemeyi_hesapla` fonksiyonu çaðrýlýp kazanan teklif verenin ödemesi hesaplanacak ve ekrana yazdýrýlacak.

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

//Son olarak, bir artýrma simülasyonunu gerçekleþtiriliyor. Artýrmaya katýlan teklif verenlerin tekliflerini içeren bir dizi oluþturdum.
// Ardýndan, bu teklifler arasýnda en yüksek teklifi veren teklif verenin belirlenmesi için acikarttirma fonksiyonunu çaðýrdým.
// Önce `Artirma` türündeki yapý olan `artirma` tanýmladým ve bellekte teklif veren sayýsý kadar yer ayrýlmýþ oldu.Teklif veren sayýsý belirledim.(Örn:5)
// `artirma.teklifler` adlý dinamik bellek alanýna teklif verenlerin bilgilerini içeren `bid` türündeki yapýlarý yerleþtirdim.
// Her bir teklif verenin numarasý ve teklifi belirlenir.
//`acikarttirma` fonksiyonu çaðýrýp, en yüksek teklifi veren teklif verenin belirlenmesini ve ödeme miktarýnýn hesaplanmasýný saðladým.
//Son olarak,'free' ile dinamik bellek alanýný serbest býrakarak bellek sýzýntýsýnýn önlenmesini saðladým.
//malloc (Memory Allocation),dinamik bellek tahsisini saðlayan bir standart kütüphane fonksiyonu olduðu için bu fonksiyonu kullandým.


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
