---
title: "Operadores aditivos C | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Operador +, operadores aditivos"
  - "operadores aditivos"
  - "operadores aritméticos [C++], operadores aditivos"
  - "operadores [C], adição"
  - "conversões aritméticas comuns"
ms.assetid: bb8ac205-b061-41fc-8dd4-dab87c8b900c
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores aditivos C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os operadores aditivos executam adição \(**\+**\) e subtração \(**–**\).  
  
## Sintaxe  
 *expressão de adição*:  
 *multiplicative\-expression*  
  
 *additive\-expression*  **\+**  *multiplicative\-expression*  
  
 *additive\-expression*  **–**  *multiplicative\-expression*  
  
> [!NOTE]
>  Embora a sintaxe da *additive\-expression* inclua a *multiplicative\-expression*, isso não significa que as expressões que usam multiplicação sejam necessárias.  Consulte a sintaxe em [Resumo de sintaxe da linguagem C](../c-language/c-language-syntax-summary.md), para *multiplicative\-expression*, *cast\-expression* e *unary\-expression*.  
  
 Os operandos podem ser valores integrais ou flutuantes.  Algumas operações aditivas também podem ser executadas em valores de ponteiro, como descrito na discussão de cada operador.  
  
 Os operadores aditivos executam as conversões aritméticas comuns em operandos do tipo integral ou flutuantes.  O tipo do resultado é o tipo dos operandos após conversão.  Como as conversões executadas pelos operadores aditivos não fornecem condições de estouro ou de estouro negativo, as informações podem ser perdidas se o resultado de uma operação aditiva não puder ser representado no tipo dos operandos após a conversão.  
  
## Consulte também  
 [Operadores aditivos: \+ e \-](../cpp/additive-operators-plus-and.md)