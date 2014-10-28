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

/*
 * Add a callback function to a given widget
 */
int addWidgetCallback(widget_t *wd, void (*callback)(GtkWidget*, gpointer),
					  char *signal, void *data) {
	signal_t *s = (signal_t*)malloc(sizeof(signal_t));

	if (!s) {
		YAWM_ERROR("Could not allocate signal struct\n");
		return -ENOMEM;
	}

	s->signalName = signal;
	s->callback = callback;	

	SIGNAL_ADD(wd->signals, s);

	g_signal_connect(wd->widget, signal, G_CALLBACK(callback), data);

	return 0;
}

/*
 * Creates a new window
 */
window_t *createWindow(char *title, WindowType t) {
	window_t *w;

	w = (window_t*)malloc(sizeof(window_t));

	if (!w) {
		errno = -ENOMEM;
		YAWM_ERROR("Error creating window: %s\n", title);
	}

	w->geometry = (geometry_t*)malloc(sizeof(geometry_t));

	if (!w->geometry) {
		errno = -ENOMEM;
		YAWM_ERROR("Erro creating geometry properties for: %s\n", title);
	}

	w->window = gtk_window_new((GtkWindowType)t);
	w->title = title;
	gtk_window_set_title(GTK_WINDOW(w->window), title);

	w->widgets = NULL;

	return w;
}

/*
 * Shows a given window
 */
void showWindow(window_t *w) {
	gtk_widget_show(w->window);
}
