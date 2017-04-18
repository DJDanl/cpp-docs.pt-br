---
title: C3496 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3496
dev_langs:
- C++
helpviewer_keywords:
- C3496
ms.assetid: e19885f2-677f-4c1e-bc69-e35852262dc3
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: cfb81290d121d200721683b46c2c1121c45d404a
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3496"></a>C3496 de erro do compilador
'this' sempre é capturado por valor: '&' ignorado  
  
 Você não pode capturar o `this` ponteiro por referência.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Capturar a `this` ponteiro por valor.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3496 porque uma referência para o `this` ponteiro aparece na lista de captura de uma expressão lambda:  
  
```  
// C3496.cpp  
// compile with: /c  
  
class C  
{  
   void f()  
   {  
      [&this] {}(); // C3496  
   }  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
