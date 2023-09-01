# ft_printf - 42 School Project

## Résumé

Le projet `ft_printf` vise à recoder la fonction `printf()` de la bibliothèque standard C. Ce projet est une excellente occasion pour apprendre à gérer un nombre variable d'arguments en C. Le code est structuré de manière à être extensible et respecte les normes de la 42 School.

## Technologies Utilisées

- Langage C
- Makefile pour la compilation

## Installation

Pour compiler la bibliothèque, clonez le dépôt et utilisez le Makefile :

```bash
git clone https://github.com/Jeanmichel7/ft_printf.git
cd ft_printf
make
```

Cela générera une bibliothèque statique `libftprintf.a`.

## Règle du projet

- Le projet doit être écrit en C et conformément à la [Norme 42](https://github.com/42School/norminette).
- Aucun comportement inattendu tel que segmentation fault, bus error, etc. ne sera toléré.
- Toute mémoire allouée sur la heap doit être correctement libérée.
- Le Makefile doit contenir les règles standard : `all`, `clean`, `fclean`, et `re`.

## Utilisation

Incluez le fichier d'en-tête dans votre projet C :

```c
#include "ft_printf.h"
```

Liez votre fichier object avec `libftprintf.a` lors de la compilation :

```bash
gcc your_file.c -L. -lftprintf -o your_program
```

### Exemple

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s!", "world");
    return 0;
}
```

## Bonus

Des fonctionnalités bonus sont disponibles, notamment la gestion des drapeaux `-0.`, `#` et `+`. Ces bonus ne seront évalués que si la partie obligatoire du projet est parfaitement réalisée.

---

Pour toute question ou suggestion, n'hésitez pas à ouvrir une issue ou à faire un pull request.
