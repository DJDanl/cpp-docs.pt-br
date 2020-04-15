---
title: Classe CComContainedObject
ms.date: 11/04/2016
f1_keywords:
- CComContainedObject
- ATLCOM/ATL::CComContainedObject
- ATLCOM/ATL::CComContainedObject::CComContainedObject
- ATLCOM/ATL::CComContainedObject::AddRef
- ATLCOM/ATL::CComContainedObject::GetControllingUnknown
- ATLCOM/ATL::CComContainedObject::QueryInterface
- ATLCOM/ATL::CComContainedObject::Release
helpviewer_keywords:
- aggregate objects [C++], in ATL
- aggregation [C++], ATL objects
- CComContainedObject class
ms.assetid: e8616b41-c200-47b8-bf2c-fb9f713ebdad
ms.openlocfilehash: 72ba27c3be6576621995ffb8c98995c6abc9324c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320792"
---
# <a name="ccomcontainedobject-class"></a>Classe CComContainedObject

Esta classe implementa [iUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) delegando ao `IUnknown`objeto do proprietário.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComContainedObject : public Base
```

#### <a name="parameters"></a>Parâmetros

*Base*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[ccomcontainedobject::Ccomcontainedobject](#ccomcontainedobject)|O construtor. Inicializa o ponteiro do membro para `IUnknown`o objeto do proprietário .|
|[objeto ccomcontained::~Ccomcontainedobject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[ccomcontainedobject::Addref](#addref)|Incrementa a contagem de referência no objeto proprietário.|
|[CComContainedObject::GetControllingUnknown](#getcontrollingunknown)|Recupera o objeto do `IUnknown`proprietário.|
|[CComContainedObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada no objeto proprietário.|
|[CComContainedObject::Lançamento](#release)|Decreta a contagem de referência no objeto do proprietário.|

## <a name="remarks"></a>Comentários

O ATL `CComContainedObject` usa nas classes [CComAggObject,](../../atl/reference/ccomaggobject-class.md) [CComPolyObject](../../atl/reference/ccompolyobject-class.md)e [CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md). `CComContainedObject`implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) delegando ao objeto `IUnknown`proprietário . (O proprietário é o objeto externo de uma agregação ou o objeto para o qual uma interface de ruptura está sendo criada.) `CComContainedObject` chamadas `CComObjectRootEx`, `OuterQueryInterface` `OuterAddRef`e `OuterRelease`, todos herdados através `Base`de .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComContainedObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ccomcontainedobjectaddref"></a><a name="addref"></a>ccomcontainedobject::Addref

Incrementa a contagem de referência no objeto proprietário.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos ou testes.

## <a name="ccomcontainedobjectccomcontainedobject"></a><a name="ccomcontainedobject"></a>ccomcontainedobject::Ccomcontainedobject

O construtor.

```
CComContainedObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
[em] O objeto do `IUnknown`dono.

### <a name="remarks"></a>Comentários

Define `m_pOuterUnknown` o ponteiro do membro `Base` (herdado através da classe) para *pv*.

## <a name="ccomcontainedobjectccomcontainedobject"></a><a name="dtor"></a>objeto ccomcontained::~Ccomcontainedobject

O destruidor.

```
~CComContainedObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="ccomcontainedobjectgetcontrollingunknown"></a><a name="getcontrollingunknown"></a>CComContainedObject::GetControllingUnknown

Retorna `m_pOuterUnknown` o ponteiro de membro (herdado através da `IUnknown`classe *Base)* que detém o objeto proprietário .

```
IUnknown* GetControllingUnknown();
```

### <a name="return-value"></a>Valor retornado

O objeto do `IUnknown`dono.

### <a name="remarks"></a>Comentários

Este método pode `Base` ser virtual se tiver declarado a [DECLARE_GET_CONTROLLING_UNKNOWN](aggregation-and-class-factory-macros.md#declare_get_controlling_unknown) macro.

## <a name="ccomcontainedobjectqueryinterface"></a><a name="queryinterface"></a>CComContainedObject::QueryInterface

Recupera um ponteiro para a interface solicitada no objeto proprietário.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>
HRESULT STDMETHODCALLTYPE QueryInterface(Q** pp);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O identificador da interface que está sendo solicitada.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *iid*. Se o objeto não suportar essa interface, *ppvObject* será definido como NULL.

*Pp*<br/>
[fora] Um ponteiro para o ponteiro `Q`de interface identificado por tipo . Se o objeto não suportar essa interface, *pp* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="ccomcontainedobjectrelease"></a><a name="release"></a>CComContainedObject::Lançamento

Decreta a contagem de referência no objeto do proprietário.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor retornado

Nas compilações de `Release` depuração, retorna um valor que pode ser útil para diagnósticos ou testes. Em construções não-depuradas, `Release` sempre retorna 0.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
