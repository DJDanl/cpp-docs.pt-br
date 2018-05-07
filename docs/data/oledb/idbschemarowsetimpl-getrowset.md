---
title: IDBSchemaRowsetImpl::GetRowset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::IDBSchemaRowsetImpl::GetRowset
- ATL.IDBSchemaRowsetImpl.GetRowset
- IDBSchemaRowsetImpl<SessionClass>::GetRowset
- IDBSchemaRowsetImpl.GetRowset
- IDBSchemaRowsetImpl::GetRowset
- ATL::IDBSchemaRowsetImpl<SessionClass>::GetRowset
- GetRowset
dev_langs:
- C++
helpviewer_keywords:
- GetRowset method
ms.assetid: 3ae28c22-e186-4a15-8591-b0192e784a6f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4ec479809bf95d4a88338401013b7f5980b703d8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="idbschemarowsetimplgetrowset"></a>IDBSchemaRowsetImpl::GetRowset
Retorna um conjunto de linhas de esquema.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD (GetRowset)(IUnknown *pUnkOuter,  
   REFGUID rguidSchema,  
   ULONG cRestrictions,  
   const VARIANT rgRestrictions[],  
   REFIID riid,  
   ULONG cPropertySets,  
   DBPROPSET rgPropertySets[],  
   IUnknown **ppRowset);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pUnkOuter`  
 [in] Um externa **IUnknown** quando agregação; caso contrário **nulo**.  
  
 `rguidSchema`  
 [in] Uma referência para o GUID do conjunto de linhas de esquema solicitado (por exemplo, `DBSCHEMA_TABLES`).  
  
 `cRestrictions`  
 [in] Uma contagem de restrições a serem aplicadas ao conjunto de linhas.  
  
 `rgRestrictions`  
 [in] Uma matriz de `cRestrictions` **VARIANT**s que representam as restrições.  
  
 `riid`  
 [in] O IID para solicitação de linhas do esquema recém-criado.  
  
 `cPropertySets`  
 [in] Define o número de propriedade para definir.  
  
 `rgPropertySets`  
 [entrada/saída] Uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas para definir no conjunto de linhas de esquema recém-criado.  
  
 `ppRowset`  
 [out] Um ponteiro para a interface solicitada no conjunto de linhas de esquema recém-criado.  
  
## <a name="remarks"></a>Comentários  
 Esse método requer que o usuário tenha um esquema do mapa na classe de sessão. Usando as informações de mapa de esquema, `GetRowset` cria um objeto de determinado conjunto de linhas se o `rguidSchema` parâmetro for igual a uma das entradas de mapa GUIDs. Consulte [SCHEMA_ENTRY](../../data/oledb/schema-entry.md) para obter uma descrição da entrada do mapa.  
  
 Consulte [IDBSchemaRowset:: Getrowset](https://msdn.microsoft.com/en-us/library/ms722634.aspx) no SDK do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)   
 [Membros de classe IDBSchemaRowsetImpl](http://msdn.microsoft.com/en-us/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [IDBSchemaRowsetImpl::GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md)   
 [Classes typedef e classes de conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)