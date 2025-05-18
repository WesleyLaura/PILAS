#include <iostream>
#define MAX 100
using namespace std;

class Pila{
	private:
		char elemento[MAX];
		int tope;
	public:
		Pila();
		void apilar(char dato);
		bool pilaVacia();
		char desapilar();
		bool esPalindromo(const string& palabra);
				
};			
Pila::Pila(){
	tope=-1;
}

bool Pila::pilaVacia(){
	if(tope==-1){
		return true;
	}
		return false;
}
void Pila::apilar(char dato){
	tope++;
	elemento[tope]=dato;
}

char Pila::desapilar(){
	if(pilaVacia()){
		cout<<"PILA VACIA\n";
		return (0);
	}else{
		char dato=elemento[tope];
		tope--;
		return dato;
	}
}	

bool Pila::esPalindromo(const string& palabra){
	Pila pila;
	for(char c: palabra){
		pila.apilar(c);
	}
	
	string invertida;
	while(!pila.pilaVacia()){
		invertida=invertida + pila.desapilar();
	}
	
	if(palabra==invertida){
		return true;
	}
		return false;
}


		
int main(){
	Pila p;
	string palabra;
	cout<<"\t--------PALINDROMO-------\n";
	cout<<"Ingrese la palabra: "; 
	cin>>palabra;
	cout<<"ES PALINDROMO "<<palabra<<" ?: "<<(p.esPalindromo(palabra) ? "SI" : "NO");
	return 0;
}