#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;

int aleatorio() {
    // rand syntax: <int> = (<numeromenor> + rand() % ( <numeromayor> + 1 - <numeromenor> ) )
    int n = ( 0 + rand() % (255 - 0) ); // 2º generar numeros del 97 al 119
    return n;
 }


int main(){

	int num_docs;
	cout << "Inserte numero de ficheros a generar: " << endl;
	cin >> num_docs;
	if (num_docs < 1) cout << "El numero no corresponde al rango >= 1" << endl;
	else{
		for (int i = 0; i < num_docs; i++){
    		ofstream fich("output" +to_string(i+1)+ ".txt");
			int rand;
			for (int i = 0; i < 15; i++){
				rand = aleatorio();
				fich << "Numero generado: " << rand << " -> " << "Letra: " << char(rand) << endl;
			}
			fich.close();
		}
	}
}