#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

// int main(void)
// {
// 	char *command = readline("tinyshell > ");
// 	rl_replace_line("this is new", 0);
// 	rl_redisplay();
// 	rl_on_new_line();
// 	add_history(command);
// 	// printf("%s\n", command);
// 	rl_clear_history(); //clear all history before exiting
// 	free(command);
// 	return (0);
// }

// int main()
// {
//     char *line;

//     while ((line = readline(">tinyshell ")) != NULL) {
//         // Replace the line with a new string
//         // rl_replace_line("You entered: ", 1);
//         // rl_point = rl_end; // Move cursor to end of line
//         // rl_message("'%s'\n", line);
//         add_history(line);
// 		if (strcmp(line, "exit") == 0)
// 			break;
// 		if (line == ctrl C)
// 			//display new prompt
//         free(line);
//     }
// 	free(line);
// 	// chdir("..");
// 	// char buf[10000];
// 	// printf("%s\n", getcwd(buf,1000));
//     // return 0;
// }

int main()
{
	// chdir("..");
	// return (0);

	#ifdef PATH_MAX
    	printf("PATH_MAX is defined as %d.\n",PATH_MAX);
	#else
    	printf("PATH_MAX isn't defined on this system.\n");
	#endif /* PATH_MAX */

    return(0);
}


