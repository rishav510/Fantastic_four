
typedef enum {ID, KEYWORD,  OPERATOR, PUNCTUATOR, NA, CONSTANT} token;


token identify_token(char *token_string);
