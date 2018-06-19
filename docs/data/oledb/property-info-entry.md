---
title: PROPERTY_INFO_ENTRY | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- PROPERTY_INFO_ENTRY
dev_langs:
- C++
helpviewer_keywords:
- PROPERTY_INFO_ENTRY macro
ms.assetid: f7bd23d6-52b4-4d6a-aa9a-1fca9834c8dc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2603d3257edad6e90357c425a8b5aef60af611dc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33105186"
---
# <a name="propertyinfoentry"></a>PROPERTY_INFO_ENTRY
Representa uma propriedade específica em um conjunto de propriedades.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
PROPERTY_INFO_ENTRY(dwPropID)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dwPropID*  
 [in] Um [DBPROPID](https://msdn.microsoft.com/en-us/library/ms723882.aspx) GUID para identificar uma propriedade do conjunto de valor que pode ser usado em conjunto com a propriedade.  
  
## <a name="remarks"></a>Comentários  
 Esta macro define o valor da propriedade do tipo `DWORD` para um valor padrão definido em ATLDB. H. Para definir a propriedade para um valor de sua escolha, use [PROPERTY_INFO_ENTRY_VALUE](../../data/oledb/property-info-entry-value.md). Para definir o [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4) e [DBPROPFLAGS](https://msdn.microsoft.com/en-us/library/ms724342.aspx) para a propriedade ao mesmo tempo, use [PROPERTY_INFO_ENTRY_EX](../../data/oledb/property-info-entry-ex.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros para modelos de provedor do OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)