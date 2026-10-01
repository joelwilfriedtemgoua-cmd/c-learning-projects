#include "display.h"
#include <string.h>

GtkWidget *create_display(void) {
    GtkWidget *display = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(display), "0");
    gtk_entry_set_alignment(GTK_ENTRY(display), 1.0);
    gtk_widget_add_css_class(display, "calculator-display");

    PangoFontDescription *font_desc = pango_font_description_from_string("Monospace 28");
    gtk_widget_override_font(display, font_desc);
    pango_font_description_free(font_desc);

    return display;
}

void display_set_text(GtkWidget *display, const char *text) {
    if (text == NULL) {
        gtk_entry_set_text(GTK_ENTRY(display), "0");
    } else {
        gtk_entry_set_text(GTK_ENTRY(display), text);
    }
}

const char *display_get_text(GtkWidget *display) {
    return gtk_entry_get_text(GTK_ENTRY(display));
}

void display_clear(GtkWidget *display) {
    gtk_entry_set_text(GTK_ENTRY(display), "0");
}

void display_backspace(GtkWidget *display) {
    const char *text = gtk_entry_get_text(GTK_ENTRY(display));
    if (text == NULL || strlen(text) <= 1) {
        gtk_entry_set_text(GTK_ENTRY(display), "0");
        return;
    }

    char *new_text = g_strdup(text);
    new_text[strlen(new_text) - 1] = '\0';
    gtk_entry_set_text(GTK_ENTRY(display), new_text);
    g_free(new_text);
}
