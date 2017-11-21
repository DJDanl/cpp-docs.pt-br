---
title: Interfaces duplas e eventos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- events [C++], dual interfaces
- dual interfaces, events
ms.assetid: bb382f7c-e885-4274-bf07-83f3602615d2
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d18124646f4d4fcb02246234bf74b5870246e7e4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="dual-interfaces-and-events"></a>Eventos e Interfaces duplas
Embora seja possível criar uma interface de evento como um duplo, há vários motivos bom design para não fazer isso. O motivo fundamental é que a origem do evento será disparado somente o evento por meio de vtable ou `Invoke`, mas não ambos. Se a origem do evento dispara o evento como uma chamada de método vtable direto, o `IDispatch` métodos nunca serão usados e é claro que a interface deve ter sido uma interface vtable puro. Se a origem do evento dispara o evento como uma chamada para `Invoke`, os métodos vtable nunca serão usados e é claro que a interface deve ter sido um dispinterface. Se você definir as interfaces de evento como duals, você vai exigir que clientes implementar a parte de uma interface que nunca será usada.  
  
> [!NOTE]
>  Esse argumento não se aplica às duas interfaces, em geral. De uma perspectiva de implementação, duals são uma maneira bem com suporte, rápida e conveniente de implementação de interfaces que são acessíveis a uma ampla gama de clientes.  
  
 Houver mais razões para evitar interfaces de evento dupla; suporte Visual Basic, nem Internet Explorer.  
  
## <a name="see-also"></a>Consulte também  
 [Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)

