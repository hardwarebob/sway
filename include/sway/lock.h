#ifndef _SWAY_LOCK_H
#define _SWAY_LOCK_H

#include <stdbool.h>

struct wlr_surface;

void arrange_locks(void);

bool sway_session_lock_has_unlocked_output(void);
bool sway_session_lock_is_surface_on_unlocked_output(struct wlr_surface *surface);

#endif
