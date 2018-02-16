---
title: IRowsetImpl::CreateRow | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4403388146b79eec4435374793b2517dd46ff188
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
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