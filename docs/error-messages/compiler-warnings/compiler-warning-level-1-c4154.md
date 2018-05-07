---
title: Compilador (nível 1) de aviso C4154 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4154
dev_langs:
- C++
helpviewer_keywords:
- C4154
ms.assetid: 4511afeb-e893-4cc6-83b6-4c7a0477f76b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ff2873b29672b7c9c0279ff7911004b641ca7795
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4154"></a>Compilador C4154 de aviso (nível 1)
exclusão de uma expressão de matriz. conversão para ponteiro fornecida  
  
 Não é possível usar `delete` em uma matriz, então o compilador converte a matriz para um ponteiro.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4154.cpp  
// compile with: /c /W1  
int main() {  
   int array[ 10 ];  
   delete array;   // C4154 can't delete stack object  
  
   int *parray2 = new int [10];  
   int (&array2)[10] = (int(&)[10]) parray2;  
   delete [] array2;   // C4154  
  
   // try the following line instead  
   delete [] &array2;  
}  
```