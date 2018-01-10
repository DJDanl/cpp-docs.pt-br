---
title: "Compilador (nível 1) de aviso C4677 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4677
dev_langs: C++
helpviewer_keywords: C4677
ms.assetid: a8d656a1-e2ff-4f8b-9028-201765131026
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7af724ad56c3a84ffb8ef48e13d14bee97db14df
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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