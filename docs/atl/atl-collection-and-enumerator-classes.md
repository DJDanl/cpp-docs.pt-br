---
title: ATL Classes de coleção e enumerador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- enumerators, ATL classes
- collection classes, ATL
ms.assetid: 6818db73-7094-48d8-a0ca-18147beec362
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a47525bb21b896b0fef8393cab66142ed40311ea
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="atl-collection-and-enumerator-classes"></a>Classes de enumerador e coleção ATL
ATL fornece as classes a seguir para ajudá-lo a implementar coleções e enumeradores.  
  
|Classe|Descrição|  
|-----------|-----------------|  
|[ICollectionOnSTLImpl](../atl/reference/icollectiononstlimpl-class.md)|Implementação de interface de coleção|  
|[IEnumOnSTLImpl](../atl/reference/ienumonstlimpl-class.md)|Implementação de interface de enumerador (supõe que os dados armazenados em um contêiner compatível de biblioteca padrão C++)|  
|[CComEnumImpl](../atl/reference/ccomenumimpl-class.md)|Implementação de interface de enumerador (supõe que os dados armazenados em uma matriz)|  
|[CComEnumOnSTL](../atl/reference/ccomenumonstl-class.md)|Implementação do objeto enumerador (usa `IEnumOnSTLImpl`)|  
|[CComEnum](../atl/reference/ccomenum-class.md)|Implementação do objeto enumerador (usa `CComEnumImpl`)|  
|[Copy](../atl/atl-copy-policy-classes.md)|Classe de política de cópia|  
|[_CopyInterface](../atl/atl-copy-policy-classes.md)|Classe de política de cópia|  
|[CAdapt](../atl/reference/cadapt-class.md)|Classe de adaptador (oculta **operador &** permitindo `CComPtr`, `CComQIPtr`, e `CComBSTR` a ser armazenado em contêineres de biblioteca padrão C++)|  
  
## <a name="see-also"></a>Consulte também  
 [Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)

