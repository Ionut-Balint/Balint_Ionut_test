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

namespace atestat_prb_14
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
            cmd = new SqlCommand("SELECT * FROM scoli", con);
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
            con.Open();
            SqlCommand cmd = new SqlCommand(@"IF OBJECT_ID('scoli_copie') IS NULL BEGIN SELECT * INTO scoli_copie FROM scoli WHERE 1 = 0 END", con);
            cmd.ExecuteNonQuery();
            cmd = new SqlCommand("DELETE FROM scoli_copie", con);
            cmd.ExecuteNonQuery();
            cmd = new SqlCommand("SET IDENTITY_INSERT scoli_copie ON", con);
            cmd.ExecuteNonQuery();
            cmd = new SqlCommand(@"INSERT INTO scoli_copie (Id, nume_scoala, localitatea, nivel_invatamant, numar_clase, numar_elevi) SELECT TOP 3 Id, nume_scoala, localitatea, nivel_invatamant, numar_clase, numar_elevi FROM scoli", con);
            cmd.ExecuteNonQuery();
            cmd = new SqlCommand("SET IDENTITY_INSERT scoli_copie OFF", con);
            cmd.ExecuteNonQuery();
            cmd = new SqlCommand("SELECT * FROM scoli_copie", con);
            da = new SqlDataAdapter(cmd);
            dt = new DataTable();
            da.Fill(dt);
            dataGridView2.DataSource = dt;
            con.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            con.Open();
            cmd = new SqlCommand("SELECT SUM(numar_elevi) FROM scoli AS Total WHERE nivel_invatamant=\'" + textBox1.Text + "\'", con);
            da = new SqlDataAdapter(cmd);
            dt = new DataTable();
            da.Fill(dt);
            dataGridView3.DataSource = dt;
            con.Close();
        }
    }
}
