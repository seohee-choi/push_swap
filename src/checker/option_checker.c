#include "checker.h"

int    option_check(char **argv, int *option)
{
    int i;

    i = 1;
    while (argv[i][0] == '-')
    {

        if (ft_strcmp("-v", argv[i]) && ft_strcmp("-c", argv[i]) && \
        ft_strcmp("-f", argv[i]))
        {
            print_error();
            return (CH_ERROR);
        }
        else if (ft_strcmp("v", argv[i]))
            *option |= DEBUG_FLAG;
        else if (ft_strcmp("c", argv[i]))
            *option |= COLOR_FLAG;
        else if (ft_strcmp("f", argv[i]))
            *option |= FILE_FLAG;
        i++;
    }
    return (i);
}