---
title: Classes de pontos de conexão (ATL)
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- classes [C++], connection points
- connection points classes
ms.assetid: 076365fa-299a-4dce-84c3-a5dff0e0da1f
ms.openlocfilehash: 0dba06b072e1e9ca545ccbea196fcfe371b02157
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492439"
---
# <a name="connection-points-classes"></a>Classes de pontos de conexão

As classes a seguir fornecem suporte para pontos de conexão:

- [IConnectionPointContainerImpl](../atl/reference/iconnectionpointcontainerimpl-class.md) Implementa um contêiner de ponto de conexão.

- [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md) Implementa um ponto de conexão.

- [IPropertyNotifySinkCP](../atl/reference/ipropertynotifysinkcp-class.md) Implementa um ponto de conexão que representa a interface [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink) .

- [CComDynamicUnkArray](../atl/reference/ccomdynamicunkarray-class.md) Gerencia conexões ilimitadas entre um ponto de conexão e seus coletores.

- [CComUnkArray](../atl/reference/ccomunkarray-class.md) Gerencia um número fixo de conexões entre um ponto de conexão e seus coletores.

- [CFirePropNotifyEvent](../atl/reference/cfirepropnotifyevent-class.md) Notifica o coletor do cliente que a propriedade de um objeto foi alterada ou está prestes a ser alterada.

- [IDispEventImpl](../atl/reference/idispeventimpl-class.md) Fornece suporte para pontos de conexão para um objeto COM ATL. Esses pontos de conexão são mapeados com um mapa de coletor de eventos, que é fornecido pelo seu objeto COM.

- [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) Funciona em conjunto com o mapa do coletor de eventos em sua classe para rotear eventos para a função de manipulador apropriada.

## <a name="related-articles"></a>Artigos relacionados

[Pontos de conexão](../atl/atl-connection-points.md)

[Manipulação de eventos e a ATL](../atl/event-handling-and-atl.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../atl/atl-class-overview.md)<br/>
[Macros de ponto de conexão](../atl/reference/connection-point-macros.md)<br/>
[Funções globais de ponto de conexão](../atl/reference/connection-point-global-functions.md)
