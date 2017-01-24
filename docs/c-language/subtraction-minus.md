---
title: "Subtra&#231;&#227;o (–) | Microsoft Docs"
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
  - "operadores [C], subtração"
  - "Operador de subtração, sintaxe"
ms.assetid: 9cacba7d-20b3-4372-8a63-ba5d8ee64177
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Subtra&#231;&#227;o (–)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O operador de subtração \(**–**\) subtrai o segundo operando do primeiro.  Ambos os operandos podem ser do tipo integral ou flutuante, ou um operando pode ser um ponteiro e o outro um inteiro.  
  
 Quando dois ponteiros são subtraídos, a diferença é convertida em um valor integral assinado dividindo a diferença pelo tamanho de um valor do tipo que os ponteiros indicam.  O tamanho do valor integral é definido pelo tipo **ptrdiff\_t** no arquivo STDDEF.H de inclusão padrão.  O resultado representa o número de posições de memória desse tipo entre os dois endereços.  O resultado é garantido somente para ser significativo para dois elementos da mesma matriz, como discutido em [Aritmética do ponteiro](../c-language/pointer-arithmetic.md).  
  
 Quando um valor inteiro é subtraído de um valor de ponteiro, o operador de subtração converte o valor do inteiro \(*i*\) multiplicando\-o pelo tamanho do valor que o ponteiro indica.  Após a conversão, o valor de inteiro representa as posições de memória *i*, onde cada posição tem o comprimento especificado pelo tipo de ponteiro.  Quando o valor do inteiro convertido é subtraído do valor do ponteiro, como resultado, o endereço de memória *i* se posiciona antes do endereço original.  O novo ponteiro aponta para um valor do tipo indicado pelo valor do ponteiro original.  
  
## Consulte também  
 [Operadores aditivos C](../c-language/c-additive-operators.md)