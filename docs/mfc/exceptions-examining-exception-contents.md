---
title: "Exce&#231;&#245;es: examinando o conte&#250;do da exce&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "blocos catch, Exceções de função MFC"
  - "Classe CException, exceções de classe"
  - "tratamento de exceção, MFC"
  - "lançando exceções, conteúdo de exceção"
  - "tratamento de exceções de try-catch, conteúdo de exceção"
  - "tratamento de exceções de try-catch, Exceções de função MFC"
ms.assetid: dfda4782-b969-4f60-b867-cc204ea7f33a
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es: examinando o conte&#250;do da exce&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Embora o argumento de um bloco de **catch** pode ser de praticamente qualquer tipo de dados, as funções de MFC lançam exceções de tipos derivados da classe `CException`.  Para capturar uma exceção gerada por uma função de MFC, em seguida, você grava um bloco de **catch** cujo argumento seja um ponteiro para um objeto de `CException` \(ou a um objeto derivado de `CException`, como `CMemoryException`\).  Dependendo do tipo exato de exceção, você pode examinar os membros de dados do objeto de exceção das informações de procedimento sobre o motivo específico que causou a exceção.  
  
 Por exemplo, o tipo de `CFileException` tem o membro de dados de `m_cause` , que contém um tipo enumerado que especifica a causa da exceção de arquivo.  Alguns exemplos dos valores de retorno possíveis são **CFileException::fileNotFound** e **CFileException::readOnly**.  
  
 O exemplo a seguir mostra como examinar o conteúdo de `CFileException`.  Outros tipos de exceção podem ser examinados de forma semelhante.  
  
 [!code-cpp[NVC_MFCExceptions#13](../mfc/codesnippet/CPP/exceptions-examining-exception-contents_1.cpp)]  
  
 Para obter mais informações, consulte [Exceções: Liberando objetos nas exceções](../Topic/Exceptions:%20Freeing%20Objects%20in%20Exceptions.md) e [Exceções: Capturando e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
## Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)