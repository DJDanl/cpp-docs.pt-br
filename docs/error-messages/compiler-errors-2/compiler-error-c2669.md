---
title: C2669 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2669
dev_langs:
- C++
helpviewer_keywords:
- C2669
ms.assetid: f9cb8111-bcdc-484b-a863-2c42e15a0496
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 642d2dd99c93b5af021503ffbb4975d1ff3c0db4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33233400"
---
# <a name="compiler-error-c2669"></a>C2669 de erro do compilador
função de membro não permitida em union anônima  
  
[Uniões anônimas](../../cpp/unions.md#anonymous_unions) não pode ter funções de membro.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C2669:  
  
```cpp  
// C2669.cpp  
struct X {  
   union {  
      int i;  
      void f() {   // C2669, remove function  
         i = 0;   
      }  
   };  
};  
```  
  