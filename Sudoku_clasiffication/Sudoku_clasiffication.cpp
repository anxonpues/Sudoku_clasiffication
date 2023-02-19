// Sudoku_clasiffication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <string>

class Cell
{
private:
    int id{};
    int label{};
    int row{};
    int col{};
    int gru{};
    std::bitset<9> sts{};
    int row_count{};
    int col_count{};
    int gru_count{};

   
public:
    void set_sts(std::bitset<9> posible)
    {
        this->sts = posible;
    }
    std::bitset<9> get_sts(int n)
    {
        return this->sts;
    }
       
    void set_id(int n)
    {
        this->id = n;
    }

    void set_label(int v)
    {
        this->label = v;
    }
    int get_label(int v)
    {
        return this->label;
    }

    void set_row(int n)
    {
        this->row = n / 9;
    }
    int get_row(int v)
    {
        return this->row;
    }

    void set_col(int n)
    {
        this->col = n % 9;
    }
    int get_col(int v)
    {
        return this->col;
    }
    
    void  set_gru(int n)
    {
        int rw_part{};
        int co_part{};
        rw_part = n / 27;
        co_part = (n / 3) % 3;
        this->gru = rw_part * 3 + co_part;
    }
    int get_gru(int v)
    {
        return this->gru;
    }

    void show(int n)
    {
        if (n < 10)
            std::cout << ' ';
        std::cout << " " << this->id << ", " << this->row << ", " << this->col << ", " << this->gru << ", " << this->label << "." 
            << " possibles "<< this->sts << " ********* " << std::endl;
    }

};

int main()
{
    // test operator integer division and modulus
    // std::cout << "\ninteger division 42/27 = " << 42 / 27 << "  modulus 42%27 = " << 42 % 27 << std::endl; 
    // done
    Cell grid[81]{}; 
    std::string labels = "..9.218.78.296...1.1.8....9.81495..6....8.19.9..6..48.4.8..9...6...789.4197246..8";
    size_t ll = labels.length();
    
    // write every data available to cell array
    for (int i = 0; i < 81; i++)
    {
        grid[i].set_id(i);
        grid[i].set_row(i);
        grid[i].set_col(i);
        grid[i].set_gru(i);
        char ch = labels[i];
        if(ch=='.')
            grid[i].set_label(0);
        else
            grid[i].set_label((int)(ch-'0'));
    }


    int rc{};
    int cc{};
    int gc{};
    std::bitset<9> mask{};
    for (int i = 0; i < 81; i++)
    {
        // counts for every cell the labels in its row, column and grup
        if (grid[i].get_label(i) == 0)
        {
            mask.reset();
            rc = 0;
            for (int j = 0; j < 9; j++)
            {
                int idx = grid[i].get_row(i) * 9 + j;
                if (grid[idx].get_label(idx) != 0)
                {
                    rc++;
                    mask.set(grid[idx].get_label(idx) - 1);
                }
            }

            cc = 0;
            for (int k = 0; k < 9; k++)
            {
                int idx = grid[i].get_col(i) + k * 9;
                if (grid[idx].get_label(idx) != 0)
                {
                    cc++;
                    mask.set(grid[idx].get_label(idx) - 1);
                }
            }

            gc = 0;
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                {
                    int idx = grid[i].get_gru(i);
                    int pcg =((idx/3) * 9 + idx % 3)*3;
                    if (grid[pcg + j * 9 + k].get_label(pcg + j * 9 + k) != 0)
                    {
                        gc++;
                        mask.set(grid[pcg + j * 9 + k].get_label(pcg + j * 9 + k) - 1);
                    }
                }

            char aji{};
            char ajc{};
            if (i < 10) aji = ' ';
            if (rc + cc + gc < 10) ajc = ' ';
            std::cout << "\n grid tag " << aji << i << "  :  " << 
                ajc  <<
                rc + cc + gc << " data.   " << mask.flip();
            //std::cout << "\n grid tag " << i << "  :  " << rc + cc  << " data.";
            //std::cout << "\n grid tag " << i << "  :  " << gc << " data.";

            // set the sts of the grid[i].sts
            grid[i].set_sts((mask.flip()));
        }
    }
    std::cout << "\n\n";
    
    for (int i = 0 ; i < 81; i++)
        grid[i].show(i);

    return 0;
}
