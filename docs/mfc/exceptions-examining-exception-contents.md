---
title: 'Exceções: Examinando o conteúdo da exceção | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- exception handling [MFC], MFC
- try-catch exception handling [MFC], MFC function exceptions
- catch blocks, MFC function exceptions
- CException class [MFC], class exceptions
- try-catch exception handling [MFC], exception contents
- throwing exceptions [MFC], exception contents
ms.assetid: dfda4782-b969-4f60-b867-cc204ea7f33a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f5fb0df0c16e9aea2f334b6c08f92a3bef4ea486
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46378370"
---
# <a name="exceptions-examining-exception-contents"></a>Exceções: examinando o conteúdo da exceção

Embora uma **catch** argumento do bloco pode ser de praticamente qualquer tipo de dados, as funções MFC lançam exceções de tipos derivadas da classe `CException`. Para capturar uma exceção gerada por uma função do MFC, em seguida, você escreve uma **catch** bloco cujo argumento é um ponteiro para um `CException` objeto (ou um objeto derivado de `CException`, como `CMemoryException`). Dependendo do tipo exato da exceção, você pode examinar os membros de dados do objeto de exceção para obter informações sobre a causa específica da exceção.

Por exemplo, o `CFileException` tipo tem o `m_cause` membro de dados, que contém um tipo enumerado que especifica a causa da exceção de arquivo. Alguns exemplos dos possíveis valores de retorno são `CFileException::fileNotFound` e `CFileException::readOnly`.

O exemplo a seguir mostra como examinar o conteúdo de um `CFileException`. Outros tipos de exceção podem ser examinados da mesma forma.

[!code-cpp[NVC_MFCExceptions#13](../mfc/codesnippet/cpp/exceptions-examining-exception-contents_1.cpp)]

Para obter mais informações, consulte [exceções: liberando objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md) e [exceções: exceções de detectar e exclua](../mfc/exceptions-catching-and-deleting-exceptions.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

