---
title: "Executando NMAKE | Microsoft Docs"
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
  - "arquivos de comando"
  - "arquivos de comando, NMAKE"
  - "programa NMAKE, executando"
  - "programa NMAKE, destinos"
  - "arquivos de resposta, NMAKE"
  - "destinos"
  - "destinos, compilando"
ms.assetid: 0421104d-8b7b-4bf3-86c1-928d9b7c1a8c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Executando NMAKE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
NMAKE [option...] [macros...] [targets...] [@commandfile...]  
```  
  
## Comentários  
 As construções de NMAKE especificadas somente *destinos* ou, se nenhum for especificado, o primeiro destino no makefile.  O primeiro destino de makefile pode ser [pseudotarget](../build/pseudotargets.md) que cria outros destinos.  NMAKE usa os makefiles especificados com \/F; \/F se não for especificado, usará o arquivo de Makefile no diretório atual.  Se nenhum makefile é especificado, usa regras de inferência para criar *destinos*de linha de comando.  
  
 O arquivo de texto de `commandfile` \(ou arquivo de resposta\) contêm a entrada da linha de comando.  A outra entrada pode inserir antes ou depois`commandfile`@.  Um caminho é permitido.  Em `commandfile`, as quebras de linha é tratada como espaços.  Incluir definições macro entre aspas se contiverem espaços.  
  
## Que você deseja saber mais?  
 [Opções de NMAKE](../Topic/NMAKE%20Options.md)  
  
 [Tools.ini e NMAKE](../build/tools-ini-and-nmake.md)  
  
 [Códigos de saída de NMAKE](../build/exit-codes-from-nmake.md)  
  
## Consulte também  
 [Referência de NMAKE](../build/nmake-reference.md)