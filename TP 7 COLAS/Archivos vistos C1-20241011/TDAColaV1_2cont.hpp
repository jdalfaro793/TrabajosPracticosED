

typedef char contenedor[MAX];

typedef struct tcola{
                contenedor datos1;
                contenedor datos2;
                int frente;
                int fin;
};

void iniciar_cola(tcola &q)
{ q.frente=MAX-1; //frente
  q.fin=MAX-1; //final
}

int siguiente(int indice)
{ if (indice==2*MAX-1)
	return 0;
  else
    return (indice+1);
}

bool cola_llena(tcola q)
{ return(siguiente(q.fin)==q.frente); //cantidad
}

bool cola_vacia(tcola q)
{ return(q.fin==q.frente);
}

void agregar_cola(tcola &q, char nuevo)
{ if (cola_llena(q)==true)
    cout << "cola COMPLETA";
  else
    { q.fin=siguiente(q.fin);
      if(q.fin<=MAX-1)
        q.datos1[q.fin]=nuevo;
      else
        q.datos2[q.fin-MAX]=nuevo;
	}
}

char  quitar_cola(tcola &q)
{char aux;
  if (cola_vacia(q)==true)
    aux='@';
  else
    { q.frente=siguiente(q.frente);
      if(q.frente>=MAX)
        aux=q.datos2[q.frente-MAX];
      else
        aux=q.datos1[q.frente];
	}
  return(aux);
}

char consultar_primero(tcola q)
{ char consultado;
    if (cola_vacia(q)==true)
        consultado='@';
    else
        if(siguiente(q.frente)>=MAX)
            consultado= q.datos2[siguiente(q.frente)-MAX];
        else
            consultado= q.datos1[siguiente(q.frente)];
    return(consultado);
}

char  consultar_ultimo(tcola q)
{int consultado;
    if (cola_vacia(q)==true)
        consultado='@';
    else
        if(q.fin>=MAX)
          consultado=q.datos2[q.fin-MAX];
        else
            consultado=q.datos1[q.fin];
    return(consultado);

}
