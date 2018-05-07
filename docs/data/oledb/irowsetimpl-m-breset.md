---
title: IRowsetImpl::m_bReset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.IRowsetImpl.m_bReset
- IRowsetImpl.m_bReset
- m_bReset
- IRowsetImpl::m_bReset
- ATL::IRowsetImpl::m_bReset
dev_langs:
- C++
helpviewer_keywords:
- m_bReset
ms.assetid: d423f9f3-4d48-4d0c-b152-684c81a0b34e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a9aec38e3cf7e9a58c4fe99d06f35ae55cfdf81c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="irowsetimplmbreset"></a>IRowsetImpl::m_bReset
Um sinalizador de bit usado para determinar se a posição do cursor é definida no conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
unsigned m_bReset:1;  
  
```  
  
## <a name="remarks"></a>Comentários  
 Se o consumidor chama [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md) com um resultado negativo `lOffset` ou *cRows* e `m_bReset` for true, `GetNextRows` move para o fim do conjunto de linhas. Se `m_bReset` for false, o consumidor recebe um código de erro, em conformidade com a especificação OLE DB. O `m_bReset` sinalizador é definido **true** quando o conjunto de linhas é criado pela primeira vez e quando o consumidor chama [irowsetimpl:: RestartPosition](../../data/oledb/irowsetimpl-restartposition.md). Ele é definido como **false** quando você chama `GetNextRows`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)