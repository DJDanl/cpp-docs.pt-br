---
title: C3299 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3299
dev_langs:
- C++
helpviewer_keywords:
- C3299
ms.assetid: 7cabdf01-bceb-404f-9401-cdd9c7fc1641
caps.latest.revision: 4
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
ms.openlocfilehash: e2ef3798259a10b09f74a2ad92f8084a65deafd8
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3299"></a>C3299 de erro do compilador
'member_function': não é possível especificar restrições, elas são herdadas do método base  
  
 Ao substituir uma função de membro genérico, você não pode especificar cláusulas de restrição (as restrições implica que as restrições não são herdadas de repetição).  
  
 As cláusulas de restrição na função genérica que você está substituindo serão herdadas.  
  
 Para obter mais informações, consulte [restrições em parâmetros de tipo genéricos (C + + / CLI)](../../windows/constraints-on-generic-type-parameters-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3299.  
  
```  
// C3299.cpp  
// compile with: /clr /c  
public ref struct R {  
   generic<class T>   
   where T : R  
   virtual void f();  
};  
  
public ref struct S : R {  
   generic<class T>   
   where T : R   // C3299  
   virtual void f() override;  
};  
```
