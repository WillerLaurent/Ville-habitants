typedef struct Ville Ville;
struct Ville
{
    char nom[20];
    int population;
};

void afficheTableau(Ville tableau[], int longueurTableau);
void triTableau(Ville tableau[], int longueurTableau);
void inversionNomVille(char *ville1, char *ville2);
void enleveRetourLigne(char *mot);
int calculeLongueurMot(char *mot);





