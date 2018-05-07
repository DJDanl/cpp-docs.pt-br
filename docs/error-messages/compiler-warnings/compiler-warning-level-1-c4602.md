---
title: Compilador (nível 1) de aviso C4602 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4602
dev_langs:
- C++
helpviewer_keywords:
- C4602
ms.assetid: c1f0300f-e2a2-4c9e-a7c3-4c7318d10509
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b2c25fd983f1ac7cebcc568a0b47c06c4d8e23a9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4602"></a>Compilador C4602 de aviso (nível 1)
\#pragma pop_macro: 'nome de macro' Nenhum push_macro #pragma anterior para este identificador  
  
 Se você usar [pop_macro](../../preprocessor/pop-macro.md) para uma determinada macro, você deve primeiro passar esse nome de macro para [push_macro](../../preprocessor/push-macro.md). Por exemplo, o exemplo a seguir gera C4602:  
  
```  
// C4602.cpp  
// compile with: /W1  
int main()  
{  
   #pragma pop_macro("x")   // C4602 x is not on the stack  
}  
```