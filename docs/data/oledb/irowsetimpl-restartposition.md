---
title: 'Irowsetimpl:: RestartPosition | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.IRowsetImpl.RestartPosition
- IRowsetImpl::RestartPosition
- RestartPosition
- ATL::IRowsetImpl::RestartPosition
- IRowsetImpl.RestartPosition
dev_langs:
- C++
helpviewer_keywords:
- RestartPosition method
ms.assetid: 14de66ef-8d2c-4404-adb6-3f6c74ac6cf1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1c203cc19e31f22df5903f099e953fcf5663718f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="irowsetimplrestartposition"></a>IRowsetImpl::RestartPosition
Reposiciona a próxima posição de busca na sua posição inicial; ou seja, sua posição quando o conjunto de linhas foi inicialmente criado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(RestartPosition )(HCHAPTER /* hReserved */);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IRowset:: RestartPosition](https://msdn.microsoft.com/en-us/library/ms712877.aspx) no *referência do programador de OLE DB*.  
  
## <a name="remarks"></a>Comentários  
 A posição do conjunto de linhas é indefinida até **GetNextRow** é chamado. Você pode mover com versões anteriores em uma rowet chamando `RestartPosition` e, em seguida, rolagem ou busca com versões anteriores.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)