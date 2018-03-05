---
title: "Usando com C++ de tratamento de exceções estruturado | Microsoft Docs"
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
- C++ exception handling, mixed with SEH
- structured exception handling [C++], with C++ exception handling
ms.assetid: ec34b528-8c26-4429-b24a-6a68553aaa91
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: db5d067a391512d56a2d01ce3052ac3fab061f28
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-structured-exception-handling-with-c"></a>Usando tratamento de exceções estruturado com C++
O tratamento de exceções estruturado descrito nesses artigos funciona com arquivos de origem de C e C++. No entanto, ele não é projetado especificamente para C++ e não é recomendado. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, o mecanismo de tratamento de exceções de C++ é mais flexível, pois pode tratar exceções de qualquer tipo.  
  
 Microsoft C++ agora dá suporte ao modelo de tratamento de exceções de C++, com base no padrão ANSI C++. Esse mecanismo controla automaticamente a destruição de objetos locais durante o desenrolamento da pilha. Se você estiver escrevendo código tolerante a falhas em C++ e desejar implementar o tratamento de exceções, é altamente recomendável que você use o tratamento de exceções de C++ em vez da estruturada. (Observe que, quando o compilador do C++ dá suporte a construções de tratamento de exceções estruturado conforme descrito nesses artigos, o compilador C padrão não oferece suporte à sintaxe de tratamento de exceções de C++.) Para obter informações detalhadas sobre o tratamento de exceções C++, consulte [manipulação de exceção C++](../cpp/cpp-exception-handling.md) e *Manual de referência C++ anotado* de Margaret Ellis e Bjarne Stroustrup.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)