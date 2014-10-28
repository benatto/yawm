#ifndef __H_WINDOW_H__
#define __H_WINDOW_H__

#include <glib.h>
#include <gtk/gtk.h>

#define SIGNAL_ADD(l,s) l = g_list_append(l, s)

#define INIT_GEOMETRY(wd, w, h, pos_x, pos_y, res, modal) \
{ \
	wd->width = w; \
	wd->height = h; \
	wd->pos_x = pos_x; \
	wd->pos_y = pos_y; \
	wd->resizable = res; \
	wd->modal = modal; \
}

#define SET_DEF_WINDOW_SIZE(wd) gtk_window_set_default_size(wd->window, wd->geometry->width, wd->geometry->height)

typedef enum WindowType {
	TopLevel = GTK_WINDOW_TOPLEVEL,
	PopUp = GTK_WINDOW_POPUP
}WindowType;

typedef struct geometry_t {
	int width;
	int height;
	int pos_x;
	int pos_y;
	gboolean resizable;
	gboolean modal;
}geometry_t;

typedef struct widget_t {
	GtkWidget *widget;
	char *name;
	GList *signals;
}widget_t;

typedef struct signal_t {
	char *signalName;
	void (*callback)(GtkWidget*, gpointer);
}signal_t;

typedef struct window_t {
	GtkWidget *window;
	char *title;
	geometry_t *geometry;
	GList *widgets; /* Widget list */
	GList *signals;
}window_t;

window_t *createWindow(char *, WindowType);
void showWindow(window_t *);
int addWidgetCallback(widget_t *, void (*)(GtkWidget*, gpointer),
					  char *, void *);
int addWidget(window_t *w, widget_t *, int); 



#endif
