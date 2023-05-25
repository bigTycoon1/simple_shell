#include "shell.h"
#include <unistd.h>
/**
 * input_buf - input to the buffers chained commands
 * @info: info passed to parameter structur
 * @buf: address of the buffer
 * @len: address of the lenght variable
 *
 * Return: read bytes
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t strt = 0;
	size_t len_t = 0;

	if (!*len) /* if buffer is empty, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		strt = getline(buf, &len_t, stdin);
#else
		strt = _getline(info, buf, &len_t);
#endif
		if (strt > 0)
		{
			if ((*buf)[strt - 1] == '\n')
			{
				(*buf)[strt - 1] = '\0'; /* remove trailing newline */
				strt--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = strt;
				info->cmd_buf = buf;
			}
		}
	}
	return (strt);
}

/**
 * get_input - reads a line of input from the user
 * @info: info to parameter structure
 *
 * Return: read bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t x, y, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		y = x; /* init new iterator to current buf position */
		p = buf + x; /* get pointer for return */

		check_chain(info, buf, &y, x, len);
		while (y < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &y))
				break;
			y++;
		}

		x = y + 1; /* increment past nulled ';'' */
		if (x >= len) /* reached end of buffer? */
		{
			x = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - buffer to be read
 * @info: info parameter structure
 * @buf: buffer
 * @x: size to the buffer
 *
 * Return: stp
 */
ssize_t read_buf(info_t *info, char *buf, size_t *x)
{
	ssize_t stp = 0;

	if (*x)
		return (0);
	stp = read(info->readfd, buf, READ_BUF_SIZE);
	if (stp >= 0)
	*x = stp;
	return (stp);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: info to parameter structure
 * @ptr: address of pointer to buffer, preallocated
 * @length: size of lenght of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - process ctrl-C
 * @sig_num: the signal of an
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
