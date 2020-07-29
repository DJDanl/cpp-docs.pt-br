---
title: _beginthread, _beginthreadex
ms.date: 4/2/2020
api_name:
- _beginthread
- _beginthreadex
- _o__beginthread
- _o__beginthreadex
api_location:
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- beginthread
- _beginthread
- beginthreadex
- _beginthreadex
helpviewer_keywords:
- _beginthread function
- threading [C++], creating threads
- beginthreadex function
- _beginthreadex function
- beginthread function
ms.assetid: 0df64740-a978-4358-a88f-fb0702720091
ms.openlocfilehash: 29458f2d752f1fe59778b752480e268f8243f15e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234270"
---
# <a name="_beginthread-_beginthreadex"></a>_beginthread, _beginthreadex

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

### <a name="parameters"></a>parâmetros

*start_address*<br/>
Endereço inicial de uma rotina que inicia a execução de um novo thread. Por **_beginthread**, a Convenção de chamada é [__cdecl](../../cpp/cdecl.md) (para código nativo) ou [__clrcall](../../cpp/clrcall.md) (para código gerenciado); por **_beginthreadex**, ele é [__stdcall](../../cpp/stdcall.md) (para código nativo) ou [__clrcall](../../cpp/clrcall.md) (para código gerenciado).

*stack_size*<br/>
Tamanho da pila para um novo thread ou 0.

*Arglist*<br/>
Lista de argumentos a ser passada para um novo thread ou **NULL**.

*Segurança*<br/>
Ponteiro para uma estrutura [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que determina se o identificador retornado pode ser herdado por processos filhos. Se a *segurança* for **nula**, o identificador não poderá ser herdado. Deve ser **nulo** para aplicativos do Windows 95.

*initflag*<br/>
Sinalizadores que controlam o estado inicial de um novo thread. Defina *initflag* como 0 para ser executado imediatamente ou para **CREATE_SUSPENDED** para criar o thread em um estado suspenso; Use [ResumeThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-resumethread) para executar o thread. Defina *initflag* como **STACK_SIZE_PARAM_IS_A_RESERVATION** sinalizador para usar *stack_size* como o tamanho de reserva inicial da pilha em bytes; Se esse sinalizador não for especificado, *stack_size* especificará o tamanho da confirmação.

*thrdaddr*<br/>
Aponta para uma variável de 32 bits que recebe o identificador de thread. Se for **nulo**, ele não será usado.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedida, cada uma dessas funções retornará um identificador para o thread recém-criado; no entanto, se o thread recém-criado sair muito rapidamente, **_beginthread** poderá não retornar um identificador válido. (Consulte a discussão na seção comentários.) Em um erro, **_beginthread** retornará-1L e **errno** será definido como **EAGAIN** se houver muitos threads, para **EINVAL** se o argumento for inválido ou se o tamanho da pilha estiver incorreto, ou para **EACCES** se houver recursos insuficientes (como memória). Em um erro, **_beginthreadex** retorna 0 e **errno** e **_doserrno** são definidos.

Se *start_address* for **NULL**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definem **errno** como **EINVAL** e retornam-1.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter mais informações sobre **uintptr_t**, consulte [tipos padrão](../../c-runtime-library/standard-types.md).

## <a name="remarks"></a>Comentários

A função **_beginthread** cria um thread que inicia a execução de uma rotina em *start_address*. A rotina em *start_address* deve usar a **`__cdecl`** Convenção de chamada (para código nativo) ou **__clrcall** (para código gerenciado) e não deve ter nenhum valor de retorno. Quando o thread retorna dessa rotina, ele é terminado automaticamente. Para obter mais informações sobre threads, consulte [Multithreading Support for Older Code (Visual C++)](../../parallel/multithreading-support-for-older-code-visual-cpp.md) [Suporte de multithreading para código mais antigo (Visual C++)].

**_beginthreadex** assemelha-se à API [CreateThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread) do Win32 mais próxima do que **_beginthread** . **_beginthreadex** difere de **_beginthread** das seguintes maneiras:

- **_beginthreadex** tem três parâmetros adicionais: *initflag*, *Security*e **threadaddr**. O novo thread pode ser criado em um estado suspenso, com uma segurança especificada, e pode ser acessado usando *thrdaddr*, que é o identificador de thread.

- A rotina em *start_address* que é passada para **_beginthreadex** deve usar a **`__stdcall`** Convenção de chamada (para código nativo) ou **__clrcall** (para código gerenciado) e deve retornar um código de saída de thread.

- **_beginthreadex** retorna 0 em caso de falha, em vez de-1L.

- Um thread criado usando **_beginthreadex** é encerrado por uma chamada para [_endthreadex](endthread-endthreadex.md).

A função **_beginthreadex** fornece mais controle sobre como o thread é criado do que **_beginthread** . A função **_endthreadex** também é mais flexível. Por exemplo, com **_beginthreadex**, você pode usar informações de segurança, definir o estado inicial do thread (em execução ou suspenso) e obter o identificador de thread do thread recém-criado. Você também pode usar o identificador de thread que é retornado por **_beginthreadex** com as APIs de sincronização, que você não pode fazer com **_beginthread**.

É mais seguro usar **_beginthreadex** do que **_beginthread**. Se o thread gerado pelo **_beginthread** for fechado rapidamente, o identificador retornado para o chamador de **_beginthread** poderá ser inválido ou apontar para outro thread. No entanto, o identificador retornado pelo **_beginthreadex** deve ser fechado pelo chamador de **_beginthreadex**, portanto, é garantido que seja um identificador válido se **_beginthreadex** não retornar um erro.

Você pode chamar [_endthread](endthread-endthreadex.md) ou **_endthreadex** explicitamente para encerrar um thread; no entanto, **_endthread** ou **_endthreadex** é chamado automaticamente quando o thread retorna da rotina que é passada como um parâmetro. Encerrar um thread com uma chamada para **_endthread** ou **_endthreadex** ajuda a garantir a recuperação correta de recursos alocados para o thread.

**_endthread** fecha automaticamente o identificador de thread, enquanto **_endthreadex** não. Portanto, quando você usa **_beginthread** e **_endthread**, não feche explicitamente o identificador de thread chamando a API [CloseHandle](/windows/win32/api/handleapi/nf-handleapi-closehandle) do Win32. Esse comportamento é diferente do comportamento da API [ExitThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread) do Win32.

> [!NOTE]
> Para um arquivo executável vinculado a LIBCMT. lib, não chame a API do Win32 **ExitThread** para que você não impeça que o sistema de tempo de execução recupere recursos alocados. **_endthread** e **_endthreadex** recuperar recursos de thread alocados e, em seguida, chamar **ExitThread**.

O sistema operacional manipula a alocação da pilha quando o **_beginthread** ou **_beginthreadex** é chamado; Você não precisa passar o endereço da pilha de threads para uma dessas funções. Além disso, o argumento *stack_size* pode ser 0. nesse caso, o sistema operacional usa o mesmo valor que a pilha especificada para o thread principal.

*Arglist* é um parâmetro a ser passado para o thread recém-criado. Geralmente, trata-se do endereço de um item de dados, como uma cadeia de caracteres. *Arglist* pode ser **nulo** se não for necessário, mas **_beginthread** e **_beginthreadex** devem receber algum valor para passar para o novo thread. Todos os threads serão encerrados se qualquer thread chamar [abortar](abort.md), **sair**, **_exit**ou **ExitProcess**.

A localidade do novo thread é inicializada usando as informações de localidade atual global por processo. Se a localidade por thread for habilitada por uma chamada para [_configthreadlocale](configthreadlocale.md) (globalmente ou para novos threads somente), o thread poderá alterar sua localidade independentemente de outros threads chamando **setlocale** ou **_wsetlocale**. Os threads que não têm o sinalizador de localidade por thread definido podem afetar as informações de localidade em todos os outros threads que também não têm o sinalizador de localidade por thread definido, bem como todos os threads recém-criados. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Para o código **/CLR** , **_beginthread** e **_beginthreadex** têm duas sobrecargas. Uma usa um ponteiro de função de Convenção de chamada nativa e o outro usa um ponteiro de função **__clrcall** . A primeira sobrecarga não é à prova de domínio do aplicativo e nunca será. Se você estiver escrevendo um código **/CLR** , deverá garantir que o novo thread Insira o domínio do aplicativo correto antes de acessar os recursos gerenciados. Você pode fazer isso, por exemplo, usando a [função call_in_appdomain](../../dotnet/call-in-appdomain-function.md). A segunda sobrecarga é o aplicativo de domínio-seguro; o thread recém-criado sempre terminará no domínio do aplicativo do chamador de **_beginthread** ou **_beginthreadex**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_beginthread**|\<process.h>|
|**_beginthreadex**|\<process.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Somente versões multi-threaded da [biblioteca em tempo de execução do C](../../c-runtime-library/crt-library-features.md).

Para usar **_beginthread** ou **_beginthreadex**, o aplicativo deve vincular-se a uma das bibliotecas de tempo de execução de C multi-threaded.

## <a name="example"></a>Exemplo

O exemplo a seguir usa **_beginthread** e **_endthread**.

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

// Bounce - Thread to create and control a colored letter that moves
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

O código de exemplo a seguir demonstra como você pode usar o identificador de thread que é retornado por **_beginthreadex** com a API de sincronização [WaitForSingleObject](/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject). O thread principal aguarda o segundo thread encerrar antes de continuar. Quando o segundo thread chama **_endthreadex**, ele faz com que seu objeto de thread vá para o estado sinalizado. Isso permite que o thread principal continue em execução. Isso não pode ser feito com **_beginthread** e **_endthread**, porque **_endthread** chama **CloseHandle**, que destrói o objeto de thread antes que ele possa ser definido como o estado sinalizado.

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

## <a name="see-also"></a>Confira também

- [Controle de processo e ambiente](../../c-runtime-library/process-and-environment-control.md)
- [_endthread, _endthreadex](endthread-endthreadex.md)
- [abort](abort.md)
- [exit, _Exit, _exit](exit-exit-exit.md)
- [GetExitCodeThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodethread)
