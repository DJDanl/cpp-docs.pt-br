---
title: Classe ISessionPropertiesImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ISessionPropertiesImpl
dev_langs:
- C++
helpviewer_keywords:
- ISessionPropertiesImpl class
ms.assetid: ca0ba254-c7dc-4c52-abec-cf895a0c6a63
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 62b1321c9d7d50ff2cd459b395efa1e8147a06ea
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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