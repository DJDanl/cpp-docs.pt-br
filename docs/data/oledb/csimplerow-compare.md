---
title: 'Csimplerow:: Compare | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CSimpleRow.Compare
- CSimpleRow::Compare
dev_langs:
- C++
helpviewer_keywords:
- Compare method
ms.assetid: 0bb65f09-c7bc-449b-aa4e-c828cac13510
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 75d79e753f1f4af630c26ef07fbb7241576535ce
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33098959"
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