#include <iostream>
#include <string.h>
using namespace std;
class fig{
public:
    int figura=0,baza[1][2]={},inaltime=0,aria=0;
    void cit (){
        cout<<"1-cerc 2-dreptunghi 3-patrat 4-triunghi dreptunghic\n";
        cout<<"Figura:";
        cin>>figura;
        if(figura==1) {
            cout<<"Raza:";
            cin >> baza[0][0]; //raza
            aria=baza[0][0]*baza[0][0]*3; //aproximam pi la 3
        }
        if(figura==2) {
            cout<<"Lungimea si latimea:";
            cin >> baza[0][0] >> baza[0][1]; //lungime si latime
            aria=baza[0][0]*baza[0][1];
        }
        if(figura==3) {
            cout<<"Latura:";
            cin >> baza[0][0]; //latura
            aria=baza[0][0]*baza[0][0];
        }
        if(figura==4) {
            cout<<"Cateta 1 si 2:";
            cin >> baza[0][0] >> baza[0][1]; // cateta 1 si cateta 2
            aria=baza[0][0]*baza[0][1]/2;
        }
        cout<<"Inaltimea:";
        cin>>inaltime;
    }

};
int main() {
    int gem=0,frisca=0,i=-1,k,j;
    char comanda[100],*p;
    fig shapes[101];
    gets(comanda);
    while(strcmp(comanda,"STOP")){
        if(strcmp(comanda,"TOTAL")==0){
            cout<<"frisca: "<<frisca<<"\ngem: "<<gem<<'\n';
        }
        else
        if(strcmp(comanda,"ADD")==0){
            shapes[++i].cit();
            cout<<"Cantitatile necesare de frisca:"<<shapes[i].aria<<" si gem:"<<shapes[i].aria*shapes[i].inaltime*2;
            gem+=shapes[i].aria*shapes[i].inaltime*2;
            frisca+=shapes[i].aria;
        }
        else{
            p= strtok(comanda," ");
            if(strcmp(comanda,"REMOVE")==0) {
                p = strtok(NULL, " ");
                k = atoi(p);
                gem -= shapes[k - 1].aria * shapes[k - 1].inaltime * 2;
                frisca -= shapes[k - 1].aria;
                for (j = k - 1; j <= i; ++j)
                    shapes[j] = shapes[j + 1];
                i--;
            }
        }
        cout<<'\n';
        fflush(stdin);
        gets(comanda);
    }
    return 0;
}