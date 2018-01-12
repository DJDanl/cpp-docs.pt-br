---
title: Erro do compilador C3487 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3487
dev_langs: C++
helpviewer_keywords: C3487
ms.assetid: 39bda474-4418-4a79-98bf-2b22fa92eaaa
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 566f130e3d65826feecc02afae0cc1a7db335efe
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3487"></a>Erro do Compilador C3487
tipo de retorno: todos retornam expressões devem ser deduzidas para o mesmo tipo: anteriormente era 'tipo de retorno'  
  
 Uma expressão lambda deve especificar seu tipo de retorno, a menos que ele contém uma única instrução de retorno. Se uma expressão lambda contiver várias instruções de retorno, eles devem todos ter o mesmo tipo.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Especifique um tipo de retorno à direita para o lambda. Verifique se todos os retornos de lambda são do mesmo tipo ou podem ser convertidos implicitamente para o tipo de retorno.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3487 porque os tipos de retorno do lambda não coincidem:  
  
```  
// C3487.cpp  
// Compile by using: cl /c /W4 C3487.cpp  
  
int* test(int* pi) {  
   // To fix the error, uncomment the trailing return type below  
   auto odd_pointer = [=]() /* -> int* */ {  
      if (*pi % 2)   
         return pi;  
      return nullptr; // C3487 - nullptr is not an int* type  
   };  
   return odd_pointer();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)