# push_swap

Go to [french version](https://github.com/HdrLucie/push_swap/tree/master#push_quoi-)

## push_what ?
Push Swap is a project implemented in C language that involves sorting a set of X numbers using a limited set of instructions efficiently, with the fewest moves possible. This program uses two stacks (a and b) and a predefined list of instructions to perform the sorting.

### List of instructions 
- sa (swap a): Swap the first two elements at the top of stack a. Does nothing if there's only one or no elements.
- sb (swap b): Swap the first two elements at the top of stack b. Does nothing if there's only one or no elements.
- ss: Perform sa and sb simultaneously.
- pa (push a): Take the first element from the top of stack b and push it onto stack a. Does nothing if stack b is empty.
- pb (push b): Take the first element from the top of stack a and push it onto stack b. Does nothing if stack a is empty.
- ra (rotate a): Shift all elements in stack a up by one position. The first element becomes the last.
- rb (rotate b): Shift all elements in stack b up by one position. The first element becomes the last.
- rr: Perform ra and rb simultaneously.
- rra (reverse rotate a): Shift all elements in stack a down by one position. The last element becomes the first.
- rrb (reverse rotate b): Shift all elements in stack b down by one position. The last element becomes the first.
- rrr: Perform rra and rrb simultaneously.

# Getting Started

## Usage
To run the program and sort the list of numbers, use the following command
```
make
./push_swap N1 N2 N3 [...] Nn
```
To check if the instructions sort the list of numbers, use the following command
```
./push_swap N1 N2 N3 [...] Nn | ./checker [-v] N1 N2 N3 [...] Nn
```
Here's an example of usage with a random number generator
```
ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker -v $ARG
```
Make sure to adjust the range of numbers and the generation method according to your needs.
Feel free to explore the source code to understand its detailed workings.

# Authors
- [Houdeyer Lucie](github.com/HdrLucie)


## push_quoi ?

Push Swap est un projet implémenté en langage C qui consiste à trier un ensemble de X nombres en utilisant un ensemble limité d'instructions de manière efficace, avec le moins de mouvements possibles. Ce programme utilise deux piles (a et b) et une liste prédéfinie d'instructions pour effectuer le tri.

### Liste d'instructions
- sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
- sb (swap b) : Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
- ss : Effectue sa et sb en même temps.
- pa (push a) : Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
- pb (push b) : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
- ra (rotate a) : Décale d’une position vers le haut tous les éléments de la pile a. Le premier élément devient le dernier.
- rb (rotate b) : Décale d’une position vers le haut tous les éléments de la pile b. Le premier élément devient le dernier.
- rr : Effectue ra et rb en même temps.
- rra (reverse rotate a) : Décale d’une position vers le bas tous les éléments de la pile a. Le dernier élément devient le premier.
- rrb (reverse rotate b) : Décale d’une position vers le bas tous les éléments de la pile b. Le dernier élément devient le premier.
- rrr : Effectue rra et rrb en même temps.

# Pour commencer

## Utilisation
Pour exécuter le programme et trier la liste de nombres, utilisez la commande suivante
```
make
./push_swap N1 N2 N3 [...] Nn
```
Pour vérifier que les instructions trient effectivement la liste de nombres, utilisez la commande suivante
```
./push_swap N1 N2 N3 [...] Nn | ./checker [-v] N1 N2 N3 [...] Nn
```
Voici un exemple d'utilisation avec un générateur de nombres aléatoires
```
ARG=`ruby -e "puts (-50..50).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker -v $ARG
```

Assurez-vous de remplacer la plage de nombres et la méthode de génération selon vos besoins.
N'hésitez pas à explorer le code source pour comprendre en détail son fonctionnement.

# Auteur
- [Houdeyer Lucie](github.com/HdrLucie)

