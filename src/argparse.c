#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <linkedlist.h>

#include <argparse.h>


struct ap_parser *		ap_create_parser()
{
	struct ap_parser * parser = (struct ap_parser *)malloc(sizeof(struct ap_parser));
	
	parser->_M_subparsers = (struct linkedlist *)malloc(sizeof(struct linkedlist));

	return parser;
}
struct ap_subparsers *		ap_add_subparsers(
		struct ap_parser * parser)
{
	struct ap_subparsers * subparsers = (struct ap_subparsers *)malloc(sizeof(struct ap_subparsers));
	
	subparsers->_M_parsers = (struct linkedlist *)malloc(sizeof(struct linkedlist));
	
	return subparsers;
}
struct ap_parser *		ap_add_parser(
		struct ap_subparsers * subparsers,
		const char * name)
{
	struct ap_parser * parser = (struct ap_parser *)malloc(sizeof(struct ap_parser));
	
	linkedlist_push_back(subparsers->_M_parsers, (void*)parser);
}
void				ap_set_defaults(
		struct ap_parser * parser,
		const char * name,
		void(*func)(struct ap_args * args))
{
}
void				ap_add_argument(
		struct ap_parser * parser,
		const char * name,
		const char * help,
		int nargs)
{
}
struct ap_args *		ap_parse_args(
		struct ap_parser * parser,
		int ac,
		char ** av)
{
	if(ac > 1) {
		if(strcmp(av[1], "-h") == 0) {
			ap_help(parser, ac, av);
			exit(0);
		}
	}

	return 0;
}
void				ap_call(
		struct ap_args * args_0,
		const char * name,
		struct ap_args * args_1)
{
}
char *			ap_usage(
		struct ap_parser * parser,
		int ac,
		char ** av)
{
	//  usage: test.py [-h] {p0,p1,p2} ...
	
	char * s = (char*)malloc(128);
	
	sprintf(s, "usage: %s [-h]", av[0]);

	return s;
}
void			ap_help(
		struct ap_parser * parser,
		int ac,
		char ** av)
{
	printf("%s\n", ap_usage(parser, ac, av));
}



