---
title: "ATL Classes de coleção e enumerador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- enumerators, ATL classes
- collection classes, ATL
ms.assetid: 6818db73-7094-48d8-a0ca-18147beec362
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 5fe6a018668f40c632e0ff980499afb7e60de8ea
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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

