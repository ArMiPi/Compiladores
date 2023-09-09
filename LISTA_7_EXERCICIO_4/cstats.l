%option noyywrap
%{
    #include <string.h>
    
    // Per file
    int lines = 1;
    int blank_lines = 0;
    int lines_with_comments = 0;
    int nb_nc_lines = 0;
    int semi_colons = 0;
    int prepoc_direct = 0;
    
    // Total across all files
    int total_lines = 0;
    int total_blank_lines = 0;
    int total_lines_with_comments = 0;
    int total_nb_nc_lines = 0;
    int total_semi_colons = 0;
    int total_prepoc_direct = 0;
%}

%%

^[ \t]*\n {++lines; ++blank_lines;}
("//".*\n) {++lines; ++lines_with_comments;}
"/*" {
    int c = input();
    while(1) {
        c = input();

        if(c == EOF) {
            fprintf(stderr, "ERRO: Faltando */\n");
            return 1;
        } else if(c == '\n') {
            ++lines; ++lines_with_comments;
        } else if(c == '*') {
            c = input();

            if(c == '/') {
                ++lines_with_comments;
                break;
            } else if(c == '\n') {
                ++lines; ++lines_with_comments;
            }
        }
    }
}
^("#include"|"#define") {++prepoc_direct; }
\n {++lines;}
";" {++semi_colons;}
<<EOF>> {
    nb_nc_lines = lines - blank_lines - lines_with_comments;
    
    yyterminate();
}
. {}

%%

int main(argc, argv)
int argc;
char **argv;
{
    int i;

    printf(" total    blank lines w/   nb, nc    semi-  prepoc. file\n");
    printf(" lines    lines comments    lines   colons   direct     \n");
    printf("------+--------+--------+--------+--------+--------+----\n");

    /* Ler de stdin */
    if(argc < 2) {
        yylex();
        printf("%6d %8d %8d %8d %8d %8d %s\n", lines, blank_lines, lines_with_comments, nb_nc_lines, semi_colons, prepoc_direct, "total");
        return 0;
    }

    for(i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");

        if(!f) {
            perror(argv[i]);
            return(1);
        }

        yyrestart(f);
        yylex();
        fclose(f);

        printf("%6d %8d %8d %8d %8d %8d %s\n", lines, blank_lines, lines_with_comments, nb_nc_lines, semi_colons, prepoc_direct, argv[i]);

        // Update e reset dos contadores
        total_lines += lines; lines = 1;
        total_blank_lines += blank_lines; blank_lines = 0;
        total_lines_with_comments += lines_with_comments; lines_with_comments = 0;
        total_nb_nc_lines += nb_nc_lines; nb_nc_lines = 0;
        total_semi_colons += semi_colons; semi_colons = 0;
        total_prepoc_direct += prepoc_direct; prepoc_direct = 0;
    }

    /* printar o total se tiver mais de um arquivo */
    if(argc > 1)
        printf("%6d %8d %8d %8d %8d %8d total\n", total_lines, total_blank_lines, total_lines_with_comments, total_nb_nc_lines, total_semi_colons, total_prepoc_direct);

    return 0;
}