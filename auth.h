
#ifndef AUTH_H
#define AUTH_H

/**
 * Function prototype for the login system.
 * This allows main.c to call the login function defined in auth.c.
 * 
 * Returns: 1 if authentication is successful, 0 otherwise.
 */
int login(void);

#endif /* AUTH_H */