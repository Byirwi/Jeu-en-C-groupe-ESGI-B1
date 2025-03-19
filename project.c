#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_MAX 100

// Structure pour stocker le nom du joueur, son score et ses choix
struct Joueur {
    char nom[TAILLE_MAX];
    int score;
    int choix_total[3]; // Tableau pour stocker le nombre de fois que chaque choix a été fait
};

// Fonction pour choisir le coup de l'ordinateur
int choix_pc (int niveau) {
    if (niveau == 0) { // Facile : Choix aléatoire
        return rand() % 3;
    } else if (niveau == 1) { // Difficile : Stratégie simple
        // ... (Ajoute une logique pour que l'ordinateur apprenne ici)
        return rand() % 3;
    } else {
        return -1; // Valeur d'erreur
    }
}

// Fonction pour choisir le coup d'un joueur
int choix_joueur(const char *nom_joueur) {
    int choix;
    printf("%s, entrez votre choix : ", nom_joueur);
    scanf("%d", &choix);
    return choix;
}

void afficher_menu() {
    printf("Choisissez :\n");
    printf("0 - Pierre\n");
    printf("1 - Papier\n");
    printf("2 - Ciseaux\n");
    printf("3 - Quitter\n");
}

void afficher_resultat(int joueur1, int joueur2) {
    if (joueur1 == joueur2) {
        printf("Égalité !\n");
    } else if ((joueur1 == 0 && joueur2 == 2) || (joueur1 == 1 && joueur2 == 0) || (joueur1 == 2 && joueur2 == 1)) {
        printf("%s gagne !\n", joueur1 == 0 ? "Joueur 1" : "Joueur 2");
    } else {
        printf("%s gagne !\n", joueur2 == 0 ? "Joueur 1" : "Joueur 2");
    }
}

int main() {
    int mode_jeu;
    int niveau_difficulte;
    int choix_joueur1, choix_joueur2, choix_pc_resultat;
    int tours;

    srand(time(NULL)); // Initialiser le générateur de nombres aléatoires

    printf("Choisissez le mode de jeu :\n");
    printf("0 - Joueur contre Joueur\n");
    printf("1 - Joueur contre Ordinateur\n");
    printf("Entrez votre choix : ");
    scanf("%d", &mode_jeu);

    if (mode_jeu == 0) { // Joueur contre Joueur
        struct Joueur joueur1, joueur2; // Déclaration des structures Joueur

        printf("Entrez le nom du Joueur 1 : ");
        scanf("%s", joueur1.nom);
        joueur1.score = 0;
        joueur1.choix_total[0] = 0;
        joueur1.choix_total[1] = 0;
        joueur1.choix_total[2] = 0;

        printf("Entrez le nom du Joueur 2 : ");
        scanf("%s", joueur2.nom);
        joueur2.score = 0;
        joueur2.choix_total[0] = 0;
        joueur2.choix_total[1] = 0;
        joueur2.choix_total[2] = 0;

        printf("Combien de tours voulez-vous jouer ? ");
        scanf("%d", &tours);

        for (int i = 0; i < tours; i++) {
            afficher_menu();

            choix_joueur1 = choix_joueur(joueur1.nom);
            choix_joueur2 = choix_joueur(joueur2.nom);

            if (choix_joueur1 == 3 || choix_joueur2 == 3) {
                printf("Un joueur a quitté le jeu.\n");
                break;
            }

            joueur1.choix_total[choix_joueur1]++;
            joueur2.choix_total[choix_joueur2]++;

            printf("%s a choisi : %d\n", joueur1.nom, choix_joueur1);
            printf("%s a choisi : %d\n", joueur2.nom, choix_joueur2);

            afficher_resultat(choix_joueur1, choix_joueur2);

            // Mise à jour des scores
            if ((choix_joueur1 == 0 && choix_joueur2 == 2) ||
                (choix_joueur1 == 1 && choix_joueur2 == 0) ||
                (choix_joueur1 == 2 && choix_joueur2 == 1)) {
                joueur1.score++;
            } else if (choix_joueur1 != choix_joueur2) {
                joueur2.score++;
            }

            printf("Score actuel - %s : %d, %s : %d\n", joueur1.nom, joueur1.score, joueur2.nom, joueur2.score);
        }

        // Déclaration du gagnant final
        if (joueur1.score > joueur2.score) {
            printf("Félicitations %s, vous avez gagné la partie avec un score de %d contre %d !\n", joueur1.nom, joueur1.score, joueur2.score);
        } else if (joueur1.score < joueur2.score) {
            printf("Félicitations %s, vous avez gagné la partie avec un score de %d contre %d !\n", joueur2.nom, joueur2.score, joueur1.score);
        } else {
            printf("La partie se termine par une égalité !\n");
        }

        // Affichage des statistiques
        printf("\nStatistiques :\n");
        printf("%s :\n", joueur1.nom);
        printf("  - Pourcentage de victoires : %.2f%%\n", (double) joueur1.score / tours * 100);
        printf("  - Pierre : %d\n", joueur1.choix_total[0]);
        printf("  - Papier : %d\n", joueur1.choix_total[1]);
        printf("  - Ciseaux : %d\n", joueur1.choix_total[2]);

        printf("%s :\n", joueur2.nom);
        printf("  - Pourcentage de victoires : %.2f%%\n", (double) joueur2.score / tours * 100);
        printf("  - Pierre : %d\n", joueur2.choix_total[0]);
        printf("  - Papier : %d\n", joueur2.choix_total[1]);
        printf("  - Ciseaux : %d\n", joueur2.choix_total[2]);

    } else if (mode_jeu == 1) { // Joueur contre Ordinateur
        struct Joueur joueur; // Déclaration de la structure Joueur

        printf("Entrez votre nom : ");
        scanf("%s", joueur.nom); // Saisir le nom du joueur
        joueur.score = 0; // Initialiser le score du joueur à 0

        printf("Choisissez un niveau de difficulté :\n");
        printf("0 - Facile\n");
        printf("1 - Difficile\n");
        printf("Entrez votre choix : ");
        scanf("%d", &niveau_difficulte);

        printf("Combien de tours voulez-vous jouer ? ");
        scanf("%d", &tours);

        for (int i = 0; i < tours; i++) {
            afficher_menu();
            printf("Entrez votre choix : ");
            scanf("%d", &choix_joueur1);

            if (choix_joueur1 == 3) {
                printf("Vous avez quitté le jeu.\n");
                break;
            }

            choix_pc_resultat = choix_pc(niveau_difficulte); // Choisir le coup de l'ordinateur

            if (choix_pc_resultat == -1) {
                printf("Niveau de difficulté incorrect.\n");
                return 1; // Arrêter le programme
            }

            printf("Vous avez choisi : %d\n", choix_joueur1);
            printf("L'ordinateur a choisi : %d\n", choix_pc_resultat);

            afficher_resultat(choix_joueur1, choix_pc_resultat);

            // Mise à jour des scores
            if ((choix_joueur1 == 0 && choix_pc_resultat == 2) ||
                (choix_joueur1 == 1 && choix_pc_resultat == 0) ||
                (choix_joueur1 == 2 && choix_pc_resultat == 1)) {
                joueur.score++; // Incrémenter le score du joueur
            } else if (choix_joueur1 != choix_pc_resultat) {
                // Le score de l'ordinateur n'est pas nécessaire ici, car il est implicite
            }

            printf("Score actuel - %s : %d, Ordinateur : %d\n", joueur.nom, joueur.score, tours - joueur.score);
        }

        // Déclaration du gagnant final
        if (joueur.score > tours - joueur.score) {
            printf("Félicitations %s, vous avez gagné la partie avec un score de %d contre %d !\n", joueur.nom, joueur.score, tours - joueur.score);
        } else if (joueur.score < tours - joueur.score) {
            printf("L'ordinateur a gagné la partie avec un score de %d contre %d !\n", tours - joueur.score, joueur.score);
        } else {
            printf("La partie se termine par une égalité !\n");
        }
    } else {
        printf("Mode de jeu incorrect.\n");
        return 1; // Arrêter le programme
    }

    return 0;
}



