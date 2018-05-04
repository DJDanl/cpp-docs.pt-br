---
title: Usar DLLs de extensão do banco de dados, OLE e MFC de soquetes em DLLs normais do MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- DLLs [C++], initializing
- DLLs [C++], extension
- DLLs [C++], regular
ms.assetid: 9f1d14a7-9e2a-4760-b3b6-db014fcdb7ff
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f902f3b512b5684cf185829fdf4346b8851ff8ba
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="using-database-ole-and-sockets-mfc-extension-dlls-in-regular-mfc-dlls"></a>Usar DLLs de extensão do banco de dados, OLE e MFC de soquetes em DLLs normais do MFC
Ao usar uma extensão do MFC DLL a partir de uma DLL MFC regular, se a extensão MFC DLL não está conectado no **CDynLinkLibrary** objeto cadeia da DLL do MFC regular, você pode executar em um ou mais de um conjunto de problemas relacionados. Como dar suporte as versões de depuração do banco de dados MFC, OLE e soquetes DLLs são implementadas como DLLs de extensão do MFC, você poderá ver problemas semelhantes, se você estiver usando esses MFC recursos, mesmo se você não estiver explicitamente usando qualquer um dos seus próprios DLLs de extensão do MFC. Alguns sintomas são:  
  
-   Ao tentar desserializar um objeto de um tipo de classe definido na extensão do MFC DLL, a mensagem "Aviso: não é possível carregar CYourClass de arquivamento. Classe não definido." aparece na janela de rastreamento de depuração e o objeto falhar para serializar.  
  
-   Uma exceção que indica a classe incorreta pode ser gerada.  
  
-   Recursos armazenados na DLL de extensão do MFC falham ao carregar porque `AfxFindResourceHandle` retorna **nulo** ou um identificador de recurso incorreto.  
  
-   `DllGetClassObject`, `DllCanUnloadNow`e o `UpdateRegistry`, `Revoke`, `RevokeAll`, e `RegisterAll` funções membro de `COleObjectFactory` não conseguir localizar uma fábrica de classes definida na DLL de extensão do MFC.  
  
-   `AfxDoForAllClasses` não funciona para todas as classes na DLL de extensão do MFC.  
  
-   Banco de dados padrão do MFC, soquetes ou recursos OLE falham ao carregar. Por exemplo, **AfxLoadString**(**AFX_IDP_SQL_CONNECT_FAIL**) retorna uma cadeia de caracteres vazia, mesmo quando a DLL do MFC regular é corretamente usando as classes de banco de dados MFC.  
  
 A solução para esses problemas é criar e exportar uma função de inicialização na extensão do MFC DLL que cria um **CDynLinkLibrary** objeto. Chame a função de inicialização exatamente uma vez cada DLL MFC regular que usa a DLL de extensão do MFC.  
  
## <a name="mfc-ole-mfc-database-or-dao-or-mfc-sockets-support"></a>OLE do MFC, o banco de dados MFC (ou DAO), ou suporte de soquetes do MFC  
 Se você estiver usando qualquer OLE do MFC, banco de dados MFC (ou DAO) ou soquetes do MFC suporte em sua DLL MFC regular, respectivamente, a depuração MFC MFCOxxD.dll DLLs de extensão do MFC, MFCDxxD.dll e MFCNxxD.dll (onde xx é o número de versão) são vinculados automaticamente. Você deve chamar uma função de inicialização predefinidos para cada uma dessas DLLs que você está usando.  
  
 Para suporte de banco de dados, adicione uma chamada para `AfxDbInitModule` para sua MFC DLL regular `CWinApp::InitInstance` função. Verifique se essa chamada ocorre antes de qualquer chamada de classe base ou qualquer código que acessa o MFCDxxD.dll de adicionada. Essa função não usa nenhum parâmetro e retorna void.  
  
 Para obter suporte OLE, adicione uma chamada para `AfxOleInitModule` para sua MFC DLL regular `CWinApp::InitInstance`. Observe que o **COleControlModule InitInstance** chamadas de função `AfxOleInitModule` , portanto, se você estiver criando um controle OLE e estiver usando `COleControlModule`, você não deve adicionar essa chamada para `AfxOleInitModule`.  
  
 Para obter suporte soquetes, adicione uma chamada para `AfxNetInitModule` para sua MFC DLL regular `CWinApp::InitInstance`.  
  
 Observe que compilações de versão do MFC DLLs e aplicativos não usam DLLs separadas para o banco de dados, soquetes, ou suporte de OLE. No entanto, é seguro chamar essas funções de inicialização no modo de liberação.  
  
## <a name="cdynlinklibrary-objects"></a>Objetos CDynLinkLibrary  
 Durante cada uma das operações mencionadas no início deste tópico, MFC precisa pesquisar para um objeto ou o valor desejado. Por exemplo, durante a desserialização, MFC precisa pesquisar todas as classes de tempo de execução atualmente disponíveis para corresponder objetos no arquivo com a classe de tempo de execução adequado.  
  
 Como parte dessas pesquisas, MFC examina todas as DLLs de extensão do MFC em uso pela movimentação de uma cadeia de **CDynLinkLibrary** objetos. **CDynLinkLibrary** objetos anexar automaticamente a uma cadeia durante sua construção e são criados por cada DLL de extensão do MFC por sua vez durante a inicialização. Além disso, cada módulo (aplicativo ou DLL MFC regular) tem sua própria cadeia de **CDynLinkLibrary** objetos.  
  
 Para uma extensão MFC DLL para obter conectados com um **CDynLinkLibrary** cadeia, é necessário criar um **CDynLinkLibrary** objeto no contexto de cada módulo que usa a DLL de extensão do MFC. Portanto, se uma extensão do MFC DLL a ser usado em DLLs normais do MFC, ele deve fornecer uma função de inicialização exportada que cria um **CDynLinkLibrary** objeto. Cada DLL MFC regular que usa a extensão MFC DLL deve chamar a função de inicialização exportada.  
  
 Se uma extensão do MFC DLL só será usada em um aplicativo MFC (.exe) e nunca de uma DLL MFC regular e, em seguida, é suficiente para criar o **CDynLinkLibrary** objeto no MFC DLL de extensão `DllMain`. Este é o que faz o código DLL de extensão do MFC de Assistente de DLL do MFC. Ao carregar uma DLL de extensão do MFC implicitamente, `DllMain` carrega e executa antes que o aplicativo nunca é iniciado. Qualquer **CDynLinkLibrary** criações são conectadas em uma cadeia padrão que a DLL do MFC reserva para um aplicativo do MFC.  
  
 Observe que é uma boa ideia para ter várias **CDynLinkLibrary** objetos de uma extensão MFC DLL em qualquer uma cadeia, especialmente se a DLL de extensão do MFC serão dinamicamente descarregado da memória. Não chame a função de inicialização mais de uma vez de qualquer um módulo.  
  
## <a name="sample-code"></a>Código de exemplo  
 Esse código de exemplo pressupõe que a DLL do MFC regular é implicitamente a vinculação para a DLL de extensão do MFC. Isso é feito por meio da vinculação para a biblioteca de importação (. lib) da DLL de extensão do MFC ao criar a DLL do MFC regular.  
  
 As linhas a seguir devem estar na fonte da DLL de extensão do MFC:  
  
```  
// YourExtDLL.cpp:  
  
// standard MFC extension DLL routines  
#include "afxdllx.h"  
  
static AFX_EXTENSION_MODULE NEAR extensionDLL = { NULL, NULL };  
  
extern "C" int APIENTRY  
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)  
{  
    if (dwReason == DLL_PROCESS_ATTACH)  
    {  
        // MFC extension DLL one-time initialization  
        if (!AfxInitExtensionModule(extensionDLL, hInstance))  
           return 0;  
    }  
    return 1;   // ok  
}  
  
// Exported DLL initialization is run in context of  
// application or regular MFC DLL  
extern "C" void WINAPI InitYourExtDLL()  
{  
    // create a new CDynLinkLibrary for this app  
    new CDynLinkLibrary(extensionDLL);  
  
    // add other initialization here  
}  
```  
  
 Certifique-se de exportar o **InitYourExtDLL** função. Isso pode ser feito usando **dllexport** ou no arquivo. def da DLL da seguinte maneira:  
  
```  
// YourExtDLL.Def:  
LIBRARY      YOUREXTDLL  
CODE         PRELOAD MOVEABLE DISCARDABLE  
DATA         PRELOAD SINGLE  
EXPORTS  
    InitYourExtDLL  
```  
  
 Adicionar uma chamada para o `InitInstance` membro o `CWinApp`-derivados do objeto em cada DLL MFC regular usando a DLL de extensão do MFC:  
  
```  
// YourRegularDLL.cpp:  
  
class CYourRegularDLL : public CWinApp  
{  
public:  
    virtual BOOL InitInstance(); // Initialization  
    virtual int ExitInstance();  // Termination  
  
    // nothing special for the constructor  
    CYourRegularDLL(LPCTSTR pszAppName) : CWinApp(pszAppName) { }  
};  
  
BOOL CYourRegularDLL::InitInstance()  
{  
    // any DLL initialization goes here  
    TRACE0("YOUR regular MFC DLL initializing\n");  
  
    // wire any MFC extension DLLs into CDynLinkLibrary chain  
    InitYourExtDLL();  
  
    return TRUE;  
}  
```  
  
### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Inicializar uma DLL de extensão do MFC](../build/run-time-library-behavior.md#initializing-extension-dlls)  
  
-   [Inicializar a DLLs normais do MFC](../build/run-time-library-behavior.md#initializing-regular-dlls)  
  
### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [DLLs de extensão de MFC](../build/extension-dlls.md)  
  
-   [DLLs MFC regulares vinculadas estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLLs MFC regulares vinculadas dinamicamente ao MFC](../build/regular-dlls-dynamically-linked-to-mfc.md)  
  
-   [Usando MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)  
  
-   [Versão de DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs de extensão de MFC](../build/extension-dlls.md)