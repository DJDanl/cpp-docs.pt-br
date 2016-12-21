---
title: "Erro das Ferramentas de Vinculador LNK1140 | Microsoft Docs"
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
  - "LNK1140"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1140"
ms.assetid: 468d7651-a7cd-47b9-aead-5bb2fab56121
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1140
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

módulos demais para a base de dados do programa; link com \/PDB:NONE  
  
 O projeto contiver mais de 4096 módulos.  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  Relink usando [\/PDB: NONE](../../build/reference/pdb-use-program-database.md).  
  
2.  Criar alguns módulos sem informações de depuração.  
  
3.  Reduza o número de módulos.