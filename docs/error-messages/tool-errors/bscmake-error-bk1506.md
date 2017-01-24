---
title: "Erro BK1506 (BSCMAKE) | Microsoft Docs"
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
  - "BK1506"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "BK1506"
ms.assetid: f51f8cea-f8fc-4323-bcf2-b7bd119792ee
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro BK1506 (BSCMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o não pode abrir arquivo “nome de arquivo” \[: motivo\]  
  
 BSCMAKE não pode abrir o arquivo.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  Arquivo bloqueado por outro processo.  Se `reason` informa **Permissão negada**, o navegador do pode usar o arquivo.  Feche a janela procurar e repita a compilação.  
  
2.  Um disco cheio.  
  
3.  Um erro de hardware.  
  
4.  O arquivo de saída especificado tem o mesmo nome que um subdiretório existente.