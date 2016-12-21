---
title: "Instru&#231;&#227;o do-while (C) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "do"
  - "while"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "palavra-chave do-while [C]"
ms.assetid: f2ac20a6-10c7-4a08-b5e3-c3b3639dbeaf
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o do-while (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A instrução `do-while` permite que você repita uma instrução ou instrução composta até que uma expressão especificada seja falsa.  
  
## Sintaxe  
 *iteration\-statement*:  
 **do**  *statement*  **while \(**  *expression*  **\) ;**  
  
 A *expressão* em uma instrução `do-while` é avaliada depois que o corpo do loop é executado.  Portanto, o corpo do loop é sempre executado ao menos uma vez.  
  
 A *expressão* deve ter o tipo aritmético ou ponteiro.  A execução procede da seguinte maneira:  
  
1.  O corpo da instrução é executado.  
  
2.  Em seguida, a *expressão* é avaliada.  Se a *expressão* for falsa, a instrução `do-while` é finalizada e o controle é passado para a próxima instrução no programa.  Se a *expressão* for verdadeira \(diferente de zero\), o processo é repetido, começando da etapa 1.  
  
 A instrução `do-while` também pode terminar quando uma instrução **break**, `goto` ou `return` for executada dentro do corpo da declaração.  
  
 Esse é um exemplo da instrução `do-while`:  
  
```  
do   
{  
    y = f( x );  
    x--;  
} while ( x > 0 );  
```  
  
 Nesta instrução `do-while`, as duas instruções `y = f( x );` e `x--;` são executadas, independente do valor inicial de `x`.  Em seguida, `x > 0` é avaliado.  Se `x` for maior que 0, o corpo da instrução é executado novamente e `x > 0` é reavaliado.  O corpo da instrução é executado repetidamente, enquanto `x` permanece maior que 0.  A execução da instrução `do-while` termina quando `x` se torna 0 ou negativo.  O corpo do loop é executado ao menos uma vez.  
  
## Consulte também  
 [Instrução do\-while \(C\+\+\)](../cpp/do-while-statement-cpp.md)