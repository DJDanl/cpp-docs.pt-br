---
title: "Escrevendo um manipulador de exceção | Microsoft Docs"
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
- structured exception handling [C++], exception handlers
- exception handling [C++], exception handlers
ms.assetid: 71473fee-f773-4a34-bf12-82a3af79579c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 52d102f29a015ea077e9ec94a9f1ed63f44f7c1d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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