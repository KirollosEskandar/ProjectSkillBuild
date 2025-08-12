using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pizza_V1
{

    public partial class Form1 : Form
    {
        private void _RestForm()
        {
            radioButton2.Checked = true;
            radioButton9.Checked = true;
            radioButton5.Checked = true;
            checkBox1.Checked = false;
            checkBox4.Checked = false;
            checkBox6.Checked = false;
            checkBox2.Checked = false;
            checkBox3.Checked = false;
            checkBox5.Checked = false;

            label9.Text = "Eat In";
            label8.Text = "Thin";
            label7.Text = "";

            groupBox1.Enabled = true;
            groupBox3.Enabled = true;
            groupBox2.Enabled = true;
            groupBox4.Enabled = true;
            groupBox5.Enabled = true;
            button2.Enabled = true;
        }
        private int _GetPricePizee()
        {
            int PricePizee = 0;
            // checkBox5
            if (radioButton1.Checked)
            {
                PricePizee += 10;
            }
            if (radioButton2.Checked)
            {
                PricePizee += 12;
            }
            if (radioButton3.Checked)
            {
                PricePizee += 15;
            }
            if (radioButton9.Checked)
            {
                PricePizee += 0;
            }
            if (radioButton8.Checked)
            {
                PricePizee += 7;
            }
            if (checkBox1.Checked)
            {
                PricePizee += 3;
            }
            if (checkBox4.Checked)
            {
                PricePizee += 3;
            }
            if (checkBox2.Checked)
            {
                PricePizee += 3;
            }
            if (checkBox6.Checked)
            {
                PricePizee += 3;
            }
            if (checkBox3.Checked)
            {
                PricePizee += 3;
            }
            if (checkBox5.Checked)
            {
                PricePizee += 3;
            }
            if (radioButton3.Checked)
            {
                PricePizee += 3;
            }
            if (radioButton5.Checked)
            {
                PricePizee += 3;
            }

            return PricePizee;
        }
        private void _SetEatWhere()
        {
            if (radioButton5.Checked)
            {
                label9.Text = "Eat in";
            }
            else
                label9.Text = "Take Out";
        }
        private void _SetCnstType()
        {
            if (radioButton9.Checked)
            {
                label8.Text = "Thin";
            }
            else if (radioButton8.Checked)
            {
                label8.Text = "Thik";
            }

        }
        private void _SetTopping()
        {
            label7.Text = "";
            if (checkBox1.Checked)
            {
                label7.Text += "Extraa Cheese,";
            }
            if (checkBox4.Checked)
            {
                label7.Text += " Green Pappers,";
            }
            if (checkBox6.Checked)
            {
                label7.Text += " Mushrooms,";
            }
            if (checkBox2.Checked)
            {
                label7.Text += "\nTomaties,";
            }
            // Olives
            if (checkBox3.Checked)
            {
                label7.Text += " Olives,";
            }
            if (checkBox5.Checked)
            {
                label7.Text += " Onion,";
            }
        }
        private void _SetSize()
        {
            if (radioButton1.Checked)
            {
                label6.Text = "Small";
            }
            else if (radioButton2.Checked)
            {
                label6.Text = "Meduim";
            }
            else
            {
                label6.Text = "Larg";
            }
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = _GetPricePizee().ToString() + "$";

            _SetSize();
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = _GetPricePizee().ToString() + "$";

            _SetSize();
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = _GetPricePizee().ToString() + "$";

            _SetSize();
        }

        private void radioButton7_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void groupBox3_Enter(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = _GetPricePizee().ToString() + "$";
            _SetTopping();
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = _GetPricePizee().ToString() + "$";
            _SetTopping();
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {

            label10.Text = _GetPricePizee().ToString() + "$";
            _SetTopping();
        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void groupBox5_Enter(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = _GetPricePizee().ToString() + "$";
            _SetTopping();

        }

        private void checkBox6_CheckedChanged(object sender, EventArgs e)
        {

            label10.Text = _GetPricePizee().ToString() + "$";
            _SetTopping();
        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {

            label10.Text = _GetPricePizee().ToString() + "$";
            _SetTopping();

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void radioButton9_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = _GetPricePizee().ToString() + "$";
            _SetCnstType();
        }

        private void radioButton8_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = _GetPricePizee().ToString() + "$";
            _SetCnstType();
        }

        private void radioButton5_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = _GetPricePizee().ToString() + "$";
            _SetEatWhere();
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = _GetPricePizee().ToString() + "$";
            _SetEatWhere();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            _RestForm();
            label10.Text = _GetPricePizee().ToString() + "$";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(
            MessageBox.Show("Are You Sure ? ",
                "Conform", MessageBoxButtons.OKCancel, MessageBoxIcon.Question)
                == DialogResult.OK)
            {
                groupBox1.Enabled = false;
                groupBox3.Enabled = false;
                groupBox2.Enabled = false;
                groupBox4.Enabled = false;
                groupBox5.Enabled = false;
                button2.Enabled = false;

                MessageBox.Show("Please Watting, Your Order Will Be Ready.");
            }
        }

        private void label11_Click(object sender, EventArgs e)
        {

        }
    }
}
