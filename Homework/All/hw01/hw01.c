#include <stdio.h>
#include <string.h>
#define MaxRow 3
#define MaxColumn 3

//  scan two puzzles
void scanPuzzle(char immovable_Puzzle[][MaxColumn], char movable_Puzzle[][MaxColumn])
{
    int i;

    for (i = 0; i < MaxRow; i++)
    {
        scanf("%s", immovable_Puzzle[i]);
    }

    for (i = 0; i < MaxRow; i++)
    {
        scanf("%s", movable_Puzzle[i]);
    }
}

// get the puzzle's bondary
void getMarginBondary(char puzzle[][MaxColumn], int mode, int *upperBond, int *lowerBond, int *leftBond, int *rightBond)
{
    // immovable puzzle
    if (mode == 1)
    {
        for (int currentRow = 0; currentRow < MaxRow; currentRow++)
        {
            for (int currentColumn = 0; currentColumn < MaxColumn; currentColumn++)
            {
                if (puzzle[currentRow][currentColumn] == '0')
                {
                    if (currentRow < *upperBond)
                        *upperBond = currentRow;
                    if (currentRow > *lowerBond)
                        *lowerBond = currentRow;
                    if (currentColumn < *leftBond)
                        *leftBond = currentColumn;
                    if (currentColumn > *rightBond)
                        *rightBond = currentColumn;
                }
            }
        }
    }
    // movable puzzle
    else if (mode == 2)
    {
        for (int currentRow = 0; currentRow < MaxRow; currentRow++)
        {
            for (int currentColumn = 0; currentColumn < MaxColumn; currentColumn++)
            {
                if (puzzle[currentRow][currentColumn] == '2')
                {
                    if (currentRow < *upperBond)
                        *upperBond = currentRow;
                    if (currentRow > *lowerBond)
                        *lowerBond = currentRow;
                    if (currentColumn < *leftBond)
                        *leftBond = currentColumn;
                    if (currentColumn > *rightBond)
                        *rightBond = currentColumn;
                }
            }
        }
    }
}

// copy the margin part of the puzzle
void copyMargin(char immovable_puzzle[][MaxColumn], int upper, int lower, int left, int right, char margin[][right - left + 1])
{
    for (int i = upper; i <= lower; i++)
    {
        for (int j = left; j <= right; j++)
        {
            if (immovable_puzzle[i][j] == '2')
            {
                margin[i - upper][j - left] = '1';
                continue;
            }
            margin[i - upper][j - left] = immovable_puzzle[i][j];
        }
    }
}

// rotate 90 degrees once
void rotation(int old_width, int old_height, int new_width, int new_height, char old[old_height][old_width], char new[new_height][new_width])
{
    int row, column;
    column = new_width - 1;

    for (int i = 0; i < old_height; i++)
    {
        row = 0;
        for (int j = 0; j < old_width; j++)
        {
            new[row][column] = old[i][j];
            row++;
        }
        column--;
    }
}

// compare whether two margin can merge or not using XOR(both elements can't be '0')
int compare(int immo_width, int immo_height, int mov_width, int mov_height, char immovable[immo_height][immo_width], char movable[mov_height][mov_width])
{
    for (int i = 0; i < immo_height; i++)
    {
        for (int j = 0; j < immo_width; j++)
        {
            if (immovable[i][j] == '0' && movable[i][j] == '0')
            {
                return 0;
            }
        }
    }
    return 1;
}

// when two puzzles can merge, print out the consequences
void success(char immovable[MaxRow][MaxColumn])
{
    printf("YES\n");
    for (int i = 0; i < MaxRow; i++)
    {
        for (int j = 0; j < MaxColumn; j++)
        {
            if (immovable[i][j] == '1')
            {
                printf("%c", immovable[i][j]);
            }
            else
            {
                printf("2");
            }
        }
        printf("\n");
    }
}

// swap two values
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    // variables and initialization
    char immovable_Puzzle[MaxRow][MaxColumn];
    char movable_Puzzle[MaxRow][MaxColumn];

    int testCount = 0;

    int immovable_upperBond, immovable_lowerBond, immovable_leftBond, immovable_rightBond;
    int movable_upperBond, movable_lowerBond, movable_leftBond, movable_rightBond;

    int immovable_width, immovable_height, movable_width, movable_height;

    //  scan how many test cases
    scanf("%d", &testCount);

    // scan two puzzles and compare whether they can merge or not
    for (int timeCnt = 0; timeCnt < testCount; timeCnt++)
    {
        // scan two puzzles
        scanPuzzle(immovable_Puzzle, movable_Puzzle);

        // initialize the variables
        immovable_upperBond = immovable_leftBond = movable_upperBond = movable_leftBond = 100;
        immovable_lowerBond = immovable_rightBond = movable_lowerBond = movable_rightBond = -1;

        //  get the margin of the puzzle and size of both margin
        getMarginBondary(immovable_Puzzle, 1, &immovable_upperBond, &immovable_lowerBond, &immovable_leftBond, &immovable_rightBond);
        getMarginBondary(movable_Puzzle, 2, &movable_upperBond, &movable_lowerBond, &movable_leftBond, &movable_rightBond);

        // calculate the height and width of both puzzles
        immovable_height = immovable_lowerBond - immovable_upperBond + 1;
        immovable_width = immovable_rightBond - immovable_leftBond + 1;
        movable_height = movable_lowerBond - movable_upperBond + 1;
        movable_width = movable_rightBond - movable_leftBond + 1;

        // two puzzle can not merge because their size are not the same
        if (immovable_height * immovable_width != movable_height * movable_width)
        {
            printf("NO\n");
            continue;
        }

        // innitialize two arrays of margin(immovable puzzle and movable puzzle)
        char immovable_Margin[immovable_lowerBond - immovable_upperBond + 1][immovable_rightBond - immovable_leftBond + 1];
        char movable_Margin[movable_lowerBond - movable_upperBond + 1][movable_rightBond - movable_leftBond + 1];
        immovable_Margin[0][0] = '\0';
        movable_Margin[0][0] = '\0';

        // copy immovable margin to the array
        copyMargin(immovable_Puzzle, immovable_upperBond, immovable_lowerBond, immovable_leftBond, immovable_rightBond, immovable_Margin);
        copyMargin(movable_Puzzle, movable_upperBond, movable_lowerBond, movable_leftBond, movable_rightBond, movable_Margin);

        //  compare diffent cases
        int ret = 0;
        int tmp_height, tmp_width;
        if (immovable_width == movable_width)
        {
            //  is square e.g: 2*2 array
            if (immovable_width == immovable_height)
            {
                //    compare 4 rotation condition 90 180 270 0 degrees
                for (int i = 0; i < 4; i++)
                {
                    // declare an array to save the order of rotated margin
                    char rotated[immovable_height][immovable_width], buffer[immovable_height][immovable_width];

                    // copy the order of movable margin to rotated
                    for (int p = 0; p < movable_height; p++)
                    {
                        strcpy(rotated[p], movable_Margin[p]);
                    }

                    // rotate 90 180 270 0 degrees
                    for (int j = 0; j <= i; j++)
                    {
                        // copy the order of rotated order to buffer and use buffer's order to do rotation
                        for (int p = 0; p < movable_height; p++)
                        {
                            strcpy(buffer[p], rotated[p]);
                        }
                        rotation(immovable_width, immovable_height, immovable_width, immovable_height, buffer, rotated);
                    }

                    ret = compare(immovable_width, immovable_height, movable_width, immovable_height, immovable_Margin, rotated);

                    // can merge
                    if (ret == 1)
                    {
                        break;
                    }
                }
            }
            //  e.g:two 3*2 arrays
            else
            {
                //    compare 2 rotation condition 0 180 degrees
                for (int i = 0; i < 2; i++)
                {
                    tmp_height = movable_height;
                    tmp_width = movable_width;

                    if (i == 1)
                    {
                        swap(&tmp_height, &tmp_width);
                        char tmpMargin[tmp_height][tmp_width];
                        rotation(movable_width, movable_height, tmp_width, tmp_height, movable_Margin, tmpMargin);
                        rotation(tmp_width, tmp_height, movable_width, movable_height, tmpMargin, movable_Margin);
                    }

                    ret = compare(immovable_width, immovable_height, movable_width, movable_height, immovable_Margin, movable_Margin);

                    // can merge
                    if (ret == 1)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            // a 2*3 array and a 3*2 array
            // rotation 90 270 degrees
            for (int i = 0; i < 2; i++)
            {
                tmp_height = movable_width;
                tmp_width = movable_height;
                char rotated[tmp_height][tmp_width];
                // rotate 90 degrees
                rotation(movable_width, movable_height, tmp_width, tmp_height, movable_Margin, rotated);
                // rotate 270 degrees
                if (i == 1)
                {
                    rotation(tmp_width, tmp_height, immovable_width, immovable_height, rotated, immovable_Margin);
                    rotation(immovable_width, immovable_height, tmp_width, tmp_height, immovable_Margin, rotated);
                }

                ret = compare(immovable_width, immovable_height, tmp_width, tmp_height, immovable_Margin, rotated);

                if (ret == 1)
                {
                    break;
                }
            }
        }
        if (ret == 1)
        {
            success(immovable_Puzzle);
            ret = 0;
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}