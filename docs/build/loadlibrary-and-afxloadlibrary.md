---
title: LoadLibrary e AfxLoadLibrary
ms.date: 05/24/2018
f1_keywords:
- LoadLibrary
helpviewer_keywords:
- DLLs [C++], AfxLoadLibrary
- DLLs [C++], LoadLibrary
- AfxLoadLibrary method
- LoadLibrary method
- explicit linking [C++]
ms.assetid: b4535d19-6243-4146-a31a-a5cca4c7c9e3
ms.openlocfilehash: c7700dd865e320686a2ad8bd036f207b9ecee6ac
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493216"
---
# <a name="loadlibrary-and-afxloadlibrary"></a>LoadLibrary e AfxLoadLibrary

Os processos chamam [LoadLibraryExA](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexa) ou [LoadLibraryExW](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) (ou [AfxLoadLibrary](../mfc/reference/application-information-and-management.md#afxloadlibrary)) para vincular explicitamente a uma dll. Se a função for bem sucedido, ela mapeará a DLL especificada para o espaço de endereço do processo de chamada e retornará um identificador para a DLL que pode ser usado com outras funções em vinculação explícita `GetProcAddress` — `FreeLibrary`por exemplo, e.

`LoadLibrary`tenta localizar a DLL usando a mesma sequência de pesquisa usada para vinculação implícita. Se o sistema não puder localizar a dll ou se a função de ponto de entrada retornar `LoadLibrary` false, retornará NULL. Se a chamada para `LoadLibrary` especificar um módulo DLL que já esteja mapeado no espaço de endereço do processo de chamada, a função retornará um identificador da dll e incrementará a contagem de referência do módulo.

Se a DLL tiver uma função de ponto de entrada, o sistema operacional chamará a função no contexto do thread que chamou `LoadLibrary`. A função de ponto de entrada não será chamada se a dll já estiver anexada ao processo devido a uma chamada anterior `LoadLibrary` a que não tem nenhuma chamada correspondente `FreeLibrary` à função.

Para aplicativos MFC que carregam DLLs de extensão do MFC, recomendamos `AfxLoadLibrary` que você `LoadLibrary`use em vez de. `AfxLoadLibrary`manipula a sincronização de threads `LoadLibrary`antes de você chamar. A interface (protótipo de função) `AfxLoadLibrary` é a mesma que `LoadLibrary`.

Se o Windows não puder carregar a DLL, o processo poderá tentar se recuperar do erro. Por exemplo, o processo poderia notificar o usuário sobre o erro e pedir ao usuário para especificar outro caminho para a DLL.

> [!IMPORTANT]
> Certifique-se de especificar o caminho completo de qualquer DLL. O diretório atual é pesquisado primeiro quando os arquivos são carregados. Se você não qualificar o caminho do arquivo, um arquivo que não seja o pretendido poderá ser carregado. Outra maneira de evitar isso é usando a opção de vinculador [/DEPENDENTLOADFLAG](reference/dependentloadflag.md) .

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#linking-implicitly)

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order)

- [FreeLibrary e AfxFreeLibrary](freelibrary-and-afxfreelibrary.md)

- [GetProcAddress](getprocaddress.md)

## <a name="see-also"></a>Consulte também

- [Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
