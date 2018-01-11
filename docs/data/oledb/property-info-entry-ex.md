---
title: PROPERTY_INFO_ENTRY_EX | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: PROPERTY_INFO_ENTRY_EX
dev_langs: C++
helpviewer_keywords: PROPERTY_INFO_ENTRY_EX macro
ms.assetid: af32dfcd-4c50-449d-af3b-48d21bd67a04
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0aae37cad8119133c468c1f635abca6ff69c5757
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="propertyinfoentryex"></a>PROPERTY_INFO_ENTRY_EX
Representa uma propriedade específica em um conjunto de propriedades.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
PROPERTY_INFO_ENTRY_EX(  
dwPropID  
, vt, dwFlags, value, options )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dwPropID*  
 [in] Um [DBPROPID](https://msdn.microsoft.com/en-us/library/ms723882.aspx) GUID para identificar uma propriedade do conjunto de valor que pode ser usado em conjunto com a propriedade.  
  
 *VT*  
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