---
title: C2460 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2460
dev_langs:
- C++
helpviewer_keywords:
- C2460
ms.assetid: d969fca9-3ac5-4e4e-88fc-df05510e2093
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 00e4015a0dae5054973ba72bb0e4f89c7443ae03
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2460"></a>C2460 de erro do compilador
'identifier1': usa 'identifier2', que está sendo definido  
  
 Uma classe ou estrutura (`identifier2`) é declarada como um membro de si mesmo (`identifier1`). Não são permitidas definições de recursiva de classes e estruturas.  
  
 O exemplo a seguir gera C2460:  
  
```  
// C2460.cpp  
class C {  
   C aC;    // C2460  
};  
```  
  
 Em vez disso, use uma referência de ponteiro na classe.  
  
```  
// C2460.cpp  
class C {  
   C * aC;    // OK  
};  
```
