---
title: 'Exceções: Examinando o conteúdo da exceção'
ms.date: 11/04/2016
helpviewer_keywords:
- exception handling [MFC], MFC
- try-catch exception handling [MFC], MFC function exceptions
- catch blocks, MFC function exceptions
- CException class [MFC], class exceptions
- try-catch exception handling [MFC], exception contents
- throwing exceptions [MFC], exception contents
ms.assetid: dfda4782-b969-4f60-b867-cc204ea7f33a
ms.openlocfilehash: f6f9bca6f6b7ca9d104cb492c760ab89f7163afd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405996"
---
# <a name="exceptions-examining-exception-contents"></a>Exceções: Examinando o conteúdo da exceção

Embora uma **catch** argumento do bloco pode ser de praticamente qualquer tipo de dados, as funções MFC lançam exceções de tipos derivadas da classe `CException`. Para capturar uma exceção gerada por uma função do MFC, em seguida, você escreve uma **catch** bloco cujo argumento é um ponteiro para um `CException` objeto (ou um objeto derivado de `CException`, como `CMemoryException`). Dependendo do tipo exato da exceção, você pode examinar os membros de dados do objeto de exceção para obter informações sobre a causa específica da exceção.

Por exemplo, o `CFileException` tipo tem o `m_cause` membro de dados, que contém um tipo enumerado que especifica a causa da exceção de arquivo. Alguns exemplos dos possíveis valores de retorno são `CFileException::fileNotFound` e `CFileException::readOnly`.

O exemplo a seguir mostra como examinar o conteúdo de um `CFileException`. Outros tipos de exceção podem ser examinados da mesma forma.

[!code-cpp[NVC_MFCExceptions#13](../mfc/codesnippet/cpp/exceptions-examining-exception-contents_1.cpp)]

Para obter mais informações, consulte [exceções: Liberando objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md) e [exceções: Obtendo e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
