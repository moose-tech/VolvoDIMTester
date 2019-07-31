using System;
using System.IO.Ports;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace DIM_Test
{
    public partial class Form1 : Form
    {
        SerialPort port;
        string[] ports = SerialPort.GetPortNames();
        bool p2_ignition = false;
        public Form1()
        {
            InitializeComponent();
            this.FormClosed += new FormClosedEventHandler(Form1_FormClosed);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.DataSource = ports;
            this.Size = new Size(315, 168);
            label2.Visible = false;
            radioButton1.Visible = false;
            radioButton2.Visible = false;
            button2.Visible = false;
            button3.Visible = false;
        }

        void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (radioButton1.Checked == true)
            {
                if (p2_ignition == true)
                {
                    //IGN Off P2
                    MessageBox.Show("Zapalování vypnete stiskem tlačítka RESET na Arduinu.");
                }
            }
            else if (radioButton2.Checked == true)
            {
                //IGN Off P3
                byte[] bytesTosend = new byte[1] { 0x05 };
                port.Write(bytesTosend, 0, 1);
            }
            if (port != null && port.IsOpen)
            {
                port.Close();
            }

        }

        private void ZavřítToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void AutorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("© Copyright 2019, Tony Castek", "Autor", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedItem == null)
            {
                MessageBox.Show("Prosím vyberte COM port.", "Chyba", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                this.Size = new Size(315, 300);
                label2.Visible = true;
                radioButton1.Visible = true;
                radioButton2.Visible = true;
                button2.Visible = true;
                button3.Visible = true;
                button1.Enabled = false;
                port = new SerialPort(comboBox1.SelectedItem.ToString(), 9600); //Set your board COM
                port.Open();
                
            }
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            if (button3.Text == "Zapnout zapalování")
            {
                button3.Text = "Vypnout zapalování";
                if (radioButton1.Checked == true)
                {
                    p2_ignition = true;
                    //IGN On P2
                    byte[] bytesTosend = new byte[1] { 0x01 };
                    port.Write(bytesTosend, 0, 1);
                }
                else if (radioButton2.Checked == true)
                {
                    //IGN On P3
                    byte[] bytesTosend = new byte[1] { 0x03 };
                    port.Write(bytesTosend, 0, 1);
                }
            }
            else if (button3.Text == "Vypnout zapalování")
            {
                button3.Text = "Zapnout zapalování";
                if (radioButton1.Checked == true)
                {
                    //IGN Off P2
                    MessageBox.Show("Zapalování vypnete stiskem tlačítka RESET na Arduinu.");
                }
                else if (radioButton2.Checked == true)
                {
                    //IGN Off P3
                    byte[] bytesTosend = new byte[1] { 0x05 };
                    port.Write(bytesTosend, 0, 1);
                }
            }
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            if (radioButton1.Checked == true)
            {
                //Test P2
                byte[] bytesTosend = new byte[1] { 0x02 };
                port.Write(bytesTosend, 0, 1);
            }
            else if (radioButton2.Checked == true)
            {
                //Test P3
                byte[] bytesTosend = new byte[1] { 0x04 };
                port.Write(bytesTosend, 0, 1);
            }
        }
    }
}
