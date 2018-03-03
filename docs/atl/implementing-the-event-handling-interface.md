---
title: "Implementando a Interface de manipulação de eventos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- ATL, event handling
- event handling, ATL
- interfaces, event and event sink
ms.assetid: eb2a5b33-88dc-4ce3-bee0-c5c38ea050d7
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9226cf2630ad18651f9bda2f154f49b5b739a433
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="implementing-the-event-handling-interface"></a>Implementando a Interface de manipulação de eventos
ATL ajuda com todos os três elementos necessários para a manipulação de eventos: Implementando a interface de eventos, informando a origem do evento e unadvising a origem do evento. As etapas precisas, que você precisará levar dependem do tipo de interface de eventos e os requisitos de desempenho do seu aplicativo.  
  
 As formas mais comuns de implementação de uma interface usando a ATL são:  
  
-   Derivando de uma interface personalizada diretamente.  
  
-   Derivando de [IDispatchImpl](../atl/reference/idispatchimpl-class.md) para interfaces duplas descritos em uma biblioteca de tipos.  
  
-   Derivando de [IDispEventImpl](../atl/reference/idispeventimpl-class.md) para dispinterfaces descrito em uma biblioteca de tipos.  
  
-   Derivando de [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) para dispinterfaces não descritos em uma biblioteca de tipos ou quando você deseja melhorar a eficiência por não carregar as informações de tipo em tempo de execução.  
  

 Se você estiver implementando uma interface personalizada ou dupla, você deve informar a origem do evento chamando [AtlAdvise](reference/connection-point-global-functions.md#atladvise) ou [CComPtrBase::Advise](../atl/reference/ccomptrbase-class.md#advise). Você precisará controlar o cookie retornado pela chamada. Chamar [AtlUnadvise](reference/connection-point-global-functions.md#atlunadvise) para interromper a conexão.  

  
 Se você estiver implementando um dispinterface usando `IDispEventImpl` ou `IDispEventSimpleImpl`, você deve informar a origem do evento chamando [IDispEventSimpleImpl::DispEventAdvise](../atl/reference/idispeventsimpleimpl-class.md#dispeventadvise). Chamar [IDispEventSimpleImpl::DispEventUnadvise](../atl/reference/idispeventsimpleimpl-class.md#dispeventunadvise) para interromper a conexão.  
  
 Se você estiver usando `IDispEventImpl` como uma classe base de um controle composto, as fontes de evento listadas no mapa do coletor será aconselhável e unadvised automaticamente usando [CComCompositeControl::AdviseSinkMap](../atl/reference/ccomcompositecontrol-class.md#advisesinkmap).  
  
 O `IDispEventImpl` e `IDispEventSimpleImpl` classes gerenciar o cookie para você.  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de eventos](../atl/event-handling-and-atl.md)

