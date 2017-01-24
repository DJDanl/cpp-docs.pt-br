---
title: "Macros do mapa de mensagens (ATL) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
ms.assetid: eefdd546-8934-4a30-b263-9c06a8addcbd
caps.latest.revision: 16
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Macros do mapa de mensagens (ATL)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Estes mapeamentos e macros definem entradas de mensagem.  
  
|||  
|-|-|  
|[ALT\_MSG\_MAP](../Topic/ALT_MSG_MAP.md)|Marca o início de um mapa alternativo de mensagem.|  
|[BEGIN\_MSG\_MAP](../Topic/BEGIN_MSG_MAP.md)|Marca o início do mapa padrão de mensagem.|  
|[CHAIN\_MSG\_MAP\_ALT](../Topic/CHAIN_MSG_MAP_ALT.md)|Cadeias a um mapa alternativo de mensagem na classe base.|  
|[CHAIN\_MSG\_MAP\_ALT\_MEMBER](../Topic/CHAIN_MSG_MAP_ALT_MEMBER.md)|Cadeias a um mapa alternativo de mensagem em um membro de dados da classe.|  
|[CHAIN\_MSG\_MAP](../Topic/CHAIN_MSG_MAP.md)|Cadeias ao mapa padrão de mensagem na classe base.|  
|[CHAIN\_MSG\_MAP\_DYNAMIC](../Topic/CHAIN_MSG_MAP_DYNAMIC.md)|Cadeias no mapa de mensagem em outra classe em tempo de execução.|  
|[CHAIN\_MSG\_MAP\_MEMBER](../Topic/CHAIN_MSG_MAP_MEMBER.md)|Cadeias ao mapa padrão de mensagem em um membro de dados da classe.|  
|[COMMAND\_CODE\_HANDLER](../Topic/COMMAND_CODE_HANDLER.md)|Mapeia uma mensagem de **WM\_COMMAND** a uma função de manipulador, com base no código de notificação.|  
|[COMMAND\_HANDLER](../Topic/COMMAND_HANDLER.md)|Mapeia uma mensagem de **WM\_COMMAND** a uma função de manipulador, com base no código de notificação e o identificador do item de menu, do controle, ou de aceleração.|  
|[COMMAND\_ID\_HANDLER](../Topic/COMMAND_ID_HANDLER.md)|Mapeia uma mensagem de **WM\_COMMAND** a uma função de manipulador, com base no identificador do item de menu, do controle, ou de aceleração.|  
|[COMMAND\_RANGE\_CODE\_HANDLER](../Topic/COMMAND_RANGE_CODE_HANDLER.md)|Mapeia uma mensagem de **WM\_COMMAND** a uma função de manipulador, com base no código de notificação e em um intervalo contígua de identificadores de controle.|  
|[COMMAND\_RANGE\_HANDLER](../Topic/COMMAND_RANGE_HANDLER.md)|Mapeia uma mensagem de **WM\_COMMAND** a uma função de manipulador, com base em um intervalo contígua de identificadores de controle.|  
|[DECLARE\_EMPTY\_MSG\_MAP](../Topic/DECLARE_EMPTY_MSG_MAP.md)|Implementa um mapa de mensagem vazia.|  
|[DEFAULT\_REFLECTION\_HANDLER](../Topic/DEFAULT_REFLECTION_HANDLER.md)|Fornece um manipulador padrão para mensagens refletidas que não são tratadas de outra forma.|  
|[END\_MSG\_MAP](../Topic/END_MSG_MAP.md)|A marca final de um mapa de mensagem.|  
|[FORWARD\_NOTIFICATIONS](../Topic/FORWARD_NOTIFICATIONS.md)|Encaminha notificações para a janela pai.|  
|[MESSAGE\_HANDLER](../Topic/MESSAGE_HANDLER.md)|Mapeia uma mensagem do windows para uma função do manipulador.|  
|[MESSAGE\_RANGE\_HANDLER](../Topic/MESSAGE_RANGE_HANDLER.md)|Mapeia um intervalo contígua de mensagens do windows para uma função do manipulador.|  
|[NOTIFY\_CODE\_HANDLER](../Topic/NOTIFY_CODE_HANDLER.md)|Mapeia uma mensagem de **WM\_NOTIFY** a uma função de manipulador, com base no código de notificação.|  
|[NOTIFY\_HANDLER](../Topic/NOTIFY_HANDLER.md)|Mapeia uma mensagem de **WM\_NOTIFY** a uma função de manipulador, com base no código de notificação e o identificador de controle.|  
|[NOTIFY\_ID\_HANDLER](../Topic/NOTIFY_ID_HANDLER.md)|Mapeia uma mensagem de **WM\_NOTIFY** a uma função de manipulador, com base no identificador de controle.|  
|[NOTIFY\_RANGE\_CODE\_HANDLER](../Topic/NOTIFY_RANGE_CODE_HANDLER.md)|Mapeia uma mensagem de **WM\_NOTIFY** a uma função de manipulador, com base no código de notificação e em um intervalo contígua de identificadores de controle.|  
|[NOTIFY\_RANGE\_HANDLER](../Topic/NOTIFY_RANGE_HANDLER.md)|Mapeia uma mensagem de **WM\_NOTIFY** a uma função de manipulador, com base em um intervalo contígua de identificadores de controle.|  
|[REFLECT\_NOTIFICATIONS](../Topic/REFLECT_NOTIFICATIONS.md)|Reflete notificações de volta para a janela que os enviou.|  
|[REFLECTED\_COMMAND\_CODE\_HANDLER](../Topic/REFLECTED_COMMAND_CODE_HANDLER.md)|Mapeia uma mensagem refletida de **WM\_COMMAND** a uma função de manipulador, com base no código de notificação.|  
|[REFLECTED\_COMMAND\_HANDLER](../Topic/REFLECTED_COMMAND_HANDLER.md)|Mapeia uma mensagem refletida de **WM\_COMMAND** a uma função de manipulador, com base no código de notificação e o identificador do item de menu, do controle, ou de aceleração.|  
|[REFLECTED\_COMMAND\_ID\_HANDLER](../Topic/REFLECTED_COMMAND_ID_HANDLER.md)|Mapeia uma mensagem refletida de **WM\_COMMAND** a uma função de manipulador, com base no identificador do item de menu, do controle, ou de aceleração.|  
|[REFLECTED\_COMMAND\_RANGE\_CODE\_HANDLER](../Topic/REFLECTED_COMMAND_RANGE_CODE_HANDLER.md)|Mapeia uma mensagem refletida de **WM\_COMMAND** a uma função de manipulador, com base no código de notificação e em um intervalo contígua de identificadores de controle.|  
|[REFLECTED\_COMMAND\_RANGE\_HANDLER](../Topic/REFLECTED_COMMAND_RANGE_HANDLER.md)|Mapeia uma mensagem refletida de **WM\_COMMAND** a uma função de manipulador, com base em um intervalo contígua de identificadores de controle.|  
|[REFLECTED\_NOTIFY\_CODE\_HANDLER](../Topic/REFLECTED_NOTIFY_CODE_HANDLER.md)|Mapeia uma mensagem refletida de **WM\_NOTIFY** a uma função de manipulador, com base no código de notificação.|  
|[REFLECTED\_NOTIFY\_HANDLER](../Topic/REFLECTED_NOTIFY_HANDLER.md)|Mapeia uma mensagem refletida de **WM\_NOTIFY** a uma função de manipulador, com base no código de notificação e o identificador de controle.|  
|[REFLECTED\_NOTIFY\_ID\_HANDLER](../Topic/REFLECTED_NOTIFY_ID_HANDLER.md)|Mapeia uma mensagem refletida de **WM\_NOTIFY** a uma função de manipulador, com base no identificador de controle.|  
|[REFLECTED\_NOTIFY\_RANGE\_CODE\_HANDLER](../Topic/REFLECTED_NOTIFY_RANGE_CODE_HANDLER.md)|Mapeia uma mensagem refletida de **WM\_NOTIFY** a uma função de manipulador, com base no código de notificação e em um intervalo contígua de identificadores de controle.|  
|[REFLECTED\_NOTIFY\_RANGE\_HANDLER](../Topic/REFLECTED_NOTIFY_RANGE_HANDLER.md)|Mapeia uma mensagem refletida de **WM\_NOTIFY** a uma função de manipulador, com base em um intervalo contígua de identificadores de controle.|  
  
## Consulte também  
 [Macros](../../atl/reference/atl-macros.md)