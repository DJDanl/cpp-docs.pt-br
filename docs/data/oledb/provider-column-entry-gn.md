---
title: PROVIDER_COLUMN_ENTRY_GN | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- PROVIDER_COLUMN_ENTRY_GN
dev_langs:
- C++
helpviewer_keywords:
- PROVIDER_COLUMN_ENTRY_GN macro
ms.assetid: be77ba85-634c-4e28-832f-d2fa40413254
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: be0cfa80b0d2a18d04dd329feda6547b5d89e6e1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33109970"
---
# <a name="providercolumnentrygn"></a>PROVIDER_COLUMN_ENTRY_GN
Representa uma coluna específica suportada pelo provedor.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
PROVIDER_COLUMN_ENTRY_GN (name  
, ordinal, flags, colSize, dbtype, precision, scale, guid )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 [in] O nome da coluna.  
  
 `ordinal`  
 [in] O número da coluna. A menos que a coluna é uma coluna de indicador, o número da coluna não deve ser 0.  
  
 `flags`  
 [in] Especifica como os dados são retornados. Consulte o `dwFlags` descrição em [estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx).  
  
 *colSize*  
 [in] O tamanho da coluna.  
  
 `dbtype`  
 [in] Indica o tipo de dados do valor. Consulte o **wType** descrição em [estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx).  
  
 *precision*  
 [in] Indica a precisão para usar ao obter dados se *dbType* é `DBTYPE_NUMERIC` ou **DBTYPE_DECIMAL**. Consulte o **bPrecision** descrição em [estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx).  
  
 `scale`  
 [in] Indica a escala a ser usado ao obter dados se for dbType `DBTYPE_NUMERIC` ou **DBTYPE_DECIMAL**. Consulte o **bScale** descrição em [estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx).  
  
 `guid`  
 Um conjunto de linhas do esquema GUID. Consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador de DB OLE* para obter uma lista de conjuntos de linhas de esquema e seus GUIDs.  
  
## <a name="remarks"></a>Comentários  
 Permite que você especifique o tamanho da coluna, tipo de dados, precisão, escala e linhas de esquema GUID.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros para modelos de provedor do OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)