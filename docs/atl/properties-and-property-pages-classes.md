---
title: Propriedades e Classes de páginas de propriedade (ATL)
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- property pages, classes
- properties [ATL], classes
- properties [ATL]
ms.assetid: 31616f98-69f8-48b2-8d58-b8e7d1c2b2d8
ms.openlocfilehash: 05c3a67e278389bb2ab1b07e9d6cf63cbe347c63
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62249620"
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
