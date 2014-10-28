#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "window.h"
#include "logger.h"

static void print_hello(GtkWidget *widget, gpointer data) {
	g_print("Hello world\n");
}

int main(int argc, char **argv){
	char *c = "teste";
	window_t *w, *w2;
	widget_t *b1;

	b1 = (widget_t*)malloc(sizeof(widget_t));
	gtk_init(&argc, &argv);

	w = createWindow(c, TopLevel);

	INIT_GEOMETRY(w->geometry, 800, 600, 0, 0, 1, 1);

	applyWindowGeometry(w);

	showWindow(w);

	c = "teste1";

	b1->widget = gtk_button_new_with_label("OK");
	
	addWidget(w, b1, 1);

	addWidgetCallback(b1, &print_hello, "clicked", NULL);

	gtk_main();

	return 0;
}
