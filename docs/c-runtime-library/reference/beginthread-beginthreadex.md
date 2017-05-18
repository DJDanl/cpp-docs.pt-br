---
title: _beginthread, _beginthreadex | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 36
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 3c556e6460f1a39bab23f2612cbf820e284d7605
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="beginthread-beginthreadex"></a>_beginthread, _beginthreadex
Cria um thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
  
#### <a name="parameters"></a>Parâmetros  
 `start_address`  
 Endereço inicial de uma rotina que inicia a execução de um novo thread. Para `_beginthread`, a convenção de chamada é [__cdecl](../../cpp/cdecl.md) (para código nativo) ou [__clrcall](../../cpp/clrcall.md) (para código gerenciado); para `_beginthreadex`, é [__stdcall](../../cpp/stdcall.md) (para código nativo) ou [__clrcall](../../cpp/clrcall.md) (para código gerenciado).  
  
 `stack_size`  
 Tamanho da pila para um novo thread ou 0.  
  
 `arglist`  
 Lista de argumentos a ser apresentada a um novo thread ou NULL.  
  
 `Security`  
 Ponteiro para uma estrutura [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) que determina se o identificador retornado pode ser herdado por processos filhos. Se `Security` for NULL, o indicador não poderá ser herdado. Deve ser NULL para aplicativos Windows 95.  
  
 `initflag`  
 Sinalizadores que controlam o estado inicial de um novo thread. Defina `initflag` como `0` para executar imediatamente ou como `CREATE_SUSPENDED` para criar o thread em um estado suspenso. Use [ResumeThread](http://msdn.microsoft.com/library/windows/desktop/ms685086.aspx) para executar o thread. Defina `initflag` com o sinalizador `STACK_SIZE_PARAM_IS_A_RESERVATION` para usar `stack_size` como tamanho de reserva inicial da pilha em bytes; se esse sinalizador não for especificado, `stack_size` especifica o tamanho da confirmação.  
  
 `thrdaddr`  
 Aponta para uma variável de 32 bits que recebe o identificador de thread. Se o valor for NULL, esse parâmetro não é usado.  
  
## <a name="return-value"></a>Valor de retorno  
 Em caso de êxito, cada uma dessas funções retorna um indicador para o thread novo. No entanto, se esse novo thread surgir muito rápido, `_beginthread` pode não retornar um indicador válido. Confira a discussão na sessão Observações. Em caso de erro, `_beginthread` retorna -1L e `errno` é definido como `EAGAIN` se houver muitos threads para `EINVAL` se o argumento for inválido ou o tamanho da pilha estiver incorreto, ou para `EACCES` se não houver recursos suficientes (como memória). Em caso de erro, `_beginthreadex` retorna 0 e `errno` e `_doserrno` são definidos.  
  
 Se `startaddress` for NULL, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão -1.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Para obter mais informações sobre `uintptr_t`, consulte [Tipos padrão](../../c-runtime-library/standard-types.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_beginthread` cria um thread que inicia a execução de uma rotina em `start_address`. A rotina em `start_address` deve usar a convenção de chamadas `__cdecl` (para código nativo) ou `__clrcall` (para código gerenciado) e não apresentar valor retornado. Quando o thread retorna dessa rotina, ele é terminado automaticamente. Para obter mais informações sobre threads, consulte [Multithreading Support for Older Code (Visual C++)](../../parallel/multithreading-support-for-older-code-visual-cpp.md) [Suporte de multithreading para código mais antigo (Visual C++)].  
  
 `_beginthreadex` lembra mais a API [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453.aspx) do Win32 do que `_beginthread`. `_beginthreadex` é diferente de `_beginthread` nestes aspectos:  
  
-   `_beginthreadex` tem três parâmetros adicionais: `initflag`, `security` e `threadaddr`. O novo thread pode ser criado em estado suspenso, com a segurança especificada, e pode ser acessado com uso de `thrdaddr`, que é o identificador do thread.  
  
-   A rotina em `start_address`, que é informada a `_beginthreadex`, deve usar a convenção de chamadas `__stdcall` (para código nativo) ou `__clrcall` (para código gerenciado) e retornar um código de saída do thread.  
  
-   `_beginthreadex` retorna 0 em caso de falha, em vez de -1L.  
  
-   Um thread que é criado usando `_beginthreadex` é terminado por uma chamada para [_endthreadex](../../c-runtime-library/reference/endthread-endthreadex.md).  
  
 A função `_beginthreadex` proporciona mais controle do que a `_beginthread` sobre o método de criação do thread. A função `_endthreadex` também é mais flexível. Por exemplo, com a função `_beginthreadex`, você pode usar informações de segurança, definir o estado iniciado do thread (em execução ou suspenso) e obter o identificador do thread recém-criado. Você também pode usar o identificador de thread retornado por `_beginthreadex` com as APIs de sincronização, o que não é possível com a função `_beginthread`.  
  
 É mais seguro usar `_beginthreadex` do que `_beginthread`. Se o thread gerado por `_beginthread` surgir rapidamente, o indicador retornado para o chamador de `_beginthread` pode ser inválido ou apontar para outro thread. No entanto, o indicador retornado por `_beginthreadex` deve ser encerrado pelo chamador de `_beginthreadex`, para que ele seja válido se `_beginthreadex` não retornar um erro.  
  
 Você pode chamar [_endthread](../../c-runtime-library/reference/endthread-endthreadex.md) ou `_endthreadex` para terminar um thread explicitamente, no entanto, `_endthread` ou `_endthreadex` é chamado automaticamente quando o thread retorna da rotina que é passada como um parâmetro. Chamar a função `_endthread` ou `_endthreadex` para terminar um thread ajuda a garantir que os recursos alocados ao thread sejam devidamente recuperados.  
  
 A função `_endthread` fecha o identificador de thread automaticamente. Já a função `_endthreadex` não faz isso. Portanto, ao usar `_beginthread` e `_endthread`, não feche explicitamente o identificador de thread chamando a API [CloseHandle](http://msdn.microsoft.com/library/windows/desktop/ms724211.aspx) do Win32. Esse comportamento é diferente do comportamento da API [ExitThread](http://msdn.microsoft.com/library/windows/desktop/ms682659.aspx) do Win32.  
  
> [!NOTE]
>  No caso de arquivos executáveis vinculados a Libcmt.lib, não chame a API `ExitThread` do Win32. Isso impede que o sistema do tempo de execução recupere os recursos alocados. As funções `_endthread` e `_endthreadex` recuperam os recursos alocados ao thread e chamam a API `ExitThread`.  
  
 O sistema operacional trata a alocação da pilha quando `_beginthread` ou `_beginthreadex` é chamado. Você não precisa informar o endereço da pilha de threads para uma dessas funções. Além disso, o argumento `stack_size` pode ser 0. Nesse caso, o sistema operacional usa o mesmo valor da pilha especificada para o thread principal.  
  
 `arglist` é um parâmetro a ser informado no thread recém-criado. Geralmente, trata-se do endereço de um item de dados, como uma cadeia de caracteres. `arglist` pode ser NULL se esse valor não for necessário, mas `_beginthread` e `_beginthreadex` devem ter outros valores para apresentar ao novo thread. Todos os threads são terminados se o thread chamar `abort`, `exit`, `_exit` ou `ExitProcess`.  
  
 A localidade do novo thread é herdada do thread pai. Se a localidade por thread for habilitada por uma chamada para [_configthreadlocale](../../c-runtime-library/reference/configthreadlocale.md) (globalmente ou somente para novos threads), o thread poderá alterar sua localidade independentemente de seu pai, chamando `setlocale` ou `_wsetlocale`. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Para obter códigos combinados e puros, `_beginthread` e `_beginthreadex` têm duas sobrecargas. Uma delas usa um ponteiro de funções de convenção de chamadas nativo. A outra usa um ponteiro da função `__clrcall`. A primeira sobrecarga não é à prova de domínio do aplicativo e nunca será. Se estiver gravando códigos combinados ou puros, você deve garantir que o novo thread insira o domínio de aplicativo certo antes de acessar os recursos gerenciados. Você pode fazer isso, por exemplo, usando a [função call_in_appdomain](../../dotnet/call-in-appdomain-function.md). A segunda sobrecarga é à prova de domínio do aplicativo. O novo thread sempre terminará no domínio do aplicativo do chamador de `_beginthread` ou `_beginthreadex`.  
  
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
  
```  
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
  
```  
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
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [_endthread, _endthreadex](../../c-runtime-library/reference/endthread-endthreadex.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [GetExitCodeThread](http://msdn.microsoft.com/library/windows/desktop/ms683190)
