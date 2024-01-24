#include <stdio.h>


int taille = 0;
int codes[100];
int quantities[100];


void ajouter(int code, int quantity) {
    int i;

    for (i = 0; i < taille; i++) {
        if (codes[i] == code) {
            quantities[i] += quantity;
            printf("Quantite ajoutee au stock.\n");
            break;
        }
    }

    codes[taille] = code;
    quantities[taille] = quantity;
    taille++;

    printf("Produit ajoute au stock.\n");
}


void supprimer(int code, int quantity) {
    int i;

    for (i = 0; i < taille; i++) {
        if (codes[i] == code) {
            if (quantities[i] >= quantity) {
                quantities[i] -= quantity;
                printf("Quantite retiree du stock.\n");
                break;
            } else {
                printf("Erreur : Quantite a retirer superieure a la quantite en stock.\n");
                break;
            }
        }
    }

    printf("Erreur : Produit non trouvee dans le stock.\n");
}


void afficherStock() {
    int i;

    if (taille == 0)  printf("Le stock est vide.\n");
        
   
    printf("Stock total :\n");
    for (i = 0; i < taille; i++) {
        printf("Code de produit : %d et la quantitee de produit est : %d\n", codes[i], quantities[i]);
    }
}

int main() {
    
    int code, quantitee;
    int choix;

    do {
        printf("Menu :\n");
        printf("1: Ajouter un produit au stock.\n");
        printf("2: Retirer un produit de stck.\n");
        printf("3: Afficher le stock.\n");
        printf("4: Quitter.\n");

        printf("Entrer votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Donner le code de produit : \n");
                scanf("%d", &code);
                printf("Donner la quantitee de produit : \n");
                scanf("%d", &quantitee);
                ajouter(code, quantitee);
                break;
            case 2:
                printf("Donner le code de produit : \n");
                scanf("%d", &code);
                printf("Donner la quantitee a retirer : \n");
                scanf("%d", &quantitee);
                supprimer(code, quantitee);
                break;
            case 3:
                afficherStock();
                break;
            case 4:
                printf("Terminee\n");
                break;
            default:
                printf("Choix invalide\n");
        }
    } while (choix != 4);

    return 0;
}

