---
title: 'Exceções: Examinando o conteúdo de exceção | Microsoft Docs'
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
ms.openlocfilehash: 82c7453b92ce14fbbcd20ea0f9a8bd8a7a2b5b6d
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36932228"
---
# <a name="exceptions-examining-exception-contents"></a>Exceções: examinando o conteúdo da exceção
Embora um **catch** argumento do bloco pode ser de praticamente qualquer tipo de dados, as funções MFC lançam exceções de tipos derivados da classe `CException`. Para capturar uma exceção gerada por uma função MFC, em seguida, você escreve um **catch** bloco cujo argumento é um ponteiro para um `CException` objeto (ou um objeto derivado de `CException`, como `CMemoryException`). Dependendo do tipo exato da exceção, você pode examinar os membros de dados do objeto de exceção para obter informações sobre a causa específica da exceção.  
  
 Por exemplo, o `CFileException` tipo tem o `m_cause` membro de dados, que contém um tipo enumerado que especifica a causa da exceção de arquivo. Alguns exemplos de como os possíveis valores de retorno são `CFileException::fileNotFound` e `CFileException::readOnly`.  
  
 O exemplo a seguir mostra como examinar o conteúdo de um `CFileException`. Outros tipos de exceção podem ser examinados da mesma forma.  
  
 [!code-cpp[NVC_MFCExceptions#13](../mfc/codesnippet/cpp/exceptions-examining-exception-contents_1.cpp)]  
  
 Para obter mais informações, consulte [exceções: liberando objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md) e [exceções: exceções de detectar e excluindo](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

