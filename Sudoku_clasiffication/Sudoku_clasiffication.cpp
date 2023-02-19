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
   
public:
    void set_id(int n)
    {
        this->id = n;
    }
    void set_label(int v)
    {
        this->label = v;
    }
    void set_row(int n)
    {
        this->row = n / 9;
    }
    void set_col(int n)
    {
        this->col = n % 9;
    }
    void  set_gru(int n)
    {
        int rw_part{};
        int co_part{};
        rw_part = n / 27;
        co_part = (n / 3) % 3;
        this->gru = rw_part * 3 + co_part;
    }
    void show(int n)
    {
        if (n < 10)
            std::cout << ' ';
        std::cout << this->id << ", " << this->row << ", " << this->col << ", " << this->gru << ", " << this->label << "." << std::endl ;
    }

};

int main()
{
    // test operator integer division and modulus
    // std::cout << "\ninteger division 42/27 = " << 42 / 27 << "  modulus 42%27 = " << 42 % 27 << std::endl; 
    // done
    Cell grid[81]{};
    std::string labels = "....218.7..2.6...1...8....9.81..5..6....8....9..6..48.4....9...6...7.9..1.724....";
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

    for (int i = 0; i < 81; i++)
        grid[i].show(i);

    return 0;
}
