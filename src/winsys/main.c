#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "window.h"
#include "logger.h"

int main(int argc, char **argv){
	char *c = "teste";
	window_t *w, *w2;
	widget_t *b1;

	b1 = (widget_t*)malloc(sizeof(widget_t));
	gtk_init(&argc, &argv);

	w = createWindow(c);
	showWindow(w);

	c = "teste1";

	w2 = createWindow(c);
	showWindow(w2);

	b1->widget = gtk_button_new_with_label("OK");
	
	addWidget(w, b1);

	gtk_main();

	return 0;
}
