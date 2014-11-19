
%{
#include <stdio.h>
#include "y.tab.h"
%}


%%
data			return DATA;
type			return TYPE;
[a-zA-Z_][a-zA-Z0-9_]*    yylval.string=strdup(yytext); return WORD;
\(						return FBRACE;
\)						return SBRACE;
\,						return COMMA;
\{                      return OBRACE;
\}                      return EBRACE;
;                       return SEMICOLON;
\n                      /* ignore EOL */;
[ \t]+                  /* ignore whitespace */;
%%
