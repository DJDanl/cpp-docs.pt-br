---
title: Usando com C++ de tratamento de exceções estruturado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- C++ exception handling, mixed with SEH
- structured exception handling [C++], with C++ exception handling
ms.assetid: ec34b528-8c26-4429-b24a-6a68553aaa91
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 71ce64a067ed75c29d83913adababe2d97dba6f0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32421933"
---
# <a name="using-structured-exception-handling-with-c"></a>Usando tratamento de exceções estruturado com C++
O tratamento de exceções estruturado descrito nesses artigos funciona com arquivos de origem de C e C++. No entanto, ele não é projetado especificamente para C++ e não é recomendado. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, o mecanismo de tratamento de exceções de C++ é mais flexível, pois pode tratar exceções de qualquer tipo.  
  
 Microsoft C++ agora dá suporte ao modelo de tratamento de exceções de C++, com base no padrão ANSI C++. Esse mecanismo controla automaticamente a destruição de objetos locais durante o desenrolamento da pilha. Se você estiver escrevendo código tolerante a falhas em C++ e desejar implementar o tratamento de exceções, é altamente recomendável que você use o tratamento de exceções de C++ em vez da estruturada. (Observe que, quando o compilador do C++ dá suporte a construções de tratamento de exceções estruturado conforme descrito nesses artigos, o compilador C padrão não oferece suporte à sintaxe de tratamento de exceções de C++.) Para obter informações detalhadas sobre o tratamento de exceções C++, consulte [manipulação de exceção C++](../cpp/cpp-exception-handling.md) e *Manual de referência C++ anotado* de Margaret Ellis e Bjarne Stroustrup.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)