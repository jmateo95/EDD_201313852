using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace servicio
{
    public class usuario
    {
        public class juego
        {
            public string oponente;
            public int desple;
            public int sob;
            public int des;
            public bool gano;
            public juego sig;
            public juego ant;
        }
        
        
        public class nodo {
            public string nick;
            public string pass;
            public string correo;
            public bool conectado;
            public juego juegos;
            public nodo iz;
            public nodo der;
        
        }
        public nodo raiz = null;

        public int lugar(string nombre, nodo raiz)
        {
           if(nombre.Equals(raiz.nick)){
               return 0;
           }
           else
           {
               int itera;
               if(nombre.Length>raiz.nick.Length){
                   itera = raiz.nick.Length;
               }
               else
               {
                   itera = nombre.Length;
               }
               for (int i = 0; i < itera; i++)
               {
                   char a;
                   char b;
                   a = Convert.ToChar(nombre.Substring(i,1));
                   b = Convert.ToChar(raiz.nick.Substring(i, 1));
                   if(b>a){
                       return 1;
                   }else if (a>b){
                       return 2;
                   }

               }
               if (nombre.Length > raiz.nick.Length)
               {
                   return 2;
               }
               else
               {
                   return 1;
               }
           }   
        }

        public int insertarusuario(string nick, string pass, string correo, bool conectado)
        {
            nodo usuario1 = new nodo();
            usuario1.nick = nick;
            usuario1.pass = pass;
            usuario1.correo = correo;
            usuario1.conectado = conectado;
            usuario1.juegos = null;
            usuario1.iz = null;
            usuario1.der = null;
            if (raiz == null){
                raiz = usuario1;
                return 1;
            }else{
                nodo ant = null;
                nodo aux = raiz;
                usuario a= new usuario();
                while (aux != null)
                {
                    ant = aux;
                    int valor=a.lugar(nick, aux);
                    if (valor==0) {
                        return 0;
                    }else if(valor==1){
                        aux = aux.iz;
                        if (aux == null)
                        {
                            ant.iz =usuario1;
                            return 1;
                        }
                    }else{
                        aux = aux.der;
                        if (aux == null)
                        {
                            ant.der = usuario1;
                            return 1;
                        }
                    }
                    
                }
                return 0;

            }

        }
        public int entrar(string nick, string pass, usuario a)
        {
            nodo aux = a.raiz;
            while (aux != null)
            {
                if (aux.nick.Equals(nick))
                {
                    if (aux.pass.Equals(pass))
                    {
                        aux.conectado = true;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    int valor = a.lugar(nick, aux);
                    if (valor == 1)
                    {
                        aux = aux.iz;
                    }
                    else
                    {
                        aux = aux.der;
                    }
                }


            }
            return 0;
        }
    }
}