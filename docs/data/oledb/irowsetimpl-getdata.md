---
title: IRowsetImpl::GetData | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.IRowsetImpl.GetData
- ATL::IRowsetImpl::GetData
- IRowsetImpl::GetData
- IRowsetImpl.GetData
dev_langs:
- C++
helpviewer_keywords:
- GetData method [OLE DB]
ms.assetid: cb15f1cc-bd25-4b74-93c3-db71aa93829c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3e2a20e8f1948078aec6994516e05f83e95cdcc1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="irowsetimplgetdata"></a>IRowsetImpl::GetData
Recupera dados da cópia do conjunto de linhas da linha.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(GetData )(HROW hRow,  
   HACCESSOR hAccessor,  
   void* pDstData);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IRowset:: GetData](https://msdn.microsoft.com/en-us/library/ms716988.aspx) no *referência do programador de OLE DB*.  
  
 Alguns parâmetros correspondem a *referência do programador de DB OLE* parâmetros de nomes diferentes, que são descritos em **IRowset:: GetData**:  
  
|Parâmetros de modelo de banco de dados OLE|*Referência do programador DB OLE* parâmetros|  
|--------------------------------|------------------------------------------------|  
|*pDstData*|`pData`|  
  
## <a name="remarks"></a>Comentários  
 Também lida com a conversão de dados usando a DLL de conversão de dados OLE DB.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)