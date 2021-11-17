#include "philo.h"

int     main(int ac, char **av)
{
    t_doc   doc;
    if (!(ac > 4 && ac < 7))
    {
        printf("Erreur lors de la saisie des parametres\n");
        return (0);
    }
    doc = parse_doc(av, ac);
    if (doc.nb_philo < 2)
        return (0);
    run(doc);
    //printf("Bye\n");
    return (0);
}
