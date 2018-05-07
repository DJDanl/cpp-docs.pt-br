---
title: Classe CAccessorRowset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CAccessorRowset
- ATL.CAccessorRowset
- ATL::CAccessorRowset
dev_langs:
- C++
helpviewer_keywords:
- CAccessorRowset class
ms.assetid: bd4f58ed-cebf-4d43-8985-1e5fcbf06953
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 27d2153c6f600c3a5c75c1218e8751baaabcf030
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="caccessorrowset-class"></a>Classe CAccessorRowset
Encapsula um conjunto de linhas e de seus acessadores associados em uma única classe.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CNoAccessor, 
          template <typename T> class TRowset = CRowset>  
class CAccessorRowset : public TAccessor, public TRowset<TAccessor>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TAccessor`  
 Uma classe de acessador.  
  
 `TRowset`  
 Uma classe de conjunto de linhas.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Ligação](../../data/oledb/caccessorrowset-bind.md)|Cria associações (usado quando **bBind** é especificado como false na [ccommand:: Open](../../data/oledb/ccommand-open.md)).|  
|[CAccessorRowset](../../data/oledb/caccessorrowset-caccessorrowset.md)|Construtor.|  
|[Fechar](../../data/oledb/caccessorrowset-close.md)|Fecha o conjunto de linhas e qualquer acessadores.|  
|[FreeRecordMemory](../../data/oledb/caccessorrowset-freerecordmemory.md)|Libera as colunas no registro atual que precisam ser liberados.|  
|[GetColumnInfo](../../data/oledb/caccessorrowset-getcolumninfo.md)|Implementa [icolumnsinfo:: Getcolumninfo](https://msdn.microsoft.com/en-us/library/ms722704.aspx).|  
  
## <a name="remarks"></a>Comentários  
 Classe `TAccessor` gerencia o acessador. Classe *TRowset* gerencia o conjunto de linhas.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)