---
title: "Manipuladores do controle de edi&#231;&#227;o | Microsoft Docs"
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
  - "ON_EN_ERRSPACE"
  - "ON_EN_UPDATE"
  - "ON_EN_VSCROLL"
  - "ON_EN_HSCROLL"
  - "ON_EN_KILLFOCUS"
  - "ON_EN_MAXTEXT"
  - "ON_EN_SETFOCUS"
  - "ON_EN_CHANGE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles de edição, manipuladores do controle de edição"
  - "Macro ON_EN_CHANGE"
  - "Macro ON_EN_ERRSPACE"
  - "Macro ON_EN_HSCROLL"
  - "Macro ON_EN_KILLFOCUS"
  - "Macro ON_EN_MAXTEXT"
  - "Macro ON_EN_SETFOCUS"
  - "Macro ON_EN_UPDATE"
  - "Macro ON_EN_VSCROLL"
ms.assetid: 55b88b5e-12b5-4422-b03e-c8c2f27d095c
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores do controle de edi&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As entradas de mapa seguir correspondem ao protótipo da função.  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|ON\_EN\_CHANGE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_EN\_ERRSPACE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_EN\_HSCROLL \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_EN\_KILLFOCUS \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_EN\_MAXTEXT \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_EN\_SETFOCUS \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_EN\_UPDATE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_EN\_VSCROLL \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)