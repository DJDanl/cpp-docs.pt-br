---
title: "Estrutura MINMAXINFO | Microsoft Docs"
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
  - "MINMAXINFO"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura MINMAXINFO"
ms.assetid: be6fb578-f98a-4581-9ada-be9df308ed2f
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura MINMAXINFO
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `MINMAXINFO` contém informações sobre o tamanho da janela e posição maximizada e mínimo e máximo de tamanho de rastreamento.  
  
## Sintaxe  
  
```  
  
      typedef struct tagMINMAXINFO {  
   POINT ptReserved;  
   POINT ptMaxSize;  
   POINT ptMaxPosition;  
   POINT ptMinTrackSize;  
   POINT ptMaxTrackSize;  
} MINMAXINFO;  
```  
  
#### Parâmetros  
 *ptReserved*  
 Reservado para uso interno.  
  
 *ptMaxSize*  
 Especifica a largura point.x maximizada \(\) e a altura point.y maximizada \(\) da janela.  
  
 `ptMaxPosition`  
 Especifica a posição do lado esquerdo da janela point.x maximizada \(\) e a posição da parte superior da janela maximizada \(point.y\).  
  
 *ptMinTrackSize*  
 Especifica a largura mínima de rastreamento \(point.x\) e a altura mínima de rastreamento \(point.y\) da janela.  
  
 *ptMaxTrackSize*  
 Especifica a largura máxima de rastreamento \(point.x\) e a altura de controle máximo \(point.y\) da janela.  
  
## Requisitos  
 **Header:** winuser.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnGetMinMaxInfo](../Topic/CWnd::OnGetMinMaxInfo.md)