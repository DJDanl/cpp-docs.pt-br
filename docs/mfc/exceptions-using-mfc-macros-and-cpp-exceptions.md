---
title: 'Exceções: Usando Macros MFC e exceções do C++'
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
ms.openlocfilehash: 00e88ddabf3a8e8b591bebae7ebc8ced0e1dc637
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406009"
---
# <a name="exceptions-using-mfc-macros-and-c-exceptions"></a>Exceções: Usando Macros MFC e exceções do C++

Este artigo aborda considerações para escrever código que usa as macros de tratamento de exceção do MFC e as palavras-chave de tratamento de exceções C++.

Este artigo aborda os seguintes tópicos:

- [Combinação de macros e palavras-chave de exceção](#_core_mixing_exception_keywords_and_macros)

- [Tente blocos dentro de blocos catch](#_core_try_blocks_inside_catch_blocks)

##  <a name="_core_mixing_exception_keywords_and_macros"></a> Combinação de Macros e palavras-chave de exceção

Você pode combinar macros de exceção MFC e palavras-chave de exceção de C++ no mesmo programa. Mas você não pode combinar macros MFC com palavras-chave de exceção de C++ no mesmo bloco porque as macros excluir objetos de exceção automaticamente quando eles saem do escopo, enquanto o código usando as palavras-chave de tratamento de exceção não. Para obter mais informações, consulte o artigo [exceções: Obtendo e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).

A principal diferença entre as macros e as palavras-chave é que as macros "automaticamente" excluir uma exceção capturada quando a exceção sai do escopo. Código usando as palavras-chave não; as exceções detectadas em um bloco catch devem ser explicitamente excluídas. Combinação de macros e palavras-chave de exceção de C++ pode causar vazamentos de memória quando um objeto de exceção não é excluído ou corrupção de heap quando uma exceção é excluída duas vezes.

O código a seguir, por exemplo, invalida o ponteiro de exceção:

[!code-cpp[NVC_MFCExceptions#10](../mfc/codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_1.cpp)]

O problema ocorre porque `e` é excluído quando a execução passará "interno" **CATCH** bloco. Usando o **THROW_LAST** macro em vez da **THROW** instrução fará com que o "externa" **CATCH** bloco para receber um ponteiro válido:

[!code-cpp[NVC_MFCExceptions#11](../mfc/codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_2.cpp)]

##  <a name="_core_try_blocks_inside_catch_blocks"></a> Tente blocos dentro de blocos Catch

Você não pode gerar novamente a exceção atual de dentro um **tente** bloco que está dentro de uma **CATCH** bloco. O exemplo a seguir é inválido:

[!code-cpp[NVC_MFCExceptions#12](../mfc/codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_3.cpp)]

Para obter mais informações, consulte [exceções: Examinando o conteúdo da exceção](../mfc/exceptions-examining-exception-contents.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
