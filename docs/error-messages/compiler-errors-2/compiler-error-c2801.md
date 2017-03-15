---
title: C2801 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2801
dev_langs:
- C++
helpviewer_keywords:
- C2801
ms.assetid: 35dfc7ea-9e37-4e30-baa1-944dc61302f5
caps.latest.revision: 8
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 1f3219ade9fa4593ee308898df8ed941684697ad
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2801"></a>C2801 de erro do compilador
'operador' deve ser um membro não estático  
  
 Os seguintes operadores podem ser sobrecarregados somente como membros não estáticos:  
  
-   Atribuição`=`  
  
-   Acesso de membro de classe`->`  
  
-   Subscripting`[]`  
  
-   Chamada de função`()`  
  
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
