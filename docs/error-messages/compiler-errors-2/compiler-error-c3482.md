---
title: C3482 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
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
ms.openlocfilehash: 1970d44f18c752b9f8f300b313938d80f3b2d3d7
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3482"></a>C3482 de erro do compilador
'this' só pode ser usado como uma captura de lambda dentro de uma função membro não static  
  
 Você não pode passar `this` à lista de captura de uma expressão lambda que é declarada em um método estático ou uma função global.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Converter a função para um método não estático, ou  
  
-   Remover o `this` ponteiro na lista da expressão lambda captura.  
  
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
