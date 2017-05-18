---
title: C3487 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3487
dev_langs:
- C++
helpviewer_keywords:
- C3487
ms.assetid: 39bda474-4418-4a79-98bf-2b22fa92eaaa
caps.latest.revision: 9
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4502e7c20f41c733e57ffc1c861a51f15b6d829c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3487"></a>Erro do Compilador C3487
tipo de retorno: todos retornam expressões devem deduzir o mesmo tipo: anteriormente era 'tipo de retorno'  
  
 Um lambda deve especificar seu tipo de retorno, a menos que ela contém uma única instrução return. Se um lambda contém várias instruções de retornos, eles devem todos ter o mesmo tipo.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Especifique um tipo de retorno à direita para lambda. Verifique se todas as devoluções de lambda são do mesmo tipo ou podem ser convertidas implicitamente para o tipo de retorno.  
  
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
