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
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630363"
---
# <a name="dlls-and-visual-c-run-time-library-behavior"></a>Comportamento de DLLs C++ e da biblioteca de tempo de execução Visual

Quando você cria uma DLL (biblioteca de vínculo dinâmico) usando o Visual Studio, por padrão, o vinculador inclui a VCRuntime C++ (biblioteca de tempo de execução) Visual. O VCRuntime contém o código necessário para inicializar e encerrar um CC++ /executável. Quando vinculado a uma dll, o código VCRuntime fornece uma função de ponto de entrada de dll `_DllMainCRTStartup` interna chamada que manipula mensagens do sistema operacional Windows para a dll a ser anexada ou desanexada de um processo ou thread. A `_DllMainCRTStartup` função executa tarefas essenciais, como configuração de segurança de buffer de pilha configurada, inicialização e terminação de CRT (biblioteca de tempo de execução) e chamadas para construtores e destruidores para objetos estáticos e globais. `_DllMainCRTStartup`também chama funções de gancho para outras bibliotecas, como WinRT, MFC e ATL para executar sua própria inicialização e encerramento. Sem essa inicialização, a CRT e outras bibliotecas, bem como suas variáveis estáticas, seriam deixadas em um estado não inicializado. As mesmas rotinas de inicialização e terminação interna do VCRuntime são chamadas se sua DLL usa um CRT vinculado estaticamente ou uma DLL CRT vinculada dinamicamente.

## <a name="default-dll-entry-point-_dllmaincrtstartup"></a>Ponto de entrada DLL padrão _DllMainCRTStartup

No Windows, todas as DLLs podem conter uma função de ponto de entrada opcional, `DllMain`geralmente chamada, que é chamada para inicialização e encerramento. Isso lhe dá a oportunidade de alocar ou liberar recursos adicionais, conforme necessário. O Windows chama a função de ponto de entrada em quatro situações: processo anexar, desanexar processo, anexar thread e desanexar thread. Quando uma DLL é carregada em um espaço de endereço de processo, quando um aplicativo que o usa é carregado ou quando o aplicativo solicita a DLL em tempo de execução, o sistema operacional cria uma cópia separada dos dados da DLL. Isso é chamado de *anexo de processo*. A anexação de *thread* ocorre quando o processo em que a dll é carregada cria um novo thread. A desanexação de *thread* ocorre quando o thread é encerrado e o *processo* de desanexação é quando a dll não é mais necessária e é liberada por um aplicativo. O sistema operacional faz uma chamada separada para o ponto de entrada de DLL para cada um desses eventos, passando um argumento de *motivo* para cada tipo de evento. Por exemplo, o sistema operacional `DLL_PROCESS_ATTACH` envia como o argumento de *motivo* para sinalizar a anexação de processo.

A biblioteca VCRuntime fornece uma função de ponto de entrada `_DllMainCRTStartup` chamada para lidar com as operações de inicialização e término padrão. Na anexação de processo `_DllMainCRTStartup` , a função configura verificações de segurança de buffer, inicializa o CRT e outras bibliotecas, inicializa informações de tipo em tempo de execução, inicializa e chama construtores para dados estáticos e não locais, inicializa o armazenamento local de thread , incrementa um contador estático interno para cada anexo e, em seguida, chama um usuário ou uma biblioteca fornecida `DllMain`. Na desanexação do processo, a função passa por essas etapas na ordem inversa. Ele chama `DllMain`, Decrementa o contador interno, chama destruidores, chama funções de terminação CRT e `atexit` funções registradas e notifica quaisquer outras bibliotecas de encerramento. Quando o contador de anexos chega a zero, a função `FALSE` retorna para indicar ao Windows que a dll pode ser descarregada. A `_DllMainCRTStartup` função também é chamada durante anexação de thread e desanexação de thread. Nesses casos, o código VCRuntime não faz inicialização ou encerramento adicional por conta própria e apenas chamadas `DllMain` para passar a mensagem. Se `DllMain` retornar `DllMain` `_DllMainCRTStartup` `DLL_PROCESS_DETACH` da anexação de processo, sinalizar falha, chamar novamente e passar como o argumento de motivo, passará pelo restante do processo de encerramento. `FALSE`

Ao criar DLLs no Visual Studio, o ponto `_DllMainCRTStartup` de entrada padrão fornecido pelo VCRuntime é vinculado automaticamente. Você não precisa especificar uma função de ponto de entrada para sua DLL usando a opção de vinculador [/Entry (símbolo de ponto de entrada)](reference/entry-entry-point-symbol.md) .

> [!NOTE]
> Embora seja possível especificar outra função de ponto de entrada para uma DLL usando a opção/entry: linker, não é recomendável, porque sua função de ponto de entrada teria que duplicar tudo o que `_DllMainCRTStartup` faz, na mesma ordem. O VCRuntime fornece funções que permitem que você duplique seu comportamento. Por exemplo, você pode chamar [__security_init_cookie](../c-runtime-library/reference/security-init-cookie.md) imediatamente na anexação de processo para dar suporte à opção de verificação de buffer [/GS (verificação de segurança de buffer)](reference/gs-buffer-security-check.md) . Você pode chamar a `_CRT_INIT` função, passando os mesmos parâmetros da função de ponto de entrada, para executar o restante das funções de inicialização ou terminação de dll.

<a name="initializing-a-dll"></a>

## <a name="initialize-a-dll"></a>Inicializar uma DLL

Sua DLL pode ter código de inicialização que deve ser executado quando a DLL é carregada. Para que você execute suas próprias funções de inicialização e encerramento de dll, `_DllMainCRTStartup` o chama uma função `DllMain` chamada que você pode fornecer. Seu `DllMain` deve ter a assinatura necessária para um ponto de entrada de dll. A função `_DllMainCRTStartup` de ponto de entrada `DllMain` padrão chama o uso dos mesmos parâmetros passados pelo Windows. Por padrão, se você não fornecer uma função `DllMain` , o Visual Studio fornecerá uma para você e a vinculará para `_DllMainCRTStartup` que sempre tenha algo a ser chamado. Isso significa que, se você não precisar inicializar a DLL, não há nada de especial que você precise fazer ao compilar sua DLL.

Esta é a assinatura usada para `DllMain`:

```cpp
#include <windows.h>

extern "C" BOOL WINAPI DllMain (
    HINSTANCE const instance,  // handle to DLL module
    DWORD     const reason,    // reason for calling function
    LPVOID    const reserved); // reserved
```

Algumas bibliotecas encapsulam `DllMain` a função para você. Por exemplo, em uma DLL do MFC regular, implemente as `CWinApp` funções `ExitInstance` do objeto e do `InitInstance` membro para executar a inicialização e o encerramento exigidos por sua dll. Para obter mais detalhes, consulte a seção [inicializar DLLs regulares do MFC](#initializing-regular-dlls) .

> [!WARNING]
> Há limites significativos no que você pode fazer com segurança em um ponto de entrada de DLL. Consulte [práticas recomendadas gerais](/windows/win32/Dlls/dynamic-link-library-best-practices) para APIs específicas do Windows que não são seguras para `DllMain`chamar. Se você precisar de qualquer coisa, exceto a inicialização mais simples, faça isso em uma função de inicialização para a DLL. Você pode exigir que os aplicativos chamem a função `DllMain` de inicialização depois que o tiver sido executado e antes de chamar qualquer outra função na dll.

<a name="initializing-non-mfc-dlls"></a>

### <a name="initialize-ordinary-non-mfc-dlls"></a>Inicializar DLLs comuns (não MFC)

Para executar sua própria inicialização em DLLs comuns (não MFC) que usam o ponto de entrada fornecido `_DllMainCRTStartup` pelo VCRuntime, o código-fonte da dll deve conter uma `DllMain`função chamada. O código a seguir apresenta um esqueleto básico que mostra como a `DllMain` definição de poderia ser:

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
> A documentação SDK do Windows mais antiga indica que o nome real da função de ponto de entrada de DLL deve ser especificado na linha de comando do vinculador com a opção/ENTRY. Com o Visual Studio, você não precisa usar a opção/ENTRY se o nome da sua função de ponto de entrada for `DllMain`. Na verdade, se você usar a opção/ENTRY e nomear sua função de ponto de entrada algo `DllMain`diferente de, o CRT não será inicializado corretamente, a menos que sua função de ponto de entrada `_DllMainCRTStartup` faça as mesmas chamadas de inicialização que o faz.

<a name="initializing-regular-dlls"></a>

### <a name="initialize-regular-mfc-dlls"></a>Inicializar DLLs regulares do MFC

Como as DLLs do MFC regulares `CWinApp` têm um objeto, elas devem executar suas tarefas de inicialização e término no mesmo local que um aplicativo do MFC `InitInstance` : `ExitInstance` nas funções de membro e de `CWinApp`membros do derivado da dll classes. Como o MFC fornece `DllMain` uma função que é chamada `_DllMainCRTStartup` pelo `DLL_PROCESS_ATTACH` para `DLL_PROCESS_DETACH`e, você não deve escrever sua `DllMain` própria função. A função fornecida `DllMain` pelo MFC chama `InitInstance` quando sua dll é carregada e ela chama `ExitInstance` antes que a dll seja descarregada.

Uma DLL do MFC regular pode controlar vários threads chamando [TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) e [TlsGetValue](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue) em sua `InitInstance` função. Essas funções permitem que a DLL rastreie dados específicos do thread.

Em sua DLL do MFC regular que vincula dinamicamente ao MFC, se você estiver usando qualquer MFC OLE, banco de dados MFC (ou DAO) ou suporte a soquetes MFC, respectivamente, o Debug MFC Extension DLLs MFCO*versão*d. dll, MFCD*versão*d. dll e MFCN*versão*d. dll ( em que *version* é o número de versão) são vinculadas automaticamente. Você deve chamar uma das seguintes funções de inicialização predefinidas para cada uma dessas DLLs que você está usando em sua DLL do `CWinApp::InitInstance`MFC regular.

|Tipo de suporte do MFC|Função de inicialização para chamar|
|-------------------------|-------------------------------------|
|MFC OLE (MFCO*versão*D. dll)|`AfxOleInitModule`|
|Banco de dados MFC (*versão*MFCD D. dll)|`AfxDbInitModule`|
|Soquetes do MFC (*versão*MFCN D. dll)|`AfxNetInitModule`|

<a name="initializing-extension-dlls"></a>

### <a name="initialize-mfc-extension-dlls"></a>Inicializar DLLs de extensão do MFC

Como as DLLs de extensão do MFC não `CWinApp`têm um objeto derivado (como as DLLs do MFC regulares), você deve adicionar o código de inicialização e `DllMain` término à função que o assistente de DLL do MFC gera.

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

A criação de `CDynLinkLibrary` um novo objeto durante a inicialização permite que a dll `CRuntimeClass` de extensão do MFC Exporte objetos ou recursos para o aplicativo cliente.

Se você pretende usar a DLL de extensão do MFC de uma ou mais DLLs do MFC regulares, deverá exportar uma função de inicialização que cria `CDynLinkLibrary` um objeto. Essa função deve ser chamada de cada uma das DLLs do MFC regulares que usam a DLL de extensão do MFC. Um local apropriado para chamar essa função de inicialização é na `InitInstance` função membro do objeto derivado da `CWinApp`dll do MFC regular antes de usar qualquer uma das classes ou funções exportadas da DLL de extensão do MFC.

`CDynLinkLibrary` `COleObjectFactory` `CRuntimeClass` `AfxInitExtensionModule` No que o assistente de DLL do MFC gera, a chamada para captura as classes de tempo de execução do módulo (estruturas), bem como suas fábricas de objeto (objetos) para uso quando o objeto é criado. `DllMain` Você deve verificar o valor de retorno `AfxInitExtensionModule`de; se um valor zero for retornado `AfxInitExtensionModule`de, retorna zero de `DllMain` sua função.

Se a DLL de extensão do MFC for explicitamente vinculada a um executável (o que `AfxLoadLibrary` significa que as chamadas de executável para vincular à dll), você `AfxTermExtensionModule` deverá `DLL_PROCESS_DETACH`adicionar uma chamada para on. Essa função permite que o MFC Limpe a DLL de extensão do MFC quando cada processo se desanexar da DLL de extensão do MFC (que acontece quando o processo é encerrado ou quando a dll é descarregada como resultado de uma `AfxFreeLibrary` chamada). Se a DLL de extensão do MFC for vinculada implicitamente ao aplicativo, a chamada `AfxTermExtensionModule` para não será necessária.

Os aplicativos que se vinculam explicitamente a DLLs de `AfxTermExtensionModule` extensão MFC devem chamar ao liberar a dll. Eles também devem usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez das funções `LoadLibrary` do Win32 `FreeLibrary`e) se o aplicativo usar vários threads. Usar `AfxLoadLibrary` e`AfxFreeLibrary` garante que o código de inicialização e de desligamento seja executado quando a DLL de extensão do MFC for carregada e descarregada não corromper o estado global do MFC.

Como o MFCx0. dll é totalmente inicializado pela hora `DllMain` é chamado, você pode alocar memória e chamar funções MFC `DllMain` dentro do (diferentemente da versão de 16 bits do MFC).

DLLs de extensão podem cuidar do multithreading manipulando os `DLL_THREAD_ATTACH` casos `DLL_THREAD_DETACH` e na `DllMain` função. Esses casos são passados para `DllMain` quando os threads são anexados e desanexados da dll. Chamar [TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) quando uma DLL está anexando permite que a dll mantenha índices de armazenamento local de thread (TLS) para cada thread anexado à dll.

Observe que o arquivo de cabeçalho Afxdllx. h contém definições especiais para estruturas usadas em DLLs de extensão do MFC, como a `AFX_EXTENSION_MODULE` definição `CDynLinkLibrary`para e. Você deve incluir esse arquivo de cabeçalho em sua DLL de extensão do MFC.

> [!NOTE]
>  É importante que você não defina nem desdefina nenhuma das `_AFX_NO_XXX` macros em *PCH. h* (*stdafx. h* no Visual Studio 2017 e anteriores). Essas macros existem somente com a finalidade de verificar se uma plataforma de destino específica dá suporte a esse recurso ou não. Você pode escrever seu programa para verificar essas macros (por exemplo `#ifndef _AFX_NO_OLE_SUPPORT`,), mas seu programa nunca deve definir ou não definir essas macros.

Uma função de inicialização de exemplo que manipula multithreading está incluída no [uso do armazenamento local de thread em uma biblioteca de vínculo dinâmico](/windows/win32/Dlls/using-thread-local-storage-in-a-dynamic-link-library) no SDK do Windows. Observe que o exemplo contém uma função de ponto de entrada `LibMain`chamada, mas você deve nomear `DllMain` essa função para que ela funcione com as bibliotecas de tempo de execução do MFC e do C.

## <a name="see-also"></a>Consulte também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)<br/>
[Ponto de entrada DllMain](/windows/win32/Dlls/dllmain)<br/>
[Práticas recomendadas da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-best-practices)
