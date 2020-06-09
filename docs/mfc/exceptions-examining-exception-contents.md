---
title: 'Exceções: examinando o conteúdo da exceção'
ms.date: 11/04/2016
helpviewer_keywords:
- exception handling [MFC], MFC
- try-catch exception handling [MFC], MFC function exceptions
- catch blocks, MFC function exceptions
- CException class [MFC], class exceptions
- try-catch exception handling [MFC], exception contents
- throwing exceptions [MFC], exception contents
ms.assetid: dfda4782-b969-4f60-b867-cc204ea7f33a
ms.openlocfilehash: 8554dda2f465aa058cea3d257c22ec38bc6e2c18
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625901"
---
# <a name="exceptions-examining-exception-contents"></a>Exceções: examinando o conteúdo da exceção

Embora o argumento de um bloco **Catch** possa ser de quase qualquer tipo de dados, as funções do MFC geram exceções de tipos derivados da classe `CException` . Para capturar uma exceção gerada por uma função MFC, você escreve um bloco **Catch** cujo argumento é um ponteiro para um `CException` objeto (ou um objeto derivado de, como `CException` `CMemoryException` ). Dependendo do tipo exato da exceção, você pode examinar os membros de dados do objeto de exceção para coletar informações sobre a causa específica da exceção.

Por exemplo, o `CFileException` tipo tem o `m_cause` membro de dados, que contém um tipo enumerado que especifica a causa da exceção de arquivo. Alguns exemplos dos possíveis valores de retorno são `CFileException::fileNotFound` e `CFileException::readOnly` .

O exemplo a seguir mostra como examinar o conteúdo de um `CFileException` . Outros tipos de exceção podem ser examinados da mesma forma.

[!code-cpp[NVC_MFCExceptions#13](codesnippet/cpp/exceptions-examining-exception-contents_1.cpp)]

Para obter mais informações, consulte [exceções: liberando objetos em exceções](exceptions-freeing-objects-in-exceptions.md) e exceções [: capturando e excluindo exceções](exceptions-catching-and-deleting-exceptions.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](exception-handling-in-mfc.md)
