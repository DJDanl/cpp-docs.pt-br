---
title: 'Idbschemarowsetimpl:: Setrestrictions | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IDBSchemaRowsetImpl::SetRestrictions
- SetRestrictions
- IDBSchemaRowsetImpl.SetRestrictions
dev_langs:
- C++
helpviewer_keywords:
- SetRestrictions method
ms.assetid: 707d5065-b853-4d38-9b67-3066b4d3b279
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f3ac45e93e0a2561bd8ab24dc7c0c6b19b245b60
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="idbschemarowsetimplsetrestrictions"></a>IDBSchemaRowsetImpl::SetRestrictions
Especifica as restrições de suporte em um conjunto de linhas de esquema específico.  
  
## <a name="syntax"></a>Sintaxe  
  
```
void SetRestrictions(ULONG cRestrictions,  
  GUID* /* rguidSchema */,  
   ULONG* rgRestrictions);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `cRestrictions`  
 [in] O número de restrições a `rgRestrictions` matriz e o número de GUIDs de `rguidSchema` matriz.  
  
 `rguidSchema`  
 [in] Uma matriz de GUIDs de conjuntos de linhas de esquema para o qual buscar restrições. Cada elemento da matriz contém o GUID do conjunto de linhas de um esquema (por exemplo, `DBSCHEMA_TABLES`).  
  
 `rgRestrictions`  
 [in] Uma matriz de comprimento `cRestrictions` dos valores de restrição a ser definido. Cada elemento corresponde às restrições no conjunto de linhas de esquema identificado pelo GUID. Se o provedor não dá suporte a um conjunto de linhas de esquema, o elemento é definido como zero. Caso contrário, o **ULONG** valor contém uma máscara de bits que representa as restrições de suporte nesse conjunto de linhas de esquema. Para obter mais informações no qual restrições correspondem a um conjunto de linhas de esquema específico, consulte a tabela de linhas de esquema GUIDs em [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador de DB OLE* no Windows SDK.  
  
## <a name="remarks"></a>Comentários  
 O **IDBSchemaRowset** objeto chamadas `SetRestrictions` para determinar quais restrições de suporte em um conjunto de linhas de esquema específico (ele é chamado [GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md) por meio de um ponteiro upcasted). Restrições permitem que os consumidores de busca somente as linhas correspondentes (por exemplo, localize todas as colunas na tabela "MyTable"). Restrições são opcionais e, no caso em que nenhum têm suporte (o padrão), todos os dados sempre é retornado.  
  
 A implementação padrão desse método define o `rgRestrictions` matriz elementos como 0. Substitua o padrão em sua classe de sessão para definir restrições que não seja o padrão.  
  
 Para obter informações sobre a implementação de suporte de conjunto de linhas de esquema, consulte [dando suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md).  
  
 Para obter um exemplo de um provedor que dá suporte a conjuntos de linhas de esquema, consulte o [UpdatePV](../../visual-cpp-samples.md) exemplo.  
  
 Para obter mais informações sobre conjuntos de linhas de esquema, consulte [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no *referência do programador de DB OLE* no SDK do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)   
 [Membros de classe IDBSchemaRowsetImpl](http://msdn.microsoft.com/en-us/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)   
 [Suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md)   
 [UpdatePV](../../visual-cpp-samples.md)