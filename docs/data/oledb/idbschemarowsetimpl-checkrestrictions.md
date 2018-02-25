---
title: 'Idbschemarowsetimpl:: Checkrestrictions | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CheckRestrictions
- IDBSchemaRowsetImpl::CheckRestrictions
- IDBSchemaRowsetImpl.CheckRestrictions
dev_langs:
- C++
helpviewer_keywords:
- CheckRestrictions method
ms.assetid: 3c9d77d2-0e4b-48fa-80db-d735da19f1cf
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 44e661bc782af4a162936caae7c8c1be06585647
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="idbschemarowsetimplcheckrestrictions"></a>IDBSchemaRowsetImpl::CheckRestrictions
Verifica a validade de restrições em relação a um conjunto de linhas de esquema.  
  
## <a name="syntax"></a>Sintaxe  
  
```
HRESULT CheckRestrictions(REFGUID rguidSchema,  
   ULONG cRestrictions,  const VARIANT rgRestrictions[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `rguidSchema`  
 [in] Uma referência para o GUID do conjunto de linhas de esquema solicitado (por exemplo, `DBSCHEMA_TABLES`).  
  
 `cRestrictions`  
 [in] O número de restrições que o consumidor passado para o conjunto de linhas de esquema.  
  
 `rgRestrictions`  
 [in] Uma matriz de comprimento *cRestrictions* de valores de restrição a ser definido. Para obter mais informações, consulte a descrição do `rgRestrictions` parâmetro em [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md).  
  
## <a name="remarks"></a>Comentários  
 Use `CheckRestrictions` para verificar a validade de restrições em relação a um conjunto de linhas de esquema. Ele verifica restrições para `DBSCHEMA_TABLES`, **DBSCHEMA_COLUMNS**, e **DBSCHEMA_PROVIDER_TYPES** conjuntos de linhas de esquema. Chamá-lo para determinar se um consumidor de chamada para **IDBSchemaRowset:: Getrowset** está correto. Se você desejar oferecer suporte a conjuntos de linhas de esquema diferente daqueles listados acima, você deve criar sua própria função para executar esta tarefa.  
  
 `CheckRestrictions` Determina se o consumidor está chamando [GetRowset](../../data/oledb/idbschemarowsetimpl-getrowset.md) com a restrição correta e o tipo de restrição correto (por exemplo, um `VT_BSTR` para uma cadeia de caracteres) que o provedor oferece suporte. Ele também determina se o número correto de restrições é suportado. Por padrão, `CheckRestrictions` pedirá que o provedor, por meio de [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md) chamar, que oferece suporte em um determinado conjunto de linhas de restrições. Ele então compara as restrições do consumidor com aquelas com suporte do provedor e o êxito ou falha.  
  
 Para obter mais informações sobre conjuntos de linhas de esquema, consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador de DB OLE* no SDK do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)   
 [Membros de classe IDBSchemaRowsetImpl](http://msdn.microsoft.com/en-us/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [Classes typedef e classes de conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)