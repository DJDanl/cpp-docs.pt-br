---
title: Interfaces e eventos duplos
ms.date: 11/04/2016
helpviewer_keywords:
- events [C++], dual interfaces
- dual interfaces, events
ms.assetid: bb382f7c-e885-4274-bf07-83f3602615d2
ms.openlocfilehash: 4ce5048c25bd55feb0f1eb20fc04ec6bfeead746
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319612"
---
# <a name="dual-interfaces-and-events"></a>Interfaces e eventos duplos

Embora seja possível projetar uma interface de evento como uma dupla, há uma série de boas razões de design para não fazê-lo. A razão fundamental é que a fonte do evento só vai `Invoke`disparar o evento através da vtable ou via , não ambos. Se a fonte do evento disparar o evento `IDispatch` como uma chamada de método vtable direto, os métodos nunca serão usados e é claro que a interface deveria ter sido uma interface pura vtable. Se a fonte do evento disparar `Invoke`o evento como uma chamada para , os métodos vtable nunca serão usados e é claro que a interface deveria ter sido uma dispinterface. Se você definir suas interfaces de evento como duplas, você estará exigindo que os clientes implementem parte de uma interface que nunca será usada.

> [!NOTE]
> Este argumento não se aplica a interfaces duplas, em geral. Do ponto de vista da implementação, os duals são uma maneira rápida, conveniente e bem suportada de implementar interfaces acessíveis a uma ampla gama de clientes.

Existem outras razões para evitar interfaces de eventos duplos; nem o Visual Basic nem o Internet Explorer os suportam.

## <a name="see-also"></a>Confira também

[Interfaces duplas e ATL](../atl/dual-interfaces-and-atl.md)
