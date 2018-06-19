---
title: CRowset::CRowset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CRowset<TAccessor>::CRowset
- CRowset.CRowset
- ATL::CRowset::CRowset
- ATL::CRowset<TAccessor>::CRowset
- ATL.CRowset.CRowset
- CRowset
- CRowset<TAccessor>.CRowset
- CRowset::CRowset
- ATL.CRowset<TAccessor>.CRowset
dev_langs:
- C++
helpviewer_keywords:
- CRowset class, constructor
ms.assetid: 1c6f72e2-f4f4-48dc-957e-038ae8914ba7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c1ac78caaf82dc42a5e4d4afdab7e03bad53c5f0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33098375"
---
# <a name="crowsetcrowset"></a>CRowset::CRowset
Cria um novo `CRowset` de objeto e (opcionalmente) associa-o com um [IRowset](https://msdn.microsoft.com/en-us/library/ms720986.aspx) interface fornecida como um parâmetro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      CRowset();   

CRowset(IRowset* pRowset);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pRowset`  
 [in] Um ponteiro para um `IRowset` interface a ser associado essa classe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowset](../../data/oledb/crowset-class.md)