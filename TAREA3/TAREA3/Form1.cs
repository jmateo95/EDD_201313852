using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TAREA3
{
    public partial class Form1 : Form
    {
        int valor;
        arbol a=new arbol();
        string imprimir = "";

        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
           if(!textBox1.Text.Equals("")){
            valor = Int32.Parse(textBox1.Text);
            a.insertar(valor);
            textBox1.Text = "";
           }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            imprimir = "";
            label6.Text = imprimir;
            a.pre = "";
            imprimir=a.preorden(a.raiz);
            label6.Text = imprimir;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            imprimir = "";
            label7.Text = imprimir;
            a.en = "";
            imprimir = a.enorden(a.raiz);
            label7.Text = imprimir;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            imprimir = "";
            label8.Text = imprimir;
            a.pos = "";
            imprimir = a.posorden(a.raiz);
            label8.Text = imprimir;
        }

        private void label8_Click(object sender, EventArgs e)
        {

        }
    }
}
