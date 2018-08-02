---
title: Escrevendo um manipulador de término | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d9773817337bce2f054b279724db9859cc2faa41
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39462827"
---
# <a name="writing-a-termination-handler"></a>Escrevendo um manipulador de término
Diferente de um manipulador de exceção, um manipulador de término sempre é executado, independentemente do bloco de código protegido encerrado normalmente. O único propósito do manipulador de término deve ser garantir que os recursos, como memória, identificadores e arquivos, sejam fechados corretamente, independentemente de como uma seção de código termina a execução.  
  
 Os manipuladores de término usam a instrução try-finally.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [A instrução try-finally](../cpp/try-finally-statement.md)  
  
-   [Limpando recursos](../cpp/cleaning-up-resources.md)  
  
-   [Tempo de ações no tratamento de exceções](../cpp/timing-of-exception-handling-a-summary.md)  
  
-   [Restrições em manipuladores de término](../cpp/restrictions-on-termination-handlers.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)