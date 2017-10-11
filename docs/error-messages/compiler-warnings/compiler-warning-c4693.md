---
title: C4693 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4693
dev_langs:
- C++
helpviewer_keywords:
- C4693
ms.assetid: 72d8db01-5e6f-4794-8731-76107e8f064a
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 1bd881645b36e29be987850c1ceb9f3b4fd35b9d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-warning-c4693"></a>C4693 de aviso do compilador
'class': uma classe sealed abstract não pode ter quaisquer membros de instância 'Test'  
  
 Se um tipo está marcado como [lacrado](../../windows/sealed-cpp-component-extensions.md) e [abstrata](../../windows/abstract-cpp-component-extensions.md), ele só pode ter membros estáticos.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4693.  
  
```  
// C4693.cpp  
// compile with: /clr /c  
public ref class Public_Ref_Class sealed abstract {  
public:  
   void Test() {}   // C4693  
   static void Test2() {}   // OK  
};  
```
