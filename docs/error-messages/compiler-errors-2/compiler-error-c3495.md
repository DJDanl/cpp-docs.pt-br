---
title: C3495 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3495
dev_langs:
- C++
helpviewer_keywords:
- C3495
ms.assetid: 1fd40cb8-8373-403d-b8a8-f08424a50807
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7accbc422256abbd75d518acce72c522fbb67c14
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3495"></a>C3495 de erro do compilador
'var': uma captura de lambda deve ter duração de armazenamento automática  
  
 Não é possível capturar uma variável que não tem duração de armazenamento automática, como uma variável que está marcado como `static` ou `extern`.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Não passe um `static` ou `extern` variável à lista de captura da expressão lambda.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3495 porque o `static` variável `n` aparece na lista de captura de uma expressão lambda:  
  
```  
// C3495.cpp  
  
int main()  
{  
   static int n = 66;  
   [&n]() { return n; }(); // C3495  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)   


