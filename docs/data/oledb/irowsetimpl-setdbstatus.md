---
title: 'Irowsetimpl:: Setdbstatus | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IRowsetImpl.SetDBStatus
- IRowsetImpl::SetDBStatus
- SetDBStatus
dev_langs:
- C++
helpviewer_keywords:
- SetDBStatus method
ms.assetid: b73f526a-4fc6-4adb-9611-c3cca2cddb23
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7e6e07b6fe1a45a779c5ffe1e1afffaabdcb6d34
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33103896"
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