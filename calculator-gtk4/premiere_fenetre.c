#include <stdio.h> //inclusion de la bibliotheque qui gere les entree/sortie
#include <gtk/gtk.h> //inclusion de la bibliotheque qui gere l'interface graphique
#include <stdlib.h> //inclusion de la bibliotheque qui gere dans mon code les conversions de type
#include <string.h> //inclusion de la bibliotheque qui gere les chaine de caractere
#include "operations.h" //inclusion de mes operations

typedef struct //enregistrement d'un type definis moi meme
{
  GtkWidget *champ; //pointeur vers un gtkwidget(une fenetre notament un champ de saisi);
} etat_calculatrice; //nom du nouveau type

static void clic_pt(GtkWidget *button, gpointer datas)
 /*creation d'un callback
(fonction executer apres un evenement precis) *button est un pointer vers un GtkWidget
 gpointer datas permet d'envoyer les donner vers datas*/
{
  etat_calculatrice *e = datas;
  /*cree un pointer ou sera affecter les donner de datas */

  const char *text_a = gtk_editable_get_text(GTK_EDITABLE(e->champ));
  
  char *last_op = NULL;
  const char *ops = "+-*/";
  for (int i = 0; ops[i] != '\0'; i++)
  {
    char *position = strrchr(text_a, ops[i]);
    if (position != NULL && (last_op == NULL || position > last_op))
      last_op = position;
  }
  const char *start_nb;
  if (last_op != NULL)
    start_nb = last_op + 1;
  else
    start_nb = text_a;
  if (strchr(start_nb, '.') != NULL)
  {
    return;
  }
  char new_text[100];
  strcpy(new_text, text_a);
  strcat(new_text, ".");
  gtk_editable_set_text(GTK_EDITABLE(e->champ), new_text);
}

static void clic_pct(GtkWidget *button, gpointer datas)
{
  etat_calculatrice *e = datas;
  const char *text_a = gtk_editable_get_text(GTK_EDITABLE(e->champ));
  double value = atof(text_a);
  double result = value / 100.0;

  char texte_result[50];
  sprintf(texte_result, "%g", result);
  gtk_editable_set_text(GTK_EDITABLE(e->champ), texte_result);
}
static void clic_ac(GtkWidget *button, gpointer datas)
{
  etat_calculatrice *e = datas;
  gtk_editable_set_text(GTK_EDITABLE(e->champ), "0");
}

static void clic_eg(GtkWidget *button, gpointer datas)
{
  etat_calculatrice *e = datas;
  char expression[100];
  strcpy(expression, gtk_editable_get_text(GTK_EDITABLE(e->champ)));
  char *operateurs = strpbrk(expression, "+-*/");

  while (operateurs != NULL)
  {
    char operateur = *operateurs;
    int long_part1 = operateurs - expression;

    char part1[50];

    strncpy(part1, expression, long_part1);

    part1[long_part1] = '\0';

    char *start_part2 = operateurs + 1;

    char *next_op = strpbrk(start_part2, "+-*/");

    char part2[50];

    if (next_op != NULL)
    {
      int long_part2 = next_op - start_part2;
      strncpy(part2, start_part2, long_part2);
      part2[long_part2] = '\0';
    }
    else
    {
      strcpy(part2, start_part2);
    }

    double a = atof(part1);
    double b = atof(part2);
    double resultat;

    switch (operateur)
    {
    case '+':
      resultat = addition(a, b);
      break;
    case '-':
      resultat = soustraction(a, b);
      break;
    case '*':
      resultat = multiplication(a, b);
      break;
    case '/':
      if (b == 0)
      {
        gtk_editable_set_text(GTK_EDITABLE(e->champ), "Error");
        return;
      }
      resultat = division(a, b);
      break;
    default:
      return;
    }
    char text_result[50];
    sprintf(text_result, "%.2lf", resultat);

    char new_expression[100];
    strcpy(new_expression, text_result);

    if (next_op != NULL)
    {
      strcat(new_expression, next_op);
    }

    strcpy(expression, new_expression);
    operateurs = strpbrk(expression, "+-*/");
  }
  gtk_editable_set_text(GTK_EDITABLE(e->champ), expression);
}

static void clic(GtkWidget *button, gpointer datas)
{
  etat_calculatrice *e = datas;

  const char *btn = gtk_button_get_label(GTK_BUTTON(button));

  const char *text_a = gtk_editable_get_text(GTK_EDITABLE(e->champ));

  int est_operateur = (strlen(btn) == 1 && strchr("+-*/", btn[0]) != NULL);

  if (est_operateur)
  {
    int longueur = strlen(text_a);
    char dernier = text_a[longueur - 1];
    if (strchr("+-*/", dernier) != NULL)
    {
      if (strchr("+-*/", dernier) != NULL)
      {
        char nouveau_text[100];
        strcpy(nouveau_text, text_a);
        nouveau_text[longueur - 1] = btn[0];
        gtk_editable_set_text(GTK_EDITABLE(e->champ), nouveau_text);
        return;
      }
    }
  }

  if (strcmp(text_a, "0") == 0)
  {
    gtk_editable_set_text(GTK_EDITABLE(e->champ), btn);
  }

  else
  {
    char new_text[100];
    strcpy(new_text, text_a);
    strcat(new_text, btn);
    gtk_editable_set_text(GTK_EDITABLE(e->champ), new_text);
  }
}

static void on_insert_text(GtkEditable *editable, const char *text, int length, int *position, gpointer datas)
{
  for (int i = 0; i < length; i++)
  {
    char c = text[i];
    if (strchr("0123456789+-*/.()%", c) == NULL)
    {
      g_signal_stop_emission_by_name(editable, "insert-text");
      return;
    }
  }
}

/*static : precise une fonction utilisable uniquement dans ce fichier C
void : permet de dire que la fonction ne renvoie rien
active : le nom que j'ai choisi pour ma fonction
rappel : un callback est une foction qui s'execute lors de l'enclenchement d'un phenomene
GtkApplication *app est un pointeur vers toutes l'application
*/

static void active(GtkApplication *app, gpointer datas)

{
  GtkWidget *window = gtk_application_window_new(app);
  // gtk_application_window_new(app) : cree une nouvelle fenetre
  gtk_window_set_title(GTK_WINDOW(window), "calc");
  // gtk_window_set_title() : pour donner un titre a une fenetre
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);

  // defini la taille de la fenetre par defaut

  GtkWidget *grid = gtk_grid_new();

  GtkWidget *champ = gtk_entry_new();

  gtk_editable_set_text(GTK_EDITABLE(champ), "0");

  g_object_set(champ, "xalign", 1.0, NULL);

  gtk_widget_add_css_class(champ, "afficheur");

  gtk_entry_set_placeholder_text(GTK_ENTRY(champ), "0");

  GtkEditable *delegue = gtk_editable_get_delegate(GTK_EDITABLE(champ));
  g_signal_connect(delegue, "insert-text", G_CALLBACK(on_insert_text), NULL);

  static etat_calculatrice etat;
  etat.champ = champ;

  GtkWidget *button1 = gtk_button_new_with_label("1");

  g_signal_connect(button1, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button2 = gtk_button_new_with_label("2");

  g_signal_connect(button2, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button3 = gtk_button_new_with_label("3");

  g_signal_connect(button3, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button4 = gtk_button_new_with_label("4");

  g_signal_connect(button4, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button5 = gtk_button_new_with_label("5");

  g_signal_connect(button5, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button6 = gtk_button_new_with_label("6");

  g_signal_connect(button6, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button7 = gtk_button_new_with_label("7");

  g_signal_connect(button7, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button8 = gtk_button_new_with_label("8");

  g_signal_connect(button8, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button9 = gtk_button_new_with_label("9");

  g_signal_connect(button9, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button0 = gtk_button_new_with_label("0");

  g_signal_connect(button0, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button_pt = gtk_button_new_with_label(".");

  g_signal_connect(button_pt, "clicked", G_CALLBACK(clic_pt), &etat);

  GtkWidget *button_ac = gtk_button_new_with_label("AC");

  g_signal_connect(button_ac, "clicked", G_CALLBACK(clic_ac), &etat);

  GtkWidget *button_add = gtk_button_new_with_label("+");

  g_signal_connect(button_add, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button_sous = gtk_button_new_with_label("-");

  g_signal_connect(button_sous, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button_mul = gtk_button_new_with_label("*");

  g_signal_connect(button_mul, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button_div = gtk_button_new_with_label("/");

  g_signal_connect(button_div, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button_pct = gtk_button_new_with_label("%");

  g_signal_connect(button_pct, "clicked", G_CALLBACK(clic_pct), &etat);

  GtkWidget *button_pth1 = gtk_button_new_with_label("(");

  g_signal_connect(button_pth1, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button_pth2 = gtk_button_new_with_label(")");

  g_signal_connect(button_pth2, "clicked", G_CALLBACK(clic), &etat);

  GtkWidget *button_eg = gtk_button_new_with_label("=");

  g_signal_connect(button_eg, "clicked", G_CALLBACK(clic_eg), &etat);

  gtk_grid_set_row_homogeneous(GTK_GRID(grid), true);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), true);

  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);

  gtk_widget_set_hexpand(champ, true);

  gtk_widget_set_hexpand(button0, true);
  gtk_widget_set_vexpand(button0, true);

  gtk_widget_set_hexpand(button1, true);
  gtk_widget_set_vexpand(button1, true);

  gtk_widget_set_hexpand(button2, true);
  gtk_widget_set_vexpand(button2, true);

  gtk_widget_set_hexpand(button3, true);
  gtk_widget_set_vexpand(button3, true);

  gtk_widget_set_hexpand(button4, true);
  gtk_widget_set_vexpand(button4, true);

  gtk_widget_set_hexpand(button5, true);
  gtk_widget_set_vexpand(button5, true);

  gtk_widget_set_hexpand(button6, true);
  gtk_widget_set_vexpand(button6, true);

  gtk_widget_set_hexpand(button7, true);
  gtk_widget_set_vexpand(button7, true);

  gtk_widget_set_hexpand(button8, true);
  gtk_widget_set_vexpand(button8, true);

  gtk_widget_set_hexpand(button9, true);
  gtk_widget_set_vexpand(button9, true);

  gtk_widget_set_hexpand(button_ac, true);
  gtk_widget_set_vexpand(button_ac, true);

  gtk_widget_set_hexpand(button_add, true);
  gtk_widget_set_vexpand(button_add, true);

  gtk_widget_set_hexpand(button_div, true);
  gtk_widget_set_vexpand(button_div, true);

  gtk_widget_set_hexpand(button_eg, true);
  gtk_widget_set_vexpand(button_eg, true);

  gtk_widget_set_hexpand(button_mul, true);
  gtk_widget_set_vexpand(button_mul, true);

  gtk_widget_set_hexpand(button_pct, true);
  gtk_widget_set_vexpand(button_pct, true);

  gtk_widget_set_hexpand(button_pt, true);
  gtk_widget_set_vexpand(button_pt, true);

  gtk_widget_set_hexpand(button_pth1, true);
  gtk_widget_set_vexpand(button_pth1, true);

  gtk_widget_set_hexpand(button_pth2, true);
  gtk_widget_set_vexpand(button_pth2, true);

  gtk_widget_set_hexpand(button_sous, true);
  gtk_widget_set_vexpand(button_sous, true);

  gtk_grid_attach(GTK_GRID(grid), champ, 0, 0, 4, 1);

  gtk_grid_attach(GTK_GRID(grid), button_pth1, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_pth2, 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_pct, 2, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_ac, 3, 1, 1, 1);

  gtk_grid_attach(GTK_GRID(grid), button7, 0, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button8, 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button9, 2, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_div, 3, 2, 1, 1);

  gtk_grid_attach(GTK_GRID(grid), button4, 0, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button5, 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button6, 2, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_mul, 3, 3, 1, 1);

  gtk_grid_attach(GTK_GRID(grid), button1, 0, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button2, 1, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button3, 2, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_sous, 3, 4, 1, 1);

  gtk_grid_attach(GTK_GRID(grid), button0, 0, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_pt, 1, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_eg, 2, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), button_add, 3, 5, 1, 1);

  gtk_window_set_child(GTK_WINDOW(window), grid);

  GtkCssProvider *provider = gtk_css_provider_new();

  gtk_css_provider_load_from_path(provider, "style_fenetre.css");

  gtk_style_context_add_provider_for_display(
      gdk_display_get_default(),
      GTK_STYLE_PROVIDER(provider),
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION

  );

  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{

  GtkApplication *app; // pointeur vers l'objet application
  int status;

  app = gtk_application_new("com.gmail.joel", G_APPLICATION_DEFAULT_FLAGS);
  // gtk_application cree une nouvelle fenetre (l'objet application)
  // com.gmail.joel : l'id de l'application generalement le nom de domaine inverser

  g_signal_connect(app, "activate", G_CALLBACK(active), NULL);
  /*g_signal_connect : permet de declencher une fonction lorsque un signale est produit
   app : c'est l'objet d'ou on attend un evenement
   G_CALLBACK : c'est la fonction qui ce declenche suuite a l'evenement sur app
  */

  status = g_application_run(G_APPLICATION(app), argc, argv); // g_application_run() : demarre la BOUCLE D'EVENEMENTS

  g_object_unref(app);
  return status;
}
