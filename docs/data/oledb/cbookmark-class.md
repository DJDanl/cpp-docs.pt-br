---
title: Classe CBookmark | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.CBookmark
- ATL::CBookmark<nSize>
- CBookmark
- ATL.CBookmark<nSize>
- ATL::CBookmark
dev_langs:
- C++
helpviewer_keywords:
- CBookmark class
ms.assetid: bc942f95-6f93-41d9-bb6e-bcdae4ae0b7a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c14fde6fb07a35ef9e2955ce61f991bede6b11a7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cbookmark-class"></a>Classe CBookmark
Contém um valor de indicador em seu buffer.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template < DBLENGTH nSize = 0 >  
class CBookmark : public CBookmarkBase
  
template <>  
class CBookmark< 0 > : public CBookmarkBase  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nSize`  
 O tamanho do buffer indicador em bytes. Quando `nSize` for zero, o buffer do indicador será criado dinamicamente em tempo de execução.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CBookmark](../../data/oledb/cbookmark-class.md)|O construtor|  
|[GetBuffer](../../data/oledb/cbookmark-getbuffer.md)|Recupera o ponteiro para o buffer.|  
|[GetSize](../../data/oledb/cbookmark-getsize.md)|Recupera o tamanho do buffer em bytes.|  
|[SetBookmark](../../data/oledb/cbookmark-setbookmark.md)|Define o valor do indicador.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](../../data/oledb/cbookmark-operator-equal.md)|Atribui um `CBookmark` classe para outro.|  
  
## <a name="remarks"></a>Comentários  
 **CBookmark\<0 >** é uma especialização de modelo de `CBookmark`; o buffer é criado dinamicamente em tempo de execução.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)