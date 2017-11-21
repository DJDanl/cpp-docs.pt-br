---
title: "Exceções: Usando Macros MFC e exceções C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ecf00200b87b1999293e8c6d69e922c3052d5c9c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="exceptions-using-mfc-macros-and-c-exceptions"></a>Exceções: usando macros MFC e exceções do C++
Este artigo aborda considerações para escrever código que usa as macros de tratamento de exceção MFC e as palavras-chave de tratamento de exceções C++.  
  
 Este artigo aborda os seguintes tópicos:  
  
-   [Mesclando macros e palavras-chave de exceção](#_core_mixing_exception_keywords_and_macros)  
  
-   [Tente blocos dentro de blocos catch](#_core_try_blocks_inside_catch_blocks)  
  
##  <a name="_core_mixing_exception_keywords_and_macros"></a>Mesclando Macros e palavras-chave de exceção  
 Você pode combinar macros de exceção MFC e palavras-chave de exceção de C++ no mesmo programa. Mas você não pode misturar macros MFC com palavras-chave de exceção de C++ no mesmo bloco porque as macros excluir objetos de exceção automaticamente quando saem do escopo, e o código usando as palavras-chave de tratamento de exceção não. Para obter mais informações, consulte o artigo [exceções: exceções de detectar e excluindo](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
 A principal diferença entre as macros e as palavras-chave é que as macros "automaticamente" excluir uma exceção capturada quando a exceção sai do escopo. O código usando as palavras-chave não; exceções detectadas em um bloco catch devem ser excluídas explicitamente. Mesclando macros e palavras-chave de exceção de C++ pode causar vazamentos de memória quando um objeto de exceção não é excluído ou corrupção de pilha quando uma exceção é excluída duas vezes.  
  
 O código a seguir, por exemplo, invalida o ponteiro de exceção:  
  
 [!code-cpp[NVC_MFCExceptions#10](../mfc/codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_1.cpp)]  
  
 O problema ocorre porque `e` é excluído quando a execução passa "interno" **CATCH** bloco. Usando o `THROW_LAST` macro em vez do **gerar** instrução fará com que o "externa" **CATCH** bloco para receber um ponteiro válido:  
  
 [!code-cpp[NVC_MFCExceptions#11](../mfc/codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_2.cpp)]  
  
##  <a name="_core_try_blocks_inside_catch_blocks"></a>Tente blocos dentro de blocos Catch  
 Você não pode gerar novamente a exceção atual de dentro um **tente** blocos dentro de um **CATCH** bloco. O exemplo a seguir é inválido:  
  
 [!code-cpp[NVC_MFCExceptions#12](../mfc/codesnippet/cpp/exceptions-using-mfc-macros-and-cpp-exceptions_3.cpp)]  
  
 Para obter mais informações, consulte [exceções: examinando o conteúdo da exceção](../mfc/exceptions-examining-exception-contents.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

