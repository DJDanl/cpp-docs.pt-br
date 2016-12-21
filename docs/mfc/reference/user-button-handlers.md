---
title: "Manipuladores de bot&#227;o do usu&#225;rio | Microsoft Docs"
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
  - "ON_BN_HILITE"
  - "ON_BN_DOUBLECLICKED"
  - "ON_BN_CLICKED"
  - "ON_BN_PAINT"
  - "ON_BN_DISABLE"
  - "ON_BN_UNHILITE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ON_BN_CLICKED"
  - "ON_BN_DISABLE"
  - "ON_BN_DOUBLECLICKED"
  - "ON_BN_HILITE"
  - "ON_BN_PAINT"
  - "ON_BN_UNHILITE"
  - "botões de usuário"
ms.assetid: 410ea968-478f-4806-b7b8-5d7c8dc2bf42
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores de bot&#227;o do usu&#225;rio
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As entradas de mapa correspondem a seguir protótipos de função.  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|ON\_BN\_CLICKED \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_BN\_DISABLE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_BN\_DOUBLECLICKED \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_BN\_HILITE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_BN\_PAINT \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_BN\_UNHILITE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)