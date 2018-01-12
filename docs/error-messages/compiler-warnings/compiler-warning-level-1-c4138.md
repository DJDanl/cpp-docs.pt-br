---
title: "Compilador (nível 1) de aviso C4138 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4138
dev_langs: C++
helpviewer_keywords: C4138
ms.assetid: 65ebf929-bba0-4237-923b-c1b66adfe17d
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 568c12beecfcfc7f5fd8cece4b19f10fa38e54e7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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