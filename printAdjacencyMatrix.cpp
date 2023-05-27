#include <iostream>
constexpr int maxSize = 999;

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void printAdjacencyMatrix(int adjacencyMatrix[][maxSize], int vertices)
{
    system("clear");
    for(int i = 0 ; i <= vertices ; ++i)
    {
        adjacencyMatrix[i][0] = i;
    }

    for(int j = 0 ; j <= vertices ; ++j)
    {
        adjacencyMatrix[0][j] = j;
    }

    std::cout << "\033[1;92m";
    std::cout << R"(
           _____       _         _____ ______ _   _  _______     __  __  __       _______ _____  _______   __
     /\   |  __ \     | |  /\   / ____|  ____| \ | |/ ____\ \   / / |  \/  |   /\|__   __|  __ \|_   _\ \ / /
    /  \  | |  | |    | | /  \ | |    | |__  |  \| | |     \ \_/ /  | \  / |  /  \  | |  | |__) | | |  \ V / 
   / /\ \ | |  | |_   | |/ /\ \| |    |  __| | . ` | |      \   /   | |\/| | / /\ \ | |  |  _  /  | |   > <  
  / ____ \| |__| | |__| / ____ \ |____| |____| |\  | |____   | |    | |  | |/ ____ \| |  | | \ \ _| |_ / . \ 
 /_/    \_\_____/ \____/_/    \_\_____|______|_| \_|\_____|  |_|    |_|  |_/_/    \_\_|  |_|  \_\_____/_/ \_\
                                                                                                             )";
    int coordinateM = 7;
    for(int i = 0 ; i <= vertices ; ++i)
    {
        gotoxy(42, ++coordinateM);

        for(int j = 0 ; j <= vertices ; ++j)
        {
            if(adjacencyMatrix[i][j] < 10)
            {
                std::cout << " ";
            }

            if(i == 0 || j == 0)
            {
                std::cout << "\033[1;91m" << adjacencyMatrix[i][j] << " ";
            }

            else
            {
                std::cout << "\033[1;96m" << adjacencyMatrix[i][j] << " ";
            }
        }
        std::cout << "\033[0m" << std::endl;
    }
}
