---
title: "Erro fatal C1307 | Microsoft Docs"
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
  - "C1307"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1307"
ms.assetid: 6f77d3d4-ba8a-476c-b540-aff19eb4efc4
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1307
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o programa foi editado desde que os dados foram coletados de perfil  
  
 Ao usar [\/LTCG: PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md), o vinculador detectou um módulo de entrada que foi recompilado após: \/LTCGPGINSTRUMENT e que o módulo foram alterados no ponto onde os dados existentes de perfil não são mais relevantes.  Por exemplo, se o gráfico de chamada alterado no módulo recompilado, o compilador gerará C1307.  
  
 Para resolver este erro, a execução \/LTCG:PGINSTRUMENT, refazer todas as execuções de teste, e \/LTCG:PGOPTIMIZEexecutado.  Se você não puder executar \/LTCG:PGINSTRUMENT e refazer todas as execuções de teste, use \/LTCG:PGUPDATE em vez de \/LTCG:PGOPTIMIZE criar a imagem otimizada.