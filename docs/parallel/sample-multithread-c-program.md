---
title: Programa C multithread de exemplo
ms.date: 08/09/2019
ms.assetid: 4706f6cd-ff9c-4dbf-99a2-1c999b568f17
ms.openlocfilehash: 355024b995dc638b89a335983bd2e0f2cb0d96ce
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924766"
---
# <a name="sample-multithread-c-program"></a>Programa C multithread de exemplo

Bounce. c é um exemplo de programa multithread que cria um novo thread sempre que a letra `a` ou `A` é digitada. Cada thread salta uma letra de uma cor diferente em toda a tela. Até 32 threads podem ser criados. A terminação normal do programa ocorre quando `q` ou `Q` é digitada.

## <a name="compile-and-link-a-multithread-program"></a>Compilar e vincular um programa multithread

Os programas são compilados como multissegmentados por padrão.

### <a name="to-compile-and-link-the-multithread-program-bouncec-from-within-the-development-environment"></a>Para compilar e vincular o programa multithread Bounce. c de dentro do ambiente de desenvolvimento

::: moniker range=">=msvc-160"

1. No menu **Arquivo** , escolha **Novo** > **Projeto** .

1. Na caixa de diálogo **criar um novo projeto** , selecione o modelo de **aplicativo de console** que tem as marcas **C++** , **Windows** e **console** . Escolha **Avançar** para continuar.

1. Na caixa de diálogo **configurar seu novo projeto** , insira um nome para seu projeto, como "elástico". Escolha **criar** para continuar.

1. Na janela **Gerenciador de soluções** , abra a pasta **arquivos de origem** em seu projeto e altere o nome do arquivo de origem para ter uma extensão. c.

1. Na janela Editar, exclua o código-fonte existente e substitua-o pelo código de exemplo.

1. No menu **Compilar** , escolha **Compilar Solução** .

1. Pressione **F5** para iniciar o programa no depurador.

::: moniker-end

::: moniker range="<=msvc-150"

1. No menu **Arquivo** , escolha **Novo** > **Projeto** .

1. Na caixa de diálogo **novo projeto** , selecione **Visual C++** no painel esquerdo e, em seguida, selecione **projeto vazio** no painel central.

1. Na caixa de edição **nome** , insira um nome para seu projeto, como "elástico". Escolha **OK** para criar o projeto vazio.

1. Na janela **Gerenciador de soluções** , abra a pasta **arquivos de origem** em seu projeto e adicione o arquivo que contém o código-fonte C ao projeto.

1. No menu **Compilar** , compile o projeto escolhendo o comando **Compilar solução** .

1. Pressione **F5** para iniciar o programa no depurador.

::: moniker-end

### <a name="to-compile-and-link-the-multithread-program-bouncec-from-the-command-line"></a>Para compilar e vincular o programa multithread Bounce. c da linha de comando

1. Compile e vincule o programa:

    ```cmd
    cl bounce.c
    ```

## <a name="example"></a>Exemplo

Para criar na linha de comando, copie e salve este exemplo em um arquivo de origem com uma extensão. c. No IDE, substitua qualquer código-fonte criado pelo modelo por este exemplo:

```C
// sample_multithread_c_program.c
// compile with: /c
//
//  Bounce - Creates a new thread each time the letter 'a' is typed.
//  Each thread bounces a character of a different color around
//  the screen. All threads are terminated when the letter 'Q' is
//  entered.
//

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>

#define MAX_THREADS  32

// The function getrandom returns a random number between
// min and max, which must be in integer range.
#define getrandom( min, max ) (SHORT)((rand() % (int)(((max) + 1) - \
                               (min))) + (min))

int main(void);                    // Thread 1: main
void KbdFunc(void);                // Keyboard input, thread dispatch
void BounceProc(void* MyID);       // Threads 2 to n: display
void ClearScreen(void);            // Screen clear
void ShutDown(void);               // Program shutdown
void WriteTitle(int ThreadNum);    // Display title bar information

HANDLE  hConsoleOut;                 // Handle to the console
HANDLE  hRunMutex;                   // "Keep Running" mutex
HANDLE  hScreenMutex;                // "Screen update" mutex
int     ThreadNr;                    // Number of threads started
CONSOLE_SCREEN_BUFFER_INFO csbiInfo; // Console information
COORD   consoleSize;
BOOL    bTrails;

int main() // Thread One
{
    // Get display screen information & clear the screen.
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
    consoleSize.X = csbiInfo.srWindow.Right;
    consoleSize.Y = csbiInfo.srWindow.Bottom;
    ClearScreen();
    WriteTitle(0);

    // Create the mutexes and reset thread count.
    hScreenMutex = CreateMutexW(NULL, FALSE, NULL);  // Cleared
    hRunMutex = CreateMutexW(NULL, TRUE, NULL);      // Set
    ThreadNr = 0;
    bTrails = FALSE;

    // Start waiting for keyboard input to dispatch threads or exit.
    KbdFunc();

    // All threads done. Clean up handles.
    if (hScreenMutex) CloseHandle(hScreenMutex);
    if (hRunMutex) CloseHandle(hRunMutex);
    if (hConsoleOut) CloseHandle(hConsoleOut);
}

void ShutDown(void) // Shut down threads
{
    while (ThreadNr > 0)
    {
        // Tell thread to die and record its death.
        ReleaseMutex(hRunMutex);
        ThreadNr--;
    }

    // Clean up display when done
    WaitForSingleObject(hScreenMutex, INFINITE);
    ClearScreen();
}

void KbdFunc(void) // Dispatch and count threads.
{
    int         KeyInfo;

    do
    {
        KeyInfo = _getch();
        if (tolower(KeyInfo) == 'a' &&
            ThreadNr < MAX_THREADS)
        {
            ThreadNr++;
            _beginthread(BounceProc, 0, &ThreadNr);
            WriteTitle(ThreadNr);
        }
        if (tolower(KeyInfo) == 't')
        {
            bTrails = !bTrails;
        }
    } while (tolower(KeyInfo) != 'q');

    ShutDown();
}

void BounceProc(void* pMyID)
{
    wchar_t MyCell, OldCell;
    WORD    MyAttrib, OldAttrib = 0;
    wchar_t BlankCell = 0x20;
    COORD   Coords, Delta;
    COORD   Old = { 0,0 };
    DWORD   Dummy;
    char* MyID = (char*)pMyID;

    // Generate update increments and initial
    // display coordinates.
    srand((unsigned int)* MyID * 3);

    Coords.X = getrandom(0, consoleSize.X - 1);
    Coords.Y = getrandom(0, consoleSize.Y - 1);
    Delta.X = getrandom(-3, 3);
    Delta.Y = getrandom(-3, 3);

    // Set up character & generate color
    // attribute from thread number.
    if (*MyID > 16)
        MyCell = 0x60 + *MyID - 16; // lower case
    else
        MyCell = 0x40 + *MyID;      // upper case
    MyAttrib = *MyID & 0x0f;   // force black background

    do
    {
        // Wait for display to be available, then lock it.
        WaitForSingleObject(hScreenMutex, INFINITE);

        if (!bTrails)
        {
            // If we still occupy the old screen position, blank it out.
            ReadConsoleOutputCharacterW(hConsoleOut, &OldCell, 1,
                Old, &Dummy);
            ReadConsoleOutputAttribute(hConsoleOut, &OldAttrib, 1,
                Old, &Dummy);
            if ((OldCell == MyCell) && (OldAttrib == MyAttrib))
                WriteConsoleOutputCharacterW(hConsoleOut, &BlankCell, 1,
                    Old, &Dummy);
        }

        // Draw new character, then clear screen lock
        WriteConsoleOutputCharacterW(hConsoleOut, &MyCell, 1,
            Coords, &Dummy);
        WriteConsoleOutputAttribute(hConsoleOut, &MyAttrib, 1,
            Coords, &Dummy);
        ReleaseMutex(hScreenMutex);

        // Increment the coordinates for next placement of the block.
        Old.X = Coords.X;
        Old.Y = Coords.Y;
        Coords.X += Delta.X;
        Coords.Y += Delta.Y;

        // If we are about to go off the screen, reverse direction
        if (Coords.X < 0 || Coords.X >= consoleSize.X)
        {
            Delta.X = -Delta.X;
            Beep(400, 50);
        }
        if (Coords.Y < 0 || Coords.Y > consoleSize.Y)
        {
            Delta.Y = -Delta.Y;
            Beep(600, 50);
        }
    }
    // Repeat while RunMutex is still taken.
    while (WaitForSingleObject(hRunMutex, 75L) == WAIT_TIMEOUT);
}

void WriteTitle(int ThreadNum)
{
    enum
    {
        sizeOfNThreadMsg = 120
    };
    wchar_t    NThreadMsg[sizeOfNThreadMsg] = { L"" };

    swprintf_s(NThreadMsg, sizeOfNThreadMsg,
        L"Threads running: %02d.  Press 'A' "
        L"to start a thread, 'T' to toggle "
        L"trails, 'Q' to quit.", ThreadNum);
    SetConsoleTitleW(NThreadMsg);
}

void ClearScreen(void)
{
    DWORD    dummy = 0;
    COORD    Home = { 0, 0 };
    FillConsoleOutputCharacterW(hConsoleOut, L' ',
        consoleSize.X * consoleSize.Y,
        Home, &dummy);
}
```

## <a name="see-also"></a>Veja também

[Multithread com C e Win32](multithreading-with-c-and-win32.md)
