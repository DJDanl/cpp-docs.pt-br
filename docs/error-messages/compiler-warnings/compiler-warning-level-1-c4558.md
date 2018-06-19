---
title: Compilador (nível 1) de aviso C4558 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4558
dev_langs:
- C++
helpviewer_keywords:
- C4558
ms.assetid: 52bb0324-7bec-468c-b35b-13a08d38e578
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 852e3d3e8bb1c8186232cbed2636ac890b0cd057
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33282451"
---
# <a name="compiler-warning-level-1-c4558"></a>Compilador C4558 de aviso (nível 1)
valor de operando 'value' está fora do intervalo 'lowerbound - upperbound'  
  
 O valor passado para uma instrução de linguagem assembly está fora do intervalo especificado para o parâmetro. O valor será truncado.  
  
 O exemplo a seguir gera C4558:  
  
```  
// C4558.cpp  
// compile with: /W1  
// processor: x86  
void asm_test() {  
   __asm pinsrw   mm1, eax, 8;   // C4558  
}  
  
int main() {  
}  
```