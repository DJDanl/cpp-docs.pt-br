---
title: "Inicializando DLLs de extens&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DLLs [C++], extensão"
  - "DLLs de extensão [C++], inicializando"
  - "inicializando DLLs"
ms.assetid: 08ad0381-3808-4bea-a93c-c9ba62496543
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Inicializando DLLs de extens&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como as dlls de extensão não têm `CWinApp`\- objeto derivado \(como nas dlls normais\), você deverá adicionar seus inicialização e código de término à função de `DllMain` que o assistente da DLL MFC gerencia.  
  
 O assistente fornece o seguinte código para dlls de extensão.  No código, `PROJNAME` é um espaço reservado para o nome do projeto.  
  
```  
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
  
      // Extension DLL one-time initialization  
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
  
 Criar um novo objeto de **CDynLinkLibrary** durante a inicialização permite que a DLL de extensão exporte objetos ou recursos de `CRuntimeClass` ao aplicativo cliente.  
  
 Se você pretende usar o DLL da extensão de um ou mais DLL regulares, você deverá exportar uma função de inicialização que cria um objeto de **CDynLinkLibrary** .  Essa função deve ser chamada de cada um dos DLL normais que usam a DLL da extensão.  O local apropriado para chamar essa função de inicialização está na função de membro de `CWinApp`normal da DLL \- objeto derivado de `InitInstance` antes de usar qualquer uma das classes exportadas ou das funções da DLL da extensão.  
  
 Em `DllMain` que o assistente da DLL MFC gerencia, a chamada para `AfxInitExtensionModule` captura as classes de tempo de execução de módulo \(estruturas de`CRuntimeClass` \) bem como suas fábricas de objeto \(objetos de`COleObjectFactory` \) para uso quando o objeto de **CDynLinkLibrary** é criado.  Você deve verificar o valor de retorno de `AfxInitExtensionModule`; se um valor nulo será retornado de `AfxInitExtensionModule`, retorna zero da função de `DllMain` .  
  
 Se seu DLL de extensão será vinculado explicitamente a um executável \(significa que as chamadas executáveis `AfxLoadLibrary` vincular a DLL\), você deve adicionar uma chamada a `AfxTermExtensionModule` em **DLL\_PROCESS\_DETACH**.  Esta função permite que o MFC limpar a DLL de extensão quando cada processo desanexar da DLL de extensão \(que acontece quando o processo é encerrado ou quando a DLL é descarregado no resultado de uma chamada de `AfxFreeLibrary` \).  Se seu DLL de extensão será vinculado implicitamente no aplicativo, a chamada para `AfxTermExtensionModule` não é necessário.  
  
 Os aplicativos que vinculam explicitamente a DLL de extensão **AfxTermExtensionModule** devem chamar para liberar a DLL.  Também devem usar `AfxLoadLibrary` e `AfxFreeLibrary` \(em vez do Win32 funcionam **LoadLibrary** e **FreeLibrary**\) se o aplicativo usar vários threads.  Usar `AfxLoadLibrary` e `AfxFreeLibrary` garante que a inicialização e o desligamento codifiquem que executa a DLL de extensão é carregado e descarregado não compromete o estado global de MFC.  
  
 Como o MFCx0.dll é totalmente inicializado antes de `DllMain` é chamado, você pode alocar memória e chamar funções de MFC dentro de `DllMain` \(em vez de versão de 16 bits de MFC\).  
  
 Dlls de extensão podem levar de multithreading tratando **DLL\_THREAD\_ATTACH** e os casos de **DLL\_THREAD\_DETACH** em `DllMain` função.  Esses casos são passados para `DllMain` quando os threads anexar e desanexar da DLL.  A chamada [TlsAlloc](http://msdn.microsoft.com/library/windows/desktop/ms686801) quando uma DLL está anexando permite que a DLL manter índices \(TLS\) de armazenamento de thread local para cada thread anexado à DLL.  
  
 Observe que o arquivo de cabeçalho Afxdllx.h contém definições especiais para as estruturas usadas na DLL da extensão, como a definição de `AFX_EXTENSION_MODULE` e **CDynLinkLibrary**.  Você deve incluir esse arquivo de cabeçalho no DLL da extensão.  
  
> [!NOTE]
>  É importante que você ou define undefine ou alguns dos macros de \_AFX\_NO\_XXX em Stdafx.h.  Para obter mais informações, consulte o artigo da Base de Dados de Conhecimento “PRB: Os problemas ocorrem ao definir o \_AFX\_NO\_XXX” \(Q140751\).  Você pode localizar artigos da Base de Dados de Conhecimento na Biblioteca MSDN ou em [http:\/\/search.support.microsoft.com\/](http://search.support.microsoft.com/).  
  
 Uma função de exemplo de inicialização que trata a multithreading é incluída em [Usando armazenamento de thread local em uma biblioteca de vínculo dinâmico\) nativa](http://msdn.microsoft.com/library/windows/desktop/ms686997) em [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].  Observe que o exemplo contém uma função de ponto de **LibMain**chamada, mas você deve nomear essa função `DllMain` de modo que trabalha com as bibliotecas de tempo de execução MFC e C de 2.0.  
  
 O exemplo [DLLHUSK](http://msdn.microsoft.com/pt-br/dfcaa6ff-b8e2-4efd-8100-ee3650071f90) MFC demonstra o uso de funções de inicialização.  
  
## O que você deseja fazer?  
  
-   [Inicializar DLL normais](../Topic/Initializing%20Regular%20DLLs.md)  
  
-   [Inicialize DLL não MFC](../Topic/Initializing%20Non-MFC%20DLLs.md)  
  
## Que você deseja saber mais?  
  
-   [O comportamento da biblioteca em tempo de execução do C e \_DllMainCRTStartup](../build/run-time-library-behavior.md)  
  
-   [Usando o base de dados, o OLE, e as dlls de extensão de soquetes na DLL normais](../build/using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)  
  
-   [\<caps:sentence id\="tgt34" sentenceid\="58bb7328659bda9ffb73a1dcd39da06b" class\="tgtSentence"\>A especificação de função para DllMain \(Windows SDK\)\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms682583)  
  
-   [\<caps:sentence id\="tgt35" sentenceid\="f29344705c59343b34b642944921cbdf" class\="tgtSentence"\>Função de ponto de entrada da biblioteca de link dinâmico \(Windows SDK\)\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms682596)  
  
## Consulte também  
 [Inicializando uma DLL](../build/initializing-a-dll.md)