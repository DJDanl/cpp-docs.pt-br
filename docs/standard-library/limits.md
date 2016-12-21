---
title: "&lt;limits&gt; | Microsoft Docs"
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
  - "std.<limits>"
  - "std::<limits>"
  - "limits/std::<limits>"
  - "<limits>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho limits"
ms.assetid: e07d6379-5b00-4a3d-a789-40d41538b59e
caps.latest.revision: 18
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;limits&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define a classe de modelo `numeric_limits` e duas enumerações relacionadas a representações de ponto flutuante e arredondamento.  
  
## Sintaxe  
  
```  
  
#include <limits>  
  
```  
  
## Comentários  
 Especializações explícitas a `numeric_limits` classe descrevem muitas propriedades de tipos fundamentais, incluindo o caractere, inteiro e tipos de ponto flutuante e `bool` que são definidos em vez de fixo pelas regras da linguagem C\+\+ de implementação.  As propriedades descritas nos limites de \< \> incluem precisão, mínimo e máximo em tamanho representações, arredondamento e sinalizar erros de tipo.  
  
### Enumeração  
  
|||  
|-|-|  
|[float\_denorm\_style](../Topic/float_denorm_style.md)|A enumeração descreve os vários métodos que pode escolher uma implementação que representa um valor de ponto flutuante desnormalizado — um pequeno demais para representar como um valor normalizado:|  
|[float\_round\_style](../Topic/float_round_style.md)|A enumeração descreve os vários métodos que pode escolher uma implementação para o arredondamento de um valor de ponto flutuante para um valor inteiro.|  
  
### Classes  
  
|||  
|-|-|  
|[Classe numeric\_limits](../standard-library/numeric-limits-class.md)|A classe de modelo descreve propriedades aritméticas tipos numéricos internos.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)