---
title: Classe CDBPropIDSet | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDBPropIDSet
- ATL.CDBPropIDSet
- ATL::CDBPropIDSet
dev_langs: C++
helpviewer_keywords: CDBPropIDSet class
ms.assetid: 52bb806c-9581-494d-9af7-50d8a4834805
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 996e1a04e9870a9cd3cf02ca6a8c7c05a1dc3e56
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cdbpropidset-class"></a>Classe CDBPropIDSet
Herda o **DBPROPIDSET** estrutura e adiciona um construtor que inicializa os campos de chave, bem como a [AddPropertyID](../../data/oledb/cdbpropidset-addpropertyid.md) método de acesso.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDBPropIDSet : public tagDBPROPIDSET  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AddPropertyID](../../data/oledb/cdbpropidset-addpropertyid.md)|Adiciona uma propriedade para a propriedade ID definida.|  
|[CDBPropIDSet](../../data/oledb/cdbpropidset-cdbpropidset.md)|Construtor.|  
|[SetGUID](../../data/oledb/cdbpropidset-setguid.md)|Define o GUID da ID de propriedade do conjunto.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](../../data/oledb/cdbpropidset-operator-equal.md)|Atribui o conteúdo da ID de propriedade de um conjunto para outro.|  
  
## <a name="remarks"></a>Comentários  
 Uso de consumidores do OLE DB **DBPROPIDSET** estruturas para passar uma matriz de IDs de propriedade para a qual o consumidor deseja obter informações de propriedade. As propriedades identificadas em uma única [DBPROPIDSET](https://msdn.microsoft.com/en-us/library/ms717981.aspx) estrutura pertencem ao conjunto de uma propriedade.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)