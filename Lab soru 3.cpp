#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öðrenci bilgilerini saklayan düðüm yapýsý
struct Ogrenci {
    int ogrenciNo;
    char isim[50];
    int yas;
    struct Ogrenci* next;
};

// Yeni bir öðrenci düðümü oluþturan fonksiyon
struct Ogrenci* yeniOgrenci(int ogrenciNo, const char* isim, int yas) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    ogrenci->ogrenciNo = ogrenciNo;
    strcpy(ogrenci->isim, isim);
    ogrenci->yas = yas;
    ogrenci->next = NULL;
    return ogrenci;
}

// Öðrenci düðümünü liste sonuna ekleyen fonksiyon
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int ogrenciNo, const char* isim, int yas) {
    struct Ogrenci* ogrenci = yeniOgrenci(ogrenciNo, isim, yas);
    if (head == NULL) {
        return ogrenci;
    }

    struct Ogrenci* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = ogrenci;
    return head;
}

// Öðrenci bilgilerini dolaþan ve ekrana yazan fonksiyon
void ogrenciBilgileriniYazdir(struct Ogrenci* head) {
    struct Ogrenci* current = head;
    int ogrenciSayisi = 0;

    while (current != NULL) {
        printf("Öðrenci No: %d, Ýsim: %s, Yaþ: %d\n", current->ogrenciNo, current->isim, current->yas);
        ogrenciSayisi++;
        current = current->next;
    }

    printf("Toplam ogrenci Sayisi: %d\n", ogrenciSayisi);
}

int main() {
    struct Ogrenci* head = NULL;
    int ogrenciSayisi;

    printf("Kac ogrenci eklemek istersiniz? ");
    scanf("%d", &ogrenciSayisi);

    for (int i = 0; i < ogrenciSayisi; i++) {
        int ogrenciNo, yas;
        char isim[50];

        printf("ogrenci No: ");
        scanf("%d", &ogrenciNo);
        printf("Ýsim: ");
        scanf("%s", isim);
        printf("Yas: ");
        scanf("%d", &yas);

        head = ogrenciEkle(head, ogrenciNo, isim, yas);
    }

    // Öðrenci bilgilerini dolaþarak ekrana yazdýrýn
    ogrenciBilgileriniYazdir(head);

    // Belleði temizle
    while (head != NULL) {
        struct Ogrenci* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

