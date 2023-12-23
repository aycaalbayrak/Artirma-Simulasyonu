# Artirma-Simulasyonu
Typedef:Yeni bir tip oluşturmak için kullanılır.Programda değişiklik yapılacağı zaman kolaylık sağlar.Tip tanımlandığı yerden değiştirilince tipi kullanan bütün yerlerde tip değişmiş olur.Structlarda kodların daha sade ve anlaşılır olmasını sağlar.
Pointer:Bir değişkenin adresini tutar. Örneğin kodumda'bid' yapısına 'teklifler' isimli bir işaretçi tanımladım.
Struct yapısı içindeki veriler bellekte tanımlandığı sıra ile tutulur.İki struct pointer tip dönüşümü ile birbirine atanmaya çalışılırsa yani kodumdaki 'bid*teklifler' satırı gibi.Bu satırda 'artirma' yapısının içine 'bid' yapısının verilerini 'teklifler' isimli bir işaretçiyle atamış oldum. Aslında aktarılan yanlızca structa ait bir bellek adresidir değişkenlerin adresi aktarılmaz.Pointer hangi bellek adresini gösterirse o adresten başlayarak sıra ile değişkenlerin bellekteki konumların da aynı sıra ile olduğu varsayılır.


Öncelikle, bid (teklif) ve Artirma (açık artırma) adlı iki farklı struct tanımladım.
'bid' struct'ı, bir teklif verenin numarasını (teklifveren_no) ve verdiği teklifi (teklif) içeriyor. Bu struct, her teklif verenin bilgilerini temsil ediyor.
'Artirma' struct'ı ise, açık artırmanın genel bilgilerini kapsıyor. 'teklifveren_sayisi' adlı değişken, toplam teklif veren sayısını, 'teklifler' ise bir dizi olarak her teklif verenin bilgilerini içeriyor.
Ardından, odemeyi_hesapla fonksiyonu tanımladım. Bu fonksiyon, belirli bir artırma durumunda kazanan teklif verenin ödemesini hesaplamak için kullanılıyor.Fonksiyon, 'Artirma' türündeki bir yapıyı ve kazanan teklif verenin indeksini alıyor.
For döngüsü ile her teklife bakıp kazanan teklif verenin teklifi buluyor ve toplam ödeme miktarı hesaplıyor.
'acikarttirma' fonksiyonu, bir açık artırma simülasyonunu gerçekleştiriyor. En yüksek teklifi veren teklif verenin bilgilerini ve ödeme miktarını ekrana yazdırıyor.
Bu fonksiyon, oyun teorisindeki bir açık artırma senaryosunu canlandırıyor.
'main' fonksiyonunda, bir Artirma türündeki bir yapı (artirma) tanımladım ve bellekte teklif veren sayısı kadar yer ayırmış oldum. Ardından, her bir teklif verenin bilgileri atanıyor ve acikarttirma fonksiyonu çağrılıyor.
Her bir teklif veren, kendi stratejisine göre bir teklif sunuyor. 'acikarttirma' fonksiyonu, en yüksek teklifi veren teklif vereni belirliyor,bu da oyun teorisi açısından bir kazananı temsil ediyor.'odemeyi_hesapla' fonksiyonu, kazananın ödeme miktarını hesaplıyor, bu da bir tür oyun teorisi stratejisini temsil ediyor.

Aşağıda kodumun örnek çıktılarına yer verdim:

ÖRNEK ÇIKTI 1


![örnek çıktı 1 giriş](https://github.com/aycaalbayrak/Artirma-Simulasyonu/assets/153324294/5c762b0a-f003-4125-8f55-e56f00bcdeea)

![örnek çıktı 1 çıktı](https://github.com/aycaalbayrak/Artirma-Simulasyonu/assets/153324294/27411584-7da0-445d-962c-31b3c6920750)


ÖRNEK ÇIKTI 2


![öç2 giriş](https://github.com/aycaalbayrak/Artirma-Simulasyonu/assets/153324294/c97ce371-9e0d-40cf-a496-fd3b71ecf9ba)

![öç2çıkış](https://github.com/aycaalbayrak/Artirma-Simulasyonu/assets/153324294/ee4151d8-1ced-4fd7-887b-a3a61ddb0d72)



ÖRNEK ÇIKTI 3


![ÖRNÇ3G (1)](https://github.com/aycaalbayrak/Artirma-Simulasyonu/assets/153324294/4a62c62c-5004-4261-8910-df93728f808e)

![ÖRNÇ3Ç](https://github.com/aycaalbayrak/Artirma-Simulasyonu/assets/153324294/4fe4ac14-cd1d-4edf-8a06-9cd0e3584957)








