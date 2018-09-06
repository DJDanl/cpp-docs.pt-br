---
title: Classes de pontos de Conexão (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.atl.connection
dev_langs:
- C++
helpviewer_keywords:
- classes [C++], connection points
- connection points classes
ms.assetid: 076365fa-299a-4dce-84c3-a5dff0e0da1f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e24d6333faee842227edb09ea05aa6a1f8b0d9a0
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43763595"
---
# <a name="connection-points-classes"></a>Classes de pontos de Conexão

As classes a seguir fornecem suporte para pontos de conexão:

- [IConnectionPointContainerImpl](../atl/reference/iconnectionpointcontainerimpl-class.md) implementa um contêiner de ponto de conexão.

- [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md) implementa um ponto de conexão.

- [IPropertyNotifySinkCP](../atl/reference/ipropertynotifysinkcp-class.md) implementa um ponto de conexão que representa o [IPropertyNotifySink](/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink) interface.

- [CComDynamicUnkArray](../atl/reference/ccomdynamicunkarray-class.md) gerencia conexões ilimitadas entre um ponto de conexão e seus coletores.

- [CComUnkArray](../atl/reference/ccomunkarray-class.md) gerencia um número fixo de conexões entre um ponto de conexão e seus coletores.

- [CFirePropNotifyEvent](../atl/reference/cfirepropnotifyevent-class.md) notifica o coletor de um cliente que a propriedade de um objeto foi alterado ou está prestes a ser alterada.

- [IDispEventImpl](../atl/reference/idispeventimpl-class.md) fornece suporte para pontos de conexão para um objeto COM ATL. Esses pontos de conexão são mapeados com um mapa de coletor de eventos, que é fornecido pelo seu objeto COM.

- [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) trabalha em conjunto com o coletor de eventos do mapa em sua classe para eventos de rota para a função de manipulador apropriado.

## <a name="related-articles"></a>Artigos relacionados

[Pontos de conexão](../atl/atl-connection-points.md)

[Manipulação de eventos e a ATL](../atl/event-handling-and-atl.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../atl/atl-class-overview.md)   
[Macros de ponto de Conexão](../atl/reference/connection-point-macros.md)   
[Funções globais de ponto de conexão](../atl/reference/connection-point-global-functions.md)

