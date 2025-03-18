#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//test commit
#define TAILLE_MAX 100

void afficher_menu()
{
    printf("Choisissez :\n");
    printf("0 - Pierre\n");
    printf("1 - Papier\n");
    printf("2 - Ciseaux\n");
    printf("3 - Quitter\n");
}

void afficher_resultat(int joueur, int ordinateur)
{
    if (joueur == ordinateur)
    {
        printf("Égalité !\n");
    }
    else if ((joueur == 0 && ordinateur == 2) || (joueur == 1 && ordinateur == 0) || (joueur == 2 && ordinateur == 1))
    {
        printf("Vous gagnez !\n");
    }
    else
    {
        printf("L'ordinateur gagne !\n");
    }
}

int main()
{
    int score_joueur = 0;
    int score_ordinateur = 0;
    int choix_joueur, choix_ordinateur;
    int tours;

    srand(time(NULL)); // Initialiser le générateur de nombres aléatoires

    printf("Combien de tours voulez-vous jouer ? ");
    scanf("%d", &tours);

    for (int i = 0; i < tours; i++)
    {
        afficher_menu();
        printf("Entrez votre choix : ");
        scanf("%d", &choix_joueur);

        if (choix_joueur == 3)
        {
            printf("Vous avez quitté le jeu.\n");
            break;
        }

        choix_ordinateur = rand() % 3; // Choisir un nombre aléatoire entre 0 et 2

        printf("Vous avez choisi : %d\n", choix_joueur);
        printf("L'ordinateur a choisi : %d\n", choix_ordinateur);

        afficher_resultat(choix_joueur, choix_ordinateur);

        // Mise à jour des scores
        if ((choix_joueur == 0 && choix_ordinateur == 2) ||
            (choix_joueur == 1 && choix_ordinateur == 0) ||
            (choix_joueur == 2 && choix_ordinateur == 1))
        {
            score_joueur++;
        }
        else if (choix_joueur != choix_ordinateur)
        {
            score_ordinateur++;
        }

        printf("Score actuel - Vous : %d, Ordinateur : %d\n", score_joueur, score_ordinateur);
    }

    // Déclaration du gagnant final
    if (score_joueur > score_ordinateur)
    {
        printf("Vous avez gagné la partie avec un score de %d contre %d !\n", score_joueur, score_ordinateur);
    }
    else if (score_joueur < score_ordinateur)
    {
        printf("L'ordinateur a gagné la partie avec un score de %d contre %d !\n", score_ordinateur, score_joueur);
    }
    else
    {
        printf("La partie se termine par une égalité !\n");
    }

    return 0;
}
