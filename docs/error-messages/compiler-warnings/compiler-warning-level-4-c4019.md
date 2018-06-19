---
title: Compilador (nível 4) de aviso C4019 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4019
dev_langs:
- C++
helpviewer_keywords:
- C4019
ms.assetid: 4ecfe85d-673f-4334-8154-36fe7f0b3444
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d015b5674ad8f64a68b86979ce93313fa098c867
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33296501"
---
# <a name="compiler-warning-level-4-c4019"></a>Compilador C4019 de aviso (nível 4)
instrução vazia em escopo global  
  
 Um ponto e vírgula no escopo global não for precedido por uma instrução.  
  
 Esse aviso pode ser corrigido, se você remover o ponto e vírgula extra.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4019.c  
// compile with: /Za /W4  
#define declint( varname ) int varname;  
declint( a );   // C4019, int a;;  
declint( b )   // OK, int b;  
  
int main()  
{  
}  
```