#include <iostream>
using namespace std;

struct Nodo{
	char info;
	Nodo *sig;
};

class Pila{
	private:
		Nodo *tope;
	public:
		Pila(){
			tope=NULL;
		}
	
	void apilar(char c){
		Nodo *q= new Nodo;
		q->info=c;
		q->sig=tope;
		tope=q;
		
	}
	
	char desapilar(){
		if(tope!=NULL){
		char c= tope->info;
		Nodo *q=tope;
		tope=tope->sig;
		delete q;
		return c;	
	
	}else{
		return '\0';
	}
}
	
	bool vacia() const {
		if(tope==NULL){
			return true;
		}else{
			return false;
		}
	}
	
	~Pila(){
		while(tope!=NULL){
			desapilar();
		}
	}
		
};

	bool esPalindromo(const string& palabra){
	Pila pila;
		for(char c: palabra){
			pila.apilar(c);
		}
		string invertida;
		while(pila.vacia()==false){
			invertida= invertida + pila.desapilar();
		}
		
		if(palabra==invertida){
			return true;
		}else{
			return false;
		}
		
	}		
	

int main(){

string palabra;
cout<<"Ingrese la palabra para verificar si es palindromo: ";
cin>>palabra;
	if(esPalindromo(palabra)){
		cout<<"Si es PALINDROMO";	
	}else{
		cout<<"No es PALINDROMO";
	}

	return 0;
}