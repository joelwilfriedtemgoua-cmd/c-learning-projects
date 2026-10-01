#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_TASK_LEN 256
#define TASKS_FILE "tasks.txt"

// Structure pour une tâche
typedef struct {
    char description[MAX_TASK_LEN];
    int done;  // 0 = pas fait, 1 = fait
    time_t created_at;
} Task;

// Variables globales
Task tasks[MAX_TASKS];
int task_count = 0;

// 📁 FICHIERS
void load_tasks() {
    FILE *file = fopen(TASKS_FILE, "r");
    if (file == NULL) {
        printf("📝 Nouvelle liste créée !\n\n");
        return;
    }

    task_count = 0;
    while (task_count < MAX_TASKS && 
           fscanf(file, "%d|%[^\n]\n", &tasks[task_count].done, tasks[task_count].description) == 2) {
        task_count++;
    }

    fclose(file);
    printf("✓ %d tâche(s) chargée(s)\n\n", task_count);
}

void save_tasks() {
    FILE *file = fopen(TASKS_FILE, "w");
    if (file == NULL) {
        printf("❌ Erreur lors de la sauvegarde !\n");
        return;
    }

    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d|%s\n", tasks[i].done, tasks[i].description);
    }

    fclose(file);
    printf("💾 Sauvegardé !\n\n");
}

// ➕ AJOUTER UNE TÂCHE
void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("❌ Liste complète !\n\n");
        return;
    }

    printf("📝 Nouvelle tâche : ");
    fgets(tasks[task_count].description, MAX_TASK_LEN, stdin);
    
    // Enlever le \n
    tasks[task_count].description[strcspn(tasks[task_count].description, "\n")] = 0;

    if (strlen(tasks[task_count].description) == 0) {
        printf("❌ Tâche vide !\n\n");
        return;
    }

    tasks[task_count].done = 0;
    tasks[task_count].created_at = time(NULL);
    task_count++;

    printf("✓ Tâche ajoutée !\n\n");
    save_tasks();
}

// 📋 AFFICHER LES TÂCHES
void list_tasks() {
    if (task_count == 0) {
        printf("📭 Aucune tâche !\n\n");
        return;
    }

    printf("╔════════════════════════════════════╗\n");
    printf("║         MA TO-DO LIST              ║\n");
    printf("╚════════════════════════════════════╝\n\n");

    for (int i = 0; i < task_count; i++) {
        char *checkbox = tasks[i].done ? "[X]" : "[ ]";
        char *status = tasks[i].done ? " (FAIT)" : "";
        printf("%2d. %s %s%s\n", i + 1, checkbox, tasks[i].description, status);
    }

    printf("\n");
}

// ✅ MARQUER COMME FAIT
void mark_done() {
    list_tasks();

    if (task_count == 0) return;

    printf("Numéro de tâche à marquer comme faite (0 pour annuler) : ");
    int choice;
    scanf("%d", &choice);
    getchar();  // Enlever le \n

    if (choice < 1 || choice > task_count) {
        printf("❌ Choix invalide !\n\n");
        return;
    }

    int idx = choice - 1;
    if (tasks[idx].done) {
        printf("⚠️  Déjà marquée comme faite !\n\n");
    } else {
        tasks[idx].done = 1;
        printf("✓ Tâche %d marquée comme faite !\n\n", choice);
        save_tasks();
    }
}

// ❌ SUPPRIMER UNE TÂCHE
void delete_task() {
    list_tasks();

    if (task_count == 0) return;

    printf("Numéro de tâche à supprimer (0 pour annuler) : ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice < 1 || choice > task_count) {
        printf("❌ Choix invalide !\n\n");
        return;
    }

    int idx = choice - 1;
    for (int i = idx; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;

    printf("✓ Tâche supprimée !\n\n");
    save_tasks();
}

// 📊 STATISTIQUES
void show_stats() {
    int completed = 0;
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].done) completed++;
    }

    int remaining = task_count - completed;
    int percentage = task_count == 0 ? 0 : (completed * 100) / task_count;

    printf("╔════════════════════════════════════╗\n");
    printf("║         STATISTIQUES               ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║ Total      : %2d tâches             ║\n", task_count);
    printf("║ Complétées : %2d tâches      ✓      ║\n", completed);
    printf("║ Restantes  : %2d tâches      [ ]    ║\n", remaining);
    printf("║ Progression: %3d%%                  ║\n", percentage);
    printf("╚════════════════════════════════════╝\n\n");
}

// 🎨 MENU PRINCIPAL
void show_menu() {
    printf("╔════════════════════════════════════╗\n");
    printf("║      QUE VEUX-TU FAIRE ?           ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║ 1. Afficher les tâches             ║\n");
    printf("║ 2. Ajouter une tâche               ║\n");
    printf("║ 3. Marquer comme faite             ║\n");
    printf("║ 4. Supprimer une tâche             ║\n");
    printf("║ 5. Voir les statistiques           ║\n");
    printf("║ 6. Quitter                         ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("Choix (1-6) : ");
}

// 🎯 MAIN
int main(void) {
    printf("\n");
    printf("╔════════════════════════════════════╗\n");
    printf("║    📝 TO-DO LIST v1.0              ║\n");
    printf("║  Gère tes tâches quotidiennes !    ║\n");
    printf("╚════════════════════════════════════╝\n\n");

    load_tasks();

    int running = 1;
    while (running) {
        show_menu();

        int choice;
        scanf("%d", &choice);
        getchar();  // Enlever le \n

        printf("\n");

        switch (choice) {
            case 1:
                list_tasks();
                break;
            case 2:
                add_task();
                break;
            case 3:
                mark_done();
                break;
            case 4:
                delete_task();
                break;
            case 5:
                show_stats();
                break;
            case 6:
                printf("Au revoir ! 👋\n\n");
                running = 0;
                break;
            default:
                printf("❌ Choix invalide !\n\n");
        }
    }

    return 0;
}
