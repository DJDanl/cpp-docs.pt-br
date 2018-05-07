---
title: Compilador (nível 1) de aviso C4552 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4552
dev_langs:
- C++
helpviewer_keywords:
- C4552
ms.assetid: ebbbb5ee-1c19-45bd-b386-41a19630fc76
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a3b58d33286163050db533fed00d27abe8903e9f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4552"></a>Compilador C4552 de aviso (nível 1)
'operator': operador não tem nenhum efeito; esperado operador com efeito colateral  
  
 Se uma instrução de expressão com um operador com nenhum efeito colateral como a parte superior da expressão, provavelmente é um erro.  
  
 Para substituir este aviso, coloque a expressão entre parênteses.  
  
 O exemplo a seguir gera C4552:  
  
```  
// C4552.cpp  
// compile with: /W1  
int main() {  
   int i, j;  
   i + j;   // C4552  
   // try the following line instead  
   // (i + j);  
}  
```