// Lagrange_Interpolasyon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double sol(double xdeger, int derece, double Z[], int call) {
    double xdegertemp = xdeger;
    double usttemp = 1;
    double alttemp = 1;
    double hesap;

    for (int i = 0; i < derece; i++)
    {
        double xdegertemp2 = xdegertemp;
        double temp = 0;
        if (call != i)
        {
            temp = (xdegertemp2 - Z[i]);
            usttemp = usttemp * temp;

        }

    }

    for (int j = 0; j < derece; j++)
    {
        double temp = 0 ;
        if (call != j)
        {
            temp = (Z[call] - Z[j]);
            alttemp = alttemp * temp;
        }
    }

    hesap = usttemp / alttemp;

    return hesap;
}
// geliþtirilmemiþ metottur.
//  
// sol2 metodunu kullanýnýz
// 
// 
//**************************************
double sol2(double xdeger, int derece, double Z[], int call) {
    double term = Z[call];
    double hesap = 1.0;

    for (int i = 0; i < derece; i++)
    {
        
        if (call != i)
        {
            hesap *= (xdeger - Z[i]) / (term - Z[i]);
            
        }
        
    }
    return hesap;
}





int main()
{
    
    double noktad = 2;
    int nokta;
    double xdeger;
    double hesap = 0;
    double Z[15]{};
    double FZ[15]{};


    cout << "Nokta sayinizi en az 2 , en fazla 15 olacak sekilde giriniz : ";
    do
    {
        
     cin >> noktad;

           if (!(noktad >= 2 && noktad <= 15))
           {
           cout << "girdiginiz sayi verilen araligi saglamamaktadir lutfen kontrol edip tekrar giriniz : " ;
           }
        
        
           nokta = (int) noktad; // kusuratlý bir sayi girilir diye baþta double alýp int e cast ettim bu sayede input alýrken inf loop hatasýný engelledim
    } while (!(noktad>=2&&noktad<=15));
    
    int tempnokta = nokta;


    int derece = tempnokta-1;
    cout << "nokta sayisi :"<<nokta <<"\n";
    cout << "derece       :" << derece << "\n\n";
    cout << "belirtilen yerlerde X ve F(x) degerlerini giriniz.\n\n";
        for (int i = 0; i < nokta; i++)
        {
            cout << "X --> X_" << i << "   : "; 
            cin >> Z[i];
            cout << "Y --> F(" << Z[i] << ")  : ";
            cin >> FZ[i];
            cout << "\n";
            for (int j = 0; j < i; j++)
            {
                if (Z[i]==Z[j])
                {
                        cout << "ayni x noktasi iki farkli y degerine gidemez lutfen farkli bir x degeri girerek tekrar deneyiniz\n";
                        i--;
                }

            }
               
        }
        
            cout << "hesaplamak istediginiz X degerini giriniz : ";
            cin >> xdeger;



    for (int i = 0; i < nokta; i++)
    {//dizi göstergesi
        cout << "X = " << Z[i] << "  F(x) = " << FZ[i] <<"\n";
    }
    

    double temp = 0;
    for (int call = 0; call < nokta; call++)
    {
       
        temp = (sol2(xdeger, nokta, Z, call) * FZ[call]);
        
        hesap += temp;
    }
    cout << "\nHesaplama \n";
    cout << "X = " << xdeger << "  F(" << xdeger << ") = " << hesap << "\n\n";
    
    
    
    
    


    
}



