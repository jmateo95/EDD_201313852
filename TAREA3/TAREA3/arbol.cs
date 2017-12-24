using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TAREA3
{
    

    public class arbol
    {
        public string pre = "";
        public string en = "";
        public string pos = "";
        public class Nodo
        {
            public int valor;
            public Nodo der;
            public Nodo iz;
        }
        public Nodo raiz = null;

        public void insertar(int valor1)
        {
           Nodo nuevo= new Nodo();
            nuevo.valor=valor1;
            nuevo.der=null;
            nuevo.iz=null;
            if(raiz==null){
                raiz=nuevo;
            }
            else
            {
                Nodo ant = null;
                Nodo aux = raiz;
                while(aux!=null){
                    ant=aux;
                    if(valor1<aux.valor){
                        aux = aux.iz;
                        if (aux == null)
                        {
                            ant.iz = nuevo;
                            break;
                        }
                    }else{
                        aux = aux.der;
                        if (aux == null)
                        {
                            ant.der = nuevo;
                            break;
                        }
                    }
                }


            }
        }
        public string preorden(Nodo raiz)
        {
         
            if (raiz != null)
            {
                pre = pre +raiz.valor +", ";
                preorden(raiz.iz);
                preorden(raiz.der);
            }
              return pre;
        }
        public string enorden(Nodo raiz)
        {
            if (raiz != null)
            {
                enorden(raiz.iz);
                en = en + raiz.valor + ", ";
                enorden(raiz.der);
            }
            return en;
        }
        public string posorden(Nodo raiz)
        {
            if (raiz != null)
            {
                posorden(raiz.iz);
                posorden(raiz.der);
                pos = pos + raiz.valor + ", ";
            }
            return pos;
        }
    
    }
        


}
