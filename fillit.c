#include "fillit.h"

//int     is_valid_fig(char **line, int len)
//{

//}

int     is_valid(int fd)
{
    char    *line[129];
    int     ret;
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    while ((ret = get_next_line(fd, &(line[i++]))))
        if (ret == -1)
            return (0);
    while (j < i - 2)
    {
        k = 0;
        if (ft_strlen(line[j]) != 4)
            return (0);
        while (k < 4)
        {
            if (line[j][k] != '.' || line[j][j] != '#')
                return (0);
            k++;
        }
    }
    return (1);
    //return (is_valid_fig(line, i - 2));
}

int     main(int argc, char **argv)
{
    int     fd;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (is_valid(fd))
        {
            
        }
        else
            write(1, "error\n", 6);
    }
    else
    {
        
    }
    return (0);
}