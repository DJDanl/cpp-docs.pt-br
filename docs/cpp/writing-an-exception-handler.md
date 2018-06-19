---
title: Escrevendo um manipulador de exceção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- structured exception handling [C++], exception handlers
- exception handling [C++], exception handlers
ms.assetid: 71473fee-f773-4a34-bf12-82a3af79579c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 01d16d95cc246ad7ef0fe9f03c20e2652fe81aad
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32421816"
---
# <a name="writing-an-exception-handler"></a>Escrevendo um manipulador de exceção
Normalmente, os manipuladores de exceções são usados para responder a erros específicos. Você pode usar a sintaxe de manipulação de exceções para filtrar todas as exceções que não sejam aquelas que você sabe tratar. Outras exceções devem ser passadas para outros manipuladores (possivelmente na biblioteca em tempo de execução ou no sistema operacional) criados para procurar essas exceções específicas.  
  
 Os manipuladores de exceções usam a instrução try-except.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Try-except instrução](../cpp/try-except-statement.md)  
  
-   [Escrevendo um filtro de exceção](../cpp/writing-an-exception-filter.md)  
  
-   [Acionando exceções de software](../cpp/raising-software-exceptions.md)  
  
-   [Exceções de hardware](../cpp/hardware-exceptions.md)  
  
-   [Restrições em manipuladores de exceção](../cpp/restrictions-on-exception-handlers.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)