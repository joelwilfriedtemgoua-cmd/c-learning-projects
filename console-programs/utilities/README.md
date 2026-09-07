# 📝 To-Do List Console

**Français** | [English](#english-version)

## 🎯 Description

Une **application de gestion de tâches en ligne de commande**, complète avec :
- ✅ Ajouter, lister, supprimer des tâches
- ✅ Marquer les tâches comme complétées
- ✅ Sauvegarde automatique dans un fichier
- ✅ Statistiques de progression
- ✅ Interface utilisateur agréable avec des couleurs

---

## 🎓 Concepts Programmation

| Concept | Utilisé | Exemple |
|---------|---------|---------|
| **Structures** | `typedef struct` | Stocker tâche + état |
| **Fichiers** | `fopen()`, `fread()`, `fwrite()` | Sauvegarder `tasks.txt` |
| **Tableaux** | `Task tasks[100]` | Stocker plusieurs tâches |
| **Boucles** | `while`, `for` | Menu et listes |
| **Chaînes** | `fgets()`, `strcpy()` | Descriptions des tâches |
| **Time** | `time.h` | Date de création |

---

## 📋 Fichier de Structure

```
tasks.txt (format simple)
========================
0|Faire les courses
1|Appeler maman
0|Terminer le projet C
1|Faire du sport

Format: done|description
- 0 = pas fait
- 1 = fait (complété)
```

---

## 🚀 Compilation & Exécution

### **Compilation**
```bash
cd console-programs/utilities
gcc todo_list.c -o todo
```

### **Exécution**
```bash
./todo
```

**Premier lancement :**
```
╔════════════════════════════════════╗
║    📝 TO-DO LIST v1.0              ║
║  Gère tes tâches quotidiennes !    ║
╚════════════════════════════════════╝

📝 Nouvelle liste créée !

╔════════════════════════════════════╗
║      QUE VEUX-TU FAIRE ?           ║
╠════════════════════════════════════╣
║ 1. Afficher les tâches             ║
║ 2. Ajouter une tâche               ║
║ 3. Marquer comme faite             ║
║ 4. Supprimer une tâche             ║
║ 5. Voir les statistiques           ║
║ 6. Quitter                         ║
╚════════════════════════════════════╝
Choix (1-6) :
```

---

## 📖 Fonctionnalités Détaillées

### **1️⃣ Afficher les Tâches**
```
Option 1
↓
╔════════════════════════════════════╗
║         MA TO-DO LIST              ║
╚════════════════════════════════════╝

 1. [☐] Faire les courses
 2. [✓] Appeler maman (FAIT)
 3. [☐] Terminer le projet C
```

### **2️⃣ Ajouter une Tâche**
```
Option 2
↓
📝 Nouvelle tâche : Étudier GTK4
✓ Tâche ajoutée !
💾 Sauvegardé !
```

### **3️⃣ Marquer comme Faite**
```
Option 3
↓
[Affiche la liste]
Numéro de tâche à marquer comme faite : 1
✓ Tâche 1 marquée comme faite !
💾 Sauvegardé !
```

### **4️⃣ Supprimer une Tâche**
```
Option 4
↓
[Affiche la liste]
Numéro de tâche à supprimer : 2
✓ Tâche supprimée !
💾 Sauvegardé !
```

### **5️⃣ Voir les Statistiques**
```
Option 5
↓
╔════════════════════════════════════╗
║         STATISTIQUES               ║
╠════════════════════════════════════╣
║ Total      :  3 tâches             ║
║ Complétées :  1 tâches      ✓      ║
║ Restantes  :  2 tâches      ☐      ║
║ Progression:  33%                  ║
╚════════════════════════════════════╝
```

---

## 📂 Fichiers Générés

**Après avoir lancé le programme :**

```
console-programs/utilities/
├── todo_list.c        (source)
├── todo              (exécutable)
└── tasks.txt         (données sauvegardées)
```

**Le fichier `tasks.txt` persiste** → tes tâches restent entre les lancements ! 💾

---

## 🔧 Code Clé

### **Charger les Tâches**
```c
void load_tasks() {
    FILE *file = fopen(TASKS_FILE, "r");
    if (file == NULL) {
        printf("📝 Nouvelle liste créée !\n");
        return;
    }

    task_count = 0;
    while (fscanf(file, "%d|%[^\n]\n", &tasks[task_count].done, 
                  tasks[task_count].description) == 2) {
        task_count++;
    }
    fclose();
}
```

### **Sauvegarder**
```c
void save_tasks() {
    FILE *file = fopen(TASKS_FILE, "w");
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d|%s\n", tasks[i].done, tasks[i].description);
    }
    fclose();
}
```

### **Marquer Comme Fait**
```c
void mark_done() {
    int choice;
    scanf("%d", &choice);
    
    int idx = choice - 1;
    tasks[idx].done = 1;  // ✓ Marquer
    save_tasks();         // 💾 Sauvegarder
}
```

---

## 🎯 Améliorations Possibles

- [ ] Éditer une tâche existante
- [ ] Ajouter des priorités (haute/moyenne/basse)
- [ ] Ajouter des dates d'expiration
- [ ] Catégories de tâches
- [ ] Recherche/filtrage
- [ ] Archiver les tâches complétées
- [ ] Export en JSON/CSV
- [ ] Interface plus colorée

---

## 📊 Exemple Complet d'Utilisation

```bash
$ gcc todo_list.c -o todo
$ ./todo

╔════════════════════════════════════╗
║    📝 TO-DO LIST v1.0              ║
║  Gère tes tâches quotidiennes !    ║
╚════════════════════════════════════╝

📝 Nouvelle liste créée !

[Menu]
Choix (1-6) : 2

📝 Nouvelle tâche : Faire les courses
✓ Tâche ajoutée !
💾 Sauvegardé !

[Menu]
Choix (1-6) : 2

📝 Nouvelle tâche : Appeler maman
✓ Tâche ajoutée !
💾 Sauvegardé !

[Menu]
Choix (1-6) : 1

╔════════════════════════════════════╗
║         MA TO-DO LIST              ║
╚════════════════════════════════════╝

 1. [☐] Faire les courses
 2. [☐] Appeler maman

[Menu]
Choix (1-6) : 3

 1. [☐] Faire les courses
 2. [☐] Appeler maman

Numéro de tâche à marquer comme faite : 1
✓ Tâche 1 marquée comme faite !
💾 Sauvegardé !

[Menu]
Choix (1-6) : 5

╔════════════════════════════════════╗
║         STATISTIQUES               ║
╠════════════════════════════════════╣
║ Total      :  2 tâches             ║
║ Complétées :  1 tâches      ✓      ║
║ Restantes  :  1 tâches      ☐      ║
║ Progression:  50%                  ║
╚════════════════════════════════════╝

[Menu]
Choix (1-6) : 6

Au revoir ! 👋
```

---

---

# English Version

## 🎯 Description

A **command-line task management application**, complete with:
- ✅ Add, list, delete tasks
- ✅ Mark tasks as completed
- ✅ Automatic file saving
- ✅ Progress statistics
- ✅ Nice UI with symbols

---

## 🎓 Programming Concepts

| Concept | Used | Example |
|---------|------|---------|
| **Structures** | `typedef struct` | Store task + state |
| **Files** | `fopen()`, `fread()`, `fwrite()` | Save `tasks.txt` |
| **Arrays** | `Task tasks[100]` | Store multiple tasks |
| **Loops** | `while`, `for` | Menu and lists |
| **Strings** | `fgets()`, `strcpy()` | Task descriptions |
| **Time** | `time.h` | Creation date |

---

## 🚀 Compile & Run

### **Compile**
```bash
cd console-programs/utilities
gcc todo_list.c -o todo
```

### **Run**
```bash
./todo
```

---

## 📖 Features

1. **List Tasks** - Display all tasks with status
2. **Add Task** - Create new task
3. **Mark as Done** - Check completed tasks
4. **Delete Task** - Remove task
5. **Statistics** - Show progress
6. **Quit** - Exit program

---

## 💾 Data Storage

**Format in `tasks.txt`:**
```
0|Faire les courses
1|Appeler maman
0|Terminer le projet C
```

- `0` = not done
- `1` = done

---

## 🎯 Possible Improvements

- [ ] Edit existing task
- [ ] Add priorities (high/medium/low)
- [ ] Add expiration dates
- [ ] Task categories
- [ ] Search/filter
- [ ] Archive completed tasks
- [ ] Export as JSON/CSV
- [ ] More colorful interface
