---
title: "C&#243;digos de sa&#237;da de NMAKE | Microsoft Docs"
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
  - "códigos de saída"
  - "programa NMAKE, códigos de saída"
ms.assetid: 75f6913c-1da5-4572-a2d3-8a4e058bed15
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C&#243;digos de sa&#237;da de NMAKE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

NMAKE retorna os seguintes códigos de saída:  
  
|Código|Significado|  
|------------|-----------------|  
|0|Nenhum erro \(possivelmente um aviso\)|  
|1|Construção incompleta \(emitida somente quando \/K for usado\)|  
|2|Erro de programa, possivelmente devido a um dos seguintes:|  
||-   Um erro de sintaxe em makefile|  
||-   Um erro ou um código de saída de um comando|  
||-   Uma interrupção pelo usuário|  
|4|Erro do sistema — fora de memória|  
|255|O destino não é atualizado \(emitido somente quando \/Q é usado\)|  
  
## Consulte também  
 [Executando NMAKE](../build/running-nmake.md)