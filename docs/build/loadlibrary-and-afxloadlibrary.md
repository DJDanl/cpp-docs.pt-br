---
title: LoadLibrary e AfxLoadLibrary | Microsoft Docs
ms.custom: ''
ms.date: 05/24/2018
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- LoadLibrary
dev_langs:
- C++
helpviewer_keywords:
- DLLs [C++], AfxLoadLibrary
- DLLs [C++], LoadLibrary
- AfxLoadLibrary method
- LoadLibrary method
- explicit linking [C++]
ms.assetid: b4535d19-6243-4146-a31a-a5cca4c7c9e3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bc3be5d374995c657021952184794f146c37f4dc
ms.sourcegitcommit: d1f576a0f59678edc3d93508cf46485138332178
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34753582"
---
# <a name="loadlibrary-and-afxloadlibrary"></a>LoadLibrary e AfxLoadLibrary

Processa chamada [LoadLibrary](https://go.microsoft.com/fwlink/p/?LinkID=259187) (ou [AfxLoadLibrary](../mfc/reference/application-information-and-management.md#afxloadlibrary)) para vincular explicitamente para uma DLL. Se a função tiver êxito, a DLL especificada é mapeado no espaço de endereço do processo de chamada e retorna um identificador para a DLL que pode ser usada com outras funções na vinculação explícita — por exemplo, `GetProcAddress` e `FreeLibrary`.

`LoadLibrary` tenta localizar a DLL usando a mesma sequência de pesquisa que é usada para vinculação implícita. Se o sistema não pode localizar a DLL ou se a função de ponto de entrada retorna FALSE, `LoadLibrary` retorna NULL. Se a chamada para `LoadLibrary` Especifica um módulo DLL que já está mapeado no espaço de endereço do processo de chamada, a função retorna um identificador de DLL e incrementa a contagem de referência do módulo.

Se a DLL tem uma função de ponto de entrada, o sistema operacional chamará a função no contexto do thread que chamou `LoadLibrary`. A função de ponto de entrada não é chamada se a DLL já está anexada ao processo devido a uma chamada anterior a `LoadLibrary` com nenhuma chamada correspondente para o `FreeLibrary` função.

Para aplicativos MFC que carregar DLLs de extensão do MFC, recomendamos que você use `AfxLoadLibrary` em vez de `LoadLibrary`. `AfxLoadLibrary` identificadores de sincronização de thread antes de chamar `LoadLibrary`. A interface (protótipo de função) `AfxLoadLibrary` é o mesmo que `LoadLibrary`.

Se o Windows não pode carregar a DLL, o processo pode tentar recuperar do erro. Por exemplo, o processo pode notificar o usuário sobre o erro e peça ao usuário para especificar outro caminho para a DLL.

> [!IMPORTANT]  
> Certifique-se de especificar o caminho completo de qualquer DLLs. O diretório atual é pesquisado pela primeira vez, quando os arquivos são carregados. Se você não qualificar o caminho do arquivo, um arquivo que não é o desejado pode ser carregado. Outra maneira de evitar isso é usando o [/DEPENDENTLOADFLAG](../build/reference/dependentloadflag.md) opção de vinculador.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Como vincular implicitamente para uma DLL](../build/linking-an-executable-to-a-dll.md#linking-implicitly)

- [Determinar qual método de associação usar](../build/linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Ordem de pesquisa de biblioteca de vínculo dinâmico](https://msdn.microsoft.com/library/windows/desktop/ms682586.aspx)

- [FreeLibrary e AfxFreeLibrary](../build/freelibrary-and-afxfreelibrary.md)

- [GetProcAddress](../build/getprocaddress.md)

## <a name="see-also"></a>Consulte também

- [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)
- [LoadLibrary](https://go.microsoft.com/fwlink/p/?LinkID=259187)
- [AfxLoadLibrary](../mfc/reference/application-information-and-management.md#afxloadlibrary)