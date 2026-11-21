#include "sway/commands.h"
#include "sway/config.h"
#include "util.h"

struct cmd_results *output_cmd_unlocked_while_locked(int argc, char **argv) {
	if (!config->handler_context.output_config) {
		return cmd_results_new(CMD_FAILURE, "Missing output config");
	}
	if (argc == 0) {
		return cmd_results_new(CMD_INVALID,
			"Missing unlocked_while_locked argument");
	}

	config->handler_context.output_config->unlocked_while_locked =
		parse_boolean(argv[0], false) ? 1 : 0;

	config->handler_context.leftovers.argc = argc - 1;
	config->handler_context.leftovers.argv = argv + 1;
	return NULL;
}
