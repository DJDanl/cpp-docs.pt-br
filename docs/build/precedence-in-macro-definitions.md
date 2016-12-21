---
title: "Preced&#234;ncia em defini&#231;&#245;es de macro | Microsoft Docs"
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
helpviewer_keywords: 
  - "Macros , precedência"
  - "programa NMAKE, precedência em definições macro"
ms.assetid: 0c13182d-83cb-4cbd-af2d-f4c916b62aeb
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Preced&#234;ncia em defini&#231;&#245;es de macro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se uma macro tem várias definições, NMAKE usa a definição de alta prioridade.  A lista a seguir mostra a ordem de prioridade, do mais alto ao mais baixo:  
  
1.  Uma macro definido na linha de comando  
  
2.  Uma macro definido em um makefile ou inclui o arquivo  
  
3.  Uma macro herdado da variável de ambiente  
  
4.  Uma macro definido no arquivo de Tools.ini  
  
5.  Uma macro predefinido, como [CC](../build/command-macros-and-options-macros.md) e [AS](../build/command-macros-and-options-macros.md)  
  
 Use \/E para fazer com que as macros herdados de variáveis de ambiente para macros de makefile de substituição com o mesmo nome.  Use **\!UNDEF** para substituir uma linha de comando.  
  
## Consulte também  
 [Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)