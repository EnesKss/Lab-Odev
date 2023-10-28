#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öðrenci yapýsý
struct Ogrenci {
    int ogrenciNo;
    char ad[50];
    struct Ogrenci* next;
};

// Yeni öðrenci ekleme fonksiyonu
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int no, const char* ad) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->ogrenciNo = no;
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->next = NULL;

    if (head == NULL) {
        return yeniOgrenci;
    }

    struct Ogrenci* gecici = head;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }
    gecici->next = yeniOgrenci;

    return head;
}

// Öðrenci listesini ekrana yazdýran fonksiyon
void ogrenciListesiYazdir(struct Ogrenci* head) {
    struct Ogrenci* gecici = head;
    while (gecici != NULL) {
        printf("Ogrenci No: %d, Ad: %s\n", gecici->ogrenciNo, gecici->ad);
        gecici = gecici->next;
    }
}

// Öðrenci silme fonksiyonu
struct Ogrenci* ogrenciSilSonraki(struct Ogrenci* head, const char* hedefAd) {
    if (head == NULL) {
        printf("Liste boþ. Silme islemi yapilamaz.\n");
        return head;
    }

    struct Ogrenci* gecici = head;
    while (gecici->next != NULL) {
        if (strcmp(gecici->ad, hedefAd) == 0) {
            struct Ogrenci* silinecek = gecici->next;
            gecici->next = silinecek->next;
            free(silinecek);
            printf("%s adlý ogrencinin sonraki ogrencisi silindi.\n", hedefAd);
            return head;
        }
        gecici = gecici->next;
    }

    printf("%s adli ogrenci bulunamadi veya listenin sonunda bulunuyor.\n", hedefAd);
    return head;
}

int main() {
    struct Ogrenci* liste = NULL;

    // Öðrenci kayýtlarý ekleniyor
    liste = ogrenciEkle(liste, 1, "enes");
    liste = ogrenciEkle(liste, 2, "rukiye");
    liste = ogrenciEkle(liste, 3, "saliha");
    liste = ogrenciEkle(liste, 4, "koray");

    // Öðrenci listesini ekrana yazdýr
    printf("Ogrenci Listesi:\n");
    ogrenciListesiYazdir(liste);

    // Kullanýcýdan silinecek öðrencinin adýný al
    char silinecekAd[50];
    printf("Hangi ogrenciden sonraki ogrenciyi silmek istersiniz? Öðrenci adini girin: ");
    scanf("%s", silinecekAd);

    // Öðrenci silme iþlemi
    liste = ogrenciSilSonraki(liste, silinecekAd);

    // Güncellenmiþ öðrenci listesini ekrana yazdýr
    printf("Guncellenmis Ogrenci Listesi:\n");
    ogrenciListesiYazdir(liste);

    // Belleði temizle (serbest býrak)
    while (liste != NULL) {
        struct Ogrenci* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}

