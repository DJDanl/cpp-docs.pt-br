---
title: Princípios (ATL) de manipulação de eventos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- event handling, implementing
- event handling, advising event sources
- interfaces, event and event sink
- dual interfaces, event interfaces
- event handling, dual event interfaces
ms.assetid: d17ca7cb-54f2-4658-ab8b-b721ac56801d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9931e194236871b9d767805464928fd4e553015e
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43762867"
---
# <a name="event-handling-principles"></a>Princípios de manipulação de eventos

Há três etapas comuns a todos os manipulação de eventos. Você precisará:

- Implemente a interface de eventos em seu objeto.

- A origem do evento de aviso que seu objeto deseja receber eventos.

- Não recomendar a origem do evento quando seu objeto não precisa mais receber eventos.

A maneira que você implementará a interface de eventos dependerá de seu tipo. Uma interface de eventos pode ser vtable, dual ou dispinterface de um. Cabe ao designer de origem do evento para definir a interface; cabe a você implementar essa interface.

> [!NOTE]
>  Embora não haja nenhum motivos técnicos que uma interface de eventos não pode ser dupla, há inúmeros motivos bom design para evitar o uso de duals. No entanto, essa é uma decisão feita pelo designer/implementador do evento *fonte*. Como você está trabalhando da perspectiva do evento `sink`, é necessário para permitir que a possibilidade de que você não pode ter qualquer opção, mas para implementar uma interface dupla do evento. Para obter mais informações sobre interfaces duplas, consulte [Interfaces duplas e ATL](../atl/dual-interfaces-and-atl.md).

Informando a origem do evento pode ser dividido em três etapas:

- Consultar o objeto de origem para [IConnectionPointContainer](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer).

- Chame [IConnectionPointContainer::FindConnectionPoint](/windows/desktop/api/ocidl/nf-ocidl-iconnectionpointcontainer-findconnectionpoint) passando o IID da interface do evento que lhe interessa. Se for bem-sucedido, isso retornará a [IConnectionPoint](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpoint) interface em um objeto de ponto de conexão.

- Chame [IConnectionPoint:: Advise](/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-advise) passando o `IUnknown` do coletor de eventos. Se for bem-sucedido, isso retornará um `DWORD` cookie que representa a conexão.

Depois que você registrou com êxito seu interesse no recebimento de eventos, métodos na interface de eventos do objeto serão chamados de acordo com os eventos acionados pelo objeto de fonte. Quando você não precisa mais receber eventos, você pode passar o cookie de volta para o ponto de conexão por meio [IConnectionPoint:: UnAdvise](/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-unadvise). Isso interromperá a conexão entre a origem e coletor.

Tenha cuidado para evitar a referência de ciclos de manipulação de eventos.

## <a name="see-also"></a>Consulte também

[Manipulação de eventos](../atl/event-handling-and-atl.md)

