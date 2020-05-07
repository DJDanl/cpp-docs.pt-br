---
title: LoadLibrary e AfxLoadLibrary
description: Usando LoadLibrary e AfxLoadLibrary para carregamento explícito de DLLs em MSVC.
ms.date: 01/28/2020
f1_keywords:
- LoadLibrary
helpviewer_keywords:
- DLLs [C++], AfxLoadLibrary
- DLLs [C++], LoadLibrary
- AfxLoadLibrary method
- LoadLibrary method
- explicit linking [C++]
ms.assetid: b4535d19-6243-4146-a31a-a5cca4c7c9e3
ms.openlocfilehash: f803212c4485f7517dc42802f1ff581ffa4e609d
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821532"
---
# <a name="loadlibrary-and-afxloadlibrary"></a>LoadLibrary e AfxLoadLibrary

Processa a chamada [LoadLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw) ou [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) para vincular explicitamente a uma dll. (Os aplicativos MFC usam [AfxLoadLibrary](../mfc/reference/application-information-and-management.md#afxloadlibrary) ou [AfxLoadLibraryEx](../mfc/reference/application-information-and-management.md#afxloadlibraryex).) Se a função for bem sucedido, ela mapeará a DLL especificada para o espaço de endereço do processo de chamada e retornará um identificador para a DLL. O identificador é necessário em outras funções usadas para vinculação explícita — por exemplo, `GetProcAddress` e `FreeLibrary`. Para obter mais informações, consulte [vinculação explícita](linking-an-executable-to-a-dll.md#linking-explicitly).

`LoadLibrary`tenta localizar a DLL usando a mesma sequência de pesquisa usada para vinculação implícita. `LoadLibraryEx`oferece mais controle sobre a ordem do caminho de pesquisa. Para obter mais informações, consulte [ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/dlls/dynamic-link-library-search-order). Se o sistema não conseguir localizar a DLL ou se a função de ponto de entrada retornar `LoadLibrary` false, retornará NULL. Se a chamada para `LoadLibrary` especificar um módulo DLL que já esteja mapeado no espaço de endereço do processo de chamada, a função retornará um identificador da dll e incrementará a contagem de referência do módulo.

Se a DLL tiver uma função de ponto de entrada, o sistema operacional chamará a função no contexto do thread que chamou `LoadLibrary` ou `LoadLibraryEx`. A função de ponto de entrada não será chamada se a DLL já estiver anexada ao processo. Isso acontece quando uma chamada anterior para `LoadLibrary` ou `LoadLibraryEx` para a dll não tinha uma chamada correspondente à `FreeLibrary` função.

Para aplicativos MFC que carregam DLLs de extensão MFC, recomendamos que `AfxLoadLibrary` você `AfxLoadLibraryEx` use ou `LoadLibrary` em `LoadLibraryEx`vez de ou. As funções do MFC lidam com a sincronização de thread antes de carregar a DLL explicitamente. As interfaces (protótipos de função) `AfxLoadLibrary` para `AfxLoadLibraryEx` e são as mesmas `LoadLibrary` de `LoadLibraryEx`e.

Se o Windows não puder carregar a DLL, seu processo poderá tentar se recuperar do erro. Por exemplo, ele poderia notificar o usuário sobre o erro e solicitar outro caminho para a DLL.

> [!IMPORTANT]
> Certifique-se de especificar o caminho completo de qualquer DLL. O diretório atual pode ser pesquisado primeiro quando os arquivos são `LoadLibrary`carregados pelo. Se você não qualificar totalmente o caminho do arquivo, um arquivo que não seja o pretendido poderá ser carregado. Ao criar uma DLL, use a opção vinculador [/DEPENDENTLOADFLAG](reference/dependentloadflag.md) para especificar uma ordem de pesquisa para dependências de dll vinculadas estaticamente. Dentro de suas DLLs, use ambos os caminhos completos para dependências explicitamente `LoadLibraryEx` carregadas, e ou `AfxLoadLibraryEx` chame parâmetros para especificar a ordem de pesquisa do módulo. Para obter mais informações, consulte [segurança da biblioteca de vínculo dinâmico](/windows/win32/dlls/dynamic-link-library-security) e [ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/dlls/dynamic-link-library-search-order).

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#linking-implicitly)

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order)

- [FreeLibrary e AfxFreeLibrary](freelibrary-and-afxfreelibrary.md)

- [GetProcAddress](getprocaddress.md)

## <a name="see-also"></a>Confira também

- [Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
