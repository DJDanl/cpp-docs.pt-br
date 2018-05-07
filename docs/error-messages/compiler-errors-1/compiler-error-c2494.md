---
title: C2494 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2494
dev_langs:
- C++
helpviewer_keywords:
- C2494
ms.assetid: 5dfd07ab-351d-49c9-b54e-f0a104776ab8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5071be235ac17fb541dc8c96871057f089646da5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2494"></a>C2494 de erro do compilador
'palavra-chave' não pode ser chamado de dentro de uma expressão de filtro ou finally/bloco finally  
  
 Não é possível usar `keyword` em um `__finally` ou bloco finally.  
  
 O exemplo a seguir gera C2494:  
  
```  
// C2494.cpp  
#include <malloc.h>  
  
int main() {  
   __try {}  
   __except ( _alloca(100), 1 ) {}   // C2494  
   __try {}  
   __finally {  
      _alloca(100);   // C2494  
   }  
}  
```  
  
 C2494 também pode ocorrer ao usar **/clr**.  
  
```  
// C2494b.cpp  
// compile with: /clr  
#include <malloc.h>  
  
int main() {  
   char * buf;  
   try {}  
   catch (char * buf2) {}  
   finally {  
      _alloca(100);   // C2494  
   }  
}  
```