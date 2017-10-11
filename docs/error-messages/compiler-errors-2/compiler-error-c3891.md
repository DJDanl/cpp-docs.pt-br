---
title: C3891 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3891
dev_langs:
- C++
helpviewer_keywords:
- C3891
ms.assetid: 6e1a9458-97f5-4580-bc0f-aa97a1bfd20d
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b9db8f6142e4d2d99071d9d02255e0789a14dd50
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3891"></a>C3891 de erro do compilador
'var': um membro de dados literal não pode ser usado como um l-value  
  
 Um [literal](../../windows/literal-cpp-component-extensions.md) variável é const, e seu valor não pode ser alterado depois que ele é inicializado na declaração.  
  
 O exemplo a seguir gera C3891:  
  
```  
// C3891.cpp  
// compile with: /clr  
ref struct Y1 {  
   literal int staticConst = 9;  
};  
  
int main() {  
   Y1::staticConst = 0;   // C3891  
}  
```
