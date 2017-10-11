---
title: C3298 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3298
dev_langs:
- C++
helpviewer_keywords:
- C3298
ms.assetid: 458c2680-95bb-4d5e-895f-ce4115844193
caps.latest.revision: 3
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: a21b2d28120cb5e1c936b632d67ff28bb6568210
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3298"></a>C3298 de erro do compilador
'constraint_1': não é possível usar 'constraint_2' como uma restrição porque 'constraint_2' tem a restrição ref e 'constraint_1' tem a restrição de valor  
  
 Não é possível especificar características mutuamente exclusivas de uma restrição. Por exemplo, um parâmetro de tipo genérico não pode ser restrito a um tipo de valor e um tipo de referência.  
  
 Para obter mais informações, consulte [restrições em parâmetros de tipo genérico (C + + CLI)](../../windows/constraints-on-generic-type-parameters-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3298.  
  
```  
// C3298.cpp  
// compile with: /clr /c   
generic<class T, class U>  
where T : ref class  
where U : T, value class   // C3298  
public ref struct R {};  
```
