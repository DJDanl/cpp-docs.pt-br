---
title: C2675 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2675
dev_langs:
- C++
helpviewer_keywords:
- C2675
ms.assetid: 4b92a12b-bff8-4dd5-a109-620065fc146c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fb949f5d6ab5881b911bab89150ae13f47443fcf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2675"></a>C2675 de erro do compilador
unário 'operator': 'type' não define este operador ou uma conversão para um tipo aceitável ao operador pré-definido  
  
 C2675 também pode ocorrer ao usar um operador unário, e o tipo não define o operador ou uma conversão para um tipo aceitável ao operador pré-definido. Para usar o operador, você deve sobrecarregá-lo para o tipo especificado ou definir uma conversão para um tipo para o qual o operador está definido.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2675.  
  
```  
// C2675.cpp  
struct C {   
   C(){}  
} c;  
  
struct D {   
   D(){}  
   void operator-(){}  
} d;  
  
int main() {  
   -c;   // C2675  
   -d;   // OK  
}  
```