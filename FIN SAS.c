#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//////////////////////////////
typedef struct {
    int jour;
    int moi;
    int anee;

}date_echeance;

 typedef struct {
    char titre [100];
    char description[256];
    int priorite;
     date_echeance date_echeance;
} tache;


int c=0;
tache k[100];
// fonctionne d'ajouter une tâche
void ajouter (){
    int size ;
        if (c >= 100) {
        printf("Limite maximale de transaction atteinte .\n");
        return;
    }

    printf("  Ajouter la  tache: \n");
    printf("  Entrer le titre de la tache :\n");
    scanf("%s", k[c].titre);

    printf("  la description de la tache :\n");
    scanf("%s",k[c].description);

    printf("  la date d'échéance:\n");
    printf(" le jour :");
    scanf("%d",&k[c].date_echeance.jour);
    printf("le moi:");
    scanf("%d",&k[c].date_echeance.moi);
    printf("l'anee:");
    scanf("%d",&k[c].date_echeance.anee);


    printf("   Définir la priorité (1:pour High/0:pour Low):\n");
    scanf("%d",&k[c].priorite);
    c++;
    printf("   Tâche ajoutée \n ");

};
//FONCTION D AFFFICHAGE
void afficher (){
if (c==0){
printf (" aucun tache pour afficher.\n");
return;
}
int i;
printf("Les taches  qui existent sont:\n");
for(i=0;i<c;i++){
printf("le titre: %s \n",k[i].titre);
printf("la description :%s \n", k[i].description);
printf("la date d'échéance: \n");
if (k[i].priorite == 1) {
    printf("Priorité : High\n");
} else if (k[i].priorite == 0) {
    printf("Priorité : Low\n");
}
}
}


void supprimer(){
    int s;
    printf("Entrez le numéro de la tâche que vous souhaitez supprimer : ");
    scanf("%d",&s);
    if (s < 1 || s > c){
        printf(" la tache n’existe pas !!!");
    }
    for (int j = s; j < c - 1;j++){
     k[j] = k[ j + 1];
    }
    c--;
}
    void   mettre_a_jour() {
    int M;
    printf("Entrez le numéro de la tâche à mettre à jour : ");
    scanf("%d", &M);
    if (M < 1 || M > c) {
        printf("La tâche n'existe pas !\n");
        return;
    }
    M--;

    printf("Titre actuel : %s \n", k[M].titre);
    printf("Entrez un nouveau titre : ");
    scanf(" %s", k[M].titre);

    printf("Description actuelle : %s\n", k[M].description);
    printf("Entrez une nouvelle description : ");
    scanf(" %s", k[M].description);

    printf("Date d'échéance actuelle : %02d/%02d/%04d\n", k[M].date_echeance.jour, k[M].date_echeance.moi, k[M].date_echeance.anee);
    printf("Entrez une nouvelle date d'échéance :\n");
    printf("Jour : ");
    scanf("%d", &k[M].date_echeance.jour);
    printf("Mois : ");
    scanf("%d", &k[M].date_echeance.moi);
    printf("Année : ");
    scanf("%d", &k[M].date_echeance.anee);

    printf("Priorité actuelle : %d\n", k[M].priorite);
    printf("Entrez une nouvelle priorité (High/Low) : ");
    scanf("%d", &k[M].priorite);

    printf("Tâche mise à jour avec succès !\n");
}

void filtrer_par_priorite() {
    int priorite_filter;
    bool found = false;

    printf("Entrez la priorité à filtrer (1 pour High, 0 pour Low) : ");
    scanf("%d", &priorite_filter);

    printf("Les tâches avec priorité '%d' sont :\n", priorite_filter);

    for (int i = 0; i < c; i++) {
        if (k[i].priorite == priorite_filter) {
            printf("Titre : %s\n", k[i].titre);
            printf("Description : %s\n", k[i].description);
            printf("Date d'échéance : %02d/%02d/%04d\n \n", k[i].date_echeance.jour, k[i].date_echeance.moi, k[i].date_echeance.anee);
            if (k[i].priorite == 1) {
    printf("Priorité : High\n ");
} else if (k[i].priorite == 0) {
    printf("Priorité : Low\n");
}
            found = true;
        }
    }

}
int main(){
    int choix ;

    do{
        printf("==============================\n");
        printf("::::::::::: MENU :::::::::::::\n");
        printf("==============================\n");
        printf("           Entrer:\n");
        printf("1.pour ajouter une tache:\n");
        printf("2.pour Afficher la Liste des Tâches:\n");
        printf("3.pour Modifier une Tâche :\n");
        printf("4.pour Supprimer une Tâche : \n");
        printf("5.pour Filtrer les Tâches :\n");
        printf("votre choix:\n");
        scanf("%d",&choix);
        switch(choix){
            case 1 :
            printf("vous avez choisi le choix d'ajout. \n");
            ajouter ();
            break;

            case 2 :
            printf("vous avez choisi le choix d'affichage. \n");
            afficher ();
            break;
            case 3:
            printf("vous avez choisi le chiox de mettre a jour .\n");
            mettre_a_jour();
              break;
            case 4:
             printf("vous avez choisi le choix de supprimer. \n");
             supprimer();
             break;
            case 5:
            printf("vous avez choisi le choix de filtrer. \n");
            filtrer_par_priorite();
        }
    }
while(choix < 6 );
return 0;
}
