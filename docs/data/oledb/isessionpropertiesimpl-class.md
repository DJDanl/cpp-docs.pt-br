---
title: Classe ISessionPropertiesImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ISessionPropertiesImpl
dev_langs:
- C++
helpviewer_keywords:
- ISessionPropertiesImpl class
ms.assetid: ca0ba254-c7dc-4c52-abec-cf895a0c6a63
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: dd7dde152b2ca122deefd3b7e8d8de24a254519a
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="isessionpropertiesimpl-class"></a>Classe ISessionPropertiesImpl
Fornece uma implementação de [ISessionProperties](https://msdn.microsoft.com/en-us/library/ms713721.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class PropClass = T>  
class ATL_NO_VTABLE ISessionPropertiesImpl :  
   public ISessionProperties,    
   public CUtlProps<PropClass>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `ISessionPropertiesImpl`.  
  
 `PropClass`  
 Uma classe de propriedade definidos pelo usuário cujo padrão é `T`.  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetProperties](../../data/oledb/isessionpropertiesimpl-getproperties.md)|Retorna a lista de propriedades no grupo de propriedade de sessão que são definidas no momento na sessão.|  
|[SetProperties](../../data/oledb/isessionpropertiesimpl-setproperties.md)|Define as propriedades do grupo de propriedade de sessão.|  
  
## <a name="remarks"></a>Comentários  
 Uma interface obrigatória em sessões. Essa classe implementa as propriedades de sessão chamando uma função estática definida pelo [mapa de conjunto de propriedade](../../data/oledb/begin-propset-map.md). O mapeamento de conjunto de propriedade deve ser especificado em sua classe de sessão.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)