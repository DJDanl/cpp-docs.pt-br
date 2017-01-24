---
title: "Instru&#231;&#227;o while (C) | Microsoft Docs"
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
  - "while"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "palavra-chave while [C]"
  - "palavra-chave while [C], sintaxe"
ms.assetid: d0c970b8-12a9-4827-afb2-a051111834b7
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o while (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A instrução `while` permite que você repita uma instrução até que uma expressão especificada seja falsa.  
  
## Sintaxe  
 *iteration\-statement*:  
 **while \(**  *expression*  **\)**  *statement*  
  
 A *expressão* deve ter o tipo aritmético ou ponteiro.  A execução procede da seguinte maneira:  
  
1.  A *expressão* é avaliada.  
  
2.  Se a *expressão* for inicialmente falsa, o corpo da instrução `while` nunca será executado, e o controle passará da instrução `while` para a próxima instrução do programa.  
  
     Se a *expressão* for verdadeira \(diferente de zero\), o corpo da instrução será executado e o processo será repetido no início da etapa 1.  
  
 A instrução `while` também pode terminar quando um **break**, `goto` ou `return` for executado dentro do corpo da declaração.  Use a instrução **continue** para finalizar uma iteração sem sair do loop de `while`.  A instrução **continue** passa o controle para a próxima iteração da instrução `while`.  
  
 Esse é um exemplo da instrução `while`:  
  
```  
while ( i >= 0 )   
{  
    string1[i] = string2[i];  
    i--;  
}  
```  
  
 Esse exemplo copia caracteres de `string2` para `string1`.  Se `i` for maior ou igual a 0, `string2[i]` é atribuído a `string1[i]` e `i` é diminuído.  Quando `i` atingir ou ficar abaixo de 0, a execução da instrução `while` termina.  
  
## Consulte também  
 [Instrução while \(C\+\+\)](../cpp/while-statement-cpp.md)