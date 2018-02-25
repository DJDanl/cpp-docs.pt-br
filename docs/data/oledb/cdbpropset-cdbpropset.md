---
title: CDBPropSet::CDBPropSet | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDBPropSet.CDBPropSet
- CDBPropSet::CDBPropSet
- ATL::CDBPropSet::CDBPropSet
- ATL.CDBPropSet.CDBPropSet
dev_langs:
- C++
helpviewer_keywords:
- CDBPropSet class, constructor
ms.assetid: 02ae5d9e-c067-47ca-8111-a03e86b5626b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: db118c9c814d957c43f11414ee583a2ccc7a416b
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdbpropsetcdbpropset"></a>CDBPropSet::CDBPropSet
O construtor. Inicializa o **rgProperties**, **cProperties**, e **guidPropertySet** campos do [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      CDBPropSet(const GUID& guid);  

CDBPropSet(const CDBPropSet& propset);  

CDBPropSet();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `guid`  
 [in] Um GUID usado para inicializar o **guidPropertySet** campo.  
  
 *propset*  
 [in] Outro `CDBPropSet` objeto para a construção de cópia.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDBPropSet](../../data/oledb/cdbpropset-class.md)   
 [CDBPropSet::SetGUID](../../data/oledb/cdbpropset-setguid.md)   
 [Estrutura DBPROP](https://msdn.microsoft.com/en-us/library/ms717970.aspx)