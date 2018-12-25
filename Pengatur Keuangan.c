#include <stdio.h>
#include <string.h>



typedef struct Data
{
	char nama[30];
	int jumlah;
	struct Data *next_Data;
} list;

list *head;

void Print(list *r);
void Add(list *temp);
void Delete(list *temp);
void judul();
void ErrorMessages();
void keluar();
int count();
int Tambah(list *b);
int batas, menu, saldo, pendapatan;

int main()
{
	int pilihan;
	list *Temp = NULL;
	awal:
	system("cls");
	judul();
	printf("Menu");
	printf("\n----\n");
	
	printf("\n1. Jalankan Program");
	printf("\n2. Bantuan");
	printf("\n3. Keluar\n");
	
	printf("\nInput	: "); scanf("%d", &menu);
	switch(menu)
	{
		case 1:
		system("cls");
		judul();
		printf("Masukan pendapatan perbulan Anda: "); scanf("%d", &pendapatan);
		printf("Masukan saldo anda saat ini: "); scanf("%d", &saldo);
		while(1)
		{
			judul();
			printf("Menu");
			printf("\n----\n");
			
			printf("\n1. Push Daftar Pengeluaran");
			printf("\n2. Delete Daftar Pengeluaran");
			printf("\n3. Display Daftar Pengeluaran");
			printf("\n4. Kondisi keuangan");
			printf("\n5. Kembali\n");
			printf("\nInput	: "); scanf("%d", &pilihan);
			switch(pilihan)
			{
				case 1: 	Add(Temp);					break; //ADD = PUSH
				case 2:		Delete(Temp);				break;
				case 3: 	Print(Temp);				break;
				case 4:		Kondisi();					break;
				case 5:		goto awal;					break;
				default:	ErrorMessages(); goto awal;	break;	//Error
			}
		}
		break;
		case 2 : 	bantuan(); goto awal; 	break;
		case 3 : 	exit(0); 	break;
		default : 	ErrorMessages(); goto awal;	break;
	}	
}

void Print(list *r)
{
	FILE *tulis;
	r=head;
	int i = 1;
	judul();
    if(r==NULL)
    {
    	
    	return;
    }
    while(r!=NULL)
    {
    	tulis = fopen("Daftar Pengeluaran.txt","a");
    	fprintf(tulis,"\n%.2d. Nama Pengeluaran	: %s ", i,r->nama);
    	fprintf(tulis, "\n    Besar		: %d",r->jumlah);
    	printf("\n%.2d. Nama Pengeluaran	: %s ", i,r->nama);
    	printf("\n    Besar		: %d",r->jumlah);
       	r=r->next_Data;
    	i++;
    	printf("\n");
    	fclose(tulis);
    }
    printf("\n\n");
    
	system("pause");
}

void Add(list *temp)
{
	int besar;
    temp=(list *)malloc(sizeof(list));
    
    judul();
	printf("\nAdd");
	printf("\n===\n");
	printf("Nama Pengeluaran	: "); scanf(" %[^\n]s", temp->nama);
    printf("Besar		    	: "); scanf(" %d", &besar);
    temp->jumlah=besar;
        
	if (head== NULL)
    {
    	head=temp;
    	head->next_Data=NULL;
    }
    else
    {
    	temp->next_Data=head;
    	head=temp;
    }
}

void Delete(list *temp)
{
	list *prev;
	char NAMA[20];
    temp=head;
    judul();
    
    printf("\nDelete");
	printf("\n======\n");
	printf("Nama Pengeluaran	: "); scanf(" %s", NAMA);
    
    while(temp!=NULL)
    {
    	if(strcmp(temp->nama, NAMA) == 0)
    	{
       		if(temp==head)
        	{
        		head=temp->next_Data;
        		free(temp);
        		return;
        	}
        	else
        	{
        		prev->next_Data=temp->next_Data;
        		free(temp);
        		return;
        	}
    	}
    	else		//Kalo gk ketemu, di next
    	{
        	prev=temp;
        	temp= temp->next_Data;
    	}
    }
	return 0;
}

void judul()
{
	system("cls");
	
	printf("\n===========================");
	printf("\n     Pengatur Keuangan     ");
	printf("\n===========================");
	printf("\n\n\n");
}

void ErrorMessages()
{
	judul();
	printf("\n\n-------------------------------------------------------");
	printf("\nError Messages	: Maaf Pilihan Yang Anda Masukan Salah");
	printf("\n-------------------------------------------------------\n\n");
	
	system("pause");

}
void bantuan(){
	system("cls");
	printf("\n===========================");
	printf("\n       Menu Bantuan        ");
	printf("\n===========================");
	printf("\n\n\n");
	printf("[1] Pada utama tekan angka 1 untuk menjalankan program\n");
	printf("[2] Masukkan pendapatan bulanan anda dan saldo yang anda miliki\n");
	printf("[3] Akan keluar beberapa menu pilihan: \n");
	printf("    -Menu 1 berfungsi untuk menambahkan list pengeluaran beserta nominalnya\n");
	printf("    -Menu 2 berfungsi untuk menghapus list pengeluaran sesuai yang anda inginkan\n");
	printf("    -Menu 3 berfungsi untuk memperlihatkan seluruh daftar pengeluaran yang sudah anda tulis\n");
	printf("    -Menu 4 berfungsi menampilkan keadaan keuangan total anda selama sehari ini dan menyimpulkan kalau pengeluaran anda boros atau tidak\n");
	printf("    -Menu 5 berfungsi untuk kembali ke menu utama\n ");
	printf("[4] Tekan angka 3 untuk keluar dari program\n");
	system("PAUSE");
	
}

void keluar(){
	return -1;
}

int Kondisi(list *b)
{
	FILE *tulis;
	int total = 0;
	b=head;
	int i = 1;
	judul();
    if(b==NULL)
    {
    	return;
    }
    while(b!=NULL)
    {
    	
    	total = total + b->jumlah ;
    	b=b->next_Data;
    	i++;
    
    }
    saldo = saldo - total;
    batas = pendapatan / 30;
    if(batas<total)
    {
    	printf("*PERINGATAN : Pengeluaran perhari anda melebihi batas\n\n");
	}
	else
	{
		printf("*Pengeluaran perhari anda stabil\n\n");
	}
	tulis = fopen("Sisa Saldo.txt","a");
	fprintf(tulis,"-Saldo anda saat ini adalah: %d",saldo);
    printf("-Total pengeluaran Anda  : %d \n\n", total);
    printf("-Saldo anda saat ini adalah: %d", saldo);
    printf("\n\n");
    fclose(tulis);
	system("pause");
}


