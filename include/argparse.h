#ifndef ARGPARSE_H
#define ARGPARSE_H

//#define AP_ARG_POSITIONAL 0
//#define AP_ARG_OPTIONAL   1

struct ap_parser
{
	struct linkedlist *		_M_args;
	struct linkedlist *		_M_subparsers;
};
struct ap_subparsers
{
	struct linkedlist *		_M_parsers;
};
struct ap_args
{
};
struct ap_arg
{
	char const *			_M_name;
	char const *			_M_help;
	int				_M_nargs;
};

struct ap_parser * ap_create_parser();

struct ap_subparsers * ap_add_subparsers(struct ap_parser * parser);

struct ap_parser * ap_add_parser(struct ap_subparsers * subparsers, const char * name);

void ap_set_defaults(struct ap_parser * parser, const char * name, void(*func)(struct ap_args * args));

/**
 * name  name of argument ("-a", "--apple")
 * help  help text
 * nargs number of arguments to except. 0 means 'store_true'. -1 means '+'. -2 means '*'
 */
void ap_add_argument(struct ap_parser * parser, const char * name, const char * help, int nargs);

struct ap_args *		ap_parse_args(struct ap_parser * parser, int ac, char ** av);
void				ap_help(
		struct ap_parser * parser,
		int ac,
		char ** av);
void				ap_call(struct ap_args * args_0, const char * name, struct ap_args * args_1);

#endif

