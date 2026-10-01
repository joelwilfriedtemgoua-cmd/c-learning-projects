#include "buttons.h"

GtkWidget *create_buttons_grid(Buttons *buttons) {
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);

    buttons->button_clear = gtk_button_new_with_label("C");
    buttons->button_delete = gtk_button_new_with_label("DEL");
    buttons->button_percent = gtk_button_new_with_label("%");
    buttons->button_divide = gtk_button_new_with_label("/");

    gtk_grid_attach(GTK_GRID(grid), buttons->button_clear, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_delete, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_percent, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_divide, 3, 0, 1, 1);

    buttons->button_7 = gtk_button_new_with_label("7");
    buttons->button_8 = gtk_button_new_with_label("8");
    buttons->button_9 = gtk_button_new_with_label("9");
    buttons->button_multiply = gtk_button_new_with_label("*");

    gtk_grid_attach(GTK_GRID(grid), buttons->button_7, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_8, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_9, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_multiply, 3, 1, 1, 1);

    buttons->button_4 = gtk_button_new_with_label("4");
    buttons->button_5 = gtk_button_new_with_label("5");
    buttons->button_6 = gtk_button_new_with_label("6");
    buttons->button_subtract = gtk_button_new_with_label("-");

    gtk_grid_attach(GTK_GRID(grid), buttons->button_4, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_5, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_6, 2, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_subtract, 3, 2, 1, 1);

    buttons->button_1 = gtk_button_new_with_label("1");
    buttons->button_2 = gtk_button_new_with_label("2");
    buttons->button_3 = gtk_button_new_with_label("3");
    buttons->button_add = gtk_button_new_with_label("+");

    gtk_grid_attach(GTK_GRID(grid), buttons->button_1, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_2, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_3, 2, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_add, 3, 3, 1, 1);

    buttons->button_0 = gtk_button_new_with_label("0");
    buttons->button_dot = gtk_button_new_with_label(".");
    buttons->button_power = gtk_button_new_with_label("x^y");
    buttons->button_sqrt = gtk_button_new_with_label("sqrt");

    gtk_grid_attach(GTK_GRID(grid), buttons->button_0, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_dot, 1, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_power, 2, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttons->button_sqrt, 3, 4, 1, 1);

    buttons->button_equals = gtk_button_new_with_label("=");
    gtk_grid_attach(GTK_GRID(grid), buttons->button_equals, 0, 5, 4, 1);

    gtk_widget_add_css_class(buttons->button_clear, "function-button");
    gtk_widget_add_css_class(buttons->button_delete, "function-button");
    gtk_widget_add_css_class(buttons->button_percent, "function-button");
    gtk_widget_add_css_class(buttons->button_divide, "operator-button");
    gtk_widget_add_css_class(buttons->button_multiply, "operator-button");
    gtk_widget_add_css_class(buttons->button_subtract, "operator-button");
    gtk_widget_add_css_class(buttons->button_add, "operator-button");
    gtk_widget_add_css_class(buttons->button_sqrt, "function-button");
    gtk_widget_add_css_class(buttons->button_power, "function-button");
    gtk_widget_add_css_class(buttons->button_equals, "equals-button");
    gtk_widget_add_css_class(buttons->button_dot, "function-button");

    for (int i = 0; i <= 9; i++) {
        GtkWidget *btn = NULL;
        switch (i) {
            case 0: btn = buttons->button_0; break;
            case 1: btn = buttons->button_1; break;
            case 2: btn = buttons->button_2; break;
            case 3: btn = buttons->button_3; break;
            case 4: btn = buttons->button_4; break;
            case 5: btn = buttons->button_5; break;
            case 6: btn = buttons->button_6; break;
            case 7: btn = buttons->button_7; break;
            case 8: btn = buttons->button_8; break;
            case 9: btn = buttons->button_9; break;
        }
        if (btn) {
            gtk_widget_add_css_class(btn, "number-button");
        }
    }

    return grid;
}
