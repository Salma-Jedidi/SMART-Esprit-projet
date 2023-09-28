#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>
#include "CRUD.h"

//Ajouter un reclamation 

void ajouter_reclamation( reclamation t){
FILE*f=NULL; //flot de donnée
f=fopen("reclamation.txt","a+");// creation du fichier reclamation .txt et ouverture en  mode lecture et ecriture a la fin
fprintf(f,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation); //f variable de type file 
fclose(f);
 //retour NULL si operation fini 
}
//********************************************************





//verifier l'existance 

int exist_reclamation(char*cin){
FILE*f=NULL;
reclamation t;
f=fopen("reclamation.txt","r");// ouverture du fichier reclamation en  mode lecture 
while(fscanf(f,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation)!=EOF){
if(strcmp(t.cin,cin)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}

//*****************************************************************




//supprimer tr
void supprimer_reclamation(char*cin){
FILE*f=NULL;
FILE*f1=NULL;
reclamation t ;
f=fopen("reclamation.txt","r");
f1=fopen("ancien.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation)!=EOF){
if(strcmp(cin,t.cin)!=0)
fprintf(f1,"%s %s %s %s %s %s\n",t.cin,t.service,t.numerochambre,t.date,t.nometprenom,t.reclamation);
}
fclose(f);
fclose(f1);
remove("reclamation.txt");
rename("ancien.txt","reclamation.txt");
}

//******************************************************************
















