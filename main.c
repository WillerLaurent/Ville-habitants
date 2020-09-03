#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main()
{
    printf("Classement de ville par leur nombre d'habitants :\n");

    Ville tableau[100];
    int i, n;

    //initialisation de n :
    printf("Combien de ville voulez vous enregistrer ? ");
    scanf("%d", &n);

    //remplissage du tableau :
    for(i=0; i<n; i++)
    {
        printf("Entrez le nom de la ville n %d et son nombre d'habitants :\n", i+1);
        scanf("%s %d", tableau[i].nom, &tableau[i].population);
    }

    //affichage du tableau :
    afficheTableau(tableau, n);
    printf("\n");

    //tri du tableau :
    triTableau(tableau, n);

    //affichage du tableau trié :
    printf("Classement par ordre croissant de population :\n");
    afficheTableau(tableau, n);

    return 0;
}

void afficheTableau(Ville tableau[], int longueurTableau)
{
    int i;

    for(i=0; i<longueurTableau; i++)
    {
        printf("%s a %d habitants\n", tableau[i].nom, tableau[i].population);
    }
}

int calculeLongueurMot(char *mot)
{
    int longueur = 0;
    char caractere = 0;

    do
    {
        caractere = mot[longueur];
        longueur++;
    }
    while(caractere != '\0');
    longueur--;

    return longueur;
}

void enleveRetourLigne(char *mot)
{
    int i = 0;
    char caractere = 0;

    do
    {
        caractere = mot[i];

        if(caractere == '\n')
        {
            mot[i] = '\0';
        }

        i++;
    }
    while(caractere != '\0');
}

void inversionNomVille(char *ville1, char *ville2)
{
    int i, longueurMot1, longueurMot2, n;
    char temp = 0;

    enleveRetourLigne(ville1);
    enleveRetourLigne(ville2);

    longueurMot1 = calculeLongueurMot(ville1);
    longueurMot2 = calculeLongueurMot(ville2);

    if(longueurMot1 <= longueurMot2)
    {
        n = longueurMot2;
    }
    else
    {
        n = longueurMot1;
    }


    for(i=0; i<n; i++)
    {
        temp = ville1[i];
        ville1[i] = ville2[i];
        ville2[i] = temp;
    }
    ville1[longueurMot2] = '\0';
    ville2[longueurMot1] = '\0';
}

void triTableau(Ville tableau[], int longueurTableau)
{
    int i, j, tempPop;

    for(i=0; i<longueurTableau-1; i++)
    {
        for(j=i+1; j<longueurTableau; j++)
        {
            if(tableau[i].population > tableau[j].population)
            {
                tempPop = tableau[i].population;
                tableau[i].population = tableau[j].population;
                tableau[j].population = tempPop;

                inversionNomVille(tableau[i].nom, tableau[j].nom);
            }



        }

    }

}
