---
title: "Estrutura treat_as_floating_point | Microsoft Docs"
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
  - "chrono/std::chrono::treat_as_floating_point"
dev_langs: 
  - "C++"
ms.assetid: d0a2161c-bbb2-4924-8961-7568d5ad5434
caps.latest.revision: 13
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura treat_as_floating_point
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica se `Rep` pode ser tratado como um tipo de ponto flutuante.  
  
## Sintaxe  
  
```  
template<class Rep>  
struct treat_as_floating_point : is_floating_point<Rep>;  
```  
  
## Comentários  
 `Rep` pode ser tratado como um tipo de ponto flutuante somente quando a especialização `treat_as_floating_point<Rep>` é derivada de [true\_type](../Topic/true_type%20Typedef.md).  A classe de modelo pode ser especializada para um tipo definido pelo usuário.  
  
## Requisitos  
 **Cabeçalho:** crono  
  
 **Namespace:** std::chrono  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<chrono\>](../standard-library/chrono.md)