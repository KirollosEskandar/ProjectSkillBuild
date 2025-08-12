using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;

namespace WindowsFormsApp5
{
    public partial class Form1 : Form
    {
        char[,] XO = { { '?', '?' , '?'}, { '?', '?', '?' } , { '?', '?', '?' } };
        private void ChangPhoto(int X, int Y)
        {
            if(LBPlayerNow.Text == "X")
            {
                if (X == 0 && Y == 0)
                {
                    XO[0, 0] = 'X';
                    pictureBox2.Image = Image.FromFile(@"C:\X.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "O";

                }
                else if (X == 0 && Y == 1)
                {
                    XO[0, 1] = 'X';
                    pictureBox3.Image = Image.FromFile(@"C:\X.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "O";

                }
                else if (X == 0 && Y == 2)
                {
                    XO[0, 2] = 'X';
                    pictureBox1.Image = Image.FromFile(@"C:\X.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "O";


                }
                else if (X == 1 && Y == 0)
                {
                    XO[1, 0] = 'X';
                    pictureBox4.Image = Image.FromFile(@"C:\X.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "O";

                }
                else if (X == 1 && Y == 1)
                {
                    XO[1, 1] = 'X';
                    pictureBox6.Image = Image.FromFile(@"C:\X.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "O";

                }
                else if (X == 1 && Y == 2)
                {
                    XO[1, 2] = 'X';
                    pictureBox5.Image = Image.FromFile(@"C:\X.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "O";

                }
                else if (X == 2 && Y == 0)
                {
                    XO[2, 0] = 'X';
                    pictureBox7.Image = Image.FromFile(@"C:\X.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "O";

                }
                else if (X == 2 && Y == 1)
                {
                    XO[2, 1] = 'X';
                    pictureBox9.Image = Image.FromFile(@"C:\X.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "O";

                }
                else if(X == 2 && Y == 2)
                {
                    XO[2, 2] = 'X';
                    pictureBox8.Image = Image.FromFile(@"C:\X.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "O";

                }
            }
            else
            {
                if (X == 0 && Y == 0)
                {
                    XO[0, 0] = 'O';
                    pictureBox2.Image = Image.FromFile(@"C:\O.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "X";

                }
                else if (X == 0 && Y == 1)
                {
                    XO[0, 1] = 'O';
                    pictureBox3.Image = Image.FromFile(@"C:\O.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "X";

                }
                else if (X == 0 && Y == 2)
                {
                    XO[0, 2] = 'O';
                    pictureBox1.Image = Image.FromFile(@"C:\O.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "X";

                }
                else if (X == 1 && Y == 0)
                {
                    XO[1, 0] = 'O';
                    pictureBox4.Image = Image.FromFile(@"C:\O.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "X";

                }
                else if (X == 1 && Y == 1)
                {
                    XO[1, 1] = 'O';
                    pictureBox6.Image = Image.FromFile(@"C:\O.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "X";

                }
                else if (X == 1 && Y == 2)
                {
                    XO[1, 2] = 'O';
                    pictureBox5.Image = Image.FromFile(@"C:\O.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "X";

                }
                else if (X == 2 && Y == 0)
                {
                    XO[2, 0] = 'O';
                    pictureBox7.Image = Image.FromFile(@"C:\O.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "X";

                }
                else if (X == 2 && Y == 1)
                {
                    XO[2, 1] = 'O';
                    pictureBox9.Image = Image.FromFile(@"C:\O.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "X";

                }
                else if (X == 2 && Y == 2)
                {
                    XO[2, 2] = 'O';
                    pictureBox8.Image = Image.FromFile(@"C:\O.png");
                    CheckWinner(LBPlayerNow.Text);
                    LBPlayerNow.Text = "X";

                }
            }

        }
        private void CheckWinner(string Player)
        {
            if(Player[0] == XO[0,0] && Player[0] == XO[1, 0] && Player[0] == XO[2, 0])
            {
                string MsgWinner = "Winner is a " + Player[0] +  "\a\a";
                MessageBox.Show(MsgWinner);
                groupBox1.Enabled = false;
                label5.Text = Player;
            }
            else if (Player[0] == XO[0, 1] && Player[0] == XO[1, 1] && Player[0] == XO[2, 1])
            {
                MessageBox.Show("Winner is [0]", Player);
                groupBox1.Enabled = false;
                label5.Text = Player;

            }
            else if (Player[0] == XO[0, 2] && Player[0] == XO[1, 2] && Player[0] == XO[2, 2])
            {
                MessageBox.Show("Winner is [0]", Player);
                groupBox1.Enabled = false;
                label5.Text = Player;

            }
            else if (Player[0] == XO[0, 0] && Player[0] == XO[1, 1] && Player[0] == XO[2, 2])
            {
                MessageBox.Show("Winner is [0]", Player);
                groupBox1.Enabled = false;
                label5.Text = Player;

            }
            else if (Player[0] == XO[0, 2] && Player[0] == XO[1, 1] && Player[0] == XO[2, 0])
            {
                MessageBox.Show("Winner is [0]", Player);
                groupBox1.Enabled = false;
                label5.Text = Player;

            }
            else if (Player[0] == XO[0, 0] && Player[0] == XO[0, 1] && Player[0] == XO[0, 2])
            {
                MessageBox.Show("Winner is [0]", Player);
                groupBox1.Enabled = false;
                label5.Text = Player;

            }
            else if (Player[0] == XO[1, 0] && Player[0] == XO[1, 1] && Player[0] == XO[1, 2])
            {
                MessageBox.Show("Winner is [0]", Player);
                groupBox1.Enabled = false;
                label5.Text = Player;

            }
            else if (Player[0] == XO[2, 0] && Player[0] == XO[2, 1] && Player[0] == XO[2, 2])
            {
                MessageBox.Show("Winner is [0]", Player);
                groupBox1.Enabled = false;
                label5.Text = Player;

            }
        }
        private void RestGame()
        {
            // pictureBox2
            pictureBox1.Image = Image.FromFile(@"C:\question-mark-96.png");
            pictureBox2.Image = Image.FromFile(@"C:\question-mark-96.png");
            pictureBox3.Image = Image.FromFile(@"C:\question-mark-96.png");
            pictureBox4.Image = Image.FromFile(@"C:\question-mark-96.png");
            pictureBox5.Image = Image.FromFile(@"C:\question-mark-96.png");
            pictureBox6.Image = Image.FromFile(@"C:\question-mark-96.png");
            pictureBox7.Image = Image.FromFile(@"C:\question-mark-96.png");
            pictureBox9.Image = Image.FromFile(@"C:\question-mark-96.png");
            pictureBox8.Image = Image.FromFile(@"C:\question-mark-96.png");
            groupBox1.Enabled = true;
            label5.Text = "In Progress";
            LBPlayerNow.Text = "X";

            for(int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    XO[i,j] = '?';

                }
            }
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            RestGame();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            if (XO[0, 1] == '?')
            {
                ChangPhoto(0, 1);
            }
            else
            {
                MessageBox.Show("Chosee Another Place .", "Can't");
            }
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            if(XO[0,0] == '?')
            {
                ChangPhoto(0, 0);
            }
            else
            {
                MessageBox.Show("Chosee Another Place .", "Can't");
            }

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if (XO[0, 2] == '?')
            {
                ChangPhoto(0, 2);
            }
            else
            {
                MessageBox.Show("Chosee Another Place .", "Can't");
            }
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            if (XO[1, 0] == '?')
            {
                ChangPhoto(1, 0);
            }
            else
            {
                MessageBox.Show("Chosee Another Place .", "Can't");
            }
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            if (XO[1, 1] == '?')
            {
                ChangPhoto(1, 1);
            }
            else
            {
                MessageBox.Show("Chosee Another Place .", "Can't");
            }
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            if (XO[1, 2] == '?')
            {
                ChangPhoto(1, 2);
            }
            else
            {
                MessageBox.Show("Chosee Another Place .", "Can't");
            }
        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {
            if (XO[2, 0] == '?')
            {
                ChangPhoto(2, 0);
            }
            else
            {
                MessageBox.Show("Chosee Another Place .", "Can't");
            }
        }

        private void pictureBox9_Click(object sender, EventArgs e)
        {
            if (XO[2, 1] == '?')
            {
                ChangPhoto(2, 1);
            }
            else
            {
                MessageBox.Show("Chosee Another Place .", "Can't");
            }
        }

        private void pictureBox8_Click(object sender, EventArgs e)
        {
            if (XO[2, 2] == '?')
            {
                ChangPhoto(2, 2);
            }
            else
            {
                MessageBox.Show("Chosee Another Place .", "Can't");
            }
        }
    }
}
