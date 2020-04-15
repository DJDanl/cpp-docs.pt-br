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
ms.openlocfilehash: afad5335bedf001329ecb401a8a16c663afb5571
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371586"
---
# <a name="exceptions-using-mfc-macros-and-c-exceptions"></a>Exceções: usando macros MFC e exceções do C++

Este artigo discute considerações para escrever código que usa tanto as macros de manipulação de exceção do MFC quanto as palavras-chave c++.

Este artigo aborda os seguintes tópicos:

- [Misturando palavras-chave de exceção e macros](#_core_mixing_exception_keywords_and_macros)

- [Tente blocos dentro de blocos de captura](#_core_try_blocks_inside_catch_blocks)

## <a name="mixing-exception-keywords-and-macros"></a><a name="_core_mixing_exception_keywords_and_macros"></a>Misturando palavras-chave de exceção e macros

Você pode misturar macros de exceção do MFC e palavras-chave de exceção C++ no mesmo programa. Mas você não pode misturar macros MFC com palavras-chave de exceção C++ no mesmo bloco porque as macros excluem objetos de exceção automaticamente quando eles saem do escopo, enquanto o código usando as palavras-chave de manipulação de exceção não. Para obter mais informações, consulte o artigo [Exceções: Captura e Exclusão exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).

A principal diferença entre as macros e as palavras-chave é que as macros "automaticamente" excluem uma exceção capturada quando a exceção sai do escopo. Código usando as palavras-chave não; exceções capturadas em um bloco de captura devem ser explicitamente excluídas. A mistura de macros e palavras-chave de exceção C++ pode causar vazamentos de memória quando um objeto de exceção não é excluído ou aumentar a corrupção quando uma exceção é excluída duas vezes.

O código a seguir, por exemplo, invalida o ponteiro de exceção:

[!code-cpp[NVC_MFCExceptions#10](../mfc/codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_1.cpp)]

O problema `e` ocorre porque é excluído quando a execução passa para fora do bloco **CATCH** "interno". Usar a **macro THROW_LAST** em vez da indade **THROW** fará com que o bloco **CATCH** "externo" receba um ponteiro válido:

[!code-cpp[NVC_MFCExceptions#11](../mfc/codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_2.cpp)]

## <a name="try-blocks-inside-catch-blocks"></a><a name="_core_try_blocks_inside_catch_blocks"></a>Tente blocos dentro de blocos de captura

Você não pode relançar a exceção atual de dentro de um bloco **de tentativa** situado dentro de um bloco **CATCH.** O exemplo a seguir é inválido:

[!code-cpp[NVC_MFCExceptions#12](../mfc/codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_3.cpp)]

Para obter mais informações, consulte [Exceções: Examinando o conteúdo de exceções](../mfc/exceptions-examining-exception-contents.md).

## <a name="see-also"></a>Confira também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
