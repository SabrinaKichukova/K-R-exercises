/*pointer strcat: concatenate t to end of s; s must be big enough */

void strcat(char *s, char *t)
{
while (*s != '\0') /* find end of s */
s++;
while (*t != '\0') /* copy t */
{
    *s = *t;
    s++;
    t++;
}
}
