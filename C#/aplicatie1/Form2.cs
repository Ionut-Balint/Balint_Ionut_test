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
    public partial class Form2 : Form
    {
        string cons = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Database1.mdf;Integrated Security=True";
        SqlConnection conn;
        SqlCommand cmd;
        SqlDataReader dr;
        SqlDataAdapter da;
        string nume, prenume;
        public Form2()
        {
            InitializeComponent();
        }
        public void ini_u()
        {
            listBox1.Items.Clear();
            conn = new SqlConnection(cons);
            conn.Open();
            cmd = new SqlCommand();
            cmd.Connection = conn;
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from elevi order by nume";
            dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                nume = dr[1].ToString();
                prenume = dr[2].ToString();
                listBox1.Items.Add(nume + " " + prenume);
            }
            conn.Close();
        }
        private void Form2_Load(object sender, EventArgs e)
        {
            ini_u();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "" && textBox2.Text != "")
            {
                conn = new SqlConnection(cons);
                conn.Open();
                cmd = new SqlCommand();
                cmd.Connection = conn;
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "insert into elevi(nume,prenume) values('" + textBox1.Text + "','" + textBox2.Text + "')";
                cmd.ExecuteNonQuery();
                conn.Close();
                ini_u();
            }
            else
                MessageBox.Show("Nu ati completet toate campurile");
        }
        private void button2_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex != -1)
            {
                nume = listBox1.SelectedItem.ToString();
                conn = new SqlConnection(cons);
                conn.Open();
                cmd = new SqlCommand();
                cmd.Connection = conn;
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "delete from elevi where nume+' '+prenume='" + nume + "'";
                cmd.ExecuteNonQuery();
                conn.Close();
                ini_u();
            }
            else
                MessageBox.Show("Nu ati  selectat nimic");
        }
        private void button3_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex != -1)
            {
                nume = listBox1.SelectedItem.ToString();
                conn = new SqlConnection(cons);
                conn.Open();
                cmd = new SqlCommand();
                cmd.Connection = conn;
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "update elevi set nume='" + textBox3.Text + "'where nume +' '+prenume='" + nume + "'";
                cmd.ExecuteNonQuery();
                conn.Close();
                conn.Open();
                cmd = new SqlCommand();
                cmd.Connection = conn;
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "update elevi set prenume='" + textBox4.Text + "'where nume +' '+prenume='" + nume + "'";
                cmd.ExecuteNonQuery();
                conn.Close();
                ini_u();
            }
            else
                MessageBox.Show("Nu s a ales un elev");
        }
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex != -1)
            {
                nume = listBox1.SelectedItem.ToString();
                conn = new SqlConnection(cons);
                conn.Open();
                cmd = new SqlCommand();
                cmd.Connection = conn;
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = "select nume , prenume from elevi where nume+' '+prenume='" + nume + "'";
                dr = cmd.ExecuteReader();
                dr.Read();
                textBox3.Text = dr[0].ToString();
                textBox4.Text = dr[1].ToString();
                conn.Close();
            }
            else
                MessageBox.Show("Nu ati selectat nimic");
        }
    }
}
