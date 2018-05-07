---
title: CDBPropSet::SetGUID | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.CDBPropSet.SetGUID
- CDBPropSet.SetGUID
- ATL::CDBPropSet::SetGUID
- SetGUID
- CDBPropSet::SetGUID
dev_langs:
- C++
helpviewer_keywords:
- SetGUID method
- AddProperty method
ms.assetid: a4cce036-cf1f-4897-9712-7b01eaf887ff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 140bc76968780efff826ccc42343f27b2cd2eae6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cdbpropsetsetguid"></a>CDBPropSet::SetGUID
Conjuntos de **guidPropertySet** campo o **DBPROPSET** estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      void SetGUID(const GUID& guid) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `guid`  
 [in] Um GUID usado para definir o **guidPropertySet** campo o [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estrutura.  
  
## <a name="remarks"></a>Comentários  
 Este campo pode ser definido pelo [construtor](../../data/oledb/cdbpropset-cdbpropset.md) também.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDBPropSet](../../data/oledb/cdbpropset-class.md)