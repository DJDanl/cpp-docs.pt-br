---
title: Classe IRowsetIdentityImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::IRowsetIdentityImpl
- ATL.IRowsetIdentityImpl
- IRowsetIdentityImpl
- IsSameRow
- IRowsetIdentityImpl.IsSameRow
- ATL.IRowsetIdentityImpl.IsSameRow
- IRowsetIdentityImpl::IsSameRow
- ATL::IRowsetIdentityImpl::IsSameRow
dev_langs:
- C++
helpviewer_keywords:
- IRowsetIdentityImpl class
- IsSameRow method
ms.assetid: 56821edf-e045-40c8-96bd-231552cd5799
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5cbafe7f43d8a6c7acfaccb52fd22b595bdd0ec4
ms.sourcegitcommit: e5792fcb89b9ba64c401f90f4f26a8e45d4a2359
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2018
ms.locfileid: "39322092"
---
# <a name="irowsetidentityimpl-class"></a>Classe IRowsetIdentityImpl
Implementa o OLE DB [IRowsetIdentity](https://msdn.microsoft.com/library/ms715913.aspx) interface, que permite o teste para a identidade de linha.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class RowClass = CSimpleRow>  
class ATL_NO_VTABLE IRowsetIdentityImpl   
   : public IRowsetIdentity  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Uma classe derivada de `IRowsetIdentityImpl`.  
  
 *RowClass*  
 A unidade de armazenamento para o `HROW`.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[IsSameRow](#issamerow)|Compara dois identificadores de linha para ver se eles se referem à mesma linha.|  
  
## <a name="issamerow"></a> Irowsetidentityimpl:: Issamerow
Compara dois identificadores de linha para ver se eles se referem à mesma linha.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(IsSameRow )(HROW hThisRow,  
   HROW hThatRow);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IRowsetIdentity::IsSameRow](https://msdn.microsoft.com/library/ms719629.aspx) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  
 Para comparar identificadores de linha, este método converte o `HROW` lida com a `RowClass` membros e chamadas `memcmp` em ponteiros.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
