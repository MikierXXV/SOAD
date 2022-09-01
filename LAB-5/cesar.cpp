#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h>

 using namespace std;
 
void encriptar(char mensaje[100], int n){ 
    int i = 0;
    while(mensaje[i] != '\0') {
        mensaje[i] +=n;
        i++;
    }
        
}
void desencriptar(char mensaje[100], int n){ 
    int i = 0;
    while(mensaje[i] != '\0') {
        mensaje[i] -=n;
        i++;
    }
        
}
//void encriptar(char mensaje[100] ,int n); 
void intro(){
    cout << "Introduze la sentencia a encriptar: " << endl;
}

char ABC [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
char abc []= "abcdefghijklmnopqrstuvwxyz"; 
int n=0; 
int num_docs = 0;
int main(){ 
    char cadena[1000];
    cin.getline(cadena, 1000);   
    //cout << "Inserte numero de ficheros a generar: " << endl;
    cin >> num_docs;
    
    cout<<"introduce un numero: "; 
    cin>> n;

    clock_t time_total;
    time_total = clock();

    for (int i = 0; i < num_docs; i++){
        clock_t t;
        t = clock();

        ofstream fich("output" +to_string(i+1)+ ".txt");

        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; 

        fich << "Encriptado: " << endl;
        encriptar (cadena, n);
        fich << cadena << endl;
        fich << endl << "Desencriptado: " << endl;
        desencriptar(cadena, n);
        fich << cadena << endl;

        t = clock() - t;
        double time_taken1 = ((double)t)/CLOCKS_PER_SEC;

        fich << "Timer Initialize: " << endl;
        fich << "The program took " << time_taken << " seconds to execute" << endl;;

        fich << "Timer Performing: " << endl;
        fich << "The program took " << time_taken1 << " seconds to execute" << endl;;
        fich.close();
    } 
    time_total = clock() - time_total;
    double time_taken2 = ((double)time_total)/CLOCKS_PER_SEC; 
    cout << "Total time spend: " << time_taken2 << endl;
}
