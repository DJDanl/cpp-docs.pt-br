---
title: C3286 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3286
dev_langs: C++
helpviewer_keywords: C3286
ms.assetid: 554328c8-cf44-4f7d-a8d2-def74d28ecdd
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ea704fce0aebd3ffa83410104b38ceb5d359a6c6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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