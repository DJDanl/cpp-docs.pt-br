---
title: "Princ&#237;pios de manipula&#231;&#227;o de eventos | Microsoft Docs"
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
  - "eventos de manipulação, Implementando"
  - "eventos de manipulação, avisando fontes de evento"
  - "interfaces, o evento e o coletor de eventos"
  - "duas interfaces, interfaces de evento"
  - "manipulação de eventos, interfaces de evento duplo"
ms.assetid: d17ca7cb-54f2-4658-ab8b-b721ac56801d
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Princ&#237;pios de manipula&#231;&#227;o de eventos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há três etapas comuns a todos os manipulação de eventos. Você precisará:  
  
-   Implemente a interface de eventos em seu objeto.  
  
-   A origem do evento de aviso que o objeto deseja receber eventos.  
  
-   Não recomendar a origem do evento quando o objeto não precisa receber eventos.  
  
 A maneira que você implementará a interface de eventos dependerá de seu tipo. Uma interface de eventos pode ser um dispinterface, duplo ou vtable. Cabe ao designer de origem do evento para definir a interface; cabe a você implementar essa interface.  
  
> [!NOTE]
>  Embora não haja nenhum razões técnicas que uma interface de eventos não pode ser dupla, há vários motivos bom design para evitar o uso de duals. No entanto, isso é uma decisão feita pelo designer\/implementador do evento *fonte*. Como você está trabalhando da perspectiva do evento `sink`, é necessário para permitir a possibilidade de que você pode não ter nada, mas para implementar uma interface de dois eventos. Para obter mais informações sobre interfaces duplas, consulte [Interfaces duplas e ATL](../atl/dual-interfaces-and-atl.md).  
  
 Informando a origem do evento pode ser dividido em três etapas:  
  
-   Consultar o objeto de origem [IConnectionPointContainer](http://msdn.microsoft.com/library/windows/desktop/ms683857).  
  
-   Chamar [IConnectionPointContainer::FindConnectionPoint](http://msdn.microsoft.com/library/windows/desktop/ms692476) passando o IID da interface de eventos que lhe interessa. Se for bem\-sucedido, isso irá retornar o [IConnectionPoint](http://msdn.microsoft.com/library/windows/desktop/ms694318) interface em um objeto de ponto de conexão.  
  
-   Chamar [IConnectionPoint::](http://msdn.microsoft.com/library/windows/desktop/ms678815) passando o **IUnknown** do coletor de eventos. Se for bem\-sucedido, isso retornará um `DWORD` cookie que representa a conexão.  
  
 Depois que você registrou com êxito seu interesse no recebimento de eventos, métodos na interface de eventos do objeto serão chamados de acordo com os eventos disparados por objeto de origem. Quando você não precisa receber eventos, você pode passar o cookie de volta para o ponto de conexão por meio de [IConnectionPoint::Unadvise](http://msdn.microsoft.com/library/windows/desktop/ms686608). Isso interromperá a conexão entre a fonte e coletor.  
  
 Tenha cuidado para evitar referência ciclos de manipulação de eventos.  
  
## Consulte também  
 [Manipulação de eventos](../Topic/Event%20Handling%20and%20ATL.md)