---
title: "Mapas de coleta de evento | Microsoft Docs"
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
  - "vc.mfc.macros.maps"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "mapas de coleta de evento"
ms.assetid: a9757eb2-5f4a-45ec-a2cd-ce5eec85b16f
caps.latest.revision: 14
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mapas de coleta de evento
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando um controlador OLE inserido dispara um evento, o contêiner recebe o evento de controle usando um mecanismo, chamado de “um mapa coletor de eventos,” MFC fornecido pelo.  Esse mapa do coletor de eventos designa funções do manipulador para cada evento específico, assim como os parâmetros desses eventos.  Para obter mais informações sobre mapas de coletor de eventos, consulte o artigo [Contêiner do controle ActiveX](../../mfc/activex-control-containers.md).  
  
### Mapas de coletor de eventos  
  
|||  
|-|-|  
|[BEGIN\_EVENTSINK\_MAP](../Topic/BEGIN_EVENTSINK_MAP.md)|Inicia a definição de um mapa de coletor de eventos.|  
|[DECLARE\_EVENTSINK\_MAP](../Topic/DECLARE_EVENTSINK_MAP.md)|Declara um mapa de coletor de eventos.|  
|[END\_EVENTSINK\_MAP](../Topic/END_EVENTSINK_MAP.md)|Termina a definição de um mapa de coletor de eventos.|  
|[ON\_EVENT](../Topic/ON_EVENT.md)|Define um manipulador de eventos para um evento específico.|  
|[ON\_EVENT\_RANGE](../Topic/ON_EVENT_RANGE.md)|Define um manipulador de eventos para um evento acionado específico de um conjunto de controladores OLE.|  
|[ON\_EVENT\_REFLECT](../Topic/ON_EVENT_REFLECT.md)|Obtém os eventos disparados pelo controle antes de serem tratados pelo contêiner do controle.|  
|[ON\_PROPNOTIFY](../Topic/ON_PROPNOTIFY.md)|Define um manipulador para tratar notificações de propriedade de um controlador OLE.|  
|[ON\_PROPNOTIFY\_RANGE](../Topic/ON_PROPNOTIFY_RANGE.md)|Define um manipulador para tratar notificações de propriedade de um conjunto de controladores OLE.|  
|[ON\_PROPNOTIFY\_REFLECT](../Topic/ON_PROPNOTIFY_REFLECT.md)|Recebe as notificações da propriedade enviadas pelo controle antes de serem tratados pelo contêiner do controle.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)