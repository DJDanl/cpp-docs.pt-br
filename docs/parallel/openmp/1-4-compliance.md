---
title: "1.4 Conformidade | Microsoft Docs"
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
ms.assetid: 662ad260-b9a1-43b7-b269-ef6ff0714e05
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 1.4 Conformidade
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

É uma implementação da API do C/C++ do OpenMP *OpenMP compatíveis* se ele reconhece e preserva a semântica de todos os elementos dessa especificação, conforme dispostos em capítulos 1, 2, 3, 4, e apêndice C. apêndices A, B, D, E e F são somente para fins informativos e não fazem parte da especificação. Implementações que incluam somente um subconjunto da API não são compatíveis com o OpenMP.  
  
 O OpenMP C e C++ API é uma extensão para o idioma base que é suportado por uma implementação. Se o idioma base não oferece suporte a uma construção de linguagem ou a extensão que aparece neste documento, a implementação OpenMP não é necessário para dar suporte a ele.  
  
 Todas as funções de biblioteca de C e C++ padrão e funções internas (ou seja, funções de que o compilador não tem conhecimento específico) deve ser thread-safe. Não sincronizado uso de funções thread-safe por threads diferentes dentro de uma região paralela não produzem um comportamento indefinido. No entanto, o comportamento não pode ser igual uma região serial. (É um exemplo de uma função de geração de número aleatório.)  
  
 A API de C/C++ do OpenMP Especifica que determinado comportamento *definido pela implementação.* Uma implementação OpenMP em conformidade é necessária para definir e documentar seu comportamento nesses casos. Consulte [Apêndice E](../Topic/E.%20Implementation-Defined%20Behaviors%20in%20OpenMP%20C-C++.md), 97, para obter uma lista de comportamentos definidos na implementação da página.