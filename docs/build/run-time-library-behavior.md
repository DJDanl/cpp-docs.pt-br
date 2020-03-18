---
title: Comportamento de DLLs C++ e da biblioteca de tempo de execução Visual
ms.date: 08/19/2019
f1_keywords:
- _DllMainCRTStartup
- CRT_INIT
helpviewer_keywords:
- DLLs [C++], entry point function
- process detach [C++]
- process attach [C++]
- DLLs [C++], run-time library behavior
- DllMain function
- _CRT_INIT macro
- _DllMainCRTStartup method
- run-time [C++], DLL startup sequence
- DLLs [C++], startup sequence
ms.assetid: e06f24ab-6ca5-44ef-9857-aed0c6f049f2
ms.openlocfilehash: 572a0ba70c1ba2d46d2d9fd6d8ac543a77bbbc01
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417309"
---
# <a name="dlls-and-visual-c-run-time-library-behavior"></a>Comportamento de DLLs C++ e da biblioteca de tempo de execução Visual

Quando você cria uma DLL (biblioteca de vínculo dinâmico) usando o Visual Studio, por padrão, o vinculador inclui a VCRuntime C++ (biblioteca de tempo de execução) Visual. O VCRuntime contém o código necessário para inicializar e encerrar um CC++ /executável. Quando vinculado a uma DLL, o código VCRuntime fornece uma função de ponto de entrada de DLL interna chamada `_DllMainCRTStartup` que manipula mensagens do sistema operacional Windows à DLL para anexar ou desanexar de um processo ou thread. A função `_DllMainCRTStartup` executa tarefas essenciais, como configuração de segurança de buffer de pilha configurada, inicialização e terminação de CRT (biblioteca de tempo de execução) e chamadas para construtores e destruidores para objetos estáticos e globais. `_DllMainCRTStartup` também chama funções de gancho para outras bibliotecas, como WinRT, MFC e ATL para executar sua própria inicialização e encerramento. Sem essa inicialização, a CRT e outras bibliotecas, bem como suas variáveis estáticas, seriam deixadas em um estado não inicializado. As mesmas rotinas de inicialização e terminação interna do VCRuntime são chamadas se sua DLL usa um CRT vinculado estaticamente ou uma DLL CRT vinculada dinamicamente.

## <a name="default-dll-entry-point-_dllmaincrtstartup"></a>Ponto de entrada DLL padrão _DllMainCRTStartup

No Windows, todas as DLLs podem conter uma função de ponto de entrada opcional, geralmente chamada de `DllMain`, que é chamada para inicialização e encerramento. Isso lhe dá a oportunidade de alocar ou liberar recursos adicionais, conforme necessário. O Windows chama a função de ponto de entrada em quatro situações: processo anexar, desanexar processo, anexar thread e desanexar thread. Quando uma DLL é carregada em um espaço de endereço de processo, quando um aplicativo que o usa é carregado ou quando o aplicativo solicita a DLL em tempo de execução, o sistema operacional cria uma cópia separada dos dados da DLL. Isso é chamado de *anexo de processo*. A *anexação de thread* ocorre quando o processo em que a dll é carregada cria um novo thread. A *desanexação de thread* ocorre quando o thread é encerrado e o *processo de desanexação* é quando a dll não é mais necessária e é liberada por um aplicativo. O sistema operacional faz uma chamada separada para o ponto de entrada de DLL para cada um desses eventos, passando um argumento de *motivo* para cada tipo de evento. Por exemplo, o sistema operacional envia `DLL_PROCESS_ATTACH` como o argumento de *motivo* para sinalizar a anexação de processo.

A biblioteca VCRuntime fornece uma função de ponto de entrada chamada `_DllMainCRTStartup` para manipular operações de inicialização e término padrão. Na anexação de processo, a função `_DllMainCRTStartup` configura verificações de segurança de buffer, inicializa o CRT e outras bibliotecas, inicializa informações de tipo em tempo de execução, inicializa e chama construtores para dados estáticos e não locais, inicializa o armazenamento local de thread, incrementa um contador estático interno para cada anexo e, em seguida, chama um `DllMain`fornecido pelo usuário ou biblioteca. Na desanexação do processo, a função passa por essas etapas na ordem inversa. Ele chama `DllMain`, Decrementa o contador interno, chama destruidores, chama funções de encerramento de CRT e funções de `atexit` registradas e notifica quaisquer outras bibliotecas de encerramento. Quando o contador de anexos chega a zero, a função retorna `FALSE` para indicar ao Windows que a DLL pode ser descarregada. A função `_DllMainCRTStartup` também é chamada durante anexação de thread e desanexação de thread. Nesses casos, o código VCRuntime não faz inicialização ou encerramento adicional por conta própria e apenas chama `DllMain` para passar a mensagem. Se `DllMain` retornar `FALSE` da anexação do processo, sinalizar falha, `_DllMainCRTStartup` chamadas `DllMain` novamente e passar `DLL_PROCESS_DETACH` como o argumento de *motivo* , passará pelo restante do processo de encerramento.

Ao criar DLLs no Visual Studio, o ponto de entrada padrão `_DllMainCRTStartup` fornecido pelo VCRuntime é vinculado automaticamente. Você não precisa especificar uma função de ponto de entrada para sua DLL usando a opção de vinculador [/Entry (símbolo de ponto de entrada)](reference/entry-entry-point-symbol.md) .

> [!NOTE]
> Embora seja possível especificar outra função de ponto de entrada para uma DLL usando a opção/ENTRY: linker, não é recomendável, porque sua função de ponto de entrada teria que duplicar tudo o que `_DllMainCRTStartup` faz, na mesma ordem. O VCRuntime fornece funções que permitem que você duplique seu comportamento. Por exemplo, você pode chamar [__security_init_cookie](../c-runtime-library/reference/security-init-cookie.md) imediatamente na anexação de processo para dar suporte à opção de verificação de buffer [/GS (verificação de segurança de buffer)](reference/gs-buffer-security-check.md) . Você pode chamar a função `_CRT_INIT`, passando os mesmos parâmetros que a função de ponto de entrada, para executar o restante das funções de inicialização ou terminação de DLL.

<a name="initializing-a-dll"></a>

## <a name="initialize-a-dll"></a>Inicializar uma DLL

Sua DLL pode ter código de inicialização que deve ser executado quando a DLL é carregada. Para que você execute suas próprias funções de inicialização e encerramento de DLL, `_DllMainCRTStartup` chama uma função chamada `DllMain` que você pode fornecer. Seu `DllMain` deve ter a assinatura necessária para um ponto de entrada de DLL. A função de ponto de entrada padrão `_DllMainCRTStartup` chama `DllMain` usando os mesmos parâmetros passados pelo Windows. Por padrão, se você não fornecer uma função `DllMain`, o Visual Studio fornecerá uma para você e a vinculará para que `_DllMainCRTStartup` sempre tenha algo a ser chamado. Isso significa que, se você não precisar inicializar a DLL, não há nada de especial que você precise fazer ao compilar sua DLL.

Esta é a assinatura usada para `DllMain`:

```cpp
#include <windows.h>

extern "C" BOOL WINAPI DllMain (
    HINSTANCE const instance,  // handle to DLL module
    DWORD     const reason,    // reason for calling function
    LPVOID    const reserved); // reserved
```

Algumas bibliotecas encapsulam a função `DllMain` para você. Por exemplo, em uma DLL de MFC regular, implemente o `InitInstance` do objeto de `CWinApp` e `ExitInstance` funções de membro para executar a inicialização e o encerramento exigidos por sua DLL. Para obter mais detalhes, consulte a seção [inicializar DLLs regulares do MFC](#initializing-regular-dlls) .

> [!WARNING]
> Há limites significativos no que você pode fazer com segurança em um ponto de entrada de DLL. Consulte [práticas recomendadas gerais](/windows/win32/Dlls/dynamic-link-library-best-practices) para APIs específicas do Windows que não são seguras para chamar em `DllMain`. Se você precisar de qualquer coisa, exceto a inicialização mais simples, faça isso em uma função de inicialização para a DLL. Você pode exigir que os aplicativos chamem a função de inicialização depois que `DllMain` tiver sido executado e antes de chamar qualquer outra função na DLL.

<a name="initializing-non-mfc-dlls"></a>

### <a name="initialize-ordinary-non-mfc-dlls"></a>Inicializar DLLs comuns (não MFC)

Para executar sua própria inicialização em DLLs comuns (não MFC) que usam o ponto de entrada de `_DllMainCRTStartup` fornecido VCRuntime, o código-fonte da DLL deve conter uma função chamada `DllMain`. O código a seguir apresenta um esqueleto básico que mostra como a definição de `DllMain` pode ser semelhante a:

```cpp
#include <windows.h>

extern "C" BOOL WINAPI DllMain (
    HINSTANCE const instance,  // handle to DLL module
    DWORD     const reason,    // reason for calling function
    LPVOID    const reserved)  // reserved
{
    // Perform actions based on the reason for calling.
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}
```

> [!NOTE]
> A documentação SDK do Windows mais antiga indica que o nome real da função de ponto de entrada de DLL deve ser especificado na linha de comando do vinculador com a opção/ENTRY. Com o Visual Studio, você não precisa usar a opção/ENTRY se o nome da função de ponto de entrada for `DllMain`. Na verdade, se você usar a opção/ENTRY e nomear sua função de ponto de entrada algo diferente de `DllMain`, o CRT não será inicializado corretamente, a menos que sua função de ponto de entrada faça as mesmas chamadas de inicialização que o `_DllMainCRTStartup` faz.

<a name="initializing-regular-dlls"></a>

### <a name="initialize-regular-mfc-dlls"></a>Inicializar DLLs regulares do MFC

Como as DLLs do MFC regulares têm um objeto `CWinApp`, elas devem executar suas tarefas de inicialização e encerramento no mesmo local que um aplicativo MFC: nas funções de membro `InitInstance` e `ExitInstance` da classe derivada de `CWinApp`da DLL. Como o MFC fornece uma função `DllMain` que é chamada pelo `_DllMainCRTStartup` para `DLL_PROCESS_ATTACH` e `DLL_PROCESS_DETACH`, você não deve escrever sua própria função de `DllMain`. A função `DllMain` fornecida pelo MFC chama `InitInstance` quando sua DLL é carregada e chama `ExitInstance` antes de o DLL ser descarregado.

Uma DLL do MFC regular pode controlar vários threads chamando [TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) e [TlsGetValue](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue) em sua função `InitInstance`. Essas funções permitem que a DLL rastreie dados específicos do thread.

Em sua DLL do MFC regular que vincula dinamicamente ao MFC, se você estiver usando qualquer MFC OLE, banco de dados MFC (ou DAO) ou suporte a soquetes MFC, respectivamente, as DLLs de extensão MFC de depuração MFCO*versão*d. dll, MFCD*versão*d. dll e MFCN*versão*d. dll (em que *version* é o número de versão) são vinculadas automaticamente. Você deve chamar uma das seguintes funções de inicialização predefinidas para cada uma dessas DLLs que você está usando em seu `CWinApp::InitInstance`de DLL do MFC regular.

|Tipo de suporte do MFC|Função de inicialização para chamar|
|-------------------------|-------------------------------------|
|MFC OLE (MFCO*versão*D. dll)|`AfxOleInitModule`|
|Banco de dados MFC (*versão*MFCD D. dll)|`AfxDbInitModule`|
|Soquetes do MFC (*versão*MFCN D. dll)|`AfxNetInitModule`|

<a name="initializing-extension-dlls"></a>

### <a name="initialize-mfc-extension-dlls"></a>Inicializar DLLs de extensão do MFC

Como as DLLs de extensão do MFC não têm um objeto derivado de `CWinApp`(como as DLLs do MFC regulares), você deve adicionar o código de inicialização e término à função `DllMain` que o assistente de DLL do MFC gera.

O assistente fornece o código a seguir para DLLs de extensão do MFC. No código, `PROJNAME` é um espaço reservado para o nome do seu projeto.

```cpp
#include "pch.h" // For Visual Studio 2017 and earlier, use "stdafx.h"
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static AFX_EXTENSION_MODULE PROJNAMEDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
   if (dwReason == DLL_PROCESS_ATTACH)
   {
      TRACE0("PROJNAME.DLL Initializing!\n");

      // MFC extension DLL one-time initialization
      AfxInitExtensionModule(PROJNAMEDLL,
                                 hInstance);

      // Insert this DLL into the resource chain
      new CDynLinkLibrary(Dll3DLL);
   }
   else if (dwReason == DLL_PROCESS_DETACH)
   {
      TRACE0("PROJNAME.DLL Terminating!\n");
   }
   return 1;   // ok
}
```

A criação de um novo objeto `CDynLinkLibrary` durante a inicialização permite que a DLL de extensão do MFC exporte `CRuntimeClass` objetos ou recursos para o aplicativo cliente.

Se você pretende usar a DLL de extensão do MFC de uma ou mais DLLs do MFC regulares, deverá exportar uma função de inicialização que cria um objeto `CDynLinkLibrary`. Essa função deve ser chamada de cada uma das DLLs do MFC regulares que usam a DLL de extensão do MFC. Um local apropriado para chamar essa função de inicialização é na função membro `InitInstance` do objeto derivado da DLL do MFC regular antes `CWinApp`de usar qualquer uma das classes ou funções exportadas da DLL de extensão do MFC.

No `DllMain` que o assistente de DLL do MFC gera, a chamada para `AfxInitExtensionModule` captura as classes de tempo de execução do módulo (estruturas de`CRuntimeClass`), bem como suas fábricas de objeto (`COleObjectFactory` objetos) para uso quando o objeto `CDynLinkLibrary` é criado. Você deve verificar o valor de retorno de `AfxInitExtensionModule`; se um valor zero for retornado de `AfxInitExtensionModule`, retornará zero de sua função `DllMain`.

Se a DLL de extensão do MFC for explicitamente vinculada a um executável (o que significa que o executável chama `AfxLoadLibrary` para vincular à DLL), você deve adicionar uma chamada para `AfxTermExtensionModule` no `DLL_PROCESS_DETACH`. Essa função permite que o MFC Limpe a DLL de extensão do MFC quando cada processo se desanexar da DLL de extensão do MFC (que acontece quando o processo é encerrado ou quando a DLL é descarregada como resultado de uma chamada de `AfxFreeLibrary`). Se a DLL de extensão do MFC for vinculada implicitamente ao aplicativo, a chamada para `AfxTermExtensionModule` não será necessária.

Os aplicativos que vinculam explicitamente a DLLs de extensão MFC devem chamar `AfxTermExtensionModule` ao liberar a DLL. Eles também devem usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez das funções do Win32 `LoadLibrary` e `FreeLibrary`) se o aplicativo usar vários threads. O uso de `AfxLoadLibrary` e `AfxFreeLibrary` garante que o código de inicialização e de desligamento executado quando a DLL de extensão do MFC for carregada e descarregada não corrompa o estado global do MFC.

Como o MFCx0. dll é totalmente inicializado pelo `DllMain` de tempo é chamado, você pode alocar memória e chamar funções MFC dentro de `DllMain` (ao contrário da versão de 16 bits do MFC).

As DLLs de extensão podem cuidar do multithreading manipulando os casos de `DLL_THREAD_ATTACH` e `DLL_THREAD_DETACH` na função `DllMain`. Esses casos são passados para `DllMain` quando os threads são anexados e desanexados da DLL. Chamar [TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) quando uma DLL está anexando permite que a dll mantenha índices de armazenamento local de thread (TLS) para cada thread anexado à dll.

Observe que o arquivo de cabeçalho Afxdllx. h contém definições especiais para estruturas usadas em DLLs de extensão do MFC, como a definição de `AFX_EXTENSION_MODULE` e `CDynLinkLibrary`. Você deve incluir esse arquivo de cabeçalho em sua DLL de extensão do MFC.

> [!NOTE]
>  É importante que você não defina nem desdefina nenhuma das macros `_AFX_NO_XXX` em *PCH. h* (*stdafx. h* no Visual Studio 2017 e anteriores). Essas macros existem somente com a finalidade de verificar se uma plataforma de destino específica dá suporte a esse recurso ou não. Você pode escrever seu programa para verificar essas macros (por exemplo, `#ifndef _AFX_NO_OLE_SUPPORT`), mas seu programa nunca deve definir ou não definir essas macros.

Uma função de inicialização de exemplo que manipula multithreading está incluída no [uso do armazenamento local de thread em uma biblioteca de vínculo dinâmico](/windows/win32/Dlls/using-thread-local-storage-in-a-dynamic-link-library) no SDK do Windows. Observe que o exemplo contém uma função de ponto de entrada chamada `LibMain`, mas você deve nomear essa função `DllMain` para que ela funcione com as bibliotecas de tempo de execução do MFC e do C.

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)<br/>
[Ponto de entrada DllMain](/windows/win32/Dlls/dllmain)<br/>
[Práticas recomendadas da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-best-practices)
