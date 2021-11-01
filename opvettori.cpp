#include <iostream>
using namespace std;
void carica(int x[],int l)
{
	int k;
	for (k=0;k<l;k++)
	{
		cout <<"Inserisci elemento:\t";
		cin >> x[k];
	}
}
void stampa(int x[],int l)
{
	int k;
	cout <<"Elementi del vettore:\n";
	for (k=0;k<l;k++)
			cout <<"\t"<<x[k];
}
void ricerca_seq(int x[],int y,int l)
{
	int trovato=0;
	int k;
	cout <<"\n inserisci elemento da cercate\t";
	cin >> y;
	for (k=0;k<l;k++)
	{
		if (x[k]==y)
		{
			trovato=1;
			cout <<"\nElemento trovato nella posizione\t \t"<<k;
		}
	}
	if (trovato==0)
		cout <<"\nNessun elemento è stato trovato\n";
}
void ricerca_flag(int x[],int l,int y)
{
	int flag=0;
	int k=0;
	cout <<"\n inserisci elemento da cercate\t";
	cin >> y;
	while ((flag==0) && (k<l))
	{
		if (x[k]==y)
		{
			flag=1;
			cout <<"\nElemento trovato nella posizione\t" <<k;
		}
		k++;
	}
}
void ordinaselezione (int x[],int l)
{
	int i,k,tmp;
	for (i=0;i<l-1;i++)
		for (k=i+1;k<l;k++)
			if (x[i]>=x[k])
				{
					tmp=x[i];
					x[i]=x[k];
					x[k]=tmp;
				}
}
void ordinabolle(int x[],int l)
{
	int i,tmp,j;
	bool scambio;
	j=0;
	do {
		scambio=false;
		i=l-1;
		do {
			if (x[i] <=x[i-1])
				{
					tmp=x[i-1];
					x[i-1]=x[i];
					x[i]=tmp;
					scambio = true;
				}
				i--;}
		while (i!=j);
		j++;
		}
	while (scambio==true && j!=l-1);	
	}
void ricercabin (int x[], int &y, int l)
{
	int inf,sup,centro;
	bool trovato;
	cout <<"\n Inserisci l'eleento da ricercare nell'array \t";
	cin >> y;
	inf=0;
	sup=l-1;
	trovato=false;
	while (inf <=sup and trovato==false)
	{
		centro = (inf+sup)/2;
		if (x[centro]==y) 
		{
				trovato=true;
				cout <<"\nElemento trovato in posizione \t "<<centro;
		}
		else
			if (y< x[centro])
				sup=centro;
			else
				inf=centro;
	}
	if (!trovato)
		cout <<"\n Elemento non trovato nel vettore\n";
}
void compatta (int x[],int y[],int l,int &m)
{
	int j,i;
	j=0;
	for (i=0;i<l;i++)
		if (x[i]>=0)
			{
				y[j]=x[i];
				j++;
			}
			m=j;
}
void fusione(int x[],int y[],int z[],int l1,int l2,int &l3)
{
	int i;
	for (i=0;i<l1;i++)
		z[i]=x[i];
	for (i=0;i<l2;i++)
		z[i+l1] = y[i];
		l3=l1+l2;
	ordinabolle(z,l3);
}
int main()
{
	int n,vet[100],ig,sost;
	int vet2[100],p;
	int vet3[100],q;
	int incognito;
	cout <<	"Inserisci il numero degli elementi del vettore\n";
	cin >> n;
	carica(vet,n);
	//ordinaselezione (vet,n);
	ordinabolle(vet,n);
	stampa(vet,n);
	ricercabin(vet,incognito,n);
	ricerca_seq(vet,ig,n);
	ricerca_flag(vet,ig,n);
	compatta(vet,vet2,n,p);
	stampa(vet2,p);
	cout << "\nInser)isci il numero degli elementi del secondo vettore\n";
	cin >> p;
	carica(vet2,p);
	fusione(vet,vet2,vet3,n,p,q),
	stampa(vet3,q);
	return 0;
}
