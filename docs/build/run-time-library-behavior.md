---
title: Comportamento de DLLs e da biblioteca em tempo de execução do Visual C++
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
ms.openlocfilehash: 2f2ffb13e6a80b144298bbf8cd76b5666a10b4dd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335660"
---
# <a name="dlls-and-visual-c-run-time-library-behavior"></a>Comportamento de DLLs e da biblioteca em tempo de execução do Visual C++

Quando você constrói uma Biblioteca de link dinâmico (DLL) usando o Visual Studio, por padrão, o linker inclui a biblioteca de tempo de execução Visual C++ (VCRuntime). O VCRuntime contém o código necessário para inicializar e encerrar um executável C/C++. Quando vinculado a uma DLL, o código VCRuntime fornece `_DllMainCRTStartup` uma função interna de ponto de entrada DLL chamada que lida com mensagens do Sistema Operacional Windows para a DLL para anexar ou desvincular de um processo ou segmento. A `_DllMainCRTStartup` função executa tarefas essenciais, como configuração de segurança de buffer de pilha, inicialização e término da biblioteca de tempo de execução C (CRT) e chamadas para construtores e destruidores para objetos estáticos e globais. `_DllMainCRTStartup`também chama funções de gancho para outras bibliotecas, como WinRT, MFC e ATL para realizar sua própria inicialização e rescisão. Sem essa inicialização, o CRT e outras bibliotecas, bem como suas variáveis estáticas, seriam deixados em um estado não inicializado. As mesmas rotinas de inicialização interna e término do VCRuntime são chamadas se a dLL usa um CRT estáticamente ligado ou um DLL CRT vinculado dinamicamente.

## <a name="default-dll-entry-point-_dllmaincrtstartup"></a>Ponto de entrada Padrão DLL _DllMainCRTStartup

No Windows, todos os DLLs podem conter uma `DllMain`função opcional de ponto de entrada, geralmente chamada de inicialização e término. Isso lhe dá a oportunidade de alocar ou liberar recursos adicionais conforme necessário. O Windows chama a função de ponto de entrada em quatro situações: anexação do processo, desapego do processo, anexação de rosca e desapego de rosca. Quando uma DLL é carregada em um espaço de endereço de processo, seja quando um aplicativo que a usa é carregado, ou quando o aplicativo solicita a DLL em tempo de execução, o sistema operacional cria uma cópia separada dos dados DLL. Isso é chamado *de process attach*. *A anexação do segmento* ocorre quando o processo em que a DLL é carregada cria um novo segmento. *O desapego da rosca* ocorre quando o segmento termina e o *desapego* do processo é quando a DLL não é mais necessária e é liberada por um aplicativo. O sistema operacional faz uma chamada separada para o ponto de entrada dll para cada um desses eventos, passando um argumento *de razão* para cada tipo de evento. Por exemplo, o `DLL_PROCESS_ATTACH` SISTEMA OPERACIONAL envia como *argumento de razão* para anexar o processo de sinal.

A biblioteca VCRuntime fornece uma `_DllMainCRTStartup` função de ponto de entrada chamada para lidar com operações de inicialização e terminação padrão. Na anexação `_DllMainCRTStartup` do processo, a função configura verificações de segurança de buffer, inicializa o CRT e outras bibliotecas, inicializa informações do tipo de tempo de execução, inicializa e chama construtores para `DllMain`dados estáticos e não locais, inicia o armazenamento local de thread, incrementa um contador estático interno para cada attach e, em seguida, chama um usuário ou biblioteca fornecido. No processo de desapego, a função passa por essas etapas ao contrário. Ele `DllMain`chama, diminui o contador interno, chama destructores, chama funções `atexit` de rescisão de CRT e funções registradas, e notifica quaisquer outras bibliotecas de rescisão. Quando o contador de anexos `FALSE` vai para zero, a função volta a indicar ao Windows que a DLL pode ser descarregada. A `_DllMainCRTStartup` função também é chamada durante a conexão de rosca e o desapego da rosca. Nesses casos, o código VCRuntime não faz nenhuma inicialização ou `DllMain` rescisão adicional por conta própria, e apenas liga para passar a mensagem. Se `DllMain` `FALSE` retornar da anexação do `_DllMainCRTStartup` `DllMain` processo, `DLL_PROCESS_DETACH` sinalizando falha, chamadas novamente e passar como argumento *de razão,* então passará pelo resto do processo de rescisão.

Ao construir DLLs no Visual Studio, o ponto `_DllMainCRTStartup` de entrada padrão fornecido pelo VCRuntime é conectado automaticamente. Você não precisa especificar uma função de ponto de entrada para sua DLL usando a opção [linker /ENTRY (símbolo de ponto](reference/entry-entry-point-symbol.md) de entrada).

> [!NOTE]
> Embora seja possível especificar outra função de ponto de entrada para uma DLL usando a opção /ENTRY: linker, não `_DllMainCRTStartup` recomendamos, pois sua função de ponto de entrada teria que duplicar tudo o que faz, na mesma ordem. O VCRuntime fornece funções que permitem duplicar seu comportamento. Por exemplo, você pode chamar [__security_init_cookie](../c-runtime-library/reference/security-init-cookie.md) imediatamente no processo de anexação para suportar a opção de verificação de buffer [/GS (Buffer security check).](reference/gs-buffer-security-check.md) Você pode `_CRT_INIT` chamar a função, passando os mesmos parâmetros da função de ponto de entrada, para executar o resto das funções de inicialização ou terminação da DLL.

<a name="initializing-a-dll"></a>

## <a name="initialize-a-dll"></a>Inicialize um DLL

Sua DLL pode ter um código de inicialização que deve ser executado quando o DLL for carregado. Para que você execute suas próprias funções de `_DllMainCRTStartup` inicialização `DllMain` e término de DLL, chama uma função chamada que você pode fornecer. Você `DllMain` deve ter a assinatura necessária para um ponto de entrada DLL. A função de `_DllMainCRTStartup` `DllMain` ponto de entrada padrão chama usando os mesmos parâmetros passados pelo Windows. Por padrão, se você `DllMain` não fornecer uma função, o Visual Studio `_DllMainCRTStartup` fornece uma para você e a vincula para que sempre tenha algo para chamar. Isso significa que se você não precisa inicializar seu DLL, não há nada de especial que você tem que fazer ao construir seu DLL.

Esta é a `DllMain`assinatura usada para:

```cpp
#include <windows.h>

extern "C" BOOL WINAPI DllMain (
    HINSTANCE const instance,  // handle to DLL module
    DWORD     const reason,    // reason for calling function
    LPVOID    const reserved); // reserved
```

Algumas bibliotecas `DllMain` embrulham a função para você. Por exemplo, em uma DLL MFC regular, implemente as `CWinApp` funções do objeto e `InitInstance` `ExitInstance` do membro para executar a inicialização e a terminação exigidas pela sua DLL. Para obter mais detalhes, consulte a seção [Inicialize DLLs Regular esminantes.](#initializing-regular-dlls)

> [!WARNING]
> Existem limites significativos sobre o que você pode fazer com segurança em um ponto de entrada DLL. Consulte [As Práticas Recomendadas Gerais](/windows/win32/Dlls/dynamic-link-library-best-practices) para APIs `DllMain`específicas do Windows que não são seguras para chamar . Se você precisar de algo além da inicialização mais simples, então faça isso em uma função de inicialização para o DLL. Você pode exigir que os aplicativos `DllMain` chamem a função de inicialização depois de executado e antes que eles chamem quaisquer outras funções na DLL.

<a name="initializing-non-mfc-dlls"></a>

### <a name="initialize-ordinary-non-mfc-dlls"></a>Inicializar DLLs ordinários (não-MFC)

Para executar sua própria inicialização em DLLs ordinários (não-MFC) que usam o ponto de entrada fornecido pelo `_DllMainCRTStartup` VCRuntime, o código fonte do DLL deve conter uma função chamada `DllMain`. O código a seguir apresenta um `DllMain` esqueleto básico mostrando como pode ser a definição:

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
> A documentação mais antiga do Windows SDK diz que o nome real da função de ponto de entrada DLL deve ser especificado na linha de comando do linker com a opção /ENTRY. Com o Visual Studio, você não precisa usar a opção /ENTRY `DllMain`se o nome da sua função de ponto de entrada for . Na verdade, se você usar a opção /ENTRY e `DllMain`nomear sua função de ponto de entrada algo diferente, o CRT `_DllMainCRTStartup` não será inicializado corretamente a menos que sua função de ponto de entrada faça as mesmas chamadas de inicialização que faz.

<a name="initializing-regular-dlls"></a>

### <a name="initialize-regular-mfc-dlls"></a>Inicializar DLLs MFC regulares

Como os DLLs MFC regulares `CWinApp` têm um objeto, eles devem executar suas tarefas `InitInstance` de `ExitInstance` inicialização e rescisão `CWinApp`no mesmo local que um aplicativo MFC: nas funções e membros da classe derivada do DLL. Como o MFC fornece `DllMain` uma `_DllMainCRTStartup` `DLL_PROCESS_ATTACH` função `DLL_PROCESS_DETACH`que é chamada `DllMain` por e , você não deve escrever sua própria função. A função fornecida `DllMain` pelo `InitInstance` MFC chama quando o DLL é carregado e ele chama `ExitInstance` antes que o DLL seja descarregado.

Um DLL MFC regular pode acompanhar vários threads chamando [TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) `InitInstance` e [TlsGetValue](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue) em sua função. Essas funções permitem que o DLL rastreie dados específicos do segmento.

Em seu MFC DLL regular que se conecta dinamicamente ao MFC, se você estiver usando qualquer MFC OLE, MFC Database (ou DAO), ou MFC Sockets suporte, respectivamente, a extensão Debug MFC DLLs MFCO*versão*D.dll, MFCD*versão*D.dll e MFCN*versão*D.dll (onde *a versão* é o número da versão) estão vinculadas automaticamente. Você deve chamar uma das seguintes funções de inicialização predefinidas para cada uma dessas DLLs que você está usando em suas DLL's `CWinApp::InitInstance`MFC regulares .

|Tipo de suporte a MFC|Função de inicialização para chamar|
|-------------------------|-------------------------------------|
|MFC OLE *(versão*MFCO D.dll)|`AfxOleInitModule`|
|Banco de dados MFC *(versão*MFCD D.dll)|`AfxDbInitModule`|
|Soquetes MFC *(versão*MFCN D.dll)|`AfxNetInitModule`|

<a name="initializing-extension-dlls"></a>

### <a name="initialize-mfc-extension-dlls"></a>Inicializar DLLs de extensão MFC

Como os DLLs de extensão MFC não possuem um `CWinApp`objeto derivado (assim como os DLLs `DllMain` MFC regulares), você deve adicionar seu código de inicialização e terminação à função que o MFC DLL Wizard gera.

O assistente fornece o seguinte código para DLLs de extensão MFC. No código, `PROJNAME` está um espaço reservado para o nome do seu projeto.

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

A criação `CDynLinkLibrary` de um novo objeto durante a `CRuntimeClass` inicialização permite que a DLL de extensão MFC exporte objetos ou recursos para o aplicativo cliente.

Se você vai usar o DLL de extensão MFC de um ou mais DLLs `CDynLinkLibrary` MFC regulares, você deve exportar uma função de inicialização que cria um objeto. Essa função deve ser chamada de cada um dos DLLs MFC regulares que usam a extensão MFC DLL. Um lugar apropriado para chamar essa `InitInstance` função de inicialização está na `CWinApp`função membro do objeto derivado do MFC DLL regular antes de usar qualquer uma das classes ou funções exportadas da extensão MFC.

No `DllMain` que o MFC DLL Wizard `AfxInitExtensionModule` gera, a chamada para capturar`CRuntimeClass` as classes de tempo de`COleObjectFactory` execução (estruturas) `CDynLinkLibrary` do módulo, bem como suas fábricas de objetos (objetos) para uso quando o objeto é criado. Você deve verificar o `AfxInitExtensionModule`valor de retorno de ; se um valor zero `AfxInitExtensionModule`for devolvido, `DllMain` retorne zero de sua função.

Se a dLL de extensão do MFC estiver explicitamente ligada `AfxLoadLibrary` a um executável (o que `AfxTermExtensionModule` significa `DLL_PROCESS_DETACH`que as chamadas executáveis para vincular à DLL), você deve adicionar uma chamada para .on . Esta função permite que o MFC limpe a dLL de extensão MFC quando cada processo se desprende da dLL de `AfxFreeLibrary` extensão MFC (que acontece quando o processo sai ou quando o DLL é descarregado como resultado de uma chamada). Se a sua extensão De MFC DLL será `AfxTermExtensionModule` vinculada implicitamente ao aplicativo, a chamada para não é necessária.

Os aplicativos que se vinculam explicitamente aos DLLs de extensão MFC devem ligar `AfxTermExtensionModule` ao liberar a DLL. Eles também `AfxLoadLibrary` devem `AfxFreeLibrary` usar e (em vez `LoadLibrary` `FreeLibrary`das funções Win32 e ) se o aplicativo usar vários threads. O `AfxLoadLibrary` `AfxFreeLibrary` uso e garante que o código de inicialização e desligamento que é executado quando a DLL de extensão MFC é carregada e descarregada não corrompe o estado MFC global.

Como o MFCx0.dll é totalmente `DllMain` inicializado pelo tempo que é chamado, `DllMain` você pode alocar memória e chamar funções MFC dentro (ao contrário da versão de 16 bits do MFC).

DLLs de extensão podem cuidar da `DLL_THREAD_ATTACH` multithreading manuseando os casos e `DLL_THREAD_DETACH` os casos na `DllMain` função. Esses casos são `DllMain` passados para quando os segmentos se anexam e se desprendem da DLL. Chamar [TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) quando uma DLL estiver anexando permite que a DLL mantenha os índices de armazenamento local (TLS) de rosca para cada rosca anexada à DLL.

Observe que o arquivo de cabeçalho Afxdllx.h contém definições especiais para estruturas `AFX_EXTENSION_MODULE` usadas `CDynLinkLibrary`em DLLs de extensão MFC, como a definição para e . Você deve incluir este arquivo de cabeçalho em sua extensão MFC DLL.

> [!NOTE]
> É importante que você não defina `_AFX_NO_XXX` nem defina nenhuma das macros em *pch.h* (*stdafx.h* no Visual Studio 2017 e anterior). Essas macros existem apenas com o propósito de verificar se uma determinada plataforma de destino suporta esse recurso ou não. Você pode escrever seu programa para verificar `#ifndef _AFX_NO_OLE_SUPPORT`essas macros (por exemplo, ), mas seu programa nunca deve definir ou desdefinir essas macros.

Uma função de inicialização de exemplo que lida com multithreading está incluída no [Uso do Armazenamento Local thread em uma Biblioteca de Link Dinâmico](/windows/win32/Dlls/using-thread-local-storage-in-a-dynamic-link-library) no SDK do Windows. Observe que a amostra contém uma `LibMain`função de ponto `DllMain` de entrada chamada , mas você deve nomear esta função para que ela funcione com as bibliotecas de tempo de execução MFC e C.

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)<br/>
[Ponto de entrada DllMain](/windows/win32/Dlls/dllmain)<br/>
[Práticas recomendadas de biblioteca de link dinâmico](/windows/win32/Dlls/dynamic-link-library-best-practices)
