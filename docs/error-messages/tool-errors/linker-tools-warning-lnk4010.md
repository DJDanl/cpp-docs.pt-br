---
title: "Aviso LNK4010 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4010"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4010"
ms.assetid: 2824cf99-4174-4b60-a6e2-c01e9f1ee52d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4010 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

número inválido do número de versão do subsistema; versão padrão do subsistema assumida  
  
 Você pode especificar uma versão para o subsistema de imagem \([\/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md)\).  Cada subsistema tem um requisito da versão mínima.  Se a versão especificada é menor que o mínimo, esse aviso ocorrerá e o vinculador usará apenas o subsistema padrão.