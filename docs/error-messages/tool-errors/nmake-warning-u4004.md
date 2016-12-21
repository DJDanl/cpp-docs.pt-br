---
title: "Aviso U4004 (NMAKE) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "U4004"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U4004"
ms.assetid: 5086bbcb-42d7-4677-a877-1a02202a86a2
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso U4004 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

regras demais para o destino “targetname”  
  
 Mais de um bloco de descrição foi especificado para o destino determinado usando únicos dois\-pontos \(**:**\) como separadores.  NMAKE executa os comandos no primeiro bloco de descrição e ignorado um blocos posterior.  
  
 Para especificar o mesmo destino em vários dependências, use dois\-pontos duplos \(`::`\) como o separador em cada linha da dependência.