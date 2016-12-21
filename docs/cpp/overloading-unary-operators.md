---
title: "Operadores un&#225;rios de sobrecarga | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "operadores de incremento, sobrecarregado"
  - "operadores [C++], unário"
  - "Operador de adição"
  - "sobrecarga de Operador de cancelamento de ponteiro"
  - "operadores unários redefiníveis"
  - "operadores unários"
  - "operadores unários, minus"
  - "operadores unários, plus"
ms.assetid: 7683ef08-42a4-4283-928f-d3dd4f3ab4c0
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores un&#225;rios de sobrecarga
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os operadores unários que podem ser sobrecarregados são os seguintes:  
  
1.  `!` \([NOT lógico](../cpp/logical-negation-operator-exclpt.md)\)  
  
2.  `&` \([address\-of](../cpp/address-of-operator-amp.md)\)  
  
3.  `~` \([complemento de um](../cpp/one-s-complement-operator-tilde.md)\)  
  
4.  `*` \([desreferência de ponteiro](../cpp/indirection-operator-star.md)\)  
  
5.  `+` \([mais unário](../cpp/additive-operators-plus-and.md)\)  
  
6.  `-` \([negação unária](../cpp/additive-operators-plus-and.md)\)  
  
7.  `++` \([incremento](../Topic/Prefix%20Increment%20and%20Decrement%20Operators:%20++%20and%20--.md)\)  
  
8.  `--` \([decremento](../Topic/Prefix%20Increment%20and%20Decrement%20Operators:%20++%20and%20--.md)\)  
  
9. operadores de conversão  
  
 Os operadores de incremento e decremento de sufixo \(`++` e **––**\) são tratados separadamente em [Incremento e decremento](../Topic/Increment%20and%20Decrement%20Operator%20Overloading%20\(C++\).md).  
  
 Os operadores de conversão também são abordados em um tópico separado; consulte [Conversões](../cpp/user-defined-type-conversions-cpp.md).  
  
 As regras a seguir são verdadeiras para todos os outros operadores unários.  Para declarar uma função de operador unário como um membro não estático, você deve declará\-la na forma:  
  
 `ret-type operator` `op` `()`  
  
 em que `ret-type` é o tipo de retorno e `op` é um dos operadores listados na tabela anterior.  
  
 Para declarar uma função de operador unário como uma função global, você deve declará\-la na forma:  
  
 `ret-type operator` `op` \(`arg` \)  
  
 em que `ret-type` e `op` são conforme descritos para funções de operador de membro e `arg` é um argumento do tipo de classe no qual operar.  
  
> [!NOTE]
>  Não há nenhuma restrição quanto aos tipos de retorno dos operadores unários.  Por exemplo, faz sentido para NOT lógico \(`!`\) retornar um valor integral, mas isso não é imposto.  
  
## Consulte também  
 [Sobrecarga de operador](../cpp/operator-overloading.md)