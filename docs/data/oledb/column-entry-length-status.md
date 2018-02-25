---
title: COLUMN_ENTRY_LENGTH_STATUS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COLUMN_ENTRY_LENGTH_STATUS
dev_langs:
- C++
helpviewer_keywords:
- COLUMN_ENTRY_LENGTH_STATUS macro
ms.assetid: 6069967c-4665-462b-b822-1e6c22b5bee1
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5c159e575def5cba5766b526d51c815589aed600
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="columnentrylengthstatus"></a>COLUMN_ENTRY_LENGTH_STATUS
Representa uma associação no conjunto de linhas para a coluna específica no banco de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
COLUMN_ENTRY_LENGTH_STATUS(nOrdinal, data, length, status)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx) no *referência do programador de OLE DB*.  
  
 `nOrdinal`  
 [in] O número da coluna.  
  
 `data`  
 [in] O membro de dados correspondente no registro do usuário.  
  
 *Comprimento*  
 [in] A variável a ser associado para o comprimento da coluna.  
  
 *status*  
 [in] A variável a ser associado ao status de coluna.  
  
## <a name="remarks"></a>Comentários  
 Use esta macro quando você deseja dar suporte a variáveis de comprimento e status. Ela é usada nos seguintes locais:  
  
-   Entre o [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md) e [END_COLUMN_MAP](../../data/oledb/end-column-map.md) macros.  
  
-   Entre o [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md) e [END_ACCESSOR](../../data/oledb/end-accessor.md) macros.  
  
-   Entre o [BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md) e [END_PARAM_MAP](../../data/oledb/end-param-map.md) macros.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md)   
 [BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md)   
 [BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md)   
 [COLUMN_ENTRY](../../data/oledb/column-entry.md)   
 [COLUMN_ENTRY_EX](../../data/oledb/column-entry-ex.md)   
 [COLUMN_ENTRY_LENGTH](../../data/oledb/column-entry-length.md)   
 [COLUMN_ENTRY_PS](../../data/oledb/column-entry-ps.md)   
 [COLUMN_ENTRY_PS_LENGTH](../../data/oledb/column-entry-ps-length.md)   
 [COLUMN_ENTRY_PS_LENGTH_STATUS](../../data/oledb/column-entry-ps-length-status.md)   
 [COLUMN_ENTRY_STATUS](../../data/oledb/column-entry-status.md)   
 [COLUMN_ENTRY_PS_STATUS](../../data/oledb/column-entry-ps-status.md)   
 [END_ACCESSOR](../../data/oledb/end-accessor.md)   
 [END_ACCESSOR_MAP](../../data/oledb/end-accessor-map.md)   
 [END_COLUMN_MAP](../../data/oledb/end-column-map.md)