---
title: Interfaces duplas e eventos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- events [C++], dual interfaces
- dual interfaces, events
ms.assetid: bb382f7c-e885-4274-bf07-83f3602615d2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 99dc173f3dde8ea81f6dc11d02298cd94673f999
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32354061"
---
# <a name="dual-interfaces-and-events"></a>Eventos e Interfaces duplas
Embora seja possível criar uma interface de evento como um duplo, há vários motivos bom design para não fazer isso. O motivo fundamental é que a origem do evento será disparado somente o evento por meio de vtable ou `Invoke`, mas não ambos. Se a origem do evento dispara o evento como uma chamada de método vtable direto, o `IDispatch` métodos nunca serão usados e é claro que a interface deve ter sido uma interface vtable puro. Se a origem do evento dispara o evento como uma chamada para `Invoke`, os métodos vtable nunca serão usados e é claro que a interface deve ter sido um dispinterface. Se você definir as interfaces de evento como duals, você vai exigir que clientes implementar a parte de uma interface que nunca será usada.  
  
> [!NOTE]
>  Esse argumento não se aplica às duas interfaces, em geral. De uma perspectiva de implementação, duals são uma maneira bem com suporte, rápida e conveniente de implementação de interfaces que são acessíveis a uma ampla gama de clientes.  
  
 Houver mais razões para evitar interfaces de evento dupla; suporte Visual Basic, nem Internet Explorer.  
  
## <a name="see-also"></a>Consulte também  
 [Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)

