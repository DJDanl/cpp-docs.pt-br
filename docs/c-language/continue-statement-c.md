---
title: "Instru&#231;&#227;o continue (C) | Microsoft Docs"
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
  - "continue"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "palavra-chave continue [C]"
  - "Estruturas de loop, palavra-chave continue"
ms.assetid: 969f293a-45fe-48a7-b4c6-287ba27a631d
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o continue (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A instrução `continue` transmite o controle para a próxima iteração da instrução `do`, `for` ou `while` delimitadora mais próxima em que aparece, ignorando qualquer instrução restante no corpo da instrução `do`, `for` ou `while`.  
  
## Sintaxe  
 `jump-statement`:  
 `continue;`  
  
 A próxima iteração de uma instrução `do`, `for` ou `while` é determinada da seguinte maneira:  
  
-   Em uma instrução `do` ou `while`, a próxima iteração começa com a reavaliação da expressão da instrução `do` ou `while`.  
  
-   Uma instrução `continue` em uma instrução `for` causa a avaliação da expressão de loop da instrução `for`.  Então, o compilador reavalia a expressão condicional e, dependendo do resultado, finaliza ou itera o corpo da instrução.  Consulte [A instrução](../c-language/for-statement-c.md) para obter mais informações sobre a instrução `for` e seus não terminais.  
  
 Esse é um exemplo da instrução `continue`:  
  
```  
while ( i-- > 0 )   
{  
    x = f( i );  
    if ( x == 1 )  
        continue;  
    y += x * x;  
}  
```  
  
 Nesse exemplo, o corpo da instrução é executado enquanto `i` é maior que 0.  Primeiro, `f(i)` é atribuído a `x`; então, se `x` for igual a 1, a instrução `continue` será executada.  O restante das instruções no corpo é ignorado, e a execução será retomada na parte superior do loop com a avaliação do teste de loop.  
  
## Consulte também  
 [Instrução continue](../cpp/continue-statement-cpp.md)