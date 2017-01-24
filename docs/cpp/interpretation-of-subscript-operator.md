---
title: "Interpreta&#231;&#227;o do operador de subscrito | Microsoft Docs"
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
  - "matrizes [C++], assinatura"
  - "interpretando operadores subscript"
  - "operadores [C++], interpretação de subscrito"
  - "Operador subscript, interpretação de"
ms.assetid: 8852ca18-9d5b-43f7-b8bd-abc89364fbf2
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interpreta&#231;&#227;o do operador de subscrito
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como outros operadores, o operador subscrito \(**\[ \]**\) pode ser redefinido pelo usuário.  O comportamento padrão do operador subscrito, se não sobrecarregado, é combinar o nome da matriz e o subscrito usando o seguinte método:  
  
 \*\(\(*array\-name*\) \+ \(*subscript*\)\)  
  
 Como em qualquer adição que envolve tipos do ponteiro, o dimensionamento é executado automaticamente para se ajustar ao tamanho do tipo.  Portanto, o valor resultante não é em bytes *subscritos* de origem de *array\-name*; em vez disso, ele é o elemento *subscript* da matriz. \(Para obter mais informações sobre essa conversão, consulte [Operadores aditivos](../cpp/additive-operators-plus-and.md).\)  
  
 De maneira semelhante, para matrizes multidimensionais, o endereço é derivado usando o seguinte método:  
  
 **\(\(**   
 ***array\-name* \) \+ \(**   
 ***subscript* 1**  *max*2 *\* max*3*...max*n\)               **\+** *subscript*2 *\* max*3*...max*n\)                    . . .  *\+* *subscript*n\)\)  
  
## Consulte também  
 [Matrizes](../Topic/Arrays%20\(C++\).md)