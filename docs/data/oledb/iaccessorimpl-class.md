---
title: Classe IAccessorImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IAccessorImpl
- ATL.IAccessorImpl.IAccessorImpl
- ATL::IAccessorImpl::IAccessorImpl
- IAccessorImpl::IAccessorImpl
- IAccessorImpl.IAccessorImpl
- IAccessorImpl
- ATL::IAccessorImpl::AddRefAccessor
- AddRefAccessor
- IAccessorImpl::AddRefAccessor
- IAccessorImpl.AddRefAccessor
- ATL.IAccessorImpl.AddRefAccessor
- IAccessorImpl::CreateAccessor
- CreateAccessor
- ATL::IAccessorImpl::CreateAccessor
- IAccessorImpl.CreateAccessor
- ATL.IAccessorImpl.CreateAccessor
- IAccessorImpl.GetBindings
- ATL::IAccessorImpl::GetBindings
- IAccessorImpl::GetBindings
- GetBindings
- ATL.IAccessorImpl.GetBindings
- ReleaseAccessor
- IAccessorImpl::ReleaseAccessor
- ATL.IAccessorImpl.ReleaseAccessor
- ATL::IAccessorImpl::ReleaseAccessor
- IAccessorImpl.ReleaseAccessor
dev_langs:
- C++
helpviewer_keywords:
- IAccessorImpl class
- IAccessorImpl class, constructor
- IAccessorImpl constructor
- AddRefAccessor method
- CreateAccessor method
- GetBindings method
- ReleaseAccessor method
ms.assetid: 768606da-8b71-417c-a62c-88069ce7730d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9ec9e30112a9f0f5b54b84ccbbb61268e56d70d2
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39338773"
---
# <a name="iaccessorimpl-class"></a>Classe IAccessorImpl
Fornece uma implementação de [IAccessor](https://msdn.microsoft.com/library/ms719672.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, 
   class BindType = ATLBINDINGS,
   class BindingVector = CAtlMap <HACCESSOR hAccessor, BindType* pBindingsStructure>>  
class ATL_NO_VTABLE IAccessorImpl : public IAccessorImplBase<BindType>  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe de objeto do conjunto de linhas ou de comando.  
  
 *BindType*  
 Unidade de armazenamento de informações de associação. O padrão é o `ATLBINDINGS` estrutura (consulte atldb.h).  
  
 *BindingVector*  
 Unidade de armazenamento para informações de coluna. O padrão é [CAtlMap](../../atl/reference/catlmap-class.md) onde o elemento-chave é um valor HACCESSOR e o elemento de valor é um ponteiro para um `BindType` estrutura.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  

## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[IAccessorImpl](#iaccessorimpl)|O construtor.|  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[AddRefAccessor](#addrefaccessor)|Adiciona uma contagem de referência a acessador existente.|  
|[CreateAccessor](#createaccessor)|Cria um acessador de um conjunto de associações.|  
|[GetBindings](#getbindings)|Retorna as associações em um acessador.|  
|[ReleaseAccessor](#releaseaccessor)|Libera um acessador.|  
  
## <a name="remarks"></a>Comentários  
 Isso é obrigatório em conjuntos de linhas e comandos. OLE DB exige que os provedores implementar um HACCESSOR, que é uma marca para uma matriz de [DBBINDING](https://msdn.microsoft.com/library/ms716845.aspx) estruturas. HACCESSORs fornecidos pelo `IAccessorImpl` são os endereços do `BindType` estruturas. Por padrão, `BindType` é definido como um `ATLBINDINGS` no `IAccessorImpl`da definição de modelo. `BindType` Fornece um mecanismo usado pelo `IAccessorImpl` para controlar o número de elementos no seu `DBBINDING` , bem como um sinalizadores de acessador e contagem de referência de matriz.  

## <a name="iaccessorimpl"></a> Iaccessorimpl:: Iaccessorimpl
O construtor.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
IAccessorImpl();  
```  

## <a name="addrefaccessor"></a> Iaccessorimpl:: Addrefaccessor
Adiciona uma contagem de referência a acessador existente.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(AddRefAccessor)(HACCESSOR hAccessor,  
   DBREFCOUNT* pcRefCount);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IAccessor::AddRefAccessor](https://msdn.microsoft.com/library/ms714978.aspx) na *referência do programador do OLE DB*.

## <a name="createaccessor"></a> Iaccessorimpl:: CreateAccessor
Cria um acessador de um conjunto de associações.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(CreateAccessor)(DBACCESSORFLAGS dwAccessorFlags,  
   DBCOUNTITEM cBindings,  
   const DBBINDING rgBindings[],  
   DBLENGTH cbRowSize,  
   HACCESSOR* phAccessor,  
   DBBINDSTATUS rgStatus[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IAccessor:: CreateAccessor](https://msdn.microsoft.com/library/ms720969.aspx) na *referência do programador do OLE DB*.  

## <a name="getbindings"></a> Iaccessorimpl:: Getbindings
Retorna as associações de colunas básico do consumidor em um acessador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(GetBindings)(HACCESSOR hAccessor,  
   DBACCESSORFLAGS* pdwAccessorFlags,  
   DBCOUNTITEM* pcBindings,  
   DBBINDING** prgBindings);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IAccessor::GetBindings](https://msdn.microsoft.com/library/ms721253.aspx) na *referência do programador do OLE DB*. 

## <a name="releaseaccessor"></a> Iaccessorimpl:: Releaseaccessor
Libera um acessador.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(ReleaseAccessor)(HACCESSOR hAccessor,  
   DBREFCOUNT* pcRefCount);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IAccessor:: Releaseaccessor](https://msdn.microsoft.com/library/ms719717.aspx) na *referência do programador do OLE DB*.
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)