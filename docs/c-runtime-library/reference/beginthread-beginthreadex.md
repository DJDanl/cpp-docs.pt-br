---
title: _beginthread, _beginthreadex
ms.date: 02/27/2018
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
helpviewer_keywords:
- _beginthread function
- threading [C++], creating threads
- beginthreadex function
- _beginthreadex function
- beginthread function
ms.assetid: 0df64740-a978-4358-a88f-fb0702720091
ms.openlocfilehash: f64fd7b945fc8ea2e5c111d300266e07faade0e7
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66504520"
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
Endereço inicial de uma rotina que inicia a execução de um novo thread. Para **beginthread**, a convenção de chamada é [cdecl](../../cpp/cdecl.md) (para código nativo) ou [clrcall](../../cpp/clrcall.md) (para código gerenciado); para **beginthreadex**, ela está [stdcall](../../cpp/stdcall.md) (para código nativo) ou [clrcall](../../cpp/clrcall.md) (para código gerenciado).

*stack_size*<br/>
Tamanho da pila para um novo thread ou 0.

*arglist*<br/>
Lista de argumentos a serem passados para um novo thread, ou **nulo**.

*Segurança*<br/>
Ponteiro para uma estrutura [SECURITY_ATTRIBUTES](/previous-versions/windows/desktop/legacy/aa379560\(v=vs.85\)) que determina se o identificador retornado pode ser herdado por processos filhos. Se *segurança* é **nulo**, o identificador não pode ser herdado. Deve ser **nulo** para aplicativos do Windows 95.

*initflag*<br/>
Sinalizadores que controlam o estado inicial de um novo thread. Definir *initflag* como 0 para executar imediatamente, ou a **CREATE_SUSPENDED** para criar o thread em um estado suspenso; use [ResumeThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-resumethread) para executar o thread. Definir *initflag* à **STACK_SIZE_PARAM_IS_A_RESERVATION** sinalizador usar *stack_size* conforme o tamanho da pilha em bytes de reserva inicial; se esse sinalizador é não especificado, *stack_size* Especifica o tamanho de confirmação.

*thrdaddr*<br/>
Aponta para uma variável de 32 bits que recebe o identificador de thread. Se ele estiver **nulo**, ele não é usado.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, cada uma dessas funções retorna um identificador para o thread recém-criado. No entanto, se o novo thread surgir muito rápido, **beginthread** podem não retornar um identificador válido. Confira a discussão na sessão Observações. Em um erro **beginthread** retorna-1l e **errno** está definido como **EAGAIN** se houver muitos threads, como **EINVAL** se o argumento for inválido ou o tamanho da pilha estiver incorreto, ou para **EACCES** se não houver recursos insuficientes (como memória). Em um erro **beginthreadex** retorna 0, e **errno** e **doserrno** são definidos.

Se *start_address* é **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e retornarão -1.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Para obter mais informações sobre **uintptr_t**, consulte [tipos padrão](../../c-runtime-library/standard-types.md).

## <a name="remarks"></a>Comentários

O **beginthread** função cria um thread que inicia a execução de uma rotina em *start_address*. A rotina em *start_address* deve usar o **cdecl** (para código nativo) ou **clrcall** (para código gerenciado) convenção de chamada e não deve ter nenhum valor de retorno. Quando o thread retorna dessa rotina, ele é terminado automaticamente. Para obter mais informações sobre threads, consulte [Multithreading Support for Older Code (Visual C++)](../../parallel/multithreading-support-for-older-code-visual-cpp.md) [Suporte de multithreading para código mais antigo (Visual C++)].

**beginthreadex** é semelhante do Win32 [CreateThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) API mais perto que **beginthread** faz. **beginthreadex** difere **beginthread** das seguintes maneiras:

- **beginthreadex** tem três parâmetros adicionais: *initflag*, *segurança*, e **threadaddr**. O novo thread pode ser criado em um estado suspenso, com a segurança especificada e pode ser acessado por meio *thrdaddr*, que é o identificador de thread.

- A rotina em *start_address* que é passado para **beginthreadex** devem usar o **stdcall** (para código nativo) ou **clrcall** (para o código gerenciado) convenção de chamada e deve retornar um código de saída de thread.

- **beginthreadex** retorna 0 em falha, em vez de-1l.

- Um thread que é criado usando **beginthreadex** é encerrado por uma chamada para [endthreadex](endthread-endthreadex.md).

O **beginthreadex** função permite que você mais controle sobre como o thread é criado que **beginthread** faz. O **endthreadex** função também é mais flexível. Por exemplo, com **beginthreadex**, você pode usar informações de segurança, definir o estado inicial do thread (em execução ou suspenso) e obter o identificador de thread do thread recém-criado. Você também pode usar o identificador de thread retornado por **beginthreadex** com as APIs de sincronização, que não pode ser feito com **beginthread**.

Ele é mais seguro usar **beginthreadex** que **beginthread**. Se o thread que é gerado pelo **beginthread** surgir rapidamente, o que é retornado ao chamador do identificador **beginthread** pode ser inválido ou apontar para outro thread. No entanto, o identificador retornado pela **beginthreadex** deve ser encerrado pelo chamador da **beginthreadex**, portanto, é garantido para ser um identificador válido, se **beginthreadex** não retornou um erro.

Você pode chamar [endthread](endthread-endthreadex.md) ou **endthreadex** explicitamente para terminar um thread; no entanto, **endthread** ou **endthreadex** é chamado automaticamente quando o thread volta da rotina que é passada como um parâmetro. Encerrar um thread com uma chamada para **endthread** ou **endthreadex** ajuda a garantir que a recuperação correta de recursos são alocados para o thread.

**endthread** fecha automaticamente o identificador de thread, enquanto **endthreadex** não faz isso. Portanto, quando você usa **beginthread** e **endthread**, não feche explicitamente o identificador de thread chamando Win32 [CloseHandle](/windows/desktop/api/handleapi/nf-handleapi-closehandle) API. Esse comportamento é diferente do comportamento da API [ExitThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) do Win32.

> [!NOTE]
> Arquivos executáveis vinculados a libcmt. lib, não chame Win32 **ExitThread** API para que você não impedir que o sistema de tempo de execução recupere recursos alocados. **endthread** e **endthreadex** recuperar os recursos alocados ao thread e, em seguida, chame **ExitThread**.

O sistema operacional trata a alocação da pilha quando qualquer um dos **beginthread** ou **beginthreadex** é chamado; você não precisa passar o endereço da pilha do thread a uma dessas funções. Além disso, o *stack_size* argumento pode ser 0, nesse caso o sistema operacional usa o mesmo valor da pilha é especificado para o thread principal.

*arglist* é um parâmetro a ser passado para o thread recém-criado. Geralmente, trata-se do endereço de um item de dados, como uma cadeia de caracteres. *arglist* pode ser **nulo** se não for necessária, mas **beginthread** e **beginthreadex** deve ser fornecido um valor para passar para o novo thread. Todos os threads são terminados se o thread chama [anular](abort.md), **sair**, **exit**, ou **ExitProcess**.

A localidade do thread novo é inicializada usando as informações de localidade ' por processo global atual. Se a localidade por thread é habilitada por uma chamada para [configthreadlocale](configthreadlocale.md) (globalmente ou para novos threads somente), o thread pode alterar sua localidade independentemente de outros threads chamando **setlocale** ou **wsetlocale**. Threads que não têm o sinalizador de localidade por thread definido podem afetar as informações de localidade em todos os outros threads que também não têm o sinalizador de localidade por thread definido, bem como todos os threads recém-criado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Para **/clr** código, **beginthread** e **beginthreadex** têm duas sobrecargas. Uma usa um ponteiro de função de convenção de chamada nativa, e o outro usa um **clrcall** ponteiro de função. A primeira sobrecarga não é à prova de domínio do aplicativo e nunca será. Se você estiver escrevendo **/clr** código, você deve garantir que o novo thread insira o domínio de aplicativo correto antes de acessar os recursos gerenciados. Você pode fazer isso, por exemplo, usando a [função call_in_appdomain](../../dotnet/call-in-appdomain-function.md). A segunda sobrecarga é à prova de domínio; do aplicativo o thread recém-criado sempre terminará no domínio do aplicativo do chamador do **beginthread** ou **beginthreadex**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_beginthread**|\<process.h>|
|**_beginthreadex**|\<process.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões multi-threaded da [biblioteca em tempo de execução do C](../../c-runtime-library/crt-library-features.md).

Para usar **beginthread** ou **beginthreadex**, o aplicativo deve ser vinculado a uma das bibliotecas de tempo de execução C multithreaded.

## <a name="example"></a>Exemplo

O exemplo a seguir usa **beginthread** e **endthread**.

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

O código de exemplo a seguir demonstra como você pode usar o identificador de thread retornado por **beginthreadex** com a API de sincronização [WaitForSingleObject](/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject). O thread principal aguarda o segundo thread encerrar antes de continuar. Quando o segundo thread chama **endthreadex**, faz com que seu objeto de thread ir para o estado sinalizado. Isso permite que o thread principal continue em execução. Isso não pode ser feito com **beginthread** e **endthread**, pois **endthread** chamadas **CloseHandle**, que destrói o thread objeto antes que ele pode ser definido para o estado sinalizado.

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

- [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)
- [_endthread, _endthreadex](endthread-endthreadex.md)
- [abort](abort.md)
- [exit, _Exit, _exit](exit-exit-exit.md)
- [GetExitCodeThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getexitcodethread)
