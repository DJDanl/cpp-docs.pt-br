---
title: C2460 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2460
dev_langs:
- C++
helpviewer_keywords:
- C2460
ms.assetid: d969fca9-3ac5-4e4e-88fc-df05510e2093
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b4220be654f93ecd79d196efc14657ca7346411f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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