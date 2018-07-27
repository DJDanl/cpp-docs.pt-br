---
title: Classe IGetDataSourceImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IGetDataSourceImpl
- ATL.IGetDataSourceImpl<T>
- ATL.IGetDataSourceImpl
- ATL::IGetDataSourceImpl
- ATL::IGetDataSourceImpl<T>
- GetDataSource
- IGetDataSourceImpl.GetDataSource
- IGetDataSourceImpl::GetDataSource
dev_langs:
- C++
helpviewer_keywords:
- IGetDataSourceImpl class
- GetDataSource method
ms.assetid: d63f3178-d663-4f01-8c09-8aab2dd6805a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 558578a82f1906d7481abebc5e1f1719b1983724
ms.sourcegitcommit: b0d6777cf4b580d093eaf6104d80a888706e7578
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/26/2018
ms.locfileid: "39269931"
---
# <a name="igetdatasourceimpl-class"></a>Classe IGetDataSourceImpl
Fornece uma implementação de [IGetDataSource](https://msdn.microsoft.com/library/ms709721.aspx) objeto.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T>  
class ATL_NO_VTABLE IGetDataSourceImpl : public IGetDataSource  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IGetDataSourceImpl`.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetDataSource](#getdatasource)|Retorna um ponteiro de interface no objeto de fonte de dados que criou a sessão.|  
  
## <a name="remarks"></a>Comentários  
 Isso é uma interface obrigatória na sessão para a obtenção de um ponteiro de interface para o objeto de fonte de dados.  

## <a name="getdatasource"></a> Igetdatasourceimpl:: Getdatasource
Retorna um ponteiro de interface no objeto de fonte de dados que criou a sessão.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(GetDataSource)(REFIID riid,   
   IUnknown ** ppDataSource);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IGetDataSource::GetDataSource](https://msdn.microsoft.com/library/ms725443.aspx) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  
 É útil se você precisar acessar as propriedades no objeto de fonte de dados.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
