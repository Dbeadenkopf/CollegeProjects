// first thing the game will need is some assetts which is
// is the stuff that the game uses to play (block pieces)
// Tetromino Blocks(Differtent Shapes)
#include <iostream>
using namespace std;
// Here is the string array that will hold 
// each Tetromino Shape
wstring tetromino[7];


// Asset # 2 The Playing Feild 
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr; // pointer used  a new board instance

int nScreenWidth = 80; // Console Screen Size X (Columns)
int nScreenHeight = 30; // Console Screen Size Y (rows)



// Now we will Perform the function tthat will rotate the peices
// subsituting for manuelly storing them
int Rotate(int px, int py, int r){
    switch(r % 4){
        case 0: return py * 4 + px;  // rotate 0 degrees
        case 1: return 12 + py - (px * 4); // rotate 90 degrees
        case 2: return 15 - (py * 4) - px; // rotate 180 degrees
        case 3: return 3 - py + (px * 4); // rotate 270 degrees
    }
    return 0;
}




// we are not gonna use all of the shapes,
// we will be indexing this Array which will perform
// that rotation for us
int main(){
    // Create Tetromino Shapes
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"....");

     tetromino[2].append(L".X..");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L".X.");
    tetromino[2].append(L"....");


    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");


     tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");



    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");

    tetromino[6].append(L"..X.");
    tetromino[6].append(L"..X.");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L"....");


    // initilize new board
    pField = new unsigned char[nFieldWidth*nFieldHeight];
    for (int x = 0; x < nFieldWidth; x++) // Board Boundary
        for (int y = 0; y < nFieldHeight; y++)
	  pField[(y*nFieldWidth) = x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;


    // now to make emulator , creates an arrary for board, with blank stuff
    // can no longer use cout
    wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
    for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWrtiten = 0;

    // Game Loop (Begin Game, End Game)
    bool bGameOver = false;
    while(!bGameOver){
    // Display Frame
    // starting at postition (0,0)
        // WE ARE HERE
        for (int x = 0; x < nFieldWidth; x++)
            for (int y = 0; y < nFieldWidth; y++)
                                                        // tetris peices here
                screen[(y+2)*nScreenWidth = (x + 2)] = L" ABCDEFG=#"[pField[y*nFieldWidth + x]]; 
        
        WriteConsoleOutputCharacter(hConsole,screen,nScreenWidth*nScreenHeight, {0,0}, &dwBytesWritten);
    }



    return 0;
}
