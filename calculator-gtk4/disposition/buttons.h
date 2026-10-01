#ifndef BUTTONS_H
#define BUTTONS_H

#include <gtk/gtk.h>

typedef struct {
    GtkWidget *button_0;
    GtkWidget *button_1;
    GtkWidget *button_2;
    GtkWidget *button_3;
    GtkWidget *button_4;
    GtkWidget *button_5;
    GtkWidget *button_6;
    GtkWidget *button_7;
    GtkWidget *button_8;
    GtkWidget *button_9;
    GtkWidget *button_add;
    GtkWidget *button_subtract;
    GtkWidget *button_multiply;
    GtkWidget *button_divide;
    GtkWidget *button_equals;
    GtkWidget *button_clear;
    GtkWidget *button_delete;
    GtkWidget *button_dot;
    GtkWidget *button_percent;
    GtkWidget *button_sqrt;
    GtkWidget *button_power;
} Buttons;

GtkWidget *create_buttons_grid(Buttons *buttons);

#endif
