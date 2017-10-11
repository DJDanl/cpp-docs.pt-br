---
title: C3482 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3482
dev_langs:
- C++
helpviewer_keywords:
- C3482
ms.assetid: bf99558e-bef4-421c-bb16-dcd9c54c1011
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b19769a8a326613401263fa7700b85c36a9dbbe1
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

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
