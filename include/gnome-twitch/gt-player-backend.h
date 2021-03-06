/*
 *  This file is part of GNOME Twitch - 'Enjoy Twitch on your GNU/Linux desktop'
 *  Copyright © 2017 Vincent Szolnoky <vinszent@vinszent.com>
 *
 *  GNOME Twitch is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GNOME Twitch is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GNOME Twitch. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GT_PLAYER_BACKEND_H
#define GT_PLAYER_BACKEND_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

GType gt_player_backend_state_get_type();

#define GT_TYPE_PLAYER_BACKEND_STATE (gt_player_backend_state_get_type())

/**
 * GtPlayerBackendState:
 * @GT_PLAYER_BACKEND_STATE_PLAYING: Currently playing
 * @GT_PLAYER_BACKEND_STATE_PAUSED: Currently paused
 * @GT_PLAYER_BACKEND_STATE_STOPPED: Currently stopped
 * @GT_PLAYER_BACKEND_STATE_BUFFERING: Currently buffering
 * @GT_PLAYER_BACKEND_STATE_LOADING: Currently loading or doing some other miscellaneous work
 *
 * The different states that a player backend can be in.
 */
typedef enum
{
    GT_PLAYER_BACKEND_STATE_PLAYING,
    GT_PLAYER_BACKEND_STATE_PAUSED,
    GT_PLAYER_BACKEND_STATE_STOPPED,
    GT_PLAYER_BACKEND_STATE_BUFFERING,
    GT_PLAYER_BACKEND_STATE_LOADING,
} GtPlayerBackendState;

#define GT_TYPE_PLAYER_BACKEND (gt_player_backend_get_type())

G_DECLARE_INTERFACE(GtPlayerBackend, gt_player_backend, GT, PLAYER_BACKEND, GObject)

struct _GtPlayerBackendInterface
{
    GTypeInterface parent_iface;

    GtkWidget* (*get_widget) (GtPlayerBackend* backend);
    void (*play) (GtPlayerBackend* backend);
    void (*pause) (GtPlayerBackend* backend);
    void (*stop) (GtPlayerBackend* backend);
    void (*set_uri) (GtPlayerBackend* backend, const gchar* uri);
    void (*set_position) (GtPlayerBackend* backend, gint64 position);
};

/**
 * gt_player_backend_get_widget
 *
 * Returns: (transfer none): The Gtk Widget
 *
 * Returns a Gtk.Widget that presents the player to the user
 */
GtkWidget* gt_player_backend_get_widget(GtPlayerBackend* backend);

/* TODO: Doc strings */
void gt_player_backend_play(GtPlayerBackend* backend);
void gt_player_backend_pause(GtPlayerBackend* backend);
void gt_player_backend_stop(GtPlayerBackend* backend);
void gt_player_backend_set_uri(GtPlayerBackend* backend, const gchar* uri);
void gt_player_backend_set_position(GtPlayerBackend* backend, gint64 position);
GtPlayerBackendState gt_player_backend_get_state(GtPlayerBackend* backend);

G_END_DECLS

#endif
