#include "./Gestion/gestion.h"

typedef struct
{
    void (*f1)(Data *);
    void (*f2)(Data *);
    void (*f3)(Data *);
    void (*f4)(Data *);
    void (*f5)(Data *);
    void (*f6)(Data *);
    void (*f7)(Data *);
    void (*f8)(Data *);

} Gestion;

void gestion(Data *data, Gestion gestion);

Data init();
Gestion fTempo();
Gestion fAffiche();
Gestion fClavier();
Gestion fClic();
Gestion fRedim();
