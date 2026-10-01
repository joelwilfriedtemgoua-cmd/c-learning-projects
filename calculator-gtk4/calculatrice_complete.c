#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "disposition/buttons.h"
#include "disposition/display.h"
#include "operations/operations.h"

typedef struct {
    GtkWidget *display;
    Buttons buttons;
    char current_input[256];
    double accumulator;
    char current_operator;
    int new_number;
} CalculatorState;

static void load_css(void) {
    GtkCssProvider *provider = gtk_css_provider_new();
    GError *error = NULL;

    const char *paths[] = {
        "style.css",
        "calculator-gtk4/style.css",
        NULL
    };

    for (int i = 0; paths[i] != NULL; i++) {
        if (g_file_test(paths[i], G_FILE_TEST_EXISTS)) {
            gtk_css_provider_load_from_path(provider, paths[i], &error);
            if (error == NULL) {
                gtk_style_context_add_provider_for_display(
                    gdk_display_get_default(),
                    GTK_STYLE_PROVIDER(provider),
                    GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
                );
                break;
            }
            g_error_free(error);
            error = NULL;
        }
    }

    g_object_unref(provider);
}

static void update_display(CalculatorState *state) {
    if (state->current_input[0] == '\0') {
        display_set_text(state->display, "0");
    } else {
        display_set_text(state->display, state->current_input);
    }
}

static void number_clicked(GtkButton *button, gpointer user_data) {
    CalculatorState *state = (CalculatorState *)user_data;
    const char *label = gtk_button_get_label(button);

    if (state->new_number) {
        strcpy(state->current_input, label);
        state->new_number = 0;
    } else {
        if (strlen(state->current_input) < 255) {
            strcat(state->current_input, label);
        }
    }

    update_display(state);
}

static void decimal_clicked(GtkButton *button, gpointer user_data) {
    (void)button;
    CalculatorState *state = (CalculatorState *)user_data;

    if (state->new_number) {
        strcpy(state->current_input, "0.");
        state->new_number = 0;
    } else if (strchr(state->current_input, '.') == NULL) {
        if (strlen(state->current_input) < 254) {
            strcat(state->current_input, ".");
        }
    }

    update_display(state);
}

static void operator_clicked(GtkButton *button, gpointer user_data) {
    CalculatorState *state = (CalculatorState *)user_data;
    const char *label = gtk_button_get_label(button);
    double value = atof(state->current_input);

    if (state->current_operator != '\0') {
        double result = 0;
        switch (state->current_operator) {
            case '+': result = add(state->accumulator, value); break;
            case '-': result = subtract(state->accumulator, value); break;
            case '*': result = multiply(state->accumulator, value); break;
            case '/': result = divide(state->accumulator, value); break;
            default: result = value; break;
        }
        snprintf(state->current_input, sizeof(state->current_input), "%.10g", result);
    }

    state->accumulator = atof(state->current_input);
    state->current_operator = label[0];
    state->new_number = 1;
    update_display(state);
}

static void equals_clicked(GtkButton *button, gpointer user_data) {
    (void)button;
    CalculatorState *state = (CalculatorState *)user_data;
    double value = atof(state->current_input);
    double result = 0;

    if (state->current_operator != '\0') {
        switch (state->current_operator) {
            case '+': result = add(state->accumulator, value); break;
            case '-': result = subtract(state->accumulator, value); break;
            case '*': result = multiply(state->accumulator, value); break;
            case '/': result = divide(state->accumulator, value); break;
            default: result = value; break;
        }
        snprintf(state->current_input, sizeof(state->current_input), "%.10g", result);
        state->accumulator = result;
        state->current_operator = '\0';
        state->new_number = 1;
        update_display(state);
    }
}

static void clear_clicked(GtkButton *button, gpointer user_data) {
    (void)button;
    CalculatorState *state = (CalculatorState *)user_data;
    strcpy(state->current_input, "0");
    state->accumulator = 0;
    state->current_operator = '\0';
    state->new_number = 1;
    update_display(state);
}

static void delete_clicked(GtkButton *button, gpointer user_data) {
    (void)button;
    CalculatorState *state = (CalculatorState *)user_data;

    if (strlen(state->current_input) > 1) {
        state->current_input[strlen(state->current_input) - 1] = '\0';
    } else {
        strcpy(state->current_input, "0");
        state->new_number = 1;
    }

    update_display(state);
}

static void sqrt_clicked(GtkButton *button, gpointer user_data) {
    (void)button;
    CalculatorState *state = (CalculatorState *)user_data;
    double value = atof(state->current_input);
    double result = square_root(value);
    snprintf(state->current_input, sizeof(state->current_input), "%.10g", result);
    state->accumulator = result;
    state->new_number = 1;
    update_display(state);
}

static void percent_clicked(GtkButton *button, gpointer user_data) {
    (void)button;
    CalculatorState *state = (CalculatorState *)user_data;
    double value = atof(state->current_input);
    double result = percentage(state->accumulator, value);
    snprintf(state->current_input, sizeof(state->current_input), "%.10g", result);
    state->accumulator = result;
    state->new_number = 1;
    update_display(state);
}

static void power_clicked(GtkButton *button, gpointer user_data) {
    (void)button;
    CalculatorState *state = (CalculatorState *)user_data;
    double value = atof(state->current_input);
    double result = power(state->accumulator, value);
    snprintf(state->current_input, sizeof(state->current_input), "%.10g", result);
    state->accumulator = result;
    state->new_number = 1;
    update_display(state);
}

static void activate(GtkApplication *app, gpointer user_data) {
    (void)user_data;

    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculatrice GTK4");
    gtk_window_set_default_size(GTK_WINDOW(window), 420, 560);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
    gtk_widget_set_margin_start(main_box, 15);
    gtk_widget_set_margin_end(main_box, 15);
    gtk_widget_set_margin_top(main_box, 15);
    gtk_widget_set_margin_bottom(main_box, 15);

    CalculatorState state = {
        .display = NULL,
        .current_input = "0",
        .accumulator = 0.0,
        .current_operator = '\0',
        .new_number = 1
    };

    state.display = create_display();
    GtkWidget *buttons_grid = create_buttons_grid(&state.buttons);

    gtk_box_append(GTK_BOX(main_box), state.display);
    gtk_box_append(GTK_BOX(main_box), buttons_grid);

    g_signal_connect(state.buttons.button_0, "clicked", G_CALLBACK(number_clicked), &state);
    g_signal_connect(state.buttons.button_1, "clicked", G_CALLBACK(number_clicked), &state);
    g_signal_connect(state.buttons.button_2, "clicked", G_CALLBACK(number_clicked), &state);
    g_signal_connect(state.buttons.button_3, "clicked", G_CALLBACK(number_clicked), &state);
    g_signal_connect(state.buttons.button_4, "clicked", G_CALLBACK(number_clicked), &state);
    g_signal_connect(state.buttons.button_5, "clicked", G_CALLBACK(number_clicked), &state);
    g_signal_connect(state.buttons.button_6, "clicked", G_CALLBACK(number_clicked), &state);
    g_signal_connect(state.buttons.button_7, "clicked", G_CALLBACK(number_clicked), &state);
    g_signal_connect(state.buttons.button_8, "clicked", G_CALLBACK(number_clicked), &state);
    g_signal_connect(state.buttons.button_9, "clicked", G_CALLBACK(number_clicked), &state);
    g_signal_connect(state.buttons.button_dot, "clicked", G_CALLBACK(decimal_clicked), &state);
    g_signal_connect(state.buttons.button_add, "clicked", G_CALLBACK(operator_clicked), &state);
    g_signal_connect(state.buttons.button_subtract, "clicked", G_CALLBACK(operator_clicked), &state);
    g_signal_connect(state.buttons.button_multiply, "clicked", G_CALLBACK(operator_clicked), &state);
    g_signal_connect(state.buttons.button_divide, "clicked", G_CALLBACK(operator_clicked), &state);
    g_signal_connect(state.buttons.button_equals, "clicked", G_CALLBACK(equals_clicked), &state);
    g_signal_connect(state.buttons.button_clear, "clicked", G_CALLBACK(clear_clicked), &state);
    g_signal_connect(state.buttons.button_delete, "clicked", G_CALLBACK(delete_clicked), &state);
    g_signal_connect(state.buttons.button_sqrt, "clicked", G_CALLBACK(sqrt_clicked), &state);
    g_signal_connect(state.buttons.button_percent, "clicked", G_CALLBACK(percent_clicked), &state);
    g_signal_connect(state.buttons.button_power, "clicked", G_CALLBACK(power_clicked), &state);

    gtk_window_set_child(GTK_WINDOW(window), main_box);
    gtk_widget_show(window);
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("fr.joel.calculator", G_APPLICATION_DEFAULT_FLAGS);
    int status;

    load_css();

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
