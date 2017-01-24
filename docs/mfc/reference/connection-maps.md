---
title: "Mapas de conex&#227;o | Microsoft Docs"
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
  - "mapas de conexão"
ms.assetid: 1f25a9bc-6d09-4614-99cf-dc38e8ddfa73
caps.latest.revision: 12
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mapas de conex&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Controladores OLE podem expor interfaces para outros aplicativos.  Essas interfaces permitem acesso somente de um contêiner no controle.  Se um controlador OLE deseja acessar interfaces externos de outros objetos OLE, um ponto de conexão deve ser estabelecida.  Esse ponto de conexão permite a um controle o acesso de saída mapas externos de distribuição, como mapas de evento ou funções de notificação.  
  
 A biblioteca de classes do Microsoft oferece um modelo de programação que oferece suporte a pontos de conexão.  Neste modelo, “mapas conexão” são usados para designar interfaces ou pontos de conexão do controlador OLE.  Os mapas de conexão contêm uma macro para cada ponto de conexão.  Para obter mais informações sobre mapas de conexão, consulte a classe de [CConnectionPoint](../Topic/CConnectionPoint%20Class.md) .  
  
 Normalmente, um controle dará suporte a apenas dois pontos de conexão: um para eventos e um para notificações da propriedade.  Esses são implementados pela classe base de `COleControl` e não requer nenhum trabalho adicional pelo gravador do controle.  Todos os pontos de conexão adicionais que você queira implementar o em sua classe devem ser adicionados manualmente.  Para dar suporte aos mapas e pontos de conexão, MFC o fornece os seguintes macros:  
  
### Declaração e delimitação da conexão  
  
|||  
|-|-|  
|[BEGIN\_CONNECTION\_PART](../Topic/BEGIN_CONNECTION_PART.md)|Declara uma classe que implementa inserido um ponto de conexão adicional \(deve ser usado na declaração de classe\).|  
|[END\_CONNECTION\_PART](../Topic/END_CONNECTION_PART.md)|Termina a declaração de um ponto de conexão \(deve ser usado na declaração de classe\).|  
|[CONNECTION\_IID](../Topic/CONNECTION_IID.md)|Especifica a ID da interface do ponto de conexão do controle.|  
|[DECLARE\_CONNECTION\_MAP](../Topic/DECLARE_CONNECTION_MAP.md)|Declara que um mapa de conexão será usado em uma classe \(deve ser usado na declaração de classe\).|  
|[BEGIN\_CONNECTION\_MAP](../Topic/BEGIN_CONNECTION_MAP.md)|Inicia a definição de um mapa de conexão \(deve ser usado na implementação da classe\).|  
|[END\_CONNECTION\_MAP](../Topic/END_CONNECTION_MAP.md)|Termina a definição de um mapa de conexão \(deve ser usado na implementação da classe\).|  
|[CONNECTION\_PART](../Topic/CONNECTION_PART.md)|Especifica um ponto de conexão da conexão de controle.|  
  
 As seguintes funções ajudam a um coletor em estabelecer e em desconectar uma conexão usando pontos de conexão:  
  
### Inicialização ou encerramento de pontos de conexão  
  
|||  
|-|-|  
|[AfxConnectionAdvise](../Topic/AfxConnectionAdvise.md)|Estabelece uma conexão entre uma origem e um coletor.|  
|[AfxConnectionUnadvise](../Topic/AfxConnectionUnadvise.md)|Interrompe a conexão entre uma origem e um coletor.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)