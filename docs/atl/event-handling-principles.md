---
title: Princípios de Manipulação de Eventos (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- event handling, implementing
- event handling, advising event sources
- interfaces, event and event sink
- dual interfaces, event interfaces
- event handling, dual event interfaces
ms.assetid: d17ca7cb-54f2-4658-ab8b-b721ac56801d
ms.openlocfilehash: 2e810853e7c81f279039e0b3dfda5199d38deee2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319573"
---
# <a name="event-handling-principles"></a>Princípios de Manipulação de Eventos

Existem três passos comuns a todos os eventos de manuseio. Você precisará:

- Implemente a interface de evento em seu objeto.

- Informe a fonte do evento de que seu objeto deseja receber eventos.

- Desavisado a fonte do evento quando seu objeto não precisar mais receber eventos.

A maneira como você implementará a interface do evento dependerá do seu tipo. Uma interface de evento pode ser vtable, dual ou uma dispinterface. Cabe ao designer da fonte do evento definir a interface; cabe a você implementar essa interface.

> [!NOTE]
> Embora não haja razões técnicas para que uma interface de evento não possa ser dupla, há uma série de boas razões de design para evitar o uso de duals. No entanto, esta é uma decisão tomada pelo designer/implementador da *fonte*do evento. Uma vez que você está trabalhando sob a perspectiva do evento, `sink`você precisa permitir a possibilidade de que você pode não ter escolha a não ser implementar uma interface de evento duplo. Para obter mais informações sobre interfaces duplas, consulte [Interfaces Duplas e ATL](../atl/dual-interfaces-and-atl.md).

Aconselhar a fonte do evento pode ser dividido em três etapas:

- Consulta o objeto de origem do [IConnectionPointContainer](/windows/win32/api/ocidl/nn-ocidl-iconnectionpointcontainer).

- Chamada [IConnectionPointContainer::FindConnectionPoint](/windows/win32/api/ocidl/nf-ocidl-iconnectionpointcontainer-findconnectionpoint) passando o IID da interface de evento que lhe interessa. Se for bem-sucedido, isso retornará a interface [IConnectionPoint](/windows/win32/api/ocidl/nn-ocidl-iconnectionpoint) em um objeto de ponto de conexão.

- Ligue para [o IConnectionPoint:::Avise](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-advise) passar pela `IUnknown` pia do evento. Se for bem sucedido, isso retornará um `DWORD` cookie representando a conexão.

Uma vez que você tenha registrado com sucesso seu interesse em receber eventos, os métodos na interface de eventos do seu objeto serão chamados de acordo com os eventos disparados pelo objeto de origem. Quando você não precisa mais receber eventos, você pode passar o cookie de volta para o ponto de conexão via [IConnectionPoint::Unadvise](/windows/win32/api/ocidl/nf-ocidl-iconnectionpoint-unadvise). Isso vai quebrar a conexão entre a fonte e a pia.

Tenha cuidado para evitar ciclos de referência ao lidar com eventos.

## <a name="see-also"></a>Confira também

[Manipulação de eventos](../atl/event-handling-and-atl.md)
