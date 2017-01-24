---
title: "Varargs | Microsoft Docs"
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
ms.assetid: aac0c54b-0a2d-4a22-b1de-ee41381a3eb1
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Varargs
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se os parâmetros são passados através de varargs \(por exemplo, argumentos reticências\), então essencialmente passar normal do parâmetro aplica incluir derramando o quinto e argumentos subsequentes.  É novamente responsabilidade do receptor despejar os argumentos que tem seu endereço executada.  Para valores de ponto flutuante somente, o inteiro e o registro de ponto flutuante conterão o valor de flutuante caso que o receptor espera o valor registro inteiro.  
  
## Consulte também  
 [Convenção de chamada](../build/calling-convention.md)