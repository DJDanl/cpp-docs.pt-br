---
title: "Macros de mapa de mensagem (MFC) | Microsoft Docs"
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
  - "vc.mfc.messages"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "demarcando mensagens do Windows"
  - "macros de mapa de mensagem"
  - "intervalos de mapas de mensagens"
  - "macros de mapeamento de mensagem"
  - "mapas de mensagem [C++], declaração e demarcação"
  - "mapas de mensagem [C++], Macros "
  - "intervalos, mapa de mensagem"
  - "mensagens do Windows [C++], declaração"
ms.assetid: 531b15ce-32b5-4ca0-a849-bb519616c731
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Macros de mapa de mensagem (MFC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para dar suporte aos mapas da mensagem, MFC o fornece os seguintes macros:  
  
### Macros de declaração e de delimitação retornadas mapa  
  
|||  
|-|-|  
|[DECLARE\_MESSAGE\_MAP](../Topic/DECLARE_MESSAGE_MAP.md)|Declara que um mapa de mensagem será usado em uma classe para mapear mensagens nas funções \(deve ser usado na declaração de classe\).|  
|[BEGIN\_MESSAGE\_MAP](../Topic/BEGIN_MESSAGE_MAP.md)|Inicia a definição de um mapa de mensagem \(deve ser usado na implementação da classe\).|  
|[END\_MESSAGE\_MAP](../Topic/END_MESSAGE_MAP.md)|Termina a definição de um mapa de mensagem \(deve ser usado na implementação da classe\).|  
  
### Macros retornadas mapeamento  
  
|||  
|-|-|  
|[ON\_COMMAND](../Topic/ON_COMMAND.md)|Indica que função tratará uma mensagem especificada do comando.|  
|[ON\_CONTROL](../Topic/ON_CONTROL.md)|Indica que função tratará uma mensagem especificada de controle\- notificação.|  
|[ON\_MESSAGE](../Topic/ON_MESSAGE.md)|Indica que função tratará uma mensagem definida pelo usuário.|  
|[ON\_OLECMD](../Topic/ON_OLECMD.md)|Indica que função tratará um comando de menu de um DocObject ou do contêiner.|  
|[ON\_REGISTERED\_MESSAGE](../Topic/ON_REGISTERED_MESSAGE.md)|Indica que função tratará uma mensagem definida pelo usuário registrado.|  
|[ON\_REGISTERED\_THREAD\_MESSAGE](../Topic/ON_REGISTERED_THREAD_MESSAGE.md)|Indica que função tratará uma mensagem definida pelo usuário registrado quando você tenha uma classe de `CWinThread` .|  
|[ON\_THREAD\_MESSAGE](../Topic/ON_THREAD_MESSAGE.md)|Indica que função tratará uma mensagem definida pelo usuário quando você tenha uma classe de `CWinThread` .|  
|[ON\_UPDATE\_COMMAND\_UI](../Topic/ON_UPDATE_COMMAND_UI.md)|Indica que função tratará uma mensagem especificada do comando de atualização da interface do usuário.|  
  
### Macros do intervalo retornadas mapa  
  
|||  
|-|-|  
|[ON\_COMMAND\_RANGE](../Topic/ON_COMMAND_RANGE.md)|Indica que função tratará o intervalo de IDs de comando especificados nos dois primeiros parâmetros para macro.|  
|[ON\_UPDATE\_COMMAND\_UI\_RANGE](../Topic/ON_UPDATE_COMMAND_UI_RANGE.md)|Indica que o manipulador de atualização tratará o intervalo de IDs de comando especificados nos dois primeiros parâmetros para macro.|  
|[ON\_CONTROL\_RANGE](../Topic/ON_CONTROL_RANGE.md)|Indica que função tratará notificações do intervalo de IDs de controle especificados em segundos e terceiro parâmetros a macro.  O primeiro parâmetro é uma mensagem de controle\- notificação, como **BN\_CLICKED**.|  
  
 Para obter mais informações sobre mapas da mensagem, macros de declaração retornadas mapa e de delimitação, e macros retornadas mapeamento, consulte [Mapas da mensagem](../../mfc/reference/message-maps-mfc.md) e [Tópicos de manipulação e o mapeamento de mensagem](../../mfc/message-handling-and-mapping.md).  Para obter mais informações sobre os intervalos retornadas o mapa, consulte [Manipuladores para intervalos retornadas mapa](../../mfc/handlers-for-message-map-ranges.md).  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)