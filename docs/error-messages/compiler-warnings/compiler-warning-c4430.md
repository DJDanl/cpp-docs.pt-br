---
title: C4430 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4430
dev_langs:
- C++
helpviewer_keywords:
- C4430
ms.assetid: 12efbfff-aa58-4a86-a7d6-2c6a12d01dd3
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 4455419ab6ce8a98dfb26bdb6575cc229d364c0f
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-warning-c4430"></a>C4430 de aviso do compilador
faltando especificador de tipo - int assumido. Observação: C++ não suporta default-int  
  
 Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: todas as declarações devem especificar explicitamente o tipo; int não mais será assumido.  
  
 C4430 sempre é emitido como um erro.  Você pode desativar esse aviso com a `#pragma warning` ou **/wd**; consulte [aviso](../../preprocessor/warning.md) ou [/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /, /wo, /Wv, /WX (nível de aviso)](../../build/reference/compiler-option-warning-level.md)para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4430.  
  
```  
// C4430.cpp  
// compile with: /c  
struct CMyClass {  
   CUndeclared m_myClass;  // C4430  
   int m_myClass;  // OK  
};  
  
typedef struct {  
   POINT();   // C4430  
   // try the following line instead  
   // int POINT();  
   unsigned x;  
   unsigned y;  
} POINT;  
```
