---
title: Compilador (nível 4) de aviso C4725 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4725
dev_langs:
- C++
helpviewer_keywords:
- C4725
ms.assetid: effa0335-71c3-4b3b-8618-da4b9b46a95d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 96f07f14c73ce6e42b8bbc057aa35c5a0f63f6ee
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33301743"
---
# <a name="compiler-warning-level-4-c4725"></a>Compilador C4725 de aviso (nível 4)
instrução pode ser incorreta em alguns Pentiums  
  
 O código contém uma instrução de assembly embutido que talvez não produza resultados precisos em alguns microprocessadores Pentium.  
  
 O exemplo a seguir gera C4725:  
  
```  
// C4725.cpp  
// compile with: /W4  
// processor: x86  
double m32fp = 2.0003e-17;  
  
void f() {  
   __asm  
   {  
      FDIV m32fp   // C4725  
   }  
}  
  
int main() {  
}  
```