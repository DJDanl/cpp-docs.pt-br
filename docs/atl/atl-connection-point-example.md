---
title: Exemplo de Ponto de Conexão de ATL
ms.date: 11/04/2016
helpviewer_keywords:
- connection points [C++], examples
- examples [ATL]
ms.assetid: a49721b7-f308-43de-8868-f662a94bc81a
ms.openlocfilehash: 3113637a3f777a56bc0b0994203ce709fbc189d5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62223336"
---
# <a name="atl-connection-point-example"></a>Exemplo de Ponto de Conexão de ATL

Este exemplo mostra um objeto que suporta [IPropertyNotifySink](/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink) como uma interface de saída:

[!code-cpp[NVC_ATL_Windowing#84](../atl/codesnippet/cpp/atl-connection-point-example_1.h)]

Ao especificar `IPropertyNotifySink` como uma interface de saída, você pode usar a classe [IPropertyNotifySinkCP](../atl/reference/ipropertynotifysinkcp-class.md) em vez de `IConnectionPointImpl`. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#85](../atl/codesnippet/cpp/atl-connection-point-example_2.h)]

## <a name="see-also"></a>Consulte também

[Ponto de Conexão](../atl/atl-connection-points.md)
