---
title: 'Exceções: usando macros MFC e exceções do C++'
ms.date: 11/04/2016
helpviewer_keywords:
- exception objects [MFC]
- memory leaks [MFC], exception object not deleted
- exception handling [MFC], MFC
- try-catch exception handling [MFC], mixing MFC macros and C++ keywords
- exception objects [MFC], deleting
- exceptions [MFC], MFC macros vs. C++ keywords
- catch blocks [MFC], mixed
- exception handling [MFC], mixed-language
- nested try blocks [MFC]
- catch blocks [MFC], explicitly deleting code in
- try-catch exception handling [MFC], nested try blocks
- heap corruption [MFC]
- nested catch blocks [MFC]
ms.assetid: d664a83d-879b-44d4-bdf0-029f0aca69e9
ms.openlocfilehash: 9e97eb545dedd3ac38dd93471f82aecc382717ae
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223168"
---
# <a name="exceptions-using-mfc-macros-and-c-exceptions"></a>Exceções: usando macros MFC e exceções do C++

Este artigo discute considerações para escrever código que usa as macros de tratamento de exceção do MFC e as palavras-chave de manipulação de exceções do C++.

Este artigo aborda os seguintes tópicos:

- [Misturar palavras-chave de exceção e macros](#_core_mixing_exception_keywords_and_macros)

- [Blocos try dentro de blocos catch](#_core_try_blocks_inside_catch_blocks)

## <a name="mixing-exception-keywords-and-macros"></a><a name="_core_mixing_exception_keywords_and_macros"></a>Misturar palavras-chave de exceção e macros

Você pode misturar macros de exceção do MFC e palavras-chave de exceção do C++ no mesmo programa. Mas você não pode misturar macros do MFC com palavras-chave de exceção do C++ no mesmo bloco, pois as macros excluem objetos de exceção automaticamente quando saem do escopo, enquanto o código que usa as palavras-chave de manipulação de exceção não. Para obter mais informações, consulte o artigo [exceções: capturando e excluindo exceções](exceptions-catching-and-deleting-exceptions.md).

A principal diferença entre as macros e as palavras-chave é que as macros "automaticamente" excluem uma exceção capturada quando a exceção sai do escopo. O código que usa as palavras-chave não; as exceções detectadas em um bloco catch devem ser excluídas explicitamente. A combinação de macros e palavras-chave de exceção do C++ pode causar vazamentos de memória quando um objeto de exceção não é excluído ou corrupção de heap quando uma exceção é excluída duas vezes.

O código a seguir, por exemplo, invalida o ponteiro de exceção:

[!code-cpp[NVC_MFCExceptions#10](codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_1.cpp)]

O problema ocorre porque o `e` é excluído quando a execução passa do bloco **Catch** "interno". Usar a macro **THROW_LAST** em vez da instrução **throw** fará com que o bloco **Catch** "externo" receba um ponteiro válido:

[!code-cpp[NVC_MFCExceptions#11](codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_2.cpp)]

## <a name="try-blocks-inside-catch-blocks"></a><a name="_core_try_blocks_inside_catch_blocks"></a>Blocos try dentro de blocos catch

Você não pode lançar novamente a exceção atual de dentro de um **`try`** bloco que está dentro de um bloco **Catch** . O exemplo a seguir é inválido:

[!code-cpp[NVC_MFCExceptions#12](codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_3.cpp)]

Para obter mais informações, consulte [exceções: examinando o conteúdo da exceção](exceptions-examining-exception-contents.md).

## <a name="see-also"></a>Confira também

[Tratamento de exceção](exception-handling-in-mfc.md)
