---
title: "Classe de CDynamicChain | Microsoft Docs"
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
  - "ATL::CDynamicChain"
  - "ATL.CDynamicChain"
  - "CDynamicChain"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDynamicChain"
  - "encadeando mapas de mensagem"
  - "mapas de mensagem, encadeamento"
ms.assetid: f084b2be-0e77-4836-973d-ae278a1e9da8
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDynamicChain
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos que suportam encadeamento dinâmica de mapas de mensagem.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CDynamicChain  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDynamicChain::CDynamicChain](../Topic/CDynamicChain::CDynamicChain.md)|o construtor.|  
|[CDynamicChain::~CDynamicChain](../Topic/CDynamicChain::~CDynamicChain.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDynamicChain::CallChain](../Topic/CDynamicChain::CallChain.md)|Direciona uma mensagem do windows no mapa da mensagem de outro objeto.|  
|[CDynamicChain::RemoveChainEntry](../Topic/CDynamicChain::RemoveChainEntry.md)|Remover uma entrada de mapa de mensagem de coleção.|  
|[CDynamicChain::SetChainEntry](../Topic/CDynamicChain::SetChainEntry.md)|Adiciona uma entrada de mapa de mensagem à coleção ou modificar uma entrada existente.|  
  
## Comentários  
 `CDynamicChain` gerencia uma coleção de mapas de mensagem, permitindo uma mensagem do windows a ser direcionada, em tempo de execução, no mapa da mensagem de outro objeto.  
  
 Para adicionar suporte para encadear dinâmica de mapas de mensagem, faça o seguinte:  
  
-   Derivado da classe de `CDynamicChain`.  Em o mapa de mensagem, especifique a macro de [CHAIN\_MSG\_MAP\_DYNAMIC](../Topic/CHAIN_MSG_MAP_DYNAMIC.md) encadear ao mapa padrão da mensagem de outro objeto.  
  
-   Cada classe derivada que você deseja encadeamento de [CMessageMap](../../atl/reference/cmessagemap-class.md).  `CMessageMap` permite que um objeto expõe seus mapeamentos de mensagem para outros objetos.  
  
-   Chame `CDynamicChain::SetChainEntry` para identificar ao objeto e que o mapa de mensagem que você deseja encadear.  
  
 Por exemplo, suponha que sua classe é definida como segue:  
  
 [!code-cpp[NVC_ATL_Windowing#88](../../atl/codesnippet/CPP/cdynamicchain-class_1.h)]  
  
 O cliente chama em `CMyWindow::SetChainEntry`:  
  
 [!code-cpp[NVC_ATL_Windowing#89](../../atl/codesnippet/CPP/cdynamicchain-class_2.cpp)]  
  
 `chainedObj` onde é o objeto encadeado e é uma instância de uma classe derivada de `CMessageMap`.  Agora, se `myCtl` recebe uma mensagem que não seja tratada por `OnPaint` ou por `OnSetFocus`, o procedimento de janela direciona a mensagem para o mapeamento padrão da mensagem de `chainedObj`.  
  
 Para obter mais informações sobre o mapa de mensagem que encadea, consulte [Mapas de mensagem](../../atl/message-maps-atl.md) no artigo “classes de janela ATL”.  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [Classe de CWindowImpl](../Topic/CWindowImpl%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)