//bicola que prioriza velocidad de proceso
typedef int contenedor[MAX];

typedef struct tbicola
{
    contenedor datos;
    int frente;
    int fin;
};

void iniciar_cola(tbicola &q)
{
    q.frente = MAX - 1; //frente
    q.fin = MAX - 1; //final
}

int siguiente(int indice)
{
    if (indice == MAX - 1)
        return 0;
    else
        return (indice + 1);
}

int anterior(int indice)
{
    if (indice == 0)
        return MAX - 1;
    else
        return (indice - 1);
}

bool cola_llena(tbicola q)
{
    return(siguiente(q.fin) == q.frente); //cantidad
}

bool cola_vacia(tbicola q)
{
    return(q.fin == q.frente);
}

void agregar_cola(tbicola &q, int nuevo)
{
    if (cola_llena(q) == true)
        cout << "cola COMPLETA";
    else
    {
        q.fin = siguiente(q.fin);
        q.datos[q.fin] = nuevo;
    }
}

//modifica la bicola
int  quitar_cola(tbicola &q, int op)
{
    int aux;
    if (cola_vacia(q) == true)
        aux = -1;
    else
    {
        if(op == 1) //quita por el frente
        {
            q.frente = siguiente(q.frente);
            aux = q.datos[q.frente];
        }
        else //quita por el final
        {
            aux = q.datos[q.fin];
            q.fin = anterior(q.fin);
        }
    }
    return(aux);
}

int consultar_primero(tbicola q)
{
    int consultado;
    if (cola_vacia(q) == true)
        consultado = -1;
    else
        consultado = q.datos[siguiente(q.frente)];
    return(consultado);
}

int  consultar_ultimo(tbicola q)
{
    int consultado;
    if (cola_vacia(q) == true)
        consultado = -1;
    else
        consultado = q.datos[q.fin];
    return(consultado);

}
