#include <stdio.h>
#include <stdlib.h>

int ticketsay=1;             //Bilet sayisini tutmak ve dinamik bellek tahsis fonksiyonlarinda boyut tutmak icin kullanildi
int bussay = 1;              //Otobus sayisini tutmak ve dinamik bellek tahsis fonksiyonlarinda boyut tutmak icin kullanildi
int biletidcount =1000;      //Bilet id takibi icin degisken
struct Bus *bus;
struct Ticket *ticket;

//Fonksiyonlar
void anamenu();
void mislemleri();
void biletal();
void biletdurumu();
void biletbilgidegistir();
void biletiptal();
void kislemleri();
void otobusislemleri();
void otobusekle();
void otobussil();
void otobuslistele();
void otobuslisteGor();
void otobusbilguncelle();
void biletlerilistele();

//Struct'lar
struct Passengerinfo       //Yolcu bilgilerini tutan struct
{
    char ad[50];
    char soyad[50];
    int tc;
    int yas;
    int gsm;
};
struct Bus                 //Otobus bilgilerini tutan struct
{
    int id;
    char busname[20];
    int koltuksayisi;
    int mevcutkoltuk;
    int ucret;
};
struct Ticket
{
    int Tid;
    struct Passengerinfo passenger;
    struct Bus *bus;
};

void anamenu()             //Ana menu fonksiyonu
{
    system  ("cls");
    int choice;
    printf ("\t\t************\n");
    printf ("\t\t*          *\n");
    printf ("\t\t* ANA MENU *\n");
    printf ("\t\t*          *\n");
    printf ("\t\t************\n");
    printf ("------------------------------------------\n");
    printf ("1.Musteri islemleri.\n");
    printf ("------------------------------------------\n");
    printf ("2.Kullanici islemleri.\n");
    printf ("------------------------------------------\n");
    printf ("3.Programdan cikis.\n");
    printf ("------------------------------------------\n");
    printf ("Seciminiz:");
    scanf  ("%d",&choice);
    printf ("\n");

    switch (choice)
    {
    case 1 :
    {
        mislemleri();
        break;
    }
    case 2 :
    {
        kislemleri();
        break;
    }
    case 3 :
    {
        printf ("\n==========================================");
        printf ("\n\nProgramdan cikiliyor iyi gunler.\n\n");
        printf ("==========================================\n");
        break;
    }
    default :
    {
        printf ("Lutfen tusladiginiz sayiya dikkat ediniz.\n");
        printf("Devam etmek icin Enter'a basiniz.!!!!!!");
        getch();
        anamenu();
    }
    }
}
void mislemleri()          //Musteri islemleri icin menu fonksiyon
{
    system("cls");
    int choice;
    printf ("\t\t*********************\n");
    printf ("\t\t*                   *\n");
    printf ("\t\t* MUSTERI ISLEMLERI *\n");
    printf ("\t\t*                   *\n");
    printf ("\t\t*********************\n");
    printf ("------------------------------------------\n");
    printf ("1.Bilet al.\n");
    printf ("------------------------------------------\n");
    printf ("2.Bilet iptali.\n");
    printf ("------------------------------------------\n");
    printf ("3.Bilet durumu goruntule.\n");
    printf ("------------------------------------------\n");
    printf ("4.Bilet bilgilerini guncelle.\n");
    printf ("------------------------------------------\n");
    printf ("5.Ana menuye don.\n");
    printf ("------------------------------------------\n");
    printf ("Seciminiz:");
    scanf ("%d",&choice);
    printf ("\n");

    switch (choice)
    {
    case 1 :
    {
        biletal();
        break;
    }
    case 2 :
    {
        biletiptal();
        break;
    }
    case 3 :
    {
        biletdurumu();
        break;
    }
    case 4 :
    {
        biletbilgidegistir();
        break;
    }
    case 5 :
    {
        anamenu();
        break;
    }
    default :
    {
        printf ("Lutfen tusladiginiz sayiya dikkat ediniz.\n");
        printf("Devam etmek icin Enter'a basiniz.!!!!!!");
        getch();
        mislemleri();
    }
    }
}
void biletal()             //Otobus eklenmis ise bilet almanizi saglayan fonksiyon
{
    system("cls");
    struct Passengerinfo passenger1;
    int sayac,i,j;
    int busid;
    if (bussay <= 1)
    {
        printf ("======================================================\n");
        printf ("Maalesef sistemde kayitli otobus bulunmamaktadir.\n");
        printf ("======================================================\n\n");
        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz.");
        printf ("\n*******************************************\n");
        getch();
        mislemleri();

    }
    else
    {
        printf ("\t\t*********************\n");
        printf ("\t\t*                   *\n");
        printf ("\t\t* BILET ALMA MENUSU *\n");
        printf ("\t\t*                   *\n");
        printf ("\t\t*********************\n");
        printf ("Kac adet bilet almak istersiniz:");
        scanf ("%d",&sayac);

        if (ticketsay <= 1)
        {
            ticket =(struct Ticket*)malloc(sayac * sizeof(struct Ticket));
        }
        else if (ticketsay > 1)
        {

            ticket = realloc(ticket,(ticketsay+sayac-1)*sizeof(struct Ticket));
        }

        for (i=0; i<sayac; i++)
        {

            printf ("------------------------------------------\n");
            printf ("\nAdinizi giriniz:");
            scanf  ("%s",&passenger1.ad);
            printf ("\n------------------------------------------\n");
            printf ("\nSoyadinizi giriniz:");
            scanf  ("%s",&passenger1.soyad);
            printf ("\n------------------------------------------\n");
            printf ("\nTC kimlik no giriniz:");
            scanf  ("%d",&passenger1.tc);
            printf ("\n------------------------------------------\n");
            printf ("\nYas giriniz:");
            scanf  ("%d",&passenger1.yas);
            printf ("\n------------------------------------------\n");
            printf ("\nTelefon no giriniz:");
            scanf  ("%d",&passenger1.gsm);
            printf ("\n------------------------------------------\n");
            printf ("\nOtobus seciniz:\n");
            printf ("\n------------------------------------------\n");
            otobuslistele();

            printf ("Yolculuk yapacaginiz otobus id sini giriniz:");
            scanf ("%d",&busid);

            int busdogrulama = 0;
            for (j = 0; j < bussay - 1; j++)
            {
                if ((bus + j)->id == busid)
                {
                    busdogrulama = 1;
                    if ((bus + j)->mevcutkoltuk == 0)
                    {
                        printf ("\n================================================================\n");
                        printf("Bu otobuste yer yoktur lutfen baska bir otobus id'si giriniz:");
                        printf ("\n================================================================\n");
                        scanf("%d", &busid);
                        j = -1;
                    }
                }
            }

            if (busdogrulama == 0)
            {
                printf ("\n========================================================================\n");
                printf("Gecerli bir otobus ID 'si girmediniz.Lutfen bilgilerinizi yeniden giriniz");
                printf ("\n========================================================================\n");
                i--;
                continue;
            }

            (ticket+ticketsay-1)->Tid = biletidcount;
            (ticket+ticketsay-1)->passenger = passenger1;
            (ticket+ticketsay-1)->bus = (bus+busid-1);
            (ticket+ticketsay-1)->bus->mevcutkoltuk--;

            printf ("\n=================================================\n");
            printf ("Biletiniz olusturulmustur ID numaraniz: %d",(ticket+ticketsay-1)->Tid);
            printf ("\n=================================================\n");
            biletidcount++;
            ticketsay++;
        }

        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz.");
        printf ("\n*******************************************\n");
        getch();
        mislemleri();
    }
}
void biletiptal()          //Bilet alinmis ise biletinizi iptal etmenizi saglayan fonksiyon
{
    system("cls");
    int ticketId;
    if (ticketsay <= 1)
    {
        printf ("\n==========================================\n");
        printf ("Iptal edilecek bilet bulunamadi");
        printf ("\n==========================================\n");
        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz.");
        printf ("\n*******************************************\n");
        getch();
        mislemleri();
    }
    else
    {
        printf("\t\t***********************\n");
        printf("\t\t*                     *\n");
        printf("\t\t*     BILET IPTAL     *\n");
        printf("\t\t*                     *\n");
        printf("\t\t***********************\n");
        printf("------------------------------------------\n");
        printf("Lutfen iptal etmek istediginiz bilet Id sini giriniz:");
        scanf("%d", &ticketId);

        int index = -1;
        for (int i = 0; i < ticketsay-1; i++)
        {
            if ((ticket + i)->Tid == ticketId)
            {
                index = i;
                break;
            }
        }

        if (index > -1)
        {
            (ticket+index)->bus->mevcutkoltuk++;
            for (int i = index; i < ticketsay - 1; i++)
            {
                ticket[i] = ticket[i + 1];
            }
            ticketsay--;

            if (ticketsay <= 1)
            {
                free(ticket);
                ticket = NULL;
            }
            else
            {
                ticket = realloc(ticket, (ticketsay) * sizeof(struct Ticket));
            }
            printf("\n\n=============================================\n");
            printf("Biletiniz iptal edilmistir.\n");
            printf("=============================================\n\n\n");
            printf("\n*******************************************\n");
            printf("Ust menuye donmek icin Enter'a basiniz.!!!!!!");
            printf("\n*******************************************\n");
        }
        if (index == -1)
        {
            printf("\n========================================\n");
            printf("Belirtilen bilet ID'si bulunamadi.");
            printf("\n========================================\n\n\n");
            printf("\n*******************************************\n");
            printf("Ust menuye donmek icin Enter'a basiniz.!!!!!!");
            printf("\n*******************************************\n");
        }
        getch();
        mislemleri();
    }
}

void biletdurumu()         //Bilet alinmis ise bilet ID'sini girerek bilet bilgilerinizi gorebileceginiz fonksiyon
{
    system("cls");
    int ticketId,i;
    int found = 0;
    if (ticketsay <= 1)
    {
        printf ("\n=======================================\n");
        printf ("Goruntulenecek bilet bulunamadi.");
        printf ("\n=======================================\n");
        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz.");
        printf ("\n*******************************************\n");
        getch();
        mislemleri();
    }
    else
    {
        printf ("\t\t***********************\n");
        printf ("\t\t*                     *\n");
        printf ("\t\t*   BILET GORUNTULE   *\n");
        printf ("\t\t*                     *\n");
        printf ("\t\t***********************\n");
        printf ("------------------------------------------\n");
        printf ("Lutfen goruntulemek istediginiz bilet Id sini giriniz:");
        scanf ("%d",&ticketId);

        for(i=0; i<ticketsay-1; i++)
        {
            if((ticket+i)->Tid == ticketId)
            {
                found = 1;
                printf ("\n=================================================\n");
                printf ("id: %d\n", (ticket+i)->Tid);
                printf ("Otobus: %s\n", (ticket+i)->bus->busname);
                printf ("Bilet Tutari : %d\n",(ticket+i)->bus->ucret);
                printf ("Yolcu Ad-Soyad: %s %s\n",(ticket+i)->passenger.ad, (ticket+i)->passenger.soyad);
                printf ("Yolcu Tc kimlik no: %d\n",(ticket+i)->passenger.tc);
                printf ("Yolcu yas: %d\n",(ticket+i)->passenger.yas);
                printf ("Yolcu telefon no: %d\n",(ticket+i)->passenger.gsm);
                printf ("=================================================\n");

                break;
            }
        }
        if (found == 0)
            {
                printf ("\n===============================================\n");
                printf ("Bilet bulunamadi dogru id girdiginize emin olun");
                printf ("\n===============================================\n");
                printf ("\n*******************************************\n");
                printf ("Ust menuye donmek icin Enter'a basiniz.");
                printf ("\n*******************************************\n");
                getch();
                mislemleri();
            }

        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz!!!!");
        printf ("\n*******************************************\n");
        getch();
        mislemleri();
    }
}
void biletbilgidegistir()  //Bilet alinmis ise bilet bilgilerini guncellemenizi saglayan fonksiyon
{
    system("cls");
    int ticketId,busid;
    int found = 0;
    if (ticketsay <= 1)
    {
        printf ("\n=======================================\n");
        printf ("Guncellenecek bilet bulunamadi.");
        printf ("\n=======================================\n");
        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz.");
        printf ("\n*******************************************\n");
        getch();
        mislemleri();
    }
    if (ticketsay > 1)
    {
        printf ("\t\t***********************\n");
        printf ("\t\t*                     *\n");
        printf ("\t\t*   BILET GUNCELLE    *\n");
        printf ("\t\t*                     *\n");
        printf ("\t\t***********************\n");
        printf ("------------------------------------------\n");
        printf ("Lutfen guncellemek istediginiz bilet Id sini giriniz:");
        scanf ("%d",&ticketId);

        for(int i=0; i<ticketsay-1; i++)
        {
            if((ticket+i)->Tid == ticketId)
            {
                found = 1;
                printf ("\n=================================================\n");
                printf ("id: %d\n", (ticket+i)->Tid);
                printf ("Otobus: %s\n", (ticket+i)->bus->busname);
                printf ("Bilet Tutari : %d\n",(ticket+i)->bus->ucret);
                printf ("Yolcu Ad-Soyad: %s %s\n",(ticket+i)->passenger.ad, (ticket+i)->passenger.soyad);
                printf ("Yolcu Tc kimlik no: %d\n",(ticket+i)->passenger.tc);
                printf ("Yolcu yas: %d\n",(ticket+i)->passenger.yas);
                printf ("Yolcu telefon no: %d\n",(ticket+i)->passenger.gsm);
                printf ("\n=================================================\n");

                printf ("\n------------------------------------------\n");
                printf ("\nAdinizi giriniz:");
                scanf  ("%s",&(ticket+i)->passenger.ad);
                printf ("\n------------------------------------------\n");
                printf ("\nSoyadinizi giriniz:");
                scanf  ("%s",&(ticket+i)->passenger.soyad);
                printf ("\n------------------------------------------\n");
                printf ("\nTC kimlik no giriniz:");
                scanf  ("%d",&(ticket+i)->passenger.tc);
                printf ("\n------------------------------------------\n");
                printf ("\nYas giriniz:");
                scanf  ("%d",&(ticket+i)->passenger.yas);
                printf ("\n------------------------------------------\n");
                printf ("\nTelefon no giriniz:");
                scanf  ("%d",&(ticket+i)->passenger.gsm);
                printf ("\n------------------------------------------\n");

                printf ("\n=================================================\n");
                printf ("Biletiniz guncellenmistir.");
                printf ("\n=================================================\n");
                break;
            }
        }
        if (found == 0)
        {
            printf ("\n=================================================\n");
            printf ("Belirtilen bilet ID'si bulunamadi.");
            printf ("\n=================================================\n");
        }
        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz.");
        printf ("\n*******************************************\n");
        getch();
        mislemleri();
    }
}
void kislemleri()          //Kullanici islemleri icin menu fonksiyonu
{
    system("cls");
    int choice;
    printf ("\t\t***********************\n");
    printf ("\t\t*                     *\n");
    printf ("\t\t* KULLANICI ISLEMLERI *\n");
    printf ("\t\t*                     *\n");
    printf ("\t\t***********************\n");
    printf ("------------------------------------------\n");
    printf ("1.Otobus islemleri.\n");
    printf ("------------------------------------------\n");
    printf ("2.Biletleri listele.\n");
    printf ("------------------------------------------\n");
    printf ("3.Ana menuye don.\n");
    printf ("------------------------------------------\n");
    printf ("Seciminiz:");
    scanf ("%d",&choice);
    printf ("\n");

    switch (choice)
    {
    case 1 :
    {
        otobusislemleri();
        break;
    }
    case 2 :
    {
        biletlerilistele();
        break;
    }
    case 3 :
    {
        anamenu();
        break;
    }
    default :
    {
        printf ("Lutfen tusladiginiz sayiya dikkat ediniz.\n");
        printf("Devam etmek icin Enter'a basiniz.!!!!!!");
        getch();
        kislemleri();
    }
    }
}
void otobusislemleri()     //Otobus islemleri icin menu fonksiyonu
{
    system("cls");
    int choice;
    printf ("\t\t********************\n");
    printf ("\t\t*                  *\n");
    printf ("\t\t* OTOBUS ISLEMLERI *\n");
    printf ("\t\t*                  *\n");
    printf ("\t\t********************\n");
    printf ("------------------------------------------\n");
    printf ("1.Otobus ekle.\n");
    printf ("------------------------------------------\n");
    printf ("2.Otobus sil.\n");
    printf ("------------------------------------------\n");
    printf ("3.Otobusleri listele.\n");
    printf ("------------------------------------------\n");
    printf ("4.Otobus bilgilerini guncelle.\n");
    printf ("------------------------------------------\n");
    printf ("5.Ust menuye don.\n");
    printf ("------------------------------------------\n");
    printf ("Seciminiz:");
    scanf ("%d",&choice);
    printf ("\n");

    switch (choice)
    {
    case 1 :
    {
        otobusekle();
        break;
    }
    case 2 :
    {
        otobussil();
        break;
    }
    case 3 :
    {
        otobuslisteGor();
        break;
    }
    case 4 :
    {
        otobusbilguncelle();
        break;
    }
    case 5 :
    {
        kislemleri();
        break;
    }
    default :
    {
        printf ("Lutfen tusladiginiz sayiya dikkat ediniz.\n");
        printf("Devam etmek icin Enter'a basiniz.!!!!!!");
        getch();
        otobusislemleri();
    }
    }
}
void otobusekle()          //Otobus ekleme fonksiyonu
{
    system("cls");
    int sayac,i;
    printf ("\t\t***************\n");
    printf ("\t\t*             *\n");
    printf ("\t\t* OTOBUS EKLE *\n");
    printf ("\t\t*             *\n");
    printf ("\t\t***************\n");
    printf ("------------------------------------------\n");
    printf ("Kac tane otobus eklemek istersiniz:");
    scanf ("%d",&sayac);
    printf ("------------------------------------------\n");
    if (bussay <= 1)
    {
        bus =(struct Bus*)malloc(sayac * sizeof(struct Bus));
    }
    if (bussay > 1)
    {
        bus = realloc(bus,(bussay+sayac-1)*sizeof(struct Bus));
    }

    for (i=0; i<sayac; i++)
    {
        printf ("\n%d. Otobusun ismini giriniz:",i+1);
        scanf  ("%s",&(bus+bussay-1)->busname);
        printf ("\n------------------------------------------\n");
        printf ("\n%d. Otobusun koltuk sayisini giriniz:",i+1);
        scanf  ("%d",&(bus+bussay-1)->koltuksayisi);
        printf ("\n------------------------------------------\n");
        printf ("\n%d. Otobusun ucretini giriniz:",i+1);
        scanf  ("%d",&(bus+bussay-1)->ucret);
        printf ("\n------------------------------------------\n");
        (bus+bussay-1)->id = bussay;
        (bus+bussay-1)->mevcutkoltuk = (bus+bussay-1)->koltuksayisi;
        bussay++;
    }
    printf ("\n=======================================\n");
    printf ("Basariyla otobus eklediniz.");
    printf ("\n=======================================\n");
    printf ("\n*******************************************\n");
    printf ("Ust menuye donmek icin Enter'a basiniz!!!!");
    printf ("\n*******************************************\n");
    getch();
    otobusislemleri();
}
void otobussil()           //Otobus girisi yapilmis ise sectiginiz otobusleri silmenizi saglayan fonksiyon
{
    system("cls");
    int busId,i;
    if (bussay <= 1)
    {
        printf ("===================================\n");
        printf ("Silinecek otobus bulunamadi.\n");
        printf ("===================================\n\n");
        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz.");
        printf ("\n*******************************************\n");
        getch();
        otobusislemleri();
    }
    if (bussay > 1)
    {
        printf("\t\t***********************\n");
        printf("\t\t*                     *\n");
        printf("\t\t*     OTOBUS SIL      *\n");
        printf("\t\t*                     *\n");
        printf("\t\t***********************\n");
        printf("------------------------------------------\n");
        printf("Lutfen iptal etmek istediginiz otobus Id sini giriniz:");
        scanf("%d", &busId);

        for (i=0; i<ticketsay-1; i++)
        {
            if ((ticket+i)->bus->id == busId)
            {
                printf("\n\n========================================================================================\n");
                printf("Bu otobusle iliskilendirilmis biletler var. Once biletlerin silinmesi gerekmektedir!!!!\n");
                printf("========================================================================================\n\n\n");
                printf("\n*******************************************\n");
                printf("Ust menuye donmek icin Enter'a basiniz.!!!!!!");
                printf("\n*******************************************\n");
                getch();
                otobusislemleri();
            }
        }

        int index = -1;
        for (i = 0; i < bussay-1; i++)
        {
            if ((bus+i)->id == busId)
            {
                index = i;
                break;
            }
        }

        if (index > -1)
        {
            for (i = index; i < bussay - 1; i++)
            {
                bus[i] = bus[i + 1];
            }
            bussay--;

            if (bussay <= 1)
            {
                free(bus);
                bus = NULL;
            }
            else
            {
                bus = realloc(bus, (bussay) * sizeof(struct Bus));
            }

            printf("\n\n============================\n");
            printf("Otobus Silinmistir.\n");
            printf("============================\n\n\n");
            printf("\n*******************************************\n");
            printf("Ust menuye donmek icin Enter'a basiniz.!!!!!!");
            printf("\n*******************************************\n");
        }
        else
        {
            printf("\n==================================\n");
            printf("Belirtilen otobus ID'si bulunamadi.");
            printf("\n==================================\n");
            printf("\n\n\n*******************************************\n");
            printf("Ust menuye donmek icin Enter'a basiniz.!!!!!!");
            printf("\n*******************************************\n");
        }

        getch();
        otobusislemleri();
    }
}
void otobuslistele()       //Otobus girisi yapilmis ise bilet al fonksiyonu icin listeleyen fonksiyon
{
    for(int i=0; i<bussay -1; i++)
    {
        printf ("=============================================\n");
        printf ("= ID: %d\n",(bus+i)->id);
        printf ("= Otobus ismi: %s\n",(bus+i)->busname);
        printf ("= Otobus ucreti: %d\n",(bus+i)->ucret);
        printf ("= Mevcut koltuk sayisi: %d\n",(bus+i)->mevcutkoltuk);
        printf ("= Toplam koltuk sayisi: %d\n",(bus+i)->koltuksayisi);
        printf ("=============================================\n");
    }
}
void otobuslisteGor()      //Otobus girisi yapilmis ise otobusleri listeleyen fonksiyon
{
    system("cls");
    if (bussay == 1)
    {
        printf("=============================================\n");
        printf("Listelenecek otobus bulunamadi!!!!\n");
        printf("=============================================\n");
        printf("\n*******************************************\n");
        printf("Ust menuye donmek icin Enter'a basiniz.!!!!!!");
        printf("\n*******************************************\n");
        getch();
        otobusislemleri();
    }
    else
    {
        for(int i=0; i<bussay-1; i++)
        {
            printf ("=============================================\n");
            printf ("= ID: %d\n",(bus+i)->id);
            printf ("= Otobus ismi: %s\n",(bus+i)->busname);
            printf ("= Otobus ucreti: %d\n",(bus+i)->ucret);
            printf ("= Mevcut koltuk sayisi: %d\n",(bus+i)->mevcutkoltuk);
            printf ("= Toplam koltuk sayisi: %d\n",(bus+i)->koltuksayisi);
            printf ("=============================================\n");
        }
        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz.!!!!!!");
        printf ("\n*******************************************\n");
        getch();
        otobusislemleri();
    }
}
void otobusbilguncelle()   //Otobus girisi yapilmis ise sectiginiz otobusun bilgilerini guncelleyen fonksiyon
{
    system("cls");
    int busid,Ykoltuk;
    int found = 0;
    if (bussay <= 1)
    {
        printf ("\n=======================================\n");
        printf ("Guncellenecek otobus bulunamadi.");
        printf ("\n=======================================\n\n\n");
        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz.");
        printf ("\n*******************************************\n");
        getch();
        otobusislemleri();
    }
    if (bussay > 1)
    {
        printf ("\t\t************************\n");
        printf ("\t\t*                      *\n");
        printf ("\t\t*   OTOBUS GUNCELLE    *\n");
        printf ("\t\t*                      *\n");
        printf ("\t\t************************\n");
        printf ("------------------------------------------\n");
        printf ("Lutfen guncellemek istediginiz bilet Id sini giriniz:");
        scanf ("%d",&busid);

        for(int i=0; i<bussay-1; i++)
        {
            if((bus+i)->id == busid)
            {
                found = 1;
                printf ("\n=================================================\n");
                printf ("id: %d\n", (bus+i)->id);
                printf ("Otobus ismi: %s\n", (bus+i)->busname);
                printf ("Otobus ucreti : %d\n",(bus+i)->ucret);
                printf ("Otobus koltuk sayisi: %d\n",(bus+i)->koltuksayisi);
                printf ("\n=================================================\n");

                printf ("\n------------------------------------------\n");
                printf ("\nOtobus ismi giriniz:");
                scanf  ("%s",&(bus+i)->busname);
                printf ("\n------------------------------------------\n");
                printf ("\nOtobus ucreti giriniz:");
                scanf  ("%d",&(bus+i)->ucret);
                printf ("\n------------------------------------------\n");
                printf ("\nKoltuk sayisi giriniz:");
                scanf  ("%d",&Ykoltuk);
                printf ("\n------------------------------------------\n");

                if (Ykoltuk > (bus+i)->koltuksayisi)
                {
                    (bus+i)->mevcutkoltuk = (bus+i)->mevcutkoltuk + (Ykoltuk-(bus->koltuksayisi));
                    (bus+i)->koltuksayisi = Ykoltuk;
                    printf ("\n==================================\n");
                    printf ("Otobusunuz guncellenmistir.");
                    printf ("\n==================================\n");
                }
                if ((bus+i)->koltuksayisi > Ykoltuk)
                {
                    if(((bus+i)->mevcutkoltuk)-((bus+i)->koltuksayisi - Ykoltuk) < 0)
                    {
                        printf ("\n=====================================================================\n");
                        printf ("Bu islemi gerceklestiremezssiniz.Koltuk sayilarina dikkat ediniz!!!!!!");
                        printf ("\n=====================================================================\n");
                    }
                    else
                    {
                        (bus+i)->mevcutkoltuk = ((bus+i)->mevcutkoltuk) - ((bus+i)->koltuksayisi - Ykoltuk);
                        (bus+i)->koltuksayisi = Ykoltuk;
                        printf ("\n==================================\n");
                        printf ("Otobusunuz guncellenmistir.");
                        printf ("\n==================================\n");
                    }
                }
                break;
            }
        }
        if (found == 0)
        {
            printf ("\n=================================================\n");
            printf ("Belirtilen otobus ID'si bulunamadi.");
            printf ("\n=================================================\n\n");
        }
        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz.");
        printf ("\n*******************************************\n");
        getch();
        otobusislemleri();
    }
}
void biletlerilistele()    //Bilet alinmis ise biletleri listeleyen fonksiyon
{
    system("cls");
    if (ticketsay <= 1)
    {
        printf("=============================================\n");
        printf("Listelenecek bilet bulunamadi!!!!\n");
        printf("=============================================\n");
        printf("\n*******************************************\n");
        printf("Ust menuye donmek icin Enter'a basiniz.!!!!!!");
        printf("\n*******************************************\n");
        getch();
        kislemleri();
    }
    else
    {
        for(int i=0; i<ticketsay-1; i++)
        {
            printf ("=============================================\n");
            printf ("= Bilet ID: %d\n",(ticket+i)->Tid);
            printf ("= Yolcu ad soyad: %s %s\n",(ticket+i)->passenger.ad,(ticket+i)->passenger.soyad);
            printf ("= Yolcunun binecegi otobus: %s\n",(ticket+i)->bus->busname);
            printf ("= Yolcunun binecegi otobus id: %d\n",(ticket+i)->bus->id);
            printf ("=============================================\n");
        }
        printf ("\n*******************************************\n");
        printf ("Ust menuye donmek icin Enter'a basiniz!!!!");
        printf ("\n*******************************************\n");
        getch();
        kislemleri();
    }
}

int main()
{
    anamenu();             //Ana menuye yonlendirir
    return 0;
}
