int     ft_upround(unsigned long long a, unsigned long long b)
{
    int ret;

    ret = (a / b) + ((a % b) ? 1 : 0);
    return (ret);
}