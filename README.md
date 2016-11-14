Devoir Maison Calculabilité & Complexité
========================================

Réduction graphe `k-coloriable` vers SAT
----------------------------------------

La réduction se déroule en deux étapes, car le problème de `k-coloriabilité` peut se réduire à ces deux règles:

1.  Chaque nœud doit pouvoir avoir au moins une couleur possible
2.  Deux nœud adjacents ne doivent pas avoir la même couleur.

Pour réaliser cette réduction nous allons avoir besoin de `k` variables par nœuds. Soit la variable `Cik` associée au nœud i, où k est une couleur. Si `Cik` est vraie, alors le nœud i est coloriable par k.

On traduit ainsi la k-coloriabilité du graphe par ceci:

1.  Pour chaque nœud, on doit avoir `(Ci1 OU Ci2 OU ... OU Cik)`. Pour cette étape nous générons donc `nbNœud` clauses.
2.  Pour chaque arête composée de deux nœuds A et B, on doit avoir: `NON(A1 ET B1) ET NON(A2 ET B2) ET ... ET NON(Ak ET Bk)`, Ce qui est équivalent à: `(NON(A1) OU NON(B1)) ET (NON(A2) OU NON(B2)) ET ... ET (NON(Ak) OU NON(Bk))` Où A1 représente le nœud A colorié avec 1. Pour cette étape nous générons donc `nbCouleurs` clauses par arête, soit `nbArêtes * ndCouleurs` clauses au total.

Si on trouve une solution à toutes ces clauses en même temps, alors le graphe est k-coloriable.

Optimisations
-------------

La seule optimisation mise en place pour le moment est que l'expression SAT générée ne contient aucune répétition dans la génération de l'étape 2.

Compilation & execution
-----------------------

Le code se compile à l'aide de CMake
