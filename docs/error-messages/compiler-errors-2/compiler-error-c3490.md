---
title: C3490 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3490
dev_langs:
- C++
helpviewer_keywords:
- C3490
ms.assetid: 7638559a-fd06-4527-a9c1-0c8ae68b3123
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 593e5509ada926f27243a761da3470eb2d846a22
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33258744"
---
# <a name="compiler-error-c3490"></a>C3490 de erro do compilador
'var' não pode ser modificado porque está sendo acessado por meio de um objeto const  
  
 Uma expressão lambda que é declarada em um `const` método não é possível modificar os dados de membro não mutável.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Remover o `const` modificador da sua declaração de método.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3490 porque ela modifica a variável membro `_i` em um `const` método:  
  
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
 O exemplo a seguir elimina C3490 removendo o `const` modificador da declaração de método:  
  
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