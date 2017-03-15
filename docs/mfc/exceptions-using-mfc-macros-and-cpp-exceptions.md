---
title: "Exce&#231;&#245;es: usando macros MFC e exce&#231;&#245;es do C++ | Microsoft Docs"
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
  - "blocos catch, excluindo código explicitamente em"
  - "blocos catch, misto"
  - "tratamento de exceção, MFC"
  - "tratamento de exceção, linguagem mista"
  - "objetos de exceção"
  - "objetos de exceção, excluindo"
  - "exceções, Macros MFC vs. palavras-chave C++"
  - "corrupção de heap"
  - "perdas de memória, objeto de exceção não excluído"
  - "blocos catch aninhados"
  - "blocos try aninhados"
  - "tratamento de exceções de try-catch, mesclando macros MFC e palavras-chave C++"
  - "tratamento de exceções de try-catch, blocos try aninhados"
ms.assetid: d664a83d-879b-44d4-bdf0-029f0aca69e9
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es: usando macros MFC e exce&#231;&#245;es do C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve considerações para escrever o código que usa macros manipulação de exceções gerais de MFC e as palavras\-chave de controle de exceções das linguagens C\+\+.  
  
 Este artigo abrange os seguintes tópicos:  
  
-   [Palavra\-chave e macros de combinação de exceção](#_core_mixing_exception_keywords_and_macros)  
  
-   [Blocos de try\/catch de dentro dos blocos da tentativa](#_core_try_blocks_inside_catch_blocks)  
  
##  <a name="_core_mixing_exception_keywords_and_macros"></a> Palavra\-chave e macros de combinação de exceção  
 Você pode combinar palavras\-chave de macros de exceção MFC e de exceção C\+\+ no mesmo programa.  Mas você não pode combinar macros de MFC com as palavras\-chave de exceção C\+\+ no mesmo bloco como macros excluem objetos de exceção automaticamente quando sair do escopo, enquanto que o código que usa palavras\-chave manipulação de exceções gerais não.  Para obter mais informações, consulte o artigo [Exceções: Capturando e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
 A principal diferença entre as macros e keywords é que as macros “automaticamente” excluir uma exceção capturada quando a exceção sai do escopo.  O código que usa palavras\-chave não faz; as exceções capturadas em um bloco de captura devem ser explicitamente excluídas.  Macros de combinação e de exceção C\+\+ palavras\-chave podem causar vazamentos de memória quando um objeto de exceção não é excluído, ou corrupção do heap quando uma exceção é excluída duas vezes em.  
  
 O código a seguir, por exemplo, invalida o ponteiro de exceção:  
  
 [!code-cpp[NVC_MFCExceptions#10](../mfc/codesnippet/CPP/exceptions-using-mfc-macros-and-cpp-exceptions_1.cpp)]  
  
 O problema ocorre porque `e` é excluído quando a execução passa bloco “interno” de **CATCH** .  Usar a macro de `THROW_LAST` em vez da instrução de **THROW** fará com que o bloco “externa” de **CATCH** recebe um ponteiro válido:  
  
 [!code-cpp[NVC_MFCExceptions#11](../mfc/codesnippet/CPP/exceptions-using-mfc-macros-and-cpp-exceptions_2.cpp)]  
  
##  <a name="_core_try_blocks_inside_catch_blocks"></a> Blocos de try\/catch de dentro dos blocos da tentativa  
 Não é possível novamente geram a exceção atual dentro de um bloco de **try** que está dentro de um bloco de **CATCH** .  O exemplo a seguir é inválido:  
  
 [!code-cpp[NVC_MFCExceptions#12](../mfc/codesnippet/CPP/exceptions-using-mfc-macros-and-cpp-exceptions_3.cpp)]  
  
 Para obter mais informações, consulte [Exceções: Conteúdo de auditoria de exceção](../mfc/exceptions-examining-exception-contents.md).  
  
## Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)