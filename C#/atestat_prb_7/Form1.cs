using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace atestat_prb_7
{
    public partial class Form1 : Form
    {
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database1.mdf;Integrated Security=True");
        SqlCommand cmd;
        SqlDataAdapter da;
        DataTable dt;
        void actualizeaza()
        {
            con.Open();
            cmd = new SqlCommand("select * from magazin", con);
            da = new SqlDataAdapter(cmd);
            dt = new DataTable();
            da.Fill(dt);
            dataGridView1.DataSource = dt;
            con.Close();
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            actualizeaza();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int min, max;
            min = int.Parse(textBox1.Text);
            max = int.Parse(textBox2.Text);
            if(min>max)
            {
                int aux;
                aux = min;
                min = max;
                max = aux;
            }
            con.Open();
            cmd = new SqlCommand("SELECT cod, denumire, unitate, cantitate, pret FROM magazin WHERE cantitate >= " + min + " AND cantitate <= " + max + "ORDER BY cantitate", con);
            da = new SqlDataAdapter(cmd);
            dt = new DataTable();
            da.Fill(dt);
            dataGridView2.DataSource = dt;
            con.Close();

        }

        private void button2_Click(object sender, EventArgs e)
        {
            con.Open();
            cmd = new SqlCommand("SELECT SUM(pret * cantitate) AS valoare_totala FROM magazin", con);
            da = new SqlDataAdapter(cmd);
            dt = new DataTable();
            da.Fill(dt);
            dataGridView3.DataSource = dt;
            con.Close();
        }
    }
}
