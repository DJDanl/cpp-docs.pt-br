---
title: Páginas de propriedades e propriedade Classes (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.atl.properties
dev_langs:
- C++
helpviewer_keywords:
- property pages, classes
- properties [ATL], classes
- properties [ATL]
ms.assetid: 31616f98-69f8-48b2-8d58-b8e7d1c2b2d8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 29400fc2e47b419587b81164aa5a7720a7ef134b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46065706"
---
# <a name="properties-and-property-pages-classes"></a>Propriedades e Classes de páginas de propriedade

As classes a seguir dão suporte a propriedades e páginas de propriedades:

- [CComDispatchDriver](../atl/reference/atl-typedefs.md#ccomdispatchdriver) recupera ou define as propriedades de um objeto por meio de um `IDispatch` ponteiro.

- [CStockPropImpl](../atl/reference/cstockpropimpl-class.md) implementa as propriedades de estoque com suporte ATL.

- [IPerPropertyBrowsingImpl](../atl/reference/iperpropertybrowsingimpl-class.md) acessa as informações nas páginas de propriedades de um objeto.

- [IPersistPropertyBagImpl](../atl/reference/ipersistpropertybagimpl-class.md) armazena propriedades de um objeto em um recipiente fornecido pelo cliente.

- [IPropertyPageImpl](../atl/reference/ipropertypageimpl-class.md) gerencia uma página de propriedade específica dentro de uma folha de propriedades.

- [IPropertyPage2Impl](../atl/reference/ipropertypage2impl-class.md) semelhante ao `IPropertyPageImpl`, mas também permite que um cliente selecionar uma propriedade específica em uma página de propriedades.

- [ISpecifyPropertyPagesImpl](../atl/reference/ispecifypropertypagesimpl-class.md) obtém os CLSIDs para as páginas de propriedades com suporte por um objeto.

## <a name="related-articles"></a>Artigos relacionados

[Tutorial da ATL](../atl/active-template-library-atl-tutorial.md)

[Página de propriedades COM da ATL](../atl/atl-com-property-pages.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../atl/atl-class-overview.md)<br/>
[Macros de mapa de propriedade](../atl/reference/property-map-macros.md)

