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
ms.openlocfilehash: 8644fc087d7f0a651724c40d2868e96c9b6ec96a
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491819"
---
# <a name="atl-connection-point-classes"></a>Classes de Ponto de Conexão de ATL

A ATL usa as seguintes classes para dar suporte a pontos de conexão:

- [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md) implementa um ponto de conexão. O IID da interface de saída que ele representa é passado como um parâmetro de modelo.

- [IConnectionPointContainerImpl](../atl/reference/iconnectionpointcontainerimpl-class.md) implementa o contêiner de ponto de conexão e gerencia a `IConnectionPointImpl` lista de objetos.

- [IPropertyNotifySinkCP](../atl/reference/ipropertynotifysinkcp-class.md) implementa um ponto de conexão que representa a interface [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) .

- O [CComDynamicUnkArray](../atl/reference/ccomdynamicunkarray-class.md) gerencia um número arbitrário de conexões entre o ponto de conexão e seus coletores.

- O [CComUnkArray](../atl/reference/ccomunkarray-class.md) gerencia um número predefinido de conexões conforme especificado pelo parâmetro de modelo.

- [CFirePropNotifyEvent](../atl/reference/cfirepropnotifyevent-class.md) notifica o coletor do cliente que a propriedade de um objeto foi alterada ou está prestes a ser alterada.

- O [IDispEventImpl](../atl/reference/idispeventimpl-class.md) fornece suporte para pontos de conexão para um objeto com ATL. Esses pontos de conexão são mapeados com um mapa de coletor de eventos, que é fornecido pelo seu objeto COM.

- O [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) trabalha em conjunto com o mapa do coletor de eventos em sua classe para rotear eventos para a função de manipulador apropriada.

## <a name="see-also"></a>Consulte também

[Ponto de conexão](../atl/atl-connection-points.md)
