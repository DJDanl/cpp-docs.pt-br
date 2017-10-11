---
title: C2473 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2473
dev_langs:
- C++
helpviewer_keywords:
- C2473
ms.assetid: 6bb7dbf5-b198-490f-860e-fd64d0c2a284
caps.latest.revision: 4
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: bbc3432383e39913ed3cd89b310b00706a26a589
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2473"></a>C2473 de erro do compilador
'Identificador': parece com uma definição de função, mas não há nenhuma lista de parâmetros.  
  
 O compilador detectou que parecia uma função, sem a lista de parâmetros.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2473.  
  
```  
// C2473.cpp  
// compile with: /clr /c  
class A {  
   int i {}   // C2473  
};  
  
class B {  
   int i() {}   // OK  
};  
```
