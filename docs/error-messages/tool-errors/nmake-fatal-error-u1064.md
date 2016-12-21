---
title: "Erro fatal U1064 (NMAKE) | Microsoft Docs"
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
  - "U1064"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U1064"
ms.assetid: 7141e66e-cde6-4173-84df-a391f3ebcdd1
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal U1064 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

MAKEFILE não encontrado e nenhum destino especificado  
  
 A linha de comando de NMAKE não especificou um makefile ou destino, e o diretório atual não continha um arquivo denominado MAKEFILE.  
  
 NMAKE requer um makefile ou um destino de linha de comando \(ou ambos\).  Para fazer um makefile disponível para NMAKE, especifique a opção \/F ou colocar um arquivo denominado MAKEFILE no diretório atual.  NMAKE pode criar um destino de linha de comando usando uma regra de inferência se um makefile não é fornecido.