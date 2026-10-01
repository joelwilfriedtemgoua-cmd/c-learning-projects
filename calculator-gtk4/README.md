# 🧮 Calculatrice GTK4 - Structure Modulaire

## 📁 Arborescence

```
calculator-gtk4/
├── calculatrice_complete.c    # Application principale
├── Makefile                    # Compilation
├── style.css                   # Styling GTK4
│
├── disposition/                # Interface utilisateur
│   ├── buttons.h              # Déclaration des boutons
│   ├── buttons.c              # Implémentation des boutons
│   ├── display.h              # Déclaration de l'affichage
│   └── display.c              # Implémentation de l'affichage
│
├── operations/                 # Opérations mathématiques
│   ├── operations.h           # Déclaration des opérations
│   └── operations.c           # Implémentation des opérations
│
└── README.md                   # Ce fichier
```

---

## 🎯 Fonctionnalités

✅ **Opérations Basiques**
- Addition (+)
- Soustraction (−)
- Multiplication (×)
- Division (÷)
- Modulo (%)

✅ **Opérations Avancées**
- Racine carrée (√)
- Puissance (x^y)
- Pourcentage

✅ **Interface**
- Affichage en temps réel
- Clavier complet (0-9)
- Point décimal
- Boutons Clear (C) et Delete (DEL)
- Styling moderne

---

## 🛠️ Compilation

### **Prérequis**
```bash
sudo apt-get install libgtk-4-dev
```

### **Compiler**
```bash
cd calculator-gtk4
make
```

### **Exécuter**
```bash
./calculatrice
```

### **Nettoyer**
```bash
make clean
```

---

## 📝 Architecture Modulaire

### **disposition/** - Interface Utilisateur
- `buttons.h/c` : Création et gestion des boutons
- `display.h/c` : Affichage et gestion de l'écran

### **operations/** - Logique Mathématique
- `operations.h/c` : Fonctions mathématiques (+, −, ×, ÷, √, etc.)

### **calculatrice_complete.c** - Application
- Gestion des événements
- Liaison des signaux
- Boucle principale GTK4

---

## 🎨 Styling

Le fichier `style.css` contient :
- Thème sombre (noir/gris)
- Boutons colorés (orange pour les opérateurs, vert pour =)
- Affichage vert sur fond noir (style calculatrice)
- Animations au survol

---

## 💡 Améliorations Possibles

- [ ] Historique des calculs
- [ ] Mode notation RPN (Polish Inverse)
- [ ] Thème clair/sombre
- [ ] Sauvegarde de l'état
- [ ] Conversions d'unités
- [ ] Graphiques de fonctions
- [ ] Statistiques
- [ ] Export des résultats

---

## 🚀 Utilisation Rapide

```bash
# Clone le repo
git clone https://github.com/joelwilfriedtemgoua-cmd/c-learning-projects.git

# Va au dossier
cd c-learning-projects/calculator-gtk4

# Compile
make

# Lance
./calculatrice
```

Enjoy! 🎉
