#include <argparse.h>

struct ap_parser * ap_create_parser()
{
}

struct ap_subparsers * ap_add_subparsers(struct ap_parser * parser)
{
}

struct ap_parser * ap_add_parser(struct ap_subparsers * subparsers, const char * name)
{
}

void ap_set_defaults(struct ap_parser * parser, const char * name, void(*func)(struct ap_args * args))
{
}

void ap_add_argument(struct ap_parser * parser, const char * name, const char * help, int nargs)
{
}

struct ap_args * ap_parse_args(struct ap_parser * parser, int ac, char ** av)
{
}

void ap_call(struct ap_args * args_0, const char * name, struct ap_args * args_1)
{
}

