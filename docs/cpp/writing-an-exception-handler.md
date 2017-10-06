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
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 5f3f81ff6ea954cda7270ff32650d5744280d918
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
