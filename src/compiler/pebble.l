%{
  #include "compiler/types.h" // Add this line
  #include "compiler/parser.h"
  #include <string.h>
  #include <stdlib.h>
  #include "error_handler/error.h"

  // Track column position for better error reporting
  int yycolumn = 1;

  // This macro is called for each matched pattern
  #define YY_USER_ACTION yycolumn += yyleng;

  int eof_sent = 0;
%}

%option noyywrap
%option yylineno

%%

var           return T_VAR;
if            return T_IF;
display       return T_DISPLAY;
print         return T_PRINT;
repeat        return T_REPEAT;
for           return T_FOR;
while         return T_WHILE;
"{"           return T_LBRACE;
"}"           return T_RBRACE;
else          return T_ELSE;
ask           return T_ASK;
and           return T_AND;
save          return T_SAVE;
as            return T_AS;
input         return T_INPUT;

"="           return T_ASSIGN;
"**"          return T_EXP;
"=="          { return T_EQ; }
"!="          { return T_NEQ; }
">="          { return T_GE; }
"<="          { return T_LE; }
">"           return T_GT;
"<"           return T_LT;
"equal"       { return T_EQ_KEYWORD; }
"not equal"   { return T_NEQ_KEYWORD; }
"greater"     { return T_GT; }
"smaller"     { return T_LT; }
"greater equal" { return T_GE; }
"smaller equal" { return T_LE; }
"+"           return T_PLUS;
"-"           return T_MINUS;
"*"           return T_MULT;
"/"           return T_DIV;
"%"           {
                  type_error(yylineno, 0,
                            "Unsupported operator", "%",
                            "The modulo operator (%) is not supported in Pebble. Use division instead.");
                  return T_MOD;
                }
"("           return T_LPAREN;
")"           return T_RPAREN;

[0-9]+\.[0-9]+      { yylval.str = strdup(yytext); return T_FLOAT; }
[0-9]+              { yylval.num = atoi(yytext); return T_NUMBER; }
\"(\\\"|[^\"])*\"  { yylval.str = strdup(yytext); return T_STRING; }
'([^'\\]|\\[\\'"nrt0])' { yylval.str = strdup(yytext); return T_CHAR; }
true                { yylval.num = 1; return T_BOOL; }
false               { yylval.num = 0; return T_BOOL; }

const          return T_CONST;

function      return T_FUNCTION;
return        return T_RETURN;
","           return T_COMMA;

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = strdup(yytext);
    if (!yylval.str) {
        fprintf(stderr, "Memory allocation failed at line %d\n", yylineno);
        exit(1);
    }
    return T_IDENT;
}

"//".*        { /* skip */ }
"#".*         { /* skip */ }

";"           return T_SEMI;
\n            { yycolumn = 1; return T_EOL; }  // Reset column counter on newline
[ \t\r]+      { /* skip other whitespace */ }

.               {
                  char suggestion[256] = "";

                  // Provide suggestions for common mistakes
                  if (yytext[0] == '$') {
                      snprintf(suggestion, sizeof(suggestion),
                               "Pebble uses 'var' for variable declarations, not '$'");
                  } else if (yytext[0] == '&' && yytext[1] != '&') {
                      snprintf(suggestion, sizeof(suggestion),
                               "Did you mean '&&' (logical AND)?");
                  } else if (yytext[0] == '|' && yytext[1] != '|') {
                      snprintf(suggestion, sizeof(suggestion),
                               "Did you mean '||' (logical OR)?");
                  }

                  // Report the error
                  syntax_error(yylineno, yycolumn - yyleng,
                              "Unknown character", yytext,
                              suggestion[0] ? suggestion : NULL);

                  // Continue lexing
                  return yytext[0];
                }

<<EOF>> {
    if (!eof_sent) {
        eof_sent = 1;
        return T_EOL;
    } else {
        return 0;
    }
}

%%