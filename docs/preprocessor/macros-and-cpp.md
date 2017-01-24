---
title: "Macros e C++ | Microsoft Docs"
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
  - "Macros "
  - "Macros , C++"
ms.assetid: 83a344c1-73c9-4ace-8b93-cccfb62c6133
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macros e C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

C\+\+ oferece recursos novos. Alguns deles substituem os oferecidos pelo pré\-processador ANSI C.  Esses novos recursos aprimoram a segurança do tipo e a previsibilidade da linguagem:  
  
-   Em C\+\+, os objetos declarados como **const** podem ser usados em expressões constantes.  Isso permite que os programas declarem as constantes que têm informações de tipo e valor e as enumerações que podem ser exibidas simbolicamente com o depurador.  Usar a política de pré\-processador `#define` para definir constantes não é um procedimento tão preciso.  Nenhum armazenamento é atribuído a um objeto **const**, a menos que uma expressão que usa seu endereço seja encontrada no programa.  
  
-   O recurso da função integrada C\+\+ substitui macros de tipo de função.  As vantagens de usar funções integradas sobre as macros são:  
  
    -   Segurança de tipo.  As funções integradas estão sujeitas à mesma verificação de tipo que as funções normais.  As macros não são do tipo seguro.  
  
    -   Corrija a manipulação de argumentos que têm efeitos colaterais.  As funções integradas avaliam as expressões fornecidas como argumentos antes de inserir o corpo da função.  Portanto, não há nenhuma possibilidade de uma expressão com efeitos colaterais não seja segura.  
  
 Para obter mais informações sobre as funções integradas, consulte [inline, \_\_inline, \_\_forceinline](../misc/inline-inline-forceinline.md).  
  
 Para compatibilidade com versões anteriores, todas as instalações de pré\-processadores que existiam em ANSI C e nas especificações anteriores do C\+\+ são preservadas para o Microsoft C\+\+.  
  
## Consulte também  
 [Macros predefinidas](../preprocessor/predefined-macros.md)   
 [Macros](../Topic/Macros%20\(C-C++\).md)