#include "shell.h"

/**
 *_realloc- reallocates mem and reset values to 0
 *@ptr: pointer to previous memory
 *@old_size: previous size
 *@new_size: size to reallocate
 *Return: pointer to new memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *p = NULL;
size_t copy_size;
if (new_size == 0)
{
free(ptr);
return (NULL);
}

if (new_size == old_size)
{
return (ptr);
}

p = malloc(new_size);
if (p == NULL)
{
return (NULL);
}

/* Use the safer 'memcpy' function and avoid 'min' macro */
copy_size = (old_size < new_size) ? old_size : new_size;
memcpy(p, ptr, copy_size);
free(ptr);

return (p);
}

