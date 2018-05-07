---
title: PROPERTY_INFO_ENTRY_EX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- PROPERTY_INFO_ENTRY_EX
dev_langs:
- C++
helpviewer_keywords:
- PROPERTY_INFO_ENTRY_EX macro
ms.assetid: af32dfcd-4c50-449d-af3b-48d21bd67a04
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 186c30584c5c5844614994700bf2a7958a73ce2d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="propertyinfoentryex"></a>PROPERTY_INFO_ENTRY_EX
Representa uma propriedade específica em um conjunto de propriedades.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
PROPERTY_INFO_ENTRY_EX(dwPropID  
, vt, dwFlags, value, options )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dwPropID*  
 [in] Um [DBPROPID](https://msdn.microsoft.com/en-us/library/ms723882.aspx) GUID para identificar uma propriedade do conjunto de valor que pode ser usado em conjunto com a propriedade.  
  
 *vt*  
 [in] O [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4) desta entrada de propriedade.  
  
 `dwFlags`  
 [in] Um [DBPROPFLAGS](https://msdn.microsoft.com/en-us/library/ms724342.aspx) valor que descreve esta entrada de propriedade.  
  
 *value*  
 [in] O valor da propriedade do tipo `DWORD`.  
  
 `options`  
 O **DBPROPOPTIONS_REQUIRED** ou **DBPROPOPTIONS_SETIFCHEAP**. Normalmente, um provedor não precisa definir `options` desde que ele é definido pelo consumidor.  
  
## <a name="remarks"></a>Comentários  
 Com essa macro, você pode especificar diretamente o valor da propriedade do tipo `DWORD` , bem como opções e sinalizadores. Para definir apenas uma propriedade para um valor padrão definido em ATLDB. H, use [PROPERTY_INFO_ENTRY](../../data/oledb/property-info-entry.md). Para definir uma propriedade para um valor de sua escolha, sem opções de configuração ou sinalizadores, use [PROPERTY_INFO_ENTRY_VALUE](../../data/oledb/property-info-entry-value.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros para modelos de provedor do OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)