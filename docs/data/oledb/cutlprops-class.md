---
title: Classe CUtlProps | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CUtlProps
dev_langs: C++
helpviewer_keywords: CUtlProps class
ms.assetid: bb525178-765c-4e23-a110-c0fd70c05437
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 75e92f48729d0aae9f85cc7b7c5c97e4778f96a7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cutlprops-class"></a>Classe CUtlProps
Implementa propriedades para uma variedade de interfaces de propriedade do banco de dados OLE (por exemplo, `IDBProperties`, `IDBProperties`, e `IRowsetInfo`).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template < class T >  
class ATL_NO_VTABLE CUtlProps : public CUtlPropsBase  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe que contém o `BEGIN_PROPSET_MAP`.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[GetPropValue](../../data/oledb/cutlprops-getpropvalue.md)|Obtém uma propriedade de um conjunto de propriedades.|  
|[IsValidValue](../../data/oledb/cutlprops-isvalidvalue.md)|Usado para validar um valor antes de definir uma propriedade.|  
|[OnInterfaceRequested](../../data/oledb/cutlprops-oninterfacerequested.md)|Trata solicitações para uma interface opcional quando um consumidor chama um método em uma interface de criação de objeto.|  
|[OnPropertyChanged](../../data/oledb/cutlprops-onpropertychanged.md)|Chamado depois de definir uma propriedade para manipular propriedades encadeadas.|  
|[SetPropValue](../../data/oledb/cutlprops-setpropvalue.md)|Define uma propriedade em um conjunto de propriedades.|  
  
## <a name="remarks"></a>Comentários  
 A maioria dessa classe é um detalhe de implementação.  
  
 `CUtlProps`contém dois membros para definir as propriedades internamente: [GetPropValue](../../data/oledb/cutlprops-getpropvalue.md) e [SetPropValue](../../data/oledb/cutlprops-setpropvalue.md).  
  
 Para obter mais informações sobre as macros usado em um mapa de conjunto de propriedade, consulte [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md) e [END_PROPSET_MAP](../../data/oledb/end-propset-map.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)