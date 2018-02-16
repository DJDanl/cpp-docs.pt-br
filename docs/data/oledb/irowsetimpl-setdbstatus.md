---
title: IRowsetImpl::SetDBStatus | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IRowsetImpl.SetDBStatus
- IRowsetImpl::SetDBStatus
- SetDBStatus
dev_langs:
- C++
helpviewer_keywords:
- SetDBStatus method
ms.assetid: b73f526a-4fc6-4adb-9611-c3cca2cddb23
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0448e6e72fcfe760b6ed01fa2b1e40a85c9d08f5
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="irowsetimplsetdbstatus"></a>IRowsetImpl::SetDBStatus
Conjuntos de `DBSTATUS` sinalizadores de status para o campo especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      virtual HRESULT SetDBStatus(DBSTATUS* statusFlags,  
   RowClass* currentRow,  
   ATLCOLUMNINFO* columnInfo);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `statusFlags`  
 O [DBSTATUS](https://msdn.microsoft.com/en-us/library/ms722617.aspx) sinalizadores para definir para a coluna.  
  
 `currentRow`  
 A linha atual.  
  
 *columnInfo*  
 A coluna status para o qual está sendo definido.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
## <a name="remarks"></a>Comentários  
 O provedor substitui essa função para fornecer processamento especial para **DBSTATUS_S_ISNULL** e **DBSTATUS_S_DEFAULT**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)