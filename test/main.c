
#include <argparse.h>

void f0(struct ap_args * args)
{
	//prt 0
}
void f1(struct ap_args * args)
{
	//print 1
	//print args.a
}
void f2(struct ap_args * args)
{
	//print 2
}

int main(int ac, char** av)
{

	struct ap_parser * parser = ap_create_parser();

	struct ap_subparsers * subparsers = ap_add_subparsers(parser);



	struct ap_parser * parser_0 = ap_add_parser(subparsers, "p0");
	struct ap_parser * parser_1 = ap_add_parser(subparsers, "p1");
	struct ap_parser * parser_2 = ap_add_parser(subparsers, "p2");


	ap_set_defaults(parser_0, "func", f0);
	ap_set_defaults(parser_1, "func", f1);
	ap_set_defaults(parser_2, "func", f2);

	ap_add_argument(parser_1, "-a", "apple",  3 /*nargs=3, required=true*/);

	ap_add_argument(parser_2, "-a", "apple",  1 /*, default="hello"*/);

	ap_add_argument(parser_2, "-b", "banana", 0 /*action='store_true'*/);

	struct ap_args * args = ap_parse_args(parser, ac, av);
	
	ap_call(args, "func", args);

}


