---
title: Princípios de manipulação de eventos (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- event handling, implementing
- event handling, advising event sources
- interfaces, event and event sink
- dual interfaces, event interfaces
- event handling, dual event interfaces
ms.assetid: d17ca7cb-54f2-4658-ab8b-b721ac56801d
ms.openlocfilehash: 066c8db60afed31ceba1c9ef6f4a10d5f842e608
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492151"
---
# <a name="event-handling-principles"></a>Princípios de manipulação de eventos

Há três etapas comuns a todos os tratamentos de eventos. Você precisará:

- Implemente a interface de evento em seu objeto.

- Avise à origem do evento que seu objeto deseja receber eventos.

- Cancelar aviso da origem do evento quando o objeto não precisar mais receber eventos.

A maneira como você implementará a interface de evento dependerá de seu tipo. Uma interface de evento pode ser vtable, dual ou uma dispinterface. Cabe ao designer da origem do evento definir a interface; cabe a você implementar essa interface.

> [!NOTE]
>  Embora não haja motivos técnicos para que uma interface de evento não possa ser dupla, há uma série de motivos de design bons para evitar o uso de dois processadores. No entanto, essa é uma decisão tomada pelo designer/implementador da *origem*do evento. Como você está trabalhando a partir da perspectiva do evento `sink`, é necessário permitir a possibilidade de que você não tenha qualquer escolha, mas implementar uma interface de evento dupla. Para obter mais informações sobre interfaces duplas, consulte [interfaces duplas e ATL](../atl/dual-interfaces-and-atl.md).

Aconselhar a origem do evento pode ser dividido em três etapas:

- Consulte o objeto de origem para [IConnectionPointContainer](/windows/win32/api/ocidl/nn-ocidl-iconnectionpointcontainer).

- Chame [IConnectionPointContainer:: FindConnectionPoint](/windows/win32/api/ocidl/nf-ocidl-iconnectionpointcontainer-findconnectionpoint) passando o IID da interface de evento que lhe interessa. Se for bem-sucedido, isso retornará a interface [IConnectionPoint](/windows/win32/api/ocidl/nn-ocidl-iconnectionpoint) em um objeto de ponto de conexão.

- Chame [IConnectionPoint:: Advise](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-advise) passando o `IUnknown` do coletor de eventos. Se for bem-sucedido, isso retornará um `DWORD` cookie que representa a conexão.

Depois de registrar com êxito seu interesse no recebimento de eventos, os métodos na interface de evento do objeto serão chamados de acordo com os eventos acionados pelo objeto de origem. Quando você não precisar mais receber eventos, poderá passar o cookie de volta para o ponto de conexão por meio de [IConnectionPoint:: Unadvise](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-unadvise). Isso interromperá a conexão entre a origem e o coletor.

Tenha cuidado para evitar ciclos de referência ao manipular eventos.

## <a name="see-also"></a>Consulte também

[Manipulação de eventos](../atl/event-handling-and-atl.md)
