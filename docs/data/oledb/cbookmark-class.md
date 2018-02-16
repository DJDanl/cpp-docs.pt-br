---
title: Classe CBookmark | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 08ab7ca180433861be2dc9081dd991dbeb89642d
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
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