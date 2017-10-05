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
- structured exception handling, with C++ exception handling
ms.assetid: ec34b528-8c26-4429-b24a-6a68553aaa91
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
ms.openlocfilehash: 8f9805479d7ee9589cfd0da8491b0344d0bd7de1
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="using-structured-exception-handling-with-c"></a>Usando tratamento de exceções estruturado com C++
O tratamento de exceções estruturado descrito nesses artigos funciona com arquivos de origem de C e C++. No entanto, ele não é projetado especificamente para C++ e não é recomendado. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, o mecanismo de tratamento de exceções de C++ é mais flexível, pois pode tratar exceções de qualquer tipo.  
  
 Microsoft C++ agora dá suporte ao modelo de tratamento de exceções de C++, com base no padrão ANSI C++. Esse mecanismo controla automaticamente a destruição de objetos locais durante o desenrolamento da pilha. Se você estiver escrevendo código tolerante a falhas em C++ e desejar implementar o tratamento de exceções, é altamente recomendável que você use o tratamento de exceções de C++ em vez da estruturada. (Observe que, quando o compilador do C++ dá suporte a construções de tratamento de exceções estruturado conforme descrito nesses artigos, o compilador C padrão não oferece suporte à sintaxe de tratamento de exceções de C++.) Para obter informações detalhadas sobre o tratamento de exceções C++, consulte [manipulação de exceção C++](../cpp/cpp-exception-handling.md) e *Manual de referência C++ anotado* de Margaret Ellis e Bjarne Stroustrup.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
