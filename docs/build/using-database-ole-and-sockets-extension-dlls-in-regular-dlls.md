---
title: "Usando banco de dados, OLE e DLLs de extens&#227;o de soquetes em DLLs regulares | Microsoft Docs"
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
  - "DLLs [C++], inicializando"
  - "DLLs [C++], regular"
ms.assetid: 9f1d14a7-9e2a-4760-b3b6-db014fcdb7ff
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando banco de dados, OLE e DLLs de extens&#227;o de soquetes em DLLs regulares
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao usar uma DLL da extensão de uma DLL normal, se a DLL de extensão não é prendido na cadeia do objeto de **CDynLinkLibrary** da DLL normal, você pode executar em um ou mais de um conjunto de problemas relacionados.  Como as versões de depuração do base de dados de MFC, OLE, e de DLL de suporte de soquetes são implementadas como DLL de extensão, talvez tenha problemas semelhantes se você estiver usando esses recursos MFC, mesmo se você não estiver usando explicitamente seus próprios DLL da extensão.  Alguns sintomas são:  
  
-   Ao tentar desserializar um objeto de um tipo de classe definido na DLL de extensão, “que a mensagem avisará: Não é possível carregar CYourClass de arquivo morto.  A classe não definida.” aparece na janela de depuração alter TRACE e o objeto não é serializado.  
  
-   Uma exceção que indica que a classe inválida pode ser gerada.  
  
-   Os recursos armazenados na DLL de extensão não são carregados como `AfxFindResourceHandle` retorna **nulo** ou um identificador incorreta de recursos.  
  
-   `DllGetClassObject`, `DllCanUnloadNow`, e `UpdateRegistry`, `Revoke`, `RevokeAll`, e as funções de membro de `RegisterAll` de `COleObjectFactory` não sites uma fábrica da classe definidas na DLL de extensão.  
  
-   `AfxDoForAllClasses` não funciona para nenhuma classes na DLL de extensão.  
  
-   O base de dados padrão, MFC soquetes, ou os recursos do não serão carregados.  Por exemplo, **AfxLoadStringAFX\_IDP\_SQL\_CONNECT\_FAIL**\(\) retorna uma cadeia de caracteres vazia, mesmo quando a DLL normal estiver usando corretamente as classes da base de dados de MFC.  
  
 A solução nesses problemas é criar e exportar uma função de inicialização na DLL de extensão que cria um objeto de **CDynLinkLibrary** .  Chamar essa função de inicialização exatamente uma vez a cada DLL normal que usa a DLL da extensão.  
  
## Base de dados de MFC OLE, MFC DAO \(ou\), ou de soquetes MFC suporte  
 Se você estiver usando qualquer MFC OLE, base de dados de MFC \(ou\) ou, DAO suporte de soquetes MFC no DLL normal, respectivamente, as dlls MFCOxxD.dll de extensão de depuração MFC, MFCDxxD.dll, e MFCNxxD.dll \(onde xx é o número da versão\) são vinculados automaticamente.  Você deve chamar uma função predefinida de inicialização de cada um desses DLL que você está usando.  
  
 Para obter suporte à base de dados, adicione uma chamada a `AfxDbInitModule` à função normal de `CWinApp::InitInstance` do DLL.  Verifique se essa chamada ocorre antes de qualquer chamada da classe base ou qualquer código que adicionado acessar o MFCDxxD.dll.  Essa função não requer nenhum parâmetro e void de retorna.  
  
 Para suporte OLE, adicionar uma chamada a `AfxOleInitModule` a `CWinApp::InitInstance`normal do DLL.  Observe que as chamadas de função `AfxOleInitModule` de **COleControlModule InitInstance** já portanto, se você estiver criando um controlador e OLE estão usando `COleControlModule`, se você adicionar essa chamada a `AfxOleInitModule`.  
  
 Para soquetes dar suporte, adicionar uma chamada a `AfxNetInitModule` a `CWinApp::InitInstance`normal do DLL.  
  
 Observe que as construções da versão de DLL e aplicativos MFC não usam DLL separados para o base de dados, soquetes, ou o suporte OLE.  No entanto, é seguro chamar estas funções de inicialização no modo de versão.  
  
## Objetos de CDynLinkLibrary  
 Durante cada uma das operações mencionadas no início desse tópico, o MFC precisa pesquisar por um valor desejado ou do objeto.  Por exemplo, durante a desserialização, o MFC precisa pesquisar em todas as classes disponíveis atualmente em tempo de execução para corresponder objetos no arquivo morto com sua própria classe de tempo de execução.  
  
 Como uma parte dessas pesquisas, MFC examina com todas as dlls de extensão em uso examinando uma cadeia de objetos de **CDynLinkLibrary** .  Os objetos de**CDynLinkLibrary** estiverem anexadas automaticamente a uma cadeia durante a compilação e são criados por cada DLL de extensão por sua vez durante a inicialização.  Além disso, cada módulo \(aplicativo ou DLL comum\) tem sua própria cadeia de objetos de **CDynLinkLibrary** .  
  
 Para que uma DLL da extensão obter prendeu em **CDynLinkLibrary** uma cadeia, ele deve criar um objeto de **CDynLinkLibrary** no contexto de cada módulo que usa a DLL da extensão.  Em virtude disso, se uma DLL de extensão deve ser usado de DLL normais, deve fornecer uma função exportada de inicialização que cria um objeto de **CDynLinkLibrary** .  Cada DLL normal que usa a DLL de extensão deve chamar a função exportada de inicialização.  
  
 Se uma DLL de extensão deve ser usado apenas de um aplicativo de MFC \(.exe\) e nunca de uma DLL normal, então é suficiente criar o objeto de **CDynLinkLibrary** em `DllMain`DLL da extensão.  Isso é o que o código DLL da extensão do assistente da DLL MFC faz.  Ao carregar uma DLL da extensão implicitamente, `DllMain` carrega e executa antes que o aplicativo nunca.  Todas as criações de **CDynLinkLibrary** são prendidas em uma cadeia padrão que o DLL MFC para permitir que um aplicativo MFC.  
  
 Observe que é uma exibição incorreto ter vários objetos de **CDynLinkLibrary** de uma DLL da extensão em qualquer cadeia, especialmente se a DLL de extensão será descarregado da memória dinamicamente.  Não chame a função de inicialização mais de uma vez de nenhum um módulo.  
  
## Código de Exemplo  
 Este código de exemplo supõe que o DLL normal está se vinculando implicitamente para a DLL da extensão.  Isso é feito vinculando à biblioteca de importação \(.lib\) da DLL de extensão para criar a DLL normal.  
  
 As seguintes linhas devem estar na origem da DLL de extensão:  
  
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
        // extension DLL one-time initialization  
        if (!AfxInitExtensionModule(extensionDLL, hInstance))  
           return 0;  
    }  
    return 1;   // ok  
}  
  
// Exported DLL initialization is run in context of  
// application or regular DLL  
extern "C" void WINAPI InitYourExtDLL()  
{  
    // create a new CDynLinkLibrary for this app  
    new CDynLinkLibrary(extensionDLL);  
  
    // add other initialization here  
}  
```  
  
 Certifique\-se de exportar a função de **InitYourExtDLL** .  Isso pode ser feito usando **\_\_declspec\(dllexport\)** ou no arquivo .def do DLL como segue:  
  
```  
// YourExtDLL.Def:  
LIBRARY      YOUREXTDLL  
CODE         PRELOAD MOVEABLE DISCARDABLE  
DATA         PRELOAD SINGLE  
EXPORTS  
    InitYourExtDLL  
```  
  
 Adicionar uma chamada ao membro de `CWinApp`\- objeto derivado de `InitInstance` em cada DLL normal usando a DLL de extensão:  
  
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
    TRACE0("YOUR regular DLL initializing\n");  
  
    // wire any extension DLLs into CDynLinkLibrary chain  
    InitYourExtDLL();  
  
    return TRUE;  
}  
```  
  
### O que você deseja fazer?  
  
-   [Inicializar uma DLL da extensão](../build/initializing-extension-dlls.md)  
  
-   [Inicializar DLL normais](../Topic/Initializing%20Regular%20DLLs.md)  
  
### Que você deseja saber mais?  
  
-   [DLLs de Extensão](../build/extension-dlls.md)  
  
-   [DLL normais estaticamente vinculados ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLL normais vinculados dinamicamente ao MFC](../Topic/Regular%20DLLs%20Dynamically%20Linked%20to%20MFC.md)  
  
-   [Usando o MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)  
  
-   [Versão de DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)  
  
## Consulte também  
 [DLLs de extensão](../build/extension-dlls.md)