/*
* The function returns a pointer to a new string, 
* which is a duplicate of the string pointed to by s. 
* The returned pointer can be passed to free(). 
* A null pointer is returned if the new string cannot be created.
*/
char *ft_strdup(const char *s)
{
    size_t  slen;     
    char    *dupptr;
    char    *dupptr_start;

    slen = ft_strlen(s); 
    dupptr = malloc(slen + 1);
    dupptr_start = dupptr;
    if (!dupptr)                 
    {
        return (NULL);
    }    
    ft_strlcpy(dupptr, s, slen + 1); 
    return (dupptr_start);
}