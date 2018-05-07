---
title: Compilador (nível 1) de aviso C4677 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4677
dev_langs:
- C++
helpviewer_keywords:
- C4677
ms.assetid: a8d656a1-e2ff-4f8b-9028-201765131026
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3511ad3100bf695cec5df97703b39e5926c71c11
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4677"></a>Compilador C4677 de aviso (nível 1)
'function': assinatura de membro não private contém tipo private de assembly 'private_type'  
  
 Um tipo que tem acessibilidade pública fora do assembly usa um tipo que tem acesso privado fora do assembly. Um componente que faz referência ao tipo de assembly público não poderá usar o tipo membro ou membros que fazem referência o tipo private de assembly.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4677.  
  
```  
// C4677.cpp  
// compile with: /clr /c /W1  
delegate void TestDel();  
public delegate void TestDel2();  
  
public ref class MyClass {  
public:  
   static event TestDel^ MyClass_Event;   // C4677  
   static event TestDel2^ MyClass_Event2;   // OK  
};  
```