---
title: Classe IDBPropertiesImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IDBPropertiesImpl
- ATL.IDBPropertiesImpl
- ATL.IDBPropertiesImpl<T>
- ATL::IDBPropertiesImpl<T>
- ATL::IDBPropertiesImpl
dev_langs:
- C++
helpviewer_keywords:
- IDBPropertiesImpl class
ms.assetid: a7f15a8b-95b2-4316-b944-d5d03f8d74ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3685e6a77e4293ef65b5ee98a0aa326500cfdb2d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33105118"
---
# <a name="idbpropertiesimpl-class"></a>Classe IDBPropertiesImpl
Fornece uma implementação para o `IDBProperties` interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T>   
class ATL_NO_VTABLE IDBPropertiesImpl   
   : public IDBProperties, public CUtlProps<T>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IDBPropertiesImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetProperties](../../data/oledb/idbpropertiesimpl-getproperties.md)|Retorna os valores das propriedades dos grupos de propriedade de inicialização de fonte de dados e informações de fonte de dados que estão atualmente definidas no objeto de fonte de dados ou os valores das propriedades do grupo de propriedade de inicialização que estão atualmente definidas do enumerador.|  
|[GetPropertyInfo](../../data/oledb/idbpropertiesimpl-getpropertyinfo.md)|Retorna informações sobre todas as propriedades com suporte pelo provedor.|  
|[SetProperties](../../data/oledb/idbpropertiesimpl-setproperties.md)|Define propriedades em grupos de propriedade fonte de dados e de inicialização, para objetos de fonte de dados, ou o grupo de propriedades de inicialização para enumeradores.|  
  
## <a name="remarks"></a>Comentários  
 [IDBProperties](https://msdn.microsoft.com/en-us/library/ms719607.aspx) é uma interface obrigatória para objetos de fonte de dados e uma interface opcional de enumeradores. No entanto, se expõe um enumerador [IDBInitialize](https://msdn.microsoft.com/en-us/library/ms713706.aspx), ele deve expor `IDBProperties`. `IDBPropertiesImpl` implementa `IDBProperties` usando uma função estática definida pelo [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)