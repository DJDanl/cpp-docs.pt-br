---
title: C3886 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3886
dev_langs:
- C++
helpviewer_keywords:
- C3886
ms.assetid: 485f6c12-cc1b-4146-9034-409a0a5e615e
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 095b0f64bc2d792f6cde5c64d32cb8110d04bdbe
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3886"></a>C3886 de erro do compilador
'var': um membro de dados literal deve ser inicializado  
  
 Um [literal](../../windows/literal-cpp-component-extensions.md) variável deve ser inicializada quando é declaraed.  
  
 O exemplo a seguir gera C3886:  
  
```  
// C3886.cpp  
// compile with: /clr /c  
ref struct Y1 {  
   literal int staticConst;   // C3886  
   literal int staticConst2 = 0;   // OK  
};  
```
