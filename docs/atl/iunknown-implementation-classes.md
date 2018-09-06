---
title: Classes de implementação de IUnknown (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.atl.Iunknown
dev_langs:
- C++
helpviewer_keywords:
- IUnknown implementation classes
ms.assetid: 47b69bb5-69d8-4a9c-84a8-329bdde2bb3f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 914e11c71d4f015f7b62797d4ba2ab3bfca3c7fb
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43754127"
---
# <a name="iunknown-implementation-classes"></a>Classes de implementação de IUnknown

As seguintes classes implementam `IUnknown` e métodos relacionados:

- [CComObjectRootEx](../atl/reference/ccomobjectrootex-class.md) gerencia a contagem de referências para objetos agregados e não agregados. Permite que você especifique um modelo de threading.

- [CComObjectRoot](../atl/reference/ccomobjectroot-class.md) gerencia a contagem de referências para objetos agregados e não agregados. Usa o padrão de modelo do servidor de threading.

- [CComAggObject](../atl/reference/ccomaggobject-class.md) implementa `IUnknown` para um objeto agregado.

- [CComObject](../atl/reference/ccomobject-class.md) implementa `IUnknown` para um objeto não agregado.

- [CComPolyObject](../atl/reference/ccompolyobject-class.md) implementa `IUnknown` para objetos agregados e não agregados. Usando o `CComPolyObject` evita a necessidade de ambos `CComAggObject` e `CComObject` em seu módulo. Um único `CComPolyObject` objeto lida com casos de agregados e não agregados.

- [CComObjectNoLock](../atl/reference/ccomobjectnolock-class.md) implementa `IUnknown` para um objeto não agregado, sem modificar a contagem de bloqueios do módulo.

- [CComTearOffObject](../atl/reference/ccomtearoffobject-class.md) implementa `IUnknown` para uma interface destacáveis.

- [CComCachedTearOffObject](../atl/reference/ccomcachedtearoffobject-class.md) implementa `IUnknown` para uma interface destacáveis "cache".

- [CComContainedObject](../atl/reference/ccomcontainedobject-class.md) implementa `IUnknown` para o objeto interno de uma agregação ou uma interface destacáveis.

- [CComObjectGlobal](../atl/reference/ccomobjectglobal-class.md) gerencia uma contagem de referência sobre o módulo para garantir que seu objeto não será excluída.

- [CComObjectStack](../atl/reference/ccomobjectstack-class.md) cria um objeto COM temporária, usando uma implementação de esqueleto da `IUnknown`.

## <a name="related-articles"></a>Artigos relacionados

[Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../atl/atl-class-overview.md)   
[Macros de classe de fábrica e agregação](../atl/reference/aggregation-and-class-factory-macros.md)   
[Macros de mapa COM](../atl/reference/com-map-macros.md)   
[Funções globais de mapa COM](../atl/reference/com-map-global-functions.md)

