---
title: "Manipuladores da caixa de listagem | Microsoft Docs"
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
  - "ON_LBN_DBLCLK"
  - "ON_LBN_ERRSPACE"
  - "ON_LBN_SETFOCUS"
  - "ON_LBN_SELCHANGE"
  - "ON_LBN_KILLFOCUS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "caixas de listagem, manipuladores de caixa de listagem"
  - "ON_LBN_DBLCLK"
  - "ON_LBN_ERRSPACE"
  - "ON_LBN_KILLFOCUS"
  - "ON_LBN_SELCHANGE"
  - "ON_LBN_SETFOCUS"
ms.assetid: e4e54412-2167-436a-883b-5dcad01820b8
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores da caixa de listagem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As entradas de mapa seguir têm o protótipo correspondente da função.  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|ON\_LBN\_DBLCLK \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_LBN\_ERRSPACE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_LBN\_KILLFOCUS \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_LBN\_SELCHANGE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_LBN\_SETFOCUS \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)