#ifndef DISPLAY_H
#define DISPLAY_H

#include <gtk/gtk.h>

GtkWidget *create_display(void);
void display_set_text(GtkWidget *display, const char *text);
const char *display_get_text(GtkWidget *display);
void display_clear(GtkWidget *display);
void display_backspace(GtkWidget *display);

#endif
