---
title: Classes de Ponto de Conexão de ATL
ms.date: 11/04/2016
helpviewer_keywords:
- CFirePropNotifyEvent class, connection point classes
- connection points [C++], ATL classes
- ATL, connection points
- CComDynamicUnkArray class, connection point classes
- CFirePropNotifyEvent class
- CComUnkArray class, connection point classes
ms.assetid: 9582ba71-7ace-4df4-9c9b-1b0636953efc
ms.openlocfilehash: f3794b5c9e4f6297cca6611929c75d0b0133557e
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57265230"
---
# <a name="atl-connection-point-classes"></a>Classes de Ponto de Conexão de ATL

ATL usa as seguintes classes para dar suporte a pontos de conexão:

- [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md) implementa um ponto de conexão. O IID da interface de saída representa é passado como um parâmetro de modelo.

- [IConnectionPointContainerImpl](../atl/reference/iconnectionpointcontainerimpl-class.md) implementa o contêiner de ponto de conexão e gerencia a lista de `IConnectionPointImpl` objetos.

- [IPropertyNotifySinkCP](../atl/reference/ipropertynotifysinkcp-class.md) implementa um ponto de conexão que representa o [IPropertyNotifySink](/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink) interface.

- [CComDynamicUnkArray](../atl/reference/ccomdynamicunkarray-class.md) gerencia um número arbitrário de conexões entre o ponto de conexão e seus coletores.

- [CComUnkArray](../atl/reference/ccomunkarray-class.md) gerencia um número predefinido de conexões conforme especificado pelo parâmetro de modelo.

- [CFirePropNotifyEvent](../atl/reference/cfirepropnotifyevent-class.md) notifica o coletor de um cliente que a propriedade de um objeto foi alterado ou está prestes a ser alterada.

- [IDispEventImpl](../atl/reference/idispeventimpl-class.md) fornece suporte para pontos de conexão para um objeto COM ATL. Esses pontos de conexão são mapeados com um mapa de coletor de eventos, que é fornecido pelo seu objeto COM.

- [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) funciona em conjunto com o mapa de coletor de eventos em sua classe para eventos de rota para a função de manipulador apropriado.

## <a name="see-also"></a>Consulte também

[Ponto de Conexão](../atl/atl-connection-points.md)
