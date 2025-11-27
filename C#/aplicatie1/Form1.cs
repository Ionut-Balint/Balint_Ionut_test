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

namespace aplicatie1
{
    public partial class Form1 : Form
    {
        string cons = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database1.mdf;Integrated Security=True";
        SqlConnection conn;
        SqlCommand cmd;
        SqlDataReader dr;
        SqlDataAdapter da;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            conn = new SqlConnection(cons);
            conn.Open();
            cmd = new SqlCommand("select * from elevi");
            cmd.Connection = conn;
            dr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            dataGridView1.DataSource = dt;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.Show();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            string nume = textBox1.Text, q;
            if (nume != "")
                q = "select * from  elevi where nume like '%" + nume + "%'";
            else
                q = "select * from elevi";
            SqlCommand c = new SqlCommand(q, conn);
            SqlDataAdapter da = new SqlDataAdapter(c);
            DataTable t = new DataTable();
            da.Fill(t);
            dataGridView1.DataSource = t;
        }
    }
}
