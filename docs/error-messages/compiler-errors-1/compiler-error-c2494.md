---
title: C2494 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2494
dev_langs: C++
helpviewer_keywords: C2494
ms.assetid: 5dfd07ab-351d-49c9-b54e-f0a104776ab8
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 11a8e6ebbca57a9e60e3348363d843f86a4e200b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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