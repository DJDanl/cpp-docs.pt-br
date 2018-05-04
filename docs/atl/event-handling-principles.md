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
ms.openlocfilehash: cb7577dc7d9fb58f43ee67d5e5b8f00393dca1bf
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="event-handling-principles"></a>Princípios de tratamento de evento
Há três etapas comuns a todos os manipulação de eventos. Você precisará:  
  
-   Implemente a interface de eventos em seu objeto.  
  
-   A origem do evento de aviso que o objeto deseja receber eventos.  
  
-   Unadvise a origem do evento quando o objeto não precisa receber eventos.  
  
 A maneira que implementará a interface de eventos dependerá de seu tipo. Uma interface de eventos pode ser vtable, dual ou dispinterface de um. É o designer da fonte de evento para definir a interface; cabe a você implementar essa interface.  
  
> [!NOTE]
>  Embora não haja nenhum motivos técnicos que uma interface de evento não pode ser dupla, há vários motivos bom design para evitar o uso de duals. No entanto, essa é uma decisão tomada pelo designer/implementador do evento *fonte*. Como você está trabalhando da perspectiva do evento `sink`, é necessário para permitir a possibilidade de que você não pode ter qualquer opção, mas para implementar uma interface de evento dupla. Para obter mais informações sobre interfaces duplas, consulte [Interfaces duplas e ATL](../atl/dual-interfaces-and-atl.md).  
  
 Informando a origem do evento pode ser dividido em três etapas:  
  
-   Consultar o objeto de origem para [IConnectionPointContainer](http://msdn.microsoft.com/library/windows/desktop/ms683857).  
  
-   Chamar [IConnectionPointContainer::FindConnectionPoint](http://msdn.microsoft.com/library/windows/desktop/ms692476) passando o IID da interface de eventos que lhe interessa. Se for bem-sucedido, isto retornará o [IConnectionPoint](http://msdn.microsoft.com/library/windows/desktop/ms694318) interface em um objeto de ponto de conexão.  
  
-   Chamar [IConnectionPoint::](http://msdn.microsoft.com/library/windows/desktop/ms678815) passando o **IUnknown** do coletor de eventos. Se for bem-sucedido, isto retornará um `DWORD` cookie que representa a conexão.  
  
 Depois que você registrou com êxito seu interesse no recebimento de eventos, métodos na interface de eventos do objeto serão chamados de acordo com os eventos disparados pelo objeto de origem. Quando você não precisa receber eventos, você pode passar o cookie de volta para o ponto de conexão por meio de [IConnectionPoint::Unadvise](http://msdn.microsoft.com/library/windows/desktop/ms686608). Isso interromperá a conexão entre a origem e do coletor.  
  
 Tenha cuidado para evitar a referência de ciclos de manipulação de eventos.  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de eventos](../atl/event-handling-and-atl.md)

