---
title: C3490 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3490
dev_langs:
- C++
helpviewer_keywords:
- C3490
ms.assetid: 7638559a-fd06-4527-a9c1-0c8ae68b3123
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
ms.openlocfilehash: 6051c278a14421a997834ee5f47db5a961b66e4b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3490"></a>C3490 de erro do compilador
'var' não pode ser modificada porque ela está sendo acessada por meio de um objeto const  
  
 Uma expressão lambda que é declarada em um `const` método não pode modificar dados de membro não mutável.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remover o `const` modificador de sua declaração de método.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3490 porque ele modifica a variável de membro`_i` em um `const` método:  
  
```  
// C3490a.cpp  
// compile with: /c  
  
class C  
{  
   void f() const   
   {  
      auto x = [=]() { _i = 20; }; // C3490  
   }  
  
   int _i;  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir resolve C3490 removendo o `const` modificador da declaração de método:  
  
```  
// C3490b.cpp  
// compile with: /c  
  
class C  
{  
   void f()  
   {  
      auto x = [=]() { _i = 20; };  
   }  
  
   int _i;  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
