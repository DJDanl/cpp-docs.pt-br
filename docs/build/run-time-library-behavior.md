---
title: DLLs e comportamento da biblioteca em tempo de execução Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d6475e2ea3ec7fe69325fd82671952dbe2c39620
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43217286"
---
# <a name="dlls-and-visual-c-run-time-library-behavior"></a>DLLs e comportamento da biblioteca em tempo de execução Visual C++  
  
Quando você cria uma biblioteca de vínculo dinâmico (DLL) usando o Visual C++, por padrão, o vinculador inclui a biblioteca de tempo de execução do Visual C++ (VCRuntime). O VCRuntime contém o código necessário para inicializar e terminar um executável de C/C++. Quando vinculado em uma DLL, o código de VCRuntime fornece uma função interna de ponto de entrada DLL chamada `_DllMainCRTStartup` que lida com mensagens de sistema operacional do Windows para a DLL para anexar ou desanexar de um processo ou thread. O `_DllMainCRTStartup` função executa tarefas essenciais, como configurar a inicialização da biblioteca em tempo de execução (CRT) de C e encerramento de segurança de buffer de pilha e chamadas para construtores e destruidores para objetos globais e estáticos. `_DllMainCRTStartup` também chamadas de funções para outras bibliotecas como WinRT, MFC e ATL para executar suas próprias inicialização e encerramento de gancho. Sem essa inicialização, o CRT e outras bibliotecas, bem como suas variáveis estáticas, teria ficar em um estado não inicializado. A inicialização interna do mesma VCRuntime e rotinas de encerramento são chamadas de se sua DLL usa um CRT vinculado estaticamente ou uma DLL do CRT vinculado dinamicamente.  
  
## <a name="default-dll-entry-point-dllmaincrtstartup"></a>Dllmaincrtstartup de ponto de entrada DLL padrão  
  
No Windows, todas as DLLs podem conter uma função de ponto de entrada opcional, geralmente chamada `DllMain`, que é chamado para inicialização e encerramento. Isso lhe dá uma oportunidade para alocar ou liberar recursos adicionais conforme necessário. Windows chama a função de ponto de entrada em quatro situações: processo anexar, desanexar do processo, thread anexar e desanexar de thread. Quando uma DLL é carregada em um espaço de endereço de processo, quando um aplicativo que usa a ele é carregado, ou quando o aplicativo solicita o DLL em tempo de execução, o sistema operacional cria uma cópia separada dos dados da DLL. Isso é chamado *processo anexar*. *Segmentar anexação* ocorre quando o processo que a DLL é carregada no cria um novo thread. *Segmentar desanexação* ocorre quando o thread é encerrado, e *desanexar processo* é quando a DLL não é mais necessária e é liberada por um aplicativo. O sistema operacional faz uma chamada separada para o ponto de entrada da DLL para cada um desses eventos, passando um *motivo* argumento para cada tipo de evento. Por exemplo, o sistema operacional envia `DLL_PROCESS_ATTACH` como o *motivo* argumento para sinalizar o processo anexar.  
  
A biblioteca VCRuntime fornece uma função de ponto de entrada chamada `_DllMainCRTStartup` para lidar com operações de inicialização e término do padrão. No processo de anexar, o `_DllMainCRTStartup` função configura as verificações de segurança de buffer, inicializa o CRT e outras bibliotecas, inicializa as informações de tipo de tempo de execução, inicializa e chama os construtores para dados estáticos e não locais, inicializa o armazenamento local de thread , incrementa um contador interno estático para cada anexo e, em seguida, chama um ou biblioteca-fornecido pelo usuário `DllMain`. No processo de desanexar, a função passa por essas etapas na ordem inversa. Ele chama `DllMain`, diminui o contador interno, chama destruidores, chamadas CRT encerramento de funções e registrado `atexit` funções e notifica sobre quaisquer outras bibliotecas de encerramento. Quando o contador de anexo chega a zero, a função retorna `FALSE` para indicar ao Windows que a DLL pode ser descarregada. O `_DllMainCRTStartup` função também é chamada durante o thread de anexação e desanexação de thread. Nesses casos, o código VCRuntime não faz nenhuma inicialização adicional ou o encerramento por conta própria e apenas chama `DllMain` para passar a mensagem junto. Se `DllMain` retorna `FALSE` do processo de anexar, falha, com sinal `_DllMainCRTStartup` chamadas `DllMain` novamente e passa `DLL_PROCESS_DETACH` como o *motivo* argumento, em seguida, percorre o restante das processo de encerramento.  
  
Ao criar DLLs no Visual C++, o ponto de entrada padrão `_DllMainCRTStartup` fornecido pelo VCRuntime é vinculado automaticamente. Você não precisará especificar uma função de ponto de entrada para sua DLL usando o [/ENTRY (símbolo de ponto de entrada)](../build/reference/entry-entry-point-symbol.md) a opção de vinculador.  
  
> [!NOTE]
> Embora seja possível especificar o outra função de ponto de entrada para uma DLL usando o /ENTRY: opção de vinculador, é recomendável, pois sua função de ponto de entrada teria que duplicar tudo que `_DllMainCRTStartup` faz, na mesma ordem. O VCRuntime fornece funções que permitem que você duplicar seu comportamento. Por exemplo, você pode chamar [security_init_cookie](../c-runtime-library/reference/security-init-cookie.md) imediatamente no processo de anexação para oferecer suporte a [/GS (verificação de segurança do Buffer)](../build/reference/gs-buffer-security-check.md) opção de verificação de buffer. Você pode chamar o `_CRT_INIT` função, passando os mesmos parâmetros como a função de ponto de entrada, para executar o restante das funções de inicialização ou encerramento da DLL.  
  
<a name="initializing-a-dll"></a>  
  
## <a name="initialize-a-dll"></a>Inicialize um DLL  
  
A DLL pode ter código de inicialização que deve ser executado quando a DLL é carregada. Para que você execute suas próprias funções de inicialização e encerramento de DLL, `_DllMainCRTStartup` chama uma função chamada `DllMain` que você pode fornecer. Seu `DllMain` deve ter a assinatura necessária para um ponto de entrada da DLL. A função de ponto de entrada padrão `_DllMainCRTStartup` chamadas `DllMain` usando os mesmos parâmetros passados pelo Windows. Por padrão, se você não fornecer um `DllMain` função, o Visual C++ fornece um para você e vincula-o no modo que `_DllMainCRTStartup` sempre tem algo para chamar. Isso significa que se você não precisar inicializar sua DLL, há nada de especial que você precisa fazer ao criar sua DLL.  
  
Isso é a assinatura usada para `DllMain`:  
  
```cpp  
#include <windows.h>  
  
extern "C" BOOL WINAPI DllMain (
    HINSTANCE const instance,  // handle to DLL module 
    DWORD     const reason,    // reason for calling function
    LPVOID    const reserved); // reserved
```  
  
Algumas bibliotecas de encapsulam o `DllMain` função para você. Por exemplo, em uma DLL MFC regular, implementar o `CWinApp` do objeto `InitInstance` e `ExitInstance` funções de membro para executar a inicialização e término exigido pela sua DLL. Para obter mais detalhes, consulte o [inicializar o DLLs MFC regulares](#initializing-regular-dlls) seção.  
  
> [!WARNING]
> Há limites significativos sobre o que você com segurança pode fazer em um ponto de entrada da DLL. Ver [práticas recomendadas gerais](/windows/desktop/Dlls/dynamic-link-library-best-practices) APIs específicas do Windows que não são seguros para chamar em `DllMain`. Se você precisa de nada, mas a inicialização mais simples, em seguida, fazer isso em uma função de inicialização para a DLL. Você pode exigir que aplicativos chamem a função de inicialização após `DllMain` tem execução e antes de eles chamam outras funções na DLL.  
  
<a name="initializing-non-mfc-dlls"></a>  
  
### <a name="initialize-ordinary-non-mfc-dlls"></a>Inicializar as DLLs normais (não MFC)  
  
Para executar seu próprio inicialização em DLLs normais (não MFC) que usam o VCRuntime fornecido pelo `_DllMainCRTStartup` ponto de entrada, seu código-fonte DLL deve conter uma função chamada `DllMain`. O código a seguir apresenta um esqueleto básico mostrando qual é a definição de `DllMain` pode parecer com:  
  
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
> Documentação do SDK do Windows mais antiga diz que o nome real da função de ponto de entrada DLL deve ser especificado na linha de comando com a opção /ENTRY vinculador. Com o Visual C++, você não precisará usar a opção /ENTRY se o nome da sua função de ponto de entrada for `DllMain`. Na verdade, se você usar a opção /ENTRY e o nome do seu ponto de entrada de função algo diferente de `DllMain`, o CRT não obter inicializado corretamente, a menos que sua função de ponto de entrada faz as chamadas de inicialização mesmo que `_DllMainCRTStartup` faz.  
  
<a name="initializing-regular-dlls"></a>  
  
### <a name="initialize-regular-mfc-dlls"></a>Inicializar dll normais do MFC  
  
Como DLLs MFC regulares têm uma `CWinApp` do objeto, eles devem executar suas tarefas de inicialização e término no mesmo local como um aplicativo do MFC: na `InitInstance` e `ExitInstance` funções de membro da DLL `CWinApp`-derivado classe. Como o MFC fornece um `DllMain` que é chamada pela função `_DllMainCRTStartup` para `DLL_PROCESS_ATTACH` e `DLL_PROCESS_DETACH`, você não deve escrever seu próprio `DllMain` função. O MFC fornecido pelo `DllMain` chamadas de função `InitInstance` quando a DLL é carregada e chama `ExitInstance` antes que a DLL seja descarregada.  
  
Uma DLL MFC regular pode manter o controle de vários threads chamando [TlsAlloc](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsalloc) e [TlsGetValue](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue) em seu `InitInstance` função. Essas funções permitem que a DLL acompanhar dados específicos de segmento.  
  
Na DLL MFC regular que vincula dinamicamente ao MFC, se você estiver usando qualquer OLE do MFC, banco de dados MFC (ou DAO) ou suporte a MFC de soquetes, respectivamente, a depuração MFCO DLLs de extensão do MFC*versão*D.dll, MFCD*versão*D.dll e MFCN*versão*D.dll (onde *versão* é o número de versão) são vinculadas automaticamente. Você deve chamar uma das seguintes funções de inicialização predefinidos para cada uma dessas DLLs que você está usando em seu MFC DLL regular `CWinApp::InitInstance`.  
  
|Tipo de suporte do MFC|Função de inicialização a ser chamada|  
|-------------------------|-------------------------------------|  
|OLE do MFC (MFCO*versão*D.dll)|`AfxOleInitModule`|  
|Banco de dados MFC (MFCD*versão*D.dll)|`AfxDbInitModule`|  
|Soquetes de MFC (MFCN*versão*D.dll)|`AfxNetInitModule`|  
  
<a name="initializing-extension-dlls"></a>  
  
### <a name="initialize-mfc-extension-dlls"></a>Inicializar a extensão de MFC  
  
Porque a extensão de MFC DLLs não tem um `CWinApp`-derivados do objeto (como DLLs MFC regulares), você deve adicionar seu código de inicialização e término para o `DllMain` função gerado pelo Assistente de DLL do MFC.  
  
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
  
Criando um novo `CDynLinkLibrary` objeto durante a inicialização permite que a extensão MFC DLL exportar `CRuntimeClass` objetos ou recursos para o aplicativo cliente.  
  
Se você pretende utilizar a extensão MFC DLL de uma ou mais DLLs MFC regulares, você deve exportar uma função de inicialização que cria um `CDynLinkLibrary` objeto. Essa função deve ser chamada de cada uma das DLLs MFC regulares que usam a extensão MFC DLL. Um local adequado para chamar essa função de inicialização está no `InitInstance` função de membro de MFC DLL regular `CWinApp`-objeto derivado antes de usar qualquer uma das funções ou classes exportadas da DLL de extensão do MFC.  
  
No `DllMain` que o Assistente de DLL do MFC gera a chamada para `AfxInitExtensionModule` captura as classes de tempo de execução do módulo (`CRuntimeClass` estruturas), bem como suas fábricas de objeto (`COleObjectFactory` objetos) para usar quando o `CDynLinkLibrary` objeto é criado. Você deve verificar o valor de retorno `AfxInitExtensionModule`; se um valor de zero for retornado por `AfxInitExtensionModule`, retornar zero de seu `DllMain` função.  
  
Se a sua DLL de extensão do MFC será vinculado explicitamente para um executável (que significa que as chamadas executáveis `AfxLoadLibrary` para vincular a DLL), você deve adicionar uma chamada para `AfxTermExtensionModule` em `DLL_PROCESS_DETACH`. Essa função permite que o MFC limpar a DLL de extensão do MFC quando cada processo desanexado da DLL de extensão do MFC (o que ocorre quando o processo é encerrado ou quando a DLL é descarregada como resultado de uma `AfxFreeLibrary` chamar). Se a sua DLL de extensão do MFC será vinculado implicitamente para o aplicativo, a chamada para `AfxTermExtensionModule` não é necessário.  
  
Aplicativos que o link para as DLLs de extensão MFC deve chamar explicitamente `AfxTermExtensionModule` ao liberar a DLL. Eles também devem usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez das funções do Win32 `LoadLibrary` e `FreeLibrary`) se o aplicativo usa vários threads. Usando o `AfxLoadLibrary` e `AfxFreeLibrary` garante que o código de inicialização e desligamento é executado quando a extensão MFC DLL é carregado e descarregado não corromper o estado global do MFC.  
  
Porque MFCx0.dll está totalmente inicializado no momento `DllMain` é chamado, você pode alocar memória e chamar funções MFC em `DllMain` (ao contrário da versão de 16 bits do MFC).  
  
DLLs de extensão podem cuidar de multithreading manipulando o `DLL_THREAD_ATTACH` e `DLL_THREAD_DETACH` casos no `DllMain` função. Esses casos são passados para `DllMain` quando os threads de anexação e desanexação da DLL. Chamando [TlsAlloc](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsalloc) quando uma DLL está relacionada a anexar permite que a DLL manter os índices de armazenamento local (TLS) para cada thread anexado à DLL do thread.  
  
Observe que o arquivo de cabeçalho Afxdllx.h contém definições especiais para estruturas usadas em DLLs de extensão do MFC, como a definição para `AFX_EXTENSION_MODULE` e `CDynLinkLibrary`. Você deve incluir esse arquivo de cabeçalho em sua extensão MFC DLL.  
  
> [!NOTE]
>  É importante que você não define nem excluir qualquer uma das definições de `_AFX_NO_XXX` macros em Stdafx. h. Essas macros existem somente para fins de verificação se uma plataforma de destino específico dá suporte a esse recurso, ou não. Você pode escrever o seu programa Verifique essas macros (por exemplo, `#ifndef _AFX_NO_OLE_SUPPORT`), mas seu programa nunca deve definir ou excluir as definições dessas macros.  
  
Uma função de inicialização de exemplo que manipula multithreading está incluído no [usando o Thread armazenamento Local em uma biblioteca de vínculo dinâmico](/windows/desktop/Dlls/using-thread-local-storage-in-a-dynamic-link-library) no SDK do Windows. Observe que o exemplo contém uma função de ponto de entrada chamada `LibMain`, mas você deve nomear essa função `DllMain` para que ele funcione com as bibliotecas de tempo de execução MFC e C.  
  
## <a name="see-also"></a>Consulte também  
  
[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)  
[Ponto de entrada de DllMain](/windows/desktop/Dlls/dllmain)  
[Práticas recomendadas da biblioteca de vínculo dinâmico](/windows/desktop/Dlls/dynamic-link-library-best-practices)  