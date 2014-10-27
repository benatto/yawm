#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "window.h"
#include "logger.h"

/*
 * Adds a widget to a window
 */
int addWidget(window_t *w, widget_t *wd, int show) {
	w->widgets = g_list_append(w->widgets, wd->widget);
	gtk_container_add(GTK_CONTAINER(w->window), wd->widget);
	
	if (show)
		gtk_widget_show(wd->widget);
}

//int addWidgetCallback(widget_t *wd, 

/*
 * Creates a new window
 */
window_t *createWindow(char *title) {
	window_t *w;

	w = (window_t*)malloc(sizeof(window_t));

	if (!w) {
		errno = -ENOMEM;
		YAWM_ERROR("Error creating window: %s\n", title);
	}

	w->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	w->title = title;
	gtk_window_set_title(GTK_WINDOW(w->window), title);

	w->widgets = NULL;

	return w;
}

void showWindow(window_t *w) {
	gtk_widget_show(w->window);
}
