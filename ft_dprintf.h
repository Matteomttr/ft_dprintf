#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* Fonctions de conversion et d'affichage (Utilitaires) */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_puthexa_fd(unsigned long long n, int fd, char *base);
void	ft_putptr_fd(void *ptr, int fd);
int		ft_countargs(const char *format, va_list *args);
void	ft_putunbr_fd(unsigned int n, int fd);

/* Fonctions de comptage */
int		ft_ullnbrlen(unsigned long long nb);
int		ft_nbrlen(int nb);
int		ft_unbrlen(unsigned int nb);
size_t	ft_strlen(char *s);
int		ft_ptrlen(void *ptr);

/* Fonction principale */
int		ft_dprintf(const char *format, ...);

#endif
