# 📋 Programmes Console - Apprentissage C

**Français** | [English](#english-version)

## 📂 Vue d'ensemble

Collection de **petits programmes éducatifs** en C, organisés par catégorie pour démontrer les concepts fondamentaux du langage.

---

## 📁 Structure

```
console-programs/
│
├── math/                          # Mathématiques
│   ├── calculatrice.c             # Calculatrice interactive
│   ├── factoriel.c                # Calcul du factoriel
│   ├── imc.c                      # Calcul de l'IMC
│   ├── som_mil.c                  # Somme de 1 à 1000
│   ├── som_prod_moy.c             # Somme, produit, moyenne
│   ├── parite.c                   # Vérifier si pair/impair
│   ├── parite50.c                 # Nombres pairs jusqu'à 50
│   ├── plus_grand.c               # Trouver le plus grand nombre
│   └── tab_moy.c                  # Moyenne d'un tableau
│
├── string/                        # Manipulation de chaînes
│   ├── strcat.c                   # Concaténation de chaînes
│   ├── strcmp.c                   # Comparaison de chaînes
│   ├── strcpy.c                   # Copie de chaîne
│   ├── strchr.c                   # Rechercher un caractère
│   ├── strlen.c                   # Longueur d'une chaîne
│   ├── strlen_info.c              # Longueur et affichage caractères
│   ├── strncmp.c                  # Comparaison partielle
│   ├── strpbrk.c                  # Chercher première consonne
│   ├── strtok.c                   # Découper une chaîne
│   ├── strstr.c                   # Chercher sous-chaîne
│   └── nom_car.c                  # Accéder aux caractères
│
├── conversion/                    # Conversion de types
│   ├── temperature_convert.c      # Celsius ↔ Fahrenheit
│   ├── heure.c                    # Convertir secondes en HH:MM:SS
│   └── atof.c                     # Chaîne vers nombre
│
├── basics/                        # Concepts fondamentaux
│   ├── age.c                      # Classification d'âge
│   ├── a.c                        # Présentation simple
│   ├── carte_visite.c             # Affichage formaté
│   ├── centaines.c                # Boucle (1-100)
│   ├── docs.c                     # Calculs simples
│   ├── permutation_pointeur.c     # Échange avec pointeurs
│   ├── rectangle_ascii.c          # Dessin ASCII
│   ├── semaine.c                  # Switch case
│   ├── var.c                      # Variables
│   └── hello.c                    # Hello World
│
├── arrays/                        # Tableaux
│   ├── tab_compar.c               # Min/Max d'un tableau
│   ├── tab_inverse.c              # Inverser un tableau
│   ├── tab_nbr_fois.c             # Compter les occurrences
│   ├── matrix_som_ligne.c         # Somme par ligne de matrice
│   └── centaines.c                # Afficher 1-100
│
└── README.md                      # Ce fichier
```

---

## 🎯 Chaque Catégorie

### **📐 math/** - Mathématiques

Programmes pour les calculs et opérations mathématiques :

| Fichier | Description | Concepts |
|---------|-------------|----------|
| `calculatrice.c` | Calculatrice interactive (+, -, *, /) | switch, boucles |
| `factoriel.c` | Calcul du factoriel (n!) | boucles, multiplication |
| `imc.c` | Indice de Masse Corporelle | formules, entrées |
| `som_mil.c` | Somme de 1 à 1000 | boucles, accumulation |
| `parite.c` | Vérifier pair/impair | modulo (%), conditions |
| `plus_grand.c` | Max de 3 nombres | comparaisons, conditions |
| `tab_moy.c` | Moyenne d'un tableau | boucles, tableaux |

**Exemple - Factoriel :**
```c
#include <stdio.h>

int main(void)
{
    int n, fact = 1;
    printf("Entrez un nombre : ");
    scanf("%d", &n);
    
    for (int i = 2; i <= n; ++i)
        fact = fact * i;
    
    printf("Factoriel : %d\n", fact);
    return 0;
}
```

---

### **📝 string/** - Manipulation de Chaînes

Programmes utilisant `<string.h>` :

| Fonction | Fichier | Description |
|----------|---------|-------------|
| `strlen()` | `strlen.c` | Longueur d'une chaîne |
| `strcpy()` | `strcpy.c` | Copier une chaîne |
| `strcat()` | `strcat.c` | Concaténer deux chaînes |
| `strcmp()` | `strcmp.c` | Comparer deux chaînes |
| `strchr()` | `strchr.c` | Chercher un caractère |
| `strstr()` | `strstr.c` | Chercher une sous-chaîne |
| `strtok()` | `strtok.c` | Découper une chaîne |

**Exemple - Concaténation :**
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char mot[100] = "bonjour ";
    char phrase[] = "le monde !";
    
    strcat(mot, phrase);
    printf("%s\n", mot);  // Output: bonjour le monde !
    
    return 0;
}
```

---

### **🔄 conversion/** - Conversion de Types

Programmes convertissant entre types :

| Fichier | Conversion | Exemple |
|---------|------------|---------|
| `temperature_convert.c` | Celsius ↔ Fahrenheit | 0°C = 32°F |
| `heure.c` | Secondes → HH:MM:SS | 3661s = 01:01:01 |
| `atof.c` | Chaîne → double | "3.14" = 3.14 |

**Exemple - Température :**
```c
#include <stdio.h>

int main(void)
{
    float c, f;
    printf("Celsius : ");
    scanf("%f", &c);
    
    f = (c * 9/5.0) + 32;
    printf("Fahrenheit : %.2f\n", f);
    
    return 0;
}
```

---

### **✨ basics/** - Concepts Fondamentaux

Les "hello world" et concepts de base :

| Fichier | Concept | Sujet |
|---------|---------|-------|
| `hello.c` | Print simple | `printf()` |
| `a.c` | Présentation | Formatage |
| `var.c` | Variables | Déclaration |
| `age.c` | Conditions | if/else |
| `semaine.c` | Switch case | Sélection multiple |
| `permutation_pointeur.c` | Pointeurs | Passage par référence |

**Exemple - Conditions :**
```c
#include <stdio.h>

int main(void)
{
    int age;
    printf("Âge : ");
    scanf("%d", &age);
    
    if (age < 6)
        printf("Bébé\n");
    else if (age < 12)
        printf("Enfant\n");
    else if (age < 18)
        printf("Ado\n");
    else
        printf("Adulte\n");
    
    return 0;
}
```

---

### **📊 arrays/** - Tableaux

Programmes manipulant les tableaux :

| Fichier | Description |
|---------|-------------|
| `tab_compar.c` | Min et Max d'un tableau |
| `tab_inverse.c` | Inverser l'ordre |
| `tab_moy.c` | Calculer la moyenne |
| `tab_nbr_fois.c` | Compter les occurrences |
| `matrix_som_ligne.c` | Matrice 3x3 |

**Exemple - Min/Max :**
```c
#include <stdio.h>

int main(void)
{
    int tab[10];
    
    for (int i = 0; i < 10; ++i)
        scanf("%d", &tab[i]);
    
    int max = tab[0], min = tab[0];
    for (int i = 1; i < 10; i++) {
        if (tab[i] > max) max = tab[i];
        if (tab[i] < min) min = tab[i];
    }
    
    printf("Max : %d, Min : %d\n", max, min);
    return 0;
}
```

---

## 🚀 Comment Compiler

### **Fichier unique :**
```bash
cd console-programs/math
gcc calculatrice.c -o calculatrice
./calculatrice
```

### **Avec Makefile (dans chaque dossier) :**
```bash
cd console-programs/math
make
make run
```

### **Tout compiler :**
```bash
cd console-programs
for dir in */; do
    cd "$dir"
    gcc *.c -o prog 2>/dev/null && echo "✓ $dir compilé"
    cd ..
done
```

---

## 📚 Concepts Clés par Programme

### **Variables et Types**
- `var.c`, `age.c`, `a.c`

### **Entrées/Sorties**
- `printf()`, `scanf()` dans tous les fichiers

### **Boucles**
- `for` : `centaines.c`, `factoriel.c`
- `while` : optionnel

### **Conditions**
- `if/else` : `age.c`, `parite.c`
- `switch` : `semaine.c`, `calculatrice.c`

### **Pointeurs**
- `permutation_pointeur.c`
- Passage par référence

### **Tableaux**
- Déclaration et accès : `tab_compar.c`
- Matrices : `matrix_som_ligne.c`

### **Chaînes de Caractères**
- `strlen()`, `strcpy()`, etc. dans `string/`

---

## 🎓 Ordre d'Apprentissage Recommandé

1. **basics/** : Commencer ici
   - `hello.c` → `var.c` → `a.c`
   - `age.c` (conditions)
   - `semaine.c` (switch)

2. **math/** : Boucles et calculs
   - `centaines.c` (boucles simples)
   - `parite.c` (modulo)
   - `factoriel.c` (boucles + maths)

3. **arrays/** : Tableaux
   - `tab_compar.c`
   - `tab_inverse.c`

4. **string/** : Chaînes
   - `strlen.c`
   - `strcmp.c`
   - `strtok.c`

5. **conversion/** : Types
   - `temperature_convert.c`
   - `heure.c`

---

## ⚠️ Erreurs Courantes

### ❌ "undefined reference to 'printf'"
- Oublié `#include <stdio.h>`

### ❌ "incompatible types"
- Type de variable incorrect
- `int` vs `float`

### ❌ "segmentation fault"
- Pointeur null ou buffer overflow
- Vérifier les limites des tableaux

---

## 💡 Conseils

✅ Étudie un programme à la fois  
✅ Change les valeurs et observe  
✅ Ajoute des `printf()` pour déboguer  
✅ Utilise `gcc -Wall` pour voir les warnings  
✅ Réécris le code sans regarder  

---

---

# English Version

## 📋 Overview

Collection of **small educational C programs**, organized by category to demonstrate fundamental language concepts.

---

## 📁 Structure

```
console-programs/
│
├── math/                          # Mathematics
│   ├── calculatrice.c             # Interactive calculator
│   ├── factoriel.c                # Factorial calculation
│   ├── imc.c                      # BMI calculation
│   ├── som_mil.c                  # Sum 1 to 1000
│   ├── som_prod_moy.c             # Sum, product, average
│   ├── parite.c                   # Check even/odd
│   ├── parite50.c                 # Even numbers up to 50
│   ├── plus_grand.c               # Find largest number
│   └── tab_moy.c                  # Array average
│
├── string/                        # String Manipulation
│   ├── strcat.c                   # String concatenation
│   ├── strcmp.c                   # String comparison
│   ├── strcpy.c                   # String copy
│   ├── strchr.c                   # Find character
│   ├── strlen.c                   # String length
│   ├── strlen_info.c              # Length and character display
│   ├── strncmp.c                  # Partial comparison
│   ├── strpbrk.c                  # Find first consonant
│   ├── strtok.c                   # Split string
│   ├── strstr.c                   # Find substring
│   └── nom_car.c                  # Access characters
│
├── conversion/                    # Type Conversion
│   ├── temperature_convert.c      # Celsius ↔ Fahrenheit
│   ├── heure.c                    # Convert seconds to HH:MM:SS
│   └── atof.c                     # String to number
│
├── basics/                        # Fundamental Concepts
│   ├── age.c                      # Age classification
│   ├── a.c                        # Simple presentation
│   ├── carte_visite.c             # Formatted output
│   ├── centaines.c                # Loop (1-100)
│   ├── docs.c                     # Simple calculations
│   ├── permutation_pointeur.c     # Swap with pointers
│   ├── rectangle_ascii.c          # ASCII drawing
│   ├── semaine.c                  # Switch case
│   ├── var.c                      # Variables
│   └── hello.c                    # Hello World
│
├── arrays/                        # Arrays
│   ├── tab_compar.c               # Min/Max of array
│   ├── tab_inverse.c              # Reverse array
│   ├── tab_nbr_fois.c             # Count occurrences
│   ├── matrix_som_ligne.c         # Matrix row sum
│   └── centaines.c                # Display 1-100
│
└── README.md                      # This file
```

---

## 🎯 Each Category

### **📐 math/** - Mathematics

Programs for calculations and mathematical operations:

| File | Description | Concepts |
|------|-------------|----------|
| `calculatrice.c` | Interactive calculator (+, -, *, /) | switch, loops |
| `factoriel.c` | Factorial calculation (n!) | loops, multiplication |
| `imc.c` | Body Mass Index | formulas, input |
| `som_mil.c` | Sum 1 to 1000 | loops, accumulation |
| `parite.c` | Check even/odd | modulo (%), conditions |
| `plus_grand.c` | Max of 3 numbers | comparisons, conditions |
| `tab_moy.c` | Array average | loops, arrays |

**Example - Factorial:**
```c
#include <stdio.h>

int main(void)
{
    int n, fact = 1;
    printf("Enter number: ");
    scanf("%d", &n);
    
    for (int i = 2; i <= n; ++i)
        fact = fact * i;
    
    printf("Factorial: %d\n", fact);
    return 0;
}
```

---

## 🚀 How to Compile

### **Single file:**
```bash
cd console-programs/math
gcc calculatrice.c -o calculatrice
./calculatrice
```

### **With Makefile (in each folder):**
```bash
cd console-programs/math
make
make run
```

### **Compile all:**
```bash
cd console-programs
for dir in */; do
    cd "$dir"
    gcc *.c -o prog 2>/dev/null && echo "✓ $dir compiled"
    cd ..
done
```

---

## 🎓 Recommended Learning Order

1. **basics/** : Start here
   - `hello.c` → `var.c` → `a.c`
   - `age.c` (conditions)
   - `semaine.c` (switch)

2. **math/** : Loops and calculations
   - `centaines.c` (simple loops)
   - `parite.c` (modulo)
   - `factoriel.c` (loops + math)

3. **arrays/** : Arrays
   - `tab_compar.c`
   - `tab_inverse.c`

4. **string/** : Strings
   - `strlen.c`
   - `strcmp.c`
   - `strtok.c`

5. **conversion/** : Types
   - `temperature_convert.c`
   - `heure.c`

---

## 💡 Tips

✅ Study one program at a time  
✅ Change values and observe  
✅ Add `printf()` for debugging  
✅ Use `gcc -Wall` to see warnings  
✅ Rewrite code without looking
