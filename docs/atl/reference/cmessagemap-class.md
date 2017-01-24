---
title: "Classe de CMessageMap | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CMessageMap"
  - "ATL.CMessageMap"
  - "ATL::CMessageMap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, manipuladores de mensagem"
  - "Classe de CMessageMap"
  - "mapas de mensagem, ATL"
ms.assetid: 1f97bc16-a8a0-4cf0-b90f-1778813a5c8e
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMessageMap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe permite que os mapeamentos da mensagem de um objeto sejam acesso por outro objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class ATL_NO_VTABLE CMessageMap  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMessageMap::ProcessWindowMessage](../Topic/CMessageMap::ProcessWindowMessage.md)|Acessa um mapa de `CMessageMap`\- classe derivada de mensagem.|  
  
## Comentários  
 `CMessageMap` é uma classe base abstrata que permite que os mapeamentos da mensagem de um objeto sejam acessados por outro objeto.  Para que um objeto expõe seus mapeamentos de mensagem, a classe deve derivar de `CMessageMap`.  
  
 Usos `CMessageMap` suportar o windows contidas e dinâmico mensagem de ATL mapeiam encadear.  Por exemplo, qualquer classe a contendo um objeto de [CContainedWindow](../Topic/CContainedWindowT%20Class.md) devem derivar de `CMessageMap`.  O código a seguir é extraído do exemplo de [REVISAR](../../top/visual-cpp-samples.md) .  Com [CComControl](../../atl/reference/ccomcontrol-class.md), a classe de `CAtlEdit` automaticamente é derivada de `CMessageMap`.  
  
 [!code-cpp[NVC_ATL_Windowing#90](../../atl/codesnippet/CPP/cmessagemap-class_1.h)]  
  
 Porque a janela, contida `m_EditCtrl`, usará um mapa de mensagem a classe continente, `CAtlEdit` deriva de `CMessageMap`.  
  
 Para obter mais informações sobre mapas de mensagem, consulte [Mapas de mensagem](../../atl/message-maps-atl.md) no artigo “classes de janela ATL”.  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [Classe de CDynamicChain](../../atl/reference/cdynamicchain-class.md)   
 [BEGIN\_MSG\_MAP](../Topic/BEGIN_MSG_MAP.md)   
 [ALT\_MSG\_MAP](../Topic/ALT_MSG_MAP.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)