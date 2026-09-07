# 🎨 To-Do List GTK4

**Français** | [English](#english-version)

## 🎯 Description

Une **application de gestion de tâches avec interface graphique GTK4**, moderne et intuitive :
- ✅ Interface graphique avec boutons et champs de texte
- ✅ Liste interactive des tâches
- ✅ Sauvegarde automatique
- ✅ Styling CSS personnalisé
- ✅ Gestion d'événements (callbacks)
- ✅ Architecture modulaire

---

## 🎓 Concepts Programmation

| Concept | Utilisé | Exemple |
|---------|---------|---------|
| **GTK4** | Widgets | GtkWindow, GtkButton, GtkEntry, GtkListBox |
| **Callbacks** | Événements | `g_signal_connect()` |
| **CSS** | Styling | Couleurs, bordures, polices |
| **Fichiers** | Persistance | `tasks.json` ou `tasks.txt` |
| **Modèles** | GTK | ListModel pour afficher les données |
| **Pointeurs** | Gestion d'état | Passer l'état aux callbacks |

---

## 📋 Structure des Fichiers

```
todo-app-gtk4/
├── todo_app_gtk4.c       (application principale)
├── todo_manager.h        (déclarations)
├── todo_manager.c        (implémentation)
├── style.css             (styling GTK4)
├── Makefile              (compilation)
├── README.md             (ce fichier)
└── tasks.json            (données persistantes)
```

---

## 🛠️ Prérequis

### Ubuntu/Debian
```bash
sudo apt-get install gcc make pkg-config libgtk-4-dev
```

### Fedora
```bash
sudo dnf install gcc make pkg-config gtk4-devel
```

### macOS
```bash
brew install gcc make pkg-config gtk4
```

---

## 🚀 Compilation & Exécution

### **Avec Make (Recommandé)**
```bash
cd todo-app-gtk4
make
./todo_app
```

### **Manuel**
```bash
cd todo-app-gtk4
gcc -o todo_app todo_app_gtk4.c todo_manager.c \
    $(pkg-config --cflags --libs gtk4) \
    -Wall -Wextra -std=c99
./todo_app
```

---

## 🖼️ Interface Graphique

```
┌────────────────────────────────────────┐
│  📝 TO-DO LIST                    [X]  │
├────────────────────────────────────────┤
│                                        │
│  ┌──────────────────────────────────┐  │
│  │ ☐ Faire les courses              │  │
│  │ ✓ Appeler maman                  │  │
│  │ ☐ Terminer le projet C           │  │
│  │ ☐ Étudier GTK4                   │  │
│  └──────────────────────────────────┘  │
│                                        │
│  [Nouvelle tâche] ________________     │
│                                        │
│  [Ajouter] [Marquer] [Supprimer] [X]  │
│                                        │
│  Statistiques: 3 restantes, 1 faite   │
└────────────────────────────────────────┘
```

---

## 📖 Fonctionnalités

### **1️⃣ Ajouter une Tâche**
- Écris dans le champ texte
- Clique "Ajouter"
- Apparaît automatiquement dans la liste

### **2️⃣ Afficher les Tâches**
- ListBox interactive
- Symboles ☐/✓ pour le statut
- Défilement automatique

### **3️⃣ Marquer comme Faite**
- Sélectionne une tâche
- Clique "Marquer"
- ☐ devient ✓

### **4️⃣ Supprimer une Tâche**
- Sélectionne une tâche
- Clique "Supprimer"
- Tâche enlever de la liste

### **5️⃣ Statistiques en Temps Réel**
- Mis à jour automatiquement
- Montre total/complétées/restantes
- Pourcentage de progression

---

## 🔧 Code Clé

### **Structure Tâche**
```c
typedef struct {
    char description[256];
    int done;
} Task;
```

### **Charger les Tâches**
```c
void load_tasks_from_file() {
    FILE *file = fopen("tasks.json", "r");
    if (file == NULL) return;
    
    while (fscanf(file, "%d|%[^\n]\n", &tasks[task_count].done,
                  tasks[task_count].description) == 2) {
        task_count++;
    }
    fclose();
}
```

### **Sauvegarder**
```c
void save_tasks_to_file() {
    FILE *file = fopen("tasks.json", "w");
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d|%s\n", tasks[i].done, tasks[i].description);
    }
    fclose();
}
```

### **Callback - Ajouter**
```c
static void on_add_clicked(GtkWidget *button, gpointer user_data) {
    AppState *state = (AppState *)user_data;
    const char *text = gtk_editable_get_text(GTK_EDITABLE(state->entry));
    
    if (strlen(text) == 0) return;
    
    add_task(text);
    gtk_editable_set_text(GTK_EDITABLE(state->entry), "");
    
    update_task_list(state);
    save_tasks_to_file();
}
```

### **Mettre à Jour la ListBox**
```c
static void update_task_list(AppState *state) {
    // Vider la liste
    gtk_list_box_remove_all(GTK_LIST_BOX(state->task_list));
    
    // Remplir avec les tâches
    for (int i = 0; i < task_count; i++) {
        char checkbox = tasks[i].done ? '✓' : '☐';
        char display[300];
        snprintf(display, sizeof(display), "%c %s", checkbox, tasks[i].description);
        
        gtk_list_box_append(GTK_LIST_BOX(state->task_list),
                           gtk_label_new(display));
    }
    
    update_stats(state);
}
```

---

## 🎨 Styling CSS

**`style.css`**
```css
window {
    background: #f5f5f5;
}

button {
    border-radius: 8px;
    padding: 10px 20px;
    background: #007AFF;
    color: white;
    font-weight: bold;
}

button:hover {
    background: #0051D5;
}

entry {
    border-radius: 8px;
    padding: 10px;
    font-size: 16px;
}

listbox {
    background: white;
    border-radius: 8px;
    padding: 10px;
}

.task-item {
    padding: 10px;
    border-bottom: 1px solid #e0e0e0;
}

.task-item:selected {
    background: #e3f2fd;
}

label {
    color: #333;
}

.stats {
    color: #666;
    font-size: 14px;
    padding: 10px;
}
```

---

## 💾 Format de Sauvegarde

**`tasks.json`** (format simple)
```
0|Faire les courses
1|Appeler maman
0|Terminer le projet C
1|Étudier GTK4
```

- `0` = pas fait
- `1` = fait

---

## 🎯 Améliorations Possibles

- [ ] Éditer une tâche existante (double-click)
- [ ] Catégories/Tags
- [ ] Dates de rappel
- [ ] Priorités (haute/moyenne/basse)
- [ ] Recherche/Filtrage
- [ ] Thème sombre
- [ ] Export en CSV
- [ ] Sync avec le cloud
- [ ] Notifications

---

## 📊 Exemple d'Utilisation

```bash
$ cd todo-app-gtk4
$ make
$ ./todo_app

[Interface GTK4 s'ouvre]

# L'utilisateur :
# 1. Tape "Faire les courses"
# 2. Clique "Ajouter"
# 3. Tape "Appeler maman"
# 4. Clique "Ajouter"
# 5. Clique sur "Faire les courses"
# 6. Clique "Marquer"
# 7. Les données sont sauvegardées automatiquement
```

---

## 🔌 Architecture

```
main()
  ↓
app_startup() → Créer interface
  ↓
load_tasks_from_file() → Charger les données
  ↓
update_task_list() → Afficher
  ↓
[Boucles GTK - attendre événements]
  ↓
on_add_clicked() → Ajouter tâche
on_mark_clicked() → Marquer faite
on_delete_clicked() → Supprimer
  ↓
save_tasks_to_file() → Sauvegarder
  ↓
update_task_list() → Mettre à jour affichage
```

---

---

# English Version

## 🎯 Description

A **task management application with GTK4 graphical interface**, modern and intuitive:
- ✅ Graphical interface with buttons and text fields
- ✅ Interactive task list
- ✅ Automatic saving
- ✅ Custom CSS styling
- ✅ Event handling (callbacks)
- ✅ Modular architecture

---

## 🎓 Programming Concepts

| Concept | Used | Example |
|---------|------|---------|
| **GTK4** | Widgets | GtkWindow, GtkButton, GtkEntry, GtkListBox |
| **Callbacks** | Events | `g_signal_connect()` |
| **CSS** | Styling | Colors, borders, fonts |
| **Files** | Persistence | `tasks.json` or `tasks.txt` |
| **Models** | GTK | ListModel for displaying data |
| **Pointers** | State Management | Pass state to callbacks |

---

## 🚀 Compile & Run

### **With Make (Recommended)**
```bash
cd todo-app-gtk4
make
./todo_app
```

### **Manual**
```bash
gcc -o todo_app todo_app_gtk4.c todo_manager.c \
    $(pkg-config --cflags --libs gtk4) \
    -Wall -Wextra -std=c99
./todo_app
```

---

## 📖 Features

1. **Add Task** - Create new task
2. **List Tasks** - View all with status (☐/✓)
3. **Mark as Done** - Check completed
4. **Delete Task** - Remove from list
5. **Statistics** - Show progress in real-time
6. **Persistent Storage** - Save to file

---

## 💾 Data Format

**`tasks.json`**
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
- [ ] Categories/Tags
- [ ] Reminder dates
- [ ] Priorities
- [ ] Search/Filter
- [ ] Dark theme
- [ ] Export to CSV
- [ ] Cloud sync
- [ ] Notifications
