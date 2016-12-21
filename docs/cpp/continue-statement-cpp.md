---
title: "Instru&#231;&#227;o continue (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "continue"
  - "continue_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave continue [C++]"
ms.assetid: 3c94ee57-f732-4c1d-8537-d0ce5382bfd4
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o continue (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Força a transferência de controle para a expressão controladora do menor loop [do](../cpp/do-while-statement-cpp.md), [for](../cpp/for-statement-cpp.md) ou [while](../cpp/while-statement-cpp.md) delimitador.  
  
## Sintaxe  
  
```  
continue;  
```  
  
## Comentários  
 As instruções restantes na iteração atual não são executadas.  A próxima iteração do loop é determinada da seguinte maneira:  
  
-   Em um loop `do` ou `while`, a próxima iteração começa com a reavaliação da expressão controladora da instrução `do` ou `while`.  
  
-   Em um loop `for` \(usando a sintaxe `for`\(`init-expr`; `cond-expr`; `loop-expr`\)\), a cláusula `loop-expr` é executada.  A cláusula `cond-expr` é reavaliada e, dependendo do resultado, o loop é encerrado ou ocorre outra iteração.  
  
 O exemplo a seguir mostra como a instrução `continue` pode ser usada para ignorar seções de código e iniciar a próxima iteração de um loop.  
  
## Exemplo  
  
```  
// continue_statement.cpp  
#include <stdio.h>  
int main()  
{  
    int i = 0;  
    do  
    {  
        i++;  
        printf_s("before the continue\n");  
        continue;  
        printf("after the continue, should never print\n");  
     } while (i < 3);  
  
     printf_s("after the do loop\n");  
}  
```  
  
  **antes da continuação**  
**antes da continuação**  
**antes da continuação**  
**depois do loop do**   
## Consulte também  
 [Instruções de salto](../cpp/jump-statements-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)