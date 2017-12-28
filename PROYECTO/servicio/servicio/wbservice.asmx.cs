using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace servicio
{
    /// <summary>
    /// Descripción breve de wbservice
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // Para permitir que se llame a este servicio web desde un script, usando ASP.NET AJAX, quite la marca de comentario de la línea siguiente. 
    // [System.Web.Script.Services.ScriptService]

    public class wbservice : System.Web.Services.WebService
    {
        usuario a = new usuario();
        [WebMethod]
        public string HelloWorld()
        {
            return "Hola a todos";
        }
        [WebMethod]
        public int insertarusuario(string nick, string pass, string correo)
        {
            return (a.insertarusuario(nick, pass, correo, false));
        }
    
    
    }
}
