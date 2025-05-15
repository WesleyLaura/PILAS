# include <iostream>
using namespace std;
struct Nodo{
	int info;
	Nodo *sig;
};

class Pila{
	private :
		Nodo * tope;  //Apunta al nodo superior de la pila
	public :
		Pila(){
			tope=NULL;
		}
		
		
		//metodo para agregar un elemento a una pila
		void agregarPila(int  dato){
			Nodo *q= new Nodo;
			q->info=dato;
			q->sig=tope;
			tope=q;
		}
		
		//metodo para quitar un elemento de la pila
		
		void sacarPila(){
			if(tope!=NULL){
			Nodo *q=tope;
			tope=q->sig;
			delete q;	
			}else
			cout<<"Pila vacia,no se puede scar elemento\n";
			return;
		}
		
		//metodo para mostrar todos los elemento de la pila
		void mostrarPila(){
			if(tope!=NULL){
				cout<<"Los elementos de la Pila son: ";
				Nodo *q=tope;
				while(q!=NULL){
					cout<<q->info<<" ";
					q=q->sig;
				}
			}else{
				cout<<"La Pila esta vacia";
				return;
			}
		}
		
		//metodo para contar los elementos de la pila
		
		int contarElementosPila(){
				Nodo *q=tope;
				int c=0;
				while(q!=NULL){
					c++;
					q=q->sig;
				}
			return c;
		}
		
		//metodo para buscar un elemetno en la pila
		bool buscarElementoPila(int dato){
			Nodo *q=tope;
			int cen=0;
			while(q!=NULL){
				if(q->info==dato){
					return true;
				}	
				q=q->sig;
			}
			return false;
		}
		
		//metodo para comparar Pila y Pila2
		
		bool compararCon(Pila& pila2){
			Nodo *q=tope;
			Nodo *q2=pila2.tope;
			int cen=0;
			while(q!=NULL && q2!=NULL){
				if(q->info==q2->info){
					return true;
				}else{
					q=q->sig;
					q2=q2->sig;
				}
			}
					return false;
			
		}
		
		//destructor para liberar memoria
		~Pila(){
			while (tope != NULL){
				sacarPila();
			}
		}
};
	void menu(){
		
		Pila pila;
		Pila pila2;
		int op, dato;
		
		do{
			cout<<"\t\n-------MENU PILA-----------\n"<<endl
				<<"1.- Apilar en Pila 1"<<endl
				<<"2.- Despilar en Pila 1"<<endl
				<<"3.- Mostrar Pila 1"<<endl
				<<"4.- Contar elementos de Pila 1"<<endl
				<<"5.- Buscar un elemento en Pila 1"<<endl
				<<"6.- Apilar en Pila 2"<<endl
				<<"7.- Mostrar Pila 2"<<endl
				<<"8.- Comparar Pila 1 con Pila 2"<<endl
				<<"0.- S A L I R"<<endl;
			cout<<"Escriba la opcion: ";cin>>op;
					
					switch(op){
						case 1:
							cout<<"Ingrese dato a apilar en Pila 1: ";
							cin>>dato;
							pila.agregarPila(dato);
							break;
						case 2:
							pila.sacarPila();
							break;
						case 3:
							pila.mostrarPila();
							break;
						case 4:
							cout<<" Cantidad de elementos en Pila 1 : "<<pila.contarElementosPila()<<endl;
							break;
						case 5:
							cout<<"Ingrese el elemento a buscar en Pila 1: ";
							cin>>dato;
							cout<<"Esta el "<<dato<<" ?: "<<(pila.buscarElementoPila(dato) ? "SI" : "NO")<<endl;
							break;
						case 6:
							cout<<"Ingrese dato a apilar en Pila 2: ";
							cin>>dato;
							pila2.agregarPila(dato);
							break;
						case 7:
							pila2.mostrarPila();
							break;
						case 8:
							if(pila.compararCon(pila2)){
								cout<<"Las pilas son iguales.\n";
							}else{
								cout<<"Las pilas son diferentes.\n";
							}
							break;		
						case 0:
							cout<<"Programa finalizado\n";
							break;
						default:
							cout<<"Opcion Invalida\n";			
					}
		}while( op != 0);
		
	}	
		
int main(){
	setlocale(LC_ALL,"");
	menu();
}