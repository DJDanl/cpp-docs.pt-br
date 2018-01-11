---
title: 'Irowsetimpl:: M_breset | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.IRowsetImpl.m_bReset
- IRowsetImpl.m_bReset
- m_bReset
- IRowsetImpl::m_bReset
- ATL::IRowsetImpl::m_bReset
dev_langs: C++
helpviewer_keywords: m_bReset
ms.assetid: d423f9f3-4d48-4d0c-b152-684c81a0b34e
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4cd9840b37157aed050bb71d48a275efd2849035
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="irowsetimplmbreset"></a>IRowsetImpl::m_bReset
Um sinalizador de bit usado para determinar se a posição do cursor é definida no conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
unsigned m_bReset:1;  
  
```  
  
## <a name="remarks"></a>Comentários  
 Se o consumidor chama [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md) com um resultado negativo `lOffset` ou *cRows* e `m_bReset` for true, `GetNextRows` move para o fim do conjunto de linhas. Se `m_bReset` for false, o consumidor recebe um código de erro, em conformidade com a especificação OLE DB. O `m_bReset` sinalizador é definido **true** quando o conjunto de linhas é criado pela primeira vez e quando o consumidor chama [irowsetimpl:: RestartPosition](../../data/oledb/irowsetimpl-restartposition.md). Ele é definido como **false** quando você chama `GetNextRows`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)