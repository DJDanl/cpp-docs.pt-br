---
title: Compilador (nível 1) de aviso C4138 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4138
dev_langs:
- C++
helpviewer_keywords:
- C4138
ms.assetid: 65ebf929-bba0-4237-923b-c1b66adfe17d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f0865935c30c4934684c7a12e50ab26f3e8b12c4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4138"></a>Compilador C4138 de aviso (nível 1)
' * /' encontrado fora de comentário  
  
 O delimitador de fechamento de comentário não for precedido por um delimitador de comentário de abertura. O compilador assumirá um espaço entre o asterisco (**\***) e a barra (/).  
  
## <a name="example"></a>Exemplo  
  
```  
// C4138a.cpp  
// compile with: /W1  
int */*comment*/ptr;   // C4138 Ambiguous first delimiter causes warning  
int main()  
{  
}  
```  
  
 Esse aviso pode ser causado pela tentativa de aninhar comentários.  
  
 Esse aviso pode ser resolvido se você comentar seções de código que contém comentários, coloque o código em um **#if / #endif** bloquear e defina a expressão de controle como zero:  
  
```  
// C4138b.cpp  
// compile with: /W1  
#if 0  
int my_variable;   /* Declaration currently not needed */  
#endif  
int main()  
{  
}  
```