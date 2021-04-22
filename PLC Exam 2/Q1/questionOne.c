//for question 1

/* front.c - a lexical analyzer system for simple
 arithmetic expressions */
#include <stdio.h>
#include <ctype.h>

/* Global declarations */
/* Variables */
int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp;

/* Function declarations */
int lookup(char ch);
void addChar(void);
void getChar(void);
void getNonBlank(void);
int lex(void);

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define MOD_OP_OP 25
#define LEFT_PAREN 26
#define RIGHT_PAREN 27
#define FOR_CODE 30
#define IF_CODE 31
#define ELSE_CODE 32
#define WHILE_CODE 33
#define DO_CODE 34
#define INT_CODE 35
#define FLOAT_CODE 36
#define SWITCH_CODE 37
#define LESS_THAN_OP 36
#define LESS_EQUAL_OP 37
#define GREATER_THAN_OP 40
#define GREATER_EQUAL_OP 41
#define IS_EQUAL_OP 42
#define NOT_EQUAL_OP 43

#define OPEN_BLOCK
#define CLOSE_BLOCK

#define OPEN_INDEX
#define CLOSE_INDEX

#define STRING_LITERAL
#define STRING_CLOSE

#define DECLARE_CHAR
#define DECLARE_FLOAT
#define DECLARE_INT
#define DECLARE_STRING
#define DECLARE_VOID

#define DECLARE_PERL_SCALAR
#define DECLARE_PERL_ARRAY
#define DECLARE_PERL_HASH



/******************************************************/
/* main driver */
int main(void) {
	/* Open the input data file and process its contents */
	 if ((in_fp = fopen("front.in", "r")) == NULL)
	 	printf("ERROR - cannot open front.in \n");
	 else {
	 	getChar();
	 do {
	 	lex();
	 } while (nextToken != EOF);
	 }
	 return 0;
}
/******************************************************/
/* lookup - a function to look up operators and
 parentheses and return the token */
int lookup(char ch) {
	 switch (ch) {
		 case '(':
			 addChar();
			 nextToken = LEFT_PAREN;
			 break;
		 case ')':
			 addChar();
			 nextToken = RIGHT_PAREN;
			 break;

         case '{':
			 addChar();
			 nextToken = OPEN_BLOCK;
			 break;
		 case '}':
			 addChar();
			 nextToken = CLOSE_BLOCK;
			 break;

         case '[':
			 addChar();
			 nextToken = OPEN_INDEX;
			 break;
		 case ']':
			 addChar();
			 nextToken = CLOSE_INDEX;
			 break;

        //perl stuff
         case '$':
			 addChar();
			 nextToken = DECLARE_PERL_SCALAR;
			 break;

         case '@':
			 addChar();
			 nextToken = DECLARE_PERL_ARRAY;
			 break;

         case '%':
			 addChar();
			 nextToken = DECLARE_PERL_HASH;
			 break;



		 case '+':
			 addChar();
			 nextToken = ADD_OP;
			 break;

		 case '-':
			 addChar();
			 nextToken = SUB_OP;
			 break;
		 case '*':
			 addChar();
			 nextToken = MULT_OP;
			 break;
		 case '/':
			 addChar();
			 nextToken = DIV_OP;
			 break;

         case '%':
			 addChar();
			 nextToken = MOD_OP;
			 break;

		case '|':
			 addChar();

			 if (charClass == UNKNOWN) {
				 if (nextChar == '|'){
                    addChar();
                    nextToken = OR_OP;
				 }
			 }

			 break;

        case '&':
			 addChar();

			 if (charClass == UNKNOWN) {
				 if (nextChar == '&'){
                    addChar();
                    nextToken = AND_OP;
				 }
			 }

			 break;


         case '>':
			 addChar();
			 nextToken = LESS_THAN_OP;

			 if (charClass == UNKNOWN) {
				 if (nextChar == '='){
                    addChar();
                    nextToken = LESS_EQUAL_OP;
				 }
			 }

			 break;

         case '<':
			 addChar();
			 nextToken = GREATER_THAN_OP;

			 if (charClass == UNKNOWN) {
				 if (nextChar == '='){
                    addChar();
                    nextToken = GREATER_EQUAL_OP;
				 }
			 }

			 break;

         case '=':
			 addChar();
			 nextToken = ASSIGN_OP;

			 if (charClass == UNKNOWN) {
				 if (nextChar == '='){
                    addChar();
                    nextToken = IS_EQUAL_OP;
				 }
			 }

			 break;

         case '!':
			 addChar();
             nextToken = NOT_OP;

			 if (charClass == UNKNOWN) {
				 if (nextChar == '='){
                    addChar();
                    nextToken = NOT_EQUAL_OP;
				 }
			 }

			 break;

         case "\"":
            addChar();

            if (nextToken!= STRING_LITERAL)
                nextToken = STRING_LITERAL;
            else
                nextToken = STRING_CLOSE;

         break;

		 default:
			 addChar();
			 nextToken = EOF;
			 break;
	 }
	 return nextToken;
}

/******************************************************/
/* addChar - a function to add nextChar to lexeme */
void addChar(void) {
	if (lexLen <= 98) {
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = '\0';
	} else
	printf("Error - lexeme is too long \n");
}


/******************************************************/
/* getChar - a function to get the next character of
 input and determine its character class */
void getChar(void) {
	 if ((nextChar = getc(in_fp)) != EOF) {
		 if (isalpha(nextChar))
		 	charClass = LETTER;
		 else if (isdigit(nextChar))
		 	charClass = DIGIT;
		 else
		 	charClass = UNKNOWN;
	 } else
	 	charClass = EOF;
}


/******************************************************/
/* getNonBlank - a function to call getChar until it
 returns a non-whitespace character */
void getNonBlank(void) {
	while (isspace(nextChar))
	getChar();
}

/******************************************************/
/* lex - a simple lexical analyzer for arithmetic
 expressions */
int lex(void) {
	 lexLen = 0;
	 getNonBlank();
	 switch (charClass) {
		/* Identifiers */
		 case LETTER:
			 addChar();
			 getChar();

			 while (charClass == LETTER || charClass == DIGIT) {
				 addChar();
				 getChar();


				 if (nextChar == 'i'){
                    addChar();
                    getChar();

                    if (nextChar == 'n'){
                        addChar();
                        getChar();

                        if (nextChar == 't'){
                            addChar();
                            getChar();

                            nextToken = DECLARE_INT;
                            break;
                        }
                    }
				 }


				 if (nextChar == 's'){
                    addChar();
                    getChar();

                    if (nextChar == 't'){
                        addChar();
                        getChar();

                        if (nextChar == 'r'){
                            addChar();
                            getChar();

                            if (nextChar == 'i'){
                                addChar();
                                getChar();

                                if (nextChar == 'n'){
                                    addChar();
                                    getChar();

                                    if (nextChar == 'g'){
                                        addChar();
                                        getChar();

                                        nextToken = DECLARE_STRING;
                                        break;
                                    }
                                }
                            }
                        }
                    }
				 }

                 if (nextChar == 'c'){
                    addChar();
                    getChar();

                    if (nextChar == 'h'){
                        addChar();
                        getChar();

                        if (nextChar == 'a'){
                            addChar();
                            getChar();

                            if (nextChar == 'r'){
                                addChar();
                                getChar();

                                nextToken = DECLARE_CHAR;
                                break;
                            }
                        }
                    }
				 }

				 if (nextChar == 'f'){
                    addChar();
                    getChar();

                    if (nextChar == 'l'){
                        addChar();
                        getChar();

                        if (nextChar == 'o'){
                            addChar();
                            getChar();

                            if (nextChar == 'a'){
                                addChar();
                                getChar();

                                if (nextChar == 't'){
                                    addChar();
                                    getChar();

                                    nextToken = DECLARE_FLOAT;
                                    break;
                                }
                            }
                        }
                    }
				 }

				 if (nextChar == 'v'){
                    addChar();
                    getChar();

                    if (nextChar == 'o'){
                        addChar();
                        getChar();

                        if (nextChar == 'i'){
                            addChar();
                            getChar();

                            if (nextChar == 'd'){
                                addChar();
                                getChar();

                                nextToken = DECLARE_VOID;
                                break;
                            }
                        }
                    }
				 }
			 }

			 if (nextToken != STRING_LITERAL)
                    nextToken = IDENT;

			 break;
		/* Integer literals */
		 case DIGIT:
			 addChar();
			 getChar();
			 while (charClass == DIGIT) {
				 addChar();
				 getChar();
			 }

			 /* floats */
			 if (charClass == UNKNOWN){
                if (nextChar == '.'){
                    addChar();
                    getChar();

                    while (charClass == DIGIT) {
                        addChar();
                        getChar();
                    }

                    if (nextChar == 'f'){
                        addChar();
                        getChar();
                        nextToken = FLOAT_CODE;
                    }
                }
			 }

			 if (nextToken != FLOAT_CODE && nextToken != STRING_LITERAL)
                nextToken = INT_LIT;

		 	break;
		/* Parentheses and operators */
		 case UNKNOWN:
			 lookup(nextChar);
			 getChar();
			 break;
			/* EOF */
		case EOF:
			 nextToken = EOF;
			 lexeme[0] = 'E';
			 lexeme[1] = 'O';
			 lexeme[2] = 'F';
			 lexeme[3] = '\0';
		 	break;
	 } /* End of switch */
	 printf("Next token is: %d, Next lexeme is %s\n",
	 nextToken, lexeme);
	 return nextToken;
} /* End of function lex */
