#ifndef __H_WINDOW_H__
#define __H_WINDOW_H__

#include <glib.h>
#include <gtk/gtk.h>



typedef struct geometry_t {
	int width;
	int height;
	int pos_x;
	int pos_y;
}geometry_t;

typedef struct widget_t {
	GtkWidget *widget;
	char *name;
}widget_t;

typedef struct signal_t {
	char *signalName;
	void (*callback)(GtkWidget*, gpointer);
}signal_t;

typedef struct window_t {
	GtkWidget *window;
	char *title;
	geometry_t geometry;
	GList *widgets; /* Widget list */
}window_t;

#endif
