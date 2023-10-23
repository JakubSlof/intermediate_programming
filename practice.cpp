#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>

/*
 * V Kocourkově se rozhodly, že systém adres domů je zastaralý a potřebují nový.
 * Protože v Kocourkově právě probíhá výzkum v oblasti automatického doručování pošty, rozhodli se systém uzpůsobit robotům.
 * Roboti neumí číst text, a proto je potřeba adresu zakódovat do čísel.
 *
 * Adresa domu se skládá z několika částí:
 * - číslo bloku
 * - číslo ulice
 * - číslo domu
 *
 * Město se skládá z několika bloků, každý blok má několik ulic a každá ulice má několik domů.
 * Bloky jsou uspořádáné ve čtvercové síti.
 * Ulice v bloku jsou pod sebou (změna osy Y)
 * Domy v ulici jsou vedle sebe (změna osy X)
 * Viz tabule.
 *
 * Každé město musím mít alespoň jeden blok, každý blok musí mít alespoň jednu ulici, každá ulice musí mít alespoň jeden dům.
 */

/*
 * Vytvořte strukturu pro definici města.
 * Potřebujete si ukládat kolik má město bloků, kolik má každý blok ulic a kolik má každá ulice domů.
 * (všechny bloky a všechny ulice jsou stejné)
 */
struct Town
{
    int blocks;
    int streets;
    int houses;
};

/*
 * Vytvořte strukturu pro definici adresy.
 * Potřebujete si ukládat číslo bloku, číslo ulice a číslo domu.
 */
struct Address
{
    int block;
    int street;
    int house;
};
/*
 * Napište funkci, která zkontorluje, zda je město validní.
 */
bool isTownValid(Town town)
{
    if (town.blocks > 0 && std::sqrt(town.blocks) * std::sqrt(town.blocks) == town.blocks && town.houses > 0 && town.streets > 0)
    {
        return true;
    }
    return false;
}

/*
 * Napište funkci, která zkontroluje, zda je adresa validní.
 */
bool isAddressValid(Address address, Town town)
{
    if (address.house < town.houses && address.street < town.streets && address.block < town.blocks)
    {
        return true;
    }
    return false;
}

/*
 * Napište funkci, která vypočítá vzdálenost mezi dvěma adresami.
 * Jsou možné následující typy pohybu.
 * Pohyb mezi domy (+-X) - vzdálenost 1
 * Pohyb mezi ulicemi (+-Y) - vzdálenost 5
 * Pohyb mezi bloky (+-X, +-Y) - vzdálenost 10
 */
// std::size_t
void distance1(Address address1, Address address2, Town town)
{
    // int house = 1;
    // int street = 5;
    // int block = 10;
    if (address1.block > address2.block)
    {
        Address c = address2;
        address2 = address1;
        address1 = c;
    }
    if (address1.block == address2.block)
    {
        if (address1.house > address2.house)
        {
            Address c = address2;
            address2 = address1;
            address1 = c;
        }
    }
    int Row = std::sqrt(town.blocks);
    int Col = std::sqrt(town.blocks);
    std::vector<std::vector<int>> block_array(Row, std::vector<int>(Col));
    // int block_array[Row][Col]; //nefunguje protoze kompiler
    int count = 0;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            block_array[i][j] = count;
            count++;
        }
    }
    int first_block = address1.block;
    int second_block = address2.block;
    bool found = false;
    int row1 = -69;
    int row2 = -69;
    int col1 = -69;
    int col2 = -69;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (block_array[i][j] == first_block)
            {
                found = true;
                row1 = i;
                col1 = j;
                break;
            }
        }
        if (found == true)
        {
            break;
        }
    }
    ////////////////////////////////////////////////////
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (block_array[i][j] == second_block)
            {
                found = true;
                row2 = i;
                col2 = j;
                break;
            }
        }
        if (found == true)
        {
            break;
        }
    }
    std::cout << row1 << std::endl;
    std::cout << col1 << std::endl;
    std::cout << row2 << std::endl;
    std::cout << col2 << std::endl;

    int row_diff = abs(row1 - row2);
    int col_diff = abs(col1 - col2);
    std::cout << " " << std::endl;
    std::cout << row_diff << std::endl;
    std::cout << col_diff << std::endl;
    int block_diff = abs(row_diff + col_diff);
    int street_dif = abs(address1.street - address2.street) + (row_diff * town.streets);
    int house_diff = (town.houses - address1.house - 1) + (address2.house) + (col_diff - 1) * (town.houses - 1);
    std::cout << " " << std::endl;
    std::cout << block_diff << std::endl;
    std::cout << street_dif << std::endl;
    std::cout << house_diff << std::endl;
    int expensivnes = block_diff * 10 + street_dif * 5 + house_diff;
    std::cout << expensivnes << std::endl;
}

std::size_t distance(Address address1, Address address2, Town town)
{
    if (address1.block > address2.block)
    {
        Address c = address2;
        address2 = address1;
        address1 = c;
    }
    if (address1.block == address2.block)
    {
        if (address1.house > address2.house)
        {
            Address c = address2;
            address2 = address1;
            address1 = c;
        }
    }
    int Row = std::sqrt(town.blocks);
    int Col = std::sqrt(town.blocks);
    std::vector<std::vector<int>> block_array(Row, std::vector<int>(Col));
    // int block_array[Row][Col]; //nefunguje protoze kompiler
    int count = 0;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            block_array[i][j] = count;
            count++;
        }
    }
    int first_block = address1.block;
    int second_block = address2.block;
    bool found = false;
    int row1 = -69;
    int row2 = -69;
    int col1 = -69;
    int col2 = -69;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (block_array[i][j] == first_block)
            {
                found = true;
                row1 = i;
                col1 = j;
                break;
            }
        }
        if (found == true)
        {
            break;
        }
    }
    ////////////////////////////////////////////////////
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (block_array[i][j] == second_block)
            {
                found = true;
                row2 = i;
                col2 = j;
                break;
            }
        }
        if (found == true)
        {
            break;
        }
    }

    int row_diff = abs(row1 - row2);
    int col_diff = abs(col1 - col2);
    int block_diff = abs(row_diff + col_diff);
    int street_dif = abs(address1.street - address2.street) + (row_diff * town.streets);
    int house_diff = (town.houses - address1.house - 1) + (address2.house) + (col_diff - 1) * (town.houses - 1);
    int expensivnes = block_diff * 10 + street_dif * 5 + house_diff;
    return expensivnes;
}

int main()
{
    Town validTown = {
        .blocks = 9,
        .streets = 3,
        .houses = 4,
    };

    Town invalidTown1 = {
        .blocks = 0,
        .streets = 5,
        .houses = 10,
    };

    Town invalidTown2 = {
        .blocks = 24,
        .streets = 2,
        .houses = 10,
    };

    Address validAddress1 = {
        .block = 0,
        .street = 1,
        .house = 2, // default 2
    };

    Address validAddress2 = {
        .block = 1, // default 1
        .street = 2,
        .house = 3,
    };

    Address invalidAddress1 = {
        .block = 4,
        .street = 3,
        .house = 3,
    };

    assert(isTownValid(validTown));
    assert(!isTownValid(invalidTown1));
    assert(!isTownValid(invalidTown2));
    assert(isAddressValid(validAddress1, validTown));
    assert(!isAddressValid(invalidAddress1, validTown));

    assert(distance(validAddress1, validAddress1, validTown) == 0);
    assert(distance(validAddress1, validAddress2, validTown) == 19);
    //distance1(validAddress1, validAddress2, validTown);
}
