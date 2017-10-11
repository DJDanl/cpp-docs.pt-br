---
title: C3896 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3896
dev_langs:
- C++
helpviewer_keywords:
- C3896
ms.assetid: eb8be0f6-5b4e-4d71-8285-8a2a94f8ba29
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 37390df0763856c671a078ee2fe4df984bd995d8
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3896"></a>C3896 de erro do compilador
'member': inicializador inadequado: este membro de dados literal só pode ser inicializado com 'nullptr'  
  
 Um [literal](../../windows/literal-cpp-component-extensions.md) membro de dados foi inicializado incorretamente.  Consulte [nullptr](../../windows/nullptr-cpp-component-extensions.md) para obter mais informações.  
  
 O exemplo a seguir gera C3896:  
  
```  
// C3896.cpp  
// compile with: /clr /c  
ref class R{};  
  
value class V {  
   literal R ^ r = "test";   // C3896  
   literal R ^ r2 = nullptr;   // OK  
};  
```
