---
title: Compilador (nível 4) de aviso C4100 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4100
dev_langs:
- C++
helpviewer_keywords:
- C4100
ms.assetid: 478ed97d-e502-49e4-9afb-ac2a6c61194b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d3cf831590af2e1f2f7cd13d93c9d13ba217e11
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4100"></a>Compilador C4100 de aviso (nível 4)
'Identificador': parâmetro formal não referenciado  
  
 O parâmetro formal não é referenciado no corpo da função. O parâmetro não referenciado será ignorado.  
  
 C4100 também pode ser emitido quando o código chama um destruidor no parâmetro de tipo primitivo não referenciados um caso contrário.  Essa é uma limitação do compilador Visual C++.  
  
 O exemplo a seguir gera C4100:  
  
```  
// C4100.cpp  
// compile with: /W4  
void func(int i) {   // C4100, delete the unreferenced parameter to  
                     //resolve the warning  
   // i;   // or, add a reference like this  
}  
  
int main()  
{  
   func(1);  
}  
```