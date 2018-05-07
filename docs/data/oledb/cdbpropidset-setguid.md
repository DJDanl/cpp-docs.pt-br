---
title: CDBPropIDSet::SetGUID | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDBPropIDSet.SetGUID
- ATL::CDBPropIDSet::SetGUID
- SetGUID
- ATL.CDBPropIDSet.SetGUID
- CDBPropIDSet::SetGUID
dev_langs:
- C++
helpviewer_keywords:
- SetGUID method
ms.assetid: 8dd0f3bf-1490-4d53-9063-322b8d821bbe
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 87878b6cc7ae38f2c9ffcf597a56ab020d8e9c8b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cdbpropidsetsetguid"></a>CDBPropIDSet::SetGUID
Define o campo GUID no **DBPROPIDSET** estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      void SetGUID(const GUID& guid) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `guid`  
 [in] Um GUID usado para definir o **guidPropertySet** campo o [DBPROPIDSET](https://msdn.microsoft.com/en-us/library/ms717981.aspx) estrutura.  
  
## <a name="remarks"></a>Comentários  
 Este campo pode ser definido pelo [construtor](../../data/oledb/cdbpropidset-cdbpropidset.md) também. Chame essa função se você usar o construtor padrão para esta classe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDBPropIDSet](../../data/oledb/cdbpropidset-class.md)