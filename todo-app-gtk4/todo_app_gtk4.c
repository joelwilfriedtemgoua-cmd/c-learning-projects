#include <gtk/gtk.h>

#include "todo_manager.h"

#define APP_TITLE "To-Do List GTK4"

typedef struct {
    GtkWidget *entry;
    GtkWidget *task_list;
    GtkWidget *status_label;
    int selected_index;
} AppState;

static void update_status_label(AppState *state) {
    int completed = 0;
    int remaining = 0;

    for (int i = 0; i < task_count; i++) {
        if (tasks[i].done) {
            completed++;
        }
    }

    remaining = task_count - completed;

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Total: %d  |  Terminé: %d  |  Restant: %d",
             task_count, completed, remaining);
    gtk_label_set_text(GTK_LABEL(state->status_label), buffer);
}

static void refresh_task_list(AppState *state) {
    gtk_list_box_remove_all(GTK_LIST_BOX(state->task_list));

    for (int i = 0; i < task_count; i++) {
        GtkWidget *row = gtk_list_box_row_new();
        GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
        GtkWidget *check = gtk_label_new(tasks[i].done ? "[X]" : "[ ]");
        GtkWidget *label = gtk_label_new(tasks[i].description);

        gtk_widget_set_halign(label, GTK_ALIGN_START);
        gtk_widget_set_hexpand(label, TRUE);

        gtk_box_append(GTK_BOX(box), check);
        gtk_box_append(GTK_BOX(box), label);
        gtk_container_add(GTK_CONTAINER(row), box);

        if (state->selected_index == i) {
            gtk_widget_add_css_class(row, "selected-row");
        }

        gtk_list_box_append(GTK_LIST_BOX(state->task_list), row);
    }

    update_status_label(state);
}

static void on_row_selected(GtkListBox *list_box, GtkListBoxRow *row, gpointer user_data) {
    AppState *state = (AppState *)user_data;

    if (row == NULL) {
        state->selected_index = -1;
        return;
    }

    state->selected_index = gtk_list_box_row_get_index(row);
    refresh_task_list(state);
}

static void on_add_clicked(GtkButton *button, gpointer user_data) {
    (void)button;
    AppState *state = (AppState *)user_data;
    const char *text = gtk_editable_get_text(GTK_EDITABLE(state->entry));

    if (text == NULL || text[0] == '\0') {
        return;
    }

    if (add_task(text)) {
        gtk_editable_set_text(GTK_EDITABLE(state->entry), "");
        state->selected_index = -1;
        refresh_task_list(state);
    }
}

static void on_mark_clicked(GtkButton *button, gpointer user_data) {
    (void)button;
    AppState *state = (AppState *)user_data;

    if (state->selected_index < 0 || state->selected_index >= task_count) {
        return;
    }

    mark_task_done(state->selected_index);
    refresh_task_list(state);
}

static void on_delete_clicked(GtkButton *button, gpointer user_data) {
    (void)button;
    AppState *state = (AppState *)user_data;

    if (state->selected_index < 0 || state->selected_index >= task_count) {
        return;
    }

    delete_task_at(state->selected_index);
    state->selected_index = -1;
    refresh_task_list(state);
}

static void on_entry_activate(GtkEntry *entry, gpointer user_data) {
    (void)entry;
    on_add_clicked(NULL, user_data);
}

static void load_css(void) {
    GtkCssProvider *provider = gtk_css_provider_new();
    GError *error = NULL;

    const char *paths[] = {
        "style.css",
        "todo-app-gtk4/style.css",
        NULL
    };

    int loaded = 0;

    for (int i = 0; paths[i] != NULL; i++) {
        if (g_file_test(paths[i], G_FILE_TEST_EXISTS)) {
            gtk_css_provider_load_from_path(provider, paths[i], &error);
            if (error != NULL) {
                g_print("CSS error: %s\n", error->message);
                g_error_free(error);
                error = NULL;
            } else {
                gtk_style_context_add_provider_for_display(
                    gdk_display_get_default(),
                    GTK_STYLE_PROVIDER(provider),
                    GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
                );
                loaded = 1;
                break;
            }
        }
    }

    if (!loaded) {
        g_print("Warning: style.css not found.\n");
    }

    g_object_unref(provider);
}

static void activate(GtkApplication *app, gpointer user_data) {
    (void)user_data;

    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), APP_TITLE);
    gtk_window_set_default_size(GTK_WINDOW(window), 520, 560);
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);

    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
    gtk_widget_set_margin_start(main_box, 18);
    gtk_widget_set_margin_end(main_box, 18);
    gtk_widget_set_margin_top(main_box, 18);
    gtk_widget_set_margin_bottom(main_box, 18);

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Ajouter une tâche...");

    GtkWidget *add_button = gtk_button_new_with_label("Ajouter");
    GtkWidget *mark_button = gtk_button_new_with_label("Marquer comme fait");
    GtkWidget *delete_button = gtk_button_new_with_label("Supprimer");

    GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_append(GTK_BOX(button_box), add_button);
    gtk_box_append(GTK_BOX(button_box), mark_button);
    gtk_box_append(GTK_BOX(button_box), delete_button);

    GtkWidget *task_list = gtk_list_box_new();
    gtk_list_box_set_selection_mode(GTK_LIST_BOX(task_list), GTK_SELECTION_SINGLE);
    gtk_widget_set_vexpand(task_list, TRUE);

    GtkWidget *status_label = gtk_label_new("Total: 0  |  Terminé: 0  |  Restant: 0");

    AppState state = {
        .entry = entry,
        .task_list = task_list,
        .status_label = status_label,
        .selected_index = -1
    };

    load_tasks_from_file();
    refresh_task_list(&state);

    g_signal_connect(add_button, "clicked", G_CALLBACK(on_add_clicked), &state);
    g_signal_connect(mark_button, "clicked", G_CALLBACK(on_mark_clicked), &state);
    g_signal_connect(delete_button, "clicked", G_CALLBACK(on_delete_clicked), &state);
    g_signal_connect(task_list, "row-selected", G_CALLBACK(on_row_selected), &state);
    g_signal_connect(entry, "activate", G_CALLBACK(on_entry_activate), &state);

    gtk_box_append(GTK_BOX(main_box), entry);
    gtk_box_append(GTK_BOX(main_box), button_box);
    gtk_box_append(GTK_BOX(main_box), task_list);
    gtk_box_append(GTK_BOX(main_box), status_label);

    gtk_window_set_child(GTK_WINDOW(window), main_box);
    gtk_widget_show(window);
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("fr.joel.todolist", G_APPLICATION_DEFAULT_FLAGS);
    int status;

    load_css();

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
