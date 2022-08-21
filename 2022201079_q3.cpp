#include <iostream>
#include <fstream>

using namespace std;

int square(int n)
{
    return n * n;
}
void calc_energy(int ***rgb, int **energy, int H, int W, int C)
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int ex = 0, ey = 0;
            for (int k = 0; k < C; k++)
            {
                if (j == 0 && i == 0)
                {
                    // x component
                    ex = ex + square(rgb[i][W - 1][k] - rgb[i][j + 1][k]);
                    // y component
                    ey = ey + square(rgb[H - 1][j][k] - rgb[i + 1][j][k]);
                }
                else if (j == 0 && i != H - 1)
                {
                    // x component
                    ex = ex + square(rgb[i][W - 1][k] - rgb[i][j + 1][k]);
                    // y component
                    ey = ey + square(rgb[i - 1][j][k] - rgb[i + 1][j][k]);
                }
                else if (j == 0 && i == H - 1)
                {
                    // x component
                    ex = ex + square(rgb[i][W - 1][k] - rgb[i][j + 1][k]);
                    // y component
                    ey = ey + square(rgb[i - 1][j][k] - rgb[0][j][k]);
                }
                else if (j == W - 1 && i == 0) // for j=W-1
                {
                    // x component
                    ex = ex + square(rgb[i][0][k] - rgb[i][j - 1][k]);
                    // y component
                    ey = ey + square(rgb[H - 1][j][k] - rgb[i + 1][j][k]);
                }
                else if (j == W - 1 && i != H - 1)
                {
                    // x component
                    ex = ex + square(rgb[i][0][k] - rgb[i][j - 1][k]);
                    // y component
                    ey = ey + square(rgb[i - 1][j][k] - rgb[i + 1][j][k]);
                }
                else if (j == W - 1 && i == H - 1)
                {
                    // x component
                    ex = ex + square(rgb[i][0][k] - rgb[i][j - 1][k]);
                    // y component
                    ey = ey + square(rgb[i - 1][j][k] - rgb[0][j][k]);
                }
                else if (i == 0 && j != 0 && j != W - 1)
                {
                    // x component
                    ex = ex + square(rgb[i][j + 1][k] - rgb[i][j - 1][k]);
                    // y component
                    ey = ey + square(rgb[H - 1][j][k] - rgb[i + 1][j][k]);
                }
                else if (j != 0 && j != W - 1 && i != H - 1)
                {
                    // x component
                    ex = ex + square(rgb[i][j + 1][k] - rgb[i][j - 1][k]);
                    // y component
                    ey = ey + square(rgb[i - 1][j][k] - rgb[i + 1][j][k]);
                }
                else if (j != W - 1 && j != 0 && i == H - 1)
                {
                    // x component
                    ex = ex + square(rgb[i][j + 1][k] - rgb[i][j - 1][k]);
                    // y component
                    ey = ey + square(rgb[i - 1][j][k] - rgb[0][j][k]);
                }
            }
            energy[i][j] = ex + ey;
        }
    }
}

int min1(int **path, int H, int W, int i, int j)
{
    int min_idx;
    if (j == 0)
    {
        if (path[i][j] > path[i][j + 1])
            min_idx = j + 1;
        else
            min_idx = j;
    }
    else if (j != W - 1)
    {
        min_idx = j;
        if (path[i][min_idx] > path[i][j - 1])
            min_idx = j - 1;
        if (path[i][min_idx] > path[i][j + 1])
            min_idx = j + 1;
    }
    else
    {
        if (path[i][j] > path[i][j - 1])
            min_idx = j - 1;
        else
            min_idx = j;
    }

    return min_idx;
}

int min2(int **path, int H, int i, int j)
{
    int min_idx;
    if (i == 0)
    {
        if (path[i][j] > path[i + 1][j])
            min_idx = i + 1;
        else
            min_idx = i;
    }
    else if (i != H - 1)
    {
        min_idx = i;
        if (path[min_idx][j] > path[i - 1][j])
            min_idx = i - 1;
        if (path[min_idx][j] > path[i + 1][j])
            min_idx = i + 1;
    }
    else
    {
        if (path[i][j] > path[i - 1][j])
            min_idx = i - 1;
        else
            min_idx = i;
    }

    return min_idx;
}

int min(int a, int b, int c)
{
    int m = 2147483647;

    if (m > b)
    {
        m = b;
    }
    if (m > a)
    {
        m = a;
    }
    if (m > c)
    {
        m = c;
    }
    return m;
}

int min(int a, int b)
{
    int m = 2147483647;

    if (m > b)
    {
        m = b;
    }
    if (m > a)
    {
        m = a;
    }
    return m;
}

int min_idx(int **energy, int W)
{
    int min_idx;
    int min_energy;
    for (int j = 0; j < W; ++j)
    {
        if (j == 0)
        {
            min_energy = energy[0][j];
            min_idx = j;
        }
        else
        {
            if (min_energy > energy[0][j])
            {
                min_energy = energy[0][j];
                min_idx = j;
            }
        }
    }
    return min_idx;
}

int min_idxH(int **energy, int H)
{
    int min_idx;
    int min_energy;
    for (int j = 0; j < H; ++j)
    {
        if (j == 0)
        {
            min_energy = energy[j][0];
            min_idx = j;
        }
        else
        {
            if (min_energy > energy[j][0])
            {
                min_energy = energy[j][0];
                min_idx = j;
            }
        }
    }
    return min_idx;
}

void calc_path(int **path, int **energy, int H, int W)
{
    for (int j = W - 1; j >= 0; j--)
    {

        for (int i = 0; i < H; ++i)
        {
            if (j != W - 1)
            {
                if (i == 0)
                {
                    path[i][j] = energy[i][j] + min(path[i][j + 1], path[i + 1][j + 1]);
                }
                else if (i != H - 1)
                {
                    path[i][j] = energy[i][j] + min(path[i + 1][j + 1], path[i][j + 1], path[i - 1][j + 1]);
                }
                else
                {
                    path[i][j] = energy[i][j] + min(path[i][j + 1], path[i - 1][j + 1]);
                }
            }
            else
            {
                path[i][j] = energy[i][j];
            }
        }
    }
}
void calc_path1(int **path, int **energy, int H, int W)
{
    for (int i = H - 1; i >= 0; i--)
    {

        for (int j = 0; j < W; ++j)
        {
            if (i != H - 1)
            {
                if (j == 0)
                {
                    path[i][j] = energy[i][j] + min(path[i + 1][j], path[i + 1][j + 1]);
                }
                else if (j != W - 1)
                {
                    path[i][j] = energy[i][j] + min(path[i + 1][j], path[i + 1][j + 1], path[i + 1][j - 1]);
                }
                else
                {
                    path[i][j] = energy[i][j] + min(path[i + 1][j], path[i + 1][j - 1]);
                }
            }
            else
            {
                path[i][j] = energy[i][j];
            }
        }
    }
}

void reduce_W(int **energy, int **path, int ***rgb, int H, int W, int W_, int C)
{
    if (W == W_)
        return;

    int j = min_idx(path, W);

    for (int i = 0; i < H; i++)
    {
        if (i == 0)
        {
            for (int k = j; k < W - 1; k++)
            {
                path[i][k] = path[i][k + 1];
                for (int l = 0; l < C; l++)
                {
                    rgb[i][k][l] = rgb[i][k + 1][l];
                }
            }
        }
        else
        {
            j = min1(path, H, W, i, j);
            for (int k = j; k < W - 1; k++)
            {
                path[i][k] = path[i][k + 1];
                for (int l = 0; l < C; l++)
                {
                    rgb[i][k][l] = rgb[i][k + 1][l];
                }
            }
        }
    }
    calc_energy(rgb, energy, H, W - 1, C);
    calc_path1(path, energy, H, W - 1);
    reduce_W(energy, path, rgb, H, W - 1, W_, C);
}

void reduce_H(int **energy, int **path, int ***rgb, int H, int W_, int H_, int C)
{
    if (H == H_)
        return;

    int j = min_idxH(path, H);

    for (int k = 0; k < W_; k++)
    {

        if (k == 0)
        {

            for (int i = j; i < H - 1; i++)
            {
                path[i][k] = path[i + 1][k];
                for (int l = 0; l < C; l++)
                {
                    rgb[i][k][l] = rgb[i + 1][k][l];
                }
            }
        }
        else
        {

            j = min2(path, H, j, k);

            for (int i = j; i < H - 1; i++)
            {
                path[i][k] = path[i + 1][k];

                for (int l = 0; l < C; l++)
                {
                    rgb[i][k][l] = rgb[i + 1][k][l];
                }
            }
        }
    }

        calc_energy(rgb, energy, H - 1, W_, C);

    calc_path(path, energy, H - 1, W_);

    reduce_H(energy, path, rgb, H - 1, W_, H_, C);
}

void solve(int ***rgb, int H, int W, int C, int H_, int W_, int C_)
{
    // We've provided you the driver.py and main.cpp for your convinience
    // Please go through them and understand the file handling and input/output format
    // Feel free to experiment on your own

    // can access the array using rgb[i][j][k] like a regular 3D array

    // Write your code here
    int **energy, **path;
    energy = new int *[H];
    path = new int *[H];
    for (int i = 0; i < H; i++)
    {
        energy[i] = new int[W];
        path[i] = new int[W];
        for (int j = 0; j < W; ++j)
        {

            energy[i][j] = 0;
            path[i][j] = 0;
        }
    }
    calc_energy(rgb, energy, H, W, C);

    for (int i = H - 1; i >= 0; i--)
    {

        for (int j = 0; j < W; ++j)
        {
            if (i != H - 1)
            {
                if (j == 0)
                {
                    path[i][j] = energy[i][j] + min(path[i + 1][j], path[i + 1][j + 1]);
                }
                else if (j != W - 1)
                {
                    path[i][j] = energy[i][j] + min(path[i + 1][j], path[i + 1][j + 1], path[i + 1][j - 1]);
                }
                else
                {
                    path[i][j] = energy[i][j] + min(path[i + 1][j], path[i + 1][j - 1]);
                }
            }
            else
            {
                path[i][j] = energy[i][j];
            }
        }
    }

    reduce_W(energy, path, rgb, H, W, W_, C);
    calc_energy(rgb, energy, H, W, C);
    calc_path(path, energy, H, W);
    reduce_H(energy, path, rgb, H, W, H_, C);
}

int main()
{
    string ip_dir = "./data/input/";
    string ip_file = "rgb_in.txt";
    ifstream fin(ip_dir + ip_file);

    int H, W, C;
    fin >> H >> W >> C;

    int ***rgb;
    rgb = new int **[H];
    for (int i = 0; i < H; ++i)
    {
        rgb[i] = new int *[W];
        for (int j = 0; j < W; ++j)
        {
            rgb[i][j] = new int[C];
            for (int k = 0; k < C; ++k)
                fin >> rgb[i][j][k];
        }
    }
    fin.close();

    int H_, W_, C_;
    cout << "Enter new value for H (must be less than " << H << "): ";
    cin >> H_;
    cout << "Enter new value for W (must be less than " << W << "): ";
    cin >> W_;
    cout << '\n';
    C_ = C;

    solve(rgb, H, W, C, H_, W_, C_);

    string op_dir = "./data/output/";
    string op_file = "rgb_out.txt";
    ofstream fout(op_dir + op_file);

    fout << H_ << " " << W_ << " " << C_ << endl;
    for (int i = 0; i < H_; ++i)
    {
        for (int j = 0; j < W_; ++j)
        {
            for (int k = 0; k < C_; ++k)
            {
                fout << rgb[i][j][k] << " ";
            }
        }
        fout << '\n';
    }
    fout.close();

    return 0;
}