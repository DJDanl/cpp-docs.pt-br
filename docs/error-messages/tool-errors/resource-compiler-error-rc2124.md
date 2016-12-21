---
title: "Erro RC2124 (compilador de recurso) | Microsoft Docs"
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
  - "RC2124"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RC2124"
ms.assetid: 4eb5c4ec-ca9b-46a0-805b-35e040e9ed41
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro RC2124 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

menus vazias não permitidos  
  
 Uma palavra\-chave de **FIM** aparecer antes que todos os itens de menu sejam definidos na instrução de **MENU** .  O compilador de recursos não permite menus vazias.  Verifique se você não tiver qualquer entre aspas aberta na instrução de **MENU** .