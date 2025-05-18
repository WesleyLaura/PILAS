#include <iostream>
#include <string>
using namespace std;

#define MAX 100 // capacidad maxima de la pila
string invertirCadena(const string& str); 

class Pila{
	private:
		char elementos[MAX];
		int tope;
	public:
		Pila();
	
		bool pilaVacia();
		bool pilaLlena();
		void agregarPila(char dato);
		char sacarPila();
		char cima();
		void mostrarPila();
		int contarElementosPila();
		bool buscarElementoPila(char dato);
		bool compararCon(Pila& otra);
		bool revisarOperacionMatematica(const string& expmatematica);
		bool esPalindromo(const string& palabra);	
		int prioridad(char op);
};

// constructor

Pila::Pila(){
	tope=-1;  //pila vacia
}

//metodo para verificar si la pila esta vacia

bool Pila::pilaVacia(){
	if(tope==-1){
		return true;
	}else{
		return false;
	}
}

// metodo para verificar si la pila esta llena
bool Pila::pilaLlena(){
	if(tope==MAX -1){
		return true;
	}else{
		return false;
	}
}

//metodo para agrefar un elemento a la pila (push)
void Pila::agregarPila(char dato){
	if(pilaLlena()){
		cout<<"Desbordamiento - Pila llena. No se puede agregar mas alemento\n";
			return;
			
	}else{
		tope++;
		elementos[tope]=dato;
		}
}
//metodo para eliminar el elemento superior de la pila (pop)
char Pila::sacarPila(){
	if(pilaVacia()){
		cout<<"Subdesbordamiento - Pila vacia. No se puede sacar elemento.\n";
		return(0); //caracter nulo
	}else{
		char dato= elementos[tope];
		tope--;
		return dato;
		}
	
}

//metodo para ver el elemento en la cima de la  pila (peek)
char Pila::cima(){
	if(!pilaVacia()){
		return elementos[tope];
	}else{
		cout<<"Pila vacia\n";
		return -1;
	}
}

//metodo para mostrar todos los elementos de la pila

void Pila::mostrarPila(){
	if(pilaVacia()){
		cout<<"Pila vacia\n";
		return;
	}else{
		for(int i=tope;i>=0;i--){
			cout<<elementos[i]<< " ";	
		}
		cout<<"\n";
	}
}

//metodo para contar elememntos

int Pila::contarElementosPila(){
	return tope+1;
}

//metodo para buscar un elemento en la pila
bool Pila::buscarElementoPila(char dato){
	if(!pilaVacia()){
		int i=tope;
		while(i>=0){
			if(elementos[i]==dato){
				return true;
			}
			
			i--;
		}
	}
				return false;
}

//metodo para comparar con otra  pila
bool Pila::compararCon(Pila& pila2){
	if(tope!=pila2.tope){
		return false;	
	}
		int i=tope;
		while(i>=0 && pila2.elementos[i]==elementos[i]){
			i--;
		}

	if(i<0){
		return true;
	}else{
		return false;
	}
}

int Pila::prioridad(char op){
	switch(op){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;			
	}
}

// Convierte expresión infija a postfija
string infijaApostfija(const string& EI) {
    Pila pila;
    string postfija ="";
    for (char simbolo : EI) {
        if (isalnum(simbolo)) {
            postfija+=simbolo;
        } else if (simbolo=='(') {
            pila.agregarPila(simbolo);
        } else if (simbolo==')') {
            while (!pila.pilaVacia() && pila.cima()!='(') {
                postfija+=pila.sacarPila();
            }
            if (!pila.pilaVacia()) pila.sacarPila(); // eliminar '('
        } else {
            while (!pila.pilaVacia() && pila.prioridad(pila.cima())>= pila.prioridad(simbolo)) {
                postfija+=pila.sacarPila();
            }
            pila.agregarPila(simbolo);
        }
    }

    while (!pila.pilaVacia()) {
        postfija+=pila.sacarPila();
    }

    return postfija;
}

// Convierte expresión infija a prefija
string infijaAprefija(const string& EI) {
    string invertida=invertirCadena(EI);

    for (int i=0;i<invertida.length(); i++) {
        if (invertida[i] =='(')
            invertida[i] =')';
        else if (invertida[i] ==')')
            invertida[i] ='(';
    }
    string postfija=infijaApostfija(invertida);
    string prefija=invertirCadena(postfija);

    return prefija;
}

//metodo para revisar una operacion matematica 
bool Pila::revisarOperacionMatematica(const string& expmatematica){
	 Pila pila;
    for (char c : expmatematica) {
        if (c =='(') {
            pila.agregarPila(c);
        } else if (c ==')') {
            if (pila.pilaVacia()) return false;
            pila.sacarPila();
        }
    }
    return pila.pilaVacia();
}

// Función para invertir una cadena manualmente
string invertirCadena(const string& str) {
    string invertida = str;
    int n = invertida.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = invertida[i];
        invertida[i] = invertida[n - i - 1];
        invertida[n - i - 1] = temp;
    }
    return invertida;
}

//menu interactivo

void menu(){
	Pila pila1;
	Pila pila2;
	int op;
	char dato;
	string expresion;
	do{
		cout<<"\n\t---------MENU PILA------"<<endl
			<<"1.- Apilar en Pila 1"<<endl
			<<"2.- Desapilar en Pila 1"<<endl
			<<"3.- Mostrar Pila 1"<<endl
			<<"4.- Contar elementos en Pila 1"<<endl
			<<"5.- Buscar un elemento en Pila 1"<<endl
			<<"6.- Apilar Pila 2"<<endl
			<<"7.- Mostrar Pila 2"<<endl
			<<"8.- Comparar Pila 1 con Pila 2"<<endl
			<<"9.- Convertir de INFIJA a POSTFIJA"<<endl
			<<"10.-Convertir de INFIJA a PREFIJA"<<endl
			<<"11.-Validar PARENTESIS de operaciones matematicas "<<endl
			<<"0.- S A L I R"<<endl;
		cout<<"Opcion : "; cin>>op;
			cin.ignore();
						switch(op){
				case 1:
					cout<<"Ingrese dato a apilar en Pila 1:";
					cin>>dato;
					pila1.agregarPila(dato);
					break;
				case 2:
					pila1.sacarPila();
					break;
				case 3:
					pila1.mostrarPila();
					break;
				case 4:
					cout<<"Cantidad de elementos en Pila: "<<pila1.contarElementosPila()<<endl;
					break;
				case 5:
					cout<<"Ingrese el elemento a buscar en Pila 1: ";
					cin>>dato;
					cout<<"Esta el "<<dato<<" ?: "<<(pila1.buscarElementoPila(dato) ? "SI" : "NO")<<endl;
					break;
				case 6:
					cout<<"Ingrese dato a apilar en Pila 2:";
					cin>>dato;
					pila2.agregarPila(dato);
					break;				
				case 7:
					pila2.mostrarPila();
					break;
				case 8:
					cout<<"Son iguales : ?"<<(pila1.compararCon(pila2) ? "SI" : "NO")<<endl;
					break;
				case 9:
					cout<<"Ingrese expresión infija: ";
                	getline(cin, expresion);
                	cout<<"Postfija: "<<infijaApostfija(expresion)<<endl;
                	break;
                case 10:
                	cout<<"Ingrese expresión infija: ";
                	getline(cin, expresion);
                	cout << "Prefija: "<<infijaAprefija(expresion)<<endl;
                	break;
				case 11:
					cout<<"Ingrese la expresion matematica: ";
					getline(cin, expresion);
                	cout<<(pila1.revisarOperacionMatematica(expresion) ? "CORRECTO." : "INCORRECTO")<<endl;
                	break;		
				case 0:
					cout<<"Programa finalizado\n";
					break;
				default:
					cout<<"Opcion invalida\n";
					
			}			
	}while(op !=0);
}
int main(){
	menu();
	return 0;
}