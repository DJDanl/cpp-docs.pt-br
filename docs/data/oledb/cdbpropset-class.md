---
title: Classe CDBPropSet | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDBPropSet
- ATL.CDBPropSet
- ATL::CDBPropSet
dev_langs:
- C++
helpviewer_keywords:
- CDBPropSet class
ms.assetid: 54190149-c277-4679-b81a-ef484d4d1c00
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8d75715ed0dc65fbbf5b581bfea48816e5bd00ce
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cdbpropset-class"></a>Classe CDBPropSet
Herda o **DBPROPSET** estrutura e adiciona um construtor que inicializa os campos de chave, bem como a `AddProperty` método de acesso.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class CDBPropSet : public tagDBPROPSET  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AddProperty](../../data/oledb/cdbpropset-addproperty.md)|Adiciona uma propriedade para o conjunto de propriedades.|  
|[CDBPropSet](../../data/oledb/cdbpropset-cdbpropset.md)|Construtor.|  
|[SetGUID](../../data/oledb/cdbpropset-setguid.md)|Conjuntos de **guidPropertySet** campo o **DBPROPSET** estrutura.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](../../data/oledb/cdbpropset-operator-equal.md)|Atribui o conteúdo de uma propriedade definida para outro.|  
  
## <a name="remarks"></a>Comentários  
 Uso de provedores e consumidores de OLE DB **DBPROPSET** estruturas para transmitir matrizes de `DBPROP` estruturas. Cada `DBPROP` estrutura representa uma única propriedade que pode ser definida.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CDBPropIDSet](../../data/oledb/cdbpropidset-class.md)   
 [Estrutura DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx)   
 [Estrutura DBPROP](https://msdn.microsoft.com/en-us/library/ms717970.aspx)