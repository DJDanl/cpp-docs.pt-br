---
title: "Exceções: Examinando o conteúdo de exceção | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 953dd61247f7d14ad04d5d5f85529c89f3aaad9d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exceptions-examining-exception-contents"></a>Exceções: examinando o conteúdo da exceção
Embora um **catch** argumento do bloco pode ser de praticamente qualquer tipo de dados, as funções MFC lançam exceções de tipos derivados da classe `CException`. Para capturar uma exceção gerada por uma função MFC, em seguida, você escreve um **catch** bloco cujo argumento é um ponteiro para um `CException` objeto (ou um objeto derivado de `CException`, como `CMemoryException`). Dependendo do tipo exato da exceção, você pode examinar os membros de dados do objeto de exceção para obter informações sobre a causa específica da exceção.  
  
 Por exemplo, o `CFileException` tipo tem o `m_cause` membro de dados, que contém um tipo enumerado que especifica a causa da exceção de arquivo. Alguns exemplos de como os possíveis valores de retorno são **CFileException::fileNotFound** e **CFileException::readOnly**.  
  
 O exemplo a seguir mostra como examinar o conteúdo de um `CFileException`. Outros tipos de exceção podem ser examinados da mesma forma.  
  
 [!code-cpp[NVC_MFCExceptions#13](../mfc/codesnippet/cpp/exceptions-examining-exception-contents_1.cpp)]  
  
 Para obter mais informações, consulte [exceções: liberando objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md) e [exceções: exceções de detectar e excluindo](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

