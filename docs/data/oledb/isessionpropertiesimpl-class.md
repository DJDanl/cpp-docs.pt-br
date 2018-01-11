---
title: Classe ISessionPropertiesImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: ISessionPropertiesImpl
dev_langs: C++
helpviewer_keywords: ISessionPropertiesImpl class
ms.assetid: ca0ba254-c7dc-4c52-abec-cf895a0c6a63
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9ff8eda4d593ff0c6064313a7be243ec498b15c4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="isessionpropertiesimpl-class"></a>Classe ISessionPropertiesImpl
Fornece uma implementação de [ISessionProperties](https://msdn.microsoft.com/en-us/library/ms713721.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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