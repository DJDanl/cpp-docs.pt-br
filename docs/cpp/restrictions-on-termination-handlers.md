---
title: "Restrições em manipuladores de encerramento | Microsoft Docs"
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
- termination handlers [C++], limitations
- restrictions, termination handlers
- try-catch keyword [C++], termination handlers
ms.assetid: 8b1cb481-303f-4e79-b409-57a002a9fa9e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 71486b167f4e9939d4913b3660ed3513dc02b8f5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="restrictions-on-termination-handlers"></a>Restrições em manipuladores de término
Você não pode usar uma instrução `goto` para ir diretamente para um bloco de instruções `__try` ou um bloco de instruções `__finally`. Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. (No entanto, você pode ignorar um bloco de instruções `__try`.) Além disso, você não pode aninhar um manipulador de exceção ou um manipulador de encerramento dentro de um bloco `__finally`.  
  
 Além disso, alguns tipos de código permitidos em um manipulador de encerramento geram resultados duvidosos. Portanto, você deve usá-los com cuidado, se usá-los. Uma é uma instrução `goto` que ignora um bloco de instruções `__finally`. Se o bloco estiver sendo executado como parte do encerramento normal, nada incomum acontecerá. No entanto, se o sistema estiver desenrolando a pilha, esse processo será interrompido e a função atual obterá o controle como se não houvesse nenhum término anormal.  
  
 Uma instrução `return` dentro de um bloco de instruções `__finally` apresenta aproximadamente a mesma situação. O controle retorna ao chamador imediato da função que contém o manipulador de encerramento. Se o sistema estava desenrolando a pilha, esse processo é paralisado e o programa continua como se nenhuma exceção tivesse sido gerada.  
  
## <a name="see-also"></a>Consulte também  
 [Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)   
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)