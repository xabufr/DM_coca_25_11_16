#include "all.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSolution(char* line, int nbColors);
void getVertexAndColor(int nbColors, int value, int* vertex, int* color);
void printUsage() { printf("Usage: ./bin/<version> -C <nbColors>\n"); }

int main(int argc, char** argv)
{
    if (argc != 3 || strcmp(argv[1], "-C") != 0) {
        printUsage();
        return 1;
    }

    int nbColors;
    if (sscanf(argv[2], "%d", &nbColors) != 1 || nbColors <= 0) {
        fprintf(stderr, "'%s' is not a valid parameter\n", argv[2]);
        printUsage();
        return 2;
    }

    size_t bufferLenght = 1024;
    int lineLength;
    char* buffer = (char*)malloc(sizeof(char) * bufferLenght);

    while ((lineLength = getline(&buffer, &bufferLenght, stdin)) != -1) {
        if (lineLength > 0 && buffer[0] == 'v') {
            printSolution(buffer, nbColors);
            return 0;
        }
    }
    printf("Graphe non %d-coloriable\n", nbColors);
    return 0;
}

void printSolution(char* line, int nbColors)
{
    //En C++ on aurait pu utiliser std::vector<bool>, qui optimise la taille des tableaux de booléens
    bool** couleursSommets = (bool**)malloc(sizeof(bool*) * orderG());
    for (int i = 0; i < orderG(); ++i) {
        couleursSommets[i] = (bool*)malloc(sizeof(bool) * nbColors);
        for (int j = 0; j < nbColors; ++j) {
            couleursSommets[i][j] = false;
        }
    }

    // On saute les deux premiers caractères
    line = line + sizeof(char) * 2;
    //Pour chaque variable présente dans la chaîne
    for (char* token = strtok(line, " "); token != NULL && token[0] != '0'; token = strtok(NULL, " ")) {
        //Si la variable est à vraie, alors le noeud correspondant est colorié
        if (token[0] != '-') {
            int value = strtol(token, NULL, 10);
            int sommet, couleur;
            getVertexAndColor(nbColors, value, &sommet, &couleur);
            couleursSommets[sommet][couleur] = true;
        }
    }
    for (int i = 0; i < orderG(); ++i) {
        for (int j = 0; j < nbColors; ++j) {
            if (couleursSommets[i][j]) {
                printf("Noeud %5d -> Couleur %d\n", i, j);
                break;
            }
        }
    }
    free(couleursSommets);
}

void getVertexAndColor(int nbColors, int value, int* vertex, int* color)
{
    *vertex = (value - 1) / nbColors;
    *color = (value - 1) - *vertex * nbColors;
}
