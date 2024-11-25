

typedef int tcola[MAX];  //pos central MAX/2, MAX/2+1, MAX/2-1


void iniciar_cola(tcola &q)
{ q[MAX/2-1]=0; //frente
  q[MAX/2]=0; //final
  q[MAX/2+1]=0; //contador
}

int siguiente(int indice)
{ int i;
  if (indice==MAX-1)
	i=0;
  else
    { i=indice+1;
      if(i==MAX/2-1)//pisa frente
         i=i+3;
    }
  return i;
}

bool cola_llena(tcola q)
{ return q[MAX/2+1]==MAX-3; //cantidad 
}

bool cola_vacia(tcola q)
{ return q[MAX/2+1]==0;
}

void agregar_cola(tcola &q, int nuevo)
{ if (cola_llena(q)==true)
    cout << "cola COMPLETA";
  else
    { q[MAX/2]=siguiente(q[MAX/2]);
	  q[  q[MAX/2]  ]=nuevo;
	  q[MAX/2+1]++;
	}
}

int  quitar_cola(tcola &q)
{int aux;
  if (cola_vacia(q)==true)
    aux=-1;
  else
    { q[MAX/2-1]=siguiente(q[MAX/2-1]);
      aux=q[  q[MAX/2-1]  ];
      q[MAX/2+1]--;
	}
  return(aux);
}

int consultar_primero(tcola q)
{ int consultado;
    if (cola_vacia(q)==true)
        consultado=-1;
    else
        consultado= q[siguiente(q[MAX/2-1])];
    return(consultado);
}

int  consultar_ultimo(tcola q)
{int consultado;
    if (cola_vacia(q)==true)
        consultado=-1;
    else
        consultado=q[q[MAX/2]];
    return(consultado);

}
