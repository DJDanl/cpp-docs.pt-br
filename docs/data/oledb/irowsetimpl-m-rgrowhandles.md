---
title: 'Irowsetimpl:: M_rgrowhandles | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IRowsetImpl::m_rgRowHandles
- IRowsetImpl.m_rgRowHandles
- m_rgRowHandles
- ATL::IRowsetImpl::m_rgRowHandles
- ATL.IRowsetImpl.m_rgRowHandles
dev_langs:
- C++
helpviewer_keywords:
- m_rgRowHandles
ms.assetid: d3c2578f-58c4-4301-bf59-cf101a523a95
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b4eeeb9d048cd33513556d8b0585d1e84a0699a8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33101741"
---
# <a name="irowsetimplmrgrowhandles"></a>IRowsetImpl::m_rgRowHandles
Um mapa de identificadores de linha contidos no momento pelo provedor em resposta a `GetNextRows`.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
MapClass  
 m_rgRowHandles;  
  
```  
  
## <a name="remarks"></a>Comentários  
 Identificadores de linha são removidas chamando `ReleaseRows`. Consulte o [visão geral de IRowsetImpl](../../data/oledb/irowsetimpl-class.md) para a definição de *MapClass*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)