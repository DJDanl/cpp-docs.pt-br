---
title: 'Irowsetimpl:: Createrow | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IRowsetImpl.CreateRow
- ATL.IRowsetImpl.CreateRow
- ATL::IRowsetImpl::CreateRow
- CreateRow
- IRowsetImpl::CreateRow
dev_langs:
- C++
helpviewer_keywords:
- CreateRow method
ms.assetid: b01c430c-9484-4fef-a6cf-a2e8d9d99130
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: eae3fbdce1db5760d4ee5ca75e007c01e98b7bed
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="irowsetimplcreaterow"></a>IRowsetImpl::CreateRow
Um método auxiliar chamado pelo [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md) para alocar um novo **HROW**.  
  
## <a name="syntax"></a>Sintaxe  
  
```
HRESULT CreateRow(DBROWOFFSET lRowsOffset,  
  DBCOUNTITEM& cRowsObtained,  
   HROW* rgRows);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *lRowsOffset*  
 Posição do cursor da linha que está sendo criada.  
  
 *cRowsObtained*  
 Uma referência é passada para o usuário que indica o número de linhas criado.  
  
 *rgRows*  
 Uma matriz de **HROW**s retornado ao chamador com as alças de linha criada recentemente.  
  
## <a name="remarks"></a>Comentários  
 Se a linha existir, este método chama [AddRefRows](../../data/oledb/irowsetimpl-addrefrows.md) e retorna. Caso contrário, ele aloca uma nova instância da variável de modelo RowClass e adiciona-o a [m_rgRowHandles](../../data/oledb/irowsetimpl-m-rgrowhandles.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)