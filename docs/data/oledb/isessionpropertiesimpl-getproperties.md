---
title: 'Isessionpropertiesimpl:: GetProperties | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ISessionPropertiesImpl::GetProperties
- ISessionPropertiesImpl.GetProperties
- GetProperties
dev_langs:
- C++
helpviewer_keywords:
- GetProperties method
ms.assetid: 48726c2a-9599-4fc5-9940-a932faef91ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 99d42f74553af7d35f9853b21d334e648106401a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33102804"
---
# <a name="isessionpropertiesimplgetproperties"></a>ISessionPropertiesImpl::GetProperties
Retorna a lista de propriedades de **DBPROPSET_SESSION** grupo de propriedades que são definidas no momento na sessão.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(GetProperties)(ULONG cPropertyIDSets,   
   const DBPROPIDSET rgPropertyIDSets[],   
   ULONG * pcPropertySets,   
   DBPROPSET ** prgPropertySets);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [ISessionProperties::GetProperties](https://msdn.microsoft.com/en-us/library/ms723643.aspx) no *referência do programador de OLE DB*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe ISessionPropertiesImpl](../../data/oledb/isessionpropertiesimpl-class.md)   
 [ISessionPropertiesImpl::SetProperties](../../data/oledb/isessionpropertiesimpl-setproperties.md)