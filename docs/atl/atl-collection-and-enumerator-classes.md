---
title: ATL Classes de coleção e enumerador
ms.date: 11/04/2016
helpviewer_keywords:
- enumerators, ATL classes
- collection classes, ATL
ms.assetid: 6818db73-7094-48d8-a0ca-18147beec362
ms.openlocfilehash: b1ab9a160b01ea278d162a515e5121054bf398f7
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57265399"
---
# <a name="atl-collection-and-enumerator-classes"></a>ATL Classes de coleção e enumerador

ATL fornece as classes a seguir para ajudá-lo a implementar coleções e enumeradores.

|Classe|Descrição|
|-----------|-----------------|
|[ICollectionOnSTLImpl](../atl/reference/icollectiononstlimpl-class.md)|Implementação de interface de coleção|
|[IEnumOnSTLImpl](../atl/reference/ienumonstlimpl-class.md)|Implementação de interface de enumerador (supõe que os dados armazenados em um contêiner compatível de biblioteca padrão C++)|
|[CComEnumImpl](../atl/reference/ccomenumimpl-class.md)|Implementação de interface de enumerador (supõe que os dados armazenados em uma matriz)|
|[CComEnumOnSTL](../atl/reference/ccomenumonstl-class.md)|Implementação do objeto enumerador (usa `IEnumOnSTLImpl`)|
|[CComEnum](../atl/reference/ccomenum-class.md)|Implementação do objeto enumerador (usa `CComEnumImpl`)|
|[_Copy](../atl/atl-copy-policy-classes.md)|Classe de política de cópia|
|[_CopyInterface](../atl/atl-copy-policy-classes.md)|Classe de política de cópia|
|[CAdapt](../atl/reference/cadapt-class.md)|Classe de adaptador (oculta **operador &** permitindo `CComPtr`, `CComQIPtr`, e `CComBSTR` sejam armazenados em contêineres da biblioteca padrão C++)|

## <a name="see-also"></a>Consulte também

[Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)
