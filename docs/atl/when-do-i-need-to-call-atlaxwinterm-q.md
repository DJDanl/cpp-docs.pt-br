---
title: "Quando eu preciso de chamar AtlAxWinTerm? | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "AtlAxWinTerm"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método de AtlAxWinTerm"
ms.assetid: 0088d494-2d8d-45b4-b582-2af726bd6cbd
caps.latest.revision: 12
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Quando eu preciso de chamar AtlAxWinTerm?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Desregistre de[AtlAxWinTerm](../Topic/AtlAxWinTerm.md) a classe de janela de **"AtlAxWin80"** .  Você deve chamá\-lo host que existente de função \(se você não precisar criar janelas de host\) após as janelas são destruídas.  Se você não chama essa função, a classe da janela será desregistrado automaticamente quando o processo termina.  
  
## Consulte também  
 [Quando eu preciso de chamar AtlAxWinInit?](../atl/when-do-i-need-to-call-atlaxwininit-q.md)   
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)