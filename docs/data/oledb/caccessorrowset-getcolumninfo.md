---
title: CAccessorRowset::GetColumnInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- GetColumnInfo
- CAccessorRowset.GetColumnInfo
- CAccessorRowset::GetColumnInfo
dev_langs:
- C++
helpviewer_keywords:
- GetColumnInfo method
ms.assetid: 8ade2388-3c58-43cd-8ed6-499ee0531291
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0c199712a270af8c73b49d33e1649de441e4077e
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="caccessorrowsetgetcolumninfo"></a>CAccessorRowset::GetColumnInfo
Obtém informações de coluna do conjunto de linhas aberto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetColumnInfo(DBORDINAL* pulColumns,  
   DBCOLUMNINFO** ppColumnInfo,  
   LPOLESTR* ppStrings) const;  

HRESULT GetColumnInfo(DBORDINAL* pColumns,  
   DBCOLUMNINFO** ppColumnInfo);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [icolumnsinfo:: Getcolumninfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx) no *referência do programador de OLE DB*.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 O usuário deve liberar o buffer de cadeia de caracteres e informações de coluna retornada. Use a segunda versão desse método quando você usar [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) e precisar substituir as associações.  
  
 Para obter mais informações, consulte [icolumnsinfo:: Getcolumninfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx) no *referência do programador de DB OLE*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAccessorRowset](../../data/oledb/caccessorrowset-class.md)