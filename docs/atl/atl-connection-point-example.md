---
title: Exemplo de Ponto de Conexão de ATL
ms.date: 11/04/2016
helpviewer_keywords:
- connection points [C++], examples
- examples [ATL]
ms.assetid: a49721b7-f308-43de-8868-f662a94bc81a
ms.openlocfilehash: f33364cee65031c358fb546312f3fe2b7ae854d3
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491791"
---
# <a name="atl-connection-point-example"></a>Exemplo de Ponto de Conexão de ATL

Este exemplo mostra um objeto que dá suporte a [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) como uma interface de saída:

[!code-cpp[NVC_ATL_Windowing#84](../atl/codesnippet/cpp/atl-connection-point-example_1.h)]

Ao especificar `IPropertyNotifySink` como uma interface de saída, você pode usar a classe [IPropertyNotifySinkCP](../atl/reference/ipropertynotifysinkcp-class.md) em `IConnectionPointImpl`vez de. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#85](../atl/codesnippet/cpp/atl-connection-point-example_2.h)]

## <a name="see-also"></a>Consulte também

[Ponto de conexão](../atl/atl-connection-points.md)
