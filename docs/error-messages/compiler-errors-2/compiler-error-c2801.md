---
title: C2801 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2801
dev_langs:
- C++
helpviewer_keywords:
- C2801
ms.assetid: 35dfc7ea-9e37-4e30-baa1-944dc61302f5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f68b3f575fcb8b909f58ac2ffbcaca26580279da
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2801"></a>C2801 de erro do compilador
'operador operator' deve ser um membro não estático  
  
 Os operadores a seguir podem ser sobrecarregados somente como membros não estáticos:  
  
-   Atribuição `=`  
  
-   Acesso de membro de classe `->`  
  
-   Subscripting `[]`  
  
-   Chamada de função `()`  
  
 Possíveis causas de C2801:  
  
-   Operador sobrecarregado não é uma classe, estrutura ou membro de união.  
  
-   Operador sobrecarregado é declarado `static`.  
  
-   O exemplo a seguir gera C2801:  
  
```  
// C2801.cpp  
// compile with: /c  
operator[]();   // C2801 not a member  
class A {  
   static operator->();   // C2801 static  
   operator()();   // OK  
};  
```