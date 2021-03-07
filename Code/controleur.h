#include "./Gestion/gestion.h"

typedef struct
{
    void (*f1)(Data * const);
    void (*f2)(Data * const);
    void (*f3)(Data * const);
    void (*f4)(Data * const);
    void (*f5)(Data * const);
    void (*f6)(Data * const);
    void (*f7)(Data * const);
    void (*f8)(Data * const);

} Gestion;

void gestion(Data *data, const Gestion gestion);

Data init();
const Gestion fTempo();
const Gestion fAffiche();
const Gestion fClavier();
const Gestion fClic();
const Gestion fRedim();
