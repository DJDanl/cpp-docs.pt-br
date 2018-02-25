---
title: CSimpleRow::Compare | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSimpleRow.Compare
- CSimpleRow::Compare
dev_langs:
- C++
helpviewer_keywords:
- Compare method
ms.assetid: 0bb65f09-c7bc-449b-aa4e-c828cac13510
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2649fcf708abaf9e971490d3e88a746c264b1009
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="csimplerowcompare"></a>CSimpleRow::Compare
Compara duas linhas para ver se elas se referem à mesma instância de linha.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Compare(CSimpleRow* pRow);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pRow`  
 Um ponteiro para um `CSimpleRow` objeto.  
  
## <a name="return-value"></a>Valor de retorno  
 Um `HRESULT` valor, normalmente `S_OK`, indicando que as duas linhas são a mesma instância de linha, ou **S_FALSE**, indicando que as duas linhas são diferentes. Consulte [IRowsetIdentity::IsSameRow](https://msdn.microsoft.com/en-us/library/ms719629.aspx) no *referência do programador DB OLE* outros possíveis valores de retorno.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSimpleRow](../../data/oledb/csimplerow-class.md)   
 [CSimpleRow::ReleaseRow](../../data/oledb/csimplerow-releaserow.md)   
 [IRowsetImpl::RefRows](../../data/oledb/irowsetimpl-refrows.md)