---
title: Classe CArrayRowset | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CArrayRowset<TAccessor>
- ATL.CArrayRowset
- CArrayRowset
- ATL::CArrayRowset
- ATL::CArrayRowset<TAccessor>
dev_langs:
- C++
helpviewer_keywords:
- CArrayRowset class
ms.assetid: 511427e1-73ca-4fd8-9ba1-ae9463557cb6
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 28d3a28f5c00cb0231738e8f02f07318bf156921
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="carrayrowset-class"></a>Classe CArrayRowset
Elementos de acessos de um conjunto de linhas usando a sintaxe de matriz.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template < class TAccessor >  
class CArrayRowset :   
   public CVirtualBuffer <TAccessor>,   
   protected CBulkRowset <TAccessor>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TAccessor`  
 O tipo de classe de acessador que você deseja usar o conjunto de linhas.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CArrayRowset](../../data/oledb/carrayrowset-carrayrowset.md)|Construtor.|  
|[Instantâneo](../../data/oledb/carrayrowset-snapshot.md)|Lê o conjunto de linhas inteiro na memória.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[Operador &#91; &#93;](../../data/oledb/carrayrowset-operator.md)|Acessa um elemento do conjunto de linhas.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[CArrayRowset::m_nRowsRead](../../data/oledb/carrayrowset-m-nrowsread.md)|O número de linhas já lidas.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CRowset](../../data/oledb/crowset-class.md)