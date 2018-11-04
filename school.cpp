//
// copyright Naoual SMAILI
//
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int sem=6;
void saisie(float [], int , int );

struct smp{
	string nom;
	string prenom;
	float note[6];
};

int main(){
smp etudiant[20];
int note, nsession;
fstream file("Notes.dat", ios::out);
for(int k=0;k<20;k++){
cout<<"\n\n\t\t *** Etudiant N "<<k+1<<" ***"<<endl;
cout<<"Saisir le nom: ";
cin>>etudiant[k].nom;
cout<<"Saisir le prenom: ";
cin>>etudiant[k].prenom;
file<<"\n=====================================\n";
file<<etudiant[k].nom<<"\t"<<etudiant[k].prenom;
file<<"\n=====================================\n";

for(int nsession=1; nsession<=sem; nsession ++){
	int somn=0;
	saisie(etudiant[k].note,6,nsession);
	file<<"\n semestre N "<<nsession<<" : "<<endl;
	for(int i=0;i<6;i++){
	file<<"Note N "<<i+1<<" : "<<etudiant[k].note[i]<<"\t";
	file<<endl;
	somn+=etudiant[k].note[i];
	}
	int moy=somn/6;
	file<<"\nMoyenne semestre: "<<moy<<"\t\t";
	if(moy> 10)
       file<<"Semestre valide\n";
    else 
	   file<<"Non valide\n";
	}
	file<<endl;
	
system("cls");
	
}
	file.close();

return 0;
 }
void saisie(float tab[], int n, int ns){
	float *p=&tab[0];
	cout<<"\n semestre: ";
	cin>>ns;
	cout<<"\n saisir les notes des 6 modules: \n";
	while(p<tab+n){
		cin>>*p;
		p++;
	}
}

