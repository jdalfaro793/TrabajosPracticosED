

typedef int contenedor[MAX];

typedef struct tcola{
                contenedor datos;
                int frente;
                int fin;
                int contador;
};

void iniciar_cola(tcola &q)
{ q.frente=MAX-1; //frente
  q.fin=MAX-1; //final
  q.contador=0;
}

int siguiente(int indice)
{ if (indice==MAX-1)
	return 0;
  else
    return (indice+1);
}

bool cola_llena(tcola q)
{ return q.contador==MAX; //cantidad
}

bool cola_vacia(tcola q)
{ return q.contador==0;
}

void agregar_cola(tcola &q, int nuevo)
{ if (cola_llena(q)==true)
    cout << "cola COMPLETA";
  else
    { q.fin=siguiente(q.fin);
	  q.datos[q.fin]=nuevo;
	  q.contador++;
	}
}

int  quitar_cola(tcola &q)
{int aux;
  if (cola_vacia(q)==true)
    aux=-1;
  else
    { q.frente=siguiente(q.frente);
      aux=q.datos[q.frente];
      q.contador--;
	}
  return(aux);
}

int consultar_primero(tcola q)
{ int consultado;
    if (cola_vacia(q)==true)
        consultado=-1;
    else
        consultado= q.datos[siguiente(q.frente)];
    return(consultado);
}

int  consultar_ultimo(tcola q)
{int consultado;
    if (cola_vacia(q)==true)
        consultado=-1;
    else
        consultado=q.datos[q.fin];
    return(consultado);

}
