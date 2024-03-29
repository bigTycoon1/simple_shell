#include "shell.h"
/**
 * cd - change directory in shell
 * @path: path to cd to
 */
void cd(char *path)
{
	char *home = _getenv("HOME");
	char *oldpwd = _getenv("OLDPWD");
	char *pwd = _getenv("PWD");
	char cwd[PATH_MAX];

	if (path == NULL)
	{
		if (chdir(home) == -1)
		{
			perror("cd");
			return;
		}
		setenv("OLDPWD", pwd, 1);
		setenv("PWD", home, 1);
	}
	else if (_strcmp(path, "-") == 0)
	{
		if (oldpwd != NULL)
		{
			if (chdir(oldpwd) == -1)
			{
				perror("cd");
				return;
			}
			setenv("OLDPWD", pwd, 1);
			setenv("PWD", oldpwd, 1);
		}
	}
	else
	{
		if (chdir(path) == -1)
		{
			perror("cd");
			return;
		}
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", pwd, 1);
		setenv("PWD", cwd, 1);
	}
}
