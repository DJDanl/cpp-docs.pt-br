---
title: Classe CTable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::CTable
- ATL.CTable
- CTable
dev_langs:
- C++
helpviewer_keywords:
- CTable class
ms.assetid: f13fdaa3-e198-4557-977d-54b0bbc3454d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e12ec9f7cc7db4da78df8f3b49ed4fdadef3f769
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33100139"
---
# <a name="ctable-class"></a>Classe CTable
Fornece um meio para acessar diretamente um conjunto de linhas simple (um sem parâmetros).  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CNoAccessor, 
            template <typename T> class TRowset = CRowset>  
class CTable :  
   public CAccessorRowset <TAccessor, TRowset>  
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
|[Abrir](../../data/oledb/ctable-open.md)|Abre a tabela.|  
  
## <a name="remarks"></a>Comentários  
 Consulte [CCommand](../../data/oledb/ccommand-class.md) para obter informações sobre como executar um comando para acessar um conjunto de linhas.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [IOpenRowset::OpenRowset](https://msdn.microsoft.com/en-us/library/ms716724.aspx)