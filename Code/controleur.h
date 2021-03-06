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

void gestion(Data *data, const Gestion gestion);

Data init();
const Gestion fTempo();
const Gestion fAffiche();
const Gestion fClavier();
const Gestion fClic();
const Gestion fRedim();
