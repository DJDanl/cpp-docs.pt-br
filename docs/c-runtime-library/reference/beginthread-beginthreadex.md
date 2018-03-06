---
title: _beginthread, _beginthreadex | Microsoft Docs
ms.custom: 
ms.date: 02/27/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _beginthread
- _beginthreadex
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- beginthread
- _beginthread
- beginthreadex
- _beginthreadex
dev_langs:
- C++
helpviewer_keywords:
- _beginthread function
- threading [C++], creating threads
- beginthreadex function
- _beginthreadex function
- beginthread function
ms.assetid: 0df64740-a978-4358-a88f-fb0702720091
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1d7b575883bfad702d32a161a985a76494797747
ms.sourcegitcommit: 4e01d36ffa64ea11bacf589f79d2f1df947e2510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2018
---
# <a name="beginthread-beginthreadex"></a>_beginthread, _beginthreadex

Cria um thread.

## <a name="syntax"></a>Sintaxe

```cpp
uintptr_t _beginthread( // NATIVE CODE
   void( __cdecl *start_address )( void * ),
   unsigned stack_size,
   void *arglist
);
uintptr_t _beginthread( // MANAGED CODE
   void( __clrcall *start_address )( void * ),
   unsigned stack_size,
   void *arglist
);
uintptr_t _beginthreadex( // NATIVE CODE
   void *security,
   unsigned stack_size,
   unsigned ( __stdcall *start_address )( void * ),
   void *arglist,
   unsigned initflag,
   unsigned *thrdaddr
);
uintptr_t _beginthreadex( // MANAGED CODE
   void *security,
   unsigned stack_size,
   unsigned ( __clrcall *start_address )( void * ),
   void *arglist,
   unsigned initflag,
   unsigned *thrdaddr
);
```

### <a name="parameters"></a>Parâmetros

*start_address*<br/>
Endereço inicial de uma rotina que inicia a execução de um novo thread. Para `_beginthread`, a convenção de chamada é [__cdecl](../../cpp/cdecl.md) (para código nativo) ou [__clrcall](../../cpp/clrcall.md) (para código gerenciado); para `_beginthreadex`, é [__stdcall](../../cpp/stdcall.md) (para código nativo) ou [__clrcall](../../cpp/clrcall.md) (para código gerenciado).

*stack_size*<br/>
Tamanho da pila para um novo thread ou 0.

*arglist*<br/>
Lista de argumentos a ser apresentada a um novo thread ou NULL.

*Segurança*<br/>
Ponteiro para uma estrutura [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) que determina se o identificador retornado pode ser herdado por processos filhos. Se *segurança* for NULL, o identificador não pode ser herdado. Deve ser NULL para aplicativos Windows 95.

*initflag*<br/>
Sinalizadores que controlam o estado inicial de um novo thread. Definir *initflag* para `0` para executar imediatamente, ou `CREATE_SUSPENDED` para criar o thread em um estado suspenso; use [ResumeThread](http://msdn.microsoft.com/library/windows/desktop/ms685086.aspx) para executar o thread. Definir *initflag* para `STACK_SIZE_PARAM_IS_A_RESERVATION` sinalizador para usar *stack_size* como o tamanho inicial de reserva da pilha em bytes; se este sinalizador não for especificado, *stack_size* Especifica o tamanho de confirmação.

*thrdaddr*<br/>
Aponta para uma variável de 32 bits que recebe o identificador de thread. Se o valor for NULL, esse parâmetro não é usado.

## <a name="return-value"></a>Valor de retorno

Em caso de êxito, cada uma dessas funções retorna um indicador para o thread novo. No entanto, se esse novo thread surgir muito rápido, `_beginthread` pode não retornar um indicador válido. Confira a discussão na sessão Observações. Em caso de erro, `_beginthread` retorna -1L e `errno` é definido como `EAGAIN` se houver muitos threads para `EINVAL` se o argumento for inválido ou o tamanho da pilha estiver incorreto, ou para `EACCES` se não houver recursos suficientes (como memória). Em caso de erro, `_beginthreadex` retorna 0 e `errno` e `_doserrno` são definidos.

Se *start_address* for NULL, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão -1.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter mais informações sobre `uintptr_t`, consulte [Tipos padrão](../../c-runtime-library/standard-types.md).

## <a name="remarks"></a>Comentários

O `_beginthread` função cria um segmento que inicia a execução de uma rotina no *start_address*. A rotina *start_address* devem usar o `__cdecl` (para código nativo) ou `__clrcall` (para código gerenciado) convenção de chamada e não deve ter nenhum valor de retorno. Quando o thread retorna dessa rotina, ele é terminado automaticamente. Para obter mais informações sobre threads, consulte [Multithreading Support for Older Code (Visual C++)](../../parallel/multithreading-support-for-older-code-visual-cpp.md) [Suporte de multithreading para código mais antigo (Visual C++)].

`_beginthreadex` lembra mais a API [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453.aspx) do Win32 do que `_beginthread`. `_beginthreadex` é diferente de `_beginthread` nestes aspectos:

- `_beginthreadex` tem três parâmetros adicionais: *initflag*, *segurança*, e `threadaddr`. O novo thread pode ser criado em um estado suspenso, com segurança especificado e podem ser acessado usando *thrdaddr*, que é o identificador de thread.

- A rotina *start_address* que é passado para `_beginthreadex` devem usar o `__stdcall` (para código nativo) ou `__clrcall` (para código gerenciado) convenção de chamada e deve retornar um código de saída do thread.

- `_beginthreadex` retorna 0 em caso de falha, em vez de -1L.

- Um thread que é criado usando `_beginthreadex` é terminado por uma chamada para [_endthreadex](../../c-runtime-library/reference/endthread-endthreadex.md).

A função `_beginthreadex` proporciona mais controle do que a `_beginthread` sobre o método de criação do thread. A função `_endthreadex` também é mais flexível. Por exemplo, com a função `_beginthreadex`, você pode usar informações de segurança, definir o estado iniciado do thread (em execução ou suspenso) e obter o identificador do thread recém-criado. Você também pode usar o identificador de thread retornado por `_beginthreadex` com as APIs de sincronização, o que não é possível com a função `_beginthread`.

É mais seguro usar `_beginthreadex` do que `_beginthread`. Se o thread gerado por `_beginthread` surgir rapidamente, o indicador retornado para o chamador de `_beginthread` pode ser inválido ou apontar para outro thread. No entanto, o indicador retornado por `_beginthreadex` deve ser encerrado pelo chamador de `_beginthreadex`, para que ele seja válido se `_beginthreadex` não retornar um erro.

Você pode chamar [_endthread](../../c-runtime-library/reference/endthread-endthreadex.md) ou `_endthreadex` para terminar um thread explicitamente, no entanto, `_endthread` ou `_endthreadex` é chamado automaticamente quando o thread retorna da rotina que é passada como um parâmetro. Chamar a função `_endthread` ou `_endthreadex` para terminar um thread ajuda a garantir que os recursos alocados ao thread sejam devidamente recuperados.

A função `_endthread` fecha o identificador de thread automaticamente. Já a função `_endthreadex` não faz isso. Portanto, ao usar `_beginthread` e `_endthread`, não feche explicitamente o identificador de thread chamando a API [CloseHandle](http://msdn.microsoft.com/library/windows/desktop/ms724211.aspx) do Win32. Esse comportamento é diferente do comportamento da API [ExitThread](http://msdn.microsoft.com/library/windows/desktop/ms682659.aspx) do Win32.

> [!NOTE]  
> No caso de arquivos executáveis vinculados a Libcmt.lib, não chame a API `ExitThread` do Win32. Isso impede que o sistema do tempo de execução recupere os recursos alocados. As funções `_endthread` e `_endthreadex` recuperam os recursos alocados ao thread e chamam a API `ExitThread`.

O sistema operacional trata a alocação da pilha quando `_beginthread` ou `_beginthreadex` é chamado. Você não precisa informar o endereço da pilha de threads para uma dessas funções. Além disso, o *stack_size* argumento pode ser 0, nesse caso o sistema operacional usa o mesmo valor como a pilha especificada para o thread principal.

*arglist* é um parâmetro a ser passado para o thread recém-criado. Geralmente, trata-se do endereço de um item de dados, como uma cadeia de caracteres. *arglist* pode ser NULL se não for necessária, mas `_beginthread` e `_beginthreadex` deve ser fornecido um valor para passar para o novo thread. Todos os threads são terminados se o thread chamar `abort`, `exit`, `_exit` ou `ExitProcess`.

A localidade do thread novo é inicializada, usando as informações de localidade ' por processo global atual. Se a localidade por thread é ativada por uma chamada para [configthreadlocale](../../c-runtime-library/reference/configthreadlocale.md) (globalmente ou para novos threads somente), o thread pode alterar sua localidade independentemente de outros threads chamando `setlocale` ou `_wsetlocale`. Threads que não tem o sinalizador de localidade por thread definido podem afetar as informações de localidade em todos os outros threads que também não tem o sinalizador de localidade por thread definido, bem como todos os threads recém-criado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Código misto e puro, `_beginthread` e `_beginthreadex` cada uma tem duas sobrecargas. Um recebe um ponteiro de função de convenção de chamada nativa e o outro usa um `__clrcall` ponteiro de função. A primeira sobrecarga não é à prova de domínio do aplicativo e nunca será. Se estiver gravando códigos combinados ou puros, você deve garantir que o novo thread insira o domínio de aplicativo certo antes de acessar os recursos gerenciados. Você pode fazer isso, por exemplo, usando a [função call_in_appdomain](../../dotnet/call-in-appdomain-function.md). A segunda sobrecarga é à prova de domínio do aplicativo. O novo thread sempre terminará no domínio do aplicativo do chamador de `_beginthread` ou `_beginthreadex`.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_beginthread`|\<process.h>|
|`_beginthreadex`|\<process.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões multi-threaded da [biblioteca em tempo de execução do C](../../c-runtime-library/crt-library-features.md).

Para usar `_beginthread` ou `_beginthreadex`, o aplicativo deve vincular-se a uma das bibliotecas de tempo de execução C multithreaded.

## <a name="example"></a>Exemplo

Os exemplos a seguir usam `_beginthread` e `_endthread`.

```C
// crt_BEGTHRD.C
// compile with: /MT /D "_X86_" /c
// processor: x86
#include <windows.h>
#include <process.h>    /* _beginthread, _endthread */
#include <stddef.h>
#include <stdlib.h>
#include <conio.h>

void Bounce( void * );
void CheckKey( void * );

// GetRandom returns a random integer between min and max.
#define GetRandom( min, max ) ((rand() % (int)(((max) + 1) - (min))) + (min))
// GetGlyph returns a printable ASCII character value
#define GetGlyph( val ) ((char)((val + 32) % 93 + 33))

BOOL repeat = TRUE;                 // Global repeat flag 
HANDLE hStdOut;                     // Handle for console window
CONSOLE_SCREEN_BUFFER_INFO csbi;    // Console information structure

int main()
{
    int param = 0;
    int * pparam = &param;

    // Get display screen's text row and column information.
    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hStdOut, &csbi );

    // Launch CheckKey thread to check for terminating keystroke.
    _beginthread( CheckKey, 0, NULL );

    // Loop until CheckKey terminates program or 1000 threads created. 
    while( repeat && param < 1000 )
    {
        // launch another character thread.
        _beginthread( Bounce, 0, (void *) pparam );

        // increment the thread parameter
        param++;

        // Wait one second between loops.
        Sleep( 1000L );
    }
}

// CheckKey - Thread to wait for a keystroke, then clear repeat flag.
void CheckKey( void * ignored )
{
    _getch();
    repeat = 0;    // _endthread implied
}

// Bounce - Thread to create and and control a colored letter that moves
// around on the screen.
//
// Params: parg - the value to create the character from
void Bounce( void * parg )
{
    char       blankcell = 0x20;
    CHAR_INFO  ci;
    COORD      oldcoord, cellsize, origin;
    DWORD      result;
    SMALL_RECT region;

    cellsize.X = cellsize.Y = 1;
    origin.X = origin.Y = 0;

    // Generate location, letter and color attribute from thread argument.
    srand( _threadid );
    oldcoord.X = region.Left = region.Right = 
        GetRandom(csbi.srWindow.Left, csbi.srWindow.Right - 1);
    oldcoord.Y = region.Top = region.Bottom = 
        GetRandom(csbi.srWindow.Top, csbi.srWindow.Bottom - 1);
    ci.Char.AsciiChar = GetGlyph(*((int *)parg));
    ci.Attributes = GetRandom(1, 15);

    while (repeat)
    {
        // Pause between loops.
        Sleep( 100L );

        // Blank out our old position on the screen, and draw new letter.
        WriteConsoleOutputCharacterA(hStdOut, &blankcell, 1, oldcoord, &result);
        WriteConsoleOutputA(hStdOut, &ci, cellsize, origin, &region);

        // Increment the coordinate for next placement of the block.
        oldcoord.X = region.Left;
        oldcoord.Y = region.Top;
        region.Left = region.Right += GetRandom(-1, 1);
        region.Top = region.Bottom += GetRandom(-1, 1);

        // Correct placement (and beep) if about to go off the screen.
        if (region.Left < csbi.srWindow.Left)
            region.Left = region.Right = csbi.srWindow.Left + 1;
        else if (region.Right >= csbi.srWindow.Right)
            region.Left = region.Right = csbi.srWindow.Right - 2;
        else if (region.Top < csbi.srWindow.Top)
            region.Top = region.Bottom = csbi.srWindow.Top + 1;
        else if (region.Bottom >= csbi.srWindow.Bottom)
            region.Top = region.Bottom = csbi.srWindow.Bottom - 2;

        // If not at a screen border, continue, otherwise beep.
        else
            continue;
        Beep((ci.Char.AsciiChar - 'A') * 100, 175);
    }
    // _endthread given to terminate
    _endthread();
}
```

Pressione qualquer tecla para encerrar um aplicativo de exemplo.

## <a name="example"></a>Exemplo

O código de exemplo a seguir demonstra como você pode usar o identificador de thread retornado por `_beginthreadex`, com a API de sincronização [WaitForSingleObject](http://msdn.microsoft.com/library/windows/desktop/ms687032.aspx). O thread principal aguarda o segundo thread encerrar antes de continuar. Quando o segundo thread chama `_endthreadex`, o objeto do thread entra no estado sinalizado. Isso permite que o thread principal continue em execução. Não é possível fazer isso com `_beginthread` e `_endthread` porque `_endthread` chama `CloseHandle`, que destrói o objeto do thread antes que ele seja definido no estado sinalizado.

```cpp
// crt_begthrdex.cpp
// compile with: /MT
#include <windows.h>
#include <stdio.h>
#include <process.h>

unsigned Counter; 
unsigned __stdcall SecondThreadFunc( void* pArguments )
{
    printf( "In second thread...\n" );

    while ( Counter < 1000000 )
        Counter++;

    _endthreadex( 0 );
    return 0;
}

int main()
{
    HANDLE hThread;
    unsigned threadID;

    printf( "Creating second thread...\n" );

    // Create the second thread.
    hThread = (HANDLE)_beginthreadex( NULL, 0, &SecondThreadFunc, NULL, 0, &threadID );

    // Wait until second thread terminates. If you comment out the line
    // below, Counter will not be correct because the thread has not
    // terminated, and Counter most likely has not been incremented to
    // 1000000 yet.
    WaitForSingleObject( hThread, INFINITE );
    printf( "Counter should be 1000000; it is-> %d\n", Counter );
    // Destroy the thread object.
    CloseHandle( hThread );
}
```

```Output
Creating second thread...
In second thread...
Counter should be 1000000; it is-> 1000000
```

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[_endthread, _endthreadex](../../c-runtime-library/reference/endthread-endthreadex.md)<br/>
[abort](../../c-runtime-library/reference/abort.md)<br/>
[exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)<br/>
[GetExitCodeThread](http://msdn.microsoft.com/library/windows/desktop/ms683190)<br/>
