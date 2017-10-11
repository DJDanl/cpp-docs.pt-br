---
title: "Escrevendo um manipulador de término | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- structured exception handling [C++], termination handlers
- exceptions [C++], terminating
- termination handlers [C++], writing
- handlers [C++]
- handlers [C++], termination
- termination handlers
- exception handling [C++], termination handlers
- try-catch keyword [C++], termination handlers
ms.assetid: 52aa1f8f-f8dd-44b8-be94-5e2fc88d44fb
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 06fb01f2ee2782f8786308554923b3c5597a4574
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="writing-a-termination-handler"></a>Escrevendo um manipulador de término
Diferente de um manipulador de exceção, um manipulador de término sempre é executado, independentemente do bloco de código protegido encerrado normalmente. O único propósito do manipulador de término deve ser garantir que os recursos, como memória, identificadores e arquivos, sejam fechados corretamente, independentemente de como uma seção de código termina a execução.  
  
 Os manipuladores de término usam a instrução try-finally.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Instrução try-finally](../cpp/try-finally-statement.md)  
  
-   [Limpando recursos](../cpp/cleaning-up-resources.md)  
  
-   [Tempo de ações no tratamento de exceção](../cpp/timing-of-exception-handling-a-summary.md)  
  
-   [Restrições em manipuladores de encerramento](../cpp/restrictions-on-termination-handlers.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
