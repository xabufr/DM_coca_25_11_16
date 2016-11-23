#include "../graphs/all.h"
#include <stdio.h>
#include <string.h>

int nodeColorToNumber(int node, int color, int nbColors)
{
    return node * nbColors + color + 1;
}

void printUsage() { printf("Usage: ./bin/<version> -C <nbColors>\n"); }

int main(int argc, char* argv[])
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

    int nbSommets = orderG();
    int nbAretes = sizeG();

    /*
   * En tout nous allons avoir:
   * * nbColors * nbSommets variables (nbColors variables par sommets)
   * * nbSommets clauses pour que chaque noeud soit colorié par au moins une
   * couleur
   * * nbArrete * nbColors pour que chaque noeud ai une couleur différente de
   * ses voisins
   */
    printf("p cnf %d %d\n", nbColors * nbSommets,
        nbSommets + nbAretes * nbColors);
    /*
   * Chaque noeud du graphe doit être colorié par au moins une couleur
   */
    for (int node = 0; node < nbSommets; ++node) {
        for (int color = 0; color < nbColors; ++color) {
            printf("%d ", nodeColorToNumber(node, color, nbColors));
        }
        printf("0\n");
    }

    /*
   * Si deux sommets sont liés, ils ne doivent pas avoir la même couleur
   * Donc:
   * -(N1-C1 AND N2-C1)
   *  DONC
   *  (-N1-C1 OR -N2-C1)
   */
    int nbAretesTrouvees = 0;
    for (int node1 = 0; node1 < nbSommets && nbAretesTrouvees != nbAretes;
         ++node1) {
        for (int node2 = node1 + 1;
             node2 < nbSommets && nbAretesTrouvees != nbAretes; ++node2) {
            if (are_adjacent(node1, node2) == 1) {
                ++nbAretesTrouvees;
                for (int i = 0; i < nbColors; ++i) {
                    printf("-%d -%d 0\n", nodeColorToNumber(node1, i, nbColors),
                        nodeColorToNumber(node2, i, nbColors));
                }
            }
        }
    }

    return 0;
}
