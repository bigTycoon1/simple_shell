#include "shell.c"
int main() {
	    char input[] = "Hello, world! How are you?";
	        const char delimiters[] = " ,!";

		    char *token = _strtok(input, delimiters);
		        while (token != NULL) {
				        printf("Token: %s\n", token);
					        token = _strtok(NULL, delimiters);
						    }

			    return 0;
}
