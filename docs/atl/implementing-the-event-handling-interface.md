---
title: "Implementando a interface de manipula&#231;&#227;o de eventos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, tratamento de eventos"
  - "tratamento de eventos, ATL"
  - "interfaces, evento e coletor de eventos"
ms.assetid: eb2a5b33-88dc-4ce3-bee0-c5c38ea050d7
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando a interface de manipula&#231;&#227;o de eventos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

ATL ajuda você com todos os três elementos necessários: manipulando eventos implementando a interface de evento, recomendando a fonte do evento, e unadvising a fonte do evento.  As etapas que precisas você precisará ter dependem do tipo da interface de evento e dos requisitos de desempenho de seu aplicativo.  
  
 As maneiras mais comuns de implementar uma interface que usa ATL são:  
  
-   Derivando de uma interface diretamente.  
  
-   Derivando de [IDispatchImpl](../atl/reference/idispatchimpl-class.md) para as interfaces duais descritas em uma biblioteca de tipo.  
  
-   Derivando de [IDispEventImpl](../atl/reference/idispeventimpl-class.md) para os dispinterfaces descritos em uma biblioteca de tipo.  
  
-   Derivando de [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) para os dispinterfaces não descritos em uma biblioteca de tipo ou quando você deseja melhorar a eficiência não carregar informações tipo em tempo de execução.  
  
 Se você estiver implementando uma interface ou dupla, você deve recomendar a fonte do evento chamando [AtlAdvise](../Topic/AtlAdvise.md) ou [CComPtrBase::Advise](../Topic/CComPtrBase::Advise.md).  Você precisará manter controle do cookie retornada pela chamada você mesmo.  Chamada [AtlUnadvise](../Topic/AtlUnadvise.md) para interromper a conexão.  
  
 Se você estiver implementando um dispinterface usando `IDispEventImpl` ou `IDispEventSimpleImpl`, você deve recomendar a fonte do evento chamando [IDispEventSimpleImpl::DispEventAdvise](../Topic/IDispEventSimpleImpl::DispEventAdvise.md).  Chamada [IDispEventSimpleImpl::DispEventUnadvise](../Topic/IDispEventSimpleImpl::DispEventUnadvise.md) para interromper a conexão.  
  
 Se você estiver usando `IDispEventImpl` como uma classe base de um controle composto, fontes de eventos listadas no mapa do coletor serão recomendadas e [CComCompositeControl::AdviseSinkMap](../Topic/CComCompositeControl::AdviseSinkMap.md)automaticamente uso de irracional.  
  
 As classes de `IDispEventImpl` e de `IDispEventSimpleImpl` gerenciam o cookie para você.  
  
## Consulte também  
 [Manipulação de eventos](../Topic/Event%20Handling%20and%20ATL.md)