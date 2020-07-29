---
title: Usando DLLs de extensão do banco de dados, OLE e sockets do MFC em DLLs comuns do MFC
ms.date: 11/04/2016
helpviewer_keywords:
- DLLs [C++], initializing
- DLLs [C++], extension
- DLLs [C++], regular
ms.assetid: 9f1d14a7-9e2a-4760-b3b6-db014fcdb7ff
ms.openlocfilehash: 3d516f7923144f0e24bda676147ed529546def25
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213756"
---
# <a name="using-database-ole-and-sockets-mfc-extension-dlls-in-regular-mfc-dlls"></a>Usando DLLs de extensão do banco de dados, OLE e sockets do MFC em DLLs comuns do MFC

Ao usar uma DLL de extensão do MFC de uma DLL do MFC regular, se a DLL de extensão do MFC não estiver conectada à cadeia de objetos **CDynLinkLibrary** da dll do MFC regular, você poderá encontrar um ou mais de um conjunto de problemas relacionados. Como as versões de depuração do banco de dados MFC, o OLE e os soquetes oferecem suporte a DLLs são implementadas como DLLs de extensão do MFC, você poderá ver problemas semelhantes se estiver usando esses recursos do MFC, mesmo se você não estiver usando explicitamente nenhuma das suas próprias DLLs de extensão do MFC. Alguns sintomas são:

- Ao tentar desserializar um objeto de um tipo de classe definido na DLL de extensão do MFC, a mensagem "aviso: não pode carregar CYourClass do arquivo. Classe não definida. " aparece na janela de depuração de rastreamento e o objeto não serializa.

- Uma exceção indicando que a classe inadequada pode ser lançada.

- Os recursos armazenados na DLL de extensão MFC falham ao serem carregados porque `AfxFindResourceHandle` retorna **NULL** ou um identificador de recurso incorreto.

- `DllGetClassObject`, `DllCanUnloadNow` , e as `UpdateRegistry` `Revoke` `RevokeAll` funções de membro,, e `RegisterAll` de `COleObjectFactory` falha ao localizar uma fábrica de classe definida na DLL de extensão do MFC.

- `AfxDoForAllClasses`Não funciona para nenhuma classe na DLL de extensão do MFC.

- Falha ao carregar o banco de dados Standard MFC, soquetes ou recursos OLE. Por exemplo, **AfxLoadString**(**AFX_IDP_SQL_CONNECT_FAIL**) retorna uma cadeia de caracteres vazia, mesmo quando a DLL do MFC regular está usando as classes de banco de dados do MFC corretamente.

A solução para esses problemas é criar e exportar uma função de inicialização na DLL de extensão do MFC que cria um objeto **CDynLinkLibrary** . Chame essa função de inicialização exatamente uma vez de cada DLL do MFC regular que usa a DLL de extensão do MFC.

## <a name="mfc-ole-mfc-database-or-dao-or-mfc-sockets-support"></a>Suporte a MFC OLE, banco de dados MFC (ou DAO) ou soquetes MFC

Se você estiver usando qualquer MFC OLE, banco de dados MFC (ou DAO) ou suporte a soquetes MFC em sua DLL do MFC regular, respectivamente, as DLLs de extensão MFC de depuração do MFC MFCOxxD.dll, MFCDxxD.dll e MFCNxxD.dll (em que XX é o número de versão) são vinculadas automaticamente. Você deve chamar uma função de inicialização predefinida para cada uma dessas DLLs que está usando.

Para obter suporte ao banco de dados, adicione uma chamada para `AfxDbInitModule` à função da dll do MFC regular `CWinApp::InitInstance` . Certifique-se de que essa chamada ocorra antes de qualquer chamada de classe base ou qualquer código adicionado que acesse a MFCDxxD.dll. Essa função não usa parâmetros e retorna void.

Para suporte a OLE, adicione uma chamada para `AfxOleInitModule` às suas DLLs do MFC regulares `CWinApp::InitInstance` . Observe que a função **COleControlModule InitInstance** já é chamada `AfxOleInitModule` , portanto, se você estiver criando um controle OLE e estiver usando `COleControlModule` o, não deverá adicionar essa chamada para `AfxOleInitModule` .

Para obter suporte a soquetes, adicione uma chamada para `AfxNetInitModule` ao seu DLL do MFC regular `CWinApp::InitInstance` .

Observe que as compilações de versão de DLLs do MFC e aplicativos não usam DLLs separadas para o suporte a banco de dados, soquetes ou OLE. No entanto, é seguro chamar essas funções de inicialização no modo de versão.

## <a name="cdynlinklibrary-objects"></a>Objetos CDynLinkLibrary

Durante cada uma das operações mencionadas no início deste tópico, o MFC precisa procurar um valor ou objeto desejado. Por exemplo, durante a desserialização, o MFC precisa pesquisar todas as classes de tempo de execução disponíveis no momento para corresponder objetos no arquivo com sua classe de tempo de execução adequada.

Como parte dessas pesquisas, o MFC verifica todas as DLLs de extensão do MFC em uso percorrendo uma cadeia de objetos **CDynLinkLibrary** . Os objetos **CDynLinkLibrary** são anexados automaticamente a uma cadeia durante a construção e são criados por cada DLL de extensão do MFC por vez durante a inicialização. Além disso, cada módulo (aplicativo ou DLL do MFC regular) tem sua própria cadeia de objetos **CDynLinkLibrary** .

Para que uma DLL de extensão do MFC seja conectada a uma cadeia **CDynLinkLibrary** , ela deve criar um objeto **CDynLinkLibrary** no contexto de cada módulo que usa a DLL de extensão do MFC. Portanto, se uma DLL de extensão do MFC for usada em DLLs comuns do MFC, ela deverá fornecer uma função de inicialização exportada que cria um objeto **CDynLinkLibrary** . Cada DLL do MFC regular que usa a DLL de extensão do MFC deve chamar a função de inicialização exportada.

Se uma DLL de extensão do MFC só será usada de um aplicativo MFC (. exe) e nunca de uma DLL do MFC regular, será suficiente criar o objeto **CDynLinkLibrary** nas DLLs de extensão do MFC `DllMain` . É isso que o código DLL da extensão MFC do assistente de DLL do MFC. Ao carregar uma DLL de extensão do MFC implicitamente, `DllMain` o carrega e executa antes de o aplicativo ser iniciado. Qualquer criação de **CDynLinkLibrary** é conectada a uma cadeia padrão que a DLL do MFC reserva para um aplicativo MFC.

Observe que é uma má ideia ter vários objetos **CDynLinkLibrary** de uma DLL de extensão do MFC em qualquer cadeia, especialmente se a DLL de extensão do MFC for descarregada dinamicamente da memória. Não chame a função de inicialização mais de uma vez a partir de um módulo.

## <a name="sample-code"></a>Exemplo de código

Este código de exemplo pressupõe que a DLL regular do MFC está Vinculando implicitamente à DLL de extensão do MFC. Isso é feito vinculando-se à biblioteca de importação (. lib) da DLL de extensão do MFC ao compilar a DLL regular do MFC.

As seguintes linhas devem estar na origem da DLL de extensão do MFC:

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

Certifique-se de exportar a função **InitYourExtDLL** . Isso pode ser feito usando **`__declspec(dllexport)`** ou no arquivo. def de sua DLL da seguinte maneira:

```
// YourExtDLL.Def:
LIBRARY      YOUREXTDLL
CODE         PRELOAD MOVEABLE DISCARDABLE
DATA         PRELOAD SINGLE
EXPORTS
    InitYourExtDLL
```

Adicione uma chamada para o `InitInstance` membro do `CWinApp` objeto derivado em cada DLL do MFC regular usando a DLL de extensão do MFC:

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

- [Inicializar uma DLL de extensão do MFC](run-time-library-behavior.md#initializing-extension-dlls)

- [Inicializar DLLs regulares do MFC](run-time-library-behavior.md#initializing-regular-dlls)

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [DLLs de extensão de MFC](extension-dlls.md)

- [DLLs regulares do MFC vinculadas estaticamente ao MFC](regular-dlls-statically-linked-to-mfc.md)

- [DLLs regulares do MFC vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [Usando o MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)

- [Versão da DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)

## <a name="see-also"></a>Confira também

[DLLs de extensão de MFC](extension-dlls.md)
