---
title: 'Idbschemarowsetimpl:: Createschemarowset | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IDBSchemaRowsetImpl::CreateSchemaRowset
- ATL::IDBSchemaRowsetImpl::CreateSchemaRowset
- CreateSchemaRowset
- IDBSchemaRowsetImpl.CreateSchemaRowset
- ATL.IDBSchemaRowsetImpl.CreateSchemaRowset
dev_langs:
- C++
helpviewer_keywords:
- CreateSchemaRowset method
ms.assetid: ad3e3e4d-45b9-461c-b7b8-3af6843631b1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 90a942fc92faf3066669b46fd825ad2eae393f43
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33103990"
---
# <a name="idbschemarowsetimplcreateschemarowset"></a>IDBSchemaRowsetImpl::CreateSchemaRowset
Implementa uma função de criador do objeto COM para o objeto especificado pelo parâmetro de modelo.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
template template <class SchemaRowsetClass>  
HRESULT CreateSchemaRowset(IUnknown *pUnkOuter,  
   ULONG cRestrictions,  
   const VARIANT rgRestrictions[],  
   REFIID riid,  
   ULONG cPropertySets,  
   DBPROPSET rgPropertySets[],  
   IUnknown** ppRowset,  
   SchemaRowsetClass*& pSchemaRowset);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pUnkOuter`  
 [in] Um externa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) ao agregar, caso contrário, **nulo**.  
  
 `cRestrictions`  
 [in] A contagem de restrições aplicadas ao conjunto de linhas de esquema.  
  
 `rgRestrictions`  
 [in] Uma matriz de `cRestrictions` **VARIANT**s a ser aplicado ao conjunto de linhas.  
  
 `riid`  
 [in] A interface para [QueryInterface](../../atl/queryinterface.md) para a saída **IUnknown**.  
  
 `cPropertySets`  
 [in] Define o número de propriedade para definir.  
  
 `rgPropertySets`  
 [in] Uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas que especificar as propriedades que está sendo definidas.  
  
 `ppRowset`  
 [out] A saída **IUnknown** solicitado pelo `riid`. Isso **IUnknown** é uma interface no objeto de conjunto de linhas de esquema.  
  
 `pSchemaRowset`  
 [out] Um ponteiro para uma instância da classe de conjunto de linhas de esquema. Normalmente, esse parâmetro não for usado, mas ele pode ser usado se você deve executar o trabalho mais no conjunto de linhas de esquema antes de enviar a um objeto COM. O tempo de vida de `pSchemaRowset` estiver associado ao `ppRowset`.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
## <a name="remarks"></a>Comentários  
 Essa função implementa um criador de genérico para todos os tipos de conjuntos de linhas de esquema. Normalmente, o usuário não chama essa função. Ele é chamado pela implementação de mapa de esquema.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)   
 [Membros de classe IDBSchemaRowsetImpl](http://msdn.microsoft.com/en-us/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [SCHEMA_ENTRY](../../data/oledb/schema-entry.md)   
 [Classes typedef e classes de conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)