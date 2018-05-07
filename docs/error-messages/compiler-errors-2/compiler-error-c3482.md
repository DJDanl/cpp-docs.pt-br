---
title: C3482 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3482
dev_langs:
- C++
helpviewer_keywords:
- C3482
ms.assetid: bf99558e-bef4-421c-bb16-dcd9c54c1011
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ad7ea983d13f03add2772da173062b1ad5652d3b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3482"></a>C3482 de erro do compilador
'this' só pode ser usado como uma captura de lambda dentro de uma função de membro não estático  
  
 Você não pode passar `this` à lista de captura de uma expressão lambda que é declarada em um método estático ou uma função global.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Converter a função delimitador para um método não estático, ou  
  
-   Remover o `this` ponteiro da lista de captura da expressão lambda.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3482:  
  
```  
// C3482.cpp  
// compile with: /c  
  
class C  
{  
public:  
   static void staticMethod()  
   {  
      [this] {}(); // C3482  
   }  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)