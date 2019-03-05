---
title: Implementando o Interface de manipulação de eventos
ms.date: 11/04/2016
helpviewer_keywords:
- ATL, event handling
- event handling, ATL
- interfaces, event and event sink
ms.assetid: eb2a5b33-88dc-4ce3-bee0-c5c38ea050d7
ms.openlocfilehash: d977b59907266a2e0141defa8c496b1e7bc66a6c
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57273407"
---
# <a name="implementing-the-event-handling-interface"></a>Implementando o Interface de manipulação de eventos

ATL ajuda você com todos os três elementos necessários para a manipulação de eventos: implementar a interface de eventos, informando a origem do evento e unadvising a origem do evento. As etapas precisas, que você precisará levar dependem do tipo de interface do evento e os requisitos de desempenho do seu aplicativo.

As formas mais comuns de implementação de uma interface usando ATL são:

- Derivando de uma interface personalizada diretamente.

- Derivando de [IDispatchImpl](../atl/reference/idispatchimpl-class.md) para interfaces duplas descritos em uma biblioteca de tipos.

- Derivando de [IDispEventImpl](../atl/reference/idispeventimpl-class.md) para dispinterfaces descrito em uma biblioteca de tipos.

- Derivando de [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) para dispinterfaces não são descritos em uma biblioteca de tipos ou quando você deseja melhorar a eficiência por não carregar as informações de tipo em tempo de execução.

Se você estiver implementando uma interface dupla ou personalizada, você deve informar a origem do evento chamando [AtlAdvise](reference/connection-point-global-functions.md#atladvise) ou [CComPtrBase::Advise](../atl/reference/ccomptrbase-class.md#advise). Você precisará manter o controle de cookie retornado pela chamada. Chame [AtlUnadvise](reference/connection-point-global-functions.md#atlunadvise) para interromper a conexão.

Se você estiver implementando um usando dispinterface `IDispEventImpl` ou `IDispEventSimpleImpl`, você deve informar a origem do evento chamando [IDispEventSimpleImpl::DispEventAdvise](../atl/reference/idispeventsimpleimpl-class.md#dispeventadvise). Chame [IDispEventSimpleImpl::DispEventUnadvise](../atl/reference/idispeventsimpleimpl-class.md#dispeventunadvise) para interromper a conexão.

Se você estiver usando `IDispEventImpl` como uma classe base de um controle composto, as origens do evento listadas no mapa do coletor será aconselhável e unadvised automaticamente usando [CComCompositeControl::AdviseSinkMap](../atl/reference/ccomcompositecontrol-class.md#advisesinkmap).

O `IDispEventImpl` e `IDispEventSimpleImpl` classes gerenciam o cookie para você.

## <a name="see-also"></a>Consulte também

[Manipulação de eventos](../atl/event-handling-and-atl.md)
