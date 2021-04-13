#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctime>
#include <locale.h>

using namespace std;


struct date
{
   int day, month, year;
};

struct car
{
	int ID;
	char owner_name[20],owner_surname[20],owner_phone[20],brand[20],model[20],make[20];
	struct date reg_date,ns_date;
}car_directory[100];


int size = 0;
char Language = 0;

time_t ttime = time(0);
tm *local_time = localtime(&ttime);

FILE *CarDATA;



void AddCar(void){

	setlocale(LC_ALL, "Turkish"); 
   if(size<=99)
     {	 
        int idcheck=0;
        car_directory[size].ID =size+1;    
        for(int i=0;i<size;i++)
        {
        	if(car_directory[size].ID ==car_directory[i].ID)
        	{    
        	    
        		car_directory[size].ID = rand() % 100 + size + 1;
        		cout << "ID: "<<car_directory[size].ID<<endl;
        		idcheck=1;
			}
		}
		if(idcheck==0)
		{
			cout << "ID: "<<car_directory[size].ID<<endl;
		}
        
        

      if(Language== 0 ){cout<<"Owner name : "; }
	if(Language== 1 ){ cout<<"Müsteri Adi : ";}
    cin >> car_directory[size].owner_name;

     
    if(Language== 0 ){cout<<"Owner surname : "; }
	if(Language== 1 ){ cout<<"Müsteri Soyadi : ";}
    cin >> car_directory[size].owner_surname;
    
    if(Language== 0 ){cout<<"Owner phone : "; }
	if(Language== 1 ){ cout<<"Müsteri telefonu : ";}
    cin >> car_directory[size].owner_phone;

      
    if(Language== 0 ){cout<<"Car Brand : "; }
	if(Language== 1 ){ cout<<"Araba Markasi : ";}
    cin >> car_directory[size].brand;
      
    if(Language== 0 ){cout<<"Car Model : "; }
	if(Language== 1 ){ cout<<"Araba Modeli : ";}
	cin >> car_directory[size].model;

    if(Language== 0 ){cout<<"Car Year of production : "; }
	if(Language== 1 ){ cout<<"Araba Üretim Yili : ";}
    cin >> car_directory[size].make;
      
     if(Language== 0 ){cout<<"Registiration date : "; }
	 if(Language== 1 ){ cout<<"Kayit Tarihi : ";}
	  cout<< local_time->tm_mday <<"/"<<1 + local_time->tm_mon<<"/"<<1900 + local_time->tm_year<<"\n";
    car_directory[size].reg_date.day = local_time->tm_mday;
    car_directory[size].reg_date.month = 1 + local_time->tm_mon;
    car_directory[size].reg_date.year = 1900 + local_time->tm_year;

      
    if(Language== 0 ){cout<<"Next service day : "; }
	if(Language== 1 ){ cout<<"Sonraki servis günü : ";}
    cin >> car_directory[size].ns_date.day;

     
    if(Language== 0 ){cout<<"Next service month: "; }
	if(Language== 1 ){ cout<<"Sonraki servis ayi : ";}
    cin >> car_directory[size].ns_date.month;

   
    if(Language== 0 ){cout<<"Next service year : "; }
	if(Language== 1 ){ cout<<"Sonraki servis yili : ";}
    cin >> car_directory[size].ns_date.year;
      

     
     

   
	   fprintf(CarDATA, "%5d %20s %20s %20s %20s %20s %20s %5d %5d %5d %5d %5d %5d\r\n", car_directory[size].ID, car_directory[size].owner_name, car_directory[size].owner_surname,car_directory[size].owner_phone, car_directory[size].brand, car_directory[size].model, car_directory[size].make, car_directory[size].reg_date.day, car_directory[size].reg_date.month, car_directory[size].reg_date.year, car_directory[size].ns_date.day, car_directory[size].ns_date.month, car_directory[size].ns_date.year);

        fclose(CarDATA);
   
   cout << endl;
   size++;
}
      else
      {
        
if(Language== 0 ){cout<<"Car list full"<<endl; }
	    if(Language== 1 ){ cout<<"Araba Listesi dolu"<<endl;}
         
         return;
      }
}

int DeleteCar(int id){
		setlocale(LC_ALL, "Turkish"); 
	
	
   freopen("cars.dat", "w", CarDATA);

  
   if(CarDATA == 0)
   {
      
      exit(1);
   }

   
   for(int i = 0; i <size; i++)
   {
      
      if(car_directory[i].ID !=id)
      {
       fprintf(CarDATA, "%5d %20s %20s %20s %20s %20s %20s %5d %5d %5d %5d %5d %5d\r\n", car_directory[i].ID, car_directory[i].owner_name, car_directory[i].owner_surname,car_directory[i].owner_phone, car_directory[i].brand, car_directory[i].model, car_directory[i].make, car_directory[i].reg_date.day, car_directory[i].reg_date.month, car_directory[i].reg_date.year, car_directory[i].ns_date.day, car_directory[i].ns_date.month, car_directory[i].ns_date.year);
	  }
   }
   
   freopen("cars.dat", "r+", CarDATA);

   
   if(CarDATA == 0)
   {
      
      exit(1);
   }

}

void ListCar(void){

	setlocale(LC_ALL, "Turkish"); 
   
   
      
   for(int i = 0; i < size; i++)
   {
      
        if(car_directory[i].ID != 0)
        {
		
        
        cout << "ID: " << car_directory[i].ID  << endl;

        if(Language== 0 ){cout<<"Owner name : "; }
	    if(Language== 1 ){ cout<<"Müsteri Adi : ";}
        cout << car_directory[i].owner_name  << endl;

        if(Language== 0 ){cout<<"Owner surname : "; }
	    if(Language== 1 ){ cout<<"Müsteri Soyadi : ";}
        cout << car_directory[i].owner_surname  << endl;
        
        if(Language== 0 ){cout<<"Owner phone : "; }
	    if(Language== 1 ){ cout<<"Müsteri telefonu : ";}
        cout << car_directory[i].owner_phone  << endl;

        if(Language== 0 ){cout<<"Car Brand : "; }
	    if(Language== 1 ){ cout<<"Araba Markasi : ";}
		cout << car_directory[i].brand  << endl;
          
        if(Language== 0 ){cout<<"Car Model : "; }
	    if(Language== 1 ){ cout<<"Araba Modeli : ";}
		cout << car_directory[i].model  << endl;
         
        if(Language== 0 ){cout<<"Car Year of production : "; }
	    if(Language== 1 ){ cout<<"Araba Üretim Yili : ";}
        cout<< car_directory[i].make  << endl;
         

        if(Language== 0 ){cout<<"Registiration date : "; }
	    if(Language== 1 ){ cout<<"Kayit Tarihi : ";}
        cout <<car_directory[i].reg_date.day <<"/"<<car_directory[i].reg_date.month <<"/"<< car_directory[i].reg_date.year<<endl;

        if(Language== 0 ){cout<<"Next service date : "; }
	    if(Language== 1 ){ cout<<"Sonraki servis tarihi : ";}
        cout << car_directory[i].ns_date.day << "/"<< car_directory[i].ns_date.month << "/"<<car_directory[i].ns_date.year << endl;
         cout<<endl;
         
        }
   }
 }

int searchID(int searchID){
		setlocale(LC_ALL, "Turkish"); 

	for(int i=0;i<size;i++)
	{
		if(car_directory[i].ID==searchID)
		{
		cout << "\nID: " << car_directory[i].ID  << endl;

        if(Language== 0 ){cout<<"Owner name : "; }
	    if(Language== 1 ){ cout<<"Müsteri Adi : ";}
        cout << car_directory[i].owner_name  << endl;

        if(Language== 0 ){cout<<"Owner surname : "; }
	    if(Language== 1 ){ cout<<"Müsteri Soyadi : ";}
        cout << car_directory[i].owner_surname  << endl;
        
        if(Language== 0 ){cout<<"Owner phone : "; }
	    if(Language== 1 ){ cout<<"Müsteri telefonu : ";}
        cout << car_directory[i].owner_phone  << endl;

        if(Language== 0 ){cout<<"Car Brand : "; }
	    if(Language== 1 ){ cout<<"Araba Markasi : ";}
		cout << car_directory[i].brand  << endl;
          
        if(Language== 0 ){cout<<"Car Model : "; }
	    if(Language== 1 ){ cout<<"Araba Modeli : ";}
		cout << car_directory[i].model  << endl;
         
        if(Language== 0 ){cout<<"Car Year of production : "; }
	    if(Language== 1 ){ cout<<"Araba Üretim Yili : ";}
        cout<< car_directory[i].make  << endl;
         

        if(Language== 0 ){cout<<"Registiration date : "; }
	    if(Language== 1 ){ cout<<"Kayit Tarihi : ";}
        cout <<car_directory[i].reg_date.day <<"/"<<car_directory[i].reg_date.month <<"/"<< car_directory[i].reg_date.year<<endl;

        if(Language== 0 ){cout<<"Next service date : "; }
	    if(Language== 1 ){ cout<<"Sonraki servis tarihi : ";}
        cout << car_directory[i].ns_date.day << "/"<< car_directory[i].ns_date.month << "/"<<car_directory[i].ns_date.year << endl;        
        cout << endl;
		}
		
	}
}

void searchName(char searchName[20]){
		setlocale(LC_ALL, "Turkish"); 
       
   	for(int i=0;i<size;i++)
	{	
		if(car_directory[i].owner_name == searchName)
		{
		cout << "ID: " << car_directory[i].ID  << endl;
		
        if(Language== 0 ){cout<<"Owner name : "; }
	    if(Language== 1 ){ cout<<"Müsteri Adi : ";}
        cout << car_directory[i].owner_name  << endl;

        if(Language== 0 ){cout<<"Owner surname : "; }
	    if(Language== 1 ){ cout<<"Müsteri Soyadi : ";}
        cout << car_directory[i].owner_surname  << endl;
        
        if(Language== 0 ){cout<<"Owner phone : "; }
	    if(Language== 1 ){ cout<<"Müsteri telefonu : ";}
        cout << car_directory[i].owner_phone  << endl;

        if(Language== 0 ){cout<<"Car Brand : "; }
	    if(Language== 1 ){ cout<<"Araba Markasi : ";}
		cout << car_directory[i].brand  << endl;
          
        if(Language== 0 ){cout<<"Car Model : "; }
	    if(Language== 1 ){ cout<<"Araba Modeli : ";}
		cout << car_directory[i].model  << endl;
         
        if(Language== 0 ){cout<<"Car Year of production : "; }
	    if(Language== 1 ){ cout<<"Araba Üretim Yili : ";}
        cout<< car_directory[i].make  << endl;
         

        if(Language== 0 ){cout<<"Registiration date : "; }
	    if(Language== 1 ){ cout<<"Kayit Tarihi : ";}
        cout <<car_directory[i].reg_date.day <<"/"<<car_directory[i].reg_date.month <<"/"<< car_directory[i].reg_date.year<<endl;

        if(Language== 0 ){cout<<"Next service date : "; }
	    if(Language== 1 ){ cout<<"Sonraki servis tarihi : ";}
        cout << car_directory[i].ns_date.day << "/"<< car_directory[i].ns_date.month << "/"<<car_directory[i].ns_date.year << endl;        
        cout << endl;
		}
		
	}
}

char searchData(char searchkey[20]){
	int low, high, middle, cnt = 0;
	low = 0;
	high = size;

	while(low <= high){
		middle = (low + high) / 2;
		cnt++;

		if(car_directory[middle].owner_surname == searchkey){
			return cnt;
		} else if(car_directory[middle].owner_surname < searchkey){
			low = middle + 1;
		} else {
			high = middle - 1;
		}
	}
	return -1;
}

char SearchCar(char choice){
		setlocale(LC_ALL, "Turkish"); 
	int sID;
	char *sName;
	if(choice == 'A' || choice == 'a')
	{
		if(Language== 0 ){cout<<"Enter Car ID: "; }
	    if(Language== 1 ){ cout<<"Araba ID numarasýný gýrýnýz : ";}
		cin>>sID;
		searchID(sID);
	}
	if(choice == 'B' || choice == 'b')
	{
		 if(Language== 0 ){cout<<"Enter Owner name: "; }
	    if(Language== 1 ){ cout<<"Müþteri Adýný gýrýnýz : ";}
		cin>>sName;
		searchName(sName);
	}
}

int UpdateCar(int id){
		setlocale(LC_ALL, "Turkish"); 
	char choice;
	for(int i = 0; i <= size; i++)
   {
      
      if(car_directory[i].ID == id)
      {
         
         cout << "ID: " << car_directory[i].ID  << endl;

        if(Language== 0 ){cout<<"Owner name : "; }
	    if(Language== 1 ){ cout<<"Müsteri Adi : ";}
        cout << car_directory[i].owner_name  << endl;
        if(Language== 0 ){cout<<"Do you update information (Y/N) : "; }
	    if(Language== 1 ){ cout<<"Bilgiyi güncellemek istiyor musun (E/H) : ";}
	    cin>>choice;
	    if(choice == 'Y' || choice == 'y' || choice == 'E' || choice == 'e')
	    {
	    if(Language== 0 ){cout<<"New Owner name : "; }
	    if(Language== 1 ){ cout<<"Yeni Sahip Adi : ";}
         cin >> car_directory[i].owner_name;
		}
	
        
        if(Language== 0 ){cout<<"Owner surname : "; }
	    if(Language== 1 ){ cout<<"Müsteri Soyadi : ";}
        cout << car_directory[i].owner_surname  << endl;
        if(Language== 0 ){cout<<"Do you update information (Y/N) : "; }
	    if(Language== 1 ){ cout<<"Bilgiyi güncellemek istiyor musun (E/H) : ";}
	    cin>>choice;
	    if(choice == 'Y' || choice == 'y' || choice == 'E' || choice == 'e')
	    {
        if(Language== 0 ){cout<<"New Owner surname : "; }
	    if(Language== 1 ){ cout<<"Yeni Sahip Soyadi : ";}
		cin >> car_directory[i].owner_surname;
		}
		
         
        if(Language== 0 ){cout<<"Owner phone : "; }
	    if(Language== 1 ){ cout<<"Müsteri telefonu : ";}
        cout << car_directory[i].owner_phone  << endl;
        
		if(Language== 0 ){cout<<"Do you update information (Y/N) : "; }
	    if(Language== 1 ){ cout<<"Bilgiyi güncellemek istiyor musun (E/H) : ";}
	    cin>>choice;
	    if(choice == 'Y' || choice == 'y' || choice == 'E' || choice == 'e')
	    {
        if(Language== 0 ){cout<<"New Owner phone : "; }
	    if(Language== 1 ){ cout<<"Müsteri telefonu : ";}
		cin >> car_directory[i].owner_phone;
		}
        
        if(Language== 0 ){cout<<"Car Brand : "; }
	    if(Language== 1 ){ cout<<"Araba Markasi : ";}
		cout << car_directory[i].brand  << endl;
		if(Language== 0 ){cout<<"Do you update information (Y/N) : "; }
	    if(Language== 1 ){ cout<<"Bilgiyi güncellemek istiyor musun (E/H) : ";}
	    cin>>choice;
	    if(choice == 'Y' || choice == 'y' || choice == 'E' || choice == 'e')
	    {
        if(Language== 0 ){cout<<"New Car Brand : "; }
	    if(Language== 1 ){ cout<<"Yeni Araba Markasi : ";}
		cin >> car_directory[i].brand;
		}
        
          
        if(Language== 0 ){cout<<"Car Model : "; }
	    if(Language== 1 ){ cout<<"Araba Modeli : ";}
		cout << car_directory[i].model  << endl;
		if(Language== 0 ){cout<<"Do you update information (Y/N) : "; }
	    if(Language== 1 ){ cout<<"Bilgiyi güncellemek istiyor musun (E/H) : ";}
	    cin>>choice;
	    if(choice == 'Y' || choice == 'y' || choice == 'E' || choice == 'e')
	    {
        if(Language== 0 ){cout<<"New Car Model : "; }
	    if(Language== 1 ){ cout<<"Yeni Araba Modeli : ";}
		cin >> car_directory[i].model;
		}
        
         
        if(Language== 0 ){cout<<"Car Year of production : "; }
	    if(Language== 1 ){ cout<<"Araba Üretim Yili : ";}
        cout<< car_directory[i].make  << endl;
        if(Language== 0 ){cout<<"Do you update information (Y/N) : "; }
	    if(Language== 1 ){ cout<<"Bilgiyi güncellemek istiyor musun (E/H) : ";}
	    cin>>choice;
	    if(choice == 'Y' || choice == 'y' || choice == 'E' || choice == 'e')
	    {
        if(Language== 0 ){cout<<"New Car Year of production : "; }
	    if(Language== 1 ){ cout<<"Yeni Araba Üretim Yili : ";}
		cin >> car_directory[i].make;
		}
        
        if(Language== 0 ){cout<<"Registiration date : "; }
	    if(Language== 1 ){ cout<<"Kayit Tarihi : ";}
        cout <<car_directory[i].reg_date.day <<"/"<<car_directory[i].reg_date.month <<"/"<< car_directory[i].reg_date.year<<endl;
        if(Language== 0 ){cout<<"Do you update information (Y/N) : "; }
	    if(Language== 1 ){ cout<<"Bilgiyi güncellemek istiyor musun (E/H) : ";}
	    cin>>choice;
	    if(choice == 'Y' || choice == 'y' || choice == 'E' || choice == 'e')
	    {
        if(Language== 0 ){cout<<"New Registiration day : "; }
	    if(Language== 1 ){ cout<<"Yeni Kayit Günü : ";}
		cin >> car_directory[i].reg_date.day;

         
         if(Language== 0 ){cout<<"New Registiration month : "; }
	    if(Language== 1 ){ cout<<"Yeni Kayit Ayi : ";}
         cin >> car_directory[i].reg_date.month;

         
        if(Language== 0 ){cout<<"New Registiration Year : "; }
	    if(Language== 1 ){ cout<<"Yeni Kayit Yýlý : ";}
		         cin >> car_directory[i].reg_date.year;
		}
        


        
        if(Language== 0 ){cout<<"Next service date : "; }
	    if(Language== 1 ){ cout<<"Sonraki servis tarihi : ";}
        cout << car_directory[i].ns_date.day << "/"<< car_directory[i].ns_date.month << "/"<<car_directory[i].ns_date.year << endl;
        
         if(Language== 0 ){cout<<"Do you update information (Y/N) : "; }
	    if(Language== 1 ){ cout<<"Bilgiyi güncellemek istiyor musun (E/H) : ";}
	    cin>>choice;
	    if(choice == 'Y' || choice == 'y' || choice == 'E' || choice == 'e')
	    {
        if(Language== 0 ){cout<<"New Next service day : "; }
	    if(Language== 1 ){ cout<<"Yeni Sonraki servis günü : ";}
		cin >> car_directory[i].ns_date.day;

        
         if(Language== 0 ){cout<<"New Next service month : "; }
	    if(Language== 1 ){ cout<<"Yeni Sonraki servis ayý : ";}
         cin >> car_directory[i].ns_date.month;

         
         if(Language== 0 ){cout<<"New Next service year : "; }
	    if(Language== 1 ){ cout<<"Yeni Sonraki servis yýlý : ";}
         cin >> car_directory[i].ns_date.year;
		}
        
        
         
         cout<<endl;
         
        freopen("cars.dat", "w", CarDATA);

  
   if(CarDATA == 0)
   {
      
      exit(1);
   }

   
   for(int i = 0; i <size; i++)
   {
      
      if(car_directory[i].ID != 0)
      {   
       fprintf(CarDATA, "%5d %20s %20s %20s %20s %20s %20s %5d %5d %5d %5d %5d %5d\r\n", car_directory[i].ID, car_directory[i].owner_name, car_directory[i].owner_surname,car_directory[i].owner_phone, car_directory[i].brand, car_directory[i].model, car_directory[i].make, car_directory[i].reg_date.day, car_directory[i].reg_date.month, car_directory[i].reg_date.year, car_directory[i].ns_date.day, car_directory[i].ns_date.month, car_directory[i].ns_date.year);
	  }
   }

   
   freopen("cars.dat", "r+", CarDATA);

   
   if(CarDATA == 0)
   {
      
      exit(1);
   }
        
        system("cls");
         if(Language== 0 ){cout<<"Record has been updated: "; }
	    if(Language== 1 ){ cout<<"Kayit güncellendi ";}
		cout << endl << endl;
		
		

       }
   }
	
	
	
}

void SortIDASC(void){

	setlocale(LC_ALL, "Turkish"); 
	for(int i = 0; i < size; i++){
		        
		if(car_directory[i].ID != 0)
		{ 
        cout << "\nID: " << car_directory[i].ID  << endl;

        if(Language== 0 ){cout<<"Owner name : "; }
	    if(Language== 1 ){ cout<<"Müsteri Adi : ";}
        cout << car_directory[i].owner_name  << endl;

        if(Language== 0 ){cout<<"Owner surname : "; }
	    if(Language== 1 ){ cout<<"Müsteri Soyadi : ";}
        cout << car_directory[i].owner_surname  << endl;
        
        if(Language== 0 ){cout<<"Owner phone : "; }
	    if(Language== 1 ){ cout<<"Müsteri telefonu : ";}
        cout << car_directory[i].owner_phone  << endl;

        if(Language== 0 ){cout<<"Car Brand : "; }
	    if(Language== 1 ){ cout<<"Araba Markasi : ";}
		cout << car_directory[i].brand  << endl;
          
        if(Language== 0 ){cout<<"Car Model : "; }
	    if(Language== 1 ){ cout<<"Araba Modeli : ";}
		cout << car_directory[i].model  << endl;
         
        if(Language== 0 ){cout<<"Car Year of production : "; }
	    if(Language== 1 ){ cout<<"Araba Üretim Yili : ";}
        cout<< car_directory[i].make  << endl;
         

        if(Language== 0 ){cout<<"Registiration date : "; }
	    if(Language== 1 ){ cout<<"Kayit Tarihi : ";}
        cout <<car_directory[i].reg_date.day <<"/"<<car_directory[i].reg_date.month <<"/"<< car_directory[i].reg_date.year<<endl;

        if(Language== 0 ){cout<<"Next service date : "; }
	    if(Language== 1 ){ cout<<"Sonraki servis tarihi : ";}
        cout << car_directory[i].ns_date.day << "/"<< car_directory[i].ns_date.month << "/"<<car_directory[i].ns_date.year << endl;
       }
         

         
	cout << endl;
	
	
	
}

}

void SortIDDESC(void){

	setlocale(LC_ALL, "Turkish"); 
	for(int i = size; i > 0; i--){
		         
		if(car_directory[i-1].ID != 0)
		{
	
        cout << "\nID: " << car_directory[i-1].ID  << endl;

        if(Language== 0 ){cout<<"Owner name : "; }
	    if(Language== 1 ){ cout<<"Müsteri Adi : ";}
        cout << car_directory[i-1].owner_name  << endl;

        if(Language== 0 ){cout<<"Owner surname : "; }
	    if(Language== 1 ){ cout<<"Müsteri Soyadi : ";}
        cout << car_directory[i-1].owner_surname  << endl;
        
        if(Language== 0 ){cout<<"Owner phone : "; }
	    if(Language== 1 ){ cout<<"Müsteri telefonu : ";}
        cout << car_directory[i-1].owner_phone  << endl;

        if(Language== 0 ){cout<<"Car Brand : "; }
	    if(Language== 1 ){ cout<<"Araba Markasi : ";}
		cout << car_directory[i-1].brand  << endl;
          
        if(Language== 0 ){cout<<"Car Model : "; }
	    if(Language== 1 ){ cout<<"Araba Modeli : ";}
		cout << car_directory[i-1].model  << endl;
         
        if(Language== 0 ){cout<<"Car Year of production : "; }
	    if(Language== 1 ){ cout<<"Araba Üretim Yili : ";}
        cout<< car_directory[i-1].make  << endl;
         

        if(Language== 0 ){cout<<"Registiration date : "; }
	    if(Language== 1 ){ cout<<"Kayit Tarihi : ";}
        cout <<car_directory[i-1].reg_date.day <<"/"<<car_directory[i].reg_date.month <<"/"<< car_directory[i].reg_date.year<<endl;

        if(Language== 0 ){cout<<"Next service date : "; }
	    if(Language== 1 ){ cout<<"Sonraki servis tarihi : ";}
        cout << car_directory[i-1].ns_date.day << "/"<< car_directory[i].ns_date.month << "/"<<car_directory[i].ns_date.year << endl;
	}
         

         
	cout << endl;
	
	
	
}

}
void SortNameASC(void){

	setlocale(LC_ALL, "Turkish"); 
}
void SortNameDESC(void){

	setlocale(LC_ALL, "Turkish"); 
	
}

char SortId(char choice){
		setlocale(LC_ALL, "Turkish"); 

	
	if(choice == 'A' || choice == 'a')
	{
		 if(Language== 0 ){cout<<"A-Sort according to car id (ASC) :\n"; }
	     if(Language== 1 ){ cout<<"A-Araba ID numarasýna göre sýralama (ASC) :\n";}

		
		SortIDASC();
	}
	if(choice == 'B' || choice == 'b')
	{
		if(Language== 0 ){cout<<"B-Sort according to car id (DESC) :\n"; }
	    if(Language== 1 ){ cout<<"B-Araba ID Numarasýna göre sýralama (DESC) :\n";}

		SortIDDESC();
	}
}



void SortName(void){

	setlocale(LC_ALL, "Turkish"); 
	

	 if(Language== 0 ){cout<<"Sorting :\n1-Sort according to car id (ASC)\n2-Sort according to car id (DESC)\n"; }
	            if(Language== 1 ){ cout<<"Sýralama :\n1-Araba ID numarasýna göre sýralama (ASC)\n2-Araba ID Numarasýna göre sýralama (DESC)\n";}




			
		
}



void ChangeLanguage(void){

	setlocale(LC_ALL, "Turkish"); 
	if(Language==0)
	{
		Language = 1;
	}
	else if(Language==1)
	{
		Language = 0;
	}
}

int main(void)
{
     
   while(true)
   {
   	size=0;
   	CarDATA = fopen("cars.dat", "r+");

   
   if(CarDATA == 0)
   {
      
      return 1;
   }

   
   while(fscanf(CarDATA, "%5d %20s %20s %20s %20s %20s %20s %5d %5d %5d %5d %5d %5d\r\n", &(car_directory[size].ID), car_directory[size].owner_name, car_directory[size].owner_surname,car_directory[size].owner_phone,car_directory[size].brand, car_directory[size].model,car_directory[size].make, &(car_directory[size].reg_date.day), &(car_directory[size].reg_date.month), &(car_directory[size].reg_date.year), &(car_directory[size].ns_date.day), &(car_directory[size].ns_date.month), &(car_directory[size].ns_date.year)) != EOF)
   {     
      
     
      size++;
   }
   	
   	   
   	  	int choice,id, sID,cnt;
	     char submenuchoice;
    if(Language== 0 )//|| Language == "En" || Language == "eN" || Language == "en"
    { 
    cout<<"---------------------------------------\n";	
	cout<<"Car Service Application v0.1.234 (CMD)\n";
	cout<<"---------------------------------------\n";	
	cout<<"MENU :\n";
	cout<<"0-Change Language\n";
	cout<<"1-Add a new car to directory\n";
	cout<<"2-Delete a car from the directory\n";
	cout<<"3-List available cars in the directory\n";
	cout<<"4-Search a car:\n  A-Search according to car id\n  B-Search according to owner_name\n";
	cout<<"5-Update car information\n";
	cout<<"6-Sort according to car id\n";
	cout<<"7-Exit the program\n";
		cout<<"---------------------------------------\n";	
	cout<<endl << endl;
	cout << "Main Menu Select : ";
    cin >> choice;	
	}
	else if(Language== 1)
	{
		setlocale(LC_ALL, "Turkish"); 
	cout<<"-------------------------------------------\n";	
	cout<<"Araba Servis Uygulamasi v0.1.234 (CMD)\n";
	cout<<"-------------------------------------------\n";	
    cout<<"MENÜ :\n";
    cout<<"0-Dili deðiþtir\n";
    cout<<"1-Dizine Yeni araba ekleyin\n";
    cout<<"2-Dizinden araba silin\n";
    cout<<"3-Dizinde mevcut olan arabalari listeleyin\n";
    cout<<"4-Araba ara:\n  A-Araba ID numarasina göre arama\n  B-Araba owner_name bilgisine göre arama\n";
    cout<<"5-Araba bilgisini güncelleme\n";
    cout<<"6-Araç id numarasina göre siralama\n";
    cout<<"7-Programdan Çikis\n";
    cout<<"-------------------------------------------\n";	

          cout  << endl;
           cout << "Ana Menü Seçimi : ";
      cin >> choice;

    }

		system("cls");


      switch(choice){
      	    case 0:
      	    ChangeLanguage();
      	    break;
      	    case 1:
      		AddCar();
      		break;
      		case 2:
      		if(Language== 0 ){cout<<"Enter Car ID (Delete Progress) :"; }
	        if(Language== 1 ){ cout<<"Araba ID Numarasi Gir (Silme Iþlemý) : ";}
			cin >> sID;
      		DeleteCar(sID);
      		break;
      		case 3:
      		ListCar();
      		break;
      		case 4:
      	    if(Language== 0 ){cout<<"Searching :\nA-Searcing according to car id \nB-Searching according to owner_name\n\nEnter the Sub Menu (A or B) :"; }
	        if(Language== 1 ){ cout<<"Arama :\nA-Araba ID numarasýna göre arama \nB-Müþteri adýna göre sýralama \n\nAlt Menü Seçeneklerinden birini girin (A veya B) : ";}
			cin >> submenuchoice;
            SearchCar(submenuchoice);
      		break;
      		case 5:
      		if(Language== 0 ){cout<<"Enter Car ID (Update Progress) :"; }
	        if(Language== 1 ){ cout<<"Araba ID Numarasi Gir (Güncelleme Iþlemý) : ";}
			cin >> sID;
      		UpdateCar(sID);
      		break;
      		case 6:		
      		if(Language== 0 ){cout<<"Sorting :\nA-Sort according to car id (ASC)\nB-Sort according to car id (DESC)\n\nEnter the Sub Menu (A or B) :"; }
	        if(Language== 1 ){ cout<<"Sýralama :\nA-Araba ID numarasýna göre sýralama (ASC)\nB-Araba ID Numarasýna göre sýralama (DESC)\n\nAlt Menü Seçeneklerinden birini girin (A veya B) : ";}
			cin >> submenuchoice;
      		SortId(submenuchoice);
      		break;
      		case 7:
      			if(Language== 0 ){cout<<"For Exit Press Enter!!!"; }
	        if(Language== 1 ){ cout<<"Çikiþ için Enter Tuþuna Basýnýz!!! ";}
      		cout << "";
      		return 0;
      		break;
      		default:
      		printf("Incorrect Choice!!");
	  }   
   }

   
   fclose(CarDATA);

   
   return 0;
}

