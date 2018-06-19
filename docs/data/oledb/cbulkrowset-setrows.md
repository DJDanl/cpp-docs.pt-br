---
title: CBulkRowset::SetRows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.CBulkRowset.SetRows
- CBulkRowset::SetRows
- CBulkRowset<TAccessor>.SetRows
- ATL.CBulkRowset<TAccessor>.SetRows
- CBulkRowset<TAccessor>::SetRows
- ATL::CBulkRowset<TAccessor>::SetRows
- ATL::CBulkRowset::SetRows
- CBulkRowset.SetRows
- SetRows
dev_langs:
- C++
helpviewer_keywords:
- SetRows method
ms.assetid: 7e92312a-bfd0-4c24-a799-62bef663f28e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1519c0113744bb3c1e03bec52d5504ce504ee719
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33096139"
---
# <a name="cbulkrowsetsetrows"></a>CBulkRowset::SetRows
Define o número de identificadores de linha recuperados por cada chamada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      void SetRows(DBROWCOUNT nRows) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nRows`  
 [in] O novo tamanho do conjunto de linhas (número de linhas).  
  
## <a name="remarks"></a>Comentários  
 Se você chamar esta função, ele deve ser antes que o conjunto de linhas é aberto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CBulkRowset](../../data/oledb/cbulkrowset-class.md)