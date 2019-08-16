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
ms.openlocfilehash: c5e2fa64cc0938e632a37eac7dd1d6e9111c3d98
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497316"
---
# <a name="ccomcontainedobject-class"></a>Classe CComContainedObject

Essa classe implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) ao delegar para o objeto do `IUnknown`proprietário.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<class Base>
class CComContainedObject : public Base
```

#### <a name="parameters"></a>Parâmetros

*Polybase*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComContainedObject::CComContainedObject](#ccomcontainedobject)|O construtor. Inicializa o ponteiro do membro para o objeto do `IUnknown`proprietário.|
|[CComContainedObject::~CComContainedObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComContainedObject::AddRef](#addref)|Incrementa a contagem de referência no objeto do proprietário.|
|[CComContainedObject::GetControllingUnknown](#getcontrollingunknown)|Recupera o objeto do `IUnknown`proprietário.|
|[CComContainedObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada no objeto do proprietário.|
|[CComContainedObject::Release](#release)|Decrementa a contagem de referência no objeto do proprietário.|

## <a name="remarks"></a>Comentários

O ATL `CComContainedObject` usa nas classes [CComAggObject](../../atl/reference/ccomaggobject-class.md), [CComPolyObject](../../atl/reference/ccompolyobject-class.md)e [CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md). `CComContainedObject`implementa [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) ao delegar para o objeto do `IUnknown`proprietário. (O proprietário é o objeto externo de uma agregação ou o objeto para o qual uma interface destacável está sendo criada.) `CComContainedObject` chama`CComObjectRootEx` ,`OuterRelease` e,`Base`todas herdadas por meio de. `OuterAddRef` `OuterQueryInterface`

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Base`

`CComContainedObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="addref"></a>  CComContainedObject::AddRef

Incrementa a contagem de referência no objeto do proprietário.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico ou teste.

##  <a name="ccomcontainedobject"></a>  CComContainedObject::CComContainedObject

O construtor.

```
CComContainedObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*pv*<br/>
no O objeto do `IUnknown`proprietário.

### <a name="remarks"></a>Comentários

Define o `m_pOuterUnknown` ponteiro do membro (Herdado `Base` por meio da classe) para *VP*.

##  <a name="dtor"></a>CComContainedObject:: ~ CComContainedObject

O destruidor.

```
~CComContainedObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="getcontrollingunknown"></a>  CComContainedObject::GetControllingUnknown

Retorna o `m_pOuterUnknown` ponteiro do membro (herdado por meio da classe *base* ) que contém o `IUnknown`objeto do proprietário.

```
IUnknown* GetControllingUnknown();
```

### <a name="return-value"></a>Valor de retorno

O objeto do `IUnknown`proprietário.

### <a name="remarks"></a>Comentários

Esse método pode ser virtual se `Base` tiver declarado a macro [DECLARE_GET_CONTROLLING_UNKNOWN](aggregation-and-class-factory-macros.md#declare_get_controlling_unknown) .

##  <a name="queryinterface"></a>  CComContainedObject::QueryInterface

Recupera um ponteiro para a interface solicitada no objeto do proprietário.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>
HRESULT STDMETHODCALLTYPE QueryInterface(Q** pp);
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
no O identificador da interface que está sendo solicitada.

*ppvObject*<br/>
fora Um ponteiro para o ponteiro de interface identificado pelo *IID*. Se o objeto não oferecer suporte a essa interface, *ppvObject* será definido como NULL.

*pp*<br/>
fora Um ponteiro para o ponteiro de interface identificado pelo `Q`tipo. Se o objeto não oferecer suporte a essa interface, *PP* será definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="release"></a>  CComContainedObject::Release

Decrementa a contagem de referência no objeto do proprietário.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor de retorno

Em compilações de `Release` depuração, retorna um valor que pode ser útil para diagnóstico ou teste. Em compilações não depuradas, `Release` sempre retorna 0.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
