---
title: DLLs e o comportamento de biblioteca de tempo de execução do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- _DllMainCRTStartup
- CRT_INIT
dev_langs:
- C++
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
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 75bf84eeaf9277c5cf037c4fa59c28d109d95856
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dlls-and-visual-c-run-time-library-behavior"></a>DLLs e o comportamento de biblioteca de tempo de execução do Visual C++  
  
Quando você cria uma biblioteca de vínculo dinâmico (DLL) usando o Visual C++, por padrão, o vinculador inclui a biblioteca de tempo de execução do Visual C++ (VCRuntime). O VCRuntime contém o código necessário para inicializar e terminar um executável de C/C++. Quando vinculados em uma DLL, o código de VCRuntime fornece uma função de ponto de entrada DLL interna chamada `_DllMainCRTStartup` que trata mensagens do sistema operacional Windows para a DLL para anexar ou desanexar do processo ou thread. O `_DllMainCRTStartup` função executa tarefas essenciais, como configurar a inicialização da biblioteca de tempo de execução (CRT) C e encerramento de segurança de buffer de pilha e chamadas para construtores e destruidores para objetos globais e estáticos. `_DllMainCRTStartup`também chamadas de funções para outras bibliotecas, como WinRT, MFC e ATL para executar suas próprias inicialização e encerramento de gancho. Sem essa inicialização, CRT e outras bibliotecas, bem como suas variáveis estáticas, será deixado em um estado não inicializado. A mesma VCRuntime de inicialização interno e rotinas de encerramento são chamadas se sua DLL usa um CRT estaticamente vinculado ou uma DLL do CRT dinamicamente vinculada.  
  
## <a name="default-dll-entry-point-dllmaincrtstartup"></a>Dllmaincrtstartup de ponto de entrada DLL padrão  
  
No Windows, todas as DLLs podem conter uma função de ponto de entrada opcional, geralmente chamada `DllMain`, que é chamado para inicialização e encerramento. Isso lhe dá a oportunidade de alocar ou liberar recursos adicionais conforme necessário. O Windows chama a função de ponto de entrada em situações de quatro: processo de anexar, desanexar do processo, thread anexar e desanexar de thread. Quando uma DLL é carregada em um espaço de endereço de processo, quando um aplicativo que usa é carregado, ou quando o aplicativo solicita o DLL em tempo de execução, o sistema operacional cria uma cópia separada dos dados da DLL. Isso é chamado de *anexar processo*. *Thread anexar* ocorre quando o processo a DLL é carregada no cria um novo thread. *Thread desanexar* ocorre quando o thread termina, e *desanexar do processo* é quando a DLL não é mais necessária e é lançada por um aplicativo. O sistema operacional faz uma chamada separada para o ponto de entrada DLL para cada um desses eventos, passando um *motivo* argumento para cada tipo de evento. Por exemplo, o sistema operacional envia `DLL_PROCESS_ATTACH` como o *motivo* argumento para sinalizar o processo de anexar.  
  
A biblioteca de VCRuntime fornece uma função de ponto de entrada chamada `_DllMainCRTStartup` para lidar com operações de inicialização e encerramento de padrão. No processo de anexar, o `_DllMainCRTStartup` função configura verificações de segurança do buffer, inicializa o CRT e outras bibliotecas, inicializa as informações de tipo de tempo de execução, inicializa e chama construtores para dados estáticos e não local, inicializa o armazenamento local de thread , incrementa um contador interno estático para cada anexo e, em seguida, chama um usuário ou biblioteca-fornecido pelo `DllMain`. No processo de desconectar, a função vai por essas etapas na ordem inversa. Ele chama `DllMain`, diminui o contador interno, chama destruidores, registrado e funções de encerramento de chamadas CRT `atexit` funções e notifica quaisquer outras bibliotecas de encerramento. Quando o contador de anexo chega a zero, a função retorna `FALSE` para indicar ao Windows que a DLL pode ser descarregada. O `_DllMainCRTStartup` função também é chamada durante a thread anexar e desanexar de thread. Nesses casos, o código de VCRuntime não sem inicialização adicional ou encerramento por conta própria e apenas chama `DllMain` para transmitir a mensagem ao longo. Se `DllMain` retorna `FALSE` do processo de anexar, indicando falha, `_DllMainCRTStartup` chamadas `DllMain` novamente e passa `DLL_PROCESS_DETACH` como o *motivo* argumento, em seguida, passa o restante das processo de encerramento.  
  
Ao criar DLLs no Visual C++, o ponto de entrada padrão `_DllMainCRTStartup` fornecido pelo VCRuntime é vinculado automaticamente. Você não precisa especificar uma função de ponto de entrada para a DLL usando o [/ENTRY (símbolo de ponto de entrada)](../build/reference/entry-entry-point-symbol.md) opção de vinculador.  
  
> [!NOTE]
> Embora seja possível especificar outra função de ponto de entrada para uma DLL usando o /ENTRY: opção de vinculador, não é recomendável, porque sua função de ponto de entrada seria necessário duplicar tudo o que `_DllMainCRTStartup` faz, na mesma ordem. O VCRuntime fornece funções que permitem que você duplicar seu comportamento. Por exemplo, você pode chamar [security_init_cookie](../c-runtime-library/reference/security-init-cookie.md) imediatamente no processo de anexar para dar suporte a [/GS (verificação de segurança do Buffer)](../build/reference/gs-buffer-security-check.md) opção de verificação de buffer. Você pode chamar o `_CRT_INIT` função, passando os mesmos parâmetros da função de ponto de entrada, para executar o restante das funções de inicialização ou encerramento da DLL.  
  
<a name="initializing-a-dll"></a>  
  
## <a name="initialize-a-dll"></a>Inicializar uma DLL  
  
A DLL pode ter o código de inicialização que deve executar quando o DLL for carregada. Em ordem para executar suas próprias funções de inicialização e encerramento de DLL, `_DllMainCRTStartup` chama uma função chamada `DllMain` que você pode fornecer. O `DllMain` deve ter a assinatura necessária para um ponto de entrada da DLL. A função de ponto de entrada padrão `_DllMainCRTStartup` chamadas `DllMain` usando os mesmos parâmetros passados pelo Windows. Por padrão, se você não fornecer um `DllMain` função, o Visual C++ fornece uma para você e links-lo no modo que `_DllMainCRTStartup` sempre tem algo a chamar. Isso significa que se você não precisar inicializar a DLL, há nada de especial, que você deve fazer ao criar sua DLL.  
  
Isso é a assinatura usada para `DllMain`:  
  
```cpp  
#include <windows.h>  
  
extern "C" BOOL WINAPI DllMain (
    HINSTANCE const instance,  // handle to DLL module 
    DWORD     const reason,    // reason for calling function
    LPVOID    const reserved); // reserved
```  
  
Algumas bibliotecas de encapsulam o `DllMain` função para você. Por exemplo, em uma DLL MFC regular, implementar a `CWinApp` do objeto `InitInstance` e `ExitInstance` funções de membro para executar a inicialização e encerramento exigido por sua DLL. Para obter mais detalhes, consulte o [regular inicializar DLLs MFC](#initializing-regular-dlls) seção.  
  
> [!WARNING]
> Há limites significativos sobre o que você com segurança pode fazer em um ponto de entrada da DLL. Consulte [as práticas recomendadas gerais](https://msdn.microsoft.com/library/windows/desktop/dn633971#general_best_practices) APIs específicas do Windows que são seguro chamar `DllMain`. Se você precisar de qualquer coisa a inicialização mais simples, em seguida, use uma função de inicialização para a DLL. Você pode exigir que os aplicativos para chamar a função de inicialização após `DllMain` tem execução e antes de eles se chamar outras funções na DLL.  
  
<a name="initializing-non-mfc-dlls"></a>  
  
### <a name="initialize-ordinary-non-mfc-dlls"></a>Inicializar DLLs comum (não MFC)  
  
Para executar seu próprio inicialização em DLLs comum (não MFC) que usam o VCRuntime fornecido `_DllMainCRTStartup` ponto de entrada, seu código-fonte DLL deve conter uma função chamada `DllMain`. O código a seguir apresenta um esqueleto básico mostrando que a definição de `DllMain` pode parecer com:  
  
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
> Documentação mais antiga do SDK do Windows informando que o nome real da função de ponto de entrada DLL deve ser especificado no vinculador de linha de comando com a opção /ENTRY. Com o Visual C++, você não precisa usar a opção /ENTRY se o nome da sua função de ponto de entrada é `DllMain`. Na verdade, se você usar a opção /ENTRY e o nome do seu ponto de entrada de função algo diferente de `DllMain`, CRT não inicializado adequadamente, a menos que a função de ponto de entrada faz chamadas mesma inicialização `_DllMainCRTStartup` faz.  
  
<a name="initializing-regular-dlls"></a>  
  
### <a name="initialize-regular-mfc-dlls"></a>Inicializar a DLLs normais do MFC  
  
Porque tem DLLs normais do MFC um `CWinApp` do objeto, eles devem executar suas tarefas de inicialização e encerramento no mesmo local como um aplicativo MFC: no `InitInstance` e `ExitInstance` funções de membro da DLL do `CWinApp`-derivado classe. Como o MFC oferece um `DllMain` função que é chamada por `_DllMainCRTStartup` para `DLL_PROCESS_ATTACH` e `DLL_PROCESS_DETACH`, você não deve gravar seus próprios `DllMain` função. O MFC fornecido `DllMain` chamadas de função `InitInstance` quando a DLL é carregada e chama `ExitInstance` antes que a DLL é descarregada.  
  
Uma DLL MFC regular pode manter o controle de vários threads chamando [TlsAlloc](http://msdn.microsoft.com/library/windows/desktop/ms686801) e [TlsGetValue](http://msdn.microsoft.com/library/windows/desktop/ms686812) no seu `InitInstance` função. Essas funções permitem que a DLL controlar os dados específicos de segmento.  
  
Em sua DLL MFC regular que vincula dinamicamente a MFC, se você estiver usando qualquer OLE do MFC, banco de dados MFC (ou DAO) ou suporte Sockets do MFC, respectivamente, a depuração MFCO DLLs de extensão do MFC*versão*D.dll, MFCD*versão*D.dll e MFCN*versão*D.dll (onde *versão* é o número de versão) são vinculados automaticamente. Você deve chamar uma das seguintes funções de inicialização predefinidos para cada uma dessas DLLs que você está usando em seu MFC DLL regular `CWinApp::InitInstance`.  
  
|Tipo de suporte do MFC|Para chamar uma função de inicialização|  
|-------------------------|-------------------------------------|  
|OLE do MFC (MFCO*versão*D.dll)|`AfxOleInitModule`|  
|Banco de dados MFC (MFCD*versão*D.dll)|`AfxDbInitModule`|  
|Soquetes de MFC (MFCN*versão*D.dll)|`AfxNetInitModule`|  
  
<a name="initializing-extension-dlls"></a>  
  
### <a name="initialize-mfc-extension-dlls"></a>Inicializar as DLLs de extensão do MFC  
  
Porque a extensão do MFC DLLs não tem um `CWinApp`-derivado do objeto (como DLLs normais do MFC), você deve adicionar o código de inicialização e encerramento de `DllMain` função gerado pelo Assistente de DLL do MFC.  
  
 O assistente fornece o código a seguir para DLLs de extensão do MFC. No código, `PROJNAME` é um espaço reservado para o nome do seu projeto.  
  
```cpp  
#include "stdafx.h"  
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
  
Criando um novo `CDynLinkLibrary` objeto durante a inicialização permite que a extensão MFC DLL para exportar `CRuntimeClass` objetos ou recursos para o aplicativo cliente.  
  
Se você pretende usar sua extensão MFC DLL a partir de uma ou mais DLLs MFC regular, você deve exportar uma função de inicialização que cria um `CDynLinkLibrary` objeto. Essa função deve ser chamada de cada uma das DLLs normais do MFC que usam a DLL de extensão do MFC. É um local adequado para chamar esta função de inicialização no `InitInstance` função membro do MFC DLL regular `CWinApp`-objeto derivado antes de usar qualquer uma das funções ou classes exportados da DLL de extensão do MFC.  
  
No `DllMain` que o Assistente de DLL MFC gera a chamada de `AfxInitExtensionModule` captura classes de tempo de execução do módulo (`CRuntimeClass` estruturas), bem como as fábricas de seu objeto (`COleObjectFactory` objetos) para usar quando o `CDynLinkLibrary` objeto é criado. Você deve verificar o valor de retorno `AfxInitExtensionModule`; se um valor zero é retornado de `AfxInitExtensionModule`, retornar zero de seu `DllMain` função.  
  
Se a DLL de extensão do MFC será vinculado explicitamente para um executável (que significa que as chamadas executável `AfxLoadLibrary` para vincular à DLL), você deve adicionar uma chamada para `AfxTermExtensionModule` em `DLL_PROCESS_DETACH`. Esta função permite MFC limpar a DLL de extensão do MFC quando cada processo desanexado da DLL de extensão do MFC (que ocorre quando o processo foi encerrado ou quando a DLL é descarregada como resultado de uma `AfxFreeLibrary` chamar). Se a DLL de extensão do MFC será vinculado implicitamente para o aplicativo, a chamada para `AfxTermExtensionModule` não é necessário.  
  
Aplicativos que o link para DLLs de extensão do MFC deve chamar explicitamente `AfxTermExtensionModule` ao liberar a DLL. Eles também devem usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez de funções do Win32 `LoadLibrary` e `FreeLibrary`) se o aplicativo usa vários threads. Usando `AfxLoadLibrary` e `AfxFreeLibrary` garante que o código de inicialização e desligamento que é executado quando a extensão MFC DLL é carregado e descarregado não corromper o estado global do MFC.  
  
Porque o MFCx0.dll está totalmente inicializado pelo tempo `DllMain` é chamado, você pode alocar memória e chamar funções MFC em `DllMain` (ao contrário da versão de 16 bits do MFC).  
  
DLLs de extensão podem cuidar de multithreading manipulando o `DLL_THREAD_ATTACH` e `DLL_THREAD_DETACH` casos no `DllMain` função. Nesses casos são passados para `DllMain` quando os threads anexar e desanexar da DLL. Chamando [TlsAlloc](http://msdn.microsoft.com/library/windows/desktop/ms686801) quando uma DLL está anexando permite que a DLL manter os índices de armazenamento local (TLS) para cada thread anexado à DLL do thread.  
  
Observe que o arquivo de cabeçalho Afxdllx.h contém definições especiais para estruturas usadas em DLLs de extensão do MFC, como a definição de `AFX_EXTENSION_MODULE` e `CDynLinkLibrary`. Você deve incluir esse arquivo de cabeçalho em sua DLL de extensão do MFC.  
  
> [!NOTE]
>  É importante que você não define nem exclua qualquer o `_AFX_NO_XXX` macros em Stdafx. h. Essas macros existem somente para fins de verificação se uma plataforma de destino em particular oferece suporte a esse recurso, ou não. Você pode escrever seu programa Verifique essas macros (por exemplo, `#ifndef _AFX_NO_OLE_SUPPORT`), mas o programa nunca deve definir ou exclua essas macros.  
  
Uma função de inicialização de exemplo identificadores multithreading está incluído no [usando Thread armazenamento Local em uma biblioteca de vínculo dinâmico](http://msdn.microsoft.com/library/windows/desktop/ms686997) no SDK do Windows. Observe que o exemplo contém uma função de ponto de entrada chamada `LibMain`, mas você deve nomear essa função `DllMain` para que ele funciona com as bibliotecas de tempo de execução MFC e C.  
  
## <a name="see-also"></a>Consulte também  
  
[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)  
[Ponto de entrada de DllMain](https://msdn.microsoft.com/library/windows/desktop/ms682583.aspx)  
[Práticas recomendadas de biblioteca de vínculo dinâmico](https://msdn.microsoft.com/library/windows/desktop/dn633971.aspx)  