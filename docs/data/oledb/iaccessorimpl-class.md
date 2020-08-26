---
title: Classe IAccessorImpl
ms.date: 11/04/2016
f1_keywords:
- IAccessorImpl
- ATL.IAccessorImpl.IAccessorImpl
- ATL::IAccessorImpl::IAccessorImpl
- IAccessorImpl::IAccessorImpl
- IAccessorImpl.IAccessorImpl
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
helpviewer_keywords:
- IAccessorImpl class
- IAccessorImpl class, constructor
- IAccessorImpl constructor
- AddRefAccessor method
- CreateAccessor method
- GetBindings method
- ReleaseAccessor method
ms.assetid: 768606da-8b71-417c-a62c-88069ce7730d
ms.openlocfilehash: 356278b316912bdb81f1c43bbf2034f00ec3d785
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845608"
---
# <a name="iaccessorimpl-class"></a>Classe IAccessorImpl

Fornece uma implementação da interface [IAccessor](/previous-versions/windows/desktop/ms719672(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T,
   class BindType = ATLBINDINGS,
   class BindingVector = CAtlMap <HACCESSOR hAccessor, BindType* pBindingsStructure>>
class ATL_NO_VTABLE IAccessorImpl : public IAccessorImplBase<BindType>
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Seu conjunto de linhas ou classe de objeto de comando.

*Associatype*<br/>
Unidade de armazenamento para informações de associação. O padrão é a `ATLBINDINGS` estrutura (consulte Atldb. h).

*BindingVector*<br/>
Unidade de armazenamento para informações de coluna. O padrão é [CAtlMap](../../atl/reference/catlmap-class.md) , em que o elemento key é um valor HACCESSOR e o elemento Value é um ponteiro para uma `BindType` estrutura.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[IAccessorImpl](#iaccessorimpl)|O construtor.|

### <a name="interface-methods"></a>Métodos de interface

| Nome | Descrição |
|-|-|
|[AddRefAccessor](#addrefaccessor)|Adiciona uma contagem de referência a acessador existente.|
|[Createaccesser](#createaccessor)|Cria um acessador de um conjunto de associações.|
|[GetBindings](#getbindings)|Retorna as associações em um acessador.|
|[ReleaseAccessor](#releaseaccessor)|Libera um acessador.|

## <a name="remarks"></a>Comentários

Isso é obrigatório em conjuntos de linhas e comandos. OLE DB requer que os provedores implementem um HACCESSOR, que é uma marca para uma matriz de estruturas [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) . HACCESSORs fornecidos pelo `IAccessorImpl` são endereços das `BindType` estruturas. Por padrão, `BindType` é definido como uma `ATLBINDINGS` `IAccessorImpl` definição de modelo no. `BindType` fornece um mecanismo usado pelo `IAccessorImpl` para controlar o número de elementos em sua `DBBINDING` matriz, bem como uma contagem de referência e sinalizadores de acessador.

## <a name="iaccessorimpliaccessorimpl"></a><a name="iaccessorimpl"></a> IAccessorImpl::IAccessorImpl

O construtor.

### <a name="syntax"></a>Sintaxe

```cpp
IAccessorImpl();
```

## <a name="iaccessorimpladdrefaccessor"></a><a name="addrefaccessor"></a> IAccessorImpl::AddRefAccessor

Adiciona uma contagem de referência a acessador existente.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(AddRefAccessor)(HACCESSOR hAccessor,
   DBREFCOUNT* pcRefCount);
```

#### <a name="parameters"></a>parâmetros

Consulte [IAccessor:: AddRefAccessor](/previous-versions/windows/desktop/ms714978(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="iaccessorimplcreateaccessor"></a><a name="createaccessor"></a> IAccessorImpl:: createaccesser

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

#### <a name="parameters"></a>parâmetros

Consulte [IAccessor:: Createaccesser](/previous-versions/windows/desktop/ms720969(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="iaccessorimplgetbindings"></a><a name="getbindings"></a> IAccessorImpl:: GetBindings

Retorna as associações de colunas básicas do consumidor em um acessador.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetBindings)(HACCESSOR hAccessor,
   DBACCESSORFLAGS* pdwAccessorFlags,
   DBCOUNTITEM* pcBindings,
   DBBINDING** prgBindings);
```

#### <a name="parameters"></a>parâmetros

Consulte [IAccessor:: GetBindings](/previous-versions/windows/desktop/ms721253(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="iaccessorimplreleaseaccessor"></a><a name="releaseaccessor"></a> IAccessorImpl::ReleaseAccessor

Libera um acessador.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(ReleaseAccessor)(HACCESSOR hAccessor,
   DBREFCOUNT* pcRefCount);
```

#### <a name="parameters"></a>parâmetros

Consulte [IAccessor:: ReleaseAccessor](/previous-versions/windows/desktop/ms719717(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
