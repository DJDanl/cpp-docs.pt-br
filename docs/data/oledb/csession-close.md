---
title: 'Csession:: Close | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CSession::Close
- ATL.CSession.Close
- CSession.Close
- ATL::CSession::Close
dev_langs:
- C++
helpviewer_keywords:
- Close method
ms.assetid: dc36c4c0-e588-4c0b-91d1-fc7dc5c8e7f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c8c40ba6b291ed17f4af772cd438756ea868f174
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="csessionclose"></a>CSession::Close
Fecha a sessão, que foi aberta por [csession:: Open](../../data/oledb/csession-open.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
void Close() throw();  
  
```  
  
## <a name="remarks"></a>Comentários  
 Versões de **m_spOpenRowset** ponteiro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSession](../../data/oledb/csession-class.md)