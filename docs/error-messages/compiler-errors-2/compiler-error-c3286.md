---
title: C3286 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3286
dev_langs:
- C++
helpviewer_keywords:
- C3286
ms.assetid: 554328c8-cf44-4f7d-a8d2-def74d28ecdd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dc47c103e93fe1e4f20f5007c6688b5b6648bf32
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3286"></a>C3286 de erro do compilador  
  
> '*especificador*': uma variável de iteração não pode ter os especificadores de classe de armazenamento  
  
Uma classe de armazenamento não pode ser especificada em uma variável de iteração. Para obter mais informações, consulte [classes de armazenamento (C++)](../../cpp/storage-classes-cpp.md) e [para cada um, no](../../dotnet/for-each-in.md).  
  
## <a name="example"></a>Exemplo  
  
O exemplo a seguir gera C3286 e também mostra o uso correto.  
  
```cpp  
// C3286.cpp  
// compile with: /clr  
int main() {  
   array<int> ^p = { 1, 2, 3 };  
   for each (static int i in p) {}   // C3286   
   for each (int j in p) {}   // OK  
}  
```